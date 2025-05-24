function   results_struct = lookup_NS_details(x_mult ,y_mult,mag_fac)
LU_Table              =     load([pwd,'\SETTINGS_FILES\NS_Details.mat'])   ;
fig = make_dialog_box(LU_Table,x_mult ,y_mult,mag_fac)                     ;
results_struct = get_LU_indeces_and_labels(fig)                            ; 
end    % function   NS_Indices = lookup_NS_details(x_mult ,y_mult,mag_fac)
% ---------------------------------------------------------

function results_struct = get_LU_indeces_and_labels (fig)
Btn_pressed        = 0;

while Btn_pressed == 0
drawnow()
if isvalid(fig)
Btn_pressed = fig.UserData.button_pushed;
else
results_struct = [];
return
end %if isvalid(fig)
end %while Btn_pressed == 0

if isvalid(fig)
results_struct.Loc        =     fig.UserData.Location          ;
results_struct.sub_Loc    =     fig.UserData.sub_Location      ;
results_struct.prop_inds  =     fig.UserData.property_inds     ;

close(fig)
end %if isvalid(fig)    
end %function results_struct = get_LU_indeces_and_labels


function fig = make_dialog_box(LU_Table,x_mult ,y_mult,mag_fac)
fig = uifigure('Resize','off','Units','normalized','Position', [0.225*mag_fac,0.11*mag_fac,0.16*mag_fac,0.16*mag_fac] ,'Name', 'Look up a specific location');
fig.Icon = 'ICON2.png';

default_Location_index = 12;
default_sub_Location_index = 1;

DD_1= uidropdown(fig,"Items",[LU_Table.Locations_],'Position', [x_mult*10, y_mult*95, x_mult*160, y_mult*28 ],'FontSize',y_mult*18,'Value',LU_Table.Locations_{default_Location_index},'ValueChangedFcn',@(src,event)DD_A(fig,LU_Table)    );
lbl1 = uilabel(fig,'Position',[x_mult*10, y_mult*125, x_mult*160, y_mult*28 ] ,'Text', 'Location:','FontSize',y_mult*18)  ;
fig.UserData.DD_1 = DD_1 ;

DD_2= uidropdown(fig,"Items",[LU_Table.Sublocations{default_Location_index}],'Visible','Off', 'Position', [x_mult*10, y_mult*25, x_mult*160, y_mult*28 ],'FontSize',y_mult*18,'Value',LU_Table.Sublocations{default_Location_index}{default_sub_Location_index});
lbl2 = uilabel(fig,'Position',[x_mult*10, y_mult*55, x_mult*160, y_mult*28 ] ,'Text', 'Sub Location:','Visible','Off','FontSize',y_mult*18)  ;
fig.UserData.DD_2 = DD_2 ;
fig.UserData.lbl2 = lbl2 ;
fig.UserData.wait_for_response = 1;
fig.UserData.button_pushed = 0;

but = uibutton(fig,"push" ,"Text","Look up",'Visible','Off','Position',[x_mult*190, y_mult*25, x_mult*100, y_mult*50],'FontSize',y_mult*18,"ButtonPushedFcn", @(src,event)ButtonPushed(fig,LU_Table));
fig.UserData.but = but;
end

function DD_A(fig,LU_Table)
fig.UserData.DD_2.Visible = 'On';
fig.UserData.lbl2.Visible = 'On';
fig.UserData.but.Visible = 'On' ;
index_temp =  (find(ismember(fig.UserData.DD_1.Items,  fig.UserData.DD_1.Value)));
fig.UserData.DD_2.Items = LU_Table.Sublocations{index_temp};
fig.UserData.index1 = index_temp;
end

function ButtonPushed(fig,LU_Table)
index_temp                 =  (find(ismember(fig.UserData.DD_2.Items,  fig.UserData.DD_2.Value))) ;
fig.UserData.index2        = index_temp                                                           ;
fig.UserData.Location      = LU_Table.Locations_{fig.UserData.index1}                             ;
fig.UserData.sub_Location  = LU_Table.Sublocations{fig.UserData.index1}{fig.UserData.index2}      ;
fig.UserData.property_inds = LU_Table.Values_{fig.UserData.index1}(:,fig.UserData.index2)         ;
fig.UserData.button_pushed = 1;
end  % function ButtonPushed(fig,LU_Table)
