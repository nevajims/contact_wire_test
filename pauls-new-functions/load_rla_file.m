function [raw_data, input_signal, success] = load_rla_file(exp_fname);
%loads file specified by current variable exp_fname
%returns: 	in_time_data = matrix of time traces in colmns
%				tx_row = row vector of transmitter rows
%				tx_pos = row vector of transmitter positions around rail
%				rx_row = row vector of receiver rows
%				rx_pos = row vector of receiver positions around rail
%				in_time = column vector of times
%				in_freq = centre frequency of excitation signal
%				in_cycles = cycles in excitation signal
success = 0;
temp_fid=fopen(exp_fname,'rt');
if temp_fid <= 0
	return;
end;
fgetl(temp_fid);
fgetl(temp_fid);
temp_x=fgetl(temp_fid);%this line has centre frequency and number of cycles
input_signal.freq=sscanf(temp_x(findstr(temp_x,'Excitation')+length('Excitation')+1:findstr(temp_x,'kHz')-1),'%f')*1e3;
input_signal.cycles=sscanf(temp_x(findstr(temp_x,'kHz')+length('kHz')+1:findstr(temp_x,'cycle')-1),'%f');
fgetl(temp_fid);
fgetl(temp_fid);
fgetl(temp_fid);
fgetl(temp_fid);
%temp_x=fgetl(temp_fid);%this line says hpow many cols
%temp_rows=sscanf(temp_x,'%f');
%temp_cols=sscanf(temp_x(findstr(temp_x,'(')+1:findstr(temp_x,'cols')-1),'%f');

temp_x=fgetl(temp_fid);%this line has the transmitter locations
temp_txs=sscanf(temp_x,'%f',inf);
temp_txs=temp_txs(2:length(temp_txs));
temp_x=fgetl(temp_fid);%this line has the receiver locations
temp_rxs=sscanf(temp_x,'%f',inf);
temp_rxs=temp_rxs(2:length(temp_rxs));
raw_data.tx_pos=floor(temp_txs);
raw_data.tx_row=round((temp_txs-raw_data.tx_pos)*100);
raw_data.rx_pos=floor(temp_rxs);
raw_data.rx_row=round((temp_rxs-raw_data.rx_pos)*100);
in_no_time_traces = length(raw_data.tx_pos);
%keyboard;
temp_data=fscanf(temp_fid,'%f',inf);
while length(temp_data)<1;
   fgetl(temp_fid);
   temp_data=fscanf(temp_fid,'%f',inf);
   end;
in_no_time_pts = length(temp_data)/(in_no_time_traces+1);
if round(in_no_time_pts)~=in_no_time_pts
   	disp('Error in rla file');
	keyboard;
	return;
end;
if in_no_time_pts<1;
   	disp('Error in rla file');
	keyboard;
	return;
end;
temp_data=reshape(temp_data,in_no_time_traces+1,in_no_time_pts)';
raw_data.time=temp_data(:,1);
raw_data.time_data=temp_data(:,2:in_no_time_traces+1);
fclose(temp_fid);
success = 1;
return;
