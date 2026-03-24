function [proc_tx_mode, proc_rx_mode, proc_tx_dir, proc_rx_dir, proc_dist, proc_dist_data] = fn_process_rail_data_DLL(...
        raw_time, raw_time_data, raw_tx, raw_rx, ...%raw data
        array_row_pos, array_trans_pos, array_trans_row, array_trans_pos_orientations, array_delay, array_trans_node_list, ... %array
        disperse_freq, disperse_vph, disperse_vgr, disperse_waveno, disperse_ms_x, disperse_ms_y, disperse_ms_z, ...
        opts_ms_matrix_modes_to_use, ...
        opts_freq_filter_on, opts_freq_filter, opts_freq_filter_bandwidth, ...
        opts_raw_data_zero_dead_time, ... %although on before, was coded wrong and didn't do anything
        opts_raw_data_ignore_pulse_echo, opts_ms_matrix_bidi_calc, ...
        opts_ms_matrix_apply_as_time_shift, opts_ms_matrix_time_step_size, opts_ms_matrix_allow_neg_amps, ... %not convinced latter two are useful
        opts_ms_matrix_calc_freqs, ...
        opts_dispersion_compensation, ...
        opts_manual_warps)

% freq_comp_for_input_signal = 0; %NOT IMPLEMENTED
% raw_data_coupling_comp = 0; %NOT IMPLEMENTED
% opts_ms_matrix_calc_method = 1; %DOESN't DO OWT

%This is a Matlab coder compatible version of fn_process_rail_data which
%avoids dynamic structures

%--------------------------------------------------------------------------
%Following eventually to be options but hardcoded to match benchmark for
%now
% opts_ms_matrix_modes_to_use = 1:4;%temp to get things working
% opts_freq_filter = 50000;
% opts_freq_filter_bandwidth = 40000;
% % freq_comp_for_input_signal = 0; %NOT IMPLEMENTED
% opts_raw_data_ignore_pulse_echo = 1;
% % raw_data_coupling_comp = 0; %NOT IMPLEMENTED
% opts_raw_data_zero_dead_time = 0; %this was coded wrong before and didn't do anything, even when set to non-zero. It is now correct, and zero is needed to turn it off.
% opts_ms_matrix_calc_method = 1; 
% opts_ms_matrix_calc_freqs = [30000 34000 38000 42000 46000 50000 54000 58000 62000 66000 70000];%temp to get things working
% 
% opts_freq_filter_on = 1;
% opts_ms_matrix_bidi_calc = 0; 
% opts_ms_matrix_apply_as_time_shift = 0; 
% opts_ms_matrix_time_step_size = 0; %if non-zero and doing time shifts, this sets the smallest integral multiple of time shifts allowed
% opts_ms_matrix_allow_neg_amps = 1;
% opts_dispersion_compensation = 0;
% opts_manual_warps = [1.02,1.02,1.02,0.952];
%--------------------------------------------------------------------------

%Sort out the indices of the outputs
proc_tx_mode = ones(length(opts_ms_matrix_modes_to_use), 1) * opts_ms_matrix_modes_to_use;
proc_rx_mode = proc_tx_mode';
proc_tx_mode = proc_tx_mode(:);
proc_rx_mode = proc_rx_mode(:);
proc_tx_dir = [ones(length(proc_tx_mode), 1);-ones(length(proc_tx_mode), 1)];
proc_rx_dir = [ones(length(proc_tx_mode), 1);-ones(length(proc_tx_mode), 1)];
if opts_ms_matrix_bidi_calc
    proc_tx_dir = [proc_tx_dir; proc_tx_dir];
    proc_rx_dir = [proc_rx_dir; flipud(proc_rx_dir)];
    proc_tx_mode = [proc_tx_mode; proc_tx_mode; proc_tx_mode; proc_tx_mode];
    proc_rx_mode = [proc_rx_mode; proc_rx_mode; proc_rx_mode; proc_rx_mode];
else
    proc_tx_mode = [proc_tx_mode; proc_tx_mode];
    proc_rx_mode = [proc_rx_mode; proc_rx_mode];
end

% %force single frequency mode shape matrix processing if simulating working in time domain
% opts_ms_matrix_calc_method = 1;
% opts_ms_matrix_apply_as_time_shift = 0;
% if opts_ms_matrix_apply_as_time_shift
%     % opts_ms_matrix_calc_freqs = opts_freq_filter;
%    opts_ms_matrix_calc_method = 1; %to force single mode shape matrix at filter freq only
% end
% 
% %set up frequency for mode shape calc if only using single freq
% if opts_ms_matrix_calc_method == 1
%     opts_ms_matrix_calc_freqs = opts_freq_filter;
% end
if isempty(opts_ms_matrix_calc_freqs)
    opts_ms_matrix_calc_freqs = opts_freq_filter;
end

%zero out dead time if required
if opts_raw_data_zero_dead_time > 0
    raw_time_data = fn_zero_dead_zone(raw_time, raw_time_data, opts_raw_data_zero_dead_time);
end

%removal of p/e columns if required
if opts_raw_data_ignore_pulse_echo == 1
    [raw_tx, raw_rx, raw_time_data] = fn_remove_pulse_echo_data(raw_tx, raw_rx, raw_time_data);
end

%convert to frequency domain
[freq, raw_freq_data, fft_pts] = fn_convert_to_freq_domain(raw_time, raw_time_data);

% %coupling compensation if required
% if options.raw_data_coupling_comp ~= 0
%     raw_data = fn_coupling_comp(raw_data, array, options);
% end

%frequency domain processing
[freq_i1, freq_i2, raw_freq_data] = fn_filter_freq_domain_data(freq, raw_freq_data, opts_freq_filter_on, opts_freq_filter, opts_freq_filter_bandwidth);

%build inverse mode shape matrix at frequency(s) required 
inv_mode_shapes = fn_inv_mode_shape_matrices(raw_tx, raw_rx, freq, raw_freq_data, ...
        array_row_pos, array_trans_pos, array_trans_row, array_trans_pos_orientations, array_delay, array_trans_node_list, ... %array
        disperse_freq, disperse_vph, disperse_vgr, disperse_waveno, disperse_ms_x, disperse_ms_y, disperse_ms_z, ...
        proc_tx_mode, proc_rx_mode, proc_tx_dir, proc_rx_dir, ...
        opts_ms_matrix_calc_freqs, opts_ms_matrix_modes_to_use); 

%do the mode extraction
proc_freq_data = fn_mode_extract_freq_dom(...
    freq, raw_freq_data, freq_i1, freq_i2, ...
    inv_mode_shapes, opts_ms_matrix_calc_freqs, ...
    opts_ms_matrix_apply_as_time_shift, opts_ms_matrix_time_step_size, opts_ms_matrix_allow_neg_amps);


%Convert from freq to distance
% if opts_dispersion_compensation
%     %TODO - will go directly from freq to dist
%     %must remember to make sure modal_vgrs is generated in proc_data
%     %for use with warping
% else
    %Convert from freq to time
    [proc_time, proc_time_data] = fn_convert_freq_to_time_dom(freq, proc_freq_data, fft_pts);
    %Convert from time to distance
    [proc_dist, proc_dist_data, modal_vgrs] = fn_convert_time_to_dist(proc_time, proc_time_data, ...
            proc_tx_mode, proc_rx_mode, ...
        disperse_freq, disperse_vgr, disperse_waveno, ...
        opts_ms_matrix_modes_to_use, opts_freq_filter);
% end
 
%Warp distance axes if desired according to opts_manual_warps (vector of
%warp factors for each mode)
if ~isempty(opts_manual_warps) 
    proc_dist_data = complex(fn_apply_dist_warps(proc_dist, proc_dist_data, proc_tx_mode, proc_rx_mode, modal_vgrs, opts_manual_warps));
end

end

%--------------------------------------------------------------------------

function time_data = fn_zero_dead_zone(time, time_data, raw_data_zero_dead_time)
time_data(time <= raw_data_zero_dead_time, :) = 0;
end

function [tx, rx, time_data] = fn_remove_pulse_echo_data(tx, rx, time_data)
pitch_catch_indices = find(tx ~= rx);
tx = tx(pitch_catch_indices);
rx = rx(pitch_catch_indices);
time_data = time_data(:, pitch_catch_indices);
end 
 
function [freq, freq_data, fft_pts] = fn_convert_to_freq_domain(time, time_data)
time_pts = size(time_data, 1);
fft_pts = 2 ^ nextpow2(time_pts);
freq_data = fft(time_data, fft_pts);
freq_data = freq_data(1:fft_pts / 2 + 1, :);
time_step = abs(time(1) - time(2));
freq_step = 1 / (fft_pts * time_step);
freq = [0:fft_pts / 2]' * freq_step;
tau = time(1);
freq_data = freq_data .* exp(-2 * pi * 1i * freq * tau);
end

% function raw_data = fn_filter_freq_domain_data(raw_data_in, input_signal, delay, freq_comp_for_input_signal, freq_filter_on, freq_filter, freq_filter_bandwidth, suppress_display);
function [freq_i1, freq_i2, freq_data] = fn_filter_freq_domain_data(freq, freq_data, freq_filter_on, freq_filter, freq_filter_bandwidth)
if freq_filter_on	
	filter = ones(length(freq), 1);
	
	% if freq_comp_for_input_signal
	% 	%calculate spectrum of input signal
	% 	time_step = abs(raw_data.time(1) - raw_data.time(2));
	% 	in_time = ([1:raw_data.fft_pts]-1) * time_step;
	% 	in_signal = 0.5 * sin(2 * pi * input_signal.freq * in_time) .* (1 - cos(2 * pi * input_signal.freq * in_time / input_signal.cycles)) .* (in_time < input_signal.cycles / input_signal.freq);
	% 	in_spec = fft(in_signal, raw_data.fft_pts);
	% 	in_spec = abs(in_spec(1:raw_data.fft_pts/2+1))';
	% 	in_valid = in_spec > 0;
	% 	in_spec(~in_valid) = 1;
	% 	filter = filter ./ in_spec;
	% 	filter(~in_valid) = 1;
	% end;
	
	max_freq = max(freq);
	filter = filter .* gaussian(length(freq), freq_filter / max_freq, freq_filter_bandwidth / max_freq);
	
	filter = filter / max(abs(filter));
	freq_i1 = min(find(filter > 0.01));
	freq_i2 = max(find(filter > 0.01));
	filter = filter * ones(1, size(freq_data, 2));
	
	freq_data = freq_data .* filter;
else
	temp = sum(abs(freq_data)');
	temp = temp / max(abs(temp));
	freq_i1 = min(find(temp > 0.01));
	freq_i2 = max(find(temp > 0.01));
end

end

function inv_mode_shapes = fn_inv_mode_shape_matrices(raw_tx, raw_rx, freq, raw_freq_data, ...
        array_row_pos, array_trans_pos, array_trans_row, array_trans_pos_orientations, array_delay, array_trans_node_list, ... %array
        disperse_freq, disperse_vph, disperse_vgr, disperse_waveno, disperse_ms_x, disperse_ms_y, disperse_ms_z, ...
        proc_tx_mode, proc_rx_mode, proc_tx_dir, proc_rx_dir, ...
        ms_matrix_calc_freqs, ms_matrix_modes_to_use)
no_time_traces = size(raw_freq_data, 2);
no_mode_combinations_proc = length(proc_tx_mode);
max_mode_index = max([max(proc_tx_mode), max(proc_rx_mode)]);
node_pts = size(disperse_ms_x, 2);
inv_mode_shapes = complex(zeros(no_mode_combinations_proc, no_time_traces, length(ms_matrix_calc_freqs)));
mode_shapes = complex(zeros(no_time_traces, no_mode_combinations_proc));
for ii=1:length(ms_matrix_calc_freqs)
	%interpolate to get mode shapes and wavenumbers of all the modes at the current frequency
	temp_mode_shape = complex(zeros(max_mode_index, node_pts, 3));
    
	temp_waveno = zeros(max_mode_index, 1);
    %Need to make this x, y and z (and perhaps normal and tangential also?)
    %so that the necessary direction can be selected when building the
    %matrix below. Also, this needs to take into account the phase
    %orientation of the transducers which is not currently used??
	for jj=1:length(ms_matrix_modes_to_use)
		temp_mode_shape(ms_matrix_modes_to_use(jj),:,1) = interp1( ...
			disperse_freq(:, 1, ms_matrix_modes_to_use(jj)), ...
			disperse_ms_x(:, :, ms_matrix_modes_to_use(jj)), ...
			ms_matrix_calc_freqs(ii),'PCHIP');  
		temp_mode_shape(ms_matrix_modes_to_use(jj),:,2) = interp1( ...
			disperse_freq(:, 1, ms_matrix_modes_to_use(jj)), ...
			disperse_ms_y(:, :, ms_matrix_modes_to_use(jj)), ...
			ms_matrix_calc_freqs(ii),'PCHIP');  
		temp_mode_shape(ms_matrix_modes_to_use(jj),:,3) = interp1( ...
			disperse_freq(:, 1, ms_matrix_modes_to_use(jj)), ...
			disperse_ms_z(:, :, ms_matrix_modes_to_use(jj)), ...
			ms_matrix_calc_freqs(ii),'PCHIP');  
		temp_waveno(ms_matrix_modes_to_use(jj)) = interp1( ...
			disperse_freq(:, 1, ms_matrix_modes_to_use(jj)), ...
			disperse_waveno(:, 1, ms_matrix_modes_to_use(jj)), ...
			ms_matrix_calc_freqs(ii),'PCHIP');
    end
	%build the mode shape matrix at this frequency, taking into account the
	%orientation of the transducers
	for jj=1:no_mode_combinations_proc
        for iii=1:no_time_traces
            mode_shapes(iii, jj) = ...
                dot(squeeze(temp_mode_shape(proc_tx_mode(jj), array_trans_node_list(array_trans_pos(raw_tx(iii))), :)), squeeze(array_trans_pos_orientations(raw_tx(iii), :))) * ...
                dot(squeeze(temp_mode_shape(proc_rx_mode(jj), array_trans_node_list(array_trans_pos(raw_rx(iii))), :)), squeeze(array_trans_pos_orientations(raw_rx(iii), :))) * ...
                exp(1i * temp_waveno(proc_tx_mode(jj)) * array_row_pos(array_trans_row(raw_tx(iii))) * proc_tx_dir(jj)) * ...
                exp(1i * temp_waveno(proc_rx_mode(jj)) * array_row_pos(array_trans_row(raw_rx(iii))) * proc_rx_dir(jj));
        end
    end
	mode_shapes(isnan(mode_shapes)) = 0;
	mode_shapes(isinf(mode_shapes)) = 0;
	inv_mode_shapes(:, :, ii) = pinv(mode_shapes);
end
end

function proc_freq_data = fn_mode_extract_freq_dom(...
    freq, raw_freq_data, freq_i1, freq_i2, ...
    inv_mode_shapes, ms_matrix_calc_freqs, ...
    ms_matrix_apply_as_time_shift, opts_ms_matrix_time_step_size, ms_matrix_allow_neg_amps)
%actually do the multiplication to convert the raw freq domain data
%to mode extracted freq domain data by one of two methods (single frequency mode shapes or interpolated frequency)
proc_freq_data = complex(zeros(size(raw_freq_data, 1), size(inv_mode_shapes, 1)));
% if length(size(inv_mode_shapes)) < 3
if numel(ms_matrix_calc_freqs) == 1
	inv_full_mode_shapes = squeeze(inv_mode_shapes(:, :, 1));
	if ~ms_matrix_apply_as_time_shift
		%normal frequency domain processing
		proc_freq_data(freq_i1:freq_i2, :) = raw_freq_data(freq_i1:freq_i2, :) * (inv_full_mode_shapes .');
	else
		%simulated time domain processing
		phase_angle = angle(inv_full_mode_shapes);
		amplitudes = abs(inv_full_mode_shapes); 
		if ms_matrix_allow_neg_amps
			ind = find(phase_angle > pi / 2);
			phase_angle(ind) = phase_angle(ind) - pi;
			amplitudes(ind) = -amplitudes(ind);
			ind = find(phase_angle < -pi / 2);
			phase_angle(ind) = phase_angle(ind) + pi;
			amplitudes(ind) = -amplitudes(ind);
        end
		
		time_shifts = phase_angle / (2 * pi * ms_matrix_calc_freqs);
		if opts_ms_matrix_time_step_size > 0
			time_shifts = round(time_shifts / opts_ms_matrix_time_step_size) * opts_ms_matrix_time_step_size;
        end
		for ii = freq_i1:freq_i2
			temp = amplitudes .* exp(1i * 2 * pi * freq(ii) * time_shifts);
			proc_freq_data(ii, :) = raw_freq_data(ii, :) * (temp .');
        end
    end
else
	for fcount = freq_i1:freq_i2
		inv_full_mode_shapes = complex(zeros(size(inv_mode_shapes, 1), size(inv_mode_shapes, 2)));
		for ii = 1:size(inv_mode_shapes, 1)
			yy = squeeze(inv_mode_shapes(ii, :, :)).';
			yi = interp1(ms_matrix_calc_freqs, yy, freq(fcount), 'linear');
			inv_full_mode_shapes(ii, :) = yi; 
        end
		inv_full_mode_shapes(isnan(inv_full_mode_shapes)) = 0;
		proc_freq_data(fcount, :) = raw_freq_data(fcount, :) * (inv_full_mode_shapes .');
    end
end
end

function [proc_time, proc_time_data] = fn_convert_freq_to_time_dom(freq, proc_freq_data, fft_pts)
freq_step = abs(freq(2) - freq(1));
time_step = 1 / (fft_pts * freq_step);
proc_time = [0:fft_pts - 1] * time_step;
proc_time_data = ifft(proc_freq_data, fft_pts);
end

function [proc_dist, proc_dist_data, modal_vgrs] = fn_convert_time_to_dist(proc_time, proc_time_data, ...
        proc_tx_mode, proc_rx_mode,  ...
    disperse_freq, disperse_vgr, disperse_waveno, ...
    ms_matrix_modes_to_use, freq_filter)
vgr = zeros(max(ms_matrix_modes_to_use), 1);
k = zeros(max(ms_matrix_modes_to_use), 1);
for ii=1:length(ms_matrix_modes_to_use)
    vgr(ms_matrix_modes_to_use(ii)) = interp1( ...
			disperse_freq(:, 1, ms_matrix_modes_to_use(ii)), ...
			disperse_vgr(:, 1, ms_matrix_modes_to_use(ii)), ...
			freq_filter,'PCHIP');
    k(ms_matrix_modes_to_use(ii)) = interp1( ...
			disperse_freq(:, 1, ms_matrix_modes_to_use(ii)), ...
			disperse_waveno(:, 1, ms_matrix_modes_to_use(ii)), ...
			freq_filter,'PCHIP');
end
modal_vgrs = vgr(:) .';
vgr = 1 ./ (1 ./ vgr(proc_tx_mode) + 1 ./ vgr(proc_rx_mode));

%set up distance axis
max_dist = max(vgr) * max(proc_time);
dist_step = 1 / (2 * max(k));
proc_dist = [0:round(max_dist/dist_step)]' * dist_step;

% disp(num2str(length(proc_data_out.dist)))

proc_dist_data = complex(zeros(length(proc_dist), length(proc_tx_mode)));

%interpolate from time data
for ii = 1:size(proc_dist_data, 2)
	temp_dist = proc_time * vgr(ii);
	proc_dist_data(:, ii) = interp1(temp_dist, abs(proc_time_data(:, ii)), proc_dist, 'linear', 0);
end

end

function proc_dist_data = fn_apply_dist_warps(proc_dist, proc_dist_data, proc_tx_mode, proc_rx_mode, modal_vgrs, modal_warps)
warp_factors = fn_calc_warp_factors(modal_warps, modal_vgrs, proc_tx_mode, proc_rx_mode);


for ii = 1:size(proc_dist_data, 2)
    old_dist = proc_dist / warp_factors(ii);
    proc_dist_data(:, ii) = interp1(old_dist, proc_dist_data(:, ii), proc_dist, 'linear', 0);
end
end

function warp_factors = fn_calc_warp_factors(modal_warps, modal_vgrs, proc_tx_mode, proc_rx_mode)
u1 = modal_vgrs(proc_tx_mode(:));
u2 = modal_vgrs(proc_rx_mode(:));
v1 = modal_vgrs(proc_tx_mode(:)) .* modal_warps(proc_tx_mode(:));
v2 = modal_vgrs(proc_rx_mode(:)) .* modal_warps(proc_rx_mode(:));
warp_factors = (1 ./ u1 + 1 ./ u2) ./ (1 ./ v1 + 1 ./ v2);
end