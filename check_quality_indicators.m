function [ do_the_prediction , cap_text , sn_text , dist_text,T_num ]      =  check_quality_indicators(PL_inf,rejection_indicators,cap_result,cap_min,dist_min,dist_max )

            [T_num]= find(rejection_indicators(2,:)==1);
                         
             b_temp = log10((cap_result(1:12,1)./cap_result(1:12,end)))' ;
             cap_fail_chns = find(b_temp<cap_min );  

             do_the_prediction = 1         ;
             cap_text          = 'Cap OK'  ;
             sn_text           = 'S/N OK'  ; 
             dist_text         = 'Dist OK' ;

             if ~isempty (cap_fail_chns)  
             cap_text = 'Low Cap: ';
             do_the_prediction = 0; 
             for index = 1:length(cap_fail_chns)
             if index == length(cap_fail_chns)
             insert_ = '.';
             else
             insert_ = ',';    
             end
             cap_text = [cap_text , num2str(cap_fail_chns(index)),'(',num2str(round(b_temp(cap_fail_chns(index))*10)/10),')',insert_] ; 
             end %for index = 1:length(cap_fail_chns)
             end %if ~isempty (cap_fail_chns)  


             if ~isempty(T_num)
             do_the_prediction = 0; 
             sn_text = 'Low S/N: ';    
             for index = 1:length(T_num)
             if index == length(T_num)
             insert_ = '.';
             else
             insert_ = ',';    
             end
             sn_text = [sn_text , num2str(T_num(index)),insert_] ; 
             end %for index = 1:length(T_num)
             end %if ~isempty(T_num)
            

             if PL_inf.DV(PL_inf.mod_val) < dist_min
             do_the_prediction = 0;
             dist_text = ['Peak to close (',num2str(round(1000*PL_inf.DV(PL_inf.mod_val))),' mm).'];
             end %if PL_inf.DV(PL_inf.mod_val) < dist_min
             
             if PL_inf.DV(PL_inf.mod_val) > dist_max
             do_the_prediction = 0;
             dist_text = ['Peak to far away (',num2str(round(1000*PL_inf.DV(PL_inf.mod_val))),' mm).'];
             end %if PL_inf.DV(PL_inf.mod_val) < dist_min

end %function [ do_the_prediction , cap_text , sn_text , dist_text ]      =  check_quality_indicators(PL_inf,rejection_indicators,cap_result,cap_min,dist_min,dist_max )