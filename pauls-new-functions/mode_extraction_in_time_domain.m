function out = mode_extraction_in_time_domain(inv_mode_shapes, raw_data, ms_freq, suppress_display);
tic;
%time_data = apply_time_delays(time, in_time_data, time_delay);
out.time = raw_data.time;
time_pts = size(raw_data.time_data, 1);
time_data_width = size(raw_data.time_data, 2);
time_step = abs(out.time(1) - out.time(2));
out.time_data = zeros(time_pts, size(inv_mode_shapes, 1));
time_delay_steps = -round(angle(inv_mode_shapes) / (2 * pi * ms_freq) / time_step);
min_delay_step = min(min(time_delay_steps));
max_delay_step = max(max(time_delay_steps));
amp_weights = abs(inv_mode_shapes);
start_row = 1;
if min_delay_step < 0
    start_row = abs(min_delay_step) + 1;
    raw_data.time_data = [zeros(start_row, time_data_width); raw_data.time_data];
end;
if max_delay_step > 0
    raw_data.time_data = [raw_data.time_data; zeros(abs(max_delay_step),time_data_width)];
end;
new_time_pts = size(raw_data.time_data, 1);
for ii = 1:size(inv_mode_shapes, 1)
	temp = ones(new_time_pts, 1) * time_delay_steps(ii,:) + ...
 	   [-start_row:new_time_pts - start_row - 1]' * ones(1, time_data_width);
   	weights = ones(time_pts ,1) * amp_weights(ii,:);
	out.time_data(:,ii) = sum( ...
		(...
			reshape( ...
				raw_data.time_data(find(temp >= 0 & temp < time_pts)), time_pts, time_data_width...
				) ...
			.* weights ...
			) .' ...
		).' ;
	%amp weights need to go in here ish
	disp(ii);
end;
out.time_data = hilbert(out.time_data);
if ~suppress_display
	disp(['Modes extracted in time domain: ',num2str(toc)]);
end;
return;
