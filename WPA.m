%Entry point script for WPA_V3 to try and control exactly which folders are
%on path
clear all;
close all;
clc;
if ~RESTOREDEFAULTPATH_EXECUTED
    restoredefaultpath;
end

%Folder of new processing code
addpath('C:\Users\mepdw\Git\Traxion-PW-\Processing code');

%Need a few functions in these here as well but should move them all to
%above
addpath('C:\Users\mepdw\Git\Traxion-PW-\SAFE solver');
addpath('C:\Users\mepdw\Git\Traxion-PW-\FE simulation code');
addpath('C:\Users\mepdw\Git\Traxion-PW-\General functions');



addpath('WinAPP');
run('WPA_V3');
