function rail_tester = process_data(rail_tester_in, options);
%default options - filter
default_options.freq_filter_on = 1;
default_options.freq_filter = 15e3;
default_options.freq_filter_bandwidth = 3.5e3;%filter half bandwidth to -40 dB points
default_options.freq_comp_for_input_signal = 1;
%default options - raw data
default_options.raw_data_ignore_pulse_echo = 0;
default_options.raw_data_coupling_comp = 0;
default_options.raw_data_zero_dead_time = 0;
%default options - mode shape matrix calculation
default_options.ms_matrix_modes_to_use = [3,5,7,8,10];%modes used in calculation of matrices
default_options.ms_matrix_calc_method = 1; %1 centre frequency; 2 linear interpolation between matrices calculated at ms_matrix_calc_freqs
default_options.ms_matrix_calc_freqs = linspace(11.5e3,16.5e3,11); %frequencies to calc mode shape matrix at for linear interpolation
default_options.ms_matrix_ignore_pulse_echo = 0;
default_options.ms_matrix_bidi_calc = 0; %turn on to include transmit in +ve direction and receive in +ve direction combos in calc
default_options.ms_matrix_apply_as_time_shift = 0; %turn on to do freq domain processing, but applied as time rather than phase shifts
default_options.ms_matrix_time_step_size = 0; %if non-zero and doing time shifts, this sets the smallest integral multiple of time shifts allowed
default_options.ms_matrix_allow_neg_amps = 1; %if non-zero and doing time shifts, time shifts of between pi and 2pi are implemented as pi less combined with a negative amplitude
%other processing options
default_options.proc_time_domain = 0; %turn on to do processing as time shifts only
default_options.dispersion_compensation = 0; %turn on for dispersion compensation
default_options.suppress_display = 0;
default_options.show_coupling_graph = 1;

options = set_default_fields(options, default_options);
rail_tester = rail_tester_in;

%add freq domain version of raw data to plate tester, if it doesn't exist
%already
if ~options.proc_time_domain
	if ~(isfield(rail_tester.raw_data, 'freq') & isfield(rail_tester.raw_data, 'freq_data')) & options.raw_data_zero_dead_time == 0
		rail_tester.raw_data = convert_to_freq_domain(...
			rail_tester.raw_data, ...
			options.suppress_display);
	end;
else
	options.ms_matrix_calc_method = 1; %to force single mode shape matrix at filter freq only
end;

%some shortcut variables, also because we don't want to damage raw data in
%output variable when e.g. p/e signals are removed
raw_data = rail_tester.raw_data;
disperse = rail_tester.disperse;
array = rail_tester.array;
input_signal = rail_tester.input_signal;

%zero out dead time - note that if set to non zero always causes freq domain version of raw
%data to be recalculated
if options.raw_data_zero_dead_time > 0
    raw_data = fn_zero_dead_zone(...
        raw_data, ...
        options.raw_data_zero_dead_time, ...
        options.suppress_display);
	raw_data = convert_to_freq_domain(...
			raw_data, ...
			options.suppress_display);
end;

%sort out the mode indices for processed data
proc_data.tx_mode = ones(length(options.ms_matrix_modes_to_use),1) * options.ms_matrix_modes_to_use;
proc_data.rx_mode = proc_data.tx_mode';
proc_data.tx_mode = proc_data.tx_mode(:);
proc_data.rx_mode = proc_data.rx_mode(:);
proc_data.tx_dir = [ones(length(proc_data.tx_mode),1);-ones(length(proc_data.tx_mode),1)];
proc_data.rx_dir = [ones(length(proc_data.tx_mode),1);-ones(length(proc_data.tx_mode),1)];
if options.ms_matrix_bidi_calc;
   proc_data.tx_dir = [proc_data.tx_dir; proc_data.tx_dir];
   proc_data.rx_dir = [proc_data.rx_dir; flipud(proc_data.rx_dir)];
   proc_data.tx_mode = [proc_data.tx_mode; proc_data.tx_mode; proc_data.tx_mode; proc_data.tx_mode];
   proc_data.rx_mode = [proc_data.rx_mode; proc_data.rx_mode; proc_data.rx_mode; proc_data.rx_mode];
else
   proc_data.tx_mode = [proc_data.tx_mode; proc_data.tx_mode];
   proc_data.rx_mode = [proc_data.rx_mode; proc_data.rx_mode];
end;

%pre-processing of raw data - removal of p/e columns
%other stuff e.g. coupling comp will be added here
if (options.raw_data_ignore_pulse_echo == 1)
	raw_data = remove_pulse_echo_data(raw_data, options.suppress_display);
end;

if options.raw_data_coupling_comp ~= 0
    raw_data = fn_coupling_comp(raw_data, options);
end;

%build inverse mode shape matrix at frequency(s) required
if options.ms_matrix_calc_method == 1
	options.ms_matrix_calc_freqs = options.freq_filter;
end;
inv_mode_shapes = build_inverse_mode_shape_matrices(...
	raw_data, ...
	proc_data, ...
	array, disperse, ...
	options.ms_matrix_calc_freqs, ...
	options.ms_matrix_modes_to_use, ...
	options.suppress_display);

if options.proc_time_domain
	%time domain processing
	%TODO - should end up with temp_time_data
	temp_time_data = mode_extraction_in_time_domain( ...
		inv_mode_shapes, ...
		raw_data, ...
		options.ms_matrix_calc_freqs, ...
		options.suppress_display);
	if options.dispersion_compensation
		%TODO - do conversion from time to dist cf. above
	else
		proc_data = convert_from_time_to_distance( ...
			temp_time_data, ...
			proc_data, ...
			disperse, ...
			options.ms_matrix_modes_to_use, ...
			options.freq_filter, ...
			options.suppress_display);
	end;
else
	%frequency domain processing
%	array.delay = 0.0;

%TODO - this should be changed to just filtering raw freq dom data
	raw_data = filter_freq_domain_data( ...
		raw_data, ...
		input_signal, ...
		array.delay, ...
		options.freq_comp_for_input_signal, ...
		options.freq_filter_on, ...
		options.freq_filter, ...
		options.freq_filter_bandwidth, ...
		options.suppress_display);
	temp_freq_data = mode_extraction_in_freq_domain(...
		inv_mode_shapes, ...
		options.ms_matrix_calc_freqs, ...
		raw_data, ...
		proc_data, ...
		options.ms_matrix_apply_as_time_shift, ...
		options.ms_matrix_time_step_size, ...
		options.ms_matrix_allow_neg_amps, ...
		options.suppress_display);
	if options.dispersion_compensation
		%TODO - do conversion directly from freq to dist
	else
		temp_time_data = convert_from_freq_to_time_domain( ...
			temp_freq_data, ...
			options.suppress_display);
		proc_data = convert_from_time_to_distance( ...
			temp_time_data, ...
			proc_data, ...
			disperse, ...
			options.ms_matrix_modes_to_use, ...
			options.freq_filter, ...
			options.suppress_display);
	end;
end;

rail_tester.proc_data = proc_data;
return;