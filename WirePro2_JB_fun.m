function []  =   WirePro2_JB_fun(varargin)
% need to make sure the  data is not mixed up from the original
% add more default options to the data files
% plot_distance --  do not seperate from proc_options -  redundant

% DONE ---- now I have alvas data new format I can convert and use that format
% DONE ---- name of alvas file  -  and compare with my data file format
% DONE ----  create the necessary files to getto work to this point
% ***DONE(1) Delete the current path and rebuild a new one
% ***DONE (2) A fake test file  -- DONE
%  ***DONE (3) A premade analysys file  
% (4) Check the file works up to this point 
%  selection  
%  ***DONE (1)  at this point choose between loading  an existing raw data file or
%  ***DONE creating a new one using alvas program
% abstract it into function
% create a status bar for translating data.. 
data_info = get_data_info();

[default_options,DOF_loaded_ok] = get_default_options(data_info.drive_letter_root ,data_info.location_of_default_options, data_info.default_option_fields) ; 

if DOF_loaded_ok  == 1
[proc_options,plot_options, plot_distance , input_vals_ok]   =  get_input_vals(nargin,varargin,default_options);

%Test_Settings , Operator_Settings, raw_data_fname
if input_vals_ok  == 1
answer_ = questdlg('Would you like to aquire data or take existing data ?','Data Source..','Do New Test','Analyse existing data','Do New Test');

if ~isempty( answer_)
[test_data]    =  get_data_to_analyse(default_options, answer_);


[rail_tester,loaded_fe_file_ok ] =  create_rail_tester_structure(default_options,test_data,proc_options);
rail_tester                                =  fn_process_rail_data(rail_tester, proc_options);


run_plots(rail_tester , plot_options , plot_distance)

end %if ~isempty( answer_)


%--------------------------------------------------------------------------------------------------------------------
%--------------------------------------------------------------------------------------------------------------------
%--------------------------------------------------------------------------------------------------------------------




end %if input_vals_ok  == 1
else
disp('problem with loading default options file')
end %if DOF_loaded_ok  == 1


end %function  WirePro2_JB_fun()

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
    rail_tester.fe_fname                            =   [default_options.drive_letter_root,rail_tester.fe_fname]        ;

if ~exist(rail_tester.fe_fname,'file')
disp('FE file not found line 81 ');
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





function [test_data]    =  get_data_to_analyse(default_options, answer_)

switch(answer_)
    
    case ('Do New Test')

disp('Run alvas program at this point')

[Test_Settings     , checked_ok_test]   = load_structure_from_file([default_options.drive_letter_root,default_options.Test_Settings_fname    ] ,default_options.Test_expected_fields)              ;
[Operator_Settings , checked_ok_oper]   = load_structure_from_file([default_options.drive_letter_root,default_options.Operator_Settings_fname] ,default_options.Operator_expected_fields)      ;

if  checked_ok_test &&checked_ok_oper

[raw_data] =  run_alva_DAQ(Test_Settings)                       ;        

[test_data]  = create_test_file(raw_data,Test_Settings, Operator_Settings);  

% have the file name in the structure
[test_data] =   save_in_file_structure (test_data,default_options); 
% test_data  has added field as the name and location of the  data file

else
disp(['problem with Test_Settings or Operator_Settings: (',num2str( checked_ok_test),', ',num2str(checked_ok_oper),').'])
end %if  checked_ok_test &&checked_ok_oper

    case ('Analyse existing data')
 % Choose a file  which will already have the data file and user file in
 % the structure

p_w_d =  pwd;
cd([default_options.drive_letter_root , default_options.raw_data_file_path])
[file,path] = uigetfile('*.mat');
file_with_path  = [path,file];

dummy__ = load(file_with_path); 
if isfield(dummy__,'test_data')
test_data = dummy__.test_data ;    

if length(fields(test_data)) == 4  && isfield(test_data,'raw_data')&& isfield(test_data,'Test_Settings') &&...
isfield(test_data,'Operator_Settings')&& isfield(test_data,'file_with_path')  
%file has the correct number of field and they have the correct names
else
%file does not have the correct number of field and/or they do not have the correct names
end %if length(fields(test_data)) == 4  && isfield(test_data,'raw_data')  

else
disp('The file is not the correct format needs to have a field') 
end %if isfield(dummy__,'test_data')
cd (p_w_d)


end % switch(answer_)
end   %function [test_data]    =  get_data_to_analyse(default_options, answer_);

function [data_info]  = get_data_info()   
data_info.drive_letter_root           =        'C:\MLPROGS\';
data_info.location_of_default_options =        [data_info.drive_letter_root,'WirePro2\SETTINGS_FILES\default_options.dat'];  
data_info.default_option_fields  =   {'drive_letter_root';'raw_data_file_options';'raw_data_file_type';'proc_options_fname';'plot_options_fname';'Test_Settings_fname';'Operator_Settings_fname';...
'raw_data_file_path';'proc_expected_fields';'plot_expected_fields';'Test_expected_fields';'Operator_expected_fields'}   ;
end %function [drive_letter_root,location_of_default_options,default_option_fields]  = get_data_info();   

function [default_options,DOF_loaded_ok] =  get_default_options(drive_letter_root, location_of_default_options,   default_option_fields )

default_options.drive_letter_root            =  drive_letter_root;

[default_options , DOF_loaded_ok]            = load_structure_from_file(location_of_default_options , default_option_fields);
if DOF_loaded_ok ~= 1
default_options = 'void';    
end %if DOF_loaded_ok == 1


end %function get_default_options('C:\MLPROGS\' , location_of_default_options,   default_option_fields );

function [proc_options , plot_options, plot_distance , ok_] = get_input_vals(num_args ,var_args , default_options)
% Default_options.proc_options_fname
% Default_options.plot_options_fname
% Load the options files and either use them or use them as a template to compare with the input the keyboard input stuctures   

ok_  = 0;
[proc_options      , checked_ok_proc]   = load_structure_from_file([default_options.drive_letter_root,default_options.proc_options_fname]  ,default_options.proc_expected_fields)               ;
[plot_options      , checked_ok_plot]   = load_structure_from_file([default_options.drive_letter_root,default_options.plot_options_fname],default_options.plot_expected_fields)               ;

if  checked_ok_proc == 1 && checked_ok_plot == 1 
ok_  = 1;
switch(num_args)
    case(0)
% plot_distance = 0.66;
select_files = 1;
    case(1)
plot_distance = var_args{1} ;
select_files =  1             ;
end %switch(num_args)

end %if  checked_ok_proc == 1 && checked_ok_plot == 1 &&  checked_ok_test == 1 && checked_ok_oper == 1

if select_files == 1
% [hardware_full_name, hw_name_found]  = Choose_generic_file_name(default_options.hardware_file_path ,'dat') ; 
switch(default_options.raw_data_file_type)
case(1)
file_ext = 'mat';
case(2)
file_ext = 'rld';
end %switch(default_options.raw_data_file_type)
end %if   select_files == 1

if ~exist('plot_distance') 
% disp('setting plot distance from default settings')
plot_distance = plot_options.plot_distance;
end %if ~exist('plot_distance') 

if  ~ok_
proc_options    = NaN ;
plot_options    = NaN ;
raw_data_fname  = NaN ; 
hardware_full_name  = NaN ;
plot_distance   = NaN ;
end %if  ~ok_

end %function [proc_options,plot_options, raw_data_fname , hardware_full_name, plot_distance]  = get_input_vals(nargin,varargin);

function [test_data]  =   save_in_file_structure (test_data,default_options)

p_w_d =  pwd;
cd([default_options.drive_letter_root,default_options.raw_data_file_path])
[year_ , month_ , day_ ] =  ymd(datetime) ;
O_S =   test_data.fixed_Operator_Settings ;

if ~exist(num2str(year_))
mkdir(num2str(year_))
cd (num2str(year_))
else
cd (num2str(year_))
end %if ~exist(num2str(year_))

if ~exist(num2str(month_))
mkdir(num2str(month_))
cd (num2str(month_))
else
cd (num2str(month_))
end %if ~exist(num2str(year_))

if ~exist(num2str(day_))
mkdir(num2str(day_))
cd (num2str(day_))
else
cd (num2str(day_))
end %if ~exist(num2str(year_))
% now create
Auto_generated_file_stub  = ['CW_test_',replace_space(O_S.Name),'__',replace_space(O_S.Site_name)]     ;
% Auto_generated_file_stub  = ['CW_test_',O_S.Name,'__',O_S.Site_name]                                     ;

temp_          =    dir([Auto_generated_file_stub,'*.*'])         ;
exist_names_   =    {temp_.name}                                  ;

if length(exist_names_)==0
new_file_number = 1;
else
    max_file_no = 0;    

    for index = 1 :length(exist_names_)
    cur_no = str2num(exist_names_{index}(min(find(exist_names_{index}=='$'))+1:max(find(exist_names_{index}=='$'))-1));
    
    if   cur_no > max_file_no 
    max_file_no = cur_no;
    end % if   cur_no > max_file_no 
    % disp(num2str(cur_no)) 

    end % for index = 1 :length(exist_names_)
new_file_number = max_file_no + 1; 
end

file_name_ =  [Auto_generated_file_stub,'$',num2str(new_file_number),'$.mat'];
file_with_path = [pwd,'\',file_name_];

test_data.file_with_path = file_with_path;
save(file_name_,'test_data')
disp(['file saved....     ',file_with_path,'.'])
cd(p_w_d)
end % function   ok_  =   save_in_file_structure (test_file)




function [test_data] =  create_test_file(raw_data,Test_Settings, Operator_Settings) 
test_data.raw_data                 = raw_data           ;
test_data.fixed_Test_Settings      = Test_Settings      ; 
test_data.fixed_Operator_Settings  = Operator_Settings  ;
end %function test_file =  create_test_file(raw_data,Test_Settings, Operator_Settings) 

function string_ = replace_space(string_)
string_(find(string_==' ')) = '_';
end

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

end  % function [rail_tester, converted_OK]  =  convert_raw_data_to proc_format(   )
%----------------------------------------------------------------------------------------------------%
%  old files underneath  some to be re - done  
%----------------------------------------------------------------------------------------------------%
%--------NOT USED----------------%
%--------NOT USED----------------%


%--------NOT USED----------------%
function [rail_tester,loaded_hardware_file_ok] = load_hardware_file(hardware_fname,default_options)

if ~exist(hardware_fname, 'file')
    disp('Hardware file not found');
	loaded_hardware_file_ok = 0 ; 
    rail_tester = NAN;

else

    [data_ ,loaded_hardware_file_ok ] = load_structure_from_file(hardware_fname,default_options.HF_expected_fields)  ;


if loaded_hardware_file_ok  ==1

    rail_tester.array.row_pos                       = data_.trans_row_pos                               ;
    rail_tester.array.trans_pos                     = data_.trans_pos                                   ;
    rail_tester.array.trans_row                     = data_.trans_row                                   ;
	rail_tester.array.delay                         = data_.delay_factor                                ;
    rail_tester.array.trans_pos_orientations        = data_.trans_pos_orientation                       ;
    rail_tester.array.trans_node_list               = data_.trans_node_list                             ;
    rail_tester.fe_fname                            = data_.fe_fname                                    ; 
    rail_tester.real_length                         = data_.real_length                                 ;  

else
disp('not loaded hardware filecorrectly')    
end %if %checked_ok ==1
end % if ~exist(hardware_fname, 'file')


end %function  load_hardware_fname()

function [rail_tester,loaded_fe_file_ok] = load_fe_file(rail_tester)

if ~exist(rail_tester.fe_fname,'file')
    disp('FE file not found 238');
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
    end % if ~exist(rail_tester.fe_fname, 'file')

end  % function load_rail_tester.fe_fname()

function [rail_tester,loaded_raw_file_ok] =  load_raw_data_file(raw_data_fname,rail_tester,proc_options)

% load some experimental data to try out with

if ~exist(raw_data_fname, 'file')
disp('Raw data file not found');
loaded_raw_file_ok = 0; 
else
   
if strcmp(raw_data_fname(end-2:end),'mat')
load(raw_data_fname);
disp('mat file read')
elseif strcmp(raw_data_fname(end-2:end),'rld')
fmc = ReadRLD(raw_data_fname);

% disp('rld file read')
else
disp(['Raw data file not correct format: ',raw_data_fname(end-2:end)]);
loaded_raw_file_ok = 0; 
end
    
sample_freq = fmc.sample_freq;
a2d_pts = fmc.a2d_pts;

rail_tester.raw_data.time = fmc.time; %PW: I added this one! Clever boy!
rail_tester.input_signal.freq = fmc.centre_freq;
rail_tester.input_signal.cycles = fmc.cycles;

if proc_options.raw_data_zero_dead_time
    proc_options.raw_data_zero_dead_time = fmc.cycles/(2*fmc.centre_freq); %Just zero out the input signal cross talk.

end %if proc_options.raw_data_zero_dead_time



%this data is stored in a different format than the original (data,rx,tx) (512,8,8)
rail_tester.raw_data.time_data = reshape(fmc.time_data, size(fmc.time_data, 1), []);

%new fields for transducer lookup indices to replace tx_row,
%tx_pos etc. in raw_data. Instead these indices are used to look up row,
%position and orientation in array file
[rail_tester.raw_data.tx, rail_tester.raw_data.rx] = meshgrid(1:size(fmc.time_data, 2), 1:size(fmc.time_data, 3)); 
rail_tester.raw_data.tx = rail_tester.raw_data.tx(:); 
rail_tester.raw_data.rx = rail_tester.raw_data.rx(:);
loaded_raw_file_ok = 1;
end

end  %  function   load_raw_data_fname
%--------NOT USED----------------%
%--------NOT USED----------------%




%--------WILL BE USED BELOW----------------%

function show_mesh(rail_tester)
trans_node_list    = rail_tester.array.trans_node_list;
mesh_              = rail_tester.mesh; 
figure;
    patch('Faces',mesh_.el.nds,'Vertices',mesh_.nd.pos, 'FaceColor', 'c'); axis equal;
    %hold on;
    %plot(mesh_.nd.pos(trans_node_list(1),1), mesh_.nd.pos(trans_node_list(1),2), 'go', 'MarkerFaceColor','g','MarkerSize',10);
    %plot(mesh_.nd.pos(trans_node_list(2),1), mesh_.nd.pos(trans_node_list(2),2), 'bo', 'MarkerFaceColor','b','MarkerSize',10);
    %plot(mesh_.nd.pos(trans_node_list(3),1), mesh_.nd.pos(trans_node_list(3),2), 'yo', 'MarkerFaceColor','y','MarkerSize',10);
    %plot(mesh_.nd.pos(trans_node_list(4),1), mesh_.nd.pos(trans_node_list(4),2), 'ro', 'MarkerFaceColor','r','MarkerSize',10);
end % function  show_mesh()


function showdispersion(plot_options,rail_tester)

if plot_options.showdispersion %plot dispersion curves for referencerail_tester.raw_data.tx = rail_tester.raw_data.tx(:); 
rail_tester.raw_data.rx = rail_tester.raw_data.rx(:);

    figure; 
    for i = 1:length(rail_tester.disperse.mode)
%disp(num2str(i))        
        plot(rail_tester.disperse.mode(i).freq / 1e3,rail_tester.disperse.mode(i).vph);
        temp_(i)= max(rail_tester.disperse.mode(i).freq); %find the limit of the frequency range
        legend_text{i} = sprintf('%s',rail_tester.disperse.mode(i).name); 
        hold on; 
    end
    ylim([0,5e3]); xlabel('Frequency (kHz)'); ylabel('Phase velocity (m/s)');
    xlim([0,min(temp_)/1e3]);
    legend(legend_text);
end % if plot_options.showdispersion %plot dispersion curves for reference

end %  function   showdispersion




function run_plots(rail_tester , plot_options , plot_distance)

if plot_options.showdispersion  == 1
showdispersion(plot_options,rail_tester)
end %if plot_options.showdispersion

%if plot_options.show_cw_result
%fn_plot_cw_result(rail_tester, plot_options);
%end %if plot_options.show_cw_result

if plot_options.show_feature_map
%  fn_plot_feature_map(rail_tester, plot_distance , plot_options);


[grid_data] = fn_get_grid_data(rail_tester , plot_options); 
fn_plot_grid_data(grid_data,plot_options,plot_distance);


% show_mode_map(grid_data , plot_options , 0)
end %if plot_options.show_feature_map


if plot_options.showmesh %plot mesh and show transducer nodes for reference
show_mesh(rail_tester)
end %if plot_options.showmesh %plot mesh and show transducer nodes for reference


if plot_options.show_cw_result == 1
fn_plot_cw_result(rail_tester, plot_options)
end %if plot_options.show_cw_result == 1

% keyboard
% fn_plot_cw_result(rail_tester, plot_options)

end %function run_plots(plot_options)






