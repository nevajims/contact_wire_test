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

    json = jsonencode(cfg.Test_Settings);

    %pass # instead of “ as shell messes this up

    json = strrep(json, '"', "#");

%OPEN THE LOGGER & PASS JSON
%Get the current app directory

p_w_d = pwd;
cd('daq');
%create the shell command
% msgbox(['at run command',  pwd])

cmdline = strcat("RightLinesWrapper.exe", " ", json);


%Open the app modally. Code pauses here until it closes
system(cmdline);

 

%RETRIEVE THE SAVED DATA
%its in the system user temp folder (tempdir)
datapath = strcat(tempdir,cfg.Test_Settings.filename);


    if isfile(datapath)

        text = fileread(datapath);
       testdata = jsondecode(text);

        hash = testdata.hash;

        %check hashes compare. This is to avoid it failing to save and then retrieving a previous file (Err = 2)

        if (strcmp(cfg.Test_Settings.hash,hash) ~= 1)

            %file on disk is not file requested

            err = 2;

        end       

        time_data = testdata;
        
        %Error code 0 = all good

        err = 0;

    else
        %Error Code = 1 : no file at all

        err = 1;

    end

 cd(p_w_d)

%End func

end