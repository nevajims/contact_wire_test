%---------------------------------
%---------------------------------
% compare data path predictions
% (1) process the data
% (2) do the data checks (SNR/CAP/dist of peak)
% (3) run the prediction  
% 3 (a) build the data structure

% (4) produce a table with each file and the prediction from each DB + the
% data check info -  do prediction whether passedor not
% line 1449  of the main program :::
% rejection_indicators   =  plot_SNR_Raw(app.test_data,[0,0,0,0],snr_settings_O,app.base_width,app.base_height,app.mag_fac);

% LF = [pwd,settings_.Data_path_options{settings_.Data_path_choice}];
% proc_file.rail_tester  =  app.rail_tester;
% proc_file.test_data    =  app.test_data  ;
%  [~,PL_inf,~] = plot_predict_processed(proc_file, settings_ ,do_plots, LF,app.base_width,app.base_height,app.mag_fac);
%---------------------------------
%---------------------------------

function compare_LS_on_shifts(choice )
% choice = 1 (all) choice = 2 (select)
% do_plots -  add options for plotting after

LS_dir     =  'P:\GITHUBS\contact_wire_test\Learning_blocks'       ;
test_dir   =  'C:\Users\Dev\REPORT_data\SHIFT REPORTS\slab_data'   ; 
settings_dir  =   'P:\GITHUBS\contact_wire_test\SETTINGS_FILES'    ;
settings_dir2 =    'C:\Users\Dev\AppData\Roaming\SETTINGS_FILES'   ; 

default_options_fn =   'default_options3.mat'                     ;
proc_options_fn    =   'proc_options2.mat'                        ; 
snr_settings_fn    =   'snr_settings2.mat'                        ;
plot_options_fn    =   'plot_options2.mat'                        ; 


default_options = load([settings_dir,'\',default_options_fn]);
proc_options    = load([settings_dir2,'\',proc_options_fn]);
snr_settings    = load([settings_dir2,'\',snr_settings_fn]);
plot_options    = load([settings_dir2,'\',plot_options_fn]);  


plot_options_O  = convert_plot_options2_old_strct(plot_options);
settings_              = plot_options_O;
snr_settings_O  = convert_to_snr_struct(snr_settings);
do_plots   = [0 0 0 0 0 0 0 0 0 0 0 0];

dum = dir(LS_dir); all_names = {dum.name}; isdirect = [dum.isdir];
all_LS = {all_names{find(isdirect == 0)}};
dum = dir(test_dir);all_names = {dum.name}; isdirect = [dum.isdir];
all_tests = {all_names{find(isdirect == 0)}};
base_width                = 1920                  ; 
base_height               = 1080                  ; 
mag_fac                   =  1                    ;

switch(choice)
    case(1)    
chosen_tests = all_tests;
chosen_LS    = all_LS;
    case(2)
chosen_inds = listdlg('PromptString',{'Select learning sets to compare'}, 'ListString',all_LS);        
chosen_LS    = all_LS(chosen_inds);

chosen_inds = listdlg('PromptString',{'Select files to analyse'}, 'ListString',all_tests);
chosen_tests = all_tests(chosen_inds);
end  %switch(choice)

% Keyboard
% Table_data
% RESULTS_STRUCTURE = []; 
% Structure of the results ?


% predict all the learning sets

% ----------
% At start::
% ----------
% Put in the thresholds for the rejection indicators
% define here
%
% SNR Boundaries ---- 
% [num2str(snr_settings.SNR_boundaries_options(snr_settings.SNR_boundaries(1))),',',num2str(snr_settings.SNR_boundaries_options(snr_settings.SNR_boundaries(2))),',',num2str(snr_settings.SNR_boundaries_options(snr_settings.SNR_boundaries(3)))]
% Cap Boundaries 
% num2str(cap_min)
%  Dist boundaries
% dist_max = num2str(plot_options.dist_pass_val_upper /1000);   
% dist_min = num2str(plot_options.dist_pass_options(plot_options.dist_pass_index)/1000);
%
% Define the Learning sets
% LS1 = 
% LS2 = 
% etc
% ----------
% ----------
% TABLE
% ----------
% Identifiers::
% ----------
% Test Label / Date / Location / Sublocation / Tester
% Clamp details
% Arm (yes/no) / wire size (120/107) / Loc_on_NS (entry/exit)

% Rejection criteria::
% ----------
% Capacitance -- Pass/Fail(Result) / SNR -- Pass/Fail(Result) / Distance of peak -- Pass/Fail(Result)
% Result::
% ----------
% For each data set
% LS_1, LS_2    etc ...
% AI / DFM / LL  --  Text for each
% ----------

for index = 1:length(chosen_tests)
current_test = chosen_tests{index};
load([test_dir,'\',current_test]) ;
keyboard


NS_name{index} =   test_data.test_parameters.LU_Label_text        ;
Clamp_L        =   test_data.test_parameters.clamp_location       ;
arm_present    =   test_data.test_parameters.arm_present          ;  
Track_id       =   test_data.test_parameters.Track_id             ;
Test_DT        =   datetime(test_data.date_time)                  ;
Tester         =   test_data.tester_details.Name                  ; 
inds = find(current_test == '$')                                  ;
test_num       =     current_test(inds(1)+1:inds(2)-1)                ;

% now process the data
[rail_tester , ~ ]     =   create_rail_tester_structure(default_options, test_data, proc_options)           ;
rail_tester           =  fn_process_rail_data(rail_tester, proc_options)                                   ;

rejection_indicators   =   plot_SNR_Raw(test_data,[0,0,0,0],snr_settings_O,base_width,base_height,mag_fac)  ;

proc_file.rail_tester    = rail_tester       ;
proc_file.test_data      = test_data         ; 

% need the key settings in there
% Rejection indicators to check  -  capacitance  ///   SNR    //   Distance of peak //    
% If any fail  then give details in Brackets   --  so  PASS  or for peak find its PASS(Value) or FAIL(Value)

% FAIL (details) 
% need the  --   capacity threshold // SNR threshold and the // Peak find
% threshold   in the table for comparison 
% also give options to plot some of the plots  (mode map)    
% do it all here first
% Cap_res

%----------------------------------------------------
% Cap_res

cap_result= test_data.raw_data.cap_test_result.z;
b_temp = log10((cap_result(1:12,1)./cap_result(1:12,end)))';
cap_min  = plot_options.cap_thresh_options(plot_options.cap_thresh_index);
cap_fail_chns = find(b_temp<cap_min );

if isempty(cap_fail_chns)
Cap_res = 'PASS';
else
Cap_res = ['FAIL(',num2str(cap_fail_chns),')'];    
end %if isempty(cap_fail_chns)
cap_thresh = num2str(cap_min);

%----------------------------------------------------
%----------------------------------------------------
% SNR_res
[T_num]= find(rejection_indicators(2,:)==1);
if isempty(T_num)
SNR_res = 'PASS';
else    
SNR_res = ['FAIL(',num2str(T_num),')'];
end %if isempty(T_num)
SNR_THRESH = num2str(snr_settings.SNR_boundaries_options(snr_settings.SNR_boundaries(1)));
%----------------------------------------------------
%----------------------------------------------------



% now get everything except the prediction and peak find value 

for index2 = 1:length(chosen_LS) % go through the learning sets   
current_LS = ['P:\GITHUBS\contact_wire_test\Learning_blocks\',chosen_LS{index2}];
keyboard

[pred_,PL_inf,PFH] = plot_predict_processed(proc_file, settings_ ,do_plots, current_LS ,base_width,base_height,mag_fac);  

end %for index2 = 1:length(chosen_LS)    


for index = 1:length(chosen_tests)
% Now create the table....

% Create the tables with results
% go through each file and produce the required data

end % function compare_LS_on_shifts(   )





