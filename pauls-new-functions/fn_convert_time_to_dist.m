function proc_data_out = fn_convert_time_to_dist(out_time_data, proc_data, disperse, ms_matrix_modes_to_use, freq_filter, suppress_display);
tic;
proc_data_out =  proc_data;
debug = 0;
if debug
	proc_data_out.dist = out_time_data.time;
	proc_data_out.dist_data = abs(out_time_data.time_data);
	return;
end;
vgr = zeros(max(ms_matrix_modes_to_use),1);
k = zeros(max(ms_matrix_modes_to_use),1);
for ii=1:length(ms_matrix_modes_to_use);
	vgr(ms_matrix_modes_to_use(ii)) = interp1(...
		disperse.mode(ms_matrix_modes_to_use(ii)).freq, ...
		disperse.mode(ms_matrix_modes_to_use(ii)).vgr, ...
		freq_filter, 'PCHIP');
	k(ms_matrix_modes_to_use(ii)) = interp1(...
		disperse.mode(ms_matrix_modes_to_use(ii)).freq, ...
		disperse.mode(ms_matrix_modes_to_use(ii)).waveno, ...
		freq_filter, 'PCHIP');
end;
proc_data_out.modal_vgrs = vgr(:) .';
vgr = 1 ./ (1 ./ vgr(proc_data.tx_mode) + 1 ./ vgr(proc_data.rx_mode));

%set up distance axis
max_dist = max(vgr) * max(out_time_data.time);
dist_step = 1 / (2 * max(k));
proc_data_out.dist = [0:round(max_dist/dist_step)]' * dist_step;

% disp(num2str(length(proc_data_out.dist)))

proc_data_out.dist_data = zeros(length(proc_data_out.dist), length(proc_data_out.tx_mode));

%interpolate from time data
for ii = 1:size(proc_data_out.dist_data, 2);
	temp_dist = out_time_data.time * vgr(ii);
	proc_data_out.dist_data(:,ii) = interp1(temp_dist, abs(out_time_data.time_data(:,ii)), proc_data_out.dist, 'linear', 0);
end;

% proc_data_out.dist = [-flipud(proc_data_out.dist); proc_data_out.dist(2:end)];
% proc_data_out.dist_data = zeros(length(proc_data_out.dist),size(out_time_data.time_trace, 2));
% 
% fwd_indices = find(proc_data.tx_dir > 0 & proc_data.rx_dir > 0);
% bwd_indices = find(proc_data.tx_dir < 0 & proc_data.rx_dir < 0);
% 
% %flip backward signals and stick behind forward ones
% temp_dist_data = [flipud(out_time_data.time_trace(:, bwd_indices)); out_time_data.time_trace(2:end, fwd_indices)];
% %make up a new time axis with pos and neg parts for interpolation
% temp_time = [-fliplr(out_time_data.time), out_time_data.time(2:end)]';
% temp_vgr = vgr(fwd_indices);
% for ii = 1:size(temp_dist_data, 2);
% 	temp_dist = temp_time * temp_vgr(ii);
% %	tap_filter = taper(floor(size(out_time_data,1)/2),in_cycles/in_freq/max_time)';
% %	out_time_data(:,count) = out_time_data(:,count) .* [tap_filter;0;tap_filter];
% 	proc_data_out.dist_data(:,ii) = interp1(temp_dist, temp_dist_data(:,ii), proc_data_out.dist, 'cubic', 0);
% end;
if ~suppress_display
	disp(['Converted to distance domain: ',num2str(toc)]);
end;
return;