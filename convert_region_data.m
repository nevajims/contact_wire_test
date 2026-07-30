function [] = convert_region_data()
%------------To Do-------------------------To Do-------------------------To Do-------------
% put in an option to remove a region from he existing --  

% two options 
%(1) add a new region or replace an existing regioon
%(2) remove a region from the files and re save the xls spreadsheet


% save_the_settings_files_and_create_backups
% create_updated_xls_spreadsheet
%------------To Do-------------------------To Do-------------------------To Do-------------
settings_dir = 'D:\githubs\contact_wire_test\SETTINGS_FILES'   ; % may need to be changed to pwd
roaming_settings_dir =  [getenv('APPDATA'),'\SETTINGS_FILES']  ;
xls_spreadsheet_dir = 'D:\githubs\contact_wire_test'           ; 

input_file ='Region_data';
[status,sheets_] = xlsfinfo(input_file); 

if strcmp(status,'Microsoft Excel Spreadsheet')

[eligable_regions,unused_sheets] = find_eligable_regions(sheets_) ;
[new_data_table_format] =  select_regions_and_load_data(eligable_regions,input_file)            ; 
[existing_data,NS_indices] = get_existing_data(new_data_table_format)                           ;
updated_data  =   update_settings_files ( existing_data , NS_indices , new_data_table_format )  ;

% TO DO -------------------
% save_the_settings_files_and_create_backups(updated_data,settings_dir,roaming_settings_dir) ;

create_updated_xls_spreadsheet(updated_data)                      ;

% TO DO ------------------- 

else
disp('incorrect file format')    
end %if strcmp(status,'Microsoft Excel Spreadsheet')
end  % function [] = convert_region_data()
%-------------------------------------------------------------------------------------------
%-------------------------------------------------------------------------------------------


function save_the_settings_files_and_create_backups(updated_data , settings_dir , roaming_settings_dir)          

p_w_d = pwd;

cd(settings_dir);

% dos('rename login_options3.mat login_options3_OV.mat')
% dos('rename advanced_settings.mat advanced_settings_OV.mat')
% dos('rename NS_Details2.mat NS_Details2_OV.mat')
% dos('rename test_parameters3.mat test_parameters3_OV.mat')

% (2)  Save the files 

save advanced_settings.mat updated_data.advanced_settings ;
save login_options3_test.mat updated_data.login_options   ;
save test_parameters3.mat updated_data.test_parameters    ;
save NS_Details2.mat updated_data.NS_Details              ; 
% save the files

% (3)  delete the roaming files so they are written over
cd(roaming_settings_dir)
dos('delete login_options3.mat')
dos('delete advanced_settings.mat')
dos('delete NS_Details2.mat')
dos('delete test_parameters3.mat')

cd(p_w_d)

end %function save_the_settings_files_and_create_backups(updated_data)          

function  create_updated_xls_spreadsheet(updated_data)                      
keyboard
% https://www.mathworks.com/help/matlab/import_export/exporting-to-excel-spreadsheets.html


% To Do
% (1)  Rename the existing file (Region_data__old.xlsx')
% (2) create the table
% (3) identify the section name (as the tab name)

% (4)  Save the new file (Region_data.xlsx')

disp('To Do')
end %function  create_updated_xls_spreadsheet(updated_data)                      


function updated_data  =   update_settings_files(existing_data , NS_indices , new_data_table_format)
% existing_data.advanced_settings
updated_data.advanced_settings     =    existing_data.advanced_settings          ;
updated_data.login_options         =    existing_data.login_options              ;
updated_data.test_parameters       =    existing_data.test_parameters            ;
updated_data.NS_Details            =    existing_data.NS_Details                 ;


for index = 1:length(NS_indices.new_regions)
updated_data.advanced_settings.options.Region_options{NS_indices.regions_to_use(index,2)} = NS_indices.new_regions{NS_indices.regions_to_use(index,1)};
eval(['dummy = cell2mat(new_data_table_format.',NS_indices.new_regions{NS_indices.regions_to_use(index,1)},'.op_struct.Sentinal)'';'])
dummy = [dummy;150270;140968];
updated_data.login_options.Login_ID_arr{NS_indices.regions_to_use(index,2)} = dummy ;

eval(['dummy = new_data_table_format.',NS_indices.new_regions{NS_indices.regions_to_use(index,1)},'.op_struct.Name'';'])
dummy{length(dummy) +1} ='Mark Evans';
dummy{length(dummy) +1} ='Jim Evans';
updated_data.login_options.Name_arr{NS_indices.regions_to_use(index,2)} = dummy;

eval(['dummy = cell2mat(new_data_table_format.',NS_indices.new_regions{NS_indices.regions_to_use(index,1)},'.op_struct.Level)'';'])
dummy = [dummy;2;2];
updated_data.login_options.level_arr{NS_indices.regions_to_use(index,2)} = dummy;

eval(['dummy = new_data_table_format.',NS_indices.new_regions{NS_indices.regions_to_use(index,1)},'.op_struct.PW'';'])
dummy{length(dummy) +1} ='dh';
dummy{length(dummy) +1} ='dh';
updated_data.login_options.PW_arr{NS_indices.regions_to_use(index,2)} = dummy;




eval(['dummy_1 = new_data_table_format.',NS_indices.new_regions{NS_indices.regions_to_use(index,1)},'.NS_struct.neutral_section_names'';'])
dummy_2 = unique(dummy_1);
dummy_2 = [dummy_2;{'Unspecified'}];
updated_data.NS_Details.Locations_arr{NS_indices.regions_to_use(index,2)} = dummy_2;

eval(['dummy_3 = new_data_table_format.',NS_indices.new_regions{NS_indices.regions_to_use(index,1)},'.NS_struct.Sub_Names'';'])
temp_vals_array = [];

eval(['track_id_temp = new_data_table_format.',NS_indices.new_regions{NS_indices.regions_to_use(index,1)},'.NS_struct.track_ID'';'])
eval(['wire_size_temp = new_data_table_format.',NS_indices.new_regions{NS_indices.regions_to_use(index,1)},'.NS_struct.wire_size'';'])
eval(['structure_temp = new_data_table_format.',NS_indices.new_regions{NS_indices.regions_to_use(index,1)},'.NS_struct.structure'';'])
eval(['ELR_temp = new_data_table_format.',NS_indices.new_regions{NS_indices.regions_to_use(index,1)},'.NS_struct.ELR'';'])
eval(['Wire_run_number_temp = new_data_table_format.',NS_indices.new_regions{NS_indices.regions_to_use(index,1)},'.NS_struct.Wire_run_number'';'])
eval(['Asset_Number_temp = new_data_table_format.',NS_indices.new_regions{NS_indices.regions_to_use(index,1)},'.NS_struct.Asset_Number;'])


for index_2 = 1: length(dummy_2)
indices_ = find(ismember(dummy_1,dummy_2{index_2})==1);

if index_2 ~= length(dummy_2)
updated_data.NS_Details.Sublocations_arr{NS_indices.regions_to_use(index,2)}{index_2} = {dummy_3{indices_}}';
else
updated_data.NS_Details.Sublocations_arr{NS_indices.regions_to_use(index,2)}{index_2} = {'Unspecified'};    
end

for index_3 = 1:length(indices_)
%  track_ID // wire_size // structure // ELR // Wire_run_number // Asset_Number
temp_vals_array{index_2}{index_3} = {track_id_temp{indices_(index_3)},wire_size_temp{indices_(index_3)},structure_temp{indices_(index_3)},ELR_temp{indices_(index_3)},Wire_run_number_temp{indices_(index_3)},Asset_Number_temp{indices_(index_3)}}; 
end %for index_3 = 1:length(indices_)

end %for index_2 = 1: length(dummy_2)

updated_data.test_parameters.data_arr{NS_indices.regions_to_use(index,2)}.Track_id_options                 =  existing_data.test_parameters.data_arr{1}.Track_id_options        ;
updated_data.test_parameters.data_arr{NS_indices.regions_to_use(index,2)}.clamp_location_options           =  existing_data.test_parameters.data_arr{1}.clamp_location_options  ;
updated_data.test_parameters.data_arr{NS_indices.regions_to_use(index,2)}.arm_present_options              =  existing_data.test_parameters.data_arr{1}.arm_present_options     ;
updated_data.test_parameters.data_arr{NS_indices.regions_to_use(index,2)}.contact_wire_options             =  existing_data.test_parameters.data_arr{1}.contact_wire_options    ;

eval(['dummy = new_data_table_format.',NS_indices.new_regions{NS_indices.regions_to_use(index,1)},'.NS_struct.structure'';'])
dummy = unique(dummy);
dummy = [{'Unspec'};dummy]';

updated_data.test_parameters.data_arr{NS_indices.regions_to_use(index,2)}.struct_id_options = dummy;

eval(['dummy = new_data_table_format.',NS_indices.new_regions{NS_indices.regions_to_use(index,1)},'.NS_struct.ELR'';'])
dummy = unique(dummy);
dummy = [{'Unspec'};dummy]';

updated_data.test_parameters.data_arr{NS_indices.regions_to_use(index,2)}.ELR_options = dummy;

eval(['dummy = new_data_table_format.',NS_indices.new_regions{NS_indices.regions_to_use(index,1)},'.NS_struct.Wire_run_number'';'])
dummy = unique(dummy)  ;
dummy = [{'Unspec'};dummy]';

updated_data.test_parameters.data_arr{NS_indices.regions_to_use(index,2)}.WR_options = dummy  ;

eval(['dummy = new_data_table_format.',NS_indices.new_regions{NS_indices.regions_to_use(index,1)},'.NS_struct.Asset_Number;'])
dummy = unique(dummy);
dummy = [{'Unspec'} ; dummy]';
updated_data.test_parameters.data_arr{NS_indices.regions_to_use(index,2)}.Asset_Number_options = dummy                                                               ;

temp_Track_id_options       =  updated_data.test_parameters.data_arr{NS_indices.regions_to_use(index,2)}.Track_id_options                                            ;
temp_contact_wire_options   =  updated_data.test_parameters.data_arr{NS_indices.regions_to_use(index,2)}.contact_wire_options                                        ;
temp_struct_id_options      =  updated_data.test_parameters.data_arr{NS_indices.regions_to_use(index,2)}.struct_id_options                                           ;
temp_ELR_options            =  updated_data.test_parameters.data_arr{NS_indices.regions_to_use(index,2)}.ELR_options                                                 ;
temp_WR_options             =  updated_data.test_parameters.data_arr{NS_indices.regions_to_use(index,2)}.WR_options                                                  ;
temp_Asset_Number_options   =  updated_data.test_parameters.data_arr{NS_indices.regions_to_use(index,2)}.Asset_Number_options                                        ;
temp_options                =  {temp_Track_id_options,temp_contact_wire_options,temp_struct_id_options,temp_ELR_options,temp_WR_options,temp_Asset_Number_options}   ;

for index_1 = 1:length(temp_vals_array)

temp_index_array = zeros(6,length(temp_vals_array{index_1}));
for index_2 = 1:length(temp_vals_array{index_1})
for index_3 = 1:length(temp_vals_array{index_1}{index_2})
temp_index_array(index_3,index_2) = find(ismember(temp_options{index_3},temp_vals_array{index_1}{index_2}{index_3})==1);
end % for index_3 = 1:length(temp_vals_array{index_1}{index_2})    
end %^for index_2 = 1:length(temp_vals_array{index_1})
% assign temp index array into the correct place -  check it with the other
% carlisle

updated_data.NS_Details.Values_arr{NS_indices.regions_to_use(index,2)}{index_1} = temp_index_array;
% assign temp index array into the correct place
end %for index_1 = 1:length(temp_vals_array)    
% now check the index values are correct
end %for index = 1:length(NS_indices.new_regions)




end  %function updated_data  =   update_settings_files(existing_data ,NS_indices,new_data_table_format)


function[ existing_data , NS_indices ] = get_existing_data(new_data_table_format)

existing_data.login_options      = load('SETTINGS_FILES\login_options3.mat')        ;
existing_data.advanced_settings  = load('SETTINGS_FILES\advanced_settings.mat')     ;
existing_data.NS_Details         = load('SETTINGS_FILES\NS_Details2.mat')           ;
existing_data.test_parameters    = load('SETTINGS_FILES\test_parameters3.mat')           ;
new_regions = fields(new_data_table_format)                                         ;

existing_region_options  = existing_data.advanced_settings.options.Region_options   ;

regions_to_use = [];
for index = 1:length(new_regions)
% create a nx2 matrix of regions to use with (index in new_regions,index in existing_data.advanced_settings.options.Region_options)

if sum(ismember(existing_region_options,new_regions)) == 0
ans__ =questdlg([new_regions{index}, ': This is a new region, include it?']);
if strcmp(ans__ ,'Yes')
%---------------------------------
regions_to_use(size(regions_to_use,1)+1,:) = [index,length(existing_region_options) + 1 ];
%---------------------------------
end %if strcmp(ans__ ,'Yes')

elseif sum(ismember(existing_region_options,new_regions)) == 1
ans__ =questdlg([new_regions{index}, ': existing region, replce it?']);

if strcmp(ans__ ,'Yes')
%---------------------------------
regions_to_use(size(regions_to_use,1)+1,:) = [index, find(ismember(existing_region_options,new_regions)==1)];
%---------------------------------
end %if strcmp(ans__ ,'Yes')
else
disp('Problem there appears to be tp fields with the same name in existing regions (should get  this)')
end %if sum(ismember(existing_region_options,new_regions)) == 0
end %for index = 1:length(new_regions)
existing_data.existing_region_options = existing_region_options ;
NS_indices.new_regions                = new_regions             ;
NS_indices.regions_to_use             = regions_to_use          ;
end  %function[existing_data,NS_indices] = get_existing_data(new_data_tf)


function [eligable_regions,unused_sheets] = find_eligable_regions(sheets_)
% create two lists on NS_List the other operator_list
NS_regions        =   [] ;
operator_regions  =   [] ; 
unused_sheets     =   [] ;

for index= 1:length(sheets_)
if strcmp(sheets_{index}(end-2:end),'_NS')
NS_regions{length(NS_regions)+1}                = sheets_{index}(1:end-3);

elseif length(sheets_{index}) >= 10
if strcmp(sheets_{index}(end-9:end),'_operators')     
operator_regions{length(operator_regions)+1}    =  sheets_{index}(1:end-10);
else
unused_sheets{length(unused_sheets)+1} = sheets_{index};
end
else
unused_sheets{length(unused_sheets)+1} = sheets_{index};
% do nothing
end %if strcmp(sheets_{index}(end-2:end),'_NS')    
end %for index= 1:length(sheets_)


eligable_regions=[];

for index= 1 : length(operator_regions)
if sum((ismember(NS_regions,operator_regions{1})))
eligable_regions{length(eligable_regions)+1} = operator_regions{index}; 
end  %for index = 1:length(operator_regions)
end
end  % function find_eligable_regions(sheets_)




function [data] =  select_regions_and_load_data(eligable_regions,input_file)

data      =  [];
[indx,OK] =  listdlg('PromptString','Select region(s)','SelectionMode','multiple','ListString', eligable_regions);

if OK ==1
for index = 1:length(indx)
current_region = eligable_regions{indx(index)};

NS_sheet = [ current_region , '_NS'          ];
op_sheet = [ current_region , '_operators'   ];

% disp(NS_sheet)
% disp(op_sheet)
% now load the data from the sheets

op_table = readtable(input_file,'UseExcel',true,'Sheet',op_sheet)   ;
NS_table = readtable(input_file,'UseExcel',true,'Sheet',NS_sheet)   ;

temp_struct = table2struct(op_table)      ;
temp_struct2 = table2struct(NS_table)     ;


[msg,OK2 ]  = check_correct_fields(temp_struct,temp_struct2);

if OK2 ==1
op_struct.Level                 = {temp_struct.Level}       ;
op_struct.PW                    = {temp_struct.PW}          ;
op_struct.Sentinal              = {temp_struct.Sentinal}    ;
op_struct.Name                  = {temp_struct.Name}        ;

NS_struct.neutral_section_names =  {temp_struct2.neutral_section_names}  ;
NS_struct.Sub_Names             =  {temp_struct2.Sub_Names}              ;

NS_struct.track_ID              =  arrayfun(@num2str, [temp_struct2.track_ID]', 'UniformOutput', 0)     ;
NS_struct.wire_size             =  arrayfun(@num2str, [temp_struct2.wire_size]', 'UniformOutput', 0)    ;
NS_struct.structure             =  {temp_struct2.structure}                                             ;
NS_struct.ELR                   =  {temp_struct2.ELR}                                                   ;
NS_struct.Wire_run_number       =  {temp_struct2.Wire_run_number}                                       ;
NS_struct.Asset_Number          =  arrayfun(@num2str, [temp_struct2.Asset_Number]', 'UniformOutput', 0) ; 

eval(['data.',current_region,'.NS_struct = NS_struct;'])
eval(['data.',current_region,'.op_struct = op_struct;']) 

clear NS_struct; clear op_struct ; 
else
disp(msg)
end %if OK2 ==1
clear temp_struct; clear temp_struct2
end %for index = 1:length(indx)   

else    
disp('no selection made')
end % if OK ==1

end %function [data] =  select_regions_and_load_data(eligable_regions)

function [msg , OK2]  = check_correct_fields(temp_struct,temp_struct2)


if length(temp_struct) ~= 0 && length(temp_struct2) ~= 0

msg = 'Missing Fields (NS): ';
temp_struct_val  = 0;
temp_struct2_val = 0;


if isfield(temp_struct2,'neutral_section_names')
temp_struct2_val = temp_struct2_val + 1 ;
else
msg = [msg,', neutral section name'];
end %if isfield(temp_struct2,'neutral_section_names')

if isfield(temp_struct2,'Sub_Names')
temp_struct2_val = temp_struct2_val + 1 ;
else
msg = [msg,', Sub_Names'];
end %if isfield(temp_struct2,'Sub_Names')

if isfield(temp_struct2,'track_ID')
temp_struct2_val = temp_struct2_val + 1 ;
else
msg = [msg,', track_ID'];
end%if isfield(temp_struct2,'track_ID')

if isfield(temp_struct2,'wire_size')
temp_struct2_val = temp_struct2_val + 1 ;
else
msg = [msg,', wire_size'];
end

if isfield(temp_struct2,'structure')
temp_struct2_val = temp_struct2_val + 1 ;
else
msg = [msg,', structure'];
end

if isfield(temp_struct2,'ELR')
temp_struct2_val = temp_struct2_val + 1 ;
else
msg = [msg,', ELR'];
end

if isfield(temp_struct2,'Wire_run_number')
temp_struct2_val = temp_struct2_val + 1 ;
else
msg = [msg,', Wire_run_number'];
end

if isfield(temp_struct2,'Asset_Number')
temp_struct2_val = temp_struct2_val + 1 ;
else
msg = [msg,', Asset_Number'];
end

msg = [msg, 'Missing Fields (login): ']; 

if isfield(temp_struct,'Name')
temp_struct_val = temp_struct_val + 1 ;
else
msg = [msg,', Name'];
end

if isfield(temp_struct,'Sentinal')
temp_struct_val = temp_struct_val + 1 ;
else
msg = [msg,', Sentinal'];
end

if isfield(temp_struct,'Level')
temp_struct_val = temp_struct_val + 1 ;
else
msg = [msg,', Level'];
end

if isfield(temp_struct,'PW')
temp_struct_val = temp_struct_val + 1 ;
else
msg = [msg,', PW'];
end

if temp_struct2_val == 8 && temp_struct_val ==4
OK2 = 1;
else
OK2 = 0;
end %if temp_struct_val == 8 && temp_struct2_val ==4

else
msg = '1 or more structure is empty';
OK2 = 0;
end %if length(temp_struct) ~= 0 && if length(temp_struct2) ~= 0

end %function [msg , OK2]  = check_correct_fields(temp_struct,temp_struct2)



