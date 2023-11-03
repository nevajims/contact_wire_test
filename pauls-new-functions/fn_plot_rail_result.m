function fn_plot_rail_result(rail_tester, options)
default_options.db_range = 30;
default_options.max_range = -1; %-ve for auto
default_options.tx_modes = [1,2,3,4];%must be same length as tx modes
default_options.rx_modes = default_options.tx_modes;%must be same length as tx modes
default_options.flip_left_right = 0;
default_options.show_forward = 1;
default_options.show_backward = 1;
default_options.transmit_delay_m = 0;
options = set_default_fields(options, default_options);

if ~isfield(rail_tester, 'proc_data')
    disp('No processed data available!');
    return;
end

%find indices of modes to plot
if default_options.flip_left_right
    flip = -1;
else
    flip = 1;
end
fwd_plot_indices = zeros(length(rail_tester.proc_data.rx_mode), 1);
fwd_plot_count = 1;
for ii = 1:length(options.tx_modes)
    fwd_plot_indices(fwd_plot_count) = find( ...
        rail_tester.proc_data.tx_mode == options.tx_modes(ii) & ...
        rail_tester.proc_data.rx_mode == options.rx_modes(ii) & ...
        rail_tester.proc_data.tx_dir == 1 * flip & ...
        rail_tester.proc_data.rx_dir == 1 * flip);
    fwd_plot_count = fwd_plot_count + 1;
end
if fwd_plot_count > 1
    fwd_plot_indices = fwd_plot_indices(1:fwd_plot_count - 1);
end

bwd_plot_indices = zeros(length(rail_tester.proc_data.rx_mode), 1);
bwd_plot_count = 1;
for ii = 1:length(options.tx_modes)
    bwd_plot_indices(bwd_plot_count) = find( ...
        rail_tester.proc_data.tx_mode == options.tx_modes(ii) & ...
        rail_tester.proc_data.rx_mode == options.rx_modes(ii) & ...
        rail_tester.proc_data.tx_dir == -1 * flip & ...
        rail_tester.proc_data.rx_dir == -1 * flip);
    bwd_plot_count = bwd_plot_count + 1;
end
if bwd_plot_count > 1
    bwd_plot_indices = bwd_plot_indices(1:bwd_plot_count - 1);
end

plot_data.x = rail_tester.proc_data.dist;
plot_data.y = rail_tester.proc_data.dist_data;

if options.max_range < 0
    max_x = max(abs(plot_data.x));
else
    max_x = options.max_range;
end
min_x = 0;

max_y = max(max(abs(plot_data.y)));
plot_data.y = abs(plot_data.y) / max_y;
invalid = find(plot_data.y == 0);
plot_data.y(invalid) = 1;
plot_data.y =20 * log10(plot_data.y) + options.db_range;
plot_data.y(invalid) = 0;
plot_data.y(find(plot_data.y < 0)) = 0;
max_y = options.db_range;
min_y = 0;

if options.show_forward & options.show_backward
    cols = 2;
    fac = 2;
else
    cols = 1;
    fac = 1;
end
if options.show_backward & ~options.show_forward
    offset = 0;
else
    offset = -1;
end
rows = max([length(bwd_plot_indices), length(fwd_plot_indices)]);

clf;

for ii = 1:length(fwd_plot_indices)
    if options.show_forward
        subplot(rows, cols, ii * fac);
        plot(plot_data.x, plot_data.y(:,fwd_plot_indices(ii)));
        axis([min_x+options.transmit_delay_m, max_x, min_y, max_y]);
        if ii < length(fwd_plot_indices)
            set(gca, 'XTickLabel', []);
        else
            xlabel('Distance (m)');
        end
    end
    if options.show_backward
        subplot(rows, cols, ii * fac +offset);
        plot(-plot_data.x, plot_data.y(:, bwd_plot_indices(ii)));
        axis([-max_x, min_x-options.transmit_delay_m, min_y, max_y]);
        if ii < length(fwd_plot_indices)
            set(gca, 'XTickLabel', []);
        else
            xlabel('Distance (m)');
        end
    end
    ylabel(sprintf('%i-%i', options.tx_modes(ii), options.rx_modes(ii)));
end