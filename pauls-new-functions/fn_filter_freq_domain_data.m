function raw_data = fn_filter_freq_domain_data(raw_data_in, input_signal, delay, freq_comp_for_input_signal, freq_filter_on, freq_filter, freq_filter_bandwidth, suppress_display);
tic;
raw_data = raw_data_in;
if freq_filter_on	
	filter = ones(length(raw_data.freq), 1);
	
	if freq_comp_for_input_signal
		%calculate spectrum of input signal
		time_step = abs(raw_data.time(1) - raw_data.time(2));
		in_time = ([1:raw_data.fft_pts]-1) * time_step;
		in_signal = 0.5 * sin(2 * pi * input_signal.freq * in_time) .* (1 - cos(2 * pi * input_signal.freq * in_time / input_signal.cycles)) .* (in_time < input_signal.cycles / input_signal.freq);
		in_spec = fft(in_signal, raw_data.fft_pts);
		in_spec = abs(in_spec(1:raw_data.fft_pts/2+1))';
		in_valid = in_spec > 0;
		in_spec(~in_valid) = 1;
		filter = filter ./ in_spec;
		filter(~in_valid) = 1;
	end;
	
	max_freq = max(raw_data.freq);
	filter = filter .* gaussian(length(raw_data.freq), freq_filter / max_freq, freq_filter_bandwidth / max_freq);
	
	filter = filter / max(abs(filter));
	raw_data.freq_i1 = min(find(filter > 0.01));
	raw_data.freq_i2 = max(find(filter > 0.01));
	filter = filter * ones(1, size(raw_data.freq_data, 2));
	
	raw_data.freq_data = raw_data.freq_data .* filter;
else
	temp = sum(abs(raw_data.freq_data)');
	temp = temp / max(abs(temp));
	raw_data.freq_i1 = min(find(temp > 0.01));
	raw_data.freq_i2 = max(find(temp > 0.01));
end;

if ~suppress_display
	disp(['Filtering complete: ',num2str(toc)]);
end;
return;