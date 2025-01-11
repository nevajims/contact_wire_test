function raw_data_out = remove_pulse_echo_data(raw_data, suppress_display);
tic;
no_time_traces = size(raw_data.time_data, 2);
not_pulse_echo = ones(1,no_time_traces);
for tt_count=1:no_time_traces;
	if (raw_data.tx_pos(tt_count)==raw_data.rx_pos(tt_count))&(raw_data.tx_row(tt_count)==raw_data.rx_row(tt_count))
		not_pulse_echo(tt_count)=0;
	end;
end;
pitch_catch_indices=find(not_pulse_echo);
no_time_traces=length(pitch_catch_indices);

raw_data_out = raw_data;
raw_data_out.tx_pos = raw_data.tx_pos(pitch_catch_indices);
raw_data_out.tx_row = raw_data.tx_row(pitch_catch_indices);
raw_data_out.rx_pos = raw_data.rx_pos(pitch_catch_indices);
raw_data_out.rx_row = raw_data.rx_row(pitch_catch_indices);
raw_data_out.time_data = raw_data.time_data(:, pitch_catch_indices);
if isfield(raw_data, 'freq_data')
	raw_data_out.freq_data = raw_data.freq_data(:, pitch_catch_indices);
end;
if ~suppress_display
	disp(['Pulse-echo data removed: ',num2str(toc)]);
end;
return;