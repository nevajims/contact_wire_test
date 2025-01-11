function   [table_] =  create_table_from_structure(struct_) 

Fields =  fieldnames(struct_);

for index = 1:length(Fields)

if length(getfield(struct_,Fields{index}))>1
   
temp_ = getfield(struct_,Fields{index});
switch(class(temp_))
    case('cell')
tab_val = [];
for index_2 = 1 : length(temp_)
if index_2 == length(temp_)
space_insert='';
else
space_insert=',';
end
tab_val  = [tab_val,num2str(temp_{index_2}),space_insert]; 
end %for index_2 = 1 : length(temp_)
Values{index} = tab_val;

    case('double')
tab_val = [];
for index_2 = 1:size(temp_,1)
if index_2 == size(temp_,1)
space_insert='';
else
space_insert=',';
end
tab_val  = [tab_val,num2str(temp_(index_2,:)),space_insert];
end %for index_2 = 1:size(temp_,1)
Values{index} = tab_val;

    case('char')
Values{index} = temp_ ;

    otherwise        
disp(['write some code for type: ',class(temp_)])
end %switch(class(temp_))

else
Values{index} = num2str(getfield(struct_,Fields{index}));
end


end
Values = Values';

table_ = table(Fields,Values);
end