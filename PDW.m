clear all
% close all
addpath(genpath('.'));


benchmark_fname = 'benchmark.mat';

load(benchmark_fname);
benchmark.input = input;
output_rail_tester{1} = output.rail_tester; %This is the current result exactly as obtained from the GUI as a references
clear('input', 'output');

%Local processing of benchmark input data to check same as GUI processing
output_rail_tester{2} = fn_process_rail_data(benchmark.input.rail_tester, benchmark.input.proc_options);

benchmark.input.proc_options.raw_data_zero_dead_time = 0;%this now works ... but has to be off to match
benchmark.input.proc_options.ms_matrix_calc_freqs = [];%new way fo forcing single freq calc
% benchmark.input.proc_options.ms_matrix_apply_as_time_shift = 1;%works but doesn't make much odds
% benchmark.input.proc_options.ms_matrix_allow_neg_amps = 1;%works but doesn't make much odds
output_rail_tester{3} = fn_process_rail_data_DLL_wrapper(benchmark.input.rail_tester, benchmark.input.proc_options);

figure;
dmax = max(output_rail_tester{1}.proc_data.dist);

col = {'r', 'k.', 'g--'};
for b = 1:numel(output_rail_tester)
    norm_val = max(abs(output_rail_tester{b}.proc_data.dist_data), [], 'all');
    tmp = 20 * log10(abs(output_rail_tester{b}.proc_data.dist_data) / norm_val);
    for direction = [-1:1]
        k = find((output_rail_tester{b}.proc_data.tx_dir == direction) & (output_rail_tester{b}.proc_data.rx_dir == direction));
        if numel(k)>3
            k = k(1:3);
        end
        for i = 1:numel(k)
            subplot(numel(k), 2, i * 2 + (direction + 1) / 2 - 1);
            plot(output_rail_tester{b}.proc_data.dist * direction, tmp(:, k(i)), col{b});
            hold on;
            ylim([-40, 0]);
            if i < numel(k)
                set(gca, 'XTickLabel', []);
            end
            if direction == 1
                if b == 1
                    text(dmax / 2, -20, sprintf('%i-%i', output_rail_tester{b}.proc_data.tx_mode(k(i)), output_rail_tester{b}.proc_data.rx_mode(k(i))));
                end
                xlim([0, dmax])
            else
                xlim([-dmax, 0])
            end
        end
    end
end
%This is fine - therefore no need to run original processing again here.
return



keyboard

% run('WPA_V2');

proc_options.raw_data_zero_dead_time = 1;


%Load to test_data
fname = 'EL00~18_PJL_1100_Entry_WA$1$.mat';
load(fname);

default_options = [];
[ rail_tester,loaded_fe_file_ok ]  =  create_rail_tester_structure(default_options, test_data, proc_options);
% return

% rail_tester = test_data;
% clear('test_data');

%Add disperse data
% fe_file_number__  =  2;
% fe_fname = test_data.fixed_Test_Settings.Model_data.fe_fnames{fe_file_number__};
% load(['.', filesep, fe_fname]);
% if ~(size(reshaped_proc_data.mode_names,2)==reshaped_proc_data.solve_details.no_modes)
%     for ii = 1:reshaped_proc_data.solve_details.no_modes
%         tempmodenames(ii)="";
%     end
%     tempmodenames(1:size(reshaped_proc_data.mode_names,2))=tempmodenames(1:size(reshaped_proc_data.mode_names,2))+reshaped_proc_data.mode_names;
%     reshaped_proc_data.mode_names=tempmodenames;
% end
% for ii = 1:reshaped_proc_data.solve_details.no_modes
%     rail_tester.disperse.mode(ii).freq   =   reshaped_proc_data.freq(:,ii)              ;
%     rail_tester.disperse.mode(ii).vph    =   reshaped_proc_data.ph_vel(:,ii)            ;
%     rail_tester.disperse.mode(ii).vgr    =   reshaped_proc_data.group_velocity(:,ii)    ;
%     rail_tester.disperse.mode(ii).waveno =   reshaped_proc_data.waveno(:,ii)            ;
%     rail_tester.disperse.mode(ii).ms_x   =   reshaped_proc_data.ms_x(:,:,ii).'          ;
%     rail_tester.disperse.mode(ii).ms_y   =   reshaped_proc_data.ms_y(:,:,ii).'          ;
%     rail_tester.disperse.mode(ii).ms_z   =   reshaped_proc_data.ms_z(:,:,ii).'          ;
%     rail_tester.disperse.mode(ii).name   =   reshaped_proc_data.mode_names(ii)          ;
% end %for ii = 1:reshaped_proc_data.solve_details.no_modes
%
% % rail_tester.disperse = reshaped_proc_data;
% rail_tester.mesh = reshaped_proc_data.mesh;
% clear('reshaped_proc_data');
%
% %Add array data
% rail_tester.array.row_pos                       =   test_data.fixed_Test_Settings.Instrument_attributes.trans_row_pos         ;
% rail_tester.array.trans_pos                     =   test_data.fixed_Test_Settings.Instrument_attributes.trans_pos             ;
% rail_tester.array.trans_row                     =   test_data.fixed_Test_Settings.Instrument_attributes.trans_row             ;
% rail_tester.array.trans_pos_orientations        =   test_data.fixed_Test_Settings.Instrument_attributes.trans_pos_orientation ;
% rail_tester.array.delay                         =   test_data.fixed_Test_Settings.TIPI_LEGACY.delay_factor                    ;
% SAFE_LRUD = get_SAFE_LRUD(rail_tester.mesh , 0);
% rail_tester.array.trans_node_list  =  [SAFE_LRUD(3),SAFE_LRUD(2),SAFE_LRUD(4),SAFE_LRUD(1)]  ;
% rail_tester.array.delay                         =   test_data.fixed_Test_Settings.TIPI_LEGACY.delay_factor                    ;
%
% %Input signal
% rail_tester.input_signal.freq   =  test_data.fixed_Test_Settings.Toneburst.Frequency       ;
% rail_tester.input_signal.cycles =  test_data.fixed_Test_Settings.Toneburst.num_cycles      ;
%
% %Some more fiddling with raw data
% rail_tester.raw_data.time = test_data.raw_data.time
% if proc_options.raw_data_zero_dead_time
%     sample_freq = 1 / (test_data.raw_data.time(2) - test_data.raw_data.time(1));
%     rail_tester.raw_data_zero_dead_time = test_data.fixed_Test_Settings.Toneburst.num_cycles/(2*test_data.fixed_Test_Settings.Toneburst.Frequency);
%     correct_time_pts = rail_tester.raw_data_zero_dead_time*sample_freq; %this is how many points to shift to set zero to middle of pulse
%     rail_tester.raw_data.time_data(:,:,:)=vertcat(test_data.raw_data.time_data(correct_time_pts:end,:,:),zeros(correct_time_pts-1,size(test_data.raw_data.time_data,2),size(test_data.raw_data.time_data,3)));
% else
%     rail_tester.raw_data_zero_dead_time = 0; %Just zero out the input signal cross talk.
% end
% [rail_tester.raw_data.tx,rail_tester.raw_data.rx] = meshgrid(1:size(rail_tester.raw_data.time_data,2), 1:size(rail_tester.raw_data.time_data,3));
% rail_tester.raw_data.time_data = reshape(rail_tester.raw_data.time_data, size(rail_tester.raw_data.time_data, 1), []);
% rail_tester.raw_data.tx = rail_tester.raw_data.tx(:);
% rail_tester.raw_data.rx = rail_tester.raw_data.rx(:);



% options = [];

%Options in GUI look like this - check same used from defaults
%     ms_matrix_modes_to_use: [1 2 3 4]
%                freq_filter: 50000
%      freq_filter_bandwidth: 40000
% freq_comp_for_input_signal: 0
% raw_data_ignore_pulse_echo: 1
%     raw_data_coupling_comp: 0
%    raw_data_zero_dead_time: 1
%      ms_matrix_calc_method: 1
%       ms_matrix_calc_freqs: [30000 34000 38000 42000 46000 50000 54000 58000 62000 66000 70000]
%           suppress_display: 1
%                warp_factor: 1



rail_tester = fn_process_rail_data(rail_tester, proc_options);

figure;
tmp = 20 * log10(rail_tester.proc_data.dist_data / max(abs(rail_tester.proc_data.dist_data), [], 'all'));
dmax = max(rail_tester.proc_data.dist);
for direction = [-1:1]
    k = find((rail_tester.proc_data.tx_dir == direction) & (rail_tester.proc_data.rx_dir == direction));
    for i = 1:numel(k)
        subplot(numel(k), 2, i * 2 + (direction + 1) / 2 - 1);
        plot(rail_tester.proc_data.dist * direction, tmp(:, k(i)));
        ylim([-40, 0]);
        if i < numel(k)
            set(gca, 'XTickLabel', []);
        end
        if direction == -1
            text(-4, -20, sprintf('%i-%i', rail_tester.proc_data.tx_mode(k(i)), rail_tester.proc_data.rx_mode(k(i))));
            xlim([-dmax, 0])
        else
            xlim([0, dmax])
        end
    end
end
