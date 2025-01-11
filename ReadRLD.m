function fmc = ReadRLD(varargin)
%  converts RLD to mat format-  either enter the filename as an input
%  argument
%  or select from a list of *.RLD files within the current directory
%  mat file will have the same root name as the rld file

%  2 options ::
%  (1) 1 arg  (filename) 
%    (a)  make sure it exists in the current folder  
%    (b)  make sure its the correct format  (make sure version = 1)    
%  (2) 0 args 
%    (a) (choose the file to load from a list of rld files in the current folder)      
%    (b)  make sure its the correct format  (make sure version = 1)    
input_OK_ = 1;
save_as_file = 0;   %  to save a .mat file

if nargin <= 1
switch(nargin)    
    case(0)
% select  file from list  *.rld
filename_list  = {dir('*.rld').name};

if length(filename_list)>0
[indx,tf] = listdlg('PromptString','Select a file to conver','ListString',filename_list,'SelectionMode','single');
if tf==1
filename = filename_list{indx};
else
input_OK_ = 0;
end
else
disp('no RLD files in this directory')
input_OK_ = 0;
end

    case(1)
filename = (varargin{1});
end %switch(nargin)    

else
    disp('number of input arguments should be 1 or none)')
    input_OK_ = 0;
end %function fmc2 = ReadRLD(varargin)

if input_OK_ == 1

channels_to_use = 12; 
fid = fopen(filename,'rt');
    version = str2double(fgetl(fid));
    
    if version ~= 1
        fclose(fid);
        return
    end

    rld.sample_freq = str2double(fgetl(fid));
    rld.a2d_pts = str2double(fgetl(fid));
    rld.centre_freq = str2double(fgetl(fid));
    rld.cycles = str2double(fgetl(fid));
    
    line = fgetl(fid);
    rld.trans_pos = transpose(str2double(split(line,",")));

    line = fgetl(fid);
    rld.trans_row = transpose(str2double(split(line,",")));

    line = fgetl(fid);
    rld.time =  (1/rld.sample_freq) * str2double(split(line,","));


    %DATA 16x16 rows of 2048
    %rld.time_data = zeros(rld.a2d_pts,12,12);
    for a = 1:16
        for b = 1:16
           rld.time_data(:,b,a) = str2double(split(fgetl(fid),","));
          
% disp(['size: ',num2str(size(rld.time_data,1)),',',num2str(size(rld.time_data,2)),',',num2str(size(rld.time_data,3)),'.'])
        end
    end
    fclose(fid);
    rld.time_data =  rld.time_data(:,1:channels_to_use,1:channels_to_use)  ;
    rld.trans_pos =  rld.trans_pos(1:channels_to_use)                      ;   
    rld.trans_row =  rld.trans_row(1:channels_to_use)                      ;   
    fmc = rld ;
    
if  save_as_file ==1
    save([filename(1:end-4),'.mat'],'fmc');
end %if  save_as_file ==1



end  %if input_OK_ == 1

end %function out = ReadRLD(filename)