function  [ok_] =  save_mat_structure_to_file( structure_ , filename_and_path ) 
ok_ = 1;

try
save(filename_and_path , '-struct' , 'structure_')
catch
ok_ = 0;
%msgbox()
end

end  % function  [ok_] =  save_mat_structure_to_file(varargin) 



