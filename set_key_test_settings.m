function Test_Settings_updated = set_key_test_settings(varargin) 
% These  functions should be in contact wire test
% Test_Settings = set_key_test_settings()
% put the FD and sttings path into the path name



switch(nargin)

    case(0) 
FD_settings_path =  [pwd,'\SETTINGS_FILES\Test_Settings3.mat']                     ; 
Settings_path    =  [getenv('APPDATA'),'\SETTINGS_FILES\Test_Settings3.mat']       ;
[Test_Settings3 , ~] =  load_mat_structure_from_file(Settings_path)                ;
Pix_SS = get(0,'screensize')              ;
x_mult = (Pix_SS(3)/1920)   ;
y_mult = (Pix_SS(4)/1080 )  ;
mag_fac = 1;

    case(6)
Test_Settings3     = varargin{1}   ;
FD_settings_path   = varargin{2}   ;
Settings_path      = varargin{3}   ;

base_width = varargin{4};
base_height = varargin{5};
mag_fac   = varargin{6};

Pix_SS = get(0,'screensize')                ;
x_mult = (Pix_SS(3)/base_width)   * mag_fac ;
y_mult = (Pix_SS(4)/base_height)  * mag_fac ;


end % switch(nargin)

[Options_,Defaults] = get_options_Defaults(Test_Settings3);

[fig] = bespoke_dialog_box2(Options_,Defaults,FD_settings_path,Settings_path,x_mult,y_mult,mag_fac);
fig.Icon = 'ICON2.png';



Test_Settings_updated = get_test_parameters_essential(fig,Test_Settings3);

if isstruct(Test_Settings_updated)
   
% OK_ =   create_file_from_structure(Test_Settings_updated,Settings_path) ;
OK_  =  save_mat_structure_to_file( Test_Settings_updated,Settings_path)  ; 

if ~OK_
msgbox('problem saving defaults')    
end %if ~OK_
end %if isstruct(Test_Settings_updated)


end %function Test_Settings = set_key_test_settings(Test_Settings) 

function Test_Settings3 = get_test_parameters_essential(fig,Test_Settings3)

%fig.UserData.RD_button_pressed = 1;
%fig.UserData.FD_button_pressed = 1;



fig.UserData.S_button_pressed  = 0;
Save_Btn_pressed  = 0;

while Save_Btn_pressed == 0
drawnow()

if isvalid(fig)
Save_Btn_pressed = fig.UserData.S_button_pressed;
else
Test_Settings3 = []; 
return
end % if isvalid(fig)

end % while Save_Btn_pressed == 0

new_vals_.SR_index  = find(ismember(fig.UserData.inps.DD_1.Items,  fig.UserData.inps.DD_1.Value));
new_vals_.ADC_index = find(ismember(fig.UserData.inps.DD_2.Items,  fig.UserData.inps.DD_2.Value));
new_vals_.TF_index  = find(ismember(fig.UserData.inps.DD_3.Items,  fig.UserData.inps.DD_3.Value));
new_vals_.NC_index  = find(ismember(fig.UserData.inps.DD_4.Items,  fig.UserData.inps.DD_4.Value));
new_vals_.TB_index  = find(ismember(fig.UserData.inps.DD_5.Items,  fig.UserData.inps.DD_5.Value));
new_vals_.NA_index  = find(ismember(fig.UserData.inps.DD_6.Items,  fig.UserData.inps.DD_6.Value));
new_vals_.NS_index  = find(ismember(fig.UserData.inps.DD_7.Items,  fig.UserData.inps.DD_7.Value));
new_vals_.TPO_index  = find(ismember(fig.UserData.inps.DD_8.Items,  fig.UserData.inps.DD_8.Value));


Test_Settings3 = update_Test_Settings3(Test_Settings3,new_vals_);
close (fig)


end %function Test_Settings3 = get_test_parameters_essential(fig)



function Test_Settings3 = update_Test_Settings3(Test_Settings3,new_vals_)

Test_Settings3.Sampling.Sample_RateHz                               =  new_vals_.SR_index   ;
Test_Settings3.Sampling.adc_Range_                                  =  new_vals_.ADC_index  ;
Test_Settings3.Toneburst.Frequency                                  =  new_vals_.TF_index   ;
Test_Settings3.Toneburst.num_cycles                                 =  new_vals_.NC_index   ;
Test_Settings3.Toneburst.Shape                                      =  new_vals_.TB_index   ;
Test_Settings3.Sampling.Num_Averages                                =  new_vals_.NA_index   ;
Test_Settings3.Sampling.Num_Samples                                 =  new_vals_.NS_index   ;    
Test_Settings3.Instrument_attributes.trans_pos_orientation_choice   =  new_vals_.TPO_index   ;    

end %function Test_Settings3 = update_Test_Settings3(Test_Settings3,new_vals_);


function [Options_,Defaults] = get_options_Defaults(Test_Settings3)


dum =  Test_Settings3.Sampling;
Options_.sample_rate_ = cellfun(@num2str, num2cell(dum.Sample_Rate_options) , 'UniformOutput', false)' ; 
Options_.num_samples  = cellfun(@num2str, num2cell(dum.Num_Samples_options) , 'UniformOutput', false)' ; 
Options_.adc_range_   = cellfun(@num2str, num2cell(dum.adc_Range_options)   , 'UniformOutput', false)' ; 
Options_.num_averages = cellfun(@num2str, num2cell(dum.Num_Averages_options), 'UniformOutput', false)' ; 

dum2 = Test_Settings3.Toneburst   ;
Options_.num_cycles  = cellfun(@num2str, num2cell(dum2.num_cycles_options ) , 'UniformOutput', false)' ; 
Options_.tone_freq_  = cellfun(@num2str, num2cell(dum2. Frequency_options ) , 'UniformOutput', false)' ;
Options_.tone_burst_shape = dum2.Shape_options;

dum3 = Test_Settings3.Instrument_attributes   ;
Options_.trans_pos_orientation_labels = dum3.trans_pos_orientation_labels;

Defaults.SR_index  = dum.Sample_RateHz ; 
Defaults.NS_index  = dum.Num_Samples  ; 
Defaults.ADC_index = dum.adc_Range_; 
Defaults.NA_index  = dum.Num_Averages;

Defaults.NC_index = dum2.num_cycles ; 
Defaults.TF_index = dum2.Frequency;   
Defaults.TB_index = dum2.Shape;
Defaults.TPO_index = dum3.trans_pos_orientation_choice;

end %function [Options_,Defaults] = get_options_Defaults(Test_Settings3)

function fig =  bespoke_dialog_box2(Options_,Defaults,FD_settings_path,Settings_path,x_mult,y_mult,mag_fac)

fig = uifigure('Resize','off','Units','normalized','Position',[0.05,0.05,0.2*mag_fac,0.3*mag_fac],'Name', 'Test Settings' );

fig.UserData.S_button_pressed = 0   ; 
fig.UserData.button_pressed   = 0   ;    
fig.UserData.Warning_message  = ''  ;
%----------------------------------------------------------------------------------
%ROW 1
%----------------------------------------------------------------------------------

fig.UserData.inps.DD_1 = uidropdown(fig,"Items",[Options_.sample_rate_],'Position', [x_mult*15, y_mult*265,x_mult*100, y_mult*28],'FontSize',y_mult*18,'Value',Options_.sample_rate_{Defaults.SR_index});
lbl = uilabel(fig,'Position',[x_mult*15, y_mult*290, x_mult*150, y_mult*28],'Text', 'S.Rate(Hz)','FontSize',y_mult*18)                           ;

fig.UserData.inps.DD_2 =  uidropdown(fig,"Items",[Options_.adc_range_],'Position', [x_mult*145,y_mult*265,x_mult*100,y_mult*28],'FontSize',y_mult*18,'Value',Options_.adc_range_{ Defaults.ADC_index}  )   ;
lbl2 = uilabel(fig,'Position',[x_mult*145, y_mult*290,x_mult*150, y_mult*28],'Text', 'DC Range(V)','FontSize',y_mult*18)                          ;

fig.UserData.inps.DD_3 = uidropdown(fig,"Items",[Options_.tone_freq_],'Position', [x_mult*275,y_mult*265,x_mult*100,y_mult*28],'FontSize',y_mult*18,'Value',Options_.tone_freq_{Defaults.TF_index});
lbl3 = uilabel(fig,'Position',[x_mult*275, y_mult*290,x_mult*150, y_mult*28],'Text', 'T.B.Freq(Hz)','FontSize',y_mult*18)                        ;

%----------------------------------------------------------------------------------
%ROW 2
%----------------------------------------------------------------------------------
fig.UserData.inps.DD_4 = uidropdown(fig,"Items",[Options_.num_cycles ],'Position', [x_mult*15,y_mult*200,x_mult*100,y_mult*28],'FontSize',y_mult*18,'Value',Options_.num_cycles{Defaults.NC_index})   ;
lbl4 = uilabel(fig,'Position',[x_mult*15, y_mult*225, x_mult*150, y_mult*28],'Text', 'No Cycles','FontSize',y_mult*18)                        ;

fig.UserData.inps.DD_5 = uidropdown(fig,"Items",[Options_.tone_burst_shape ],'Position', [x_mult*145,y_mult*200,x_mult*100,y_mult*28],'FontSize',y_mult*18,'Value',Options_.tone_burst_shape{Defaults.TB_index})   ;
lbl5 = uilabel(fig,'Position',[x_mult*145, y_mult*225, x_mult*150, y_mult*28],'Text', 'T.B. Window','FontSize',y_mult*18)                        ;

fig.UserData.inps.DD_6 = uidropdown(fig,"Items",[Options_.num_averages ],'Position', [x_mult*275,y_mult*200,x_mult*100,y_mult*28],'FontSize',y_mult*18,'Value',Options_.num_averages{Defaults.NA_index})   ;
lbl6 = uilabel(fig,'Position',[x_mult*275, y_mult*225, x_mult*150, y_mult*28],'Text', 'No Averages','FontSize',y_mult*18)                        ;

%----------------------------------------------------------------------------------
%ROW 3
%----------------------------------------------------------------------------------
fig.UserData.inps.DD_7 = uidropdown(fig,"Items",[Options_.num_samples],'Position', [x_mult*15, y_mult*135, x_mult*100, y_mult*28],'FontSize',y_mult*18,'Value',Options_.num_samples{Defaults.NS_index})   ;
lbl7 = uilabel(fig,'Position',[x_mult*15, y_mult*160, x_mult*100, y_mult*28],'Text', 'No Samples','FontSize',y_mult*18)                                           ;

fig.UserData.inps.DD_8 = uidropdown(fig,"Items",[Options_.trans_pos_orientation_labels],'Position', [x_mult*275, y_mult*135, x_mult*100, y_mult*28],'FontSize',y_mult*18,'Value',Options_.trans_pos_orientation_labels{Defaults.TPO_index})   ;
lbl8 = uilabel(fig,'Position',[x_mult*275, y_mult*160, x_mult*100, y_mult*28],'Text', 'Trans Orient','FontSize',y_mult*18)                                           ;

%----------------------------------------------------------------------------------
%ROW 4 --  Buttons
%----------------------------------------------------------------------------------
but1 = uibutton(fig,"push" ,"Text","Reload FDs",'Position',[x_mult*5,y_mult*30,x_mult*120,y_mult*55],'FontSize',y_mult*18,"ButtonPushedFcn", @(src,event)FD_ButtonPushed(fig,FD_settings_path))   ;
but2 = uibutton(fig,"push" ,"Text","Reload Defs",'Position',[x_mult*132,y_mult*30,x_mult*120,y_mult*55],'FontSize',y_mult*18,"ButtonPushedFcn", @(src,event)RD_ButtonPushed(fig,Settings_path))   ;
but3 = uibutton(fig,"push" ,"Text","Save/Exit",'Position',[x_mult*260,y_mult*30,x_mult*120,y_mult*55],'FontSize',y_mult*18,"ButtonPushedFcn", @(src,event)S_ButtonPushed(fig))   ;

end %function bespoke_dialog_box(data_)

function FD_ButtonPushed(fig,FD_settings_path)
%disp('load the factory defaults')

% [Test_Settings_default , ~ ] = load_structure_from_file(FD_settings_path);
[Test_Settings_default , ~ ] =  load_mat_structure_from_file(FD_settings_path);
[Options_,Defaults] = get_options_Defaults(Test_Settings_default);

reset_the_dropdowns(fig , Options_ , Defaults)
end %function Button1Pushed(fig)

function RD_ButtonPushed(fig,Settings_path)
%load the defaults data
%[Test_Settings_default , ~ ] = load_structure_from_file(Settings_path);
[Test_Settings_default , ~ ] = load_mat_structure_from_file(Settings_path);
[Options_,Defaults] = get_options_Defaults(Test_Settings_default);

reset_the_dropdowns(fig , Options_ , Defaults)

end %function Button1Pushed(fig)

function S_ButtonPushed(fig)
fig.UserData.S_button_pressed = 1;
end %function Button1Pushed(fig)

function reset_the_dropdowns(fig , Options_ , Defaults)

fig.UserData.inps.DD_1.Value = Options_.sample_rate_{Defaults.SR_index};
fig.UserData.inps.DD_2.Value = Options_.adc_range_{ Defaults.ADC_index};
fig.UserData.inps.DD_3.Value = Options_.tone_freq_{Defaults.TF_index};
fig.UserData.inps.DD_4.Value = Options_.num_cycles{Defaults.NC_index};
fig.UserData.inps.DD_5.Value = Options_.tone_burst_shape{Defaults.TB_index};
fig.UserData.inps.DD_6.Value = Options_.num_averages{Defaults.NA_index};
fig.UserData.inps.DD_7.Value = Options_.num_samples{Defaults.NS_index};
fig.UserData.inps.DD_8.Value = Options_.trans_pos_orientation_labels{Defaults.TPO_index};

end %function reset_the_dropdowns(fig , Options_ , Defaults)




