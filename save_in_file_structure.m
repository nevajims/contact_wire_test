function [test_data]  =   save_in_file_structure ( slab_root, test_data , default_options , prog_state )

not_allowed_characters = {'*','"','/','\','<','>',':','|','?','.'} ;  % remove these from file name

p_w_d =  pwd;
cd([slab_root,default_options.raw_data_file_path])

[year_ , month_ , day_ ] =  ymd(datetime) ;
O_S =   test_data.fixed_Operator_Settings ;

if ~exist(num2str(year_))
mkdir(num2str(year_))
cd (num2str(year_))
else
cd (num2str(year_))
end %if ~exist(num2str(year_))

if ~exist(num2str(month_))
mkdir(num2str(month_))
cd (num2str(month_))
else
cd (num2str(month_))
end %if ~exist(num2str(year_))

if ~exist(num2str(day_))
mkdir(num2str(day_))
cd (num2str(day_))
else
cd (num2str(day_))
end %if ~exist(num2str(year_))
% now create

%------------------------------------------------------------------
%  Structure ID  -  4 tests for each  STRUCT-ID ELR TRACK ID  ENTRANCE/EXIT  
%  3 letters and a number 
%  QAL
%------------------------------------------------------------------

if prog_state ~=3
switch(test_data.test_parameters.arm_present)
    case('Yes')
CPtxt = 'WA';        
    case('No')
CPtxt = 'NA';        
    otherwise
CPtxt = 'US';        
end %switch(arm_present)        

Auto_generated_file_stub  = [test_data.test_parameters.Structure_ID,'_',test_data.test_parameters.ELR,'_',...
test_data.test_parameters.Track_id,'_',test_data.test_parameters.clamp_location,'_',CPtxt];

for index = 1:length(not_allowed_characters)
if ~isempty(find(Auto_generated_file_stub ==not_allowed_characters{index}))
Auto_generated_file_stub(find(Auto_generated_file_stub ==not_allowed_characters{index})) = '~';
% replace illegal characters with  '_' 
end %if ~isempty(find(a ==not_allowed_characters{index}))
end %for index = 1:length(not_allowed_characters)    

else
Auto_generated_file_stub = 'CALIBRATION';   
end% if prog_state ~=3

temp_          =    dir([Auto_generated_file_stub,'*.*'])         ;
exist_names_   =    {temp_.name}                                  ;

if length(exist_names_)==0
new_file_number = 1;
else
    max_file_no = 0;    

    for index = 1 :length(exist_names_)
    cur_no = str2num(exist_names_{index}(min(find(exist_names_{index}=='$'))+1:max(find(exist_names_{index}=='$'))-1));
    
    if   cur_no > max_file_no 
    max_file_no = cur_no;
    end % if   cur_no > max_file_no 
    % disp(num2str(cur_no)) 
    end % for index = 1 :length(exist_names_)

new_file_number = max_file_no + 1; 
end

file_name_ =  [Auto_generated_file_stub,'$',num2str(new_file_number),'$.mat'];

file_with_path = [pwd,'\',file_name_];

test_data.file_with_path = file_with_path;

try
save(file_name_,'test_data')
catch
msgbox(['Problem saving the file: ',file_name_])    
end %try

% msgbox(['file saved....     ',file_with_path,'.'])
cd(p_w_d)

end % function   ok_  =   save_in_file_structure (test_file)


function string_ = replace_space(string_)
string_(find(string_==' ')) = '_';
end