function fn_plot_dna_rail_data(rail_tester, options);
default_options.db_range = 30;
default_options.max_range = -1; %-ve for auto
default_options.modes = [3, 5, 7, 8, 10];
default_options.show_pulse_echo_modes_first = 1;
default_options.flip_left_right = 0;
default_options.show_forward = 1;
default_options.show_backward = 1;

options = set_default_fields(options, default_options);

if ~isfield(rail_tester, 'proc_data')
    disp('No processed data available!');
    return;
end;

%find indices of modes to plot
if default_options.flip_left_right
    flip = -1;
else
    flip = 1;
end;

tx_modes = options.modes(:) * ones(size(options.modes(:)))';
rx_modes = tx_modes';
tx_modes = tx_modes(:);
rx_modes = rx_modes(:);

if options.show_pulse_echo_modes_first
    pe_indices = find(tx_modes == rx_modes);
    pc_indices = find(tx_modes ~= rx_modes);
    tx_modes = [tx_modes(pe_indices); tx_modes(pc_indices)];
    rx_modes = [rx_modes(pe_indices); rx_modes(pc_indices)];
end;

fwd_plot_indices = zeros(size(tx_modes));
bwd_plot_indices = zeros(size(tx_modes));
for ii = 1:length(fwd_plot_indices);
    fwd_plot_indices(ii) = find(rail_tester.proc_data.tx_dir == flip & ...
        rail_tester.proc_data.rx_dir == flip & ...
        rail_tester.proc_data.tx_mode == tx_modes(ii) & ...
        rail_tester.proc_data.rx_mode == rx_modes(ii));
    bwd_plot_indices(ii) = find(rail_tester.proc_data.tx_dir == -flip & ...
        rail_tester.proc_data.rx_dir == -flip & ...
        rail_tester.proc_data.tx_mode == tx_modes(ii) & ...
        rail_tester.proc_data.rx_mode == rx_modes(ii));
end;

plot_data.x = [-flipud(rail_tester.proc_data.dist);rail_tester.proc_data.dist];
plot_data.z = [flipud(rail_tester.proc_data.dist_data(:, bwd_plot_indices));rail_tester.proc_data.dist_data(:, fwd_plot_indices)];
plot_data.z = plot_data.z';

if options.max_range < 0
    max_dist = max(abs(plot_data.x));
else
    max_dist = options.max_range;
end;
min_x = 0;

plot_data.z = abs(plot_data.z) / max(max(abs(plot_data.z)));
plot_data.z = 20 * log10(plot_data.z) + options.db_range;

%this next crap just because of the stupid surf convention of ignoring last row/column
plot_data.z = [plot_data.z; zeros(1, size(plot_data.z, 2))];
plot_data.z = [plot_data.z, zeros(size(plot_data.z, 1), 1)];
plot_data.x = [plot_data.x; 0];

max_z = options.db_range;
min_z = 0;

clf;
surf(plot_data.x, [1:length(tx_modes)+1], plot_data.z);
shading flat;
caxis([0, options.db_range]);
view(2);
colorbar;

max_x = 0;
min_x = 0;
if options.show_forward
    max_x = max_dist;
end;
if options.show_backward
    min_x = -max_dist;
end;
xlim([min_x, max_x]);
ylim([1, size(plot_data.z,1)]);
temp = ylim; min_y = temp(1); max_y = temp(2);
axis off;

%show mode labels
for ii = 1:length(tx_modes);
    a = text(min_x - (max_x - min_x) / 50, ii + 0.5, sprintf('%i-%i',tx_modes(ii), rx_modes(ii)));
    set(a, 'HorizontalAlignment', 'right');
    set(a, 'VerticalAlignment', 'middle');
end;

%show distance labels
a = text(min_x, min_y - (max_y - min_y) / 50, sprintf('%.1f', min_x));
set(a, 'HorizontalAlignment', 'center');
set(a, 'VerticalAlignment', 'top');
a = text(max_x, min_y - (max_y - min_y) / 50, sprintf('%.1f', max_x));
set(a, 'HorizontalAlignment', 'center');
set(a, 'VerticalAlignment', 'top');
a = text((max_x + min_x) / 2, min_y - (max_y - min_y) / 50, 'Distance (m)');
set(a, 'HorizontalAlignment', 'center');
set(a, 'VerticalAlignment', 'top');

return;