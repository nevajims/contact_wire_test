function [time_data, err] = GetDataFromDevice_2()

%load('C:\MLPROGS\WirePro2\SLAB_data\testdata_examp.mat','testdata');
load([pwd,'\SLAB_data\testdata_examp.mat'],'testdata');

time_data = testdata;
err = 0;

end %function [time_data, err] = GetDataFromDevice_2(Test_Settings)
