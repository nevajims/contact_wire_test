function OK_ =   create_file_from_structure(varargin)

% OK_ =  create_file_from_structure(stucture_2_save,'file_name.dat', 'path'); 

[structure_ ,filename_and_path]   = process_inputs(varargin,nargin);

% if the file name exists make it  filename_1  filename_2   etc
% file_name(filename_,filepath_);
% open the file name for writing 
OK_ =  write_data_to_file(structure_ ,filename_and_path);

end %function  OK_ =   create_file_from_structure(varargin)

function  OK_ =  write_data_to_file(structure_ ,filename_and_path)
%p_w_d = pwd;
%cd(filepath_)
fileID = fopen(filename_and_path,'w');

%try
fprintf(fileID,'START\n');
field_names = fields(structure_);
for index = 1:length(field_names)

if ~eval(['isstruct(structure_.',field_names{index},');'])
%disp(field_names{index})
fprintf(fileID,['%%',field_names{index},'%%\n']);
val_ = eval(['structure_.',field_names{index}]);
fprint_the_value(val_,fileID);
else
% its a struct    
eval(['sub_field_names = fields(structure_.',field_names{index},');'] )

for index_2 = 1: length(sub_field_names)
fprintf(fileID,['%%',field_names{index},'.',sub_field_names{index_2},'%%\n']);
val_ = eval(['structure_.',field_names{index},'.',sub_field_names{index_2}]);

%if strcmp(class(val_),'double')
%disp(['type = ',class(val_)] )

fprint_the_value(val_,fileID)
%elseif strcmp(class(val_),'cell')
%fprint_the_value(val_{index3},fileID)

%else
%end %if strcmp(class(val_),'double')

end %for index_2 = 1: length(sub_field_names)

end %if    eval(['isstruct(structure_.',field_names{index},')'])
end %for index = 1:length(structure)



fprintf(fileID,'END\n');
OK_ = 1;
%catch
%disp('error caught..... ')
%OK_ = 0;
%end %try
fclose(fileID);

%cd (p_w_d )
end %function  OK_ =  write_data_to_file(structure_ ,filename_,filepath_)


function fprint_the_value( val_, fileID)

for index = 1:size(val_,1)
sub_val = val_(index,:);

if ~isstr(sub_val) && ~iscell(sub_val)      
if sum(sub_val- floor(sub_val))==0    
% i.e. it is an integer (no decmal values)
allOneString = sprintf('%.0f,' ,sub_val);
fprintf(fileID,[allOneString(1:end-1),'\n']);
else
decimal_places = find_the_decimal_places(sub_val);
allOneString = sprintf(['%.',num2str(decimal_places),'f,'],sub_val);
fprintf(fileID,[allOneString(1:end-1),'\n']);
end %if sum(a- floor(a))==0    

elseif isstr(sub_val)
%disp([double_forward_slash(sub_val),'\n'])    
fprintf(fileID,[double_forward_slash(sub_val),'\n']);
elseif iscell(sub_val)

for index2 = 1:length(sub_val)
%disp([double_forward_slash(sub_val{index2}),'\n'])    
fprintf(fileID,[double_forward_slash(sub_val{index2}),'\n']);
end %for index = 1:length(sub_val)
   
end % if ~isstr(sub_val)
end %for index = 1:size(val_,1)
end %function fprint_the_value( field_value)




function no_decimals = find_the_decimal_places(sub_val)
decimals_found =0;
no_decimals = 0;
multiplier = 1;
while decimals_found ==0
no_decimals = no_decimals + 1;    
multiplier = multiplier * 10;
if sum(multiplier*sub_val- floor(multiplier*sub_val))==0
decimals_found = 1;
end %if sum(multiplier*sub_val- floor(multiplier*sub_val))==0
end %while decimals_found ==0

end %function decimal_places = find_the_decimal_places(sub_val);

function new_text = double_forward_slash(text)
% Puts an extra \ in wherever there is a \ (so it comes out correctly on frintf

slashes = find(text=='\');
if length(slashes) == 0
new_text = text;
else

%if slashes(1) ~=1
slashes = [1,slashes];
%end %if slashes(1) ~=1

if slashes(end) ~= length(text)
slashes = [slashes,length(text)];
end %if slashes(1) ~=1
temp_text = [];

for index = 1: length(slashes)-1

if index ~=length(slashes)-1
temp_text = [temp_text,text(slashes(index):slashes(index+1)-1),'\'];   
else
temp_text = [temp_text,text(slashes(index):slashes(index+1))]; 
end %if index ~=lengthslashes-1
end% for index = 1: lengthslashes-1
new_text = temp_text;
end %if length(slashes) == 0
end %function new_text = double_forward_slash(text)

function new_filename = check_file_name (filename_,filepath_)

p_w_d = pwd;
cd(filepath_)
if ~exist(filename_)
new_filename = filename_; 
else
temp_ = dir([filename_(1:end-4),'_*.dat']);
names ={temp_.name};
if length(names) == 0
new_filename = [filename_(1:end-4),'_1.dat'];
else
max_val = 0 ;
for index = 1: length(names)    
cur_string = names{index};    
cur_val = str2num(cur_string(max(find(cur_string=='_'))+1:end-4));    
if cur_val > max_val
max_val = cur_val;
end %if cur_val > max_val
end %for index = 1: length(names)    
new_filename = [filename_(1:end-4),'_',num2str(max_val+1)  ,'.dat'];
end %if length(names) == 0
end %if ~exist(filename_)
cd(p_w_d)
end%function filename_ = check_file_name (filename_,filepath_);

function [structure_ ,filename_and_path]   = process_inputs (varargin__,nargin__)
switch(nargin__)
    case(1)
structure_           = varargin__{1} ;  
%filename_            = 'ascii_data_file.dat' ;     
%filepath_            =   
filename_and_path    = 'P:\Experimental setup files\ascii_data_file.dat';

    case(2)
structure_           = varargin__{1} ;  
filename_and_path    = varargin__{2} ;  

%filepath_            = 'P:\Experimental setup files';  

    case(3)

structure_           = varargin__{1} ;  

temp_path = varargin__{3};
if ~strcmp(temp_path(end),'\')
temp_path = [temp_path,'\'];
end %if ~strcmp(varargin__{3}(end),'\')
filename_and_path= [temp_path,varargin__{2}];
end %switch(nargin)

end
