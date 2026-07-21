function [] = convert_region_data()
% add in advanced users withot them being in the excell spreadsheet

% (1) -  Select the file to convert
% (2) -  Get the sheet names
% (3) -  Find and pairs of name_NS and name_operators 
% [status,sheets] = xlsfinfo('Region_data.xlsx') 
% Make sure correct files are deleted so its updated
% input_file = uigetfile('*.xls*');

input_file ='Region_data';
[status,sheets_] = xlsfinfo(input_file); 
if strcmp(status,'Microsoft Excel Spreadsheet')
[eligable_regions,unused_sheets] = find_eligable_regions(sheets_)                  ;



[data] =  select_regions_and_load_data(eligable_regions);


else
disp('incorrect file format')    
end %if strcmp(status,'Microsoft Excel Spreadsheet')
end  % function [] = convert_region_data()


function [eligable_regions,unused_sheets] = find_eligable_regions(sheets_)
% create two lists on NS_List the other operator_list
NS_regions        =   [] ;
operator_regions  =   [] ; 
unused_sheets     =   [] ;

for index= 1:length(sheets_)
if strcmp(sheets_{index}(end-2:end),'_NS')
NS_regions{length(NS_regions)+1}                = sheets_{index}(1:end-3);

elseif length(sheets_{index}) >= 10
if strcmp(sheets_{index}(end-9:end),'_operators')     
operator_regions{length(operator_regions)+1}    =  sheets_{index}(1:end-10);
else
unused_sheets{length(unused_sheets)+1} = sheets_{index};
end
else
unused_sheets{length(unused_sheets)+1} = sheets_{index};
% do nothing
end %if strcmp(sheets_{index}(end-2:end),'_NS')    
end %for index= 1:length(sheets_)

eligable_regions=[];

for index= 1:length(operator_regions)
if ismember(NS_regions,operator_regions{index})
eligable_regions{length(eligable_regions)+1} = operator_regions{index}; 
end  %for index = 1:length(operator_regions)
end
end  % function find_eligable_regions(sheets_)




function [data] =  select_regions_and_load_data(eligable_regions)
keyboard


[indx,OK] = listdlg('PromptString','Select region(s)','SelectionMode','multiple','ListString',eligable_regions);


if OK ==1
for index = 1:length(indx)
%current_region = 



end %for index = 1:length(indx)   

else    
disp('no selection made')
end % if OK ==1

end %function [data] =  select_regions_and_load_data(eligable_regions)










