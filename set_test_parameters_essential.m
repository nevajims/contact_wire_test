function test_parameters_ = set_test_parameters_essential(varargin)

% Remove

switch(nargin)
    
    case(0)    
FD_settings_path =                [pwd,'\SETTINGS_FILES\test_parameters2.mat']                   ; 
%Settings_path    =                [getenv('APPDATA'),'\SETTINGS_FILES\test_parameters2.mat']     ;

[test_paramters_options , ~] =  load_mat_structure_from_file(FD_settings_path);
%[test_paramters_last , ~]    =  load_mat_structure_from_file(Settings_path);

base_width                = 1920                  ; 
base_height               = 1080                  ; 
mag_fac                     =  1.82               ;

    case(5)
% FD_settings_path       =       varargin{2}  ; 
Settings_path          =       varargin{2}  ;
test_paramters_options =       varargin{1};

%[test_paramters_last , ~] =  load_mat_structure_from_file(Settings_path);


base_width     = varargin{3}  ;
base_height    = varargin{4}  ;  
mag_fac        = varargin{5}  ; 
end %switch(nargin)


if exist([pwd,'\SETTINGS_FILES\NS_Details.mat']) == 2
do_LU = 1;    
else
do_LU = 0;    
end


Pix_SS = get(0,'screensize')               ;
x_mult = (Pix_SS(3)/base_width)   * mag_fac;
y_mult = (Pix_SS(4)/base_height)  * mag_fac;


%keyboard

%test_parameters_essential = set_test_parameters_essential()

data_         =  test_paramters_options.data_       ;
defaults_     =  test_paramters_options.defaults_   ;
%defaults_last =  test_paramters_last.defaults_      ;

[fig] = bespoke_dialog_box2(do_LU, data_,defaults_,x_mult ,y_mult,mag_fac );

fig.Icon = 'ICON2.png';
[test_parameters_] = get_test_parameters_essential(fig);


% test_parameters_file

%{
if isstruct(test_parameters_file)
%create_file_from_structure(test_parameters_file,Settings_path)  
OK_  =  save_mat_structure_to_file( test_parameters_file,Settings_path)  ; 
end % if isstruct(test_parameters_file)
%}

% outpt  test_parameters_
% save   test_parameters_file
%-------------these should be inputs
end %function test_parameters_essential = set_test_parameters_essential()

function [test_parameters_]  = get_test_parameters_essential(fig)
Btn_pressed        = 0;
no_warnings        = 0;

while no_warnings ==0
while Btn_pressed == 0
drawnow()

if isvalid(fig)
Btn_pressed = fig.UserData.button_pressed;
else
test_parameters_file = [];
test_parameters_     = [];
return
end %if isvalid(fig)
end %while Btn_pressed == 0


if isvalid(fig)

if length(fig.UserData.Warning_message) == 0
no_warnings = 1;

else
wmsg_ = fig.UserData.Warning_message                       ; 
wmsg_{length(wmsg_)+1} = ''                                ;
wmsg_{length(wmsg_)+1} = 'IGNORE WARNINGS OR TRY AGAIN?'   ;
answer_ = questdlg(wmsg_,'WARNINGS','Ignore','Try Again','Try Again');

if strcmp(answer_,'Ignore') == 1
no_warnings = 1;
else
no_warnings = 0;
Btn_pressed = 0;
fig.UserData.button_pressed = 0;
end %if strcmp(answer_,'Ignore') == 1

end %if length(fig.UserData.Warning_message) == 0
end
end % while no_warnings ==0;


test_parameters_ = fig.UserData.OPs;

% test_parameters_file                = test_paramters_last     ;
% test_parameters_file.defaults_      = fig.UserData.OPs        ;
% test_parameters_essential = fig.UserData.OPs                 ;
% test_parameters_ = 
% test_parameters_file
close(fig)
% end %if fig_closed  == 0
end %function test_parameters_essential = get_test_parameters_essential(fig)



function fig =  bespoke_dialog_box2(do_LU,data_,defaults_,x_mult ,y_mult,mag_fac)


fig = uifigure('Resize','off','Units','normalized','Position',[0.05,0.05,0.2*mag_fac,0.3*mag_fac],'Name', 'Input Test Parameters');

fig.UserData.button_pressed  = 0     ;
fig.UserData.Warning_message =  '';
fig.UserData.spec_button_status = 1;  %  this is for the load last / re load defaults  - name toggle  button  1  or  2

%----------------------------------------------------------------------------------
%ROW 1
%----------------------------------------------------------------------------------

DD_4= uidropdown(fig,"Items",[data_.clamp_location_options ],'Position', [x_mult*10, y_mult*265, x_mult*100, y_mult*28 ],'FontSize',y_mult*18,'Value',data_.clamp_location_options{defaults_.clamp_location},"ValueChangedFcn",@(src,event)check_text_fields(fig));
lbl4 = uilabel(fig,'Position',[x_mult*10, y_mult*290, x_mult*100, y_mult*28],'Text', 'Clamp Loc','FontSize',y_mult*18,'FontColor',[0.9 0 0])                     ;

fig.UserData.labels.clamp_location  = lbl4;
fig.UserData.inps.clamp_location = DD_4;  

DD_2 =  uidropdown(fig,"Items",[data_.contact_wire_options],'Position', [x_mult*137,y_mult*265,x_mult*100,y_mult*28],'FontSize',y_mult*18,'Value',data_.contact_wire_options{defaults_.contact_wire},"ValueChangedFcn",@(src,event)check_text_fields(fig))  ;
lbl2 = uilabel(fig,'Position',[x_mult*137, y_mult*290, x_mult*100, y_mult*28],'Text', 'Wire Type','FontSize',y_mult*18,'FontColor',[0.9 0 0])                          ;

fig.UserData.labels.contact_wire   = lbl2;
fig.UserData.inps.contact_wire     = DD_2;


DD_3= uidropdown(fig,"Items",[data_.arm_present_options],'Position', [x_mult*260,y_mult*265,x_mult*100,y_mult*28],'FontSize',y_mult*18,'Value',data_.arm_present_options{defaults_.arm_present},"ValueChangedFcn",@(src,event)check_text_fields(fig))   ;
lbl3 = uilabel(fig,'Position',[x_mult*260, y_mult*290, x_mult*150, y_mult*28],'Text', 'Arm Present','FontSize',y_mult*18,'FontColor',[0.9 0 0])                        ;

fig.UserData.labels.arm_present   = lbl3;
fig.UserData.inps.arm_present = DD_3                                                                ;

%----------------------------------------------------------------------------------
%ROW 2
%----------------------------------------------------------------------------------

%DD_1= uidropdown(fig,"Items",[data_.Track_id_options],'Position', [x_mult*10,y_mult*200,x_mult*100,y_mult*28],'FontSize',y_mult*18,'Value', data_.Track_id_options{defaults_.Track_id});
%lbl = uilabel(fig,'Position',[x_mult*10 y_mult*225 x_mult*150 y_mult*28],'Text', 'Track ID','FontSize',y_mult*18)                           ;
%fig.UserData.inps.Track_id  = DD_1;    

txa_5     = uitextarea(fig,'Position' ,[x_mult*10,y_mult*200,x_mult*100,y_mult*28], 'Value', data_.Track_id_options{defaults_.Track_id}, 'FontSize',y_mult*18,"ValueChangedFcn",@(src,event)check_text_fields(fig))                                        ;
lbl10     = uilabel(fig,'Position',[x_mult*10, y_mult*225, x_mult*100, y_mult*28],'Text', 'Track ID','FontSize',y_mult*18,'FontColor',[0.9 0 0])                       ;


fig.UserData.labels.Track_id  = lbl10;
fig.UserData.inps.Track_id    = txa_5;

txa_5_DD  = uidropdown(fig,"Items",[data_.Track_id_options],'Position', fig.UserData.inps.Track_id.Position ,'Visible','off', 'FontSize' ,fig.UserData.inps.Track_id.FontSize ,'Value', data_.Track_id_options{defaults_.Track_id},'ValueChangedFcn',@(src,event)DD_A(fig,data_,defaults_));
fig.UserData.Track_id_DD      = txa_5_DD;

txa_4 = uitextarea(fig,'Position' ,[x_mult*137, y_mult*200, x_mult*100, y_mult*28], 'Value', data_.Asset_Number_options{defaults_.Asset_Number}, 'FontSize',y_mult*18,"ValueChangedFcn",@(src,event)check_text_fields(fig))                                        ;
lbl9 = uilabel(fig,'Position',[x_mult*137, y_mult*225, x_mult*100, y_mult*28],'Text', 'Asset No','FontSize',y_mult*18,'FontColor',[0.9 0 0])                       ;

fig.UserData.labels.Asset_no  = lbl9;
fig.UserData.inps.Asset_no  = txa_4;


txa_4_DD  = uidropdown(fig,"Items",[data_.Asset_Number_options],'Position', fig.UserData.inps.Asset_no.Position ,'Visible','off', 'FontSize' ,fig.UserData.inps.Asset_no.FontSize ,'Value', data_.Asset_Number_options{defaults_.Asset_Number},'ValueChangedFcn',@(src,event)DD_B(fig,data_,defaults_));
fig.UserData.Asset_no_DD      = txa_4_DD;

txa_3 = uitextarea(fig,'Position' ,[x_mult*260, y_mult*200, x_mult*100, y_mult*28], 'Value', data_.WR_options{defaults_.WR}, 'FontSize',y_mult*18,"ValueChangedFcn",@(src,event)check_text_fields(fig))                                        ;
lbl7 = uilabel(fig,'Position',[x_mult*260, y_mult*225, x_mult*100, y_mult*28],'Text', 'Wire Run','FontSize',y_mult*18,'FontColor',[0.9 0 0])                       ;

fig.UserData.labels.WR  = lbl7;
fig.UserData.inps.WR  = txa_3;

txa_3_DD  = uidropdown(fig,"Items",[data_.WR_options],'Position', fig.UserData.inps.WR.Position ,'Visible','off', 'FontSize' ,fig.UserData.inps.WR.FontSize ,'Value', data_.WR_options{defaults_.WR},'ValueChangedFcn',@(src,event)DD_C(fig,data_,defaults_));
fig.UserData.WR_DD      = txa_3_DD;

%--------------------------------------------------------------------------------------------------------------------------------------------------------------------
%ROW 3
%--------------------------------------------------------------------------------------------------------------------------------------------------------------------
txa_1 = uitextarea(fig,'Position' ,[x_mult*10, y_mult*140, x_mult*100, y_mult*28],'Value', data_.ELR_options{defaults_.ELR},'FontSize',y_mult*18,"ValueChangedFcn",@(src,event)check_text_fields(fig))                          ;
lbl5 = uilabel(fig,'Position',[x_mult*10, y_mult*165, x_mult*100, y_mult*28],'Text', 'ELR','FontSize',y_mult*18,'FontColor',[0.9 0 0])                                ;

fig.UserData.labels.ELR             = lbl5;
fig.UserData.inps.ELR              = txa_1;

txa_1_DD  = uidropdown(fig,"Items",[data_.ELR_options],'Position', fig.UserData.inps.ELR.Position ,'Visible','off', 'FontSize' ,fig.UserData.inps.ELR.FontSize ,'Value', data_.ELR_options{defaults_.ELR},'ValueChangedFcn',@(src,event)DD_D(fig,data_,defaults_));
fig.UserData.ELR_DD                = txa_1_DD;

txa_2 = uitextarea(fig,'Position' ,[x_mult*137, y_mult*140, x_mult*100, y_mult*28],'Value', data_.struct_id_options{defaults_.Structure_ID},'FontSize',y_mult*18,"ValueChangedFcn",@(src,event)check_text_fields(fig))                     ;
lbl6 = uilabel(fig,'Position',[x_mult*137, y_mult*165, x_mult*100, y_mult*28],'Text', 'Struct ID','FontSize',y_mult*18,'FontColor',[0.9 0 0])                      ;


fig.UserData.labels.Structure_ID             = lbl6  ;
fig.UserData.inps.Structure_ID               = txa_2 ;

txa_2_DD  = uidropdown(fig,"Items",[data_.struct_id_options],'Position', fig.UserData.inps.Structure_ID.Position ,'Visible','off', 'FontSize' ,fig.UserData.inps.Structure_ID.FontSize ,'Value', data_.struct_id_options{defaults_.Structure_ID},'ValueChangedFcn',@(src,event)DD_E(fig,data_,defaults_)) ;
fig.UserData.Structure_ID_DD      = txa_2_DD ;

%--------------------------------------------------------------------------------------------------------------------------------------------------------------------
%ROW 4
%--------------------------------------------------------------------------------------------------------------------------------------------------------------------
txa_4 = uitextarea(fig,'Position' ,[x_mult*15, y_mult*30, x_mult*230, y_mult*80],'Value',defaults_.Notes,'FontSize',y_mult*18)                               ;
lbl8 = uilabel(fig,'Position',[x_mult*15, y_mult*110, x_mult*150, y_mult*28],'Text', 'Notes','FontSize',y_mult*18)                              ;
fig.UserData.inps.Notes = txa_4;

%--------------------------------------------------------------------------------------------------------------------------------------------------------------------
but = uibutton(fig,"push" ,"Text","Submit",'Position',[x_mult*270, y_mult*30, x_mult*100, y_mult*50],'FontSize',y_mult*18,"ButtonPushedFcn", @(src,event)ButtonPushed(fig,data_));

% fig.but_spec1 = uibutton(fig,"push" ,"Text","Use Last",'sPosition',[270,30,100,55],'FontSize',18,"ButtonPushedFcn", @(src,event)ButtonPushed(fig,data_))   ;


%but2 =  uibutton(fig,"push" ,"Text","Last",'Position',[x_mult*270,y_mult*80,x_mult*100,y_mult*35],'FontSize',y_mult*18,"ButtonPushedFcn", @(src,event)ButtonPushed_special(fig,data_,defaults_,defaults_last));
%fig.UserData.inps.ren_but = but2;

but3 =  uibutton(fig,"push" ,"Text","Lookup",'Position',[x_mult*270,y_mult*90,x_mult*100,y_mult*35],'FontSize',y_mult*18,"ButtonPushedFcn", @(src,event)ButtonPushed_Lookup(fig,data_,defaults_,x_mult ,y_mult,mag_fac));
fig.UserData.inps.LU_but = but3;




if do_LU == 0
but3.Enable = 'off';
end

lbl9 = uilabel(fig,'Position',[x_mult*15,y_mult*1,x_mult*250,y_mult*35],'Text', 'Bespoke Settings ','FontSize', y_mult*14,'FontAngle', 'italic', 'Visible','on');
fig.UserData.inps.lookup_label = lbl9;


%--LU buttons----------------------------------------------------------------------------------------

%Track ID
but4 = uibutton(fig,"push" ,"Text","#",'Position',[x_mult*115, y_mult*210, x_mult*15, y_mult*15],'FontSize',y_mult*8,"ButtonPushedFcn", @(src,event)ButtonPushed_LU1(fig,data_,defaults_));
fig.UserData.inps.TID_but = but4;

%Asset No
but5 = uibutton(fig,"push" ,"Text","#",'Position',[x_mult*240, y_mult*210, x_mult*15, y_mult*15],'FontSize',y_mult*8,"ButtonPushedFcn", @(src,event)ButtonPushed_LU2(fig,data_,defaults_));
fig.UserData.inps.AN_but = but5;

%Wire run
but6 = uibutton(fig,"push" ,"Text","#",'Position',[x_mult*363, y_mult*210, x_mult*15, y_mult*15],'FontSize',y_mult*8,"ButtonPushedFcn", @(src,event)ButtonPushed_LU3(fig,data_,defaults_));
fig.UserData.inps.WR_but = but6;

%ELR
but7 = uibutton(fig,"push" ,"Text","#",'Position',[x_mult*115, y_mult*150, x_mult*15, y_mult*15],'FontSize',y_mult*8,"ButtonPushedFcn", @(src,event)ButtonPushed_LU4(fig,data_,defaults_));
fig.UserData.inps.ELR_but = but7;

%Struct_ID
but8 = uibutton(fig,"push" ,"Text","#",'Position',[x_mult*240, y_mult*150, x_mult*15, y_mult*15],'FontSize',y_mult*8,"ButtonPushedFcn", @(src,event)ButtonPushed_LU5(fig,data_,defaults_));
fig.UserData.inps.SID_but = but8;

check_text_fields(fig)

end %function bespoke_dialog_box(data_)



function check_text_fields(fig)

if strcmp(fig.UserData.inps.clamp_location.Value,'Unspec')
fig.UserData.labels.clamp_location.FontColor =  [0.9000 0 0];
else
fig.UserData.labels.clamp_location.FontColor = [0 0 0];
end %if strcmp(fig.UserData.inps.clamp_location.Value,'Unspec')
%
if strcmp(fig.UserData.inps.contact_wire.Value,'Unspec')
fig.UserData.labels.contact_wire.FontColor =   [0.9000 0 0];
else
fig.UserData.labels.contact_wire.FontColor = [0 0 0];
end %if strcmp(fig.UserData.inps.contact_wire.Value,'Unspec')
%
if strcmp(fig.UserData.inps.arm_present.Value,'Unspec')
fig.UserData.labels.arm_present.FontColor =   [0.9000 0 0];
else
fig.UserData.labels.arm_present.FontColor = [0 0 0];
end %if strcmp(fig.UserData.inps.arm_present.Value,'Unspec')
%
if strcmp(fig.UserData.inps.Track_id.Value,'Unspec')
fig.UserData.labels.Track_id.FontColor =   [0.9000 0 0];
else
fig.UserData.labels.Track_id.FontColor = [0 0 0];
end %if strcmp(fig.UserData.inps.arm_present.Value,'Unspec')
%
if strcmp(fig.UserData.inps.Asset_no.Value,'Unspec')
fig.UserData.labels.Asset_no.FontColor =   [0.9000 0 0];
else
fig.UserData.labels.Asset_no.FontColor = [0 0 0];
end %if strcmp(fig.UserData.inps.arm_present.Value,'Unspec')
%
if strcmp(fig.UserData.inps.WR.Value,'Unspec')
fig.UserData.labels.WR.FontColor =   [0.9000 0 0];
else
fig.UserData.labels.WR.FontColor = [0 0 0];
end %if strcmp(fig.UserData.inps.arm_present.Value,'Unspec')
%
if strcmp(fig.UserData.inps.ELR.Value,'Unspec')
fig.UserData.labels.ELR.FontColor =   [0.9000 0 0];
else
fig.UserData.labels.ELR.FontColor = [0 0 0];
end %if strcmp(fig.UserData.inps.arm_present.Value,'Unspec')
%
if strcmp(fig.UserData.inps.Structure_ID.Value,'Unspec')
fig.UserData.labels.Structure_ID.FontColor =   [0.9000 0 0];
else
fig.UserData.labels.Structure_ID.FontColor = [0 0 0];
end %if strcmp(fig.UserData.inps.arm_present.Value,'Unspec')
%

end  % ----------------------



%{
function ButtonPushed_special(fig,data_,df,dfl)
% load up the file from the roaming directory

% fig.spec_button_status = 1

switch(fig.UserData.spec_button_status)
    case(1)
fig.UserData.spec_button_status = 2;
fig.UserData.inps.ren_but.Text = 'Clear';
defaults_ = dfl;
    case(2)
fig.UserData.spec_button_status = 1;
fig.UserData.inps.ren_but.Text = 'Last';
defaults_ = df;
end  % switch(fig.spec_button_status)


fig.UserData.inps.Track_id.Value       =   data_.Track_id_options{(defaults_.Track_id)};
fig.UserData.inps.contact_wire.Value   =   data_.contact_wire_options{(defaults_.contact_wire)};
fig.UserData.inps.arm_present.Value    =   data_.arm_present_options{(defaults_.arm_present)};
fig.UserData.inps.clamp_location.Value =   data_.clamp_location_options{(defaults_.clamp_location)};

fig.UserData.inps.ELR.Value            =   defaults_.ELR           ;
fig.UserData.inps.Structure_ID.Value   =   defaults_.Structure_ID  ;
%fig.UserData.inps.milage.Value         =   defaults_.milage        ;
fig.UserData.inps.Notes.Value          =   defaults_.Notes         ;
end %function ButtonPushed2(fig,data_)
%}


function ButtonPushed_Lookup(fig,data_,defaults_,x_mult , y_mult,mag_fac)

fig.UserData.Track_id_DD.Visible = 'off';
fig.UserData.Asset_no_DD.Visible = 'off';
fig.UserData.WR_DD.Visible = 'off'; 
fig.UserData.ELR_DD.Visible = 'off';
fig.UserData.Structure_ID_DD.Visible = 'off'; 

fig.UserData.inps.TID_but.BackgroundColor = [0.9600,0.9600,0.9600];
fig.UserData.inps.AN_but.BackgroundColor = [0.9600,0.9600,0.9600];
fig.UserData.inps.WR_but.BackgroundColor = [0.9600,0.9600,0.9600];
fig.UserData.inps.ELR_but.BackgroundColor = [0.9600,0.9600,0.9600];
fig.UserData.inps.SID_but.BackgroundColor = [0.9600,0.9600,0.9600];

fig.UserData.inps.LU_but.BackgroundColor = [0.9600,0.6600,0.6600];
NS_struct = lookup_NS_details(x_mult ,y_mult,mag_fac);
fig.UserData.inps.LU_but.BackgroundColor = [0.9600,0.9600,0.9600];


if isstruct(NS_struct)
fig.UserData.inps.Track_id.Value       =  fig.UserData.Track_id_DD.Items{NS_struct. prop_inds(1)}   ;
fig.UserData.inps.Asset_no.Value       =  fig.UserData.Asset_no_DD.Items{ NS_struct. prop_inds(6)}  ;

fig.UserData.inps.WR.Value             =  fig.UserData.WR_DD.Items{NS_struct. prop_inds(5)}         ; 
fig.UserData.inps.ELR.Value            =  fig.UserData.ELR_DD.Items{NS_struct. prop_inds(4)}         ;   
fig.UserData.inps.Structure_ID.Value   =  fig.UserData.Structure_ID_DD.Items {NS_struct. prop_inds(3)}; 
fig.UserData.inps.contact_wire.Value   =  fig.UserData.inps.contact_wire.Items{NS_struct. prop_inds(2)};

fig.UserData.Track_id_DD.Value     = fig.UserData.Track_id_DD.Items{NS_struct. prop_inds(1)}       ;
fig.UserData.Asset_no_DD.Value     = fig.UserData.Asset_no_DD.Items{ NS_struct. prop_inds(6)}      ;
fig.UserData.WR_DD.Value           = fig.UserData.WR_DD.Items{NS_struct. prop_inds(5)}             ; 
fig.UserData.ELR_DD.Value          = fig.UserData.ELR_DD.Items{NS_struct. prop_inds(4)}            ;
fig.UserData.Structure_ID_DD.Value = fig.UserData.Structure_ID_DD.Items {NS_struct. prop_inds(3)}  ;


fig.UserData.inps.lookup_label.Visible = 'on'; 
fig.UserData.inps.lookup_label.Text    = [NS_struct.Loc,' (',NS_struct.sub_Loc,').'];
end   %if isstruct(NS_struct)

check_text_fields(fig)

end %function ButtonPushed_Lookup(fig,data_)


function ButtonPushed_LU1(fig,data_,defaults_)
%Track ID

switch(fig.UserData.Track_id_DD.Visible)
    case('off')    
fig.UserData.Track_id_DD.Visible = 'on';
fig.UserData.inps.TID_but.BackgroundColor = [0.9600,0.7600,0.7600];

    case('on')
fig.UserData.Track_id_DD.Visible = 'off';        
fig.UserData.inps.TID_but.BackgroundColor = [0.9600,0.9600,0.9600];




end %switch(fig.UserData.Track_id_DD.Visible)

end %function ButtonPushed_LU1(fig,data_)


function ButtonPushed_LU2(fig,data_,defaults_)
%Asset No

switch(fig.UserData.Asset_no_DD.Visible)
    case('off')    
fig.UserData.Asset_no_DD.Visible = 'on';
fig.UserData.inps.AN_but.BackgroundColor = [0.9600,0.7600,0.7600];

    case('on')
fig.UserData.Asset_no_DD.Visible = 'off';        
fig.UserData.inps.AN_but.BackgroundColor = [0.9600,0.9600,0.9600];

end

end %function ButtonPushed_LU1(fig,data_)


function ButtonPushed_LU3(fig,data_,defaults_)
%Wire run

switch(fig.UserData.WR_DD.Visible)
    case('off')    
fig.UserData.WR_DD.Visible = 'on';
fig.UserData.inps.WR_but.BackgroundColor = [0.9600,0.7600,0.7600];


    case('on')
fig.UserData.WR_DD.Visible = 'off';        
fig.UserData.inps.WR_but.BackgroundColor = [0.9600,0.9600,0.9600];

end




end %function ButtonPushed_LU1(fig,data_)

function ButtonPushed_LU4(fig,data_,defaults_)
%ELR
switch(fig.UserData.ELR_DD.Visible)
    case('off')    
fig.UserData.ELR_DD.Visible = 'on';
fig.UserData.inps.ELR_but.BackgroundColor = [0.9600,0.7600,0.7600];
    case('on')
fig.UserData.ELR_DD.Visible = 'off';        
fig.UserData.inps.ELR_but.BackgroundColor = [0.9600,0.9600,0.9600];

end %function ButtonPushed_LU4(fig,data_,defaults_)
end %function ButtonPushed_LU1(fig,data_)

function ButtonPushed_LU5(fig,data_,defaults_)

switch(fig.UserData.Structure_ID_DD.Visible)
    case('off')    
fig.UserData.Structure_ID_DD.Visible = 'on';
fig.UserData.inps.SID_but.BackgroundColor = [0.9600,0.7600,0.7600];
    case('on')
fig.UserData.Structure_ID_DD.Visible = 'off'; 
fig.UserData.inps.SID_but.BackgroundColor = [0.9600,0.9600,0.9600];

end
end %function ButtonPushed_LU1(fig,data_)

%---------------------------------------------------------------------------------------------------------------------------------------------------------
%---------------------------------------------------------------------------------------------------------------------------------------------------------
%---------------------------------------------------------------------------------------------------------------------------------------------------------


function DD_A(fig,data_,defaults_)
fig.UserData.inps.Track_id.Value = fig.UserData.Track_id_DD.Items(fig.UserData.Track_id_DD.ValueIndex);
fig.UserData.Track_id_DD.Visible = 'off'; 
fig.UserData.inps.TID_but.BackgroundColor = [0.9600,0.9600,0.9600];
check_text_fields(fig)
end

function DD_B(fig,data_,defaults_)
fig.UserData.inps.Asset_no.Value = fig.UserData.Asset_no_DD.Items(fig.UserData.Asset_no_DD.ValueIndex);
fig.UserData.Asset_no_DD.Visible = 'off';
fig.UserData.inps.AN_but.BackgroundColor = [0.9600,0.9600,0.9600];
check_text_fields(fig)
end

function DD_C(fig,data_,defaults_)
fig.UserData.inps.WR.Value = fig.UserData.WR_DD.Items(fig.UserData.WR_DD.ValueIndex);
fig.UserData.WR_DD.Visible = 'off';
fig.UserData.inps.WR_but.BackgroundColor = [0.9600,0.9600,0.9600];
check_text_fields(fig)
end

function DD_D(fig,data_,defaults_)
fig.UserData.inps.ELR.Value = fig.UserData.ELR_DD.Items(fig.UserData.ELR_DD.ValueIndex);
fig.UserData.ELR_DD.Visible = 'off';
fig.UserData.inps.ELR_but.BackgroundColor = [0.9600,0.9600,0.9600];
check_text_fields(fig)
end

function DD_E(fig,data_,defaults_)
fig.UserData.inps.Structure_ID.Value = fig.UserData.Structure_ID_DD.Items(fig.UserData.Structure_ID_DD.ValueIndex);
fig.UserData.Structure_ID_DD.Visible = 'off';
fig.UserData.inps.SID_but.BackgroundColor = [0.9600,0.9600,0.9600];
check_text_fields(fig)
end

function ButtonPushed(fig,data_)
Warning_message = [] ;
counter_ = 0 ;
OPs.ELR = upper(fig.UserData.inps.ELR.Value{1});

%{
if str2num(OPs.ELR) < str2num(data_.ELR_range_lower) || str2num(OPs.ELR) > str2num(data_.ELR_range_upper)
counter_ = counter_+1;
Warning_message{counter_} = 'ELR should be a 4 digit number';
end
else
counter_ = counter_+1;
Warning_message{counter_} = 'ELR should be a number';
%OPs.ELR = fig.UserData.inps.ELR.Value{1};
OPs.ELR = '';
%}

%{
if str2num( fig.UserData.inps.milage.Value{1})~=0
if isempty(find(fig.UserData.inps.milage.Value{1}=='.'))
counter_ = counter_+1;
OPs.milage =  fig.UserData.inps.milage.Value{1};
Warning_message{counter_} = 'Distance should have 2 nums after the dp';
else
if length(fig.UserData.inps.milage.Value{1})- find(fig.UserData.inps.milage.Value{1}=='.') ==2
OPs.milage =  fig.UserData.inps.milage.Value{1};
else
counter_ = counter_+1;
OPs.milage = fig.UserData.inps.milage.Value{1};
Warning_message{counter_} = 'Distance should have 2 nums after the dp';
end %if length(fig.UserData.inps.milage{1}- find(fig.UserData.inps.milage{1}--'.')) ~=2
end %if isempty(find(fig.UserData.inps.milage{1}=='.'))
else
counter_ = counter_+1;
OPs.milage = '';
%OPs.milage  = fig.UserData.inps.milage.Value{1};
Warning_message{counter_} = 'Distance should be a number';
end % if str2num( fig.UserData.inps.milage{1})~=0
%}


% Clamp Location -----------
if strcmp(fig.UserData.inps.clamp_location.Value,'Unspec')
counter_ = counter_+1;
Warning_message{counter_} = 'A value should be specified for clamp_location.';
end %if strcmp(fig.UserData.inps.clamp_location,'Unspec')
OPs.clamp_location      = fig.UserData.inps.clamp_location.Value;
% Clamp Location -----------

% Contact Wire -----------
if strcmp(fig.UserData.inps.contact_wire.Value,'Unspec')
counter_ = counter_+1;
Warning_message{counter_} = 'A value should be specified for contact_wire.';
end %if strcmp(fig.UserData.inps.contact_wire,'Unspec')
OPs.contact_wire        = fig.UserData.inps.contact_wire.Value;
% Contact Wire -----------

% Arm Present ------------
if strcmp(fig.UserData.inps.arm_present.Value,'Unspec')
counter_ = counter_+1;
Warning_message{counter_} = 'A value should be specified for arm_present.';
end %if strcmp(fig.UserData.inps.arm_present,'Unspec')
OPs.arm_present         = fig.UserData.inps.arm_present.Value;
% Arm Present ------------

% Track ID ---------------
if strcmp(fig.UserData.inps.Track_id.Value{1} ,'Unspec')
counter_ = counter_+1;
Warning_message{counter_} = 'A value should be specified for Track_id.';
end %if strcmp(fig.UserData.inps.Track_id,'Unspec')
OPs.Track_id            = fig.UserData.inps.Track_id.Value{1};
% Track ID ---------------

% Asset No ---------------
if strcmp(fig.UserData.inps.Asset_no.Value{1} ,'Unspec')
counter_ = counter_+1;
Warning_message{counter_} = 'A value should be specified for Asset No.';
end %
OPs.Asset_No            = fig.UserData.inps.Asset_no.Value{1};
% Asset No ---------------

% WR ---------------
if strcmp(fig.UserData.inps.WR.Value{1} ,'Unspec')
counter_ = counter_+1;
Warning_message{counter_} = 'A value should be specified for Wire Run';
end %
OPs.WR            = fig.UserData.inps.WR.Value{1};
% WR ---------------

% ELR ---------------
if strcmp(fig.UserData.inps.ELR.Value{1} ,'Unspec')
counter_ = counter_+1;
Warning_message{counter_} = 'A value should be specified for ELR';
end %
OPs.ELR            = fig.UserData.inps.ELR.Value{1};
% ELR ---------------

% Structure_ID ---------------
if strcmp(fig.UserData.inps.Structure_ID.Value{1} , 'Unspec')
counter_ = counter_+1;
Warning_message{counter_} = 'A value should be specified for Struct ID';
end %
OPs.Structure_ID            = fig.UserData.inps.Structure_ID.Value{1};
% Structure_ID ---------------

% Notes ---------
OPs.Notes =  fig.UserData.inps.Notes.Value{1};
% Notes ---------

OPs.LU_Label_text = fig.UserData.inps.lookup_label.Text;



fig.UserData.Warning_message = Warning_message;
fig.UserData.button_pressed = 1  ;
fig.UserData.OPs = OPs;

end %function ButtonPushedFcn(data_,login_name,txa)





