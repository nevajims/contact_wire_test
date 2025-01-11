%Demo shows how to load a *.rla file, and save the contents as a *.mat file (for faster subsequent loading)
%with the same name.
%Also requires a hardware file to be specified that contains the details of the array geometry and
%an FE dispersion data file from which the mode shapes will be extracted
%The information from these files is stored in the resulting *.mat file, so they Are not required for
%subsequent analysis

clear; close all;
cd 'C:\tmp';
all_fname= dir ('*.rla');
num_files=size(all_fname,1);
%Source FE dispersion data file
%fe_fname = '\\excite\gul\grail\matlab\fe-data\2d-models\BS80_5mm_TAP.mat';
fe_fname = 'g:\grail\matlab\fe-data\2d-models\BS80_5mm_tap.mat';
%Source hardware data file
hardware_fname = 'g:\grail\matlab\BS80_six_row_prototype.m';
%hardware_fname = 'd:\grail\matlab\old_prototype.m';
file_version = 2;

for i = 1:num_files
    %Source *.rla file
    rla_fname = all_fname(i).name;
    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    %Create *.mat filename
    [pt, fn, ex, vr] = fileparts(rla_fname);
    mat_fname = fullfile(pt, [fn, '.mat']);
    
    %Load *.rla file, combine data with FE and hardware info
    [rail_tester, success] = fn_convert_rla_file(rla_fname, fe_fname, hardware_fname);
    
    %Save data as *.mat file
    save(mat_fname, 'rail_tester');
    
end

