function time_data = apply_time_delays(time, in_time_data, time_delays);
time_step = abs(time(1) - time(2));
time_delay_steps = round(time_delays / time_step);
min_delay_step = min(time_delay_steps);
max_delay_step = max(time_delay_steps);
time_points = size(in_time_data, 1);
time_data_width = size(in_time_data, 2);
start_row = 1;
if min_delay_step < 0
    start_row = abs(min_delay_step) + 1;
    in_time_data = [zeros(start_row, time_data_width); in_time_data];
end;
if max_delay_step > 0
    in_time_data = [in_time_data; zeros(abs(max_delay_step),time_data_width)];
end;

%delayed_end_row = delayed_start_row + time_points - 1;

temp = ones(size(in_time_data,1), 1) * time_delay_steps + ...
    [-start_row:size(in_time_data,1) - start_row - 1]' * ones(1, time_data_width);

%keyboard;

time_data = reshape(in_time_data(find(temp >= 0 & temp < time_points)), time_points, time_data_width);
return;


