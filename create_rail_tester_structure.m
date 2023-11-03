function [ rail_tester,loaded_fe_file_ok ]  =  create_rail_tester_structure(default_options,test_data,proc_options)
%    test_data.fixed_Test_Settings.Instrument_attributes
%
%     number_of_transducers: 12
%                 trans_row: [1 1 1 1 2 2 2 2 3 3 3 3]
%                 trans_pos: [1 2 3 4 1 2 3 4 1 2 3 4]
%     trans_pos_orientation: [12×3 double]
%             trans_row_pos: [0.0120 0 -0.0120]
%

    rail_tester.array.row_pos                       =   test_data.fixed_Test_Settings.Instrument_attributes.trans_row_pos         ;
    rail_tester.array.trans_pos                     =   test_data.fixed_Test_Settings.Instrument_attributes.trans_pos             ;
    rail_tester.array.trans_row                     =   test_data.fixed_Test_Settings.Instrument_attributes.trans_row             ;
	rail_tester.array.trans_pos_orientations        =   test_data.fixed_Test_Settings.Instrument_attributes.trans_pos_orientation ;
    rail_tester.array.delay                         =   test_data.fixed_Test_Settings.TIPI_LEGACY.delay_factor                    ;
    rail_tester.array.trans_node_list               =   test_data.fixed_Test_Settings.Model_data.trans_node_list(test_data.fixed_Operator_Settings.contact_wire_type_120_107,:)  ;
    rail_tester.fe_fname                            =   test_data.fixed_Test_Settings.Model_data.fe_fnames{test_data.fixed_Operator_Settings.contact_wire_type_120_107}          ;
    rail_tester.real_length                         =   test_data.fixed_Test_Settings.Model_data.real_length                                                                     ;
    rail_tester.fe_fname                            =   [pwd,rail_tester.fe_fname]        ;


if ~exist(rail_tester.fe_fname,'file')

msgbox(rail_tester.fe_fname )
msgbox('FE file not found line 81 ');
loaded_fe_file_ok = 0;
else
load(rail_tester.fe_fname);
    rail_tester.mesh =  reshaped_proc_data.mesh;
    %stick FE data into right format
    %Get the mode names and put in blanks if not defined
    if ~(size(reshaped_proc_data.mode_names,2)==reshaped_proc_data.solve_details.no_modes)
        for ii = 1:reshaped_proc_data.solve_details.no_modes
            tempmodenames(ii)="";
        end
        tempmodenames(1:size(reshaped_proc_data.mode_names,2))=tempmodenames(1:size(reshaped_proc_data.mode_names,2))+reshaped_proc_data.mode_names;
        reshaped_proc_data.mode_names=tempmodenames;
    end
    %Confirmed now that sign flipping is done in the safe model and saved
    %in original variable names so just load them into rail_tester
        
	for ii = 1:reshaped_proc_data.solve_details.no_modes
		rail_tester.disperse.mode(ii).freq   =   reshaped_proc_data.freq(:,ii)              ;
		rail_tester.disperse.mode(ii).vph    =   reshaped_proc_data.ph_vel(:,ii)            ;
		rail_tester.disperse.mode(ii).vgr    =   reshaped_proc_data.group_velocity(:,ii)    ;
		rail_tester.disperse.mode(ii).waveno =   reshaped_proc_data.waveno(:,ii)            ;
		rail_tester.disperse.mode(ii).ms_x   =   reshaped_proc_data.ms_x(:,:,ii).'          ;
		rail_tester.disperse.mode(ii).ms_y   =   reshaped_proc_data.ms_y(:,:,ii).'          ;
		rail_tester.disperse.mode(ii).ms_z   =   reshaped_proc_data.ms_z(:,:,ii).'          ;
        rail_tester.disperse.mode(ii).name   =   reshaped_proc_data.mode_names(ii)          ;

    end %for ii = 1:reshaped_proc_data.solve_details.no_modes
    loaded_fe_file_ok = 1;
end % if ~exist(rail_tester.fe_fname,'file')

[rail_tester, converted_OK]  =  convert_raw_data_to_proc_format(rail_tester,test_data,proc_options);

end %function rail_tester =  create_rail_tester_structure(default_options,test_data);



function [rail_tester, converted_OK]  =  convert_raw_data_to_proc_format(rail_tester,test_data,proc_options)

converted_OK= 1;

rail_tester.sample_freq         =  test_data.fixed_Test_Settings.Sampling.Sample_RateHz    ;
rail_tester.a2d_pts             =  test_data.fixed_Test_Settings.Sampling.Num_Samples      ;
rail_tester.raw_data.time       =  test_data.raw_data.time                                 ;
rail_tester.input_signal.freq   =  test_data.fixed_Test_Settings.Toneburst.Frequency       ;
rail_tester.input_signal.cycles =  test_data.fixed_Test_Settings.Toneburst.num_cycles      ;

if proc_options.raw_data_zero_dead_time
    rail_tester.raw_data_zero_dead_time = rail_tester.input_signal.cycles/(2*rail_tester.input_signal.freq); 
    %Just zero out the input signal cross talk.
% disp (['Raw data zero dead time =     ',num2str(rail_tester.raw_data_zero_dead_time)])
% just to check what it is

else
    rail_tester.raw_data_zero_dead_time = 0; %Just zero out the input signal cross talk.
end %if proc_options.raw_data_zero_dead_time
%  How it was:::::::
% if proc_options.raw_data_zero_dead_time
%    proc_options.raw_data_zero_dead_time = fmc.cycles/(2*fmc.centre_freq); %Just zero out the input signal cross talk.
% end %if proc_options.raw_data_zero_dead_time

rail_tester.raw_data.time_data = reshape(test_data.raw_data.time_data, size(test_data.raw_data.time_data, 1), []);
[rail_tester.raw_data.tx,rail_tester.raw_data.rx] = meshgrid(1:size(test_data.raw_data.time_data,2), 1:size(test_data.raw_data.time_data,3)); 
rail_tester.raw_data.tx = rail_tester.raw_data.tx(:); 
rail_tester.raw_data.rx = rail_tester.raw_data.rx(:);

end


