function plot_Options_updated = set_plot_options_BASICU(varargin) 

switch(nargin)
    case(0)
FD_settings_path =  [pwd,'\SETTINGS_FILES\plot_options2.mat']                   ; 
Settings_path    =  [getenv('APPDATA'),'\SETTINGS_FILES\plot_options2.mat']     ;
[plot_options , ~ ] = load_mat_structure_from_file(Settings_path)               ;
    
    
    case(6)
FD_settings_path  =  varargin{2}; 
Settings_path     =  varargin{3};
plot_options       = varargin{1};

base_width = varargin{4};
base_height = varargin{5};
mag_fac   = varargin{6};

Pix_SS = get(0,'screensize')                ;
x_mult = (Pix_SS(3)/base_width)   * mag_fac ;
y_mult = (Pix_SS(4)/base_height)  * mag_fac ;
           

%x_mult,y_mult,mag_fac

end % switch(nargin)

[Options_,Defaults] = get_options_Defaults(plot_options);
[fig] = bespoke_dialog_box2(Options_,Defaults,FD_settings_path,Settings_path,x_mult,y_mult,mag_fac);
plot_Options_updated = get_Plot_Options_essential(fig,plot_options);

if isstruct(plot_Options_updated)
% OK_ =   create_file_from_structure(plot_Options_updated,Settings_path);
OK_ =  save_mat_structure_to_file(plot_Options_updated,Settings_path); 

if ~OK_
    msgbox('problem saving')    
end %if ~OK_
end

end  % function plot_options = set_plot_options(varargin) 

function plot_Options_updated = get_Plot_Options_essential(fig,plot_options)

fig.UserData.S_button_pressed  = 0;
Save_Btn_pressed  = 0;

while Save_Btn_pressed == 0
drawnow()
if isvalid(fig)
Save_Btn_pressed = fig.UserData.S_button_pressed;
else
 plot_Options_updated = []; 
return
end % if isvalid(fig)
end % while Save_Btn_pressed == 0

%  updat the values in he structure then save
plot_Options_updated = update_plot_options(fig,plot_options);
close (fig)

end %function plot_Options_updated = get_Plot_Options_essential(fig,plot_options);


function plot_options = update_plot_options(fig,plot_options )

%new_vals_.DPath_ind  = find(ismember(fig.UserData.inps.DD_1.Items,  fig.UserData.inps.DD_1.Value));

new_vals_.IniStart_ind = find(ismember(fig.UserData.inps.DD_6.Items,  fig.UserData.inps.DD_6.Value));
new_vals_.WinStart_ind = find(ismember(fig.UserData.inps.DD_10.Items,  fig.UserData.inps.DD_10.Value));

%plot_options.Data_path_choice     = new_vals_.DPath_ind       ;
plot_options.initial_thresh_index = new_vals_.IniStart_ind    ;
plot_options.window_start_index   = new_vals_.WinStart_ind    ;

end %function plot_options_updated = update_plot_options(new_vals,plot_options )

function [Options_,Defaults] = get_options_Defaults(dum)

%Options_.sample_rate_ = cellfun(@num2str, num2cell(dum.Sample_Rate_options) , 'UniformOutput', false)' ;


Options_.DPath                 = dum.Data_path_options;
Options_.MPair                 = dum.mode_pairs_to_Use_options;
%Options_.MPair = cellfun(@num2str, num2cell(dum.mode_pairs_to_Use_options) , 'UniformOutput', false)' ;

%Options_.NNeib                 = dum.NumNeighbors_options;
Options_.NNeib = cellfun(@num2str, num2cell(dum.NumNeighbors_options) , 'UniformOutput', false)' ;

%----------------------------------------------------------------------------

%Options_.NSlice                = dum.num_slices_options;
Options_.NSlice = cellfun(@num2str, num2cell(dum.num_slices_options) , 'UniformOutput', false)' ;

%Options_.ThreshV               = dum.thresh_val_options;
Options_.ThreshV = cellfun(@num2str, num2cell(dum.thresh_val_options) , 'UniformOutput', false)' ;

%Options_.IniStart              = dum.initial_thresh_options;
Options_.IniStart = cellfun(@num2str, num2cell(dum.initial_thresh_options) , 'UniformOutput', false)' ;

%----------------------------------------------------------------------------
Options_.AI_pred = dum.AI_pred_options;
Options_.DM_pred = dum.DM_pred_options;
Options_.LL_pred = dum.LL_pred_options;

%----------------------------------------------------------------------------
Options_.WinStart = cellfun(@num2str, num2cell(dum.window_start_options) , 'UniformOutput', false)' ;
%Options_.Pred2use              = dum.predictions2use_options;
%Options_.Pred2use = cellfun(@num2str, num2cell(dum.predictions2use_options) , 'UniformOutput', false)' ;

Defaults.DPath_ind             = dum.Data_path_choice     ;
Defaults.MPair_ind             = dum.mode_pairs_to_Use    ;
Defaults.NNeib_ind             = dum.NumNeighbors         ;
Defaults.NSlice_ind            = dum.num_slices_index     ;
Defaults.ThreshV_ind           = dum.thresh_val_index     ;
Defaults.IniStart_ind          = dum.initial_thresh_index ;
Defaults.WinStart_ind          = dum.window_start_index   ;
Defaults.AI_pred_ind           = dum.AI_pred_choice       ;
Defaults.DM_pred_ind           = dum.DM_pred_choice       ; 
Defaults.LL_pred_ind           = dum.LL_pred_choice       ;  

% Defaults.Pred2use_ind          = dum.predictions2use      ;

end % function [Options_,Defaults] = get_options_Defaults(snr_settings)

function [fig] = bespoke_dialog_box2(Options_,Defaults,FD_settings_path,Settings_path,x_mult,y_mult,mag_fac)

fig = uifigure('Resize','off','Units','normalized','Position',[0.1000 0.100 0.2000*mag_fac 0.1200*mag_fac],'Name', 'Plot Options' );
fig.Icon = 'ICON2.png';
fig.UserData.S_button_pressed = 0;



%fig.UserData.inps.DD_1 = uidropdown(fig,"Items",[Options_.DPath],'Position', [x_mult*10,y_mult*130,x_mult*350,y_mult*28],'FontSize',y_mult*18,'Value',Options_.DPath{Defaults.DPath_ind});
%lbl = uilabel(fig,'Position',[x_mult*10,y_mult*165,x_mult*350,y_mult*28],'Text', 'Learning Set','FontSize',y_mult*18)                             ;

fig.UserData.inps.DD_6 = uidropdown(fig,"Items",[Options_.IniStart ],'Position', [x_mult*35 y_mult*75 x_mult*100 y_mult*28],'FontSize',y_mult*18,'Value',Options_.IniStart{Defaults.IniStart_ind})   ;
lbl6 = uilabel(fig,'Position',[x_mult*35 y_mult*100 x_mult*100 y_mult*28],'Text', 'Initial thresh','FontSize',y_mult*18)                        ;

fig.UserData.inps.DD_10 = uidropdown(fig,"Items",[Options_.WinStart ],'Position', [x_mult*215 y_mult*75 x_mult*100 y_mult*28],'FontSize',y_mult*18,'Value',Options_.WinStart{Defaults.WinStart_ind})   ;
lbl10 = uilabel(fig,'Position',[x_mult*215 y_mult*100 x_mult*100 y_mult*28],'Text', 'Win Start','FontSize',y_mult*18);  


but1 = uibutton(fig,"push" ,"Text","Reload FDs",'Position',[x_mult*5,y_mult*10,x_mult*120,y_mult*55],'FontSize',y_mult*18,"ButtonPushedFcn", @(src,event)FD_ButtonPushed(fig,FD_settings_path))   ;
but2 = uibutton(fig,"push" ,"Text","Reload Defs",'Position',[x_mult*132,y_mult*10,x_mult*120,y_mult*55],'FontSize',y_mult*18,"ButtonPushedFcn", @(src,event)RD_ButtonPushed(fig,Settings_path))   ;
but3 = uibutton(fig,"push" ,"Text","Save/Exit",'Position',[x_mult*260,y_mult*10,x_mult*120,y_mult*55],'FontSize',y_mult*18,"ButtonPushedFcn", @(src,event)S_ButtonPushed(fig))   ;

end %function [fig] = bespoke_dialog_box2(Options_,Defaults,FD_settings_path,Settings_path);

function FD_ButtonPushed(fig,FD_settings_path)
%disp('load the factory defaults')
%[plot_options_default , ~ ] = load_structure_from_file    (FD_settings_path);
 [plot_options_default , ~ ] = load_mat_structure_from_file(FD_settings_path);

[Options_,Defaults] = get_options_Defaults(plot_options_default);

reset_the_dropdowns(fig , Options_ , Defaults)
end %function Button1Pushed(fig)

function RD_ButtonPushed(fig,Settings_path)
%load the defaults data
%[plot_options_default , ~ ] =    load_structure_from_file(Settings_path);
[plot_options_default , ~ ] = load_mat_structure_from_file(Settings_path);

[Options_,Defaults] = get_options_Defaults(plot_options_default);
reset_the_dropdowns(fig , Options_ , Defaults)
end %function Button1Pushed(fig)

function S_ButtonPushed(fig)
%  Save the data in the structure  
%
fig.UserData.S_button_pressed = 1;
%disp('save the test settings structure' )
end %function Button1Pushed(fig)

function reset_the_dropdowns(fig , Options_ , Defaults)

%fig.UserData.inps.DD_1.Value = Options_.DPath{Defaults.DPath_ind};
fig.UserData.inps.DD_6.Value = Options_.IniStart{Defaults.IniStart_ind} ;
fig.UserData.inps.DD_10.Value = Options_.WinStart{Defaults.WinStart_ind} ;

end %function reset_the_dropdowns(fig , Options_ , Defaults)