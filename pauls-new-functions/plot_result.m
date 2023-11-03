function plot_result(rail_tester, options);
default_options.plot_what = 1;%1 - modes vs. distance, 2 - raw data vs. time (not implemented)
default_options.db_scale = 1;%only relevant for 1 and 2
default_options.db_range = 40;
default_options.max_range = -1; %-ve for auto
default_options.tx_modes = [3, 5, 7, 8, 10];%must be same length as rx modes
default_options.rx_modes = default_options.tx_modes;
default_options.flip_left_right = 0;
default_options.show_forward = 1;
default_options.show_backward = 1;

options = set_default_fields(options, default_options);

%find indices of modes to plot
if default_options.flip_left_right
	flip = -1;
else
	flip = 1;
end;
fwd_plot_indices = zeros(length(rail_tester.proc_data.rx_mode), 1);
fwd_plot_count = 1;
for ii = 1:length(options.tx_modes)
	fwd_plot_indices(fwd_plot_count) = find( ...
		rail_tester.proc_data.tx_mode == options.tx_modes(ii) & ...
		rail_tester.proc_data.rx_mode == options.rx_modes(ii) & ...
		rail_tester.proc_data.tx_dir == 1 * flip & ...
		rail_tester.proc_data.rx_dir == 1 * flip);
	fwd_plot_count = fwd_plot_count + 1;
end;
if fwd_plot_count > 1
	fwd_plot_indices = fwd_plot_indices(1:fwd_plot_count - 1);
end;

bwd_plot_indices = zeros(length(rail_tester.proc_data.rx_mode), 1);
bwd_plot_count = 1;
for ii = 1:length(options.tx_modes)
	bwd_plot_indices(bwd_plot_count) = find( ...
		rail_tester.proc_data.tx_mode == options.tx_modes(ii) & ...
		rail_tester.proc_data.rx_mode == options.rx_modes(ii) & ...
		rail_tester.proc_data.tx_dir == -1 * flip & ...
		rail_tester.proc_data.rx_dir == -1 * flip);
	bwd_plot_count = bwd_plot_count + 1;
end;
if bwd_plot_count > 1
	bwd_plot_indices = bwd_plot_indices(1:bwd_plot_count - 1);
end;

switch options.plot_what
case 1
	plot_data.x = rail_tester.proc_data.dist;
	plot_data.y = rail_tester.proc_data.dist_data;
case 2
case 3
otherwise
	return;
end;

if options.max_range < 0
	max_x = max(abs(plot_data.x));
else
	max_x = options.max_range;
end;
min_x = 0;

max_y = max(max(abs(plot_data.y)));
if options.db_scale  & options.plot_what == 1
	plot_data.y = abs(plot_data.y) / max_y;
	invalid = find(plot_data.y == 0);
	plot_data.y(invalid) = 1;
	plot_data.y =20 * log10(plot_data.y) + options.db_range;
	plot_data.y(invalid) = 0;
	plot_data.y(find(plot_data.y < 0)) = 0;
	max_y = options.db_range;
	min_y = 0;
else
	plot_data.y = real(plot_data.y) / max_y;
	max_y = 1;
	min_y = 0;
end;

if options.show_forward & options.show_backward
	cols = 2;
	fac = 2;
else
	cols = 1;
	fac = 1;
end;
if options.show_backward & ~options.show_forward
	offset = 0;
else
	offset = -1;
end;
rows = max([length(bwd_plot_indices), length(fwd_plot_indices)]);

clf;

for ii = 1:length(fwd_plot_indices);
	if options.show_forward
		subplot(rows, cols, ii * fac);
		plot(plot_data.x, plot_data.y(:,fwd_plot_indices(ii)));
		axis([min_x, max_x, min_y, max_y]);
	end;
	if options.show_backward
		subplot(rows, cols, ii * fac +offset);
		plot(-plot_data.x, plot_data.y(:, bwd_plot_indices(ii)));
		axis([-max_x, min_x, min_y, max_y]);
	end;
end;