function inv_mode_shapes = fn_inv_mode_shape_matrices(raw_data, proc_data, array, disperse, ms_matrix_calc_freqs, ms_matrix_modes_to_use, suppress_display);
tic;
no_time_traces = size(raw_data.time_data, 2);
no_mode_combos = length(proc_data.tx_mode);
max_mode_index = max([max(proc_data.tx_mode), max(proc_data.rx_mode)]);
no_freqs = length(ms_matrix_calc_freqs);

%Reduce mode shapes to just values at transducer positions
for m = 1:numel(disperse.mode)
    disperse.mode(m).ms_x = disperse.mode(m).ms_x(:, array.trans_node_list);
    disperse.mode(m).ms_y = disperse.mode(m).ms_y(:, array.trans_node_list);
    disperse.mode(m).ms_z = disperse.mode(m).ms_z(:, array.trans_node_list);
end

%Interpolate onto calc frequencies and drop superfluous stuff to avoid
%confusion
for m = 1:numel(disperse.mode)
    disperse.mode(m).ms_x = interp1(disperse.mode(m).freq, disperse.mode(m).ms_x, ms_matrix_calc_freqs);
    disperse.mode(m).ms_y = interp1(disperse.mode(m).freq, disperse.mode(m).ms_y, ms_matrix_calc_freqs);
    disperse.mode(m).ms_z = interp1(disperse.mode(m).freq, disperse.mode(m).ms_z, ms_matrix_calc_freqs);
    disperse.mode(m).waveno = interp1(disperse.mode(m).freq, disperse.mode(m).waveno, ms_matrix_calc_freqs);
    disperse.mode(m).freq = ms_matrix_calc_freqs;
end
disperse.mode = rmfield(disperse.mode, 'vph');
disperse.mode = rmfield(disperse.mode, 'vgr');

inv_mode_shapes = zeros(no_mode_combos, no_time_traces, no_freqs);
mode_shapes = zeros(no_time_traces, no_mode_combos);
for i = 1:no_freqs
	for j = 1:no_mode_combos
        tx_md = proc_data.tx_mode(j);
        rx_md = proc_data.rx_mode(j);
        tx_dir = proc_data.tx_dir(j);
        rx_dir = proc_data.rx_dir(j);
        tx_ms_dir_vev = [1, 1, -tx_dir];
        rx_ms_dir_vev = [1, 1, -rx_dir];
        tx_k = disperse.mode(tx_md).waveno(i);
        rx_k = disperse.mode(rx_md).waveno(i);
        for k = 1:no_time_traces
            % tx_row = array.trans_row(raw_data.tx(k));
            % rx_row = array.trans_row(raw_data.rx(k));
            tx_pos = array.trans_pos(raw_data.tx(k));
            rx_pos = array.trans_pos(raw_data.rx(k));
            tx_vec = array.trans_pos_orientations(raw_data.tx(k), :);
            rx_vec = array.trans_pos_orientations(raw_data.rx(k), :);
            tx_ms = [disperse.mode(tx_md).ms_x(i, tx_pos), disperse.mode(tx_md).ms_y(i, tx_pos), disperse.mode(tx_md).ms_z(i, tx_pos)] .* tx_ms_dir_vev;
            rx_ms = [disperse.mode(rx_md).ms_x(i, rx_pos), disperse.mode(rx_md).ms_y(i, rx_pos), disperse.mode(rx_md).ms_z(i, rx_pos)] .* rx_ms_dir_vev;
            tx_z = array.row_pos(array.trans_row(raw_data.tx(k)));
            rx_z = array.row_pos(array.trans_row(raw_data.rx(k)));
            mode_shapes(k, j) = ...
                exp(1i * tx_k * tx_z * tx_dir) * exp(1i * rx_k * rx_z * rx_dir) * ...
                dot(tx_ms, tx_vec) * dot(rx_ms, rx_vec);
        end
    end
    inv_mode_shapes(:,:,i) = pinv(mode_shapes);
end


if ~suppress_display
	disp(['Inverse mode shape matrix built: ',num2str(toc)]);
end
return