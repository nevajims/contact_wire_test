function raw_data = fn_zero_dead_zone(raw_data, raw_data_zero_dead_time, suppress_display);
tic;

i1 = min(find(raw_data.time > raw_data_zero_dead_time));
for ii = 1:size(raw_data.time_data, 2);
    raw_data.time_data(1:i1, ii) = 0;
end;
  
if ~suppress_display
	disp(['Dead zone zeroed: ',num2str(toc)]);
end;
return;
