function [value_] = login_window(varargin)

%  logn_data
%  'ICON1.ico'
%  temp_code

switch (nargin)
    case(0)
login_path =  [pwd,'\SETTINGS_FILES\login_options2.mat']; 
fields_ = {'Login_ID','Name','PW','level'};
[data_ , ~] =  load_mat_structure_from_file(login_path,fields_);
Pix_SS = get(0,'screensize')              ;
x_mult = (Pix_SS(3)/1920)   ;
y_mult = (Pix_SS(4)/1080 )  ;
mag_fac   =   1;
    case(4)
data_ = varargin{1};
base_width = varargin{2};
base_height = varargin{3};
mag_fac   = varargin{4};

Pix_SS = get(0,'screensize')                ;
x_mult = (Pix_SS(3)/base_width)   * mag_fac ;
y_mult = (Pix_SS(4)/base_height)  * mag_fac ;
           

end %switch (nargin)

[fig] = bespoke_dialog_box(data_,x_mult,y_mult,mag_fac);
fig.Icon = 'ICON2.png';

%fig.Position = [500 500 1000 445];
%pathToMLAPP = fileparts(mfilename('fullpath'));
%fig.Icon = fullfile(pathToMLAPP, 'P:\GITHUBS\contact_AI\ICON1.png');

%keyboard

%temp_code

succes_tmp = 0;

while succes_tmp == 0
drawnow()

if isvalid(fig)
succes_tmp = fig.UserData.LI_success;
else
value_.values_set   = 0;
value_.Name         = 'not set';
value_.Sentinal_no  = 'not set';
value_.Level        = 'not set';
return
end %if ~isempty(fig)


if fig.UserData.attmp_counter  > 3
succes_tmp = 1;
end %if fig.UserData.attmp_counter  == 4
end %while fig.UserData.LI_success == 0

if fig.UserData.attmp_counter  >3 &&  fig.UserData.LI_success == 0
aa = msgbox('Maximum of 3 attemps');
pause(1)
close (aa)
end %if fig.UserData.attmp_counter  == 4

if  fig.UserData.user_index ~= 0
value_.values_set   = 1;
value_.Name         = data_.Name{fig.UserData.user_index};
value_.Sentinal_no  = data_.Login_ID(fig.UserData.user_index);
value_.Level        = data_.level(fig.UserData.user_index);
else
value_.values_set   = 0;
value_.Name         = 'not set';
value_.Sentinal_no  = 'not set';
value_.Level        = 'not set';
end %if  fig.UserData.user_index ~= 0

%fig.UserData
close(fig)
% value_
end %function [value_] = login_window()

function fig =  bespoke_dialog_box(data_,x_mult,y_mult,mag_fac)

fig                                  = uifigure('Resize','off','Units','normalized','Position',[0.05,0.05,0.2*mag_fac,0.3*mag_fac],'Name', 'LOGIN' )    ;

%fig                                  = uifigure('Resize','off','Units','normalized','Position',[0.1,0.1,0.6,0.4],'Name', 'LOGIN' )    ;
fig.UserData.LI_success              =  0                                                                                             ;
fig.UserData.attmp_counter           =  0                                                                                             ;
fig.UserData.user_index              =  0                                                                                             ; 

lbla = uilabel(fig,'Position',[50*x_mult, 250*y_mult, 200*x_mult, 22*y_mult],'Text', 'Select Username');
lbla.FontSize = 16*y_mult;
login_name = uidropdown(fig,"Items",[data_.Name],'Position',[50*x_mult 200*y_mult 200*x_mult 44*y_mult]);
login_name.FontSize = 14*y_mult;

%user_index =  find(ismember(data_.Name,login_name.Value));
txa = uitextarea(fig,'Position' , [50*x_mult, 100*y_mult, 200*x_mult,30*y_mult]);
txa.FontSize = 14*y_mult;

lbl = uilabel(fig,'Position',[50*x_mult, 135*y_mult, 200*x_mult, 22*y_mult],'Text', 'Enter Password') ;
lbl.FontSize = 16*y_mult;

but = uibutton(fig,"push" ,"Text","Login","FontSize",ceil(16 * y_mult),'Position',[270*x_mult,100*y_mult,100*x_mult,35*y_mult],"ButtonPushedFcn", @(src,event)ButtonPushed(txa ,data_,login_name,fig));


end %function bespoke_dialog_box(data_)


function ButtonPushed(txa,data_,login_name,fig)
user_index =  find(ismember(data_.Name,login_name.Value));
data_.PW{user_index};
dum =txa.Value;


if strcmp(lower(data_.PW{user_index}),lower(dum{1}))==1
fig.UserData.LI_success = 1;
fig.UserData.user_index = user_index;

% put the login details here 
else
fig.UserData.attmp_counter = fig.UserData.attmp_counter + 1;

if fig.UserData.attmp_counter <= 3
aa = msgbox(['incorrect password ( Attempt #',num2str(fig.UserData.attmp_counter),')']);
pause(1)
close (aa)
end %if fig.UserData.attmp_counter <= 3

end %if strcmp(data_.PW{user_index},dum{1})==1

end %function ButtonPushedFcn(data_,login_name,txa)












