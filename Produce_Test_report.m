function Produce_Test_report( proc_file  ,  PL_inf , T_num, Prediction_,default_options,slab_root,P_Opts,Prog_STATE )


capacitance_thresholds  = [P_Opts.cap_thresh_lower,  P_Opts.cap_thresh_options(P_Opts.cap_thresh_index)]  ;   % one  value    min  threshold
dist_pass_val           = [P_Opts.dist_pass_options(P_Opts.dist_pass_index),P_Opts.dist_pass_val_upper]   ;   % one  minimum  dist 
%  These need to go in the settings 

if isfield(proc_file.test_data,'ver')
SW_version = proc_file.test_data.ver;
else
SW_version = '1.0';  %  every subsequent  version has this field
end

if isfield(proc_file.test_data.raw_data , 'serial_number')

SN_ = proc_file.test_data.raw_data.serial_number;

else
SN_ = 'not known'; 
end

% get the test conditions and operator information first
if str2num(SW_version) ==1
% special case with old info    

con_Wires = {'120','107'};
Report_info.date_time         = proc_file.test_data.date_time                              ;
Report_info.Tester_name       = proc_file.test_data.fixed_Operator_Settings.Name           ;
Report_info.Sentinal_no       = proc_file.test_data.fixed_Operator_Settings.Sentinel_No    ; 
Report_info.SW_version        = SW_version                                                 ;
Report_info.ELR               = num2str(proc_file.test_data.fixed_Operator_Settings.ELR)   ;
%Report_info.milage           = num2str(proc_file.test_data.fixed_Operator_Settings.Milage);  
Report_info.Notes             = proc_file.test_data.fixed_Operator_Settings.Notes          ;
Report_info.Track_id          = num2str(proc_file.test_data.fixed_Operator_Settings.Track_ID);
Report_info.contact_wire      = con_Wires{proc_file.test_data.fixed_Operator_Settings.contact_wire_type_120_107};
Report_info.Structure_ID      = proc_file.test_data.fixed_Operator_Settings.Tower_ID       ;
Report_info.arm_present       = 'not known';  
Report_info.clamp_location    = 'not known';
Report_info.file_with_path    = proc_file.test_data.file_with_path;
Report_info.Peak_location_mm  = 1000*PL_inf.DV(PL_inf.mod_val);
Report_info.Prediction_text   = [Prediction_.Labels{Prediction_.pred_value},'(', Prediction_.txt_insrt,')'];
Report_info.SN_               = SN_;
Report_info.INI_val               = P_Opts.initial_thresh_index  ;
else

Report_info.date_time         = proc_file.test_data.date_time                              ;
Report_info.Tester_name       = proc_file.test_data.tester_details.Name                    ;
Report_info.Sentinal_no       = proc_file.test_data.tester_details.Sentinal_no             ;
Report_info.SW_version        = SW_version                                                 ;

if isempty(proc_file.test_data.test_parameters.ELR)
Report_info.ELR = 'Unspec';
else 
Report_info.ELR               = proc_file.test_data.test_parameters.ELR                    ;
end


%Report_info.milage            = proc_file.test_data.test_parameters.milage                 ;
Report_info.Notes             = proc_file.test_data.test_parameters.Notes                  ;
Report_info.Track_id          = proc_file.test_data.test_parameters.Track_id               ;
Report_info.contact_wire      = proc_file.test_data.test_parameters.contact_wire           ;

if isempty(proc_file.test_data.test_parameters.Structure_ID)
Report_info.Structure_ID = 'Unspec';
else
Report_info.Structure_ID      = proc_file.test_data.test_parameters.Structure_ID           ;
end %if isempty(proc_file.test_data.test_parameters.Structure_ID)

Report_info.arm_present       = proc_file.test_data.test_parameters.arm_present            ;
Report_info.clamp_location    = proc_file.test_data.test_parameters.clamp_location         ;

if isfield(proc_file.test_data.test_parameters, 'Asset_No')
Report_info.Asset_No          = proc_file.test_data.test_parameters.Asset_No               ;
else
Report_info.Asset_No          = 'Not Specified' ; 
end

if isfield(proc_file.test_data.test_parameters, 'WR')
Report_info.WR                = proc_file.test_data.test_parameters.WR                     ;
else
Report_info.WR                = 'Not Specified'  ;
end

if isfield(proc_file.test_data.test_parameters,'LU_Label_text')
Report_info.LU_Label_text     = proc_file.test_data.test_parameters.LU_Label_text                          ;
else
Report_info.LU_Label_text     = 'Bespoke values'             ;
end


Report_info.file_with_path    = proc_file.test_data.file_with_path                         ;
Report_info.Peak_location_mm  = 1000*PL_inf.DV(PL_inf.mod_val)                             ;
Report_info.Prediction_text   = [Prediction_.Labels{Prediction_.pred_value},'(', Prediction_.txt_insrt,')'];
Report_info.SN_               = SN_;   
Report_info.INI_val               = P_Opts.initial_thresh_options(P_Opts.initial_thresh_index);
end %if str2num(SW_version) ==1


FN__  =  Report_info.file_with_path(max(find(Report_info.file_with_path=='\'))+1:end-4);
if  strcmp (FN__(1:5),'CALIB') ==1 &&  Prog_STATE~=3
msgbox('Can only produce a calibration report at the time it was done')
else
% now create the uifigure 
    Pix_SS = get(0,'screensize');
    x_mult = Pix_SS(3)/1920;
    y_mult = Pix_SS(4)/1080;
    fig = uifigure('Resize','on','Units','normalized','Position',[0.0100 0.0500 0.3500 0.7940],'Name', 'Test Report');
    fig.Icon = 'ICON2.png';
    px_LH = 10; py_LH = 10; px_SZ = 653; py_SZ = 830;
    p1 = uipanel(fig,'Position',[x_mult*px_LH y_mult*py_LH x_mult*px_SZ y_mult*py_SZ],'AutoResizeChildren','off');
    p1.BorderColor = [0,0,0]   ;
    
         
    if Prog_STATE~=3
         label_Title = uilabel(p1,'Text','\underline{Rightlines Test Report}','Position',[x_mult*170 y_mult*770 x_mult*400 y_mult*52 ],'FontSize',y_mult*30,'Interpreter','Latex');
      else
         label_Title = uilabel(p1,'Text','\underline{Rightlines Calibration}','Position',[x_mult*170 y_mult*770 x_mult*400 y_mult*52 ],'FontSize',y_mult*30,'Interpreter','Latex'); 
    end
   
    % Tester details %%%%%%%%%%%%%%%%%%
    px2_LH = 20; py2_LH = 580; px2_SZ = 630; py2_SZ = 180;
    p2 = uipanel(fig,'Position',[x_mult*px2_LH y_mult*py2_LH x_mult*px2_SZ y_mult*py2_SZ],'AutoResizeChildren','off');
    
    TD_string = char(datetime(Report_info.date_time));
    date_str =  TD_string(1:find(TD_string == ' ')-1);
    time_str =  TD_string(find(TD_string == ' ')+1:end);   

    % Tester
    label_tester_ST           = uilabel(p2,'Text', '\underline{Operator}','Position',[x_mult*10 y_mult*140 x_mult*300 y_mult*40],'FontSize',y_mult*16,'Interpreter','Latex');
    
    
    
    label_Operator            = uilabel(p2,'Text',[Report_info.Tester_name,', (Sentinal# ',num2str(Report_info.Sentinal_no),').'],'Position',[x_mult*10 y_mult*120 x_mult*300 y_mult*40],'FontSize',y_mult*14,'Interpreter','Latex');
    label_DateTime            = uilabel(p2,'Text',['Test Date: ',date_str,' (',time_str,').'],'Position',[x_mult*10 y_mult*100 x_mult*300 y_mult*40],'FontSize',y_mult*14,'Interpreter','Latex');
    label_Notes               = uilabel(p2,'Text','\underline{Notes}','Position',[x_mult*10 y_mult*60 x_mult*300 y_mult*40],'FontSize',y_mult*14,'Interpreter','Latex');
    label_Notes_val           = uilabel(p2,'Text',[Report_info.Notes],'Position',[x_mult*10 y_mult*0 x_mult*220 y_mult*90],'FontSize',y_mult*14,'Interpreter','Latex','WordWrap',"on"); 
    

    % Test information %%%%%%%%%%%
    
    label_test_info_ST        = uilabel(p2,'Text', '\underline{Location and line information}','Position',[x_mult*300 y_mult*140 x_mult*300 y_mult*40],'FontSize',y_mult*16,'Interpreter','Latex');
    
    label_location             = uilabel(p2,'Text',['Location: ',Report_info.LU_Label_text],'Position',[x_mult*300 y_mult*120 x_mult*300 y_mult*40],'FontSize',y_mult*14,'Interpreter','Latex'); 
    
    label_Structure_ID        = uilabel(p2,'Text',['Structure ID: ',Report_info.Structure_ID,'.'],'Position',[x_mult*300 y_mult*90 x_mult*300 y_mult*40],'FontSize',y_mult*14,'Interpreter','Latex'); 
    
    
        
    label_ELR                 = uilabel(p2,'Text',['ELR: ',Report_info.ELR,','],                  'Position',[x_mult*300 y_mult*70 x_mult*120 y_mult*40],'FontSize',y_mult*14,'Interpreter','Latex');
    label_Asset_No            = uilabel(p2,'Text',['Asset No: ',Report_info.Asset_No,'.'],            'Position',[x_mult*450 y_mult*70 x_mult*200 y_mult*40],'FontSize',y_mult*14,'Interpreter','Latex'); 
    
    label_Track_ID            = uilabel(p2,'Text',['Track ID: ',Report_info.Track_id,','],        'Position',[x_mult*300 y_mult*50 x_mult*120 y_mult*40],'FontSize',y_mult*14,'Interpreter','Latex');
    label_WR                 = uilabel(p2,'Text',['Wire run: ',Report_info.WR,'.']      ,               'Position',[x_mult*450 y_mult*50 x_mult*200 y_mult*40],'FontSize',y_mult*14,'Interpreter','Latex');

    
    label_arm_present         = uilabel(p2,'Text',['Arm present: ',Report_info.arm_present,','],'Position',[x_mult*300 y_mult*30 x_mult*140 y_mult*40],'FontSize',y_mult*14,'Interpreter','Latex'); 
    label_clamp_location      = uilabel(p2,'Text',['Clamp location: ',Report_info.clamp_location,'.'],'Position',[x_mult*450 y_mult*30 x_mult* 170 y_mult*40],'FontSize',y_mult*14,'Interpreter','Latex');   
    

    label_Contact_wire        = uilabel(p2,'Text',['Wire size: ',Report_info.contact_wire,'.'],'Position',[x_mult*300 y_mult*10 x_mult*300 y_mult*40],'FontSize',y_mult*14,'Interpreter','Latex');
    
    
    



    



    
    %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
    



    % Data Checks
    px3_LH = 20; py3_LH = 335; px3_SZ = 630; py3_SZ = 240;
    p3                        = uipanel(fig,'Position',[x_mult*px3_LH y_mult*py3_LH x_mult*px3_SZ y_mult*py3_SZ],'AutoResizeChildren','off');
    
    label_data_checks_ST      =  uilabel(p3,'Text','\underline{Data checks}' ,'Position',[x_mult*10 y_mult*190 x_mult*300 y_mult*40],'FontSize',y_mult*16,'Interpreter','Latex');
    label_file_with_path      =  uilabel(p3,'Text',['Data File:     ', Report_info.file_with_path],'Position',[x_mult*10 y_mult*170 x_mult*650 y_mult*40],'FontSize',y_mult*14);
       
        
    label_Instr_serial        =  uilabel(p3,'Text',['Instrument Serial No: ',Report_info.SN_],'Position',[x_mult*10 y_mult*150 x_mult*550 y_mult*40],'FontSize',y_mult*14);
        
    label_soft_version         =  uilabel(p3,'Text',['Software version #: ',Report_info.SW_version],'Position',[x_mult*300 y_mult*150 x_mult*550 y_mult*40],'FontSize',y_mult*14);
    
    label_In_Thresh       =  uilabel(p3,'Text',['Inital Thresh: ',num2str(Report_info.INI_val),'.'],'Position',[x_mult*10 y_mult*130 x_mult*550 y_mult*40],'FontSize',y_mult*14);

    %Report_info.INI_val
    
    % peak_test_insert
    pass_val_ =  round(Report_info.Peak_location_mm);
    PT_accpt = 1;
    peak_test_insert = 'OK';
    if pass_val_< dist_pass_val(1)
    peak_test_insert = ['FAIL: too close (<', num2str(dist_pass_val(1)),'mm).'];
    PT_accpt = 0;
    end
    if pass_val_> dist_pass_val(2)
    peak_test_insert = ['FAIL: too far away  (>', num2str(dist_pass_val(2)),'mm).'];
    PT_accpt = 0;
    end

    if isempty(T_num)
    SN_insert2 = 'OK';
    SN_insert1 = 'All chans good';
    SN_accpt = 1;
    else
    SN_insert2 = 'FAIL: low Signal ';
    SN_insert1 = ['Low on chans#: ',num2str(T_num),'.'];
    SN_accpt = 0;
    end

    % need actual values in here-  currently just a placeholder

    cap_result =  proc_file.test_data.raw_data.cap_test_result.z   ;
        
    b_temp = log10((cap_result(1:12,1)./cap_result(1:12,end)))'    ;
    
    cap_fail_chns = find(b_temp<capacitance_thresholds(2) );
    cap_text = '';
    if ~isempty (cap_fail_chns)  
    cap_text = 'Low: ';
    for index = 1:length(cap_fail_chns)
    if index == length(cap_fail_chns)
    insert_ = '.';
    else
    insert_ = ',';    
    end
    cap_text = [cap_text , num2str(cap_fail_chns(index)),'(',num2str(round(b_temp(cap_fail_chns(index))*10)/10)  ,')',insert_] ; 
    end %for index = 1:length(cap_fail_chns)
    end %if ~isempty (cap_fail_chns)  

    CC_insert1 = cap_text;

    if isempty(find(b_temp < capacitance_thresholds(2) ))
    CC_insert2 = 'OK'; 
    CC_accpt = 1 ;
    else
    shts = find(b_temp < capacitance_thresholds(1));
    if length(shts)>0
    sht_chs =  ['(sh: ', sprintf('%d ', shts),'),'];
       else
    sht_chs = '';
    end
    errs  = find(b_temp < capacitance_thresholds(2) & b_temp > capacitance_thresholds(1));
    
    if length(errs)>0
    err_chs =  ['(er: ', sprintf('%d ', errs),')'];
       else
    err_chs = '';
    end
    
    CC_insert2 = ['FAIL,',sht_chs,err_chs] ; 
    CC_accpt = 0 ;
    end

    label_Peak_1  = uilabel(p3,'Text','Peak (3-3) location:','Position',[x_mult*10 y_mult*100 x_mult*200 y_mult*40],'FontSize',y_mult*14,'Interpreter','Latex');
    label_Peak_2  = uilabel(p3,'Text',[num2str(pass_val_),' mm.   '],'Position',[x_mult*10 y_mult*80 x_mult*200 y_mult*40],'FontSize',y_mult*14,'Interpreter','Latex');
    label_Peak_3  = uilabel(p3,'Text',peak_test_insert,'Position',[x_mult*390 y_mult*100 x_mult*300 y_mult*40],'FontSize',y_mult*14,'Interpreter','Latex');
    
    label_SN_1    = uilabel(p3,'Text','Signal to Noise:','Position',[x_mult*10 y_mult*60 x_mult*200 y_mult*40],'FontSize',y_mult*14,'Interpreter','Latex');
    label_SN_2    = uilabel(p3,'Text',SN_insert1,'Position',[x_mult*10 y_mult*40 x_mult*300 y_mult*40],'FontSize',y_mult*14,'Interpreter','Latex');
    label_SN_3    = uilabel(p3,'Text',SN_insert2,'Position',[x_mult*390 y_mult*60 x_mult*200 y_mult*40],'FontSize',y_mult*14,'Interpreter','Latex');

    label_CC_1    = uilabel(p3,'Text','Capacitance check:','Position',[x_mult*10 y_mult*20 x_mult*200 y_mult*40],'FontSize',y_mult*14,'Interpreter','Latex');
    label_CC_2    = uilabel(p3,'Text',CC_insert1,'Position',[x_mult*10 y_mult*0 x_mult*400 y_mult*40],'FontSize',y_mult*14,'Interpreter','Latex');
    label_CC_3    = uilabel(p3,'Text',CC_insert2,'Position',[x_mult*390 y_mult*20 x_mult*250 y_mult*40],'FontSize',y_mult*14,'Interpreter','Latex');
    
    px4_LH = 20; py4_LH = 50; px4_SZ = 630; py4_SZ = 260;
    p4 = uipanel(fig,'Position',[x_mult*px4_LH y_mult*py4_LH x_mult*px4_SZ y_mult*py4_SZ],'AutoResizeChildren','off');
    label_data_checks_ST      = uilabel(p4,'Text','\underline{Result}' ,'Position',[x_mult*10 y_mult*210 x_mult*300 y_mult*40],'FontSize',y_mult*16,'Interpreter','Latex');

    if PT_accpt==1 &&  SN_accpt==1 && CC_accpt==1 
    pred_txt = [Prediction_.Labels{Prediction_.pred_value},' (',Prediction_.txt_insrt,')'];
    else   
    pred_txt = 'Invalid test (see data checks)';
    end %if PT_accpt==1 &&  SN_accpt==1 && CC_accpt==1 

    label_Pred_1    = uilabel(p4,'Text',['Prediction: ',pred_txt],'Position',[x_mult*10 y_mult*100 x_mult*500 y_mult*100],'FontSize',y_mult*25,'Interpreter','Latex');





% create this at the file open - put it in the defaults options
answer_ = questdlg('Save the report?','Report',	'Yes','No','Yes');

if strcmp(answer_,'Yes')
% now create the file name and file structure and save there
p_w_d =  pwd;
cd([slab_root,default_options.report_data_file_path]) % create this at the file open 

year_    =  Report_info.date_time(1) ;
month_   =  Report_info.date_time(2) ;
day_     =  Report_info.date_time(3) ;

if ~exist(num2str(year_))
mkdir(num2str(year_))
cd (num2str(year_))
else
cd (num2str(year_))
end %if ~exist(num2str(year_))

if ~exist(num2str(month_))
mkdir(num2str(month_))
cd (num2str(month_))
else
cd (num2str(month_))
end %if ~exist(num2str(year_))

if ~exist(num2str(day_))
mkdir(num2str(day_))
cd (num2str(day_))
else
cd (num2str(day_))
end %if ~exist(num2str(year_))
target_fn = [Report_info.file_with_path(max(find(Report_info.file_with_path=='\'))+1:end-4),'.pdf'];

if exist(target_fn) == 0
new_target_fn = target_fn;
else
dum = dir([target_fn(1:end-4),'*.pdf']);
files_= {dum.name};
num_insrt = num2str(length(files_));
new_target_fn = [target_fn(1:end-4),'_',num_insrt,'.pdf'];       
end %if exist(target_fn) == 0
exportapp(fig,new_target_fn)
cd(p_w_d) 
end %ifstrcmp(answer_,'Yes')
end %if  strcmp (FN__(1:5),'CALIB') ==1 &&  Prog_STATE~=3

end %function Produce_Test_report(TPs,RI,PL_inf,T_num)


