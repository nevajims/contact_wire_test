function [prediction_,peak_loc,PFH]  = plot_predict_processed(varargin)
%-------------------------------------
%-------------------------------------
%-------------------------------------
% have it display aa montage of  mean/std of tags
% 2 5 8 14
% prediction = [];
% deal with the  new input settings 
% (0)
% --  DONE
% (3)
% Deal with predition_colours  --  look at size of learning file and work
% From there
%
%  display in themode plot the position of on 33
%
% like the other:
% -  two options 
%-------------------------------------
%  nargin = 0
% --   select the file to predict
% --   select what to show  (do_plot)
%-------------------------------------
%  nargin = 3
%  varagin{1} rail_tester 
%  varagin{2} settings_
%  varagin{4} do_plots_
%-------------------------------------
%-------------------------------------
%-------------------------------------

switch(nargin)
     case(0)    
settings_              = load_structure_from_file('P:\GITHUBS\contact_AI\SETTINGS_FILES\plot_options2.dat');
% settings_.DATA_PATH  = settings_.Data_path_options{settings_.Data_path_choice};
starting_dir           =  'P:\GITHUBS\AIDATA';
P_W_D = pwd ;
if (exist('P:\GITHUBS\AIDATA')) == 7  
cd(starting_dir)
end %if (exist('P:\GITHUBS\AIDATA')) == 7  

[FILE_TO_PREDICT,file_path_]        =  uigetfile('*.mat',  'Selec the file to Predict'  ,'MultiSelect'  , 'off');
[DATA_FILE_TO_PREDICT,file_path_2]  =  uigetfile('*.mat',  'Selec the learning set'     ,'MultiSelect'  , 'off');
settings_.DATA_PATH  =  [file_path_2,DATA_FILE_TO_PREDICT];

cd (P_W_D)
do_plots = [0 0 0 0 0 0 0 0 0 0 0 0];
plot_list =   {'Peak find','Mode pairs','Single Mode map','mean/std of modes','MM Viewer','Tag MMs','Predictions','DFM table','LL Table','Overall Prediction','all mean/stds','means_v_tag/result'};
do_plots_dum =  choose_plots_to_show(plot_list);
do_plots(find(do_plots_dum ==1)) = 1;
dummy_1              = load([file_path_,FILE_TO_PREDICT]);
grid_data            = fn_get_grid_data(dummy_1.rail_tester , settings_);

  case(3)
% prediction_ = plot_predict_processed(PF,DP,do_plots)   
% PF = 'C:\Users\Dev\SLAB_data\2024\00 NEW HEAD\Processed_data\PD_CW_test_Mark_Evans__H0CE-107$4$_1.mat'      
% DP = 'P:\GITHUBS\contact_wire_test\Learning_blocks\Block_data_01234__102_tests.mat';
% do_plots = [0 0 0 0 1 0 0 0 0 0 0 0];

% load the settings
proc_file_path       =  varargin{1}                                 ; 
DP                   =  varargin{2}                                 ; 
do_plots             =  varargin{3}                                 ;


settings_            = load_structure_from_file('P:\GITHUBS\contact_AI\SETTINGS_FILES\plot_options2.dat')           ; 
settings_.DATA_PATH  = DP                                                                                           ;

proc_file              = load(proc_file_path);
rail_tester   =  proc_file.rail_tester                                                                              ;
grid_data     = fn_get_grid_data(rail_tester,settings_)                                                             ;  

FILE_TO_PREDICT = proc_file_path(max(find(proc_file_path =='\'))+1:end);

% select the file to predict

   case(4)

% prediction_ = plot_predict_processed(proc_file, settings_ ,do_plots, settings_.Data_path_options{settings_.Data_path_choice})        
proc_file            =  varargin{1}                                 ;   
settings_            =  varargin{2}                                 ;
do_plots             =  varargin{3}                                 ;
DP                   =  varargin{4}                                 ;   

settings_.DATA_PATH  =  DP                                          ;
% settings_.DATA_PATH  = settings_.Data_path_options{settings_.Data_path_choice};
rail_tester   =  proc_file.rail_tester                       ;
grid_data     = fn_get_grid_data(rail_tester , settings_) ;
FILE_TO_PREDICT = proc_file.test_data.file_with_path(max(find(proc_file.test_data.file_with_path =='\'))+1:end);


mag_fac                   =  1.9531;
base_width                = 1920                  ; 
base_height               = 1080                  ; 
Pix_SS = get(0,'screensize')                ;
x_mult = (Pix_SS(3)/base_width)   * mag_fac ;
y_mult = (Pix_SS(4)/base_height)  * mag_fac ;



    case(7)

% prediction_ = plot_predict_processed(proc_file, settings_ ,do_plots, settings_.Data_path_options{settings_.Data_path_choice})        
proc_file            =  varargin{1}                                 ;   
settings_            =  varargin{2}                                 ;
do_plots             =  varargin{3}                                 ;
DP                   =  varargin{4}                                 ;   

% prediction_ = plot_predict_processed(
base_width = varargin{5};
base_height = varargin{6};
mag_fac   = varargin{7};

Pix_SS = get(0,'screensize')                ;
x_mult = (Pix_SS(3)/base_width)   * mag_fac ;
y_mult = (Pix_SS(4)/base_height)  * mag_fac ;




settings_.DATA_PATH  =  DP                                          ;
% settings_.DATA_PATH  = settings_.Data_path_options{settings_.Data_path_choice};
rail_tester   =  proc_file.rail_tester                       ;
grid_data     = fn_get_grid_data(rail_tester , settings_) ;
FILE_TO_PREDICT = proc_file.test_data.file_with_path(max(find(proc_file.test_data.file_with_path =='\'))+1:end);
end  % switch(nargin)        

PFH = [];





%---------------------------------------------------------
%---------------------------------------------------------
% ----------------------------------------------------
%other internal stuff

labels = {'1-1','1-2','1-3','1-4','2-1','2-2','2-3','2-4','3-1','3-2','3-3','3-4','4-1','4-2','4-3','4-4'};
mod_vals_inds = [1,1;1,2;1,3;1,4;2,1;2,2;2,3;2,4;3,1;3,2;3,3;3,4;4,1;4,2;4,3;4,4];
% ----------------------------------------------------
dummy = load(settings_.DATA_PATH) ;
Block_DATA = dummy.Block_DATA   ;
%------------------------------------------------------------------------------
%------------------------------------------------------------------------------

switch(length(Block_DATA.Labels_))
    case(2)
settings_.predition_colours      =    [1,3] ;  % 1 = green / 3 = red         
    case(3)
settings_.predition_colours      =    [1,2,3] ;  % 1 = green // 2 = yellow  // 3 = red         
    case(4)
settings_.predition_colours      =    [1,1,2,3] ;  % 1 = green // 2 = yellow  // 3 = red         
    case(5)
settings_.predition_colours      =    [1,1,2,3,3] ;  % 1 = green // 2 = yellow  // 3 = red         
    case(6)
settings_.predition_colours      =    [1,1,2,3,3,3] ;  % 1 = green // 2 = yellow  // 3 = red         
end %switch(length(Block_DATA.Labels_))

[slice_options,slice_indices] = get_slice_options(Block_DATA.max_number_of_slices) ;

[Slice_index,Thresh_index]  = get_index_value (settings_,Block_DATA,slice_options) ;  %  extract from the learning file

[mod_val,lower_val,upper_val,~]  =  get_peak_vals_and_plot(grid_data,settings_ ,do_plots(1),x_mult,y_mult,mag_fac );

peak_loc.DV =  grid_data.distance_vector;
peak_loc.mod_val = mod_val;



if do_plots(2) ==1
plot_mode_pairs(mod_val, grid_data,labels,mod_vals_inds,x_mult,y_mult,mag_fac) 
end  %if do_plots(2) ==1

[ ~ , MP_mean,MP_std] =  get_normalised_stack_and_mean_P(lower_val,upper_val,grid_data.data_stack);

if do_plots(3) ==1
Plot_single_mode_map(MP_mean,settings_.MM_interp_res,settings_.db_range, FILE_TO_PREDICT(1:end-4),grid_data,x_mult,y_mult,mag_fac)
end %if do_plots(3) ==1

if do_plots(4) ==1
Plot_mean_and_std_of_MM (MP_mean,MP_std,settings_.mode_pairs_to_Use,FILE_TO_PREDICT,labels,x_mult,y_mult,mag_fac)
end %if do_plots(4) ==1

if do_plots(5) ==1
raw_mode_map_viewer(grid_data,mod_val,settings_.MM_interp_res,settings_.db_range,x_mult,y_mult,mag_fac )
end

%------------------------------------------------------------------------------
%------------------------------------------------------------------------------
% Predictions
%------------------------------------------------------------------------------
%------------------------------------------------------------------------------
% LS = Learning set

LS_crack_mode_matrices = create_crack_mode_matrices(Block_DATA.crack_mode_ , Thresh_index, slice_indices{Slice_index});

% creates learning block on the fly

AI_Block  = Create_AI_learning_Block(settings_.NumNeighbors , settings_.mode_pairs_to_Use, LS_crack_mode_matrices  ,  Block_DATA.Labels_ , Block_DATA.tag_label_index );

%SV = specific value (the test to be predicted)
SV_crack_mode     = MP_mean ; 
SV_temp    = reshape(SV_crack_mode, 1 , numel(SV_crack_mode))  ;      

[ai_tag,~,~] = predict(AI_Block , SV_temp(settings_.mode_pairs_to_Use));

Block_DATA  =  add_means_and_std_of_tags_to_Block_DATA(Block_DATA,LS_crack_mode_matrices);

if do_plots(6) ==1
display_tag_mode_maps(Block_DATA,settings_,MP_mean,FILE_TO_PREDICT,x_mult,y_mult,mag_fac)
end % if do_plots(6) ==1

Score_vals =  get_Score_vals(SV_temp,Block_DATA , settings_.mode_pairs_to_Use);
[DFM_table, LL_table, DFM_tag , LL_tag]    = get_tags_and_score_tables(Score_vals,labels,settings_.mode_pairs_to_Use,Block_DATA.Labels_);
prediction_.ai_tag  =  ai_tag{1}         ;
prediction_.DFM_tag =  DFM_tag            ;
prediction_.LL_tag  =  LL_tag             ;
prediction_.Labels  =  Block_DATA.Labels_  ;
prediction_.values  =  get_prediction_values(prediction_);
prediction_.colours =  settings_.predition_colours;

temp_V =  prediction_.values;
if length(unique(temp_V))==length(temp_V)
pred_value = ceil(mean(temp_V));
% floor(mean(temp_V))
txt_insrt = 'c';
elseif length(unique(temp_V)) == 2    
pred_value = mode(temp_V);
txt_insrt = 'b';
elseif length(unique(temp_V)) == 1    
pred_value = mode(temp_V);
txt_insrt = 'a';
end %if length(unique(temp_V))==length(temp_V)
prediction_.pred_value = pred_value;
prediction_.txt_insrt = txt_insrt;


if do_plots(7) ==1
show_predictions(prediction_ ,settings_.predictions2use,x_mult,y_mult,mag_fac) ;    
end %if do_plots(7) ==1

if do_plots(8) ==1
show_dfm_table(DFM_table,length(settings_.mode_pairs_to_Use),x_mult,y_mult,mag_fac );
end %if do_plots(7) ==1

if do_plots(9) ==1
show_LL_table(LL_table,length(settings_.mode_pairs_to_Use),x_mult,y_mult,mag_fac);
end %if do_plots(7) ==1

if do_plots(10) ==1

    PFH  = do_overall_prediction(prediction_,x_mult,y_mult,mag_fac);    

end %if do_plots(10) ==1

if do_plots(11) ==1
do_all_stds(Block_DATA,MP_mean,MP_std,settings_,FILE_TO_PREDICT,labels,x_mult,y_mult,mag_fac);    
end %if do_plots(10) ==1

if do_plots(12) ==1
do_mean_vs_group(Block_DATA,MP_mean,MP_std,settings_,FILE_TO_PREDICT,labels,mod_vals_inds,x_mult,y_mult,mag_fac);    
end %if do_plots(10) ==1


%---------------------------------------------------------------------------------------------------------
%---------------------------------------------------------------------------------------------------------
end %function predict_plot_processed()
%---------------------------------------------------------------------------------------------------------
%---------------------------------------------------------------------------------------------------------
% END OF MAIN
%---------------------------------------------------------------------------------------------------------
%---------------------------------------------------------------------------------------------------------
function  do_mean_vs_group(Block_DATA,MP_mean,MP_std,settings_,FILE_TO_PREDICT,labels,mod_vals_inds,x_mult,y_mult,mag_fac)    
subplot_inds = [1,1 ; 2,1 ; 2,2 ; 2,2 ; 3,2 ; 3,2 ; 3,3 ; 3,3 ; 3,3 ; 3,4 ; 3,4 ; 3,4 ; 4,4 ; 4,4 ; 4,4 ; 4,4];
LL_ = length(Block_DATA.Labels_);      % might not need
%MP2U = 
L_MP2U = length(settings_.mode_pairs_to_Use);
MP2U = mod_vals_inds(settings_.mode_pairs_to_Use,:);
x_nums = 1:LL_ ;

fig = uifigure('Resize','on','Units','normalized','Position',[0.05,0.05,0.29*mag_fac,0.44*mag_fac],'Name', 'Tag RCs vs Test RC for chosen MPs');
fig.Icon = 'ICON2.png';
dum_tit = 'Tag reflection coefficients vs Test (for predictive Mode Pairs)';

px_LH = 10; py_LH = 10; px_SZ = 538; py_SZ = 453;
p1 = uipanel(fig,'Position',[x_mult*px_LH y_mult*py_LH x_mult*px_SZ y_mult*py_SZ],'AutoResizeChildren','off');
p1.BorderColor = [0.94,0.94,0.94];
%dum_tit = FILE_TO_PREDICT(1:end-4);
%dum_tit(find(dum_tit=='_')) = ' ';
p1.Title = dum_tit;
p1.FontSize = 16*y_mult;
p1.TitlePosition = 'centertop';
p1.FontWeight = 'bold';

for   index = 1:L_MP2U
ax{index} =   subplot( subplot_inds(L_MP2U,1) , subplot_inds(L_MP2U,2),index,'Parent', p1);
[means_for_tag,stds_for_tag]  = get_mean_stds_for_mp(Block_DATA.mean_tag_modes_,Block_DATA.std_tag_modes_ ,mod_vals_inds( settings_.mode_pairs_to_Use(index),:));
errorbar(ax{index},x_nums,means_for_tag,stds_for_tag,':o');
hold(ax{index},'on')
temp_val  = MP_mean(mod_vals_inds( settings_.mode_pairs_to_Use(index),1),mod_vals_inds( settings_.mode_pairs_to_Use(index),2));
XLim             =  [0.75,LL_+0.25]    ;
plot(ax{index},[XLim(1),XLim(2)],[temp_val,temp_val],'g:','LineWidth',1.3)

temp_val2 = MP_std(mod_vals_inds( settings_.mode_pairs_to_Use(index),1),mod_vals_inds( settings_.mode_pairs_to_Use(index),2));                                   

plot(ax{index},[XLim(1),XLim(2)],[temp_val+temp_val2,temp_val+temp_val2],'g:','LineWidth',0.6*y_mult)
plot(ax{index},[XLim(1),XLim(2)],[temp_val-temp_val2,temp_val-temp_val2],'g:','LineWidth',0.6*y_mult)

ax{index}.XTick=  1:LL_              ; 
ax{index}.XLim             =   [0.75,LL_+0.25]    ;
ax{index}.XTickLabel       =   Block_DATA.Labels_ ;
ax{index}.YLabel.String    =  'Norm RC'           ;
ax{index}.XLabel.String    =  'Tags'              ;
ax{index}.Title.String     =  labels{settings_.mode_pairs_to_Use(index)};
if L_MP2U < 5
ax{index}.Title.FontSize = 10*y_mult;
ax{index}.XLabel.FontSize =10*y_mult;
ax{index}.YLabel.FontSize =10*y_mult;
end

if L_MP2U < 5
if index ==1
legend(ax{index},{'Learning Set','Test'},'location','NorthWest')
end %if index ==1
end %if index == 1

end  %for   index = 1:L_MP2U
end %function  do_mean_vs_group(Block_DATA,MP_mean,MP_std,settings_,FILE_TO_PREDICT,labels)    

function [means_ , stds_]  = get_mean_stds_for_mp( means_TM , std_TM , mode_ind )

means_     = zeros(1,length(means_TM))  ;
stds_      = zeros(1,length(std_TM))    ;

for index = 1:length(std_TM)
means_(index) = means_TM{index}(mode_ind(1),mode_ind(2));
stds_ (index) = std_TM{index}(mode_ind(1),mode_ind(2)); 
end %for index = 1:length(std_TM)
end %function [means_,stds_]  = get_mean_stds_for_mp(means_TM,std_TM,mode_ind)


function do_all_stds(Block_DATA,MP_mean,MP_std,settings_,FILE_TO_PREDICT,labels,x_mult,y_mult,mag_fac)

subplot_inds = [1,1;2,1;2,2;2,2;3,2;3,2];
LL_ = length(Block_DATA.Labels_);
max_y_val = max(max(MP_mean));
fig = uifigure('Resize','off','Units','normalized','Position',[0.05,0.05,0.355*mag_fac,0.55*mag_fac],'Name', 'Mean/STD of Tags vs Test');
fig.Icon = 'ICON2.png';
px_LH = 10; py_LH = 10; px_SZ = 660; py_SZ = 570;
p1 = uipanel(fig,'Position',[x_mult*px_LH y_mult*py_LH x_mult*px_SZ y_mult*py_SZ],'AutoResizeChildren','off');
p1.BorderColor = [0.94,0.94,0.94];
tit_ins = settings_.DATA_PATH(max(find(settings_.DATA_PATH=='\'))+1:end-4); 
tit_ins(find(tit_ins=='_'))=' ';
p1.Title = ['Mean/STD for learning set: ', tit_ins,' : compared with Test'] ;
p1.FontSize = 22*y_mult;
p1.TitlePosition = 'centertop';
p1.FontWeight = 'bold';

for index_a = 1: (LL_)
cur_max =  max(max(Block_DATA.mean_tag_modes_{index_a}));    
if cur_max > max_y_val
max_y_val = cur_max;
end %if cur_max > max_y_val
num_tag_tests(index_a) = length(find(Block_DATA.tag_label_index ==index_a));
end % for index_a = 1: (LL_)

for index = 1: (LL_+ 1)
ax{index} =   subplot(subplot_inds(LL_+ 1,1),subplot_inds(LL_+ 1,2),index, 'Parent', p1);    

if index == LL_+ 1 
Plot_mean_and_std_of_MM_2 (MP_mean,MP_std, MP_mean , MP_std , settings_.mode_pairs_to_Use , 'TEST' , labels,ax{index},max_y_val,1 )
else    
Plot_mean_and_std_of_MM_2 (Block_DATA.mean_tag_modes_{index}, Block_DATA.std_tag_modes_{index},MP_mean , MP_std , settings_.mode_pairs_to_Use , Block_DATA.Labels_{index} , labels , ax{index},max_y_val,num_tag_tests(index) )
end %if index == LL_+ 1 
end %for index = 1: LL_
end %function do_all_stds()


function Plot_mean_and_std_of_MM_2 (MP_mean  ,  MP_std, MP_mean2  ,  MP_std2  ,  mode_pairs_to_Use  ,   title_,labels,ax,max_y_val,num_tag_tests)

std_bar_size = 1;
val_nos_tmp = 1:16;
spec_vals_means = reshape(MP_mean, 1 , numel(MP_mean));
spec_vals_std = reshape(MP_std, 1 , numel(MP_std));
spec_vals_means_2 = reshape(MP_mean2, 1 , numel(MP_mean2));
spec_vals_std_2 = reshape(MP_std2, 1 , numel(MP_std2));

errorbar(ax,val_nos_tmp,spec_vals_means , spec_vals_std*std_bar_size,':o');
hold(ax,'on')

errorbar(ax,mode_pairs_to_Use,spec_vals_means_2(mode_pairs_to_Use),spec_vals_std_2(mode_pairs_to_Use)*std_bar_size,'rs','markersize',15)
ax.XTick       =  1:16   ;
ax.XLim        = [0,17]  ;
ax.XTickLabel  = labels  ;
ax.YLim        = [0,max_y_val*1.1] ;

ax.Title.String = [title_,'(',num2str(num_tag_tests),')'];
ax.Title.FontSize = 10*y_mult;

end %function Plot_mean_and_std_of_MM (MP_mean,MP_std,settings_.mode_pairs_to_Use )

%---------------------------------------------------------------------------------------------------------
%---------------------------------------------------------------------------------------------------------
%---------------------------------------------------------------------------------------------------------
%---------------------------------------------------------------------------------------------------------
%---------------------------------------------------------------------------------------------------------
%---------------------------------------------------------------------------------------------------------

function fig =  do_overall_prediction(prediction_,x_mult,y_mult,mag_fac)

%Pix_SS = get(0,'screensize');
%x_mult = Pix_SS(3)/1920;
%y_mult = Pix_SS(4)/1080;

fig = uifigure('Resize','off','Units','normalized','Position',[ 0.05,0.05,0.195*mag_fac,0.247*mag_fac],'Name', 'Prediction');
fig.Icon = 'ICON2.png';
RGB_colours = [0,1,0; 1 0.5 0  ;1,0,0];

pred_value  = prediction_.pred_value;       
txt_insrt   = prediction_.txt_insrt;
pred_txt = [prediction_.Labels{pred_value},'(',txt_insrt,')'];

tx1 = uitextarea(fig,'Position',[x_mult*60 y_mult*100 x_mult*240 y_mult*40], 'Value',pred_txt,'FontSize',y_mult*25,'FontColor',RGB_colours(prediction_.colours(pred_value),:),'FontWeight','bold','HorizontalAlignment','center');
tx2 = uitextarea(fig,'Position',[x_mult*60 y_mult*160 x_mult*240 y_mult*40], 'Value','PREDICTION','FontSize',y_mult*20,'FontWeight','bold','HorizontalAlignment','center');
end %function do_overall_prediction(prediction_)






function do_plots =  choose_plots_to_show(plot_list)
[ones_,~] = listdlg('ListString',plot_list);
do_plots(ones_) = 1;
end %function do_plots =  choose_plots_to_show(plot_list);

function values_ = get_prediction_values(prediction_)

values_ = zeros(1,3);



for index = 1:length(prediction_.Labels)

if strcmp(prediction_.ai_tag, prediction_.Labels{index})
values_(1) = index;
end %if strcmp(prediction_.ai_tag, prediction_.Labels{index})

if strcmp(prediction_.DFM_tag, prediction_.Labels{index})
values_(2) = index;
end %if strcmp(prediction_.DFM_tag, prediction_.Labels{index})

if strcmp(prediction_.LL_tag, prediction_.Labels{index})
values_(3) = index;
end %if strcmp(prediction_.LL_tag, prediction_.Labels{index})

end %for index = 1:length(prediction_.Labels)

end %function values_ = get_prediction_values(prediction_)

function show_dfm_table(DFM_table,no_el,x_mult,y_mult,mag_fac)

fig = uifigure('Resize','off','Units','normalized','Position',[0.05,0.05,0.29*mag_fac,0.435*mag_fac],'Name', 'Dist from Mean' );
fig.Icon = 'ICON2.png';

uit = uitable(fig,'Data',DFM_table,'Position',[x_mult*135,y_mult*170,x_mult*300,y_mult*145]) ;
UITA = uitextarea(fig,'Position',[x_mult*140 y_mult*350 x_mult*240 y_mult*37], 'Value','DfM (normalised by std)','FontSize',y_mult*20,'FontWeight','bold','HorizontalAlignment','center');

end %function show_dfm_table(DFM_table)

function show_LL_table(LL_table,no_el,x_mult,y_mult,mag_fac)

fig = uifigure('Resize','off','Units','normalized','Position',[0.05,0.05,0.29*mag_fac,0.435*mag_fac],'Name', 'Log Likelyhood' );
fig.Icon = 'ICON2.png';

uit = uitable(fig,'Data',LL_table,'Position',[x_mult*135,y_mult*170,x_mult*300,y_mult*145],'FontSize',12*y_mult) ;
UITA = uitextarea(fig,'Position',[x_mult*140 y_mult*350 x_mult*240 y_mult*37], 'Value','Log Likelyhood','FontSize',y_mult*20,'FontWeight','bold','HorizontalAlignment','center');

end %function show_LL_table(LL_table)

function show_predictions(prediction_, predictions2use,x_mult,y_mult,mag_fac )
fig = uifigure('Resize','off','Units','normalized','Position',[ 0.05,0.05,0.18*mag_fac,0.247*mag_fac],'Name', '3 Methods');
fig.Icon = 'ICON2.png';

ai_tag  =  prediction_.ai_tag  ;
DFM_tag = prediction_.DFM_tag  ; 
LL_tag  = prediction_.LL_tag   ;
Labels  = prediction_.Labels   ;
values  = prediction_.values   ;
colours = prediction_.colours  ;

if predictions2use(1)==1
AI_txt = ['AI Pred = ',ai_tag];
else
AI_txt = [];
end %if predictions2use(1)==1

if predictions2use(2)==1
DFM_txt = ['DFM Pred = ',DFM_tag];
else
DFM_txt = [];
end %if predictions2use(2)==1

if predictions2use(3)==1
LL_txt = ['LL Pred = ',LL_tag];
else
LL_txt = [];
end %if predictions2use(3)==1
RGB_colours = [0,1,0; 1 0.5 0  ;1,0,0];
str1  = AI_txt  ;
str2  = DFM_txt ;
str3  = LL_txt  ;

tx1 = uitextarea(fig,'Position',[x_mult*40 y_mult*130 x_mult*260 y_mult*40], 'Value',str1,'FontSize',y_mult*25,'FontColor',RGB_colours(colours(values(1)),:),'FontWeight','bold','HorizontalAlignment','center');
tx2 = uitextarea(fig,'Position',[x_mult*40 y_mult*80 x_mult*260 y_mult*40], 'Value',str2,'FontSize',y_mult*25,'FontColor',RGB_colours(colours(values(2)),:),'FontWeight','bold','HorizontalAlignment','center');
tx3 = uitextarea(fig,'Position',[x_mult*40 y_mult*30 x_mult*260 y_mult*40], 'Value',str3,'FontSize',y_mult*25,'FontColor',RGB_colours(colours(values(3)),:),'FontWeight','bold','HorizontalAlignment','center');
tx4 = uitextarea(fig,'Position',[x_mult*40 y_mult*200 x_mult*260 y_mult*40], 'Value','PREDICTIONS','FontSize',y_mult*20,'FontWeight','bold','HorizontalAlignment','center');


end % function show_predictions(ai_tag, DFM_tag , LL_tag ,Labels_,predictions2use )

%-------------------------------------------------------------------------
%-------------------------------------------------------------------------
%-------------------------------------------------------------------------

function  [DFM_table, LL_table, DFM_tag , LL_tag]    = get_tags_and_score_tables(Score_vals,labels,mode_pairs_to_Use,Tags_)

%DFM-------------Distance From mean-----------------------------------------

%----old
%{
DFM_mat = zeros( length(Score_vals.Means_) , length(mode_pairs_to_Use) + 1 );
for index = 1 :length(Score_vals.Means_)
temp_ =  100 * abs((Score_vals.Means_{index}-Score_vals.spec_vals_ ));
DFM_mat(index,:) = [temp_,mean(temp_)];
end % for index = 1 :length(Score_vals.Means_)
%}
%----old

%------------new
for index = 1 :length(Score_vals.Means_)
temp_ =  Score_vals.Means_{index};
mean_mat(index,:) = [temp_,mean(temp_)];
end % for index = 1 :length(Score_vals.Means_)

for index = 1 :length(Score_vals.Means_)
temp_ =  Score_vals.Stds_{index};
std_mat(index,:) = [temp_,mean(temp_)];
end % for index = 1 :length(Score_vals.Means_)

std_dist_mat = abs((mean_mat(:,1:end-1) - Score_vals.spec_vals_))  ./ std_mat(:,1:end-1);  
std_dist_mat = [std_dist_mat,mean(std_dist_mat,2)];
std_dist_mat =  round(std_dist_mat*100)/100; 

DFM_mat = std_dist_mat;
%------------new



columns__ =  [labels(mode_pairs_to_Use),{'Mean'}];

[~ ,DFM_index]  =  min(DFM_mat(:,end));
DFM_tag = Tags_{DFM_index};
DFM_table = array2table(DFM_mat,...
       'VariableNames',columns__,...
       'RowNames',Tags_); 

%DFM-------------Distance From mean-----------------------------------------

%LL---------------Log Likelyhood---------------------------------------
for index = 1 :length(Score_vals.Means_)
temp_ = round(100*abs(log( Score_vals.Stds_{index}.*pdf('Normal',Score_vals. spec_vals_ , Score_vals.Means_{index},Score_vals.Stds_{index}))))/100;
LL_mat(index,:) = [temp_,mean(temp_)];
end % for index = 1 :length(Score_vals.Means_)


LL_table = array2table(LL_mat,...
       'VariableNames',columns__,...
       'RowNames',Tags_); 

[~ ,LL_indx]  =  min(LL_mat(:,end));
LL_tag = Tags_{LL_indx};
%LL---------------Log Likelyhood---------------------------------------

end %function  [DFM_table,LL_table, DFM_tag , LL_tag]    = get_tags_score_tables(Score_vals,labels,mode_pairs_to_Use,Block_DATA.Labels_);

function Score_vals =  get_Score_vals(spec_vals_temp,Block_DATA , mode_pairs_to_Use)

for index = 1: length(Block_DATA.Labels_)
mean_temp         =  reshape (Block_DATA.mean_tag_modes_{index},1,numel(Block_DATA.mean_tag_modes_{index}));
SD_temp           =  reshape (Block_DATA.std_tag_modes_{index},1,numel(Block_DATA.std_tag_modes_{index}));
Means_{index} = mean_temp(mode_pairs_to_Use);
Stds_{index}  = SD_temp(mode_pairs_to_Use);
end %for index = 1: length(Block_DATA.Labels_)

Score_vals.Means_       =  Means_                              ;
Score_vals.Stds_        =  Stds_                               ; 
Score_vals.spec_vals_   =  spec_vals_temp(mode_pairs_to_Use)   ;
end %function Score_vals =  get_Score_vals(SV_temp,Block_DATA , settings_.mode_pairs_to_Use, labels)

function   display_tag_mode_maps(Block_DATA,settings_,MP_mean,FILE_TO_PREDICT,x_mult,y_mult,mag_fac)

subplot_inds = [1,1;2,1;2,2;2,2;3,2;3,2];
LL_ = length(Block_DATA.Labels_);



fig = uifigure('Resize','off','Units','normalized','Position',[0.05,0.05,0.29*mag_fac,0.435*mag_fac],'Name', 'Tag Mode vs Test');
fig.Icon = 'ICON2.png';
px_LH = 10; py_LH = 10; px_SZ = 530; py_SZ = 450;
p1 = uipanel(fig,'Position',[x_mult*px_LH y_mult*py_LH x_mult*px_SZ y_mult*py_SZ],'AutoResizeChildren','off');
p1.BorderColor = [0.94,0.94,0.94];
tit_ins = settings_.DATA_PATH(max(find(settings_.DATA_PATH=='\'))+1:end-4); 
tit_ins(find(tit_ins=='_'))=' ';
 p1.Title = ['MM for learning set: ', tit_ins];
p1.FontSize = 16*y_mult;
p1.TitlePosition = 'centertop';
p1.FontWeight = 'bold';

for index = 1: LL_+ 1
ax{index} =   subplot(subplot_inds(LL_+ 1,1),subplot_inds(LL_+ 1,2),index, 'Parent', p1);

if index == LL_+ 1
do_the_mode_map(MP_mean,'TEST ',settings_,ax{index},mag_fac)
else    
do_the_mode_map(Block_DATA.mean_tag_modes_{index},Block_DATA.Labels_{index},settings_,ax{index},length(find(Block_DATA.tag_label_index == index)),mag_fac)
end
end %for index = 1: LL_


end %function   display_tag_mode_maps(Block_DATA)


function do_the_mode_map(slice_data,label,settings_, ax2,no_tests,mag_fac)
Pix_SS = get(0,'screensize')              ;
x_mult = (Pix_SS(3)/1920) ;
y_mult = (Pix_SS(4)/1080) ;
grid_size_to_plot = settings_.MM_interp_res   ;

db_range          = settings_.db_range        ;
if grid_size_to_plot > 4
    x = linspace(1,size(slice_data,1),grid_size_to_plot);
    y = linspace(1,size(slice_data,2),grid_size_to_plot);
    [xi, yi] = meshgrid(x, y);
    interp_data = interp2([1:size(slice_data,1)],[1:size(slice_data,2)],slice_data,xi,yi);
else
    interp_data = slice_data;
end %if grid_size_to_plot > length(options.modes)

interp_data = [interp_data; zeros(1, size(interp_data, 2)) ]       ;
interp_data = [interp_data, zeros(size(interp_data,1), 1)  ]       ;

sf_plotH =surf(ax2,interp_data);
sf_plotH.EdgeColor = 'none';
ax2.View = [0 90];
ax2.Visible = 'off';
ax2.CLim = [0, db_range];
ax2.DataAspectRatio = [1 1 1];
sf = grid_size_to_plot / 4;
    offset = grid_size_to_plot / grid_size_to_plot;
modes_temp = [1,2,3,4];

for ii = 1:4
    a = text(ax2,(ii - 0.5) * sf + 1, - offset + 1, sprintf('%i',modes_temp(ii)));
    set(a, 'HorizontalAlignment', 'center');
    set(a, 'VerticalAlignment', 'top');

    a = text(ax2,-offset + 1, (ii - 0.5) * sf + 1, sprintf('%i',modes_temp(ii)));
    set(a, 'HorizontalAlignment', 'right');
    set(a, 'VerticalAlignment', 'middle');
end % for ii = 1:length(options.modes)
a.FontSize = 12*y_mult;

ax2.Title.String = [label,', (',num2str(no_tests),')'];
ax2.Title.FontSize = 12*y_mult;
ax2.Title.Visible = 'on';
ax2.Title.Position = [28*x_mult,53*y_mult,30*y_mult];



end %function do_the_mode_map(map,label,sb_handle)

function  Block_DATA  =  add_means_and_std_of_tags_to_Block_DATA(Block_DATA,LS_crack_mode_matrices)

for index = 1:length(Block_DATA.Labels_)
tag_indicies                   = find(Block_DATA.tag_label_index == index);
tag_modes_ =   LS_crack_mode_matrices(:,:,tag_indicies);
mean_temp = mean(tag_modes_ , 3) ;
mean_tag_modes_{index}         = mean_temp;
std_temp = std(tag_modes_,0,3)  ;
std_tag_modes_{index}          = std_temp;
end %for index = 1:length(Labels_)
Block_DATA.mean_tag_modes_ = mean_tag_modes_;
Block_DATA.std_tag_modes_  = std_tag_modes_;
end %function  Block_DATA  =  add_means_and_std_of_tags_to_Block_DATA(Block_DATA,labels,LS_crack_mode_matrices)

function AI_Block  = Create_AI_learning_Block(NumNeighbors_,mode_pairs_to_Use, all_modes,Labels_,tag_label_index)
mode_block_2d = reshape(all_modes,16,length(all_modes))';
Data_mat = mode_block_2d(:,mode_pairs_to_Use);
tags_ = Labels_(tag_label_index)';
AI_Block = fitcknn(Data_mat,tags_,"Standardize",true,'NumNeighbors',NumNeighbors_ ,'Distance','cityblock');
end %function AI_Block  = Create_AI_learning_Block()

function crack_mode_matrix = create_crack_mode_matrices (crack_mode_,Thresh_index, slice_ind)

crack_mode_matrix = zeros(4,4,length(crack_mode_));

for index = 1:length(crack_mode_)
dum = crack_mode_{index}{Thresh_index}(:,:,slice_ind);
crack_mode_matrix(:,:,index) = mean(dum,3);
end %for index = 1:length(crack_mode_)

end %function crack_mode_matrix = create_crack_mode_matrix(Block_DATA.crack_mode_,Thresh_index, slice_indices);

function raw_mode_map_viewer(grid_data,mod_val,MM_interp_res,db_range,x_mult,y_mult,mag_fac)
warning off

fig = uifigure('Resize','off','Units','normalized','Position', [ 0.05 , 0.05 , 0.29 * mag_fac , 0.435 * mag_fac ],'Name', 'Mode Pair Comparitor','AutoResizeChildren','off');
fig.Icon = 'ICON2.png';
px_LH = 60; py_LH = 60; px_SZ = 490; py_SZ = 410;
p1 = uipanel(fig,'Position',[x_mult*px_LH y_mult*py_LH x_mult*px_SZ y_mult*py_SZ],'AutoResizeChildren','off');

%p1.BorderColor = [1,1,1];
p1.BorderWidth = 0;
ax1 = subplot(8,6,1:6, 'Parent', p1);
ax2 = subplot(8,6,[14,15,16,17,20,21,22,23,26,27,28,29,32,33,34,35,38,39,40,41,44,45,46,47], 'Parent', p1);
plot_data_structure.dv = grid_data.distance_vector;
plot_data_structure.mod_val = mod_val;
plot_data_structure.mod_val_variable = mod_val;
plot_data_structure.mm_33  = squeeze(grid_data.data_stack(3,3,:));
plot_data_structure.data_stack= grid_data.data_stack;
plot_data_structure.MM_interp_res = MM_interp_res;
plot_data_structure.db_range = db_range;
plot_data_structure.fig = fig;
plot_data_structure.ax1  =  ax1;
plot_data_structure.ax2  =  ax2; 
plot_data_structure.XL1  =  -0.1;
plot_data_structure.XL2  =   1.1;
%--------------------------------------------
v_temp = plot_data_structure.dv(plot_data_structure.mod_val);

sld  =  uislider(fig, 'Limits',[-0.1  1.1],'Position',[x_mult*35 y_mult*40 x_mult*400 y_mult*10],'Value', v_temp,'ValueChangingFcn', @(src,event)change_MM_dist(src,event),'MajorTicks', [-0.1:0.1:1.1],'MinorTicks', [] ); 
sld.FontSize = 12*y_mult;

txa = uitextarea(fig,'Position',[x_mult*460 y_mult*20 x_mult*70 y_mult*20], 'Value', [num2str(round(v_temp*1000)),' mm.']);

txa.FontSize=12*y_mult;
btn = uibutton(fig,'Position',[x_mult*5,y_mult*80,x_mult*50,y_mult*40],'Text','Reset','ButtonPushedFcn',@reset_MM_plot);

btn.FontSize=12*y_mult;
btn2 = uibutton(fig,'Position',[x_mult*5,y_mult*120,x_mult*50,y_mult*40],'Text','Update','ButtonPushedFcn',@update_MM_plot);
btn2.FontSize=12*y_mult;
plot_data_structure.sld = sld ;
plot_data_structure.txa = txa ;
plot_data_structure.btn = btn ; 
plot_data_structure.btn2 = btn2 ; 

fig.UserData = plot_data_structure ;
update_top_plot(plot_data_structure)    ;
update_bottom_plot(plot_data_structure) ;
end %function raw_mode_map_viewer(grid_data )


function update_top_plot(plot_data_structure)
XL1 = plot_data_structure.XL1 ; 
XL2 = plot_data_structure.XL2 ;

Pix_SS = get(0,'screensize');
%x_mult = Pix_SS(3)/1920;
y_mult = Pix_SS(4)/1080;

dv               = plot_data_structure.dv              ;
mod_val          = plot_data_structure.mod_val         ;
mod_val_variable = plot_data_structure.mod_val_variable;
mm_33            = plot_data_structure.mm_33           ;
ax1              = plot_data_structure.ax1             ;
hold(ax1,'off')
plot(ax1 , dv ,mm_33)
hold(ax1,'on')
plot(ax1,[dv(mod_val) dv(mod_val)] ,[ax1.YLim(1) ax1.YLim(2)],'k')
plot(ax1,[dv(mod_val_variable) dv(mod_val_variable)] ,[ax1.YLim(1) ax1.YLim(2)],'r')
leg_ = legend(ax1,{'M3-3','MM','MM view'});
ax1.XLabel.String = 'Distance(m)';
ax1.XLabel.FontSize = y_mult*10;
ax1.Title.String = 'Mode 3-3 ';
ax1.Title.FontSize = y_mult*11;
ax1.XLim =[XL1, XL2 ]       ;
leg_ = legend(ax1,{'M3-3','MM','MM view'})   ;
leg_.Location = 'westoutside';
leg_.FontSize= 7*y_mult;
end %function update_top_plot(plot_data_structure)


function update_bottom_plot(plot_data_structure)
Pix_SS = get(0,'screensize');
x_mult = Pix_SS(3)/1920;
y_mult = Pix_SS(4)/1080;

dv                    = plot_data_structure.dv              ;
mod_val_variable      = plot_data_structure.mod_val_variable;
data_stack            = plot_data_structure.data_stack      ;
grid_size_to_plot     = plot_data_structure.MM_interp_res   ;
db_range              = plot_data_structure.db_range        ;
ax2                   = plot_data_structure.ax2             ;
slice_data = data_stack(:,:,mod_val_variable);
slice_data = slice_data/mean(mean(slice_data));

if grid_size_to_plot > 4
    x = linspace(1,size(slice_data,1),grid_size_to_plot);
    y = linspace(1,size(slice_data,2),grid_size_to_plot);
    [xi, yi] = meshgrid(x, y);
    interp_data = interp2([1:size(slice_data,1)],[1:size(slice_data,2)],slice_data,xi,yi);
else
    interp_data = slice_data;

end %if grid_size_to_plot > length(options.modes)

interp_data = [interp_data; zeros(1, size(interp_data, 2)) ]       ;
interp_data = [interp_data, zeros(size(interp_data,1), 1)  ]       ;

sf_plotH =surf(ax2,interp_data);
sf_plotH.EdgeColor = 'none';
ax2.View = [0 90];
ax2.Visible = 'off';
ax2.CLim = [0, db_range];
ax2.DataAspectRatio = [1 1 1];

sf = grid_size_to_plot / 4;
    offset = grid_size_to_plot / grid_size_to_plot;
modes_temp = [1,2,3,4];

for ii = 1:4
    a = text(ax2,(ii - 0.5) * sf + 1, - offset + 1, sprintf('%i',modes_temp(ii)));
    set(a, 'HorizontalAlignment', 'center');
    set(a, 'VerticalAlignment', 'top');

    a = text(ax2,-offset + 1, (ii - 0.5) * sf + 1, sprintf('%i',modes_temp(ii)));
    set(a, 'HorizontalAlignment', 'right');
    set(a, 'VerticalAlignment', 'middle');
end % for ii = 1:length(options.modes)
a.FontSize = 12*y_mult;

end %function update_bottom_plot(plot_data_structure)


function update_MM_plot(hObject, ~)
plot_data_structure  =  get(get(hObject,'Parent'),'UserData');
update_top_plot(plot_data_structure)    ;
update_bottom_plot(plot_data_structure) ;
end

function reset_MM_plot(hObject, ~)
plot_data_structure  =  get(get(hObject,'Parent'),'UserData');
plot_data_structure.mod_val_variable = plot_data_structure.mod_val;
update_top_plot(plot_data_structure)    ;
update_bottom_plot(plot_data_structure) ;
plot_data_structure.sld.Value = plot_data_structure.dv(plot_data_structure.mod_val);
set(get(hObject,'Parent'),'UserData',plot_data_structure);
end


function change_MM_dist(src,event)
new_value =  event.Value;
plot_data_structure  =  get(get(src,'Parent'),'UserData');
plot_data_structure.txa.Value = [num2str(round(new_value*1000)),' mm.'];
[~ ,plot_data_structure.mod_val_variable]  =  min(abs(  plot_data_structure.dv - new_value));
set(get(src,'Parent'),'UserData',plot_data_structure);
end %function change_MM_dist(src,event)

%-----------------------------------------------------------------------------

function Plot_mean_and_std_of_MM (MP_mean,MP_std,mode_pairs_to_Use,file_name,labels,x_mult,y_mult,mag_fac )

fig = uifigure('Resize','off','Units','normalized','Position',[0.05,0.05,0.29*mag_fac,0.435*mag_fac],'Name', 'Mean and Std Mode Pairs');
fig.Icon = 'ICON2.png';
px_LH = 50; py_LH = 0; px_SZ = 550; py_SZ = 470;
ax_LH = 10; ay_LH = 40; ax_SZ = 450; ay_SZ = 390;

p1 = uipanel(fig,'Position',[x_mult*px_LH y_mult*py_LH x_mult*px_SZ y_mult*py_SZ]);
p1.BorderColor = [0.94,0.94,0.94];
ax = uiaxes(p1,'Position',[x_mult*ax_LH y_mult*ay_LH x_mult*ax_SZ y_mult*ay_SZ]);
ax.Box    = 'on' ;


std_bar_size = 1;
val_nos_tmp = 1:16;
spec_vals_means = reshape(MP_mean, 1 , numel(MP_mean));
spec_vals_std = reshape(MP_std, 1 , numel(MP_std));
file_name(find(file_name =='_')) = ' ';
xBlanks = zeros(1, length(mode_pairs_to_Use));

ax.XTick = 1: 16;
ax.XLim  = [0,17]; 
ax.XTickLabel = labels;


hold(ax,'on')
errorbar(ax,val_nos_tmp,spec_vals_means,spec_vals_std*std_bar_size,':o')
errorbar(ax,mode_pairs_to_Use,spec_vals_means(mode_pairs_to_Use),spec_vals_std(mode_pairs_to_Use)*std_bar_size,'rs','markersize',15)
ax.Title.String = ['Prediction modes vals: ',file_name(1:end-4)];
ax.Title.FontSize = y_mult*14;
leg_ =legend(ax,{'All Modes','Prediction Modes'});
leg_.FontSize = y_mult*10;



%{
std_bar_size = 1;
val_nos_tmp = 1:16;
spec_vals_means = reshape(MP_mean, 1 , numel(MP_mean));
spec_vals_std = reshape(MP_std, 1 , numel(MP_std));
file_name(find(file_name =='_')) = ' ';
xBlanks = zeros(1, length(mode_pairs_to_Use));
axes('XTick', 1: 16, 'XLim', [0,17], 'XTickLabel', labels);
%axes('XTick', 1: length(mode_pairs_to_Use), 'XLim', [0,length(mode_pairs_to_Use)+1 ], 'XTickLabel', labels(mode_pairs_to_Use));

hold on

errorbar(val_nos_tmp,spec_vals_means,spec_vals_std*std_bar_size,':o')
errorbar(mode_pairs_to_Use,spec_vals_means(mode_pairs_to_Use),spec_vals_std(mode_pairs_to_Use)*std_bar_size,'rs','markersize',15)
legend('All Modes','Prediction Modes')
title(['Prediction modes vals: ',file_name(1:end-4)])
%}

end %function Plot_mean_and_std_of_MM (MP_mean,MP_std,settings_.mode_pairs_to_Use )


function Plot_single_mode_map(slice_data,grid_size_to_plot,db_range,filename_ , grid_data,x_mult,y_mult,mag_fac )
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



fig = uifigure('Resize','off','Units','normalized','Position',[0.05,0.05,0.25*mag_fac,0.4*mag_fac],'Name', 'Mode Map');
fig.Icon = 'ICON2.png';
px_LH = 00; py_LH = 0; px_SZ = 470; py_SZ = 470;
ax_LH = 0; ay_LH = 20; ax_SZ = 450; ay_SZ = 390;
p1 = uipanel(fig,'Position',[x_mult*px_LH y_mult*py_LH x_mult*px_SZ y_mult*py_SZ]);
p1.BorderColor = [1,1,1];
ax = uiaxes(p1,'Position',[x_mult*ax_LH y_mult*ay_LH x_mult*ax_SZ y_mult*ay_SZ]);
ax.Box    = 'on' ;

interp_data = [interp_data; zeros(1, size(interp_data, 2)) ] ;
interp_data = [interp_data, zeros(size(interp_data,1), 1)  ] ;
sf_plotH =surf(ax,interp_data);
sf_plotH.EdgeColor = 'none';
ax.View = [0 90];
ax.Visible = 'off';
ax.CLim = [0, db_range];
ax.DataAspectRatio = [1 1 1];
filename_ = remove_(filename_);
ax.Title.String = ['MM: ',filename_ '.'];
ax.Title.FontSize = 15*y_mult;
ax.Title.Visible = 'on';

sf = grid_size_to_plot / 4;
    offset = grid_size_to_plot / grid_size_to_plot;
modes_temp = [1,2,3,4];

for ii = 1:4
    a = text(ax,(ii - 0.5) * sf + 1, - offset + 1, sprintf('%i',modes_temp(ii)));
    set(a, 'HorizontalAlignment', 'center');
    set(a, 'VerticalAlignment', 'top');

    a = text(ax,-offset + 1, (ii - 0.5) * sf + 1, sprintf('%i',modes_temp(ii)));
    set(a, 'HorizontalAlignment', 'right');
    set(a, 'VerticalAlignment', 'middle');
end % for ii = 1:length(options.modes)
a.FontSize = 12*y_mult;

 cb = colorbar(ax);
 cb.Position= [0.86,0.11,0.04,0.7];
 cb.FontSize = 8*y_mult;
  %ax.XLabel.String = 'Mode #';
  %ax.YLabel.String = 'Mode #';

end %function Plot_single_mode_map(MP_mean)

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

function plot_mode_pairs(mod_val, grid_data,labels_,mod_val_inds,x_mult,y_mult,mag_fac) 
mode_map                   = grid_data.data_stack                   ;

label1_ind = 1;
label2_ind = 11;

fig = uifigure('Resize','off','Units','normalized','Position',[0.05,0.05,0.29*mag_fac,0.435*mag_fac],'Name', 'Mode Pair Comparitor' );

fig.Icon = 'ICON2.png';
px_LH = 80; py_LH = 0; px_SZ = 470; py_SZ = 470;
ax_LH = 10; ay_LH = 40; ax_SZ = 450; ay_SZ = 390;

p1 = uipanel(fig,'Position',[x_mult*px_LH y_mult*py_LH x_mult*px_SZ y_mult*py_SZ]);

p1.BorderColor = [0.9400,0.9400,0.9400];
ax = uiaxes(p1,'Position',[x_mult*ax_LH y_mult*ay_LH x_mult*ax_SZ y_mult*ay_SZ]);
ax.Box    = 'on' ;

DD_1 = uidropdown(fig,"Items",labels_,'Position', [x_mult*0 y_mult*100 x_mult*70 y_mult*40],'FontSize',y_mult*16,'Value',labels_{label1_ind},'ValueChangedFcn',@change_MP1);
DD_2 = uidropdown(fig,"Items",labels_,'Position', [x_mult*0 y_mult*50 x_mult*70 y_mult*40],'FontSize',y_mult*16,'Value',labels_{label2_ind},'ValueChangedFcn',@change_MP2);

plot_data_structure.label1_ind                  = label1_ind;                    
plot_data_structure.label2_ind                  = label2_ind;                    
plot_data_structure.labels_                     = labels_;   
plot_data_structure.p1                          = p1;
plot_data_structure.ax                          = ax; 
plot_data_structure.mode_map                    = mode_map                               ;
plot_data_structure.fig                         = fig                                  ;
plot_data_structure.Row_ind1                    = 1                                     ;
plot_data_structure.Col_ind1                    = 1                                     ;
plot_data_structure.Row_ind2                    = 3                                     ;
plot_data_structure.Col_ind2                    = 3                                     ;
plot_data_structure.dv                          = grid_data.distance_vector              ;  
plot_data_structure.mm_33                       = squeeze(mode_map(3,3,:))               ;
plot_data_structure.mod_val                     = mod_val                                ; 
plot_data_structure.mod_val_inds                = mod_val_inds                          ;  
fig.UserData = plot_data_structure;
update_mode_plot(plot_data_structure);
end %function plot_mode_pairs(  ) 


function change_MP1(hObject, ~)
new_value =  get(hObject,'Value');
plot_data_structure  =  get(get(hObject,'Parent'),'UserData');
new_value_index = find(ismember(plot_data_structure.labels_,new_value)==1);
plot_data_structure.label1_ind  = new_value_index;
plot_data_structure.Row_ind1 = plot_data_structure.mod_val_inds(new_value_index,1);
plot_data_structure.Col_ind1 = plot_data_structure.mod_val_inds(new_value_index,2);
update_mode_plot(plot_data_structure)  
set(get(hObject,'Parent'),'UserData',plot_data_structure);
end %function change_row(hObject, ~)

function change_MP2(hObject, ~)
new_value =  get(hObject,'Value');
plot_data_structure  =  get(get(hObject,'Parent'),'UserData');
new_value_index = find(ismember(plot_data_structure.labels_,new_value)==1);
plot_data_structure.label2_ind  = new_value_index;
plot_data_structure.Row_ind2 = plot_data_structure.mod_val_inds(new_value_index,1);
plot_data_structure.Col_ind2 = plot_data_structure.mod_val_inds(new_value_index,2);
update_mode_plot(plot_data_structure)  
set(get(hObject,'Parent'),'UserData',plot_data_structure);
end %function change_row(hObject, ~)

function update_mode_plot(plot_data_structure)
Pix_SS = get(0,'screensize');
x_mult = Pix_SS(3)/1920;
y_mult = Pix_SS(4)/1080;
P1            = plot_data_structure.p1            ;  
ax            = plot_data_structure.ax            ;
mode_map      = plot_data_structure.mode_map      ;
%fig           = plot_data_structure.fig          ;
Row_ind1      = plot_data_structure.Row_ind1      ;
Col_ind1      = plot_data_structure.Col_ind1      ;
Row_ind2      = plot_data_structure.Row_ind2      ;
Col_ind2      = plot_data_structure.Col_ind2      ;
dv            = plot_data_structure.dv            ;  
mm_33         = plot_data_structure.mm_33         ;
mod_val       = plot_data_structure.mod_val       ; 
label1_ind    = plot_data_structure.label1_ind    ;
label2_ind    = plot_data_structure.label2_ind    ;
labels_       = plot_data_structure.labels_       ;



%figure(fig_H)

mm_temp1  = squeeze(mode_map(Row_ind1,Col_ind1,:)); 
mm_temp2  = squeeze(mode_map(Row_ind2,Col_ind2,:)); 
hold(ax,'off')
plot(ax,dv,mm_temp1,'k')
hold(ax,'on')
plot(ax,dv,mm_temp2,'r:')
ylim_ =ax.YLim;
plot(ax,[dv(mod_val) dv(mod_val)],[ylim_(1) ylim_(2)])
ax.Title.String = ['Full range plots (Mod ',num2str(Row_ind1),'-',num2str(Col_ind1),' Mod ',num2str(Row_ind2),'-',num2str(Col_ind2),')'];
ax.Title.FontSize = 22*y_mult;
ax.XLabel.String = 'Distance (m)';
ax.XLabel.FontSize = y_mult*14;
leg_ =legend(ax,{labels_{label1_ind},labels_{label2_ind}});
leg_.FontSize = y_mult*12;
end %function update_mode_plot(plot_data_structure)

function  [mod_val,lower_val,upper_val,actual_peak_val]  =  get_peak_vals_and_plot(grid_data,settings_ , do_plot,x_mult,y_mult,mag_fac)
%--------------------------------------------------------------------------------------------
% function [mod_val  , lower_val  ,  upper_val  ,  actual_peak_val]  =  get_peak_values( )
%--------------------------------------------------------------------------------------------
initial_thresh = settings_.initial_thresh                 ;
thresh_val     = settings_.thresh_val                     ;
num_slices     = settings_.num_slices                     ;
window_start   = settings_.window_start                   ;    
mode_map             = grid_data.data_stack               ;
mm33                 = squeeze(mode_map(3,3,:))           ;
dv                   = grid_data.distance_vector          ;  
start_val       =   min(find(dv>window_start)) + min(find(mm33(find(dv>window_start))  >   max(mm33(find(dv>window_start)))*initial_thresh))-1;

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

function  [Slice_index,Thresh_index]  = get_index_value (settings_,Block_DATA,slice_options)
Slice_index  =   find(slice_options ==  settings_. num_slices);
Thresh_index =  find(Block_DATA.threshold_value == settings_.thresh_val);
end  % function  [Slice_index,Thresh_index]  = get_index_value (settings_,Block_DATA,slice_options)

function [slice_options ,  slice_indices] = get_slice_options(max_number_of_slices)
slice_options = [1:2:max_number_of_slices];
central_val = ceil(max_number_of_slices/2);
for index = 1: length(slice_options)
amount_to_PM = floor(slice_options(index)/2);
slice_indices{index} =  [(central_val-amount_to_PM): (central_val+amount_to_PM)];
end %for index = 1: length(slice_options)
%slice_indices
end %function slice_options = get_slice_options(Block_DATA.max_number_of_slices);


