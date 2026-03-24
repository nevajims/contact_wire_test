function rail_tester = fn_process_rail_data_fn_wrapper(rail_tester, options, fn_version)

%First get options as structure
if nargin < 2
    options = [];
end
options = fn_set_default_fields(options, get_default_options());
if nargin < 3
    fn_version = 'original matlab';
end

switch fn_version
    case 'original matlab'
        rail_tester = fn_process_rail_data(rail_tester, options);
        return
    case 'dll'
        dll_name = 'fn_process_rail_data_DLL';
        function_name = dll_name;

        dll_folder = fullfile(pwd,'codegen','dll', dll_name);
        dll_fname = fullfile(dll_folder, [dll_name, '.dll']);
        hdr_fname = fullfile(dll_folder, [dll_name, '.h']);

        if ~libisloaded(dll_name)
            [notfound,warnings] = loadlibrary(dll_fname, hdr_fname);   % add 'addheader' for any extra headers if needed
        end
end


%At this point one of the new versions will be called. These are all based
%around a new version coded in Matlab that is compatible with MATLAB CODER,
%so the input needs to be changed to match this version (lots of
%separate parameters, rather than one structure because MATLAB CODER
%doesn't like those)

if options.raw_data_zero_dead_time == 1
    %This handles what appears to be mistake in original
    %fn_process_rail_data code in the function fn_zero_dead_zone. In that
    %function, data at time < options.raw_data_zero_dead_time would be set 
    %to 0 unless options.raw_data_zero_dead_time > max(time), in which case
    %nothing happened. Since 1 is going to be > max(time), this is
    %invariably what happened. However, it is more logical to set it to
    %zero for nothing to happen, hence following line that is just to make
    %behaviour consistent.
    options.raw_data_zero_dead_time = 0;
end

if options.ms_matrix_calc_method == 1
    %In original fn_process_rail_data, options.ms_matrix_calc_method = 1
    %meant single frequency mode shapes at the filter frequency were used
    %while options.ms_matrix_calc_method = 2 meant mode shapes were 
    %calculated at each frequency in options.ms_matrix_calc_freqs.
    %In new function, options.ms_matrix_calc_method does not exist and the
    %default is to use at each frequency in options.ms_matrix_calc_freqs
    %unless that is empty, in which case behaviour is to use a single
    %frequency at the filter frequency, so this is how 
    %options.ms_matrix_calc_method = 1 is now achieved.
    options.ms_matrix_calc_freqs = [];
end

no_modes = numel(rail_tester.disperse.mode);
no_freq_pts = numel(rail_tester.disperse.mode(1).freq);
no_ms_pts = size(rail_tester.disperse.mode(1).ms_x, 2);
for m = 1:no_modes
    if m == 1
        disperse_freq = zeros(no_freq_pts, 1, no_modes);
        disperse_vph = zeros(no_freq_pts, 1, no_modes);
        disperse_vgr = zeros(no_freq_pts, 1, no_modes);
        disperse_waveno = zeros(no_freq_pts, 1, no_modes);
        disperse_ms_x = zeros(no_freq_pts, no_ms_pts, no_modes);
        disperse_ms_y = zeros(no_freq_pts, no_ms_pts, no_modes);
        disperse_ms_z = zeros(no_freq_pts, no_ms_pts, no_modes);
    end
    disperse_freq(:,1,m) = rail_tester.disperse.mode(m).freq;
    disperse_vph(:,1,m) = rail_tester.disperse.mode(m).vph;
    disperse_vgr(:,1,m) = rail_tester.disperse.mode(m).vgr;
    disperse_waveno(:,1,m) = rail_tester.disperse.mode(m).waveno;
    disperse_ms_x(:,:,m) = rail_tester.disperse.mode(m).ms_x;
    disperse_ms_y(:,:,m) = rail_tester.disperse.mode(m).ms_y;
    disperse_ms_z(:,:,m) = rail_tester.disperse.mode(m).ms_z;
end

switch fn_version
    case 'new matlab'
        [rail_tester.proc_data.tx_mode, rail_tester.proc_data.rx_mode, rail_tester.proc_data.tx_dir, rail_tester.proc_data.rx_dir, rail_tester.proc_data.dist, rail_tester.proc_data.dist_data] = ...
            fn_process_rail_data_DLL( ...
            rail_tester.raw_data.time, ...
            rail_tester.raw_data.time_data, ...
            int64(rail_tester.raw_data.tx), ...
            int64(rail_tester.raw_data.rx), ...%raw data
            rail_tester.array.row_pos, ...
            int64(rail_tester.array.trans_pos), ...
            int64(rail_tester.array.trans_row), ...
            rail_tester.array.trans_pos_orientations, ...
            rail_tester.array.delay, ...
            int64(rail_tester.array.trans_node_list), ...
            disperse_freq, disperse_vph, disperse_vgr, disperse_waveno, disperse_ms_x, disperse_ms_y, disperse_ms_z, ...
            options.ms_matrix_modes_to_use, ...
            options.freq_filter_on, options.freq_filter, options.freq_filter_bandwidth, ...
            options.raw_data_zero_dead_time, ... %although on before, was coded wrong and didn't do anything
            options.raw_data_ignore_pulse_echo, options.ms_matrix_bidi_calc, ...
            options.ms_matrix_apply_as_time_shift, options.ms_matrix_time_step_size, options.ms_matrix_allow_neg_amps, ... %not convinced latter two are useful
            options.ms_matrix_calc_freqs, ...
            options.dispersion_compensation, ...
            options.manual_warps);
    case 'new mex'
        [rail_tester.proc_data.tx_mode, rail_tester.proc_data.rx_mode, rail_tester.proc_data.tx_dir, rail_tester.proc_data.rx_dir, rail_tester.proc_data.dist, rail_tester.proc_data.dist_data] = ...
            fn_process_rail_data_DLL_mex( ...
            rail_tester.raw_data.time, ...
            rail_tester.raw_data.time_data, ...
            int64(rail_tester.raw_data.tx), ...
            int64(rail_tester.raw_data.rx), ...%raw data
            rail_tester.array.row_pos, ...
            int64(rail_tester.array.trans_pos), ...
            int64(rail_tester.array.trans_row), ...
            rail_tester.array.trans_pos_orientations, ...
            rail_tester.array.delay, ...
            int64(rail_tester.array.trans_node_list), ...
            disperse_freq, disperse_vph, disperse_vgr, disperse_waveno, disperse_ms_x, disperse_ms_y, disperse_ms_z, ...
            options.ms_matrix_modes_to_use, ...
            options.freq_filter_on, options.freq_filter, options.freq_filter_bandwidth, ...
            options.raw_data_zero_dead_time, ... %although on before, was coded wrong and didn't do anything
            options.raw_data_ignore_pulse_echo, options.ms_matrix_bidi_calc, ...
            options.ms_matrix_apply_as_time_shift, options.ms_matrix_time_step_size, options.ms_matrix_allow_neg_amps, ... %not convinced latter two are useful
            options.ms_matrix_calc_freqs, ...
            options.dispersion_compensation, ...
            options.manual_warps);
    case 'new dll'
        error('Not implemented yet')
end
end

function default_options  = get_default_options()
%default options - filter
default_options.freq_filter_on = 1;
default_options.freq_filter = 50e3;
default_options.freq_filter_bandwidth = 3.5e3;%filter half bandwidth to -40 dB points
default_options.freq_comp_for_input_signal = 1;
%default options - raw data
default_options.raw_data_ignore_pulse_echo = 0;
default_options.raw_data_coupling_comp = 2;
default_options.raw_data_zero_dead_time = 0;
%default options - mode shape matrix calculation - what modes and directions are included
default_options.ms_matrix_modes_to_use = [1,2,3,4];%modes used in calculation of matrices
default_options.ms_matrix_bidi_calc = 0; %turn on to include transmit in +ve direction and receive in +ve direction combos in calc
%default options - mode shape matrix calculation - single or multi-frequency
default_options.ms_matrix_calc_method = 1; %1 filter frequency; 2 linear interpolation between matrices calculated at ms_matrix_calc_freqs
default_options.ms_matrix_calc_freqs = linspace(47.5e3,52.5e3,11); %frequencies to calc mode shape matrix at for linear interpolation
%default options - mode shape matrix calculation - if you want to simulate pure time domain processing
default_options.ms_matrix_apply_as_time_shift = 0; %turn on to do freq domain processing, but applied as time rather than phase shifts
default_options.ms_matrix_time_step_size = 0; %if non-zero and doing time shifts, this sets the smallest integral multiple of time shifts allowed
default_options.ms_matrix_allow_neg_amps = 1; %if non-zero and doing time shifts, time shifts of between pi and 2pi are implemented as pi less combined with a negative amplitude
%default options - other
default_options.dispersion_compensation = 0; %turn on for dispersion compensation - not implemented!!
default_options.warp_factor = 1; %0 - no warping, 1 - use the manual warps, 2 - smart warp (I haven't tested this);
%default_options.manual_warps = ones(1, max(default_options.ms_matrix_modes_to_use));
default_options.manual_warps = [1.02,1.02,1.02,0.952]; %added this to see how it works, based on experimental result.
%default_options.manual_warps = [1.11,1.05,1.01,1.13]; %These are the warps
%for the pogo models
default_options.smart_warp_ref_mode = 3;
default_options.smart_warp_trial_range = linspace(0.9, 1.1, 21);
default_options.suppress_display = 0;
default_options.show_coupling_graph = 1;
end
