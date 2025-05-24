function test_parameters_ = set_test_parameters_essential(varargin)
switch(nargin)

    case(0)    

FD_settings_path =                [pwd,'\SETTINGS_FILES\test_parameters2.mat']                   ; 
Settings_path    =                [getenv('APPDATA'),'\SETTINGS_FILES\test_parameters2.mat']     ;

[test_paramters_options , ~] =  load_mat_structure_from_file(FD_settings_path);
[test_paramters_last , ~]    =  load_mat_structure_from_file(Settings_path);

    case(5)

% FD_settings_path       =       varargin{2}  ; 
Settings_path          =       varargin{2}  ;
test_paramters_options =       varargin{1};
[test_paramters_last , ~] =  load_mat_structure_from_file(Settings_path);
base_width     = varargin{3}  ;
base_height    = varargin{4}  ;  
mag_fac        = varargin{5}  ; 

Pix_SS = get(0,'screensize')               ;
x_mult = (Pix_SS(3)/base_width)   * mag_fac;
y_mult = (Pix_SS(4)/base_height)  * mag_fac;

end %switch(nargin)

%keyboard

%test_parameters_essential = set_test_parameters_essential()

data_         =  test_paramters_options.data_       ;
defaults_     =  test_paramters_options.defaults_   ;
defaults_last =  test_paramters_last.defaults_      ;

[fig] = bespoke_dialog_box2(data_,defaults_,defaults_last,x_mult ,y_mult,mag_fac );

fig.Icon = 'ICON2.png';
[test_parameters_file,test_parameters_] = get_test_parameters_essential(fig,test_paramters_last);


% test_parameters_file

if isstruct(test_parameters_file)
%create_file_from_structure(test_parameters_file,Settings_path)  

OK_  =  save_mat_structure_to_file( test_parameters_file,Settings_path)  ; 

end % if isstruct(test_parameters_file)


% outpt  test_parameters_
% save   test_parameters_file
%-------------these should be inputs
end %function test_parameters_essential = set_test_parameters_essential()


function [test_parameters_file,test_parameters_]  = get_test_parameters_essential(fig,test_paramters_last)
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
test_parameters_.Track_id          =  test_paramters_last.data_.Track_id_options{fig.UserData.OPs.Track_id};
test_parameters_.contact_wire      =  test_paramters_last.data_.contact_wire_options{fig.UserData.OPs.contact_wire};
test_parameters_.arm_present       =  test_paramters_last.data_.arm_present_options{fig.UserData.OPs.arm_present};
test_parameters_.clamp_location    =  test_paramters_last.data_.clamp_location_options{fig.UserData.OPs.clamp_location};

test_parameters_file                = test_paramters_last     ;

test_parameters_file.defaults_      = fig.UserData.OPs        ;


% test_parameters_essential = fig.UserData.OPs                 ;
% test_parameters_ = 
% test_parameters_file
close(fig)
% end %if fig_closed  == 0
end %function test_parameters_essential = get_test_parameters_essential(fig)


function fig =  bespoke_dialog_box2(data_,defaults_,defaults_last,x_mult ,y_mult,mag_fac)



fig = uifigure('Resize','off','Units','normalized','Position',[0.05,0.05,0.2*mag_fac,0.3*mag_fac],'Name', 'Input Test Parameters');
fig.UserData.button_pressed  = 0     ;
fig.UserData.Warning_message =  '';
fig.UserData.spec_button_status = 1;  %  this is for the load last / re load defaults  - name toggle  button  1  or  2

%----------------------------------------------------------------------------------
%ROW 1
%----------------------------------------------------------------------------------
%keyboard
DD_1= uidropdown(fig,"Items",[data_.Track_id_options],'Position', [x_mult*15, y_mult*265, x_mult*100, y_mult*28],'FontSize',y_mult*18,'Value', data_.Track_id_options{defaults_.Track_id});
lbl = uilabel(fig,'Position',[x_mult*15, y_mult*290, x_mult*100, y_mult*28],'Text', 'Track ID','FontSize',y_mult*18)                           ;
fig.UserData.inps.Track_id  = DD_1                                                                 ;

DD_2 =  uidropdown(fig,"Items",[data_.contact_wire_options],'Position', [x_mult*145,y_mult*265,x_mult*100,y_mult*28],'FontSize',y_mult*18,'Value',data_.contact_wire_options{defaults_.contact_wire})  ;
fig.UserData.inps.contact_wire = DD_2;
lbl2 = uilabel(fig,'Position',[x_mult*145, y_mult*290, x_mult*100, y_mult*28],'Text', 'Wire Type','FontSize',y_mult*18)                          ;

DD_3= uidropdown(fig,"Items",[data_.arm_present_options],'Position', [x_mult*275,y_mult*265,x_mult*100,y_mult*28],'FontSize',y_mult*18,'Value',data_.arm_present_options{defaults_.arm_present})   ;
lbl3 = uilabel(fig,'Position',[x_mult*275, y_mult*290, x_mult*150, y_mult*28],'Text', 'Arm Present','FontSize',y_mult*18)                        ;
fig.UserData.inps.arm_present = DD_3                                                                ;
%----------------------------------------------------------------------------------
%ROW 2
%----------------------------------------------------------------------------------
DD_4= uidropdown(fig,"Items",[data_.clamp_location_options ],'Position', [x_mult*15,y_mult*200,x_mult*100,y_mult*28],'FontSize',y_mult*18,'Value',data_.clamp_location_options{defaults_.clamp_location})   ;
lbl4 = uilabel(fig,'Position',[x_mult*15 y_mult*225 x_mult*150 y_mult*28],'Text', 'Clamp Location','FontSize',y_mult*18)                     ;
fig.UserData.inps.clamp_location = DD_4                                                                   ;

%--------------------------------------------------------------------------------------------------------------------------------------------------------------------
%ROW 3
%--------------------------------------------------------------------------------------------------------------------------------------------------------------------

txa_1 = uitextarea(fig,'Position' ,[x_mult*15, y_mult*140, x_mult*100, y_mult*28],'Value',defaults_.ELR,'FontSize',y_mult*18)                          ;
lbl5 = uilabel(fig,'Position',[x_mult*15, y_mult*165, x_mult*100, y_mult*28],'Text', 'ELR','FontSize',y_mult*18)                                ;
fig.UserData.inps.ELR                = txa_1;

txa_2 = uitextarea(fig,'Position' ,[x_mult*145, y_mult*140, x_mult*100, y_mult*28],'Value',defaults_.Structure_ID,'FontSize',y_mult*18)                     ;
lbl6 = uilabel(fig,'Position',[x_mult*145, y_mult*165, x_mult*100, y_mult*28],'Text', 'Struct ID','FontSize',y_mult*18)                      ;
fig.UserData.inps.Structure_ID           = txa_2;

%txa_3 = uitextarea(fig,'Position' ,[x_mult*275, y_mult*140, x_mult*100, y_mult*28], 'Value', defaults_.milage, 'FontSize',y_mult*18)                                        ;
%lbl7 = uilabel(fig,'Position',[x_mult*275, y_mult*165, x_mult*100, y_mult*28],'Text', 'Dist(miles)','FontSize',y_mult*18)                       ;
%fig.UserData.inps.milage  = txa_3;


%--------------------------------------------------------------------------------------------------------------------------------------------------------------------
%ROW 4
%--------------------------------------------------------------------------------------------------------------------------------------------------------------------
txa_4 = uitextarea(fig,'Position' ,[x_mult*15, y_mult*20, x_mult*230, y_mult*90],'Value',defaults_.Notes,'FontSize',y_mult*18)                               ;
lbl8 = uilabel(fig,'Position',[x_mult*15, y_mult*110, x_mult*150, y_mult*28],'Text', 'Notes','FontSize',y_mult*18)                              ;
fig.UserData.inps.Notes = txa_4;


%--------------------------------------------------------------------------------------------------------------------------------------------------------------------
but = uibutton(fig,"push" ,"Text","Submit",'Position',[x_mult*270, y_mult*20, x_mult*100, y_mult*50],'FontSize',y_mult*18,"ButtonPushedFcn", @(src,event)ButtonPushed(fig,data_));

% fig.but_spec1 = uibutton(fig,"push" ,"Text","Use Last",'sPosition',[270,30,100,55],'FontSize',18,"ButtonPushedFcn", @(src,event)ButtonPushed(fig,data_))   ;
but2 =  uibutton(fig,"push" ,"Text","Last",'Position',[x_mult*295,y_mult*80,x_mult*65,y_mult*35],'FontSize',y_mult*18,"ButtonPushedFcn", @(src,event)ButtonPushed_special(fig,data_,defaults_,defaults_last));
fig.UserData.inps.ren_but = but2;

end %function bespoke_dialog_box(data_)

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

OPs.Notes =  fig.UserData.inps.Notes.Value{1} ;


if strcmp(fig.UserData.inps.Track_id.Value,'Unspec')
counter_ = counter_+1;
Warning_message{counter_} = 'A value should be specified for Track_id.';
end %if strcmp(fig.UserData.inps.Track_id,'Unspec')

if strcmp(fig.UserData.inps.contact_wire.Value,'Unspec')
counter_ = counter_+1;
Warning_message{counter_} = 'A value should be specified for contact_wire.';
end %if strcmp(fig.UserData.inps.contact_wire,'Unspec')

if strcmp(fig.UserData.inps.arm_present.Value,'Unspec')
counter_ = counter_+1;
Warning_message{counter_} = 'A value should be specified for arm_present.';
end %if strcmp(fig.UserData.inps.arm_present,'Unspec')

if strcmp(fig.UserData.inps.clamp_location.Value,'Unspec')
counter_ = counter_+1;
Warning_message{counter_} = 'A value should be specified for clamp_location.';
end %if strcmp(fig.UserData.inps.clamp_location,'Unspec')


%new_vals_.SR_index  = find(ismember(fig.UserData.inps.DD_1.Items,  fig.UserData.inps.DD_1.Value));

OPs.Track_id            = (find(ismember(data_.Track_id_options,  fig.UserData.inps.Track_id.Value)));
OPs.contact_wire        = (find(ismember(data_.contact_wire_options,  fig.UserData.inps.contact_wire.Value)));

OPs.Structure_ID        = fig.UserData.inps.Structure_ID.Value{1};

OPs.arm_present         = (find(ismember(data_.arm_present_options,  fig.UserData.inps.arm_present.Value)));
OPs.clamp_location      = (find(ismember(data_.clamp_location_options, fig.UserData.inps.clamp_location.Value)));

fig.UserData.Warning_message = Warning_message;
fig.UserData.button_pressed = 1  ;
fig.UserData.OPs = OPs;
end %function ButtonPushedFcn(data_,login_name,txa)
