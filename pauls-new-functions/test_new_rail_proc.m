%test new rail processing
clear;
%close all;

%experimental file details - this can be either and old (*.rla) or new
%(*.mat) file. If extension not included, then *.mat file will be searched
%for. If not found *.rla file will be searched for and converted using
%specified fe_fname and hardware_fname files
data_fname = 'C:\Paul\matlab\rail\WR000-19#00224=20020612_4AVG';
data_fname = 'simulated-perfect-mode-reflectors.mat';
data_fname = 'simulated-test.mat';
%data_fname = 'C:\Paul\matlab\rail\WR000-19#00224=20020612_4AVG.rla';

fe_fname = 'C:\Paul\matlab\rail\fe-data\5mm_tap.mat';
hardware_fname = 'C:\Paul\matlab\rail\new_prototype.m';

%processing options

time_dom = [1, 0, 0, 1, 1, 1, 1];
neg_amps = [1, 0, 0, 0, 0, 1, 1];
bidi = [1, 0, 1, 0, 1, 0, 1];

options.raw_data_ignore_pulse_echo = 0;
options.proc_time_domain = 0;
options.ms_matrix_apply_as_time_shift = 1;
options.ms_matrix_time_step_size = 0;
options.ms_matrix_bidi_calc = 1;
options.ms_matrix_allow_neg_amps = 1;
save_after_processing = 0;
display_result = 1;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%load the file
[pt, fn, ex, vr] = fileparts(data_fname);
switch ex;
case '';
	%look for new file
	mat_fname = fullfile(pt, [fn, '.mat']);
	if exist(mat_fname, 'file')
		load_from_old_file = 0;
	else
		rla_fname = fullfile(pt, [fn, '.rla']);
		load_from_old_file = 1;
	end
case '.mat'
	mat_fname = data_fname;
	load_from_old_file = 0;
case '.rla'
	rla_fname = data_fname;
	load_from_old_file = 1;
otherwise
	disp('Invalid data file extension');
	return;
end;
if load_from_old_file
	[rail_tester, success] = convert_rla_file(rla_fname, fe_fname, hardware_fname);
	mat_fname = fullfile(pt, [fn, '.mat']);
	if ~success
		disp('Failed to load rla file');
		return;
	end;
else
	if exist(mat_fname, 'file');
		tic;
		load(mat_fname);
		disp(['Loaded input file: ',num2str(toc)]);
	else
		disp('Failed to load mat file');
		return;
	end;
end;
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%process it
for ii = 1:1;%length(time_dom);
options.ms_matrix_apply_as_time_shift = time_dom(ii);
options.ms_matrix_bidi_calc = bidi(ii);
options.ms_matrix_allow_neg_amps = neg_amps(ii);
rail_tester = process_data(rail_tester, options);
	figure;
	plot_options = [];
	plot_options.max_range = 12;
	plot_result(rail_tester, plot_options);
end;
return;

if save_after_processing
	save(mat_fname, 'rail_tester');
end;

if display_result
	figure;
	plot_options = [];
	plot_options.max_range = 12;
	plot_result(rail_tester, plot_options);
end;