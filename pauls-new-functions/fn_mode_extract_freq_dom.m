function out = fn_mode_extract_freq_dom(inv_mode_shapes, matrix_calc_freqs, raw_data, proc_data, apply_as_time_shift, min_time_step, allow_neg_amps, suppress_display);
tic;
%actually do the multiplication to convert the raw freq domain data
%to mode extracted freq domain data by one of two methods (single frequency mode shapes or interpolated frequency)
out.fft_pts = raw_data.fft_pts;
out.freq = raw_data.freq;
out.freq_data = zeros(size(raw_data.freq_data, 1), size(inv_mode_shapes, 1));
if length(size(inv_mode_shapes)) < 3;
	inv_full_mode_shapes = squeeze(inv_mode_shapes(:, :, 1));
	if ~apply_as_time_shift
		%normal frequency domain processing
		out.freq_data(raw_data.freq_i1:raw_data.freq_i2, :) = raw_data.freq_data(raw_data.freq_i1:raw_data.freq_i2, :) * (inv_full_mode_shapes .');
	else
		%simulated time domain processing
		phase_angle = angle(inv_full_mode_shapes);
		amplitudes = abs(inv_full_mode_shapes); 
		if allow_neg_amps
			ind = find(phase_angle > pi / 2);
			phase_angle(ind) = phase_angle(ind) - pi;
			amplitudes(ind) = -amplitudes(ind);
			ind = find(phase_angle < -pi / 2);
			phase_angle(ind) = phase_angle(ind) + pi;
			amplitudes(ind) = -amplitudes(ind);
		end;
		
		time_shifts = phase_angle / (2 * pi * matrix_calc_freqs);
		if min_time_step > 0
			time_shifts = round(time_shifts / min_time_step) * min_time_step;
		end;
		for ii = raw_data.freq_i1:raw_data.freq_i2
			temp = amplitudes .* exp(i * 2 * pi * raw_data.freq(ii) * time_shifts);
			out.freq_data(ii, :) = raw_data.freq_data(ii, :) * (temp .');
		end;
		write_matrix_files(time_shifts, amplitudes, raw_data, proc_data, 'time_shifts_bidi_method2_unrounded.txt', 'amps_bidi_method2.txt', 'modes.txt', 'trans.txt');
	end;
else
	for fcount = raw_data.freq_i1:raw_data.freq_i2
		inv_full_mode_shapes = zeros(size(inv_mode_shapes,1),size(inv_mode_shapes,2));
		for ii=1:size(inv_mode_shapes,1)
			yy = squeeze(inv_mode_shapes(ii, :, :)).';
			yi = interp1(matrix_calc_freqs, yy, raw_data.freq(fcount), 'linear');
			inv_full_mode_shapes(ii, :) = yi; 
		end;
		inv_full_mode_shapes(find(isnan(inv_full_mode_shapes))) = 0;
		out.freq_data(fcount,:) = raw_data.freq_data(fcount,:) * (inv_full_mode_shapes .');
	end;
end;
if ~suppress_display
	disp(['Modes extracted in frequency domain: ',num2str(toc)]);
end;
return;

function write_matrix_files(time_shifts, amplitudes, raw_data, proc_data, shift_fname, amp_fname, mode_fname, trans_fname)
shift_fid = fopen(shift_fname, 'wt');
amp_fid = fopen(amp_fname, 'wt');
mode_fid = fopen(mode_fname, 'wt');
fprintf(mode_fid, 'TxMode\tTxDir\tRxMode\tRxDir\n');
for ii = 1:size(time_shifts, 1)
	if proc_data.tx_dir(ii) == proc_data.rx_dir(ii)
		fprintf(shift_fid, '%e\t', time_shifts(ii, 1:end-1));
		fprintf(shift_fid, '%e\n', time_shifts(ii, end));
		fprintf(amp_fid, '%e\t', amplitudes(ii, 1:end-1));
		fprintf(amp_fid, '%e\n', amplitudes(ii, end));
		fprintf(mode_fid, '%i\t%i\t%i\t%i\n', proc_data.tx_mode(ii), proc_data.tx_dir(ii), proc_data.rx_mode(ii), proc_data.rx_dir(ii));
	end;
end;
fclose(shift_fid);
fclose(amp_fid);
fclose(mode_fid);

trans_fid = fopen(trans_fname, 'wt');
fprintf(trans_fid, 'TxRow\tTxPos\tRxRow\tRxPos\n');
for ii = 1:length(raw_data.tx_row)
	fprintf(trans_fid, '%i\t%i\t%i\t%i\n', raw_data.tx_row(ii), raw_data.tx_pos(ii), raw_data.rx_row(ii), raw_data.rx_pos(ii));
end;
fclose(trans_fid);
return;