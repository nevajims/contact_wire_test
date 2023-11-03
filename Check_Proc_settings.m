function [messge_ , check_ok] = Check_Proc_settings(field_,Value_)

%keyboard
messge_ = '';

switch(field_)

    case('ms_matrix_modes_to_use')
    % Must have length 1 to 4 
    % And only have 1 to 4 in it
    if strcmp(class(Value_),'double') ==1
    if  length(Value_)>=1 && length(Value_)<=4
       
    if  max(Value_) <= 4 &&  min(Value_) >= 1
    check_ok =1;
    else
    check_ok = 0;
    disp('hereb')
    messge_ = 'modes from 1 to 4';
    end %if  max(Value_) <= 4 &&  min(Value_) >= 4
    else
    messge_ = 'max 4 modes';
    check_ok = 0;
    end %if  length(Value_)>=1 && length(Value_)<=4
    else
    messge_ = 'numeric input only';
    check_ok = 0;
    end %if strcmp(class(Value_),'double') ==1
    
    case('freq_filter')
    if strcmp(class(Value_),'double') ==1
        if Value_<= 500000 &&  Value_>= 0 
    check_ok = 1;
    else
    check_ok = 0;    
    messge_ = 'must be between 0 and 500,000 Hz';
    end
    else
    check_ok = 0;
    messge_ = 'numeric input only';
    end %if strcmp(class(Value_),'double') ==1
   
    case('freq_filter_bandwidth')
    if strcmp(class(Value_),'double') ==1
    if Value_<= 100000 &&  Value_>= 0 
    check_ok = 1;
    else
    check_ok = 0;    
    messge_ = 'must be between 0 and 100,000 Hz';
    end
    else
    check_ok = 0;
    messge_ = 'numeric input only';
    end %if strcmp(class(Value_),'double') ==1
    
    case('freq_comp_for_input_signal')
    if strcmp(class(Value_),'double') ==1
    if Value_== 0 ||  Value_== 1 
    check_ok = 1;
    else
    check_ok = 0;    
    messge_ = 'must be between 0 or 1 (switch)';
    end
    else
    check_ok = 0;    
    messge_ = 'numeric input only';
    end %if strcmp(class(Value_),'double') ==1
        
    case('freq_filter_bandwidth')
    if strcmp(class(Value_),'double') ==1
    if Value_== 0 ||  Value_== 1 
    check_ok = 1;
    else
    check_ok = 0;    
    messge_ = 'must be between 0 or 1 (switch)';
    end
    else
    check_ok = 0;    
    messge_ = 'numeric input only';
    end %if strcmp(class(Value_),'double') ==1
  
    case('raw_data_ignore_pulse_echo')
    if strcmp(class(Value_),'double') ==1
    if Value_== 0 ||  Value_== 1 
    
    check_ok = 1;
    else
    check_ok = 0;    
    messge_ = 'must be between 0 or 1 (switch)';
    end
    else
    check_ok = 0;    
    messge_ = 'numeric input only';
    end %if strcmp(class(Value_),'double') ==1
    
    case('raw_data_coupling_comp')
    if strcmp(class(Value_),'double') ==1
    
    if Value_== 0 ||  Value_== 1 
    
    check_ok = 1;
    else
    check_ok = 0;    
    messge_ = 'must be between 0 or 1 (switch)';
    end
    else
    check_ok = 0;    
    messge_ = 'numeric input only';
    end %if strcmp(class(Value_),'double') ==1
  
    
    case('raw_data_zero_dead_time')
    if strcmp(class(Value_),'double') ==1
    
    if Value_== 0 ||  Value_== 1 
    
    check_ok = 1;
    else
    check_ok = 0;    
    messge_ = 'must be between 0 or 1 (switch)';
    end
    else
    check_ok = 0;    
    messge_ = 'numeric input only';
    end %if strcmp(class(Value_),'double') ==1
    
    case('ms_matrix_calc_method')
    if strcmp(class(Value_),'double') ==1
    
    if Value_== 0 ||  Value_== 1 
    
    check_ok = 1;
    else
    check_ok = 0;    
    messge_ = 'must be between 0 or 1 (switch)';
    end
    else
    check_ok = 0;    
    messge_ = 'numeric input only';
    end %if strcmp(class(Value_),'double') ==1
    
    case('ms_matrix_calc_freqs')
    if strcmp(class(Value_),'double') ==1
    if  length(Value_)>=1 && length(Value_)<=15
    if  max(Value_) <= 200000 &&  min(Value_) >= 1
    check_ok =1;
    else
    check_ok = 0;
    messge_ = 'vals between 1 and 20000Hz';
    end %if  max(b) <= 4 &&  min(b) >= 4
    else
    check_ok = 0;    
    messge_ = 'max 15 values';
    end %if  length(Value_)>=1 && length(Value_)<=4
    else
    check_ok = 0;
    messge_ = 'numeric input only';
    end %if strcmp(class(Value_),'double') ==1
    

    case('suppress_display')
    if strcmp(class(Value_),'double') ==1
    
    if Value_== 0 ||  Value_== 1 
    
    check_ok = 1;
    else
    check_ok = 0;    
    messge_ = 'must be between 0 or 1 (switch)';
    end
    else
    check_ok = 0;    
    messge_ = 'numeric input only';
    end %if strcmp(class(Value_),'double') ==1
    
    case('warp_factor')
    if strcmp(class(Value_),'double') ==1
    
    if Value_== 0 ||  Value_== 1 
    check_ok = 1;
    else
    messge_ = 'must be between 0 or 1 (switch)';
    check_ok = 0;
    end
    else
    messge_ = 'numeric input only';
    check_ok = 0;
    end %if strcmp(class(Value_),'double') ==1
    
end %switch(field_)

end %function [messge_ , check_ok] = Check_Proc_settings(field_,Value_)
