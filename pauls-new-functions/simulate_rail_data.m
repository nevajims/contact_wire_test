function rail_tester = simulate_rail_data(array, disperse, input_signal, features, tx_pos, tx_row, rx_pos, rx_row, options);
default_options.time_step = 5e-6;
default_options.min_vgr = 1e3;
default_options.db_down = 40;
default_options.safety_factor = 1.5;
default_options.interp_method = 'linear';
options = set_default_fields(options, default_options);


%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%copy basic stuff
rail_tester.array = array;
rail_tester.disperse = disperse;
rail_tester.input_signal = input_signal;
rail_tester.raw_data.tx_pos = tx_pos;
rail_tester.raw_data.tx_row = tx_row;
rail_tester.raw_data.rx_pos = rx_pos;
rail_tester.raw_data.rx_row = rx_row;

%find max feature distance
max_dist = 0;
for ii = 1:length(features)
	if abs(features(ii).pos) > max_dist
		max_dist = abs(features(ii).pos);
	end;
end;

%sort out time pts
max_time = max_dist / options.min_vgr * 2 * options.safety_factor;
time_step = options.time_step;
time_pts = ceil(max_time / time_step);

%simulate input signal
[time, in_time_sig, rail_tester.raw_data.freq, in_freq_spec, rail_tester.raw_data.fft_pts] = create_input_signal(...
	time_pts, ...
	rail_tester.input_signal.freq, ...
	time_step, ...
	input_signal.cycles);
[min_freq, cent_freq, max_freq, min_freq_index, cent_index, max_freq_index] = calculate_bandwidth_of_spectrum(...
	rail_tester.raw_data.freq, ...
	in_freq_spec, ...
	options.db_down);

%set up the results matrix
rail_tester.raw_data.freq_data = zeros(rail_tester.raw_data.fft_pts / 2 + 1, length(rail_tester.raw_data.tx_pos));

%the main loop
for fi = min_freq_index:max_freq_index %through frequency
	for ri = 1:length(features) %through the features
		[ii, jj] = find(features(ri).refl_coeff);
		inc_mi = features(ri).modes(ii);
		ref_mi = features(ri).modes(jj);
		inc_d = abs(features(ri).pos - rail_tester.array.row_pos(rail_tester.raw_data.tx_row));
		ref_d = abs(features(ri).pos - rail_tester.array.row_pos(rail_tester.raw_data.rx_row));
		for mi = 1:length(inc_mi) %through the incident and reflected modes for that feature
			inc_k = interp1(rail_tester.disperse.mode(inc_mi(mi)).freq, rail_tester.disperse.mode(inc_mi(mi)).waveno, rail_tester.raw_data.freq(fi), options.interp_method, 0);
			ref_k = interp1(rail_tester.disperse.mode(ref_mi(mi)).freq, rail_tester.disperse.mode(ref_mi(mi)).waveno, rail_tester.raw_data.freq(fi), options.interp_method, 0);
			inc_v = interp1(rail_tester.disperse.mode(inc_mi(mi)).freq, rail_tester.disperse.mode(inc_mi(mi)).vgr, rail_tester.raw_data.freq(fi), options.interp_method, 0);
			ref_v = interp1(rail_tester.disperse.mode(ref_mi(mi)).freq, rail_tester.disperse.mode(ref_mi(mi)).vgr, rail_tester.raw_data.freq(fi), options.interp_method, 0);
         	inc_disp = interp1(rail_tester.disperse.mode(ref_mi(mi)).freq, rail_tester.disperse.mode(ref_mi(mi)).ms_z(:, rail_tester.raw_data.tx_pos), rail_tester.raw_data.freq(fi), options.interp_method, 0);
         	ref_disp = interp1(rail_tester.disperse.mode(ref_mi(mi)).freq, rail_tester.disperse.mode(ref_mi(mi)).ms_z(:, rail_tester.raw_data.rx_pos), rail_tester.raw_data.freq(fi), options.interp_method, 0);
			if inc_v > default_options.min_vgr | ref_v > default_options.min_vgr
				rail_tester.raw_data.freq_data(fi, :) = rail_tester.raw_data.freq_data(fi, :) + ...
					in_freq_spec(fi) * ...
					features(ri).refl_coeff(ii(mi), jj(mi)) * ...
					exp(-2 * pi * i * (inc_k * inc_d + ref_k * ref_d)) .* ...
					inc_disp .* ref_disp * rail_tester.raw_data.freq(fi);
			end;
		end;
	end;
	show_progress(fi - min_freq_index, max_freq_index - min_freq_index);
end;

%back to time domain
rail_tester.raw_data.time_data = ifft(rail_tester.raw_data.freq_data, rail_tester.raw_data.fft_pts);
rail_tester.raw_data.time_data = real(rail_tester.raw_data.time_data(1:time_pts, :));
rail_tester.raw_data.time = ([1:time_pts] - 1) * time_step;

return;