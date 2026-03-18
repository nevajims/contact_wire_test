function raw_data = fn_convert_to_freq_domain_for_dll(time, time_data, suppress_display)
tic;
time_pts = size(time_data, 1);
raw_data.fft_pts = 2 ^ nextpow2(time_pts);
raw_data.freq_data = fft(time_data, raw_data.fft_pts);
raw_data.freq_data = raw_data.freq_data(1:raw_data.fft_pts/2+1, :);
time_step = abs(time(1) - time(2));
freq_step = 1 / (raw_data.fft_pts * time_step);
raw_data.freq = [0:raw_data.fft_pts / 2]' * freq_step;
tau = time(1);
raw_data.freq_data = raw_data.freq_data .* exp(-2 * pi * 1i * raw_data.freq * tau);
if ~suppress_display
	disp(['Raw data converted to frequency domain: ',num2str(toc)]);
end;
return;