function out_time_data = return_to_time_domain(out_freq_data, suppress_display);
tic;
fft_pts = 2 ^ nextpow2(out_freq_data.i2);
freq_step = abs(out_freq_data.freq(2) - out_freq_data.freq(1));
time_step = 1 / (fft_pts * freq_step);
out_time_data.time_trace = ifft(out_freq_data.spectrum, fft_pts);
out_time_data.time = [0:fft_pts - 1] * time_step;
if ~suppress_display
	disp(['Returned to time domain: ',num2str(toc)]);
end;
return;