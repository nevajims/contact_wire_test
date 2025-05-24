function [time_data, err] = GetDataFromDevice(Test_Settings)

    %for testing
    %  
    % cfg = load("Test_Settings_1.mat");
    
    
    cfg.Test_Settings = Test_Settings;
%CONFIG TO JSON   
    %internal use

    cfg.Test_Settings.filename = "rl_temp.dat";   %name file (think this is actually hardcoded at moment)

    %sends to logger, and checks file for this
    cfg.Test_Settings.hash = randi(1000) + " " + string(datetime);
   

    %NOTE: am taking the Test_Settings substruct here. Make sure matches the cfg that is passed in.
    try 
    json = jsonencode(cfg.Test_Settings);
    catch error_
    msgbox( [ '(1) json = jsonencode(cfg.Test_Settings);  ' , error_.message])
    end   % end

    %pass # instead of “ as shell messes this up
    json = strrep(json, '"', "#");


%keyboard
%OPEN THE LOGGER & PASS JSON
%Get the current app directory

p_w_d = pwd;
cd('daq');
%create the shell command
% msgbox(['at run command',  pwd])

cmdline = strcat("RightLinesWrapper.exe", " ", json);

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Jim I've edited the next section for the new DAQ (on desktop)
% Just uncomment single % down to end and remove "[status,text] =" to revert
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% Open the app modally. Code pauses here until it closes

try
[status,text] = system(cmdline);
catch error_

text = [];
msgbox( [ '(2) problem running system(cmdline):  ' , error_.message ])
end %try


% msgbox(['First 100chars of json:',text(1:100)])




%%  RETRIEVE THE SAVED DATA
%%  its in the system user temp folder (tempdir)
%   datapath = strcat(tempdir,cfg.Test_Settings.filename);
%%  datapath = strcat('C:\Users\Dev\',cfg.Test_Settings.filename);
%%   disp('remove this (and above)')
%    if isfile(datapath)


        %text = fileread(datapath);
if ~isempty(text)
        try   
        testdata = jsondecode(text);
        catch error_
        msgbox(['(3) error running testdata = jsondecode(text)  ',error_.message])   
        if length(text)                      <= 200 
        msgbox(['json text:',text(1:end)])
        else
        msgbox(['json text(first200 chars):',text(1:200)])
        end
        end %try
              
        hash = testdata.hash;
        %%check hashes compare. This is to avoid it failing to save and then retrieving a previous file (Err = 2)
        time_data = testdata;
        %%Error code 0 = all good
        err = 0;
        if (strcmp(cfg.Test_Settings.hash,hash) ~= 1)
          %% msgbox('file on disk is not file requested' )
          %%  file on disk is not file requested
            err = 2;
        end   % if (strcmp(cfg.Test_Settings.hash,hash) ~= 1)   


%    else
%        %  Error Code = 1 : no file at all
%           msgbox('Error Code = 1 : no file at all' )
%           time_data = [];
%           err = 1;
%
%    end
   
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%]
% End of Edits
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%]

% testdata.serial_number  ACCESS WITH THIS
else
%msgbox('empty text')
time_data = [];
err = 1 ; 
end %if ~isempty(text)
cd(p_w_d)
%End func
end %function [time_data, err] = GetDataFromDevice(Test_Settings)
