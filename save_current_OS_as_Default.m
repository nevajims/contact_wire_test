function [OK_ ] = save_current_OS_as_Default(default_options,Current_Operator_Settings)

% Also saves old defaults somewhere
% Save current defaults in new file

default_Operator_Settings   =  load_structure_from_file([pwd,default_options.Operator_Settings_fname],...
default_options.Operator_expected_fields);
p_w_d = pwd;

cd(default_options.Operator_Settings_fname(min(find(default_options.Operator_Settings_fname=='\'))+1:...
    max(find(default_options.Operator_Settings_fname=='\'))-1))


temp_ =  dir('OldOS#*#_USER.dat');
exist_names_   =    {temp_.name}                                  ;


if length(exist_names_)==0
new_file_number = 1;
else
    max_file_no = 0;    

    for index = 1 :length(exist_names_)
    cur_no = str2num(exist_names_{index}(min(find(exist_names_{index}=='#'))+1:max(find(exist_names_{index}=='#'))-1));
    if   cur_no > max_file_no 
    max_file_no = cur_no;
    end % if   cur_no > max_file_no 
    % disp(num2str(cur_no)) 

    end % for index = 1 :length(exist_names_)
new_file_number = max_file_no + 1; 
end

cd(p_w_d)

new_file_name = ['OldOS#',num2str(new_file_number),'#_USER.dat']; 
file_path_  =   [pwd,default_options.Operator_Settings_fname(1:max(find(default_options.Operator_Settings_fname=='\'))-1)];

OK_1  =  create_file_from_structure(default_Operator_Settings,new_file_name,file_path_);


%  ------------------------------------------------------------
%  OK_ =   create_file_from_structure(varargin)
%  structure_           = varargin__{1} ;  
%  filename_            = varargin__{2} ;   
%  filepath_            = varargin__{3} ;  
%  ------------------------------------------------------------
% save current values as default  
OK_2 =   create_file_from_structure(Current_Operator_Settings,'Operator_Settings.dat',file_path_);

if OK_1 ==1 &&  OK_2 ==1
OK_  =  1;
end  %if OK_1 ==1 &&  OK_2 ==1

end %function [OK_ ] = save_current_OS_as_Default(Default_Settings,Current_Operator_Settings)
