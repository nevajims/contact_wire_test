function out = fn_convert_freq_to_time_dom(in, suppress_display);
tic;
freq_step = abs(in.freq(2) - in.freq(1));
time_step = 1 / (in.fft_pts * freq_step);
out.time = [0:in.fft_pts - 1] * time_step;
out.time_data = ifft(in.freq_data, in.fft_pts);
if ~suppress_display
	disp(['Returned to time domain: ',num2str(toc)]);
end;
return;