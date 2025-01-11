clear;
close all;

source_fname = 'C:\Paul\matlab\rail\WR000-19#00224=20020612_4AVG.mat';
output_fname = 'simulated-perfect-mode-reflectors.mat';
output_fname = 'simulated-test.mat';

% for ii = 1:5
% 	features(ii).pos = ii * 2 * (-1) ^ ii;
% 	features(ii).refl_coeff = zeros(5,5);
% 	features(ii).refl_coeff(ii, ii) = 1; % diag(ones(5,1)); %
% 	features(ii).modes = [3, 5, 7, 8, 10];
% end;
features(1).pos = 10;
features(1).refl_coeff = diag(ones(5,1));
features(1).modes = [3, 5, 7, 8, 10];
features(2).pos = -5;
features(2).refl_coeff = diag(ones(5,1));
features(2).modes = [3, 5, 7, 8, 10];

options.time_step = 10e-6;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
load(source_fname);

rail_tester = simulate_rail_data(rail_tester.array, ...
	rail_tester.disperse, ...
	rail_tester.input_signal, ...
	features, ...
	rail_tester.raw_data.tx_pos, ...
	rail_tester.raw_data.tx_row, ...
	rail_tester.raw_data.rx_pos, ...
	rail_tester.raw_data.rx_row, ...
	options);

save(output_fname, 'rail_tester');
figure;
indices = find(rail_tester.raw_data.tx_row == 1 & rail_tester.raw_data.rx_row == 1);
plot(rail_tester.raw_data.time, sum(rail_tester.raw_data.time_data(:,indices)')');