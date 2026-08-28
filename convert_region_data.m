function [] = convert_region_data()
%------------To Do-------------------------To Do-------------------------To Do-------------
% Do a full test to make sure its workng properly
% make into a small compiled app
% try replacing a region with some bits swapped out to check its working
%------------To Do-------------------------To Do-------------------------To Do-------------

settings_dir             =    'D:\githubs\contact_wire_test\SETTINGS_FILES'      ;    
roaming_settings_dir     =    [getenv('APPDATA'),'\SETTINGS_FILES']              ;

% xls_spreadsheet_dir = 'D:\githubs\contact_wire_test'           ; 
% select the xls file to input from
%select an excel file

opts.Default = 'Exit';opts.Interpreter = 'tex';
Answer__ = questdlg('Add or Remove Regions?', 'What to Do? ', 'Add','Remove','Exit',opts);

switch(Answer__)
    case('Add')    
[input_file, OK] = uigetfile('*.xlsx','Choose the xls file');

if (OK)
[status,sheets_] = xlsfinfo(input_file); 
if strcmp(status,'Microsoft Excel Spreadsheet')
[eligable_regions,unused_sheets] = find_eligable_regions(sheets_) ;
[new_data_table_format,done_] =  select_regions_and_load_data(eligable_regions,input_file)      ; 

if done_ ==1
[existing_data] = get_existing_data();
[NS_indices] = select_what_to_add_or_replace(new_data_table_format,existing_data);

if ~isempty(NS_indices.regions_to_use)
updated_data  =   update_settings_files ( existing_data , NS_indices , new_data_table_format )  ;
save_settings =1;
try
create_updated_xls_spreadsheet(updated_data)                                                    ;
catch
disp('problem saving in excel file Region_data_UD.xlsx - make sure it isnt open')    
save_settings =0;    
end

if save_settings ==1    
save_the_settings_files_and_create_backups(updated_data,settings_dir,roaming_settings_dir)      ;
end%if save_settings ==1    

else
disp('no new data added')    
end %if ~isempty(NS_indices.regions_to_use)
else
disp('no data loaded')    
end% if done_ ==1
else
disp('incorrect file format')    
end %if strcmp(status,'Microsoft Excel Spreadsheet')
else
disp('no file chosen')        
end  %if (OK)

  case('Remove')

[existing_data] = get_existing_data();
[Region_indx,OK__] = listdlg('PromptString','Select a Region to remove','ListString', existing_data.advanced_settings.options.Region_options);

if OK__
updated_data =  Remove_region(Region_indx,existing_data);
save_settings =1;

try
create_updated_xls_spreadsheet(updated_data)                                              ;
catch
disp('problem saving in excel file Region_data_UD.xlsx - make sure it isnt open')    
save_settings =0;    
end

if save_settings ==1    
save_the_settings_files_and_create_backups(updated_data,settings_dir,roaming_settings_dir);
end%if save_settings ==1    

end %$if OK__
    case('Exit')
disp('Ending')        
end %switch(Answer__)

end  % function [] = convert_region_data()
%-------------------------------------------
function Updated_data =  Remove_region(Region_indx,existing_data)

existing_data.login_options.Login_ID_arr(Region_indx) = [];
existing_data.login_options.Name_arr(Region_indx)     = [];
existing_data.login_options.PW_arr(Region_indx)       = [];
existing_data.login_options.level_arr(Region_indx)    = [];
existing_data.advanced_settings.options.Region_options(Region_indx) = [];

dummy = existing_data.advanced_settings.choices.Region_index;
if dummy > Region_indx 
existing_data.advanced_settings.choices.Region_index  =  dummy-1;
elseif dummy == Region_indx
if Region_indx~=1
existing_data.advanced_settings.choices.Region_index  =  dummy-1;
end %if Region_indx~=1    
end %if dummy > Region_indx

existing_data.NS_Details.Locations_arr(Region_indx)      = [] ;
existing_data.NS_Details.Sublocations_arr(Region_indx)   = [] ;
existing_data.NS_Details.Values_arr(Region_indx)         = [] ;
existing_data.test_parameters.data_arr(Region_indx)      = [] ;
existing_data.test_parameters.defaults_arr(Region_indx)  = [] ;
Updated_data = existing_data;

end %function Updated_data =  Remove_region(Region_indx,existing_data)
%-------------------------------------------
function save_the_settings_files_and_create_backups(updated_data , settings_dir , roaming_settings_dir)          
p_w_d = pwd;
cd(settings_dir);
[~,~]=dos('copy login_options3.mat login_options3_OV.mat');
[~,~]=dos('copy advanced_settings.mat advanced_settings_OV.mat');
[~,~]=dos('copy NS_Details2.mat NS_Details2_OV.mat');
[~,~]=dos('copy test_parameters3.mat test_parameters3_OV.mat');

 if length(updated_data.test_parameters.data_arr)> length(updated_data.test_parameters.defaults_arr)
 for index   = length(updated_data.test_parameters.defaults_arr) + 1:length(updated_data.test_parameters.data_arr)
 updated_data.test_parameters.defaults_arr{index} =  updated_data.test_parameters.defaults_arr{1}; % they are all the same so could simplify this
 end %for index   = length(updated_data.test_parameters.defaults_arr) + 1:length(updated_data.test_parameters.data_arr)
 end %if length(updated_data.test_parameters.data_arr)> length(updated_data.test_parameters.defaults_arr)

% (2)  Save the files 
as_ = updated_data.advanced_settings; lo_ = updated_data.login_options; tp_ = updated_data.test_parameters; nsd_ = updated_data.NS_Details;
save ('advanced_settings.mat','-struct', 'as_');
save ('login_options3.mat','-struct',  'lo_');
save ('test_parameters3.mat','-struct', 'tp_');
save ('NS_Details2.mat','-struct', 'nsd_');
% save the files

% (3)  delete the roaming files so they are written over
cd(roaming_settings_dir)
%check they exist and iof they do then
if exist('advanced_settings.mat')~=0;dos('del advanced_settings.mat');end
if exist('test_parameters3.mat')~=0;dos('del test_parameters3.mat');end
cd(p_w_d)

end %function save_the_settings_files_and_create_backups(updated_data)          
%-------------------------------------------
function  create_updated_xls_spreadsheet(updated_data)                      


Region_options  =  updated_data.advanced_settings.options.Region_options;
% create the tabs  _NS and _Operators for each and write the data in there

filename__ = 'Region_data_UD.xlsx';
if exist(filename__)~=0;[~,~]=dos(['del ',filename__]);end

for index = 1:length(Region_options)
count = 0 ;

Name_      =    updated_data.login_options.Name_arr{index}      ;
Sentinal_  =    updated_data.login_options.Login_ID_arr{index}  ;
Level_     =    updated_data.login_options.level_arr{index}     ;
PW_        =    updated_data.login_options.PW_arr{index}        ;
jim_inds = strcmp(Name_, 'Jim Evans')==1; mark_inds = strcmp(Name_, 'Mark Evans');
keep_inds = find((jim_inds+mark_inds)==0);

Name = {Name_{keep_inds}}'; Sentinal = Sentinal_(keep_inds); Level = Level_(keep_inds); PW = {PW_{keep_inds}}';


T         =    table(Name,Sentinal,Level,PW)                   ;
neutral_section_names = [];Sub_Names = [];track_ID_ = [];wire_size_ = [];structure =[];ELR = [];Wire_run_number =[];Asset_Number_ = [];

for index_2 = 1:length(updated_data.NS_Details.Locations_arr{index})
%  go through every sub region
% now create the table for the data

for index_3 = 1 : length(updated_data.NS_Details.Sublocations_arr{index}{index_2})
if ~strcmp(updated_data.NS_Details.Locations_arr{index}{index_2},'Unspecified')    
count = count + 1 ;
neutral_section_names {count} =  updated_data.NS_Details.Locations_arr{index}{index_2}                                                                            ;
Sub_Names             {count} =  updated_data.NS_Details.Sublocations_arr{index}{index_2}{index_3}                                                                ;
track_ID_             {count} =  updated_data.test_parameters.data_arr{index}.Track_id_options{updated_data.NS_Details.Values_arr{index}{index_2}(1,index_3)}     ;   
wire_size_            {count} =  updated_data.test_parameters.data_arr{index}.contact_wire_options{updated_data.NS_Details.Values_arr{index}{index_2}(2,index_3)} ;   
structure             {count} =  updated_data.test_parameters.data_arr{index}.struct_id_options{updated_data.NS_Details.Values_arr{index}{index_2}(3,index_3)}    ;   
ELR                   {count} =  updated_data.test_parameters.data_arr{index}.ELR_options{updated_data.NS_Details.Values_arr{index}{index_2}(4,index_3)}          ;   
Wire_run_number       {count} =  updated_data.test_parameters.data_arr{index}.WR_options{updated_data.NS_Details.Values_arr{index}{index_2}(5,index_3)}           ;   
Asset_Number_         {count} =   updated_data.test_parameters.data_arr{index}.Asset_Number_options{updated_data.NS_Details.Values_arr{index}{index_2}(6,index_3)};   
end %if ~strcmp(updated_data.NS_Details.Locations_arr{index}{index_2},'Unspecified')    
end %for index_3 = 1:length(updated_data.NS_Details.Sublocations_arr{index}{index_2})
end %for index_2 = 1:length(updated_data.NS_Details.Locations_arr{index})

neutral_section_names = neutral_section_names';Sub_Names = Sub_Names';structure =structure';ELR = ELR';Wire_run_number = Wire_run_number';

track_ID = cellfun(@(a) str2double(a),  track_ID_' );
wire_size = cellfun(@(a) str2double(a),  wire_size_' );
Asset_Number = cellfun(@(a) str2double(a),  Asset_Number_' );
T2   =    table(neutral_section_names,Sub_Names,track_ID,wire_size,structure,ELR,Wire_run_number,Asset_Number);

writetable( T,  filename__,  'Sheet' , [Region_options{index},  '_operators'])
writetable( T2, filename__,  'Sheet' , [Region_options{index},  '_NS'       ])

% open the spreadsheet and check the values are correct
end % for index = 1:length(Region_options)

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


%disp([ num2str(index_1),' ++ ',num2str(index_2),' ++ ',num2str(index_3) ])    
temp_index_array(index_3,index_2) =   find(ismember(temp_options{index_3} , temp_vals_array{index_1}{index_2}{index_3})==1);

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
%-------------------------------------------
function[ existing_data ] = get_existing_data()
existing_data.login_options      = load('SETTINGS_FILES\login_options3.mat')        ;
existing_data.advanced_settings  = load('SETTINGS_FILES\advanced_settings.mat')     ;
existing_data.NS_Details         = load('SETTINGS_FILES\NS_Details2.mat')           ;
existing_data.test_parameters    = load('SETTINGS_FILES\test_parameters3.mat')           ;
end
%-------------------------------------------
function NS_indices = select_what_to_add_or_replace(new_data_table_format,existing_data)
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
else
end %if strcmp(ans__ ,'Yes')

else
disp('Problem there appears to be two fields with the same name in existing regions (should get  this)')
end %if sum(ismember(existing_region_options,new_regions)) == 0
end %for index = 1:length(new_regions)
existing_data.existing_region_options = existing_region_options ;
NS_indices.new_regions                = new_regions             ;
NS_indices.regions_to_use             = regions_to_use          ;
end  %function NS_indices = select_what_to_add_or_replace(new_data_table_format,existing_data)
%-------------------------------------------
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
%-------------------------------------------
function [data,done_ ] =  select_regions_and_load_data(eligable_regions,input_file)
done_ = 0;
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
done_ = 1;
else    
disp('no selection made')
end % if OK ==1
end %function [data] =  select_regions_and_load_data(eligable_regions)
%-------------------------------------------
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
%-------------------------------------------