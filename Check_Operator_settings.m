function [messge_ , check_ok] = Check_Operator_settings(field_,Value_)

%keyboard

switch(field_)
    case('Name')
    if  strcmp(class(Value_),'char') ==1
    check_ok = 1; 
    messge_ = '';
    else
    check_ok = 0; 
    messge_ = 'should be text';
    end %

    case('Sentinel_No')        
    if  strcmp(class(Value_),'double')  &&  rem(Value_,1) == 0
    check_ok = 1; 
    messge_ = '';
    else
    check_ok = 0; 
    messge_ = 'should be a number (no decimal pt)';
    end %if  strcmp(class(Value_),'double')  &&  rem(Value_,1) == 0
  
    case('Notes')
    % No Restrictions
    check_ok = 1; 
    messge_ = '';
    
    case('Tower_ID')
    % No Restrictions
    check_ok = 1; 
    messge_ = '';

    case('Site_name')
    % No Restrictions
    check_ok = 1; 
    messge_ = '';


    case('ELR')
    if   length(num2str(Value_)) == 4
    check_ok = 1; 
    messge_ = '';
    else
    check_ok = 0; 
    messge_ = 'Should be 4 characters long ';
    end %
    
    case('Track_ID')
    if length(num2str(Value_)) == 4 &&  strcmp(class(Value_),'double')
    check_ok = 1; 
    messge_ = '';
    else
    check_ok = 0; 
    messge_ = 'Should be a 4 digit number';
    end %

    case('contact_wire_type_120_107')
    if Value_ == 1 || Value_ == 2        
    check_ok = 1; 
    messge_ = '';
    else
    check_ok = 0; 
    messge_ = 'must be a 1 or 2';
    end %

    case('feature_distance_m')  
    if strcmp(class(Value_),'double')
    check_ok = 1; 
    messge_ = '';
    else
    check_ok = 0; 
    messge_ = 'must be a number';
    end %

    case('Milage')    
    if strcmp(class(Value_),'double')
    check_ok = 1; 
    messge_ = '';
    else
    check_ok = 0; 
    messge_ = 'must be a number';
    end %
    
    otherwise
    check_ok = 0;
    messge_ = 'Field name is not in the structure' ; 

end





end    % function [ message_   ,   check_ok ] = Check_Operator_settings(field ,  Value )
