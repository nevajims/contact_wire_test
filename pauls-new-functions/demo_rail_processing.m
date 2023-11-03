%This demo shows how to load a *.mat rail data file, process it according to specified
%options and plot results

clear;
close all;

%*.mat data file to process
%mat_fname = '\\excite\gul\grail\exp-results\Verification-Study\TW-Thermit-Weld\SKV-F-parametric-study\Weld-data-for-processing\G05#1080.mat';
mat_fname = 'E:\grail\exp-results\Verification-Study\TW-Thermit-Weld\SKV-F-parametric-study\Weld-data-for-processing\G05#1080.mat';

%a couple of distances for this file
feature_distance = 5.4;
max_plot_range = 20;

%Processing options
proc_options = []; % all defaults!
proc_options.ms_matrix_modes_to_use = [3,5,6,7,8,9,10];
proc_options.manual_warps = [1,1,1, 1, 1, 1, 1, 1, 1, 1];
proc_options.warp_factor = 2;

%Plotting options
plot_options.max_range = max_plot_range;
plot_options.tx_modes = [3, 5, 6, 7, 8, 9, 10];
plot_options.rx_modes = [3, 5, 6, 7, 8, 9, 10];
dna_options.max_range = max_plot_range;
feat_options = [];

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%Load the *.mat file
load(mat_fname);

%Process it
rail_tester = fn_process_rail_data(rail_tester, proc_options);

%Plot results
figure;
fn_plot_rail_result(rail_tester, plot_options);

figure;
fn_plot_dna_rail_data(rail_tester, dna_options)

figure;
rail_tester.rc_matrix = fn_plot_feature_map(rail_tester, feature_distance, feat_options);
rail_tester.feature_distance = feature_distance;

