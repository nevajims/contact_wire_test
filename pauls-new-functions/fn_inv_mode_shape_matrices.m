function inv_mode_shapes = fn_inv_mode_shape_matrices(raw_data, proc_data, array, disperse, ms_matrix_calc_freqs, ms_matrix_modes_to_use, suppress_display);
tic;
no_time_traces = size(raw_data.time_data, 2);
no_mode_combinations_proc = length(proc_data.tx_mode);
max_mode_index = max([max(proc_data.tx_mode), max(proc_data.rx_mode)]);
node_pts = size(disperse.mode(1).ms_x,2);
inv_mode_shapes = zeros(no_mode_combinations_proc, no_time_traces, length(ms_matrix_calc_freqs));
mode_shapes = zeros(no_time_traces, no_mode_combinations_proc);
for ii=1:length(ms_matrix_calc_freqs)
	%interpolate to get mode shapes and wavenumbers of all the modes at the current frequency
	temp_mode_shape = zeros(max_mode_index, node_pts);
	temp_waveno = zeros(max_mode_index, 1);
	for jj=1:length(ms_matrix_modes_to_use)
		temp_mode_shape(ms_matrix_modes_to_use(jj),:) = interp1( ...
			disperse.mode(ms_matrix_modes_to_use(jj)).freq, ...
			disperse.mode(ms_matrix_modes_to_use(jj)).ms_z, ...
			ms_matrix_calc_freqs(ii),'PCHIP'); %this assumes the ms_z will be used in the matrix. 
		temp_waveno(ms_matrix_modes_to_use(jj)) = interp1( ...
			disperse.mode(ms_matrix_modes_to_use(jj)).freq, ...
			disperse.mode(ms_matrix_modes_to_use(jj)).waveno, ...
			ms_matrix_calc_freqs(ii),'PCHIP');
	end;
	%build the mode shape matrix at this frequency
	sign = 1;
	for jj=1:no_mode_combinations_proc
		mode_shapes(:, jj) = (...
			temp_mode_shape(proc_data.tx_mode(jj), raw_data.tx_pos) .* ...
			temp_mode_shape(proc_data.rx_mode(jj), raw_data.rx_pos) .* ...
			exp( 2*pi*i*temp_waveno(proc_data.tx_mode(jj)) * array.row_pos(raw_data.tx_row) * proc_data.tx_dir(jj)).* ...
			exp( 2*pi*i*temp_waveno(proc_data.rx_mode(jj)) * array.row_pos(raw_data.rx_row) * proc_data.rx_dir(jj) * sign) ...
			).';
	end;
	mode_shapes(find(isnan(mode_shapes)))=0;
	mode_shapes(find(isinf(mode_shapes)))=0;
	inv_mode_shapes(:,:,ii) = pinv(mode_shapes);
end;
if ~suppress_display
	disp(['Inverse mode shape matrix built: ',num2str(toc)]);
end;
return