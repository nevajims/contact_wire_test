%test new rail processing
clear;
%close all;

%experimental file details - this can be either and old (*.rla) or new
%(*.mat) file. If extension not included, then *.mat file will be searched
%for. If not found *.rla file will be searched for and converted using
%specified fe_fname and hardware_fname files
data_fname = 'D:\grail\Exp-Results\6-row-prototype\6 row and 5 row comparison\Export-1563-14kHz';

fe_fname = 'N:\grail\matlab\fe-data\2D-models\5mm_tap.mat';
hardware_fname = 'N:\grail\matlab\pauls-new-functions\new_prototype.m';

save_after_processing = 1;
display_result = 1;


%processing options

%default options - filter
options.freq_filter_on = 1;
options.freq_filter = 15e3;
options.freq_filter_bandwidth = 3.5e3;%filter half bandwidth to -40 dB points
default_options.freq_comp_for_input_signal = 1;
%default options - raw data
options.raw_data_ignore_pulse_echo = 1;
options.raw_data_coupling_comp = 2; %0 for none, 1 for straight scaling of individual signals, 2 iterative optimisation of couplings
options.raw_data_zero_dead_time = 15e-4;
%default options - mode shape matrix calculation
options.ms_matrix_modes_to_use = [3,5,7,8,10];%modes used in calculation of matrices
options.ms_matrix_calc_method = 1; %1 centre frequency; 2 linear interpolation between matrices calculated at ms_matrix_calc_freqs
options.ms_matrix_calc_freqs = linspace(11.5e3,16.5e3,11); %frequencies to calc mode shape matrix at for linear interpolation
options.ms_matrix_ignore_pulse_echo = 0;
options.ms_matrix_bidi_calc = 0; %turn on to include transmit in +ve direction and receive in +ve direction combos in calc
options.ms_matrix_apply_as_time_shift = 0; %turn on to do freq domain processing, but applied as time rather than phase shifts
options.ms_matrix_time_step_size = 0; %if non-zero and doing time shifts, this sets the smallest integral multiple of time shifts allowed
options.ms_matrix_allow_neg_amps = 0; %if non-zero and doing time shifts, time shifts of between pi and 2pi are implemented as pi less combined with a negative amplitude
%other processing options
options.proc_time_domain = 0; %turn on to do processing as time shifts only
options.dispersion_compensation = 0; %turn on for dispersion compensation  - not implemented 26/5/04
options.suppress_display = 0;


%plot options
plot_options.db_range = 30;
% plot_options.tx_modes = [8,8,8,8,8,10,10,10,10,10];
% plot_options.rx_modes = [3, 5, 7, 8, 10, 3, 5, 7, 8, 10];
% 
plot_options.tx_modes = [5, 5, 5, 5, 5];
plot_options.rx_modes = [3, 5, 7, 8, 10];

plot_options.max_range = 25;
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
rail_tester = process_data(rail_tester, options);
figure;
plot_result(rail_tester, plot_options);

if save_after_processing
	save(mat_fname, 'rail_tester');
end;