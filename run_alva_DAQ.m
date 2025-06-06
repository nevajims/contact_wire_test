function [raw_data,err] =  run_alva_DAQ(Test_Settings)

% need the to run safe for the other contact wire
% 'C:\MLPROGS\WirePro2\Simulated_live_test_results\rl_temp_20-04-2023.rld'
% raw_data = load a file
% [testdata, err,err2] = GetDataFromDevice(cfg);  % this is the link to alvas program

% if err~=0
% disp('warning err~=0' )
% end %if err~=0

% disp('loading dummy file')                                   %  just load a file at this stage
% temp_2 = load('C:\MLPROGS\WirePro2\SLAB_data\testdata2');    %  just load a file at this stage
% testdata = temp_2.testdata;                                  %  just load a file at this stage     


%[testdata, err] = GetDataFromDevice_2();   % fake data

%if err~=0 msgbox('warning from device- '); end 


%---------------------------------------
% this is loading the old RLD format
%---------------------------------------
%disp(['This is a simulation of the actual test,test_Settings sample rate set at ',num2str(Test_Settings.Sampling.Num_Samples),' Hz.'])
% Need  alvas program in here to get the dat afrom the slab
% keep in for the moment
% temp_ = ReadRLD( 'C:\MLPROGS\WirePro2\Simulated_live_test_results\rl_temp_20-04-2023.rld' );
% raw_data_old.time                        =  [temp_.time]          ;
% raw_data_old.time_data                   =  [temp_.time_data]     ;
% raw_data_old.cap_test_result             =  1                     ;  % 1 is pass /// 0 is fail
%---------------------------------------
% this is loading the old RLD format
%---------------------------------------



[testdata, err] = GetDataFromDevice(Test_Settings); % real




if err ==0
raw_data.time = (1/Test_Settings.Sampling.Sample_RateHz)*[0:Test_Settings.Sampling.Num_Samples-1]' ;

  %
  % check
   if Test_Settings.Sampling.Num_Samples  ~=  length(testdata.test{1})
   disp('warning Test_Settings.Sampling.Num_Samples  ~=  length(testdata.test{1})')
  end %  if Test_Settings.Sampling.Num_Samples  ~=  length(testdata.test{1})

  temp_3 = zeros(length(testdata.test{1}),12,12);

  for index_1 = 2:13
  for index_2 = 1:12
  temp_3(:,index_1-1,index_2) = testdata.test{index_1}(index_2,:)';
  end % for index_2 = 1:12
  end % for index_1 = 2:13

  for index_3 = 1:12
  temp_4(:,index_3) = testdata.test{1}(index_3,:)';
  end %for index_3 = 1:12
    

  % now do the SNR bit 
  raw_data.time_data = temp_3;
  
   % temp hack --------------------   for problem with pulse on 1st channel
   % in noise

   raw_data.noise_data = temp_4;  
   %raw_data.noise_data = [temp_4(:,2),temp_4(:,2:12)];
     %-------------------------------------------------------------------


  raw_data.cap_test_result = testdata.dataz;
  raw_data.serial_number =  testdata.serial_number;
  


else

raw_data = [];

end %  if err ==0

end %function [raw_data, cap_test_result ] =  run_alva_DAQ(Test_Settings);
