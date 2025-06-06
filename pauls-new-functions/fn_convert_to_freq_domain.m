function raw_data = fn_convert_to_freq_domain(raw_data_in, suppress_display)
tic;
raw_data = raw_data_in;
time_pts = size(raw_data.time_data, 1);
raw_data.fft_pts = 2 ^ nextpow2(time_pts);
raw_data.freq_data = fft(raw_data.time_data, raw_data.fft_pts);
raw_data.freq_data = raw_data.freq_data(1:raw_data.fft_pts/2+1, :);
time_step = abs(raw_data.time(1)- raw_data.time(2));
freq_step = 1 / (raw_data.fft_pts * time_step);
raw_data.freq = [0:raw_data.fft_pts / 2]' * freq_step;
tau = raw_data.time(1);
raw_data.freq_data = raw_data.freq_data .* exp(-2 * pi * 1i * raw_data.freq * tau);
if ~suppress_display
	disp(['Raw data converted to frequency domain: ',num2str(toc)]);
end;
return;