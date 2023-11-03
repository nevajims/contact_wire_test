function [rail_tester, success] = fn_convert_rla_file(rla_fname, fe_fname, hardware_fname);
success = 0;
rail_tester = 0;
%load the array hardware m-file
if ~exist(hardware_fname, 'file')
	disp('Hardware file not found');
	return;
else
	tic;
	run(hardware_fname);
	rail_tester.array.row_pos = trans_row_pos;
	rail_tester.array.tx_rows = transmitter_rows;
	rail_tester.array.rx_rows = receiver_rows;
	rail_tester.array.delay = wavemaker_delay_factor;
	disp(['Loaded hardware file: ',num2str(toc)]);
end;

%load the fe data file
if ~exist(fe_fname, 'file')
	disp('FE file not found');
	return;
else
	tic;
	load(fe_fname);
	%this is the sign flipper
	for mi=1:length(data_mode_start_indices)-1;
		[start_index,end_index]=get_good_mode_indices(mi,data_freq,data_mode_start_indices);
		for ii=start_index:end_index-1'
			if (data_ms_z(trans_node_list,ii)' * data_ms_z(trans_node_list,ii+1))<0
				data_ms_z(:,ii+1:end_index) = -data_ms_z(:,ii+1:end_index);
			end;
		end;
	end;
	%stick FE data into right format
	for ii = 1:length(data_mode_start_indices)-1
		rail_tester.disperse.mode(ii).freq = data_freq(data_mode_start_indices(ii):data_mode_start_indices(ii+1) - 1);
		rail_tester.disperse.mode(ii).vph = data_ph_vel(data_mode_start_indices(ii):data_mode_start_indices(ii+1) - 1);
		rail_tester.disperse.mode(ii).vgr = data_gr_vel(data_mode_start_indices(ii):data_mode_start_indices(ii+1) - 1);
		rail_tester.disperse.mode(ii).waveno = rail_tester.disperse.mode(ii).freq ./ rail_tester.disperse.mode(ii).vph;
		rail_tester.disperse.mode(ii).ms_x = data_ms_x(trans_node_list, data_mode_start_indices(ii):data_mode_start_indices(ii+1) - 1) .';
		rail_tester.disperse.mode(ii).ms_y = data_ms_y(trans_node_list, data_mode_start_indices(ii):data_mode_start_indices(ii+1) - 1) .';
		rail_tester.disperse.mode(ii).ms_z = data_ms_z(trans_node_list, data_mode_start_indices(ii):data_mode_start_indices(ii+1) - 1) .';
	end;
	disp(['Loaded FE data: ',num2str(toc)]);
end;

if 1 % skip actual data loading for debugging if required
%load rla file
tic;
[rail_tester.raw_data, rail_tester.input_signal, rla_success] = fn_load_rla_file(rla_fname);
if ~rla_success
	disp('Failed to load rla file');
	return;
else
	disp(['Loaded rla file: ',num2str(toc)]);
end;
end

%sort out the signs of the columns in raw data according to phasing
%information in hardware file

for count = 1:size(rail_tester.raw_data.time_data, 2)
	sgn1 = trans_pos_phasings(rail_tester.raw_data.tx_pos(count));
    sgn2 = trans_pos_phasings(rail_tester.raw_data.rx_pos(count));
    sgn = sgn1*sgn2;
    rail_tester.raw_data.time_data(:, count) = rail_tester.raw_data.time_data(:, count) * sgn;
end;

%save the lot as *.mat file
[pt, fn, ex, ver] = fileparts(rla_fname);
out_fname = fullfile(pt, [fn, '.mat']);
save(out_fname, 'rail_tester');
success = 1;
return;