function SNR_Settings = set_SNR_settings(varargin) 


%app.base_width,app.base_height,app.mag_fac  

switch(nargin)
    case(0) 
FD_settings_path      =    [pwd,'\SETTINGS_FILES\snr_settings2.mat']; 
Settings_path         =    [getenv('APPDATA'),'\SETTINGS_FILES\snr_settings2.mat'];
[snr_settings , ~]    =    load_mat_structure_from_file(Settings_path);  
Pix_SS = get(0,'screensize')              ;


mag_fac                   =  1.9531               ;
base_width                = 1920                  ; 
base_height               = 1080                  ; 
x_mult = (Pix_SS(3)/base_width)   * mag_fac       ;
y_mult = (Pix_SS(4)/base_height)  * mag_fac       ;

    case(3) 
snr_settings = varargin{1};
FD_settings_path = varargin{2};
Settings_path    = varargin{3};

mag_fac                   =  1.9531               ;
base_width                = 1920                  ; 
base_height               = 1080                  ; 
Pix_SS = get(0,'screensize')                      ;
x_mult = (Pix_SS(3)/base_width)   * mag_fac       ;
y_mult = (Pix_SS(4)/base_height)  * mag_fac       ;

    case(6)
snr_settings = varargin{1};
FD_settings_path = varargin{2};
Settings_path    = varargin{3};
base_width = varargin{4};
base_height = varargin{5};
mag_fac   = varargin{6};

Pix_SS = get(0,'screensize')                ;
x_mult = (Pix_SS(3)/base_width)   * mag_fac ;
y_mult = (Pix_SS(4)/base_height)  * mag_fac ;
end % switch(nargin)

[Options_,Defaults] = get_options_Defaults(snr_settings);


[fig] = bespoke_dialog_box2(Options_,Defaults,FD_settings_path,Settings_path,x_mult,y_mult,mag_fac);

SNR_Settings = get_snr_settings_updated(fig , snr_settings);

if isstruct(SNR_Settings)

%OK_ =   create_file_from_structure(SNR_Settings,Settings_path);
OK_ =  save_mat_structure_to_file(SNR_Settings,Settings_path);

if ~OK_
msgbox('problem saving defaults')    
end %if ~OK_
end %if isstruct(SNR_Settings)

end %function SNR_Settings = set_SNR_settings() 

%--------------------------------------------------------------------------------------------
%--------------------------------------------------------------------------------------------

function snr_settings_updated = get_snr_settings_updated(fig,snr_settings)
% make sure it works 1st and then introduce the error checks for the boundaries

fig.UserData.S_button_pressed  = 0;
Save_Btn_pressed  = 0;
no_errors       = 0;

%valid_values      = 0

% fig.UserData.error_message

while no_errors      == 0

while Save_Btn_pressed == 0
drawnow()
if isvalid(fig)
Save_Btn_pressed = fig.UserData.S_button_pressed;
else
snr_settings_updated = []; 
return
end % if isvalid(fig)
end % while Save_Btn_pressed == 0

if isvalid(fig)

if length(fig.UserData.error_message) == 0
no_errors = 1;
else

emsg_ = fig.UserData.error_message                       ; 
emsg_{length(emsg_)+1} = ''                                ;
emsg_{length(emsg_)+1} = 'TRY AGAIN or EXIT?'   ;
answer_ = questdlg(emsg_,'WARNINGS','Try Again','Exit','Try Again');

if strcmp(answer_,'Exit') == 1
no_errors = 2;
else
no_errors = 0;
Save_Btn_pressed = 0;
fig.UserData.S_button_pressed = 0;
end %if strcmp(answer_,'Ignore') == 1
end % if length(fig.UserData.error_message) == 0
end% if isvalid(fig)
end %while no_errors      == 0

if no_errors == 1
new_vals_ = get_values_from_dropdowns(fig);
snr_settings_updated = update_snr_settings(snr_settings , new_vals_);
else
disp('settings not saved')
snr_settings_updated  = [];
end

close (fig)
end %function snr_settings_updated = get_snr_settings_updated(fig,snr_settings)

function new_vals_ = get_values_from_dropdowns(fig)
new_vals_.RMS1_index  = find(ismember(fig.UserData.inps.DD_1.Items       ,  fig.UserData.inps.DD_1.Value));
new_vals_.RMS2_index  = find(ismember(fig.UserData.inps.DD_2.Items       ,  fig.UserData.inps.DD_2.Value));
new_vals_.RMS3_index  = find(ismember(fig.UserData.inps.DD_3.Items       ,  fig.UserData.inps.DD_3.Value));

new_vals_.SNR1_index  = find(ismember(fig.UserData.inps.DD_4.Items       ,  fig.UserData.inps.DD_4.Value));
new_vals_.SNR2_index  = find(ismember(fig.UserData.inps.DD_5.Items       ,  fig.UserData.inps.DD_5.Value));
new_vals_.SNR3_index  = find(ismember(fig.UserData.inps.DD_6.Items       ,  fig.UserData.inps.DD_6.Value));

new_vals_.LFN_1_index  = find(ismember(fig.UserData.inps.DD_7.Items      ,  fig.UserData.inps.DD_7.Value));
new_vals_.LFN_2_index  = find(ismember(fig.UserData.inps.DD_8.Items      ,  fig.UserData.inps.DD_8.Value));
new_vals_.LFN_3_index  = find(ismember(fig.UserData.inps.DD_9.Items      ,  fig.UserData.inps.DD_9.Value));

new_vals_.HFN_1_index  = find(ismember(fig.UserData.inps.DD_10.Items     ,  fig.UserData.inps.DD_10.Value));
new_vals_.HFN_2_index  = find(ismember(fig.UserData.inps.DD_11.Items     ,  fig.UserData.inps.DD_11.Value));
new_vals_.HFN_3_index  = find(ismember(fig.UserData.inps.DD_12.Items     ,  fig.UserData.inps.DD_12.Value));

new_vals_.Exit_freq_index   = find(ismember(fig.UserData.inps.DD_13.Items ,  fig.UserData.inps.DD_13.Value));
new_vals_.bandwidth_index   = find(ismember(fig.UserData.inps.DD_14.Items ,  fig.UserData.inps.DD_14.Value));

new_vals_.timegate_index    = find(ismember(fig.UserData.inps.DD_15.Items ,  fig.UserData.inps.DD_15.Value));
new_vals_.D_timegate_index  = find(ismember(fig.UserData.inps.DD_16.Items ,  fig.UserData.inps.DD_16.Value));
new_vals_.timegate2_index    = find(ismember(fig.UserData.inps.DD_17.Items ,  fig.UserData.inps.DD_17.Value));
new_vals_.timegate3_index    = find(ismember(fig.UserData.inps.DD_18.Items ,  fig.UserData.inps.DD_18.Value));
end   %function new_vals_ = get_values_from_dropdowns(fig)


function snr_settings = update_snr_settings(snr_settings , new_vals_)

snr_settings.RMS_boundaries =[new_vals_.RMS1_index , new_vals_.RMS2_index  , new_vals_.RMS3_index  ] ;
snr_settings.SNR_boundaries =[new_vals_.SNR1_index , new_vals_.SNR2_index  , new_vals_.SNR3_index  ] ;
snr_settings.LFN_boundaries =[new_vals_.LFN_1_index, new_vals_.LFN_2_index , new_vals_.LFN_3_index ] ;
snr_settings.HFN_boundaries       =[new_vals_.HFN_1_index, new_vals_.HFN_2_index , new_vals_.HFN_3_index    ] ;
snr_settings.exitation_freq_kHz   =new_vals_.Exit_freq_index  ; 
snr_settings.SNR_bandwidth_kHz    =new_vals_.bandwidth_index  ;
snr_settings.time_gate            =new_vals_.timegate_index   ;
snr_settings.time_gate2           =new_vals_.timegate2_index   ;
snr_settings.time_gate3           =new_vals_.timegate3_index   ;
snr_settings.diagonal_time_gate   =new_vals_.D_timegate_index ;

end %function snr_settings_updated = update_snr_settings(snr_settings , new_vals_)



function [fig] = bespoke_dialog_box2(Options_,Defaults,FD_settings_path,Settings_path,x_mult,y_mult,mag_fac)
fig = uifigure('Resize','off','Units','normalized','Position',[0.05,0.05,0.25*mag_fac,0.3*mag_fac],'Name', 'SNR Settings' );
fig.Icon = 'ICON2.png';

%----------------------------------------------------------------------------------
% ROW 1
%----------------------------------------------------------------------------------

fig.UserData.inps.DD_1 = uidropdown(fig,"Items",[Options_.RMS],'Position',  [x_mult*9, y_mult*265, x_mult*68, y_mult*28],'FontSize',y_mult*18,'Value',Options_.RMS{Defaults.RMS1_index});
lbl = uilabel(fig,'Position',[x_mult*9, y_mult*290, x_mult*150, y_mult*28],'Text', 'RMS 1','FontSize',y_mult*18)                           ;

fig.UserData.inps.DD_2 = uidropdown(fig,"Items",[Options_.RMS],'Position',  [x_mult*79, y_mult*265, x_mult*68, y_mult*28],'FontSize',y_mult*18,'Value',Options_.RMS{Defaults.RMS2_index});
lbl2 = uilabel(fig,'Position',[x_mult*79, y_mult*290, x_mult*150, y_mult*28],'Text', 'RMS 2','FontSize',y_mult*18)                           ;

fig.UserData.inps.DD_3 = uidropdown(fig,"Items",[Options_.RMS],'Position',  [x_mult*149, y_mult*265, x_mult*68, y_mult*28],'FontSize',y_mult*18,'Value',Options_.RMS{Defaults.RMS3_index});
lbl3 = uilabel(fig,'Position',[x_mult*149, y_mult*290, x_mult*150, y_mult*28],'Text', 'RMS 3','FontSize',y_mult*18)                           ;


fig.UserData.inps.DD_4 = uidropdown(fig,"Items",[Options_.SNR],'Position',  [x_mult*264, y_mult*265, x_mult*68, y_mult*28],'FontSize',y_mult*18,'Value',Options_.SNR{Defaults.SNR1_index});
lbl4 = uilabel(fig,'Position',[x_mult*264, y_mult*290, x_mult*150, y_mult*28],'Text', 'SNR 1','FontSize',y_mult*18)                           ;

fig.UserData.inps.DD_5 = uidropdown(fig,"Items",[Options_.SNR],'Position',  [x_mult*334, y_mult*265, x_mult*68, y_mult*28],'FontSize',y_mult*18,'Value',Options_.SNR{Defaults.SNR2_index});
lbl5 = uilabel(fig,'Position',[x_mult*334, y_mult*290, x_mult*150, y_mult*28],'Text', 'SNR 2','FontSize',y_mult*18)                           ;

fig.UserData.inps.DD_6 = uidropdown(fig,"Items",[Options_.SNR],'Position',  [x_mult*404, y_mult*265, x_mult*68, y_mult*28],'FontSize',y_mult*18,'Value',Options_.SNR{Defaults.SNR3_index});
lbl6 = uilabel(fig,'Position',[x_mult*404, y_mult*290, x_mult*150, y_mult*28],'Text', 'SNR 3','FontSize',y_mult*18)                           ;

% RMS Boundaries (3)defaults
% SNR Boundaries (3)

%----------------------------------------------------------------------------------
%ROW 2
%----------------------------------------------------------------------------------
fig.UserData.inps.DD_7 = uidropdown(fig,"Items",[Options_.LFN],'Position',  [x_mult*9, y_mult*205, x_mult*68, y_mult*28],'FontSize',y_mult*18,'Value',Options_.LFN{Defaults.LFN_1_index});
lbl7 = uilabel(fig,'Position',[x_mult*9, y_mult*230, x_mult*150, y_mult*28],'Text', 'LFN 1','FontSize',y_mult*18)                           ;

fig.UserData.inps.DD_8 = uidropdown(fig,"Items",[Options_.LFN],'Position',  [x_mult*79, y_mult*205, x_mult*68, y_mult*28],'FontSize',y_mult*18,'Value',Options_.LFN{Defaults.LFN_2_index});
lbl8 = uilabel(fig,'Position',[x_mult*79, y_mult*230, x_mult*150, y_mult*28],'Text', 'LFN 2','FontSize',y_mult*18)                           ;

fig.UserData.inps.DD_9 = uidropdown(fig,"Items",[Options_.LFN],'Position',  [x_mult*149, y_mult*205, x_mult*68 y_mult*28],'FontSize',y_mult*18,'Value',Options_.LFN{Defaults.LFN_3_index});
lbl9 = uilabel(fig,'Position',[x_mult*149, y_mult*230, x_mult*150, y_mult*28],'Text', 'LFN 3','FontSize',y_mult*18)                           ;


fig.UserData.inps.DD_10 = uidropdown(fig,"Items",[Options_.HFN],'Position',  [x_mult*264, y_mult*205, x_mult*68, y_mult*28],'FontSize',y_mult*18,'Value',Options_.HFN{Defaults.HFN_1_index});
lbl10 = uilabel(fig,'Position',[x_mult*264, y_mult*230, x_mult*150, y_mult*28],'Text', 'HFN 1','FontSize',y_mult*18)                           ;

fig.UserData.inps.DD_11 = uidropdown(fig,"Items",[Options_.HFN],'Position',  [x_mult*334, y_mult*205, x_mult*68, y_mult*28],'FontSize',y_mult*18,'Value',Options_.HFN{Defaults.HFN_2_index});
lbl11 = uilabel(fig,'Position',[x_mult*334, y_mult*230, x_mult*150, y_mult*28],'Text', 'HFN 2','FontSize',y_mult*18)                           ;

fig.UserData.inps.DD_12 = uidropdown(fig,"Items",[Options_.HFN],'Position',  [x_mult*404, y_mult*205, x_mult*68, y_mult*28],'FontSize',y_mult*18,'Value',Options_.HFN{Defaults.HFN_3_index});
lbl12 = uilabel(fig,'Position',[x_mult*404, y_mult*230, x_mult*150, y_mult*28],'Text', 'HFN 3','FontSize',y_mult*18)                           ;        

% LFN Boundaries (3)
% HFN Boundaries (3)

%----------------------------------------------------------------------------------
%ROW 3
%----------------------------------------------------------------------------------
% exitation_freq_kHz
% SNR_bandwidth_kHz
% time_gate
% diagonal_time_gate

fig.UserData.inps.DD_13 = uidropdown(fig,"Items",[Options_.Exit_freq ],'Position', [x_mult*10,y_mult*130,x_mult*65,y_mult*28],'FontSize',y_mult*18,'Value',Options_.Exit_freq{Defaults.Exit_freq_index})   ;
lbl13 = uilabel(fig,'Position',[x_mult*10, y_mult*155, x_mult*130, y_mult*28],'Text', 'Exf(kHz)','FontSize',y_mult*16)                        ;

fig.UserData.inps.DD_14 = uidropdown(fig,"Items",[Options_.bandwidth_KHz ],'Position', [x_mult*87,y_mult*130,x_mult*65,y_mult*28],'FontSize',y_mult*18,'Value',Options_.bandwidth_KHz{Defaults.bandwidth_index})   ;
lbl14 = uilabel(fig,'Position',[x_mult*87,y_mult*155,x_mult*130, y_mult*28],'Text', 'BW(KHz)','FontSize',y_mult*16)                        ;

fig.UserData.inps.DD_15 = uidropdown(fig,"Items",[Options_.timegate],'Position',[x_mult*167,y_mult*130,x_mult*65,y_mult*28],'FontSize',y_mult*18,'Value',Options_.timegate{Defaults.timegate_index})   ;
lbl15 = uilabel(fig,'Position',[x_mult*167, y_mult*155, x_mult*130, y_mult*28],'Text', 'Gt1(sp)','FontSize',y_mult*16);

fig.UserData.inps.DD_17 = uidropdown(fig,"Items",[Options_.timegate2],'Position',[x_mult*247,y_mult*130,x_mult*65,y_mult*28],'FontSize',y_mult*18,'Value',Options_.timegate2{Defaults.timegate2_index})   ;
lbl17 = uilabel(fig,'Position',[x_mult*247, y_mult*155, x_mult*130, y_mult*28],'Text', 'Gt2(sp)','FontSize',y_mult*16);

fig.UserData.inps.DD_18 = uidropdown(fig,"Items",[Options_.timegate3],'Position',[x_mult*327,y_mult*130,x_mult*65,y_mult*28],'FontSize',y_mult*18,'Value',Options_.timegate3{Defaults.timegate3_index})   ;
lbl18 = uilabel(fig,'Position',[x_mult*327, y_mult*155, x_mult*130, y_mult*28],'Text', 'Gt3(sp)','FontSize',y_mult*16);

fig.UserData.inps.DD_16 = uidropdown(fig,"Items",[Options_.D_timegate],'Position', [x_mult*407,y_mult*130,x_mult*65,y_mult*28],'FontSize',y_mult*18,'Value',Options_.D_timegate{Defaults.D_timegate_index})   ;
lbl16 = uilabel(fig,'Position',[x_mult*407, y_mult*155, x_mult*130, y_mult*28],'Text', 'DGt(sp)','FontSize',y_mult*16);
%----------------------------------------------------------------------------------
% 3 Buttons
%----------------------------------------------------------------------------------

but1 = uibutton(fig,"push" ,"Text","Reload FDs",'Position',[x_mult*34,y_mult*30,x_mult*120,y_mult*55],'FontSize',y_mult*18,"ButtonPushedFcn", @(src,event)FD_ButtonPushed(fig,FD_settings_path))   ;
but2 = uibutton(fig,"push" ,"Text","Reload Defs",'Position',[x_mult*182,y_mult*30,x_mult*120,y_mult*55],'FontSize',y_mult*18,"ButtonPushedFcn", @(src,event)RD_ButtonPushed(fig,Settings_path))   ;
but3 = uibutton(fig,"push" ,"Text","Save/Exit",'Position',[x_mult*329,y_mult*30,x_mult*120,y_mult*55],'FontSize',y_mult*18,"ButtonPushedFcn", @(src,event)S_ButtonPushed(fig))   ;
%----------------------------------------------------------------------------------
end %function [fig] = bespoke_dialog_box2(Options_,Defaults)

function FD_ButtonPushed(fig,FD_settings_path)

%[snr_settings , ~ ]     = load_structure_from_file(FD_settings_path);
[snr_settings , ~ ]     = load_mat_structure_from_file(FD_settings_path);
[Options_,Defaults]     = get_options_Defaults(snr_settings);
reset_the_dropdowns(fig , Options_ , Defaults)

end %function Button1Pushed(fig)



function RD_ButtonPushed(fig,Settings_path)
%[snr_settings , ~ ]     = load_structure_from_file(Settings_path);
[snr_settings , ~ ]     = load_mat_structure_from_file(Settings_path);
[Options_,Defaults]     = get_options_Defaults(snr_settings);
reset_the_dropdowns(fig , Options_ , Defaults)
end %function Button1Pushed(fig)



function S_ButtonPushed(fig)
%  Save the data in the structure  
fig.UserData.S_button_pressed = 1;

%  have error messages in here-  check the 4 boudaries and make sure the
%  indices are in assending order

 error_message = [] ;
 counter_ = 0 ;
%--------------------------------------------------------------------------------------------------------
rms_bounds =    [find(ismember(fig.UserData.inps.DD_1.Items,fig.UserData.inps.DD_1.Value)),...
                 find(ismember(fig.UserData.inps.DD_2.Items,fig.UserData.inps.DD_2.Value)),...
                 find(ismember(fig.UserData.inps.DD_3.Items,fig.UserData.inps.DD_3.Value))];

if length(find((rms_bounds - sort(rms_bounds))==0)) ~= length(rms_bounds)
% create an error message
counter_ = counter_ + 1;
error_message{counter_} = 'RMS boundaries must be in ascending order';
end  % if length(find([rms_bounds - sort(rms_bounds)]==0)) ~= length(rms_bounds)
%--------------------------------------------------------------------------------------------------------
snr_bounds =    [find(ismember(fig.UserData.inps.DD_4.Items,fig.UserData.inps.DD_4.Value)),...
                 find(ismember(fig.UserData.inps.DD_5.Items,fig.UserData.inps.DD_5.Value)),...
                 find(ismember(fig.UserData.inps.DD_6.Items,fig.UserData.inps.DD_6.Value))];

if length(find((snr_bounds - sort(snr_bounds))==0)) ~= length(snr_bounds)
% create an error message
counter_ = counter_ + 1;
error_message{counter_} = 'SNR boundaries must be in ascending order';
end  % if length(find([rms_bounds - sort(rms_bounds)]==0)) ~= length(rms_bounds)
%--------------------------------------------------------------------------------------------------------
lfn_bounds =    [find(ismember(fig.UserData.inps.DD_7.Items,fig.UserData.inps.DD_7.Value)),...
                 find(ismember(fig.UserData.inps.DD_8.Items,fig.UserData.inps.DD_8.Value)),...
                 find(ismember(fig.UserData.inps.DD_9.Items,fig.UserData.inps.DD_9.Value))];

if length(find((lfn_bounds - sort(lfn_bounds))==0)) ~= length(lfn_bounds)
% create an error message
counter_ = counter_ + 1;
error_message{counter_} = 'LFN boundaries must be in descending order';
end  % if length(find([rms_bounds - sort(rms_bounds)]==0)) ~= length(rms_bounds)
%--------------------------------------------------------------------------------------------------------
hfn_bounds =    [find(ismember(fig.UserData.inps.DD_10.Items,fig.UserData.inps.DD_10.Value)),...
                 find(ismember(fig.UserData.inps.DD_11.Items,fig.UserData.inps.DD_11.Value)),...
                 find(ismember(fig.UserData.inps.DD_12.Items,fig.UserData.inps.DD_12.Value))];
%--------------------------------------------------------------------------------------------------------
if length(find((hfn_bounds - sort(hfn_bounds))==0)) ~= length(hfn_bounds)
% create an error message
counter_ = counter_ + 1;
error_message{counter} = 'HFN boundaries must be in descending order';
end  % if length(find([rms_bounds - sort(rms_bounds)]==0)) ~= length(rms_bounds)
%--------------------------------------------------------------------------------------------------------

fig.UserData.error_message = error_message ;

end %function Button1Pushed(fig)

function reset_the_dropdowns(fig , Options_ , Defaults)
fig.UserData.inps.DD_1.Value  = Options_.RMS{Defaults.RMS1_index};
fig.UserData.inps.DD_2.Value  = Options_.RMS{Defaults.RMS2_index};
fig.UserData.inps.DD_3.Value  = Options_.RMS{Defaults.RMS3_index};
fig.UserData.inps.DD_4.Value  = Options_.SNR{Defaults.SNR1_index};
fig.UserData.inps.DD_5.Value  = Options_.SNR{Defaults.SNR2_index};
fig.UserData.inps.DD_6.Value  = Options_.SNR{Defaults.SNR3_index};
fig.UserData.inps.DD_7.Value  = Options_.LFN{Defaults.LFN_1_index};
fig.UserData.inps.DD_8.Value  = Options_.LFN{Defaults.LFN_2_index};
fig.UserData.inps.DD_9.Value  = Options_.LFN{Defaults.LFN_3_index};
fig.UserData.inps.DD_10.Value = Options_.HFN{Defaults.HFN_1_index};
fig.UserData.inps.DD_11.Value = Options_.HFN{Defaults.HFN_2_index};
fig.UserData.inps.DD_12.Value = Options_.HFN{Defaults.HFN_3_index};
fig.UserData.inps.DD_13.Value = Options_.Exit_freq{Defaults.Exit_freq_index};
fig.UserData.inps.DD_14.Value = Options_.bandwidth_KHz{Defaults.bandwidth_index};
fig.UserData.inps.DD_15.Value = Options_.timegate{Defaults.timegate_index};
fig.UserData.inps.DD_16.Value = Options_.D_timegate{Defaults.D_timegate_index};
fig.UserData.inps.DD_17.Value = Options_.timegate2{Defaults.timegate2_index};
fig.UserData.inps.DD_18.Value = Options_.timegate3{Defaults.timegate3_index};

end %function reset_the_dropdowns(fig , Options_ , Defaults)


function [Options_,Defaults] = get_options_Defaults(dum)
  
Options_.RMS           = cellfun(@num2str, num2cell(dum.RMS_boundaries_options)     , 'UniformOutput', false)';    
Options_.SNR           = cellfun(@num2str, num2cell(dum.SNR_boundaries_options)     , 'UniformOutput', false)';    
Options_.LFN           = cellfun(@num2str, num2cell(dum.LFN_boundaries_options)     , 'UniformOutput', false)';    
Options_.HFN           = cellfun(@num2str, num2cell(dum.HFN_boundaries_options)     , 'UniformOutput', false)';    
Options_.Exit_freq     = cellfun(@num2str, num2cell(dum.exitation_freq_kHz_options) , 'UniformOutput', false)';    
Options_.bandwidth_KHz = cellfun(@num2str, num2cell(dum.SNR_bandwidth_kHz_options)  , 'UniformOutput', false)';    
Options_.timegate      = cellfun(@num2str, num2cell(dum.time_gate_options)          , 'UniformOutput', false)';    
Options_.timegate2      = cellfun(@num2str, num2cell(dum.time_gate2_options)        , 'UniformOutput', false)';    
Options_.timegate3      = cellfun(@num2str, num2cell(dum.time_gate3_options)        , 'UniformOutput', false)';    

Options_.D_timegate    = cellfun(@num2str, num2cell(dum.diagonal_time_gate_options) , 'UniformOutput', false)';    

Defaults.RMS1_index = dum.RMS_boundaries(1); 
Defaults.RMS2_index = dum.RMS_boundaries(2);
Defaults.RMS3_index = dum.RMS_boundaries(3);

Defaults.SNR1_index = dum.SNR_boundaries(1);
Defaults.SNR2_index = dum.SNR_boundaries(2);
Defaults.SNR3_index = dum.SNR_boundaries(3);

Defaults.LFN_1_index= dum.LFN_boundaries(1);
Defaults.LFN_2_index= dum.LFN_boundaries(2);
Defaults.LFN_3_index= dum.LFN_boundaries(3);

Defaults.HFN_1_index= dum.HFN_boundaries(1);
Defaults.HFN_2_index= dum.HFN_boundaries(2);
Defaults.HFN_3_index= dum.HFN_boundaries(3);

Defaults.Exit_freq_index  = dum.exitation_freq_kHz      ;
Defaults.bandwidth_index  = dum.SNR_bandwidth_kHz       ;
Defaults.timegate_index    = dum.time_gate              ;
Defaults.timegate2_index    = dum.time_gate2            ;
Defaults.timegate3_index    = dum.time_gate3            ;

Defaults.D_timegate_index  = dum.diagonal_time_gate     ;

% dum =  Test_Settings_new.Sampling;
% Options_.sample_rate_ = cellfun(@num2str, num2cell(xxxx) , 'UniformOutput', false)' ;

%{
Options_.RMS   =  {'0.05','0.1','0.15','0.2','0.25','0.3','0.35','0.4','0.45','0.5','0.55','0.6','0.65','0.7'} ;
Options_.SNR   =  {'0.1','0.2','0.3','0.4','0.5','0.6','0.7','0.8','0.9','1','1.1','1.2','1.3','1.4','1.5','1.6','1.7','1.8','1.9','2'} ;  

Options_.LFN   =  {'-0.5','-1','-1.5','-2','-2.5','-3','-3.5','-4','-4.5','-5','-4','-4.5','-5'};
Options_.HFN   =  Options_.LFN;

Options_.Exit_freq = {'40','45','50','55','60'};
Options_.bandwidth_KHz = {'10','11','12','13','14','15','16','17','18','19','20','21','22','23','24','25','26','27','28','29','30'};

Options_.timegate  = {'30','35','40','45','50','55','60','65','70' };
Options_.D_timegate = {'160','170','180','190','200','210','220','230'};

Defaults.RMS1_index = 2        ; 
Defaults.RMS2_index = 5        ;
Defaults.RMS3_index = 12       ;

Defaults.SNR1_index = 3        ;
Defaults.SNR2_index = 10       ; 
Defaults.SNR3_index = 20       ;

Defaults.LFN_1_index = 2       ;
Defaults.LFN_2_index = 7       ;
Defaults.LFN_3_index = 10      ;

Defaults.HFN_1_index = 2       ;
Defaults.HFN_2_index = 7       ;
Defaults.HFN_3_index = 10      ;

Defaults.Exit_freq_index = 3   ;
Defaults.bandwidth_index = 12  ;
Defaults.timegate_index  =  7  ;
Defaults.D_timegate_index      =  5  ; 
%}
end %function [Options_,Defaults] = get_options_Defaults(snr_settings);
