function  formatted_txt= convert_table_to_formatted_txt(table_)

keyboard

CN = table_.Properties.VariableNames;
RN = table_.Properties. RowNames;
TA = table2array(table_) ;

%  first display the titles
formatted_txt = '\t\t\t\t';
for index = 1: length(CN)
if index == length(CN)   
formatted_txt = [formatted_txt,CN{index},'\n'];
else
formatted_txt = [formatted_txt,CN{index},'\t\t\t'];
end %if index == length(CN)   
end %for index = 1: length(CN)

formatted_txt = [formatted_txt,'\t\t\t'];
for index = 1: length(CN)
if index == length(CN)   
formatted_txt = [formatted_txt,'_____','\n'];
else
formatted_txt = [formatted_txt,'_____','\t\t'];
end %if index == length(CN)   
end %for index = 1: length(CN)

for index = 1:length(RN)

formatted_txt = [formatted_txt,RN{index},'\t\t\t\t'];      
for index_2 = 1:length(CN)

if index_2 == length(CN)   
formatted_txt = [formatted_txt,num2str(TA(index,index_2)),'\n'];
else
formatted_txt = [formatted_txt,num2str(TA(index,index_2) ),'\t\t'];
end %if index == length(CN)   


end %for index_2 = 1:length(CN)
end %for index = 1:length(RN)






end  % function  formatted_txt= convert_table_to_formatted_txt(table_)
