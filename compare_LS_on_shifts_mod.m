function compare_LS_on_shifts(choice)

% Go throughh the files and get the dates
%  give the mean SNR and the method of calc
% colour the text
% remove invalid results-  not distance
% order by arm/ not arm
% Save ouput into a txt file as a structure to reload

%  Allow plotting of any of the graphs (e.g. mode maps)
%  ***DONE Mode maps plotted
%  ***DONE   plot the SNR values as well as
%  ***DONE Make the functions usable for both the windows and the analysis programs
%- ***DONE With an extra oputput   [   ,other_stuff]  =  etcetc  
%- ***DONE With an extra oputput   [   , ~ ]  =  etcetc as used in windows program   
%  ***DONE plot_SNR_Raw  
% Compare_LS_on_shifts(2)
% Choice = 1 (all) choice = 2 (select)  choice = 3 (load old data)
do_single_mode_plot = 1 ;
screen_parameters = get_screen_parameters();
[proc_options,plot_options,snr_settings,plot_options_O,snr_settings_O,LS_dir,test_dir,default_options]    =    get_all_settings();
[chosen_LS,chosen_tests]    =   get_the_tests_and_learning_sets(LS_dir,test_dir,choice)                        ;

do_plots   = [0 0 0 0 0 0 0 0 0 0 0 0 0]                                                                       ;

% [SNR_THRESH , SNR_Boundaries, cap_min,dist_pass_val,dist_pass_val_upper]   =    get_pass_fail_boundaries(plot_options,snr_settings) ;
[SNR__,cap_min,DIST__,SYM__]                                                 =    get_pass_fail_boundaries(plot_options,snr_settings) ;

%  Need the assymetry threhold + mean value to cause failure  (e.g. < 0.3(ratio) && >  1 (mean))  
group_conditions = define_the_prediction_conditions(SNR__ , cap_min , DIST__ , SYM__  ,chosen_LS , chosen_tests,test_dir) ;


for index = 1:length(chosen_tests)
[test_conditions{index} , current_test,test_data  ]  =  get_Individual_test_data_and_conditions(index,chosen_tests,test_dir);
disp(current_test)

[proc_file,rejection_indicators,SNR_details] = process_data_and_get_rejection_indicators(snr_settings_O,test_data,proc_options,default_options,screen_parameters);


temp_LS = [LS_dir,'\',chosen_LS{1}];


if do_single_mode_plot ==1
grid_data          =  fn_get_grid_data(proc_file.rail_tester , plot_options_O);
[~,lower_val,upper_val,~]  =  get_peak_vals_and_plot(grid_data , plot_options_O ,0,1,1,1 );
[ ~ , MP_mean,~] =  get_normalised_stack_and_mean_P(lower_val,upper_val,grid_data.data_stack);

SMM_vals{index}.slice_data         =  MP_mean ; 
SMM_vals{index}.grid_size_to_plot  =  plot_options_O.MM_interp_res   ;
SMM_vals{index}.db_range           =  plot_options_O.db_range        ;
SMM_vals{index}.filename_          =  current_test                   ;
SMM_vals{index}.grid_data          =  grid_data;                       
SMM_vals{index}.x_mult             =  1; 
SMM_vals{index}.y_mult             =  1;
SMM_vals{index}.mag_fac            =  1;

end %if do_single_mode_plot ==1



[pred_temp,PL_inf,~,~] = plot_predict_processed(proc_file, plot_options_O ,do_plots, temp_LS, screen_parameters.base_width,screen_parameters.base_height,screen_parameters.mag_fac);  

cap_result= test_data.raw_data.cap_test_result.z;


indicator_results{index} = get_indicators(index,cap_result,rejection_indicators,PL_inf ,SNR__ , cap_min , DIST__ , SYM__ ,pred_temp,SNR_details);

pred_results = [];

for index2 = 1:length(chosen_LS) % go through the learning sets   
current_LS = [LS_dir,'\',chosen_LS{index2}];

[prediction_temp,~,~,~] = plot_predict_processed( proc_file , plot_options_O , do_plots , current_LS , screen_parameters.base_width , screen_parameters.base_height , screen_parameters.mag_fac )  ;  

pred_results{index2} = prediction_temp;
end % for index2 = 1:length(chosen_LS)    
all_predictions{index} = pred_results;
end % for index = 1:length(chosen_tests)

plot_SNR_indicators(indicator_results)

if do_single_mode_plot
plot_SMM(SMM_vals)
end

Results_struct.group_conditions    = group_conditions  ; 
Results_struct.test_conditions     = test_conditions   ;
Results_struct.indicator_results   = indicator_results ;
Results_struct.all_predictions     = all_predictions   ; 
tabulate_the_results(Results_struct)

end % function compare_LS_on_shifts(   )
%---------------------------------------------------------------------------------------------------------------------
%---------------------------------------------------------------------------------------------------------------------
%---------------------------------------------------------------------------------------------------------------------




function plot_SMM(SMM_vals)
if length(SMM_vals) ==1
SP_inds = [1,1];    
elseif    length(SMM_vals)> 1 && length(SMM_vals) < 5
SP_inds = [2,2];
elseif length(SMM_vals) >= 5 && length(SMM_vals)  < 10
SP_inds = [3,3];
elseif length(SMM_vals) >= 10 &&  length(SMM_vals) < 17
SP_inds = [4,4];
elseif length(SMM_vals) >= 17 && length(SMM_vals) <26
SP_inds = [5,5];
elseif length(SMM_vals) >= 26 && length(SMM_vals) <43
SP_inds = [7,6];
elseif length(SMM_vals) >= 43 && length(SMM_vals) <50
SP_inds = [7,7];
elseif length(SMM_vals) >= 50
SP_inds = [8,7];
end %if length(SMM_vals) < 9



figure
for index = 1: length(SMM_vals) 
filename_ = SMM_vals{index}.filename_;
filename_ = filename_(1:end-4);
filename_ = ['(',num2str(index),')',filename_];
sph = subplot(SP_inds(1),SP_inds(2),index);
Plot_single_mode_map(SMM_vals{index}.slice_data,SMM_vals{index}.grid_size_to_plot,SMM_vals{index}.db_range,filename_ , SMM_vals{index}.grid_data,SMM_vals{index}.x_mult,SMM_vals{index}.y_mult,SMM_vals{index}.mag_fac,sph)

end %for index = 1 

end %function plot_SMM(SMM_vals)


function plot_SNR_indicators(indicator_results)

figure
for index = 1: length(indicator_results)
snr_bars(index,:) = indicator_results{index}.SNR_vals_float;
if index <10
y_labels{index} = ['Test ',num2str(index),' '];
else
y_labels{index} = ['Test ',num2str(index)]; 
end %if index <10
end %for index = 1: length(indicator_results)

for index2 = 1:12
if index <10
x_labels{index2} = ['T#',num2str(index2),' '];
else
x_labels{index2} = ['T#',num2str(index2)]; 
end %if index <10

end %for index2 = 1:12


snr_bars(snr_bars<0) = NaN;
HM_Handle = heatmap(round(snr_bars));
HM_Handle.ColorLimits = [-1 4];
HM_Handle.Colormap = jet;

HM_Handle.YDisplayLabels = y_labels;
HM_Handle.XDisplayLabels = x_labels;

HM_Handle.Title = 'Transducer SNR Values';
end %for index = 1: length(indicator_results)


function tabulate_the_results(Results_struct)
display_group_conditions(Results_struct.group_conditions)
display_test_conditions(Results_struct.test_conditions)
display_results_and_predictions(Results_struct)
show_valid_tests(Results_struct)

end %function tabulate_the_results(Results_struct)




function display_results_and_predictions(Results_struct)
% all tests including invalid ones

test_conditions = Results_struct.test_conditions;
indicator_results = Results_struct.indicator_results;
all_predictions = Results_struct.all_predictions;
group_conditions = Results_struct.group_conditions;

% first    
fprintf('---------------------------------------------------------------------------------------------------------------------\n')
fprintf('----------------PRE TEST CHECKS=-------------------------------------------------------------------------------------\n')
fprintf('---------------------------------------------------------------------------------------------------------------------\n')
fprintf('Test#\tCap\t\t\tSNR\t\t\t\tDist\t\tSYM\t\t\t\tSNR Vals\n')

for index = 1:length(indicator_results)
fprintf(['(',num2str(index),'):\t'])
fprintf([make_X_long(indicator_results{index}.Cap_res,10),'\t'])
fprintf([make_X_long(indicator_results{index}.SNR_res,15),'\t'])
fprintf([make_X_long(indicator_results{index}.dist_res,10),'\t'])
fprintf([make_X_long(indicator_results{index}.sym_res,15),'\t'])
fprintf([make_X_long(indicator_results{index}.SNR_vals,20),'\n'])
end %for index = 1:length(indicator_results)

%keyboard
% group_conditions

fprintf('---------------------------------------------------------------------------------------------------------------------\n')
fprintf('----------------PREDICTIONS------------------------------------------------------------------------------------------\n')
fprintf('---------------------------------------------------------------------------------------------------------------------\n')
%group_conditions.chosen_LS
fprintf('Test#\tValid\t\t\t\t')
for index2 = 1:length(group_conditions.chosen_LS)
%fprintf([ '(LS',num2str(index2),')',group_conditions.chosen_LS{index2},'\t\t'])
fprintf([ '(LS',num2str(index2),')','\t\t\t'])
end %for index2 = 1:length(group_conditions.chosen_LS)


fprintf('\n')
for index = 1:length(indicator_results)
fprintf(['(',num2str(index),'):\t'])

if indicator_results{index}.Cap_bin + indicator_results{index}.SNR_bin+ indicator_results{index}.dist_bin+  indicator_results{index}.sym_bin   ==4
valid_tag = 'VALID';
else
valid_tag = 'INVALID';
end

if indicator_results{index}.Cap_bin  ==0
valid_tag = [valid_tag,'(C)'];
end %if indicator_results{index}.Cap_bin  ==0
if indicator_results{index}.SNR_bin  ==0
valid_tag = [valid_tag,'(S)'];
end %if indicator_results{index}.SNR_bin  ==0
if indicator_results{index}.dist_bin ==0
valid_tag = [valid_tag,'(D)'];
end %if indicator_results{index}.dist_bin ==0
if indicator_results{index}.sym_bin == 0
valid_tag = [valid_tag,'(Sy)'];
end %if indicator_results{index}.dist_bin ==0

fprintf([make_X_long(valid_tag,15),'\t\t'])

for index2 = 1:length(group_conditions.chosen_LS)


    fprintf( make_X_long(all_predictions{index}{index2}.Labels{all_predictions{index}{index2}.pred_value},16),'\t\t\t\t\t\t\t');
end %for index2 = 1:length(indicator_results)
fprintf('\n')

end %for index = 1:length(indicator_results)
fprintf('---------------------------------------------------------------------------------------------------------------------\n')

end %function display_results_and_predictions(indicator_results,all_predictions)

function new_str = make_X_long(string_, X)
if X > length(string_)
new_str =    [string_,repmat(' ',1,X-length(string_))];
else
%disp(['str too long ',num2str(length(string_))])    
new_str = string_;
end
end %function make_X_long (string_, X)


function display_test_conditions(test_conditions)
fprintf('---------------------------------------------------------------------------------------------------------------------\n')
fprintf('----------------TEST NAMES\\LOCATIONS--------------------------------------------------------------------------------\n')
fprintf('---------------------------------------------------------------------------------------------------------------------\n')
fprintf(['Test#\tTest name\t\t\t\t\t\t#Instr\t\tNS name\n'])
fprintf('---------------------------------------------------------------------------------------------------------------------\n')
for index = 1 : length(test_conditions)
fprintf(['(',num2str(index),'):\t'])
fprintf([make_X_long(test_conditions{index}.test_name(1:end-4),30)    , '\t'      ])
fprintf([make_X_long(test_conditions{index}.instr_serial_number,10)   , '\t'     ])
fprintf([make_X_long(test_conditions{index}.NS_name(1:end-1),26)      , '\n'     ])
end %for index = 1 : length(test_conditions)

fprintf('---------------------------------------------------------------------------------------------------------------------\n')
fprintf('----------------TEST INFORMATION-------------------------------------------------------------------------------------\n')
fprintf('---------------------------------------------------------------------------------------------------------------------\n')
fprintf(['Test#\tClamp Location\tArm?\tTrack ID\tDate\t\t\tTime\t\tTester\t\t\ttag\n'])
fprintf('---------------------------------------------------------------------------------------------------------------------\n')
for index = 1 : length(test_conditions)
fprintf(['(',num2str(index),'):\t'])
fprintf([make_X_long(test_conditions{index}.Clamp_L,15)              , '\t'     ])
fprintf([make_X_long(test_conditions{index}.arm_present,5)          , '\t'     ])
fprintf([make_X_long(test_conditions{index}.Track_id,10)             , '\t'     ])
DateString_temp = datestr(test_conditions{index}.Test_DT );
fprintf([make_X_long(DateString_temp(1:strfind(DateString_temp,' ')-1),12) ,'\t'])
fprintf([make_X_long(DateString_temp(strfind(DateString_temp,' ')+1:end),10),'\t'])
fprintf([make_X_long(test_conditions{index}.Tester,12), '\t'])
fprintf([make_X_long(test_conditions{index}.test_num,10), '\n'])
end %for index = 1 : length(test_conditions)


end %function display_test_conditions(test_conditions)


function show_valid_tests(Results_struct)
% all tests including invalid ones
test_conditions = Results_struct.test_conditions;
indicator_results = Results_struct.indicator_results;
all_predictions = Results_struct.all_predictions;
group_conditions = Results_struct.group_conditions;

for index = 1: length(indicator_results)


end    % for index = 1: length(indicator_results)


end %function show_valid_tests(Results_struct)


function display_group_conditions(group_conditions)
fprintf('\n\n\n---------------------------------------------------------------------------------------------------------------------\n')
fprintf('-----------------GROUP SETTINGS--------------------------------------------------------------------------------------\n')
fprintf('---------------------------------------------------------------------------------------------------------------------\n')
fprintf(['Minimum Capacitance val:    ',num2str(group_conditions.cap_min),'\n'])
fprintf(['Distance pass val(min) :    ',num2str(group_conditions.dist_pass_val*1000),'mm\n'])
fprintf(['Distance pass val(max) :    ',num2str(group_conditions.dist_pass_val_upper*1000),'mm\n'])
fprintf(['SNR Threshold          :    ',group_conditions.SNR_THRESH,'\n'])
fprintf(['sym mean threshold(min) :   ',num2str(group_conditions.sym_mean_val_min),'\n'])
fprintf(['sym val  threshold(min) :   ',num2str(group_conditions.sym_min_val),'\n'])
for index = 1:length(group_conditions.chosen_LS)
fprintf(['Learning set(',num2str(index),')        :    ' ,group_conditions.chosen_LS{index},'\n'])
end %for index = 1:length(group_conditions.chosen_LS)
fprintf([ num2str(length(group_conditions.chosen_tests)), ' tests from: \n',strrep(group_conditions.test_dir,'\','\\'), '\n'])
end %function display_group_conditions(group_conditions)

function indicators = get_indicators(index,cap_result,rejection_indicators,PL_inf,SNR__ , cap_min , DIST__ , SYM__ , pred_temp,SNR_details)

all_bars              = SNR_details.all_bars            ;
SNR_uses_noise_chan   = SNR_details.SNR_uses_noise_chan ;

dist_pass_val       =  DIST__.dist_pass_val         ;
dist_pass_val_upper =  DIST__.dist_pass_val_upper   ;
% keyboard

%----------------------------------------------------
% Cap_res
b_temp = log10((cap_result(1:12,1)./cap_result(1:12,end)))';
cap_fail_chns = find(b_temp<cap_min );
if isempty(cap_fail_chns)
Cap_res = 'PASS';
Cap_bin = 1;
else
Cap_res = ['FAIL(',num2str( length(cap_fail_chns) ),')'];    
Cap_bin = 0;
end %if isempty(cap_fail_chns)
cap_thresh = num2str(cap_min);
indicators.Cap_res = Cap_res;
indicators.Cap_bin = Cap_bin;

%----------------------------------------------------
%----------------------------------------------------
% SNR_res

if SNR_uses_noise_chan ==1
SNR_insert = ' NC-' ;
else
SNR_insert = 'XNC-' ;
end %if SNR_uses_noise_chan ==1


[T_num]= find(rejection_indicators(2,:)==1);
if isempty(T_num)
SNR_res = [SNR_insert,'PASS'];
SNR_bin = 1;
else    
SNR_res = [SNR_insert,'FAIL(', num2str(length(T_num)),')'];
SNR_bin = 0;
end %if isempty(T_num)

vals_ = all_bars(2,:);
SNR_vals=[];

for index_ = 1:length(vals_)
if index_ ~= length(vals_)
SNR_vals = [SNR_vals,num2str(round(vals_(index_)*10)/10),'|'];
else
SNR_vals = [SNR_vals,num2str(round(vals_(index_)*10)/10)];    
end %if index_ ~= length(vals_)
end %for index_ = 1:length(vals_)
SNR_vals = ['[',SNR_vals ,']' ];

%----------------------------------------------------
%----------------------------------------------------
% DIST
% now do the distance value--- need the distance vector and the boundaries
% dist_pass_val, dist_pass_val_upper,PL_inf
peak_dist = PL_inf.DV(PL_inf.mod_val);
if peak_dist > dist_pass_val && peak_dist < dist_pass_val_upper
dist_res = 'PASS';
dist_bin = 1;
elseif peak_dist < dist_pass_val
dist_res = 'FAIL(near)';
dist_bin = 0;
elseif peak_dist > dist_pass_val_upper
dist_res = 'FAIL(far)';
dist_bin = 0;
end
%----------------------------------------------------
%----------------------------------------------------
%SYMMETRY
if pred_temp.Mode_SYM.val < SYM__. MP_sym_min_val && pred_temp.Mode_SYM.mean_val > SYM__.MP_sym_mean_val_min
sym_res = 'FAIL';
sym_bin = 0;
else
sym_res = 'PASS';
sym_bin = 1;
end
addtxt = ['(',num2str( round(10*pred_temp.Mode_SYM.val)/10 ),'S',',',num2str(round(10*pred_temp.Mode_SYM.mean_val)/10),'M)'];
sym_res = [sym_res,addtxt];
%----------------------------------------------------
%----------------------------------------------------

if SNR_bin== 1  && Cap_bin ==1 && sym_bin ==1
show_result_bin = 1;
else
show_result_bin = 0;
end %if SNR_bin== 1  && Cap_bin_ ==1 && sym_bin ==1

indicators.show_result_bin  = show_result_bin;
indicators.Cap_res          = Cap_res;
indicators.Cap_bin          = Cap_bin;
indicators.SNR_res          = SNR_res;
indicators.SNR_bin          = SNR_bin;
indicators.SNR_vals         = SNR_vals;
indicators.SNR_vals_float   =  vals_;
indicators.peak_dist        = peak_dist;
indicators.dist_res         = dist_res;
indicators.dist_bin         = dist_bin;
indicators.sym_res          = sym_res;
indicators.sym_bin          = sym_bin;

end %function prediction_structure = get_indicators(index,cap_result,cap_min,rejection_indicators);conditions_(index)

function [proc_file,rejection_indicators,SNR_details] = process_data_and_get_rejection_indicators(snr_settings_O,test_data,proc_options,default_options,screen_parameters)
base_width  =  screen_parameters.base_width        ; 
base_height =  screen_parameters.base_height       ; 
mag_fac     =  screen_parameters.mag_fac          ;

[rail_tester , ~ ]       =   create_rail_tester_structure(default_options, test_data, proc_options)             ;

rail_tester              =   fn_process_rail_data(rail_tester, proc_options)                                    ;

[rejection_indicators,Other_stuff]     =   plot_SNR_Raw(test_data,[0,0,0,0],snr_settings_O,base_width,base_height,mag_fac);


SNR_details.all_bars                   =   Other_stuff.all_bars                              ;
SNR_details.SNR_uses_noise_chan        =   Other_stuff.SNR_calc_method_uses_noise_channel    ;

proc_file.rail_tester    =   rail_tester                                                                        ;
proc_file.test_data      =   test_data;   
end %function [proc_file,rejection_indicators] = process_data_and_get_rejection_indicators(test_data,proc_options,default_options,screen_parameters)

function screen_parameters = get_screen_parameters()
screen_parameters.base_width                = 1920                  ; 
screen_parameters.base_height               = 1080                  ; 
screen_parameters.mag_fac                   =  1                    ;
end %function screen_parameters = get_screen_parameters()

function  [conditions_,current_test,test_data  ]  =  get_Individual_test_data_and_conditions(index,chosen_tests,test_dir)
current_test = chosen_tests{index};

conditions_.test_name = current_test;
dummy = load([test_dir,'\',current_test]) ; 
test_data = dummy.test_data  ;

conditions_.instr_serial_number  =   test_data.raw_data.serial_number               ;
conditions_.NS_name              =   test_data.test_parameters.LU_Label_text        ;
conditions_.Clamp_L              =   test_data.test_parameters.clamp_location       ;
conditions_.arm_present          =   test_data.test_parameters.arm_present          ;  
if strcmp(conditions_.arm_present,'Yes') == 1
conditions_.arm_present_bin = 1 ;
else
conditions_.arm_present_bin = 0 ;
end %if strcmp(conditions_.arm_present,'Yes') == 1



conditions_.Track_id             =   test_data.test_parameters.Track_id             ;
conditions_.Test_DT              =   datetime(test_data.date_time)                  ;
conditions_.Tester               =   test_data.tester_details.Name                  ; 
inds                             =   find(current_test == '$')                      ;
conditions_.test_num             =   current_test(inds(1)+1:inds(2)-1)              ;

end %function  [conditions_, current_test,test_data  ]    get_Indidual_test_data_and_conditions(index,chosen_tests )



%function [SNR_THRESH,SNR_Boundaries,cap_min,dist_pass_val,dist_pass_val_upper]    =    get_pass_fail_boundaries(plot_options,snr_settings)
function [SNR__,cap_min,DIST__,SYM__]    =    get_pass_fail_boundaries(plot_options,snr_settings)


%  Need the SNR threshold to cause failure at the top (Need he actual SNR vals)
SNR_Boundaries =   snr_settings.SNR_boundaries_options(snr_settings.SNR_boundaries) ;  % which on is the key boudary? 1,2 or 3? 



%  Need the Cap threshold to cause failure at the top --  which one ofthese
%  two::
cap_min           =  plot_options.cap_thresh_options(plot_options.cap_thresh_index);
%  Need the dist threshold to cause failure at the top 
dist_pass_val = plot_options.dist_pass_options(plot_options.dist_pass_index)/1000;
dist_pass_val_upper =  plot_options.dist_pass_val_upper/1000;

SNR_THRESH                              = num2str(snr_settings.SNR_boundaries_options(snr_settings.SNR_boundaries(1)));

MP_sym_mean_val_min =  plot_options.MP_mean_symmetry_options(plot_options.MP_mean_symmetry_choice); % if less than this flag
MP_sym_min_val      =   plot_options.symmetry_options(plot_options.symmetry_choice);                % if less than this flag 

SNR__.SNR_THRESH             = SNR_THRESH           ;
SNR__.SNR_Boundaries         = SNR_Boundaries       ;
DIST__.dist_pass_val         = dist_pass_val        ;
DIST__.dist_pass_val_upper   = dist_pass_val_upper  ;
SYM__.MP_sym_mean_val_min    = MP_sym_mean_val_min  ;
SYM__.MP_sym_min_val         = MP_sym_min_val       ;

end %function [SNR_THRESH,SNR_Boundaries,cap_min,dist_pass_val,dist_pass_val_upper]    =    get_pass_fail_boundaries(plot_options,snr_settings)





function [proc_options,plot_options,snr_settings,plot_options_O,snr_settings_O,LS_dir,test_dir,default_options]    =    get_all_settings()
LS_dir        =  [pwd,'\Learning_blocks' ];
test_dir      =  [getenv('systemDrive'),getenv('homePath'),'\REPORT_data\SHIFT REPORTS\slab_data']  ; 
settings_dir  =  [pwd,'\SETTINGS_FILES']                                                            ;
settings_dir2 =  [getenv('APPDATA'),'\SETTINGS_FILES']                                              ; 

default_options_fn =   'default_options3.mat'                                                       ;
proc_options_fn    =   'proc_options2.mat'                                                          ; 
snr_settings_fn    =   'snr_settings2.mat'                                                          ;
plot_options_fn    =   'plot_options3.mat'                                                          ; 

default_options = load([settings_dir,'\',default_options_fn]);
proc_options    = load([settings_dir2,'\',proc_options_fn]);
snr_settings    = load([settings_dir2,'\',snr_settings_fn]);
plot_options    = load([settings_dir2,'\',plot_options_fn]);  

plot_options_O  = convert_plot_options2_old_strct(plot_options);
snr_settings_O  = convert_to_snr_struct(snr_settings);



end %function [plot_options_O,snr_settings_O]    =    get_all_settings()

function [group_conditions] = define_the_prediction_conditions(SNR__ , cap_min , DIST__ , SYM__  , chosen_LS,chosen_tests,test_dir)

SNR_THRESH          = SNR__.SNR_THRESH             ;
SNR_Boundaries      = SNR__.SNR_Boundaries         ;
dist_pass_val       = DIST__.dist_pass_val         ;
dist_pass_val_upper = DIST__.dist_pass_val_upper   ;
MP_sym_mean_val_min = SYM__.MP_sym_mean_val_min    ;
MP_sym_min_val      = SYM__.MP_sym_min_val         ;

group_conditions = [];
group_conditions.SNR_THRESH             = SNR_THRESH  ;
group_conditions.cap_min                = cap_min     ;
group_conditions.dist_pass_val          = dist_pass_val ;
group_conditions.dist_pass_val_upper    = dist_pass_val_upper;
group_conditions.sym_mean_val_min       =   MP_sym_mean_val_min;   
group_conditions.sym_min_val            = MP_sym_min_val;  
group_conditions.chosen_LS              = chosen_LS ;
group_conditions.chosen_tests           = chosen_tests;
group_conditions.test_dir               = test_dir;
end %function [test_group_conditions]   = define_the_prediction_conditions(SNR_THRESH,cap_min,dist_past_m, chosen_LS,chosen_tests);


function [chosen_LS,chosen_tests_ordered]    =   get_the_tests_and_learning_sets(LS_dir,test_dir,choice)
dum = dir(LS_dir); all_names = {dum.name}; isdirect = [dum.isdir];

all_LS = {all_names{find(isdirect == 0)}};
dum = dir(test_dir);all_names = {dum.name}; isdirect = [dum.isdir];

all_tests = {all_names{find(isdirect == 0)}};

switch(choice)
    case(1)    
chosen_tests = all_tests;
chosen_LS    = all_LS;
chosen_inds = 1:length(chosen_tests);

    case(2)
chosen_inds = listdlg('PromptString',{'Select learning sets to compare'}, 'ListString',all_LS);        
chosen_LS    = all_LS(chosen_inds);

chosen_inds = listdlg('PromptString',{'Select files to analyse'}, 'ListString',all_tests);
chosen_tests = all_tests(chosen_inds);
end  %switch(choice)



% Re-arrange the files to be in date time order and out put it here as 
disp(['reordering ',num2str(length(chosen_inds))  ,' files in date order....'])

for index = 1: length(chosen_inds)
if index == length(chosen_inds)
fprintf([num2str(index),'.\n'])    
else
fprintf([num2str(index),'.'])    
end

temp = load([test_dir,'\',all_tests{chosen_inds(index)}]);
times_unordered(index,:) =temp.test_data.date_time;
end %for index = 1: length(chosen_inds)
tt = datetime(times_unordered);
[~, idx] = sort(tt);

chosen_tests_ordered =  chosen_tests(idx);

end %function [chosen_LS,chosen_inds]    =   get_the_tests_and_learning_sets(LS_dir,test_dir);




function  [mod_val,lower_val,upper_val,actual_peak_val]  =  get_peak_vals_and_plot(grid_data,settings_ , do_plot,x_mult,y_mult,mag_fac)
%--------------------------------------------------------------------------------------------
% function [mod_val  , lower_val  ,  upper_val  ,  actual_peak_val]  =  get_peak_values( )
%--------------------------------------------------------------------------------------------

initial_thresh       =   settings_.initial_thresh           ;
thresh_val           =   settings_.thresh_val               ;
num_slices           =   settings_.num_slices               ;
window_start         =   settings_.window_start             ;    
mode_map             =   grid_data.data_stack               ;
mm33                 =   squeeze(mode_map(3,3,:))           ;
dv                   =   grid_data.distance_vector          ;  
start_val            =   min(find(dv>window_start)) + min(find(mm33(find(dv>window_start))  >   max(mm33(find(dv>window_start)))*initial_thresh))-1;

mm33_s = mm33(start_val:start_val+200);
mm33_s_diff = diff(mm33_s);
dum_ = find(mm33_s_diff>0);
DV2 = dum_(find(diff(dum_)>1));
actual_peak_val = DV2(1)+ start_val;
actual_max_val = mm33(actual_peak_val);
target_val=  actual_max_val*thresh_val;

temp_val = actual_peak_val;
peak_found =0;
while peak_found ==0
temp_val = temp_val -1;
if mm33(temp_val) <= target_val
   mod_val = temp_val;
   peak_found =1;
end    

end % while peak_not_found ==1

lower_val     =   mod_val-floor(num_slices/2);
upper_val     =   mod_val+floor(num_slices/2);

if do_plot ==1
fig = uifigure('Resize','off','Units','normalized','Position',[0.05,0.05,0.29*mag_fac,0.435*mag_fac],'Name', 'PEAK LOCATION' );
fig.Icon = 'ICON2.png';
p1 = uipanel(fig,'Position',[x_mult*27 y_mult*22 x_mult*500 y_mult*430]);
p1.BorderColor = [0.94,0.94,0.94];

ax = uiaxes(p1,'Position',[x_mult*0  y_mult*0 x_mult*500 y_mult*430]);
%%ax.XGrid  = 'off' ;
%ax.YGrid  = 'off' ;
ax.Box    = 'on' ;

plot(ax,dv,mm33)
hold(ax,'on')
plot(ax,dv(actual_peak_val),mm33(actual_peak_val),'g.','markersize',10)
plot(ax,dv(mod_val),mm33(mod_val),'rs','markersize',10)
plot(ax,dv(lower_val),mm33(lower_val),'r.','markersize',10)
plot(ax,dv(upper_val),mm33(upper_val),'r.','markersize',10)
ax.XLim =[0 round(max(dv))];
ax.YLim = [0 1.2*max( mm33(find(dv>0)))];
ax.XLabel.String = 'Dist (m)';
ax.YLabel.String = 'M33 Amplitude';
ax.XLabel.FontSize = y_mult*10;
ax.YLabel.FontSize = y_mult*10;
plot(ax,[window_start window_start], [ax.YLim(1) ax.YLim(2)], 'r:')
plot(ax,[ax.XLim(1) ax.XLim(2)], [max(mm33(find(dv>window_start)))*initial_thresh max(mm33(find(dv>window_start)))*initial_thresh], 'b:')
leg_ =legend(ax,{'M33','Peak','Mode centre val', 'av start','av end','Xgate','Ygate'});
leg_.FontSize = y_mult*9;
ax.Title.String = (['Distance from instrument (for mode map): ',num2str(round(1000*dv(mod_val))), 'mm.']);
ax.Title.FontSize = y_mult*15;
end % if do_plot ==1
end % function [mod_val  , lower_val  ,  upper_val  ,  actual_peak_val]  =  get_peak_values(dv,mm33,initial_thresh,thresh_val,num_slices)


function [ MP_stack,MP_mean,MP_std ] = get_normalised_stack_and_mean_P(lower_val,upper_val,mode_map)    
MP_stack = zeros(4,4,upper_val-lower_val);
count = 0;
for index = lower_val:upper_val
count = count + 1;
temp_MM =mode_map(:,:,index);
MP_stack(:,:,count) = temp_MM;
MP_stack(:,:,count) = temp_MM/ mean(mean(temp_MM));
end  % for index = lower_val:upper_val
MP_mean = mean(MP_stack,3)  ;

MP_std  =  std(MP_stack,[],3)  ;
end %function [MP_stack,MP_mean] = get_normalised_stack_and_mean(lower_val,upper_val,mode_map)





function  Plot_single_mode_map(slice_data,grid_size_to_plot,db_range,filename_ , grid_data,x_mult,y_mult,mag_fac,sph )

%,mod_val,grid_data,lower_val,upper_val
dv =grid_data.distance_vector;
if grid_size_to_plot > 4
    x = linspace(1,size(slice_data,1),grid_size_to_plot);
    y = linspace(1,size(slice_data,2),grid_size_to_plot);
     %x = linspace(1,4,grid_size_to_plot);
    %y = linspace(1,4,grid_size_to_plot);
     
    [xi, yi] = meshgrid(x, y);
    interp_data = interp2([1:size(slice_data,1)],[1:size(slice_data,2)],slice_data,xi,yi);
else
    interp_data = slice_data;
end %if grid_size_to_plot > length(options.modes)
interp_data = [interp_data; zeros(1, size(interp_data, 2)) ] ;
interp_data = [interp_data, zeros(size(interp_data,1), 1)  ] ;
subplot(sph)
colormap default;
surf(interp_data);
view(2);
axis equal;
shading flat;
axis off;
caxis([0, db_range]);
colorbar;
filename_ = remove_(filename_);
title(filename_)
    sf = grid_size_to_plot / 4;
    offset = grid_size_to_plot / grid_size_to_plot;
modes_temp = [1,2,3,4];
for ii = 1:4
    a = text((ii - 0.5) * sf + 1, - offset + 1, sprintf('%i',modes_temp(ii)));
    set(a, 'HorizontalAlignment', 'center');
    set(a, 'VerticalAlignment', 'top');
    a = text(-offset + 1, (ii - 0.5) * sf + 1, sprintf('%i',modes_temp(ii)));
    set(a, 'HorizontalAlignment', 'right');
    set(a, 'VerticalAlignment', 'middle');
end % for ii = 1:length(options.modes)
end %function Plot_single_mode_map(MP_mean)


















