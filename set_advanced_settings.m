function advanced_settings_updated = set_advanced_settings(varargin) 

switch(nargin)
    case(0)
FD_settings_path =  [pwd,'\SETTINGS_FILES\advanced_settings.mat']; 
Settings_path    =  [getenv('APPDATA'),'\SETTINGS_FILES\advanced_settings.mat'];
[advanced_settings , ~ ] = load_mat_structure_from_file(Settings_path); 

    case(3)
advanced_settings     =   varargin{1};
FD_settings_path =  varargin{2};
Settings_path    =  varargin{3};

mag_fac                   =  1.9531;
base_width                =  1920                  ; 
base_height               =  1080                  ; 

Pix_SS = get(0,'screensize')                ;
x_mult = (Pix_SS(3)/base_width)   * mag_fac ;
y_mult = (Pix_SS(4)/base_height)  * mag_fac ;

    case(6)
advanced_settings    = varargin{1};
FD_settings_path    =  varargin{2};
Settings_path       =  varargin{3};

base_width          = varargin{4};
base_height         = varargin{5};
mag_fac             = varargin{6};

Pix_SS = get(0,'screensize')                ;
x_mult = (Pix_SS(3)/base_width)   * mag_fac ;
y_mult = (Pix_SS(4)/base_height)  * mag_fac ;
           
end % switch(nargin)

[Options_,Defaults] = get_options_Defaults(advanced_settings);

[fig] = bespoke_dialog_box2(Options_,Defaults,FD_settings_path,Settings_path,x_mult,y_mult,mag_fac);
advanced_settings_updated = get_advanced_settings_essential(fig,advanced_settings);


if isstruct(advanced_settings_updated)
OK_ =    save_mat_structure_to_file(advanced_settings_updated,Settings_path); 
if ~OK_
    msgbox('problem saving')    
end %if ~OK_
end %if isstruct(plot_Options_updated)
end  % function advanced_settings_updated = set_advanced_settings(varargin) 


function advanced_settings_updated = get_advanced_settings_essential(fig,plot_options)

fig.UserData.S_button_pressed  = 0 ;
Save_Btn_pressed               = 0 ;

while Save_Btn_pressed == 0
drawnow()
if isvalid(fig)
Save_Btn_pressed = fig.UserData.S_button_pressed;
else
 advanced_settings_updated = []; 
return
end % if isvalid(fig)
end % while Save_Btn_pressed == 0
%  updat the values in he structure then save

advanced_settings_updated = update_plot_options(fig,plot_options);
close (fig)
end %function plot_Options_updated = get_Plot_Options_essential(fig,plot_options);


function advanced_settings = update_plot_options(fig,advanced_settings )
advanced_settings.choices.mag  = find(ismember(fig.UserData.inps.DD_1.Items,  fig.UserData.inps.DD_1.Value));
advanced_settings.choices.Region_index  = find(ismember(fig.UserData.inps.DD_2.Items,  fig.UserData.inps.DD_2.Value));

end


function [Options_,Defaults] = get_options_Defaults(dum)

Options_.mag_labels                 = dum.options.mag_labels     ;
Options_.Region_options             = dum.options.Region_options ; 

Defaults.mag                        = dum.choices.mag            ;
Defaults.Region_index               = dum.choices.Region_index   ;

end % function [Options_,Defaults] = get_options_Defaults(snr_settings)



function [fig] = bespoke_dialog_box2(Options_,Defaults,FD_settings_path,Settings_path,x_mult,y_mult,mag_fac)


fig = uifigure('Resize','off','Units','normalized','Position',[0.05,0.05,0.2*mag_fac,0.3*mag_fac],'Name', 'Advanced Settings');
fig.Icon = 'ICON2.png';
fig.UserData.S_button_pressed = 0;

%----------------------------------------------------------------------------------
%ROW 1
%----------------------------------------------------------------------------------
fig.UserData.inps.DD_1 =  uidropdown(fig,"Items",[Options_.mag_labels],'Position', [x_mult*145,y_mult*265,x_mult*110,y_mult*28],'FontSize',y_mult*18,'Value',Options_.mag_labels{Defaults.mag});
lbl2 = uilabel(fig,'Position',[x_mult*145, y_mult*290, x_mult*150, y_mult*28],'Text', 'Magnification','FontSize',y_mult*18)                          ;
%----------------------------------------------------------------------------------
%ROW 2
%----------------------------------------------------------------------------------

fig.UserData.inps.DD_2 =  uidropdown(fig,"Items",[Options_.Region_options],'Position', [x_mult*145,y_mult*135,x_mult*180,y_mult*28],'FontSize',y_mult*18,'Value',Options_.Region_options{Defaults.Region_index});
lbl3 = uilabel(fig,'Position',[x_mult*145, y_mult*160, x_mult*150, y_mult*28],'Text', 'Region','FontSize',y_mult*18);

%----------------------------------------------------------------------------------
%ROW 5 --  Buttons
%----------------------------------------------------------------------------------
but1 = uibutton(fig,"push" ,"Text","Reload FDs",'Position',[x_mult*5,y_mult*10,x_mult*120,y_mult*55],'FontSize',y_mult*18,"ButtonPushedFcn", @(src,event)FD_ButtonPushed(fig,FD_settings_path))   ;
but2 = uibutton(fig,"push" ,"Text","Reload Defs",'Position',[x_mult*132,y_mult*10,x_mult*120,y_mult*55],'FontSize',y_mult*18,"ButtonPushedFcn", @(src,event)RD_ButtonPushed(fig,Settings_path))   ;
but3 = uibutton(fig,"push" ,"Text","Save/Exit",'Position',[x_mult*260,y_mult*10,x_mult*120,y_mult*55],'FontSize',y_mult*18,"ButtonPushedFcn", @(src,event)S_ButtonPushed(fig))   ;

end %function [fig] = bespoke_dialog_box2(Options_,Defaults,FD_settings_path,Settings_path);


function FD_ButtonPushed(fig,FD_settings_path)
%disp('load the factory defaults')
%[Test_Settings_default , ~ ] = load_structure_from_file(FD_settings_path);
[advanced_settings_default , ~ ]          = load_mat_structure_from_file(FD_settings_path); 
[Options_,Defaults] = get_options_Defaults(advanced_settings_default);
reset_the_dropdowns(fig , Options_ , Defaults)
end %function Button1Pushed(fig)


function RD_ButtonPushed(fig,Settings_path)
%load the defaults data
%[Test_Settings_default , ~ ] = load_structure_from_file(Settings_path);
[advanced_settings_defaault , ~ ]          = load_mat_structure_from_file(Settings_path); 
[Options_,Defaults] = get_options_Defaults(advanced_settings_defaault);
reset_the_dropdowns(fig , Options_ , Defaults)
end %function Button1Pushed(fig)

function S_ButtonPushed(fig)
fig.UserData.S_button_pressed = 1;
end %function Button1Pushed(fig)

function reset_the_dropdowns(fig , Options_ , Defaults)
fig.UserData.inps.DD_1.Value = Options_.mag_labels{Defaults.mag}                      ;
fig.UserData.inps.DD_2.Value = Options_.Region_options{Defaults.Region_index}         ;

% to be written
end %function reset_the_dropdowns(fig , Options_ , Defaults)








