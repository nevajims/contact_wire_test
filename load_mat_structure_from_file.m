function  [structure_ , warning_message_] =  load_mat_structure_from_file(varargin) 
%(1) the structure  (2) name and path of structure to be saved (3) fields it should have

switch(nargin)
    case(0)
disp('load_mat_strcture+_from_file should have 1 or 2 inputs')        
    case(1)
file_with_path = varargin{1};
structure_  = load(file_with_path);
    case(2)
file_with_path = varargin{1};
structure_  = load(file_with_path);
check_fields_ = varargin{2};
end % switch


if isempty(find(file_with_path=='\'))
file_name =   file_with_path                                            ;
else
file_name =   file_with_path(max(find(file_with_path == '\'))+1:end-4)    ;
end   %if isempty(find(file_with_path=='\'))

if nargin==2

% now check the actual fields with the ones given
% Check size of the 2 structure
% are they the same length
% accomadat for sub fields

warning_message_ = '';

% check if subfields exists
SF_exist_ =  do_subfields_exist(structure_);


if SF_exist_
FS = get_w_SF(structure_);
else
FS = fields(structure_);
end

counter_ = 0;

if length(FS) == length(check_fields_)
length_same = 1;    
else
length_same = 0;
counter_ = counter_ + 1;
warning_message_{counter_} = 'Length of structure fields and required fields dont match';
end %if length(FS) == length(check_fields_)

if  isempty(find(ismember(FS, check_fields_)==0))
extra_members = 0;    
else
extra_members = 1;
counter_ = counter_ + 1;
warning_message_{counter_} = 'There are unknown fields in the structure as follows:';
inds_ = find(ismember(FS, check_fields_)==0);

if length(inds_) ==1
txt_ =  [FS{inds_},'.'] ;
else    
txt_ = '';
for index = 1:length(inds_)
if index == length(inds_)
insert_ = '.';
else
insert_ = ',';
end
txt_ = [txt_,FS{inds_(index)},insert_];
end  %for index = 1:length(inds_)
end %if length(inds_) ==1
counter_ = counter_ + 1;
warning_message_{counter_} =txt_;   % extra members warning
end %if find (ismember(FS, check_fields_)==0) == 0

if  isempty(find(ismember(check_fields_, FS)==0))
missing_members = 0;    
else
missing_members = 1;
counter_ = counter_ + 1;
warning_message_{counter_} = 'There are missing fields in the structureas as follows:';

inds_ = find(ismember(check_fields_, FS)==0);

if length(inds_) ==1
txt_ =  [check_fields_{inds_},'.'];
else    
txt_ = '';
for index = 1:length(inds_)
if index == length(inds_)
insert_ = '.';
else
insert_ = ',';
end
txt_ = [txt_,check_fields_{inds_(index)},insert_];
end  %for index = 1:length(inds_)
end %if length(inds_) ==1
counter_ = counter_ + 1;
warning_message_{counter_} =txt_;   % extra members warning
end %if  isempty(find(ismember(check_fields_, FS)==0))
else
warning_message_=[];
end %if nargin==2

if ~isempty(warning_message_)
warning_message_{length(warning_message_)+1} = ''       ;
warning_message_{length(warning_message_)+1} =  ['(FILE NAME:        ', file_name,')']; 
msg_H       =     msgbox(warning_message_) ;
msg_H.Name  =     'WARNING'                ;

%pause(4)
%close (msg_H)
end %if ~isempty(warning_message_)

end % function load_mat_structure_from_files(varargin) 
%save('default_options2.mat','-struct','dummy')

function SF_exist_ =  do_subfields_exist(structure_)
SF_exist_ = 0;

dum1 = fields(structure_);
for index = 1 :length(dum1)
if eval(['isstruct(structure_.',dum1{index},')'])
SF_exist_ = 1;
end %if isfield(structure_,dum1{index})

end %for index = 1 :length(dum1)
end %function SF_exist_ =  do_subfields_exist(structure_)


function FS = get_w_SF(structure_)
dum1 = fields(structure_);
% FS
counter_ = 0;

dum1 = fields(structure_);
for index = 1 :length(dum1)
if eval(['isstruct(structure_.',dum1{index},')'])

dum2 = eval([ 'fields(structure_.',dum1{index},')']) ;
for index_2 = 1 :length(dum2)
counter_  = counter_  + 1 ;    
FS{counter_} = [dum1{index},'.',dum2{index_2}] ;
end %for index_2 = 1 :length(dum2)
end %if isfield(structure_,dum1{index})
end %for index = 1 :length(dum1)
FS = FS';

end %function FS = get_w_SF(structure_)







