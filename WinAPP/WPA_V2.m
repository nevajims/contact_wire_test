classdef WPA_V2 < matlab.apps.AppBase

    % Properties that correspond to app components
    properties (Access = public)
        UIFigure                       matlab.ui.Figure
        Sentinal_LabelVAL2             matlab.ui.control.Label
        USERLabel_val2                 matlab.ui.control.Label
        PredictionLamp                 matlab.ui.control.Lamp
        PredictionLampLabel            matlab.ui.control.Label
        CheckProcessLamp               matlab.ui.control.Lamp
        CheckProcessLampLabel          matlab.ui.control.Label
        DataloadedLamp                 matlab.ui.control.Lamp
        DataloadedLampLabel            matlab.ui.control.Label
        LoginLamp                      matlab.ui.control.Lamp
        LoginLampLabel                 matlab.ui.control.Label
        SentinalLabel_2                matlab.ui.control.Label
        UserLabel                      matlab.ui.control.Label
        Program_version_label          matlab.ui.control.Label
        CONTACTWireTestLabel           matlab.ui.control.Label
        ProgMODELabel                  matlab.ui.control.Label
        TabGroup                       matlab.ui.container.TabGroup
        LoginTab                       matlab.ui.container.Tab
        Level_label_val                matlab.ui.control.Label
        LevelLabel                     matlab.ui.control.Label
        Sentinal_label_val             matlab.ui.control.Label
        Cur_Log_in_Label_Val           matlab.ui.control.Label
        SentinalLabel                  matlab.ui.control.Label
        CurrentlyloggedinLabel         matlab.ui.control.Label
        LOGINButton                    matlab.ui.control.Button
        DISP_settButton                matlab.ui.control.Button
        CALButton                      matlab.ui.control.Button
        TestSettingsTab                matlab.ui.container.Tab
        GetTransducerDetailsButton     matlab.ui.control.Button
        TestSettingsButton             matlab.ui.control.Button
        ClearCurrentDataButton         matlab.ui.control.Button
        Notes_val                      matlab.ui.control.Label
        Test_DandT_val                 matlab.ui.control.Label
        Cur_dat_set_val                matlab.ui.control.Label
        NotesLabel                     matlab.ui.control.Label
        TestDateandTimeLabel           matlab.ui.control.Label
        CurrentDataSetLabel            matlab.ui.control.Label
        LoadExistingDataButton         matlab.ui.control.Button
        RunNewTestButton               matlab.ui.control.Button
        CheckProcessTab                matlab.ui.container.Tab
        ClearprocesseddataButton       matlab.ui.control.Button
        SignalQualityIndicatorsButton  matlab.ui.control.Button
        ChanTimeandFreqViewerButton    matlab.ui.control.Button
        DisplaySNRBarChartsButton      matlab.ui.control.Button
        SNRSettingsButton              matlab.ui.control.Button
        DisplaySNRMapsButton           matlab.ui.control.Button
        ProcessDataButton              matlab.ui.control.Button
        CheckSignalQualityButton       matlab.ui.control.Button
        PredictionTab                  matlab.ui.container.Tab
        ProduceareportButton           matlab.ui.control.Button
        Label_PL                       matlab.ui.control.Label
        PeakLocationmmLabel            matlab.ui.control.Label
        MPRCvsTagButton                matlab.ui.control.Button
        ClearPredictionsButton         matlab.ui.control.Button
        ModeMapTagsButton              matlab.ui.control.Button
        PLamp                          matlab.ui.control.Lamp
        PLampLabel                     matlab.ui.control.Label
        ShowDispersionButton           matlab.ui.control.Button
        ShowMeshButton                 matlab.ui.control.Button
        DistanceMeanTableButton        matlab.ui.control.Button
        LogLikelyhoodTableButton       matlab.ui.control.Button
        InteractiveMMViewerButton      matlab.ui.control.Button
        ShowPeakFindButton             matlab.ui.control.Button
        ViewModeMapButton              matlab.ui.control.Button
        MeanSTDmodesButton             matlab.ui.control.Button
        PredsButton                    matlab.ui.control.Button
        PREDICTIONButton               matlab.ui.control.Button
        ModePairViewerFDButton         matlab.ui.control.Button
        SetPredictionOptionsButton     matlab.ui.control.Button
                 
    end

    
    properties (Access = private)
    Property % Description
    
    
    location_of_default_options =  '\SETTINGS_FILES\default_options2.mat';
    current_test_folder         =  '';

    slab_root     = [getenv('systemDrive'),getenv('homePath')];
    settings_root = [getenv('APPDATA')];
    
default_option_fields       =  {'raw_data_file_options';...
                                'raw_data_file_type';...
                                'login_options_fname';...
                                'plot_options_fname';...
                                'snr_settings_fname';...
                                'test_parameters_fname';...
                                'Test_Settings_fname';...
                                'proc_options_fname';...        
                                'raw_data_file_path';...
                                'report_data_file_path';...
                                'login_options_fields';...
                                'plot_options_fields';...
                                'snr_settings_fields';...
                                'test_parameters_fields';...
                                'Test_Settings_fields';...
                                'proc_options_fields';...
                                'display_settings_fields';...
                                'display_settings_fname'
                                } ;

    default_options             = [];
    login_details               = []; 
    login_options               = [];
    plot_options                = [];
    snr_settings                = [];
    test_parameters             = [];
    Test_Settings               = [];
    proc_options                = [];
    test_parameters_choices     = [];
    test_data                   = [];
    rail_tester                 = [];
    display_settings            = [];

    status_                     =  1;        
    
    %status info

    %mag_fac_options            = 
    mag_fac                     =  1.82      ; % magnifation factor of the windows   
                                            % {'Min';'size 2';'size 3';'size 4';'size 5';'size 6';'Max'}
                                            % [0.6;0.8;1.0;1.2;1.4;1.6;1.82]

    Prog_STATE                =  1         ;  % 1-View  2-Test  3-Calibrate  %%%% add 4th CHECK
    have_test_data            =  0         ;  
    have_processed_data       =  0         ;
    login_level               =  0         ;
    prediction_done           =  0         ;  
    prediction_figure_handle  = [] ;
    Pix_SS                    = get(0,'screensize')   ;
    base_width                = 1920                  ; 
    base_height               = 1080                  ; 
    

    %status info
    end
    
    
    methods (Access = private)
        
        function  get_status(app)

         if app.have_test_data == 0 && app.have_processed_data == 0 && app.prediction_done ==0
         app.status_ = 1 ;
         elseif  app.have_test_data == 1 && app.have_processed_data == 0 && app.prediction_done ==0
         app.status_ = 2 ;             
         elseif  app.have_test_data == 1 && app.have_processed_data == 1 && app.prediction_done ==0
         app.status_ = 3 ;
         elseif  app.have_test_data == 1 && app.have_processed_data == 1 && app.prediction_done ==1
         app.status_ = 4 ;
         else
         app.status_ = 1 ;
         msgbox ('Status Unclear - check')
         end  % if app.have_test_data   ........

        end %        function  get_status(app)


        function set_status(app)
            
        switch(app.status_)  
            case(1)
            set_Tab_2(app,1)
            set_Tab_3(app,0)
            set_Tab_4(app,0)
            set_3lights(app,[0 0 0])
            if ishandle(app.prediction_figure_handle)
                close(app.prediction_figure_handle)
                app.prediction_figure_handle = [] ;
            end %if ishandle(app.prediction_figure_handle)
            
            case(2)
            set_Tab_2(app,0)
            set_Tab_3(app,1)
            set_Tab_4(app,0)
            set_3lights(app,[1 0 0])
            if ishandle(app.prediction_figure_handle)
                close(app.prediction_figure_handle)
                app.prediction_figure_handle = [] ;
            end %if ishandle(app.prediction_figure_handle)

            case(3)
            set_Tab_2(app,0)
            set_Tab_3(app,0)
            set_Tab_4(app,1)  % P light off    /   prediction on
            set_3lights(app,[1 1 0])

            case(4)
            set_Tab_2(app,0)
            set_Tab_3(app,0)
            set_Tab_4(app,2)  % P light on     /  prediction off 
            set_3lights(app,[1 1 1])

        end %switch(app.status_)  
        end %function set_status(app)
        



        function set_Tab_2(app,switch_val)

           switch(switch_val)
               case(1)
               app.RunNewTestButton.Enable              ='on';  
               app.LoadExistingDataButton.Enable        = 'on';     
               app.TestSettingsButton.Enable            = 'on';
               GetTransducerDetailsButtonPushed.Enable  = 'on';
               case(0)
               app.RunNewTestButton.Enable            ='off';  
               app.LoadExistingDataButton.Enable     = 'off';      
               app.TestSettingsButton.Enable         = 'off';
               GetTransducerDetailsButtonPushed.Enable  = 'off';
           end %        function set_Tab_2(app,switch_val)
        
        if app.Prog_STATE ==  3  % i.e. calibrate state
           app.LoadExistingDataButton.Enable     = 'off';      
        end
        
        
        end

         function set_Tab_3(app,switch_val)

           switch(switch_val)
               case(1)
                app.CheckSignalQualityButton.Enable  ='on'; 
                app.ProcessDataButton.Enable         ='on'; 
                app.DisplaySNRMapsButton.Enable      ='on';    
                app.DisplaySNRBarChartsButton.Enable ='on'; 
                app.ChanTimeandFreqViewerButton.Enable ='on'; 
                app.SignalQualityIndicatorsButton.Enable ='on';

               case(0)
                app.CheckSignalQualityButton.Enable  ='off'; 
                app.ProcessDataButton.Enable         ='off'; 
                app.DisplaySNRMapsButton.Enable      ='off';    
                app.DisplaySNRBarChartsButton.Enable ='off'; 
                app.ChanTimeandFreqViewerButton.Enable ='off'; 
                app.SignalQualityIndicatorsButton.Enable ='off'; 
                end   

                switch(app.login_level)
                    case(2)
                    app.DisplaySNRMapsButton.Visible      = 'on';
                    app.DisplaySNRBarChartsButton.Visible = 'on';
                    app.DisplaySNRBarChartsButton.Visible = 'on'; 
                    app.SNRSettingsButton.Visible         = 'on';  
                    otherwise
                    app.DisplaySNRMapsButton.Visible      = 'off';
                    app.DisplaySNRBarChartsButton.Visible = 'off';
                    app.DisplaySNRBarChartsButton.Visible = 'off'; 
                    app.SNRSettingsButton.Visible         = 'off';  
                end %                switch(app.login_level)


           end %        function set_Tab_3(app,switch_val)

         function set_Tab_4(app,switch_val)

           switch(switch_val)
            
               case(0)
            app.PREDICTIONButton.Enable         ='off';
            app.ModePairViewerFDButton.Enable   ='off';
            app.ViewModeMapButton.Enable        ='off';
            app.PredsButton.Enable              ='off';
            app.ShowPeakFindButton.Enable       ='off';
            app.DistanceMeanTableButton.Enable  ='off';
            app.LogLikelyhoodTableButton.Enable ='off';
            app.ModeMapTagsButton.Enable        ='off';
            app.ShowDispersionButton.Enable     ='off';
            app.ShowMeshButton.Enable           ='off';
            app.MeanSTDmodesButton.Enable       ='off';   
            app.InteractiveMMViewerButton.Enable='off';
            app.MPRCvsTagButton.Enable          ='off';
            app.SetPredictionOptionsButton.Enable ='on'; 
            app.ProduceareportButton.Enable     ='off'; 
            app.ClearPredictionsButton.Enable   ='off'; 

                case(1)
            app.PREDICTIONButton.Enable         ='on';
            app.ModePairViewerFDButton.Enable   ='on';
            app.ViewModeMapButton.Enable        ='on';
            app.PredsButton.Enable              ='on';
            app.ShowPeakFindButton.Enable       ='on';
            app.DistanceMeanTableButton.Enable  ='on';
            app.LogLikelyhoodTableButton.Enable ='on';
            app.ModeMapTagsButton.Enable        ='on';
            app.ShowDispersionButton.Enable     ='on';
            app.ShowMeshButton.Enable           ='on';
            app.MeanSTDmodesButton.Enable       ='on';   
            app.InteractiveMMViewerButton.Enable='on';   
            app.MPRCvsTagButton.Enable          ='on';
            app.SetPredictionOptionsButton.Enable  ='on';
            app.ProduceareportButton.Enable     ='on'; 
            app.ClearPredictionsButton.Enable   ='on'; 


                case(2)
            app.PREDICTIONButton.Enable         ='off';
            app.ModePairViewerFDButton.Enable   ='on';
            app.ViewModeMapButton.Enable        ='on';
            app.PredsButton.Enable              ='on';
            app.ShowPeakFindButton.Enable       ='on';
            app.DistanceMeanTableButton.Enable  ='on';
            app.LogLikelyhoodTableButton.Enable ='on';
            app.ModeMapTagsButton.Enable        ='on';
            app.ShowDispersionButton.Enable     ='on';
            app.ShowMeshButton.Enable           ='on';
            app.MeanSTDmodesButton.Enable       ='on';   
            app.InteractiveMMViewerButton.Enable='on'; 
            app.MPRCvsTagButton.Enable          ='on';
            app.SetPredictionOptionsButton.Enable ='on';
            app.ProduceareportButton.Enable     ='on'; 
            app.ClearPredictionsButton.Enable   ='on'; 
           end   

           if app.Prog_STATE ==  3  % i.e. calibrate state
           app.SetPredictionOptionsButton.Enable      ='off';
           end %app.SetPredictionOptionsButton      ='off';
           
           switch(app.login_level)
                    case(2)
                   app.ModePairViewerFDButton.Visible   ='on';  
                   app.ViewModeMapButton.Visible        ='on';  
                   app.ShowPeakFindButton.Visible       ='on';  
                   app.PredsButton.Visible              ='on'; 
                   app.DistanceMeanTableButton.Visible  ='on'; 
                   app.LogLikelyhoodTableButton.Visible ='on';
                   app.ModeMapTagsButton.Visible        ='on';
                   app.ShowDispersionButton.Visible     ='on';
                   app.ShowMeshButton.Visible           ='on';
                   app.MeanSTDmodesButton.Visible       ='on';   
                   app.InteractiveMMViewerButton.Visible='on'; 
                   app.MPRCvsTagButton.Visible          ='on';
                   
               otherwise

                   app.ModePairViewerFDButton.Visible   ='on';  
                   app.ViewModeMapButton.Visible        ='on';  
                   app.ShowPeakFindButton.Visible       ='on';  
                   app.MPRCvsTagButton.Visible          ='off';     
                   app.ModeMapTagsButton.Visible        ='off';
                   app.PredsButton.Visible              ='off'; 
                   app.DistanceMeanTableButton.Visible  ='off';     
                   app.LogLikelyhoodTableButton.Visible ='off';
                   app.ShowDispersionButton.Visible     ='off';
                   app.ShowMeshButton.Visible           ='off';
                   app.MeanSTDmodesButton.Visible       ='off';   
                   app.InteractiveMMViewerButton.Visible='off'; 
                   
          end      % switch(app.login_level) 

         

           end %        function set_Tab_3(app,switch_val)
           
           function        set_3lights(app,switches_3)
           
            switch  switches_3(1)
                case(1)
                    app.DataloadedLamp.Color =   [0,1,0];
                case(0)
                    app.DataloadedLamp.Color =   [1,0,0];
            end

            switch  switches_3(2)
                case(1)
                    app.CheckProcessLamp.Color =   [0,1,0];
                case(0)
                    app.CheckProcessLamp.Color =   [1,0,0];
            end

           switch  switches_3(3)
               case(1)
                    app.PredictionLamp.Color  =   [0,1,0];
                case(0)
                    app.PredictionLamp.Color  =   [1,0,0];
            end

           end     %function        set_3lights(app,switches_3)


    end %methods (Access = private)

    

    % Callbacks that handle component events
    methods (Access = private)

       % Code that executes after component creation
       function startupFcn(app)

       app.UIFigure.Icon='ICON2.png';
       app.UIFigure.Name = 'Traxion-NDT';

       if exist([app.settings_root,'\SETTINGS_FILES']) ~= 7  
       try
       mkdir([app.settings_root,'\SETTINGS_FILES'])
       msgbox(['created folder: ', app.settings_root,'\SETTINGS_FILES'])
       catch
       msgbox(['problem creating folder: ',app.settings_root,'\SETTINGS_FILES'])
       end %try
       end %if exist([app.settings_root,'\SETTINGS_FILES']) ~= 7  
       
       if exist([app.slab_root,'\SLAB_data']) ~= 7
       try
       mkdir([app.slab_root ,'\SLAB_data']) ; 
       msgbox(['created folder: ', app.slab_root ,'\SLAB_data'])
       catch
       msgbox(['problem creating folder: ', app.slab_root ,'\SLAB_data'])
       end %try
       end %if exist([getenv('systemDrive'),getenv('homePath'),'\SLAB_data']) ~= 7
       


       if exist([app.slab_root,'\REPORT_data']) ~= 7
       try
       mkdir([app.slab_root ,'\REPORT_data']) ; 
       msgbox(['created folder: ', app.slab_root ,'\REPORT_data'])
       catch
       msgbox(['problem creating folder: ',app.slab_root ,'\REPORT_data'])
       end %try
       end %if exist([getenv('systemDrive'),getenv('homePath'),'\SLAB_data']) ~= 7
       



            [app.default_options, ~]  =  load_mat_structure_from_file([pwd,app.location_of_default_options],app.default_option_fields) ; 


            if exist([app.settings_root,app.default_options.plot_options_fname ]) ~=2
            try
            msgbox('copying plot_options file from installation to roaming')
            copyfile([pwd,app.default_options.plot_options_fname ],[app.settings_root,app.default_options.plot_options_fname ]); 
            catch
            msgbox('error copying')    
            end
            
            else
            end    %if exist([app.settings_root,app.default_options.plot_options_fname ]) ~=2

            if exist([app.settings_root,app.default_options.snr_settings_fname]) ~=2
            try
            msgbox('copying snr_settings file from installation to roaming')   
            copyfile([pwd,app.default_options.snr_settings_fname],[app.settings_root,app.default_options.snr_settings_fname]); 
            catch
            msgbox('error copying')    
            end
            
            else
            end    %if exist([app.settings_root,app.default_options.snr_settings_fname]) ~=2



            if exist([app.settings_root,app.default_options.test_parameters_fname]) ~=2
            try
            msgbox('copying test_parameters file from installation to roaming')
            copyfile([pwd,app.default_options.test_parameters_fname],[app.settings_root,app.default_options.test_parameters_fname]); 
            catch
            msgbox('error copying')    
            end
            end    %if exist([app.settings_root,app.default_options.test_parameters_fname]) ~=2

            if exist([app.settings_root,app.default_options.Test_Settings_fname]) ~=2
            try
            msgbox('copying Test_Settings file from installation to roaming')
            copyfile([pwd,app.default_options.Test_Settings_fname],[app.settings_root,app.default_options.Test_Settings_fname]); 
            catch
            msgbox('error copying')    
            end
            else
            end    %if exist([app.settings_root,app.default_options.Test_Settings_fname]) ~=2
                        
            if exist([app.settings_root,app.default_options. proc_options_fname]) ~=2
            try
            msgbox('copying proc_options_fname file from installation to roaming')                
            copyfile([pwd,app.default_options.proc_options_fname] , [app.settings_root,app.default_options.proc_options_fname]) ; 
            catch
            msgbox('error copying')    
            end
            else
            end    %if exist([app.settings_root,app.default_options. proc_options_fname]) ~=2



            if exist([app.settings_root,app.default_options.display_settings_fname]) ~=2
            try
            msgbox('copying display_settings_fname file from installation to roaming')                
            copyfile([pwd,app.default_options.display_settings_fname] , [app.settings_root,app.default_options.display_settings_fname]) ; 
            catch
            msgbox('error copying')    
            end
            else
            end    %if exist([app.settings_root,app.default_options. proc_options_fname]) ~=2
 





            
      try  
      app.login_options        =    load_mat_structure_from_file([pwd,app.default_options.login_options_fname],...
                                    app.default_options.login_options_fields);                        
      catch
      msgbox(['error loading.....', pwd,app.default_options.login_options_fname])          
      end
       
      try
      app.plot_options         =    load_mat_structure_from_file([app.settings_root,app.default_options.plot_options_fname],...
                                    app.default_options.plot_options_fields);
      catch
      msgbox(['error loading.....', app.settings_root,app.default_options.plot_options_fname])          
      end

      try
      app.snr_settings         =    load_mat_structure_from_file([app.settings_root,app.default_options.snr_settings_fname],...
                                    app.default_options.snr_settings_fields);
      
      catch
      msgbox(['error loading.....', app.settings_root,app.default_options.snr_settings_fname])          
      end
      
      try 
      app.test_parameters      =    load_mat_structure_from_file([pwd,app.default_options.test_parameters_fname],...
                                    app.default_options.test_parameters_fields);
      catch
      msgbox(['error loading.....',pwd,app.default_options.test_parameters_fname])    
      end
     
      try
      app.Test_Settings        =    load_mat_structure_from_file([app.settings_root,app.default_options.Test_Settings_fname],...
                                    app.default_options.Test_Settings_fields);
      catch
      msgbox(['error loading.....',app.settings_root,app.default_options.Test_Settings_fname])      
      end
      
      try
      app.proc_options         =    load_mat_structure_from_file([app.settings_root,app.default_options.proc_options_fname],...
                                    app.default_options.proc_options_fields);

      catch
      msgbox(['error loading.....',app.settings_root,app.default_options.proc_options_fname])    
      end

      old_value_temp = app.mag_fac;

       try
       app.display_settings         =    load_mat_structure_from_file([app.settings_root,app.default_options.display_settings_fname],...
                                     app.default_options.display_settings_fields);
       catch
       msgbox(['error loading.....',app.settings_root,app.default_options.display_settings_fname])    
       end

      
      app.mag_fac  =    app.display_settings.options.mag_values(app.display_settings.choices.mag);
      if app.mag_fac ~= old_value_temp
      reset_window_sizes(app) 
      end           


      app.LoginLamp.Color =   [1,0,0]; 
      app.get_status
      app.set_status
      app.RunNewTestButton.Enable    ='off';
      app.TestSettingsButton.Enable  = 'off';

 %    app.UIFigure.Units = 'normalized';
 %    app.UIFigure.Position = [0.6 0.45 0.3818 0.5120];
 %    app.UIFigure.Resize = 'Off';
 

       end %startupFcn(app)


function DSbuttonPushed (app, event)
      
      old_mag_val =   app.mag_fac;
      FDSF_temp   =   [pwd,app.default_options.display_settings_fname]                   ; 
      SF_temp     =   [app.settings_root,app.default_options.display_settings_fname]     ;
      
      dum = set_display_settings(app.display_settings,FDSF_temp,SF_temp,app.base_width,app.base_height,app.mag_fac); 
      
      if isstruct(dum)
      app.display_settings = dum;      
      app.mag_fac  =    app.display_settings.options.mag_values(app.display_settings.choices.mag);
      
      if old_mag_val ~=  app.mag_fac   
      reset_window_sizes(app)
      end
      end %if isstruct(app.display_settings)

end % function DSbuttonPushed (app, event)


function reset_window_sizes(app)

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Pix_SS = get(0,'screensize')              ;
            x_mult = (Pix_SS(3)/app.base_width)   * app.mag_fac ;
            y_mult = (Pix_SS(4)/app.base_height)  * app.mag_fac ;
            x_mult_o = (Pix_SS(3)/app.base_width) ;
            y_mult_o = (Pix_SS(4)/app.base_height);

            app.UIFigure.Position  = [0.018*x_mult_o 0.024*y_mult_o  0.5120 * app.mag_fac 0.5120 * app.mag_fac];

       
            app.TabGroup.Position = [x_mult*1 y_mult*67 x_mult*980 y_mult*442];
            app.CONTACTWireTestLabel.Position = [x_mult*2 y_mult*513 x_mult*334 y_mult*39];
            app.ProgMODELabel.Position = [x_mult*600 y_mult*515 x_mult*150 y_mult*26];
            app.Program_version_label.Position = [x_mult*340 y_mult*515 x_mult*25 y_mult*22];
            

            app.CONTACTWireTestLabel.FontSize = y_mult*30;
            app.ProgMODELabel.FontSize = y_mult*18;
            app.Program_version_label.FontSize = y_mult*12;            

            %app.TabGroup.Position = [0 0.119 1 0.8 ];

                         

            app.LOGINButton.FontSize = y_mult*36;
            app.LOGINButton.Position = [x_mult*31 y_mult*291 x_mult*191 y_mult*97];
            app.DISP_settButton.FontSize         =  y_mult*20;
            app.DISP_settButton.Position         =  [x_mult*700 y_mult*291 x_mult*191 y_mult*97];
            app.CALButton.FontSize = y_mult*22;   
            app.CALButton.Position = [x_mult*31 y_mult*50 x_mult*200 y_mult*67];
            app.CurrentlyloggedinLabel.FontSize = y_mult*18;
            app.CurrentlyloggedinLabel.Position = [x_mult*293 y_mult*353 x_mult*190 y_mult*23];
            app.SentinalLabel.FontSize = y_mult*18;
            app.SentinalLabel.Position = [x_mult*293 y_mult*298 x_mult*100 y_mult*23];
            app.Cur_Log_in_Label_Val.Position = [x_mult*507 y_mult*353 x_mult*158 y_mult*22];
            app.Cur_Log_in_Label_Val.FontSize = 14*x_mult;
            app.Sentinal_label_val.Position = [x_mult*507 y_mult*298 x_mult*151 y_mult*22];
            app.Sentinal_label_val.FontSize = 14*x_mult; 
            app.LevelLabel.FontSize = y_mult*18;
            app.LevelLabel.Position = [x_mult*293 y_mult*244 x_mult*73 y_mult*23];
            app.Level_label_val.Position = [x_mult*510 y_mult*244 x_mult*155 y_mult*22];
            app.Level_label_val.FontSize = y_mult*14;
            app.RunNewTestButton.FontSize = y_mult*36;
            app.RunNewTestButton.Position = [x_mult*45 y_mult*320 x_mult*273 y_mult*78];
            app.LoadExistingDataButton.FontSize = y_mult*24;
            app.LoadExistingDataButton.Position = [x_mult*45 y_mult*253 x_mult*237 y_mult*39];
            app.CurrentDataSetLabel.Position = [x_mult*45 y_mult*168 x_mult*120 y_mult*22];
            app.CurrentDataSetLabel.FontSize = x_mult*14;
            app.TestDateandTimeLabel.Position = [x_mult*45 y_mult*135 x_mult*130 y_mult*22];
            app.TestDateandTimeLabel.FontSize = x_mult*14;
            app.NotesLabel.Position = [x_mult*45 y_mult*84 x_mult*60 y_mult*22];
            app.NotesLabel.FontSize = x_mult*14;
            app.Cur_dat_set_val.Position = [x_mult*179 y_mult*168 x_mult*480 y_mult*22];
            app.Cur_dat_set_val.FontSize = x_mult*14;
            app.Test_DandT_val.Position = [x_mult*179 y_mult*135 x_mult*468 y_mult*22];
            app.Test_DandT_val.FontSize = x_mult*14;
            app.Notes_val.Position = [x_mult*84 y_mult*12 x_mult*351 y_mult*94];
            app.Notes_val.FontSize = x_mult*14;
            app.ClearCurrentDataButton.FontSize = y_mult*24;
            app.ClearCurrentDataButton.Position = [x_mult*525 y_mult*30 x_mult*179 y_mult*76];
            app.TestSettingsButton.FontSize = y_mult*18;
            app.TestSettingsButton.Position = [x_mult*525 y_mult*343 x_mult*164 y_mult*50];
            app.GetTransducerDetailsButton.FontSize = y_mult*18;
            app.GetTransducerDetailsButton.Position = [x_mult*526 y_mult*270 x_mult*163 y_mult*52];
            app.CheckSignalQualityButton.FontSize = y_mult*24;
            app.CheckSignalQualityButton.Position = [x_mult*37 y_mult*279 x_mult*174 y_mult*96];
            app.ProcessDataButton.FontSize = y_mult*36;
            app.ProcessDataButton.Position = [x_mult*37 y_mult*68 x_mult*253 y_mult*54];
            app.DisplaySNRMapsButton.FontSize = y_mult*14;
            app.DisplaySNRMapsButton.Position = [x_mult*544 y_mult*360 x_mult*175 y_mult*37];
            app.SNRSettingsButton.FontSize = y_mult*24;
            app.SNRSettingsButton.Position = [x_mult*43 y_mult*193 x_mult*179 y_mult*61];
            app.DisplaySNRBarChartsButton.FontSize = y_mult*14;
            app.DisplaySNRBarChartsButton.Position = [x_mult*527 y_mult*309 x_mult*191 y_mult*37];
            app.ChanTimeandFreqViewerButton.FontSize = y_mult*14;
            app.ChanTimeandFreqViewerButton.Position = [x_mult*528 y_mult*253 x_mult*190 y_mult*37];
            app.SignalQualityIndicatorsButton.FontSize = y_mult*14;
            app.SignalQualityIndicatorsButton.Position = [x_mult*544 y_mult*193 x_mult*175 y_mult*37];
            app.ClearprocesseddataButton.Position = [x_mult*519 y_mult*12 x_mult*180 y_mult*56];
            app.ClearprocesseddataButton.FontSize = y_mult*24;
            app.SetPredictionOptionsButton.FontSize = y_mult*24;
            app.SetPredictionOptionsButton.Position = [x_mult*66 y_mult*301 x_mult*170 y_mult*84];
            app.ModePairViewerFDButton.FontSize = y_mult*14;
            app.ModePairViewerFDButton.Position = [x_mult*562 y_mult*376 x_mult*171 y_mult*30];
            app.PREDICTIONButton.FontSize = y_mult*36;
            app.PREDICTIONButton.Position = [x_mult*73 y_mult*132 x_mult*285 y_mult*86];
            app.ModeMapTagsButton.FontSize = y_mult*14;
            app.ModeMapTagsButton.Position = [x_mult*562 y_mult*289 x_mult*171 y_mult*30];
            app.PredsButton.FontSize = y_mult*14;
            app.PredsButton.Position = [x_mult*567 y_mult*121 x_mult*166 y_mult*30];
            app.MeanSTDmodesButton.FontSize = y_mult*14;
            app.MeanSTDmodesButton.Position =[x_mult*569 y_mult*84 x_mult*163 y_mult*30];
            app.MPRCvsTagButton.FontSize = y_mult*14;
            app.MPRCvsTagButton.Position = [x_mult*562 y_mult*256 x_mult*171 y_mult*30];
            app.ViewModeMapButton.FontSize = y_mult*14;
            app.ViewModeMapButton.Position = [x_mult*562 y_mult*349 x_mult*171 y_mult*30];
            app.ShowPeakFindButton.FontSize = y_mult*14;
            app.ShowPeakFindButton.Position = [x_mult*562 y_mult*320 x_mult*171 y_mult*30];
            app.InteractiveMMViewerButton.FontSize = y_mult*14;
            app.InteractiveMMViewerButton.Position = [x_mult*567 y_mult*154 x_mult*166 y_mult*30];
            app.LogLikelyhoodTableButton.FontSize = y_mult*14;
            app.LogLikelyhoodTableButton.Position = [x_mult*567 y_mult*188 x_mult*166 y_mult*30];
            app.DistanceMeanTableButton.FontSize = y_mult*14;
            app.DistanceMeanTableButton.Position = [x_mult*564 y_mult*223 x_mult*171 y_mult*30];
            app.ShowMeshButton.FontSize = y_mult*14;
            app.ShowMeshButton.Position = [x_mult*564 y_mult*5 x_mult*171 y_mult*30];
            app.ShowDispersionButton.FontSize = y_mult*14;
            app.ShowDispersionButton.Position = [x_mult*569 y_mult*39 x_mult*166 y_mult*30];
            app.PLampLabel.Position = [x_mult*382 y_mult*164 x_mult*25 y_mult*22];
            app.PLampLabel.FontSize = 12 * x_mult;
            app.PLamp.Position = [x_mult*422 y_mult*164 x_mult*20 y_mult*20];
            app.ClearPredictionsButton.Position = [x_mult*418 y_mult*5 x_mult*130 y_mult*30];
            app.ClearPredictionsButton.FontSize = 14*y_mult;
            app.PeakLocationmmLabel.Position = [x_mult*274 y_mult*80 x_mult*152 y_mult*22];
            app.PeakLocationmmLabel.FontSize = 14* y_mult;
            app.Label_PL.Position = [x_mult*449 y_mult*80 x_mult*95 y_mult*22];
            app.Label_PL.FontSize = 12 * y_mult;
            app.ProduceareportButton.Position = [x_mult*40 y_mult*12 x_mult*100 y_mult*43];
            app.ProduceareportButton.FontSize = 16 * y_mult;
            
            app.UserLabel.Position = [x_mult*5 y_mult*39 x_mult*54 y_mult*22];
            app.UserLabel.FontSize = y_mult*14;
            app.SentinalLabel_2.Position = [x_mult*5 y_mult*14 x_mult*72 y_mult*22];
            app.SentinalLabel_2.FontSize = y_mult*14;
            app.LoginLampLabel.Position = [x_mult*161 y_mult*28 x_mult*64 y_mult*22];
            app.LoginLampLabel.FontSize =  14*y_mult ;
            app.LoginLamp.Position = [x_mult*240 y_mult*28 x_mult*20 y_mult*20];
            app.DataloadedLampLabel.Position = [x_mult*290 y_mult*28 x_mult*90 y_mult*22];
            app.DataloadedLampLabel.FontSize = y_mult*14; 
            app.DataloadedLamp.Position = [x_mult*391 y_mult*28 x_mult*20 y_mult*20];
            app.CheckProcessLampLabel.Position = [x_mult*427 y_mult*27 x_mult*114 y_mult*22];
            app.CheckProcessLampLabel.FontSize = y_mult*14;
            app.CheckProcessLamp.Position = [x_mult*548 y_mult*27 x_mult*20 y_mult*20];
            app.PredictionLampLabel.Position = [x_mult*582 y_mult*28 x_mult*74 y_mult*22];
            app.PredictionLampLabel.FontSize = y_mult*14; 
            app.PredictionLamp.Position = [x_mult*665 y_mult*28 x_mult*20 y_mult*20];
            app.USERLabel_val2.Position = [x_mult*77 y_mult*40 x_mult*108 y_mult*22];
            app.USERLabel_val2.FontSize   =  14*y_mult ;
            app.Sentinal_LabelVAL2.Position = [x_mult*77 y_mult*15 x_mult*70 y_mult*22];
            app.Sentinal_LabelVAL2.FontSize   =  14*y_mult;
           
            

%app.CONTACTWireTestLabel
%app.ProgMODELabel
%app.Program_version_label



            
           %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

end % function reset_window_sizes(app)



        % Button pushed function: LOGINButton
        function LOGINButtonPushed(app, event)
         
            
            switch(app.LOGINButton.Text)
                case('LOGIN')   

            %----------------------------------        
            if ishandle(app.prediction_figure_handle)
                close(app.prediction_figure_handle)
                app.prediction_figure_handle = [] ;
            end %if ishandle(app.prediction_figure_handle)

            app.prediction_done         =     0         ; 
            app.PLamp.Color             = [0.9,0.9,0.9] ; 
            app.Label_PL.Text           = '**';
            app.Label_PL.FontColor = [0 0 0];
            %---------------------------------- 
        
            app.login_details =  login_window(app.login_options,app.base_width,app.base_height,app.mag_fac);  %run a seperate windows prog to get the login details
            

            if app.login_details.values_set  == 1
            
                app.Cur_Log_in_Label_Val.Text   =  app.login_details.Name                  ;
            app.USERLabel_val2.Text         =  app.login_details.Name                  ;  
            app.Sentinal_label_val.Text     =  num2str(app.login_details.Sentinal_no)   ;                
            app.Sentinal_LabelVAL2.Text     =  num2str(app.login_details.Sentinal_no)   ;                
                        
            switch(app.login_details.Level)
                case(1)
            app.Level_label_val.Text    = 'Standard';
            app.DISP_settButton.Visible =  'off'    ;
                case(2)
            app.Level_label_val.Text = 'Enhanced';
            app.DISP_settButton.Visible =  'on'    ;

            end %  switch(app.login_details.Level)
            
            
            
            app.login_level  =  app.login_details.Level;
            app.LoginLamp.Color =   [0,1,0];

            app.LOGINButton.Text = 'LOGOUT' ;

            app.TabGroup.SelectedTab =  app.TestSettingsTab;
            
            app.RunNewTestButton.Enable  = 'on';
            app.RunNewTestButton.Text = 'Run New Test';

            app.TestSettingsButton.Enable         = 'on';     
            app.CALButton.Enable = 'on';
            app.Prog_STATE            =  2;
            app.ProgMODELabel.Text = 'Mode: Test';

            app.get_status
            app.set_status 

                        else
            % do nothing, possibly msgbox
            end %if app.login_details.values_set  == 1


                case('LOGOUT')
            
            %----------------------------------        
            if ishandle(app.prediction_figure_handle)
                close(app.prediction_figure_handle)
                app.prediction_figure_handle = [] ;
            end %if ishandle(app.prediction_figure_handle)

            app.prediction_done         =     0         ; 
            app.PLamp.Color             = [0.9,0.9,0.9] ; 
            
            app.Label_PL.Text           = '**';
            app.Label_PL.FontColor = [0 0 0];

            %----------------------------------

            app.LOGINButton.Text = 'LOGIN'                              ;  
            app.login_level = 0                                         ;
            app.login_details = []                                      ;

            app.Prog_STATE                  =  1                        ;

            app.Cur_Log_in_Label_Val.Text   =  'NONE'                   ;
            app.USERLabel_val2.Text         =  'NONE'                   ;  
            app.Sentinal_label_val.Text     =  'NONE'                   ;                
            app.Sentinal_LabelVAL2.Text     =  'NONE'                   ; 
            app.Level_label_val.Text        =  'UNSET'                  ;   
            app.LoginLamp.Color =   [1,0,0];    
            app.RunNewTestButton.Enable    ='off';
            app.RunNewTestButton.Text = 'Run New Test';

            app.TestSettingsButton.Enable         = 'off';     
            app.CALButton.Enable = 'off' ;
            app.ProgMODELabel.Text = 'Mode: View';
            app.DISP_settButton.Visible =  'off'    ;

            end %switch(app.LOGINButton.Text)
            app.get_status
            app.set_status

        end

        % Button pushed function: TestSettingsButton
%------------------------------------------------------
%------------------------------------------------------
%------------------------------------------------------
function CALButtonPushed(app, event)

switch(app.CALButton.Text)

% app.RunNewTestButton.    


    case('Go to CAL')
app.CALButton.Text = 'Go to TEST'    ;
app.Prog_STATE            =  3       ;
app.LOGINButton.Enable = 'off'       ;

app.plot_options.initial_thresh_index = app.plot_options.initial_thresh_index_C   ;
app.plot_options.Data_path_choice     = app.plot_options.Data_path_choice_C       ;
app.plot_options.mode_pairs_to_Use    = app.plot_options.mode_pairs_to_Use_C      ; 

app.RunNewTestButton.Enable = 'on';
app.RunNewTestButton.Text = 'Run Cal Test';

app.get_status
app.set_status
app.ProgMODELabel.Text = 'Mode: Cal';

    case('Go to TEST')
app.CALButton.Text = 'Go to CAL';        
app.Prog_STATE            =  2;
app.LOGINButton.Enable = 'on';

% go back to the original plot_options
app.plot_options         =    load_mat_structure_from_file([app.settings_root,app.default_options.plot_options_fname],...
app.default_options.plot_options_fields);


app.get_status
app.set_status
app.ProgMODELabel.Text = 'Mode: Test';
app.RunNewTestButton.Enable = 'on';
app.RunNewTestButton.Text = 'Run New Test';
end  %switch(app.CALButton.Text)        


% Prog_STATE            =  1    ;  % 1-View  2-Test  3-Calibrate  
% app.CALButton.Text = 'BACK TO TEST';


end %function CALButtonPushed(app, event)
%------------------------------------------------------
%------------------------------------------------------
%------------------------------------------------------
        function TestSettingsButtonPushed(app, event)
            
     FDSF_temp   =   [pwd,app.default_options.Test_Settings_fname]                   ; 
     SF_temp     =   [app.settings_root,app.default_options.Test_Settings_fname]     ;
          
     switch (app.login_level)

            case(0)
            msgbox('you need to login to change') 
            dummy_ = []; 
            case(1)
            dummy_ = set_key_test_settings_BASICU(app.Test_Settings,FDSF_temp,SF_temp,app.base_width,app.base_height,app.mag_fac);  
            case(2)
            dummy_ = set_key_test_settings(app.Test_Settings,FDSF_temp,SF_temp,app.base_width,app.base_height,app.mag_fac); 
         otherwise
            dummy_ = []; 
            msgbox(['Unknown LL level: ',num2str(app.login_level)  ])

     end  % switch (app.login_level)
                       
            if isstruct(dummy_)
            app.Test_Settings = dummy_;
            end % if isstruct(dummy_)
        end

        % Button pushed function: RunNewTestButton

        function RunNewTestButtonPushed(app, event)

            %FDSF_temp   =   [pwd,app.default_options.Ttest_parameters_fname]                     ; 
            SF_temp      =   [app.settings_root,app.default_options.test_parameters_fname]         ;              
            
switch (app.login_level)

            case(0)
                
            msgbox('you need to login to do a test')

            case{1,2}
            
if app.have_test_data ==0
            %if app.have_test_data ==0    
             
            %msgbox('this is the level 1/2 option')

            if app.Prog_STATE ~= 3
            dummy__   = set_test_parameters_essential(app.test_parameters   ,  SF_temp  ,app.base_width,app.base_height,   app.mag_fac);
   


            else
dummy__.ELR            =  'N/A' ;
dummy__.clamp_location =  'N/A' ;
dummy__.contact_wire   =  'N/A' ;
dummy__.arm_present    =  'N/A' ;
dummy__.Track_id       =  'N/A' ;
dummy__.Asset_No       =  'N/A' ;
dummy__.WR             =  'N/A' ;
dummy__.Structure_ID   =  'N/A' ;
dummy__.LU_Label_text  =  'N/A' ;
dummy__.Notes          =  'Calibration Test';
          
            
            
            end %if app.Prog_STATE ~= 3


            if isstruct(dummy__)
               app.test_parameters_choices = dummy__;
           
            switch (app.test_parameters_choices.contact_wire)
                case('120')
             fixed_Operator_Settings.contact_wire_type_120_107 = 1;
                case('107')  
             fixed_Operator_Settings.contact_wire_type_120_107 = 2;                
                otherwise
             fixed_Operator_Settings.contact_wire_type_120_107 = 1;
            end %switch (app.test_parameters_choices.contact_wire)
            
            

            % make this the operator name with no spaces
            % And the site name as the Structure ID

            dum1 = app.login_details.Name;
            dum1(find(dum1 ==' '))= '';

            dum2 = app.test_parameters_choices.Structure_ID;
            dum2(find(dum2==' '))= '';
         
            fixed_Operator_Settings.Name      = dum1;
            fixed_Operator_Settings.Site_name = dum2;
            
            [Test_Settings_O] = convert_test_strct(app.Test_Settings ); 
                        
            %try  
            [raw_data,err] =  run_alva_DAQ(Test_Settings_O) ;
                        
            %catch error_
            %msgbox(['error running run_alva_DAQ: ', error_.message  ] ) 
            %end  % try
            

            if isstruct(raw_data) ==1 && err == 0
            clock_temp = fix(clock); 

            app.test_data.raw_data                 = raw_data                                                        ;
            app.test_data.fixed_Test_Settings      = Test_Settings_O                                                 ;  
            app.test_data.date_time                = clock_temp                                                      ;
            app.test_data.tester_details           =  app.login_details                                              ;
            app.test_data.test_parameters          =  app.test_parameters_choices                                    ;
            app.test_data.fixed_Operator_Settings  = fixed_Operator_Settings                                          ;
            app.test_data.serial_number            = raw_data.serial_number ;
            app.test_data.ver = '2.0'                                                                                ;
            app.test_data =   save_in_file_structure (app.slab_root, app.test_data,app.default_options,app.Prog_STATE)              ; 
            app.current_test_folder = app.test_data.file_with_path(1:max(find(app.test_data.file_with_path=='\')))   ;
            %--------------------------------------------------------------------------
            app.Cur_dat_set_val.Text    =    app.test_data.file_with_path( max((find(app.test_data.file_with_path=='\')))+1:end) ;
            app.Test_DandT_val.Text     =    string(datetime(app.test_data.date_time))                                           ;
            app.Notes_val.Text          =    ['ver',app.test_data.ver]                                                          ;  
            app.have_test_data = 1;
            app.get_status
            app.set_status
            app.TabGroup.SelectedTab = app.CheckProcessTab;
            else
            msgbox('esc no test')

            end %if isstruct(dummy_)
end %if isstruct(dummy__)



else
     msgbox('Clear current data first' )





end % if app.have_test_data ==0








end  % switch (app.login_level)

        end  % FUNCTION

        % Button pushed function: LoadExistingDataButton
        function LoadExistingDataButtonPushed(app, event)

%   all levels including (0)  should be able to load old data and analyse it     
%   needs to differentiate between newand old data V1.0 and v2.0

if  app.have_test_data == 0
dummy_ = app.default_options.raw_data_file_path ;
[file_,path_, ok_] = uigetfile([app.slab_root ,dummy_ , '\*.mat']);

if ok_ ==1

file_with_path  = [path_,file_];
dummy__ = load(file_with_path);

if isfield(dummy__,'test_data')

app.test_data = dummy__.test_data ;    

if length(fields(app.test_data)) == 5  && isfield(app.test_data,'raw_data')&& isfield(app.test_data,'fixed_Test_Settings') &&...
isfield(app.test_data,'fixed_Operator_Settings')&& isfield(app.test_data,'file_with_path') && isfield(app.test_data,'date_time')  
% msgbox('This is legacy data-  with the old fixed_test_settings and fixed_operator_settings ')    
ver_insert_tmp = 'Ver1.0 (legacy)';

%elseif  -  new format check in here
else
%need a check here
%msgbox('Warning format not recognised - check ')

ver_insert_tmp = 'Ver2.0';
end

%----------------------------------------------------------------
% assignents 
%----------------------------------------------------------------
% GUI display assignments----------------------------------------

app.Cur_dat_set_val.Text    =    app.test_data.file_with_path( max((find(app.test_data.file_with_path=='\')))+1:end);
app.Test_DandT_val.Text     =    string(datetime(app.test_data.date_time))           ;
app.Notes_val.Text          =    ver_insert_tmp                                      ;  

% structure assignments------------------------------------------
app.current_test_folder = path_;
app.have_test_data      = 1    ; 
            
app.get_status
app.set_status
app.TabGroup.SelectedTab = app.CheckProcessTab;

% status assignments---------------------------------------------
% app.current_status = 2;
% app.Set_Status();
%------------------------------------------------------------------------------------

else
msgbox('The file is not the correct format needs to have a field')
end %if isfield(dummy__,'test_data')
end  % if ok_ ==1
else
msgbox('Clear current data first' )
end

        
% modified fromold code in WireProApp (1.0) ::

        end

        % Button pushed function: ClearCurrentDataButton
        function ClearCurrentDataButtonPushed(app, event)
 
            app.test_data               =    []         ;
            app.Cur_dat_set_val.Text    =    ''         ;
            app.Test_DandT_val.Text     =    ''         ;
            app.Notes_val.Text          =    ''         ;  
            app.current_test_folder     =    []         ;
            app.rail_tester             =    []         ;
            app.have_test_data          =     0         ; 
            app.have_processed_data     =     0         ;
            app.prediction_done         =     0         ; 
            app.PLamp.Color             = [0.9,0.9,0.9] ; 
            app.get_status
            app.set_status
            
            app.Label_PL.Text           = '**';
            app.Label_PL.FontColor = [0 0 0];


            if app.login_level == 0
            app.RunNewTestButton.Enable    ='off';
            end 

        end

        % Button pushed function: CheckSignalQualityButton
        function CheckSignalQualityButtonPushed(app, event)
            % To be worked out
            snr_settings_O = convert_to_snr_struct(app.snr_settings);

            if isstruct(app.test_data)  
            rejection_indicators   = plot_SNR_Raw(app.test_data,[0,0,0,0],snr_settings_O,app.base_width,app.base_height,app.mag_fac);
                     
           
            if length(find(rejection_indicators(1,:)<4)) 
            RMS_msg = ['Warning RMS flags on channels:'  num2str((find(rejection_indicators(1,:)<4))) ] ;   
            else
            RMS_msg = 'RMS flags OK'  ;
            end %if length(find(rejection_indicators(2,:)<3))  >0
            
            if length(find(rejection_indicators(2,:)<3)) 
            SNR_msg = ['Warning SNR flags on channels:'  num2str((find(rejection_indicators(2,:)<4))) ] ;   
            else
            SNR_msg = 'SNR flags OK'  ;
            end %if length(find(rejection_indicators(2,:)<3))  >0
            
            if length(find(rejection_indicators(3,:)<4)) 
            LFN_msg = ['Warning LFN flags on channels:'  num2str((find(rejection_indicators(3,:)<4))) ] ;   
            else
            LFN_msg = 'LFN flags OK'  ;
            end %if length(find(rejection_indicators(2,:)<3))  >0
            
            if length(find(rejection_indicators(4,:)<4)) 
            HFN_msg = ['Warning HFN flags on channels:'  num2str((find(rejection_indicators(4,:)<4))) ] ;   
            else
            HFN_msg = 'HFN flags OK'  ;
            end %if length(find(rejection_indicators(2,:)<3))  >0
                       
            

            %Pix_SS = get(0,'screensize')                ;
            %x_mult = (Pix_SS(3)/app.base_width)   * app.mag_fac ;
            %y_mult = (Pix_SS(4)/app.base_height)  * app.mag_fac ;
            msgbox({RMS_msg,SNR_msg,LFN_msg,HFN_msg});  
            %dum.Position  = [100 100 260*x_mult 108*y_mult] ;
             
            % USE UI figure here
            % USE UI figure here
            % USE UI figure here
            % USE UI figure here

           end %if isstruct(app.test_data)  

        end

        % Button pushed function: DisplaySNRMapsButton
        function DisplaySNRMapsButtonPushed(app, event)
            %plot_list =   {'Maps','Bar Charts','indicators','time_freq_traces' } 
            
            if isstruct(app.test_data)  
            snr_settings_O = convert_to_snr_struct(app.snr_settings);
            [~]   = plot_SNR_Raw(app.test_data,[1,0,0,0],snr_settings_O,app.base_width,app.base_height,app.mag_fac); 
            end %if isstruct(app.test_data)  
            


        end

        % Button pushed function: ProcessDataButton
        function ProcessDataButtonPushed(app, event)
          if isstruct(app.test_data)           
 
          [app.rail_tester,loaded_fe_file_ok ] =  create_rail_tester_structure(app.default_options,app.test_data,app.proc_options);
          
          if loaded_fe_file_ok~= 1
          msgbox('warning issue with fe file loading- cant process')
          else
          app.rail_tester                                =  fn_process_rail_data(app.rail_tester, app.proc_options);
          
          if isstruct(app.rail_tester)
          app.have_processed_data = 1;
          end %if isstruct(app.rail_tester)
          
          end %if loaded_fe_file_ok~= 1
                    
            app.get_status
            app.set_status
          app.TabGroup.SelectedTab = app.PredictionTab ;

          end %if isstruct(app.test_data)

          % fit thisinto the next window 
          % txt_ = app.plot_options2.Data_path_options{app.plot_options2.Data_path_choice};    
          % app.Learning_set_Label.Text = ['PREDICTION DB: ',txt_(max(find(txt_=='\'))+1:end),'.'];
          % app.Set_Status();
%}

        end

        % Button pushed function: SetPredictionOptionsButton
        
        function SetPredictionOptionsButtonPushed(app, event)
            
             FDSF_temp             =   [pwd,app.default_options.plot_options_fname]                    ; 
             SF_temp               =   [app.settings_root,app.default_options.plot_options_fname]      ;
 
            switch (app.login_level)

                 case{0,1}    
              dummy_ =  set_plot_options_BASICU(app.plot_options,FDSF_temp,SF_temp,app.base_width,app.base_height,app.mag_fac); 
                 case(2)
              dummy_  =  set_plot_options(app.plot_options,FDSF_temp,SF_temp,app.base_width,app.base_height,app.mag_fac); 
             
            end %switch (app.login_level)
              
              if isstruct(dummy_)
              app.plot_options = dummy_;
              end
            
        end

        % Button pushed function: ModePairViewerFDButton
        function ModePairViewerFDButtonPushed(app, event)
            if isstruct(app.rail_tester)   
            plot_options_O  = convert_plot_options2_old_strct(app.plot_options);

            proc_file.rail_tester  =  app.rail_tester;
            proc_file.test_data    =  app.test_data  ;
            settings_               = plot_options_O; 

            do_plots = [0 1 0 0 0 0 0 0 0 0 0 0];
            LF = [pwd,settings_.Data_path_options{settings_.Data_path_choice}];
            
            [~] = plot_predict_processed(proc_file, settings_ ,do_plots, LF,app.base_width,app.base_height,app.mag_fac);        
                        
            end %if isstruct(app.rail_tester)   
            
        end

        % Button pushed function: PREDICTIONButton
        function PREDICTIONButtonPushed(app, event)
%----------------------------------------------
%----------------------------------------------

             if isstruct(app.rail_tester)    
            
             dist_max = app.plot_options.dist_pass_val_upper /1000;   
             dist_min = app.plot_options.dist_pass_options(app.plot_options.dist_pass_index)/1000;
             cap_min  = app.plot_options.cap_thresh_options(app.plot_options.cap_thresh_index); 

             proc_file.rail_tester  =  app.rail_tester;
             proc_file.test_data    =  app.test_data  ;
             plot_options_O  = convert_plot_options2_old_strct(app.plot_options);
             settings_              = plot_options_O;

             snr_settings_O = convert_to_snr_struct(app.snr_settings);
             rejection_indicators   =  plot_SNR_Raw(app.test_data,[0,0,0,0],snr_settings_O,app.base_width,app.base_height,app.mag_fac);
      
             do_plots   = [0 0 0 0 0 0 0 0 0 0 0 0];  
             LF = [pwd,settings_.Data_path_options{settings_.Data_path_choice}];
             
             [~,PL_inf,~] = plot_predict_processed(proc_file, settings_ ,do_plots, LF,app.base_width,app.base_height,app.mag_fac);  
             [T_num]= find(rejection_indicators(2,:)==1);
              
             cap_result= app.test_data.raw_data.cap_test_result.z;
             b_temp = log10((cap_result(1:12,1)./cap_result(1:12,end)))' ;
             cap_fail_chns = find(b_temp<cap_min );  

             do_the_prediction = 1 ;
             cap_text  = 'Cap OK';
             sn_text   = 'S/N OK'; 
             dist_text = 'Dist OK';

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


             if do_the_prediction == 0
             if app.login_level ~= 2
             msgbox({'Cannot predict because data has the following issues:'  ,cap_text,sn_text,dist_text})               
             else
             ans_ = questdlg({'Prediction invalid for following issues:'  ,cap_text,sn_text,dist_text, 'SEE ANYWAY?'}) ;                               
             if strcmp(ans_,'Yes')
             do_the_prediction = 1;                
             end %if strcmp(ans_,'Yes')

             end %if app.login_level ~= 2
                             
             end %if do_the_prediction ==0                 
             
             if do_the_prediction == 1  
              
             do_plots   = [0 0 0 0 0 0 0 0 0 1 0 0];  
             LF = [pwd,settings_.Data_path_options{settings_.Data_path_choice}];
             
             % [~,PL_inf,~] = plot_predict_processed    (proc_file, settings_ ,do_plots, LF,app.base_width,app.base_height,app.
             % mag_fac);
                  
             [pred_,PL_inf,PFH] = plot_predict_processed(proc_file, settings_ ,do_plots, LF,app.base_width,app.base_height,app.mag_fac);  
             
             app.prediction_figure_handle = PFH;
             app.Label_PL.Text = num2str(floor(10000*PL_inf.DV(PL_inf.mod_val))/10);
                          
             if PL_inf.DV(PL_inf.mod_val) > dist_min
             app.Label_PL.FontColor = [0 1 0];
             else
             app.Label_PL.FontColor = [1 0 0];    
             end

             c_index = pred_.colours(pred_.pred_value);

             RGB_colours = [0,1,0;1 0.7 0 ;1,0,0];
             
             app.PLamp.Color = RGB_colours(c_index,:);
             app.prediction_done  = 1 ;
             app.get_status
             app.set_status
             
             end %if do_the_prediction == 1;  
                       
            end %if isstruct(app.rail_tester)   
             
        end

        % Button pushed function: SNRSettingsButton
        function SNRSettingsButtonPushed(app, event)
            %  also  only Visible for level 2
            
            switch (app.login_level)
                case{0,1}    
             msgbox('Settings only availible for advanced user')                     
                 case(2)
             FDSF_temp             =   [pwd,app.default_options.snr_settings_fname]                    ; 
             SF_temp               =   [app.settings_root,app.default_options.snr_settings_fname]      ;

             dummy_      =   set_SNR_settings(app.snr_settings,FDSF_temp,SF_temp,app.base_width,app.base_height,app.mag_fac);
            
             if isstruct(dummy_)
             app.snr_settings = dummy_;
             end
                         

            end %switch (app.login_level)

        end

        % Button pushed function: DisplaySNRBarChartsButton
        function DisplaySNRBarChartsButtonPushed(app, event)
            %plot_list =   {'Maps','Bar Charts','indicators','time_freq_traces' } 
            
            if isstruct(app.test_data)  
            snr_settings_O = convert_to_snr_struct(app.snr_settings);
            [~]   = plot_SNR_Raw(app.test_data,[0,1,0,0],snr_settings_O,app.base_width,app.base_height,app.mag_fac); 
            end %if isstruct(app.test_data)  
            
        end

        % Button pushed function: ChanTimeandFreqViewerButton
        function ChanTimeandFreqViewerButtonPushed(app, event)
            %plot_list =   {'Maps','Bar Charts','indicators','time_freq_traces' } 
            
            if isstruct(app.test_data)  
            snr_settings_O = convert_to_snr_struct(app.snr_settings);
            [~]   = plot_SNR_Raw(app.test_data,[0,0,0,1],snr_settings_O,app.base_width,app.base_height,app.mag_fac); 
            end %if isstruct(app.test_data)  
        end

        % Button pushed function: SignalQualityIndicatorsButton
        function SignalQualityIndicatorsButtonPushed(app, event)
            %plot_list =   {'Maps','Bar Charts','indicators','time_freq_traces' } 
            
            if isstruct(app.test_data)  
            snr_settings_O = convert_to_snr_struct(app.snr_settings);
            [~]   = plot_SNR_Raw(app.test_data,[0,0,1,0],snr_settings_O,app.base_width,app.base_height,app.mag_fac); 
                        
            end %if isstruct(app.test_data)  
        end

        % Button pushed function: ViewModeMapButton
        function ViewModeMapButtonPushed(app, event)
            if isstruct(app.rail_tester)   
            plot_options_O  = convert_plot_options2_old_strct(app.plot_options);

            proc_file.rail_tester  =  app.rail_tester;
            proc_file.test_data    =  app.test_data  ;
            settings_               = plot_options_O; 

           %do_plots = [0 0 1 0 0 0 0 0 0 0];
            do_plots = [0 0 1 0 0 0 0 0 0 0 0 0];
            
            LF = [pwd,settings_.Data_path_options{settings_.Data_path_choice}];
            
            [~] = plot_predict_processed(proc_file, settings_ ,do_plots, LF,app.base_width,app.base_height,app.mag_fac);        
            end %if isstruct(app.rail_tester)   
            
        end

        % Button pushed function: MeanSTDmodesButton
        function MeanSTDmodesButtonPushed(app, event)
            if isstruct(app.rail_tester)   
            plot_options_O  = convert_plot_options2_old_strct(app.plot_options);

            proc_file.rail_tester  =  app.rail_tester;
            proc_file.test_data    =  app.test_data  ;
            settings_               = plot_options_O; 

            
            do_plots = [0 0 0 1 0 0 0 0 0 0 0 0];
            
            LF = [pwd,settings_.Data_path_options{settings_.Data_path_choice}];
            
            [~] = plot_predict_processed(proc_file, settings_ ,do_plots, LF,app.base_width,app.base_height,app.mag_fac);        
            end %if isstruct(app.rail_tester)   
            
        end

        % Button pushed function: PredsButton
        function PredsButtonPushed(app, event)
            if isstruct(app.rail_tester)   
            plot_options_O  = convert_plot_options2_old_strct(app.plot_options);

            proc_file.rail_tester  =  app.rail_tester;
            proc_file.test_data    =  app.test_data  ;
            settings_               = plot_options_O; 

            
            do_plots = [0 0 0 0 0 0 1 0 0 0 0 0];
            
            LF = [pwd,settings_.Data_path_options{settings_.Data_path_choice}];
            
            [~] = plot_predict_processed(proc_file, settings_ ,do_plots, LF,app.base_width,app.base_height,app.mag_fac);        
            end %if isstruct(app.rail_tester)
        end

        % Button pushed function: ShowPeakFindButton
        function ShowPeakFindButtonPushed(app, event)
             if isstruct(app.rail_tester)   
            plot_options_O  = convert_plot_options2_old_strct(app.plot_options);

            proc_file.rail_tester  =  app.rail_tester;
            proc_file.test_data    =  app.test_data  ;
            settings_               = plot_options_O; 
            
            %do_plots = [1 0 0 0 0 0 0 0 0 0];
            do_plots =  [1 0 0 0 0 0 0 0 0 0 0 0];  
            
            LF = [pwd,settings_.Data_path_options{settings_.Data_path_choice}];
            
            [~] = plot_predict_processed(proc_file, settings_ ,do_plots, LF,app.base_width,app.base_height,app.mag_fac);        
            end %if isstruct(app.rail_tester)
        end

        % Button pushed function: DistanceMeanTableButton
        function DistanceMeanTableButtonPushed(app, event)
            if isstruct(app.rail_tester)   
            plot_options_O  = convert_plot_options2_old_strct(app.plot_options);

            proc_file.rail_tester  =  app.rail_tester;
            proc_file.test_data    =  app.test_data  ;
            settings_               = plot_options_O; 

            %do_plots = [0 0 0 0 0 0 0 1 0 0];
            do_plots =  [0 0 0 0 0 0 0 1 0 0 0 0];  
            LF = [pwd,settings_.Data_path_options{settings_.Data_path_choice}];
            
            [~] = plot_predict_processed(proc_file, settings_ ,do_plots, LF,app.base_width,app.base_height,app.mag_fac);        
            end %if isstruct(app.rail_tester)
        end

        % Button pushed function: LogLikelyhoodTableButton
        function LogLikelyhoodTableButtonPushed(app, event)
             if isstruct(app.rail_tester)   
            plot_options_O  = convert_plot_options2_old_strct(app.plot_options);

            proc_file.rail_tester  =  app.rail_tester;
            proc_file.test_data    =  app.test_data  ;
            settings_               = plot_options_O; 

            %do_plots = [0 0 0 0 0 0 0 0 1 0];
            do_plots =  [0 0 0 0 0 0 0 0 1 0 0 0];  
            LF = [pwd,settings_.Data_path_options{settings_.Data_path_choice}];
            
            [~] = plot_predict_processed(proc_file, settings_ ,do_plots, LF,app.base_width,app.base_height,app.mag_fac);        
            end %if isstruct(app.rail_tester)
        end

        % Button pushed function: InteractiveMMViewerButton
        function InteractiveMMViewerButtonPushed(app, event)
            if isstruct(app.rail_tester)   
            plot_options_O  = convert_plot_options2_old_strct(app.plot_options);

            proc_file.rail_tester  =  app.rail_tester;
            proc_file.test_data    =  app.test_data  ;
            settings_               = plot_options_O; 

            %do_plots = [0 0 0 0 1 0 0 0 0 0];
            do_plots =  [0 0 0 0 1 0 0 0 0 0 0 0];  
            
            LF = [pwd,settings_.Data_path_options{settings_.Data_path_choice}];
            
            [~] = plot_predict_processed(proc_file, settings_ ,do_plots, LF,app.base_width,app.base_height,app.mag_fac);        
            end %if isstruct(app.rail_tester)
        end

        % Button pushed function: ShowDispersionButton
        function ShowDispersionButtonPushed(app, event)
            if isstruct(app.rail_tester)
            plot_options_O  = convert_plot_options2_old_strct(app.plot_options);
            showdispersion(plot_options_O,app.rail_tester,app.base_width,app.base_height,app.mag_fac);
            end% if isstruct(app.rail_tester) 
        end

        % Button pushed function: ShowMeshButton
        function ShowMeshButtonPushed(app, event)
            if isstruct(app.rail_tester)
            show_mesh(app.rail_tester,app.base_width,app.base_height,app.mag_fac);
            end%if isstruct(app.rail_tester)            
        end

        % Button pushed function: ModeMapTagsButton
        function ModeMapTagsButtonPushed(app, event)
            if isstruct(app.rail_tester)   
            plot_options_O  = convert_plot_options2_old_strct(app.plot_options);

            proc_file.rail_tester  =  app.rail_tester;
            proc_file.test_data    =  app.test_data  ;
            settings_               = plot_options_O; 

            %do_plots = [0 0 0 0 0 1 0 0 0 0];
            do_plots =  [0 0 0 0 0 1 0 0 0 0 0 0];  
            LF = [pwd,settings_.Data_path_options{settings_.Data_path_choice}];
            
            [~] = plot_predict_processed(proc_file, settings_ ,do_plots, LF,app.base_width,app.base_height,app.mag_fac);        
            end %if isstruct(app.rail_tester)
        end

        % Button pushed function: ClearPredictionsButton
        function ClearPredictionsButtonPushed(app, event)
            
            

            if ishandle(app.prediction_figure_handle)
                close(app.prediction_figure_handle)
                app.prediction_figure_handle = [] ;
            end %if ishandle(app.prediction_figure_handle)
            
            app.Label_PL.Text           = '**';
            app.Label_PL.FontColor = [0 0 0];

            app.prediction_done         =     0         ; 
            app.PLamp.Color             = [0.9,0.9,0.9] ; 
            app.get_status
            app.set_status

        end

        % Button pushed function: ClearprocesseddataButton
        function ClearprocesseddataButtonPushed(app, event)
            app.rail_tester             =    []         ;
            
            if ishandle(app.prediction_figure_handle)
                close(app.prediction_figure_handle)
                app.prediction_figure_handle = [] ;
            end %if ishandle(app.prediction_figure_handle)
            
            app.Label_PL.Text           = '**';
            app.Label_PL.FontColor = [0 0 0];

            app.have_processed_data     =     0         ;
            app.prediction_done         =     0         ; 
            app.PLamp.Color             = [0.9,0.9,0.9] ;
            app.get_status
            app.set_status
        end

        % Button pushed function: MPRCvsTagButton
        function MPRCvsTagButtonPushed(app, event)
            if isstruct(app.rail_tester)   
            plot_options_O  = convert_plot_options2_old_strct(app.plot_options);

            proc_file.rail_tester  =  app.rail_tester;
            proc_file.test_data    =  app.test_data  ;
            settings_               = plot_options_O; 

            do_plots =  [0 0 0 0 0 0 0 0 0 0 0 1];  
            LF = [pwd,settings_.Data_path_options{settings_.Data_path_choice}];
           
            [~] = plot_predict_processed(proc_file, settings_ ,do_plots, LF,app.base_width,app.base_height,app.mag_fac) ;        

            end %if isstruct(app.rail_tester)
        end

        % Button pushed function: GetTransducerDetailsButton
        function GetTransducerDetailsButtonPushed(app, event)
           
            if app.have_test_data == 1
            display_trans_positions(app.test_data.fixed_Test_Settings,'from when the test was done',app.base_width,app.base_height,app.mag_fac)
            else
            display_trans_positions(app.Test_Settings,'current instrument settings',app.base_width,app.base_height,app.mag_fac)                      
            end %if have_test_data == 1
           
        end %function GetTransducerDetailsButtonPushed(app, event)

        % Button pushed function: ProduceareportButton
        function ProduceareportButtonPushed(app, event)
                        
            %  ----------------------------------------------------------mag_fac 
            %  Save in a directory   --   (where the results are) / Reports. 
            %  Save in a date file structure as in the results            
            %  ----------------------------------------------------------
            %  Only if a prediction has been made already
            %  app.prediction_done
            %  Produce_Test_report(       );            
            %  exportgraphics(f,'AnnotatedPlot.pdf')
            % ----------------------------------------------------------

 if isstruct(app.rail_tester)    

             proc_file.rail_tester  =  app.rail_tester;
             proc_file.test_data    =  app.test_data  ;
             plot_options_O  = convert_plot_options2_old_strct(app.plot_options);
             
             settings_              = plot_options_O;
             
             snr_settings_O = convert_to_snr_struct(app.snr_settings);
             rejection_indicators   =  plot_SNR_Raw(app.test_data,[0,0,0,0],snr_settings_O,app.base_width,app.base_height,app.mag_fac);

             do_plots   = [0 0 0 0 0 0 0 0 0 0 0 0];  
             LF = [pwd,settings_.Data_path_options{settings_.Data_path_choice}];
             [PREDICTION_,PL_inf,~] = plot_predict_processed(proc_file, settings_ ,do_plots, LF,app.base_width,app.base_height,app.mag_fac);  
             [T_num]= find(rejection_indicators(2,:)==1);
              
             %app.test_parameters_choices
             Produce_Test_report( proc_file, PL_inf, T_num, PREDICTION_,app.default_options,app.slab_root,app.plot_options,app.Prog_STATE)

 end % if isstruct(app.rail_tester)    

        end
    end

    % Component initialization
    methods (Access = private)

        % Create UIFigure and components
        function createComponents(app)
            Pix_SS = get(0,'screensize')              ;
            x_mult = (Pix_SS(3)/app.base_width)    * app.mag_fac ;
            y_mult = (Pix_SS(4)/app.base_height)   * app.mag_fac ;
            x_mult_o = (Pix_SS(3)/app.base_width)  * app.mag_fac;
            y_mult_o = (Pix_SS(4)/app.base_height) * app.mag_fac;

            % Create UIFigure and hide until all components are created
            %app.UIFigure = uifigure('Visible', 'off','Resize','off');
            app.UIFigure = uifigure('Visible', 'on','Resize','off');
       %     app.UIFigure.Color = [1 1 1];
       %     app.UIFigure.Position = [x_mult*100 y_mult*100 x_mult*733 y_mult*553];
            
            app.UIFigure.Units = 'normalized';

            app.UIFigure.Position  = [0.018*x_mult_o 0.024*y_mult_o  0.5120 * app.mag_fac 0.5120 * app.mag_fac];

            app.TabGroup = uitabgroup(app.UIFigure,'Position',[x_mult*1 y_mult*67 x_mult*960 y_mult*442],'Visible','on');
            
           %------------------------------------ 
            %app.TabGroup.Position = [x_mult*1 y_mult*67 x_mult*980 y_mult*442];
            %app.CONTACTWireTestLabel.Position = [x_mult*2 y_mult*513 x_mult*334 y_mult*39];
            %app.ProgMODELabel.Position = [x_mult*600 y_mult*515 x_mult*150 y_mult*26];
            %app.Program_version_label.Position = [x_mult*340 y_mult*515 x_mult*25 y_mult*22];
            


            

            % keyboard 

            % 'InnerPosition',[x_mult*2 y_mult*45 x_mult*487 y_mult*271]
            
            % Create LoginTab
            app.LoginTab = uitab(app.TabGroup);
            %app.LoginTab = uitab(app.TabGroup,'position',[1 1 292 152]);
            app.LoginTab.Title = 'Login';
                        
            % Create LOGINButton
            app.LOGINButton = uibutton(app.LoginTab, 'push');
            app.LOGINButton.ButtonPushedFcn = createCallbackFcn(app, @LOGINButtonPushed, true);
            app.LOGINButton.FontSize = y_mult*36;
            app.LOGINButton.Position = [x_mult*31 y_mult*291 x_mult*191 y_mult*97];
            app.LOGINButton.Text = 'LOGIN';
            
            % Create DisplaySettings
            app.DISP_settButton                  =  uibutton(app.LoginTab, 'push');
            app.DISP_settButton.ButtonPushedFcn  =  createCallbackFcn(app, @DSbuttonPushed, true);
            app.DISP_settButton.FontSize         =  y_mult*20;
            app.DISP_settButton.Position         =  [x_mult*700 y_mult*291 x_mult*191 y_mult*97];
            app.DISP_settButton.Text             =  'Display Settings'     ;
            app.DISP_settButton.Visible          =  'off'                  ;

            
                       
            % Create Caibrate Button
            app.CALButton = uibutton(app.LoginTab, 'push');
            app.CALButton.ButtonPushedFcn = createCallbackFcn(app, @CALButtonPushed, true);
            app.CALButton.FontSize = y_mult*22;   
            app.CALButton.Position = [x_mult*31 y_mult*50 x_mult*200 y_mult*67];
            app.CALButton.Text = 'Go to CAL';
            app.CALButton.Enable = 'off';
            
            % Create CurrentlyloggedinLabel
            app.CurrentlyloggedinLabel = uilabel(app.LoginTab);
            app.CurrentlyloggedinLabel.FontSize = y_mult*18;
            app.CurrentlyloggedinLabel.Position = [x_mult*293 y_mult*353 x_mult*190 y_mult*23];
            app.CurrentlyloggedinLabel.Text = 'Currently logged in :';

            % Create SentinalLabel
            app.SentinalLabel = uilabel(app.LoginTab);
            app.SentinalLabel.FontSize = y_mult*18;
            app.SentinalLabel.Position = [x_mult*293 y_mult*298 x_mult*100 y_mult*23];
            app.SentinalLabel.Text = 'Sentinal :';

            % Create Cur_Log_in_Label_Val
            app.Cur_Log_in_Label_Val = uilabel(app.LoginTab);
            app.Cur_Log_in_Label_Val.Position = [x_mult*507 y_mult*353 x_mult*158 y_mult*22];
            app.Cur_Log_in_Label_Val.Text = 'NONE';
            app.Cur_Log_in_Label_Val.FontSize = 14*x_mult;

            % Create Sentinal_label_val
            app.Sentinal_label_val = uilabel(app.LoginTab);
            app.Sentinal_label_val.Position = [x_mult*507 y_mult*298 x_mult*151 y_mult*22];
            app.Sentinal_label_val.Text = 'NONE';
            app.Sentinal_label_val.FontSize = 14*x_mult; 

            % Create LevelLabel
            app.LevelLabel = uilabel(app.LoginTab);
            app.LevelLabel.FontSize = y_mult*18;
            app.LevelLabel.Position = [x_mult*293 y_mult*244 x_mult*73 y_mult*23];
            app.LevelLabel.Text = 'Level:';

            % Create Level_label_val
            app.Level_label_val = uilabel(app.LoginTab);
            app.Level_label_val.Position = [x_mult*510 y_mult*244 x_mult*155 y_mult*22];
            app.Level_label_val.Text = 'UNSET';
            app.Level_label_val.FontSize = y_mult*14;

%----------------------------------------------------------------------

            % Create TestSettingsTab
            app.TestSettingsTab = uitab(app.TabGroup);
            app.TestSettingsTab.Title = 'Test/Settings';

            % Create RunNewTestButton
            app.RunNewTestButton = uibutton(app.TestSettingsTab, 'push');
            app.RunNewTestButton.ButtonPushedFcn = createCallbackFcn(app, @RunNewTestButtonPushed, true);
            app.RunNewTestButton.FontSize = y_mult*36;
            app.RunNewTestButton.Position = [x_mult*45 y_mult*320 x_mult*273 y_mult*78];
            app.RunNewTestButton.Text = 'Run New Test';
            app.RunNewTestButton.Enable = 'off';

            % Create LoadExistingDataButton
            app.LoadExistingDataButton = uibutton(app.TestSettingsTab, 'push');
            app.LoadExistingDataButton.ButtonPushedFcn = createCallbackFcn(app, @LoadExistingDataButtonPushed, true);
            app.LoadExistingDataButton.FontSize = y_mult*24;
            app.LoadExistingDataButton.Position = [x_mult*45 y_mult*253 x_mult*237 y_mult*39];
            app.LoadExistingDataButton.Text = 'Load Existing Data';

            % Create CurrentDataSetLabel
            app.CurrentDataSetLabel = uilabel(app.TestSettingsTab);
            app.CurrentDataSetLabel.Position = [x_mult*45 y_mult*168 x_mult*120 y_mult*22];
            app.CurrentDataSetLabel.Text = 'Current Data Set:';
            app.CurrentDataSetLabel.FontSize = x_mult*14;
   
            % Create TestDateandTimeLabel
            app.TestDateandTimeLabel = uilabel(app.TestSettingsTab);
            app.TestDateandTimeLabel.Position = [x_mult*45 y_mult*135 x_mult*130 y_mult*22];
            app.TestDateandTimeLabel.Text = 'Test Date and Time:';
            app.TestDateandTimeLabel.FontSize = x_mult*14;

            % Create NotesLabel
            app.NotesLabel = uilabel(app.TestSettingsTab);
            app.NotesLabel.Position = [x_mult*45 y_mult*84 x_mult*60 y_mult*22];
            app.NotesLabel.Text = 'Notes:';
            app.NotesLabel.FontSize = x_mult*14;

            % Create Cur_dat_set_val
            app.Cur_dat_set_val = uilabel(app.TestSettingsTab);
            app.Cur_dat_set_val.Position = [x_mult*179 y_mult*168 x_mult*480 y_mult*22];
            app.Cur_dat_set_val.Text = 'NONE';
            app.Cur_dat_set_val.FontSize = x_mult*14;

            % Create Test_DandT_val
            app.Test_DandT_val = uilabel(app.TestSettingsTab);
            app.Test_DandT_val.Position = [x_mult*179 y_mult*135 x_mult*468 y_mult*22];
            app.Test_DandT_val.Text = 'NONE';
            app.Test_DandT_val.FontSize = x_mult*14;

            % Create Notes_val
            app.Notes_val = uilabel(app.TestSettingsTab);
            app.Notes_val.Position = [x_mult*84 y_mult*12 x_mult*351 y_mult*94];
            app.Notes_val.Text = 'NONE';
            app.Notes_val.FontSize = x_mult*14;

            % Create ClearCurrentDataButton
            app.ClearCurrentDataButton = uibutton(app.TestSettingsTab, 'push');
            app.ClearCurrentDataButton.ButtonPushedFcn = createCallbackFcn(app, @ClearCurrentDataButtonPushed, true);
            app.ClearCurrentDataButton.FontSize = y_mult*24;
            app.ClearCurrentDataButton.Position = [x_mult*525 y_mult*30 x_mult*179 y_mult*76];
            app.ClearCurrentDataButton.Text = {'Clear Current'; 'Data'};

            % Create TestSettingsButton
            app.TestSettingsButton = uibutton(app.TestSettingsTab, 'push');
            app.TestSettingsButton.ButtonPushedFcn = createCallbackFcn(app, @TestSettingsButtonPushed, true);
            app.TestSettingsButton.FontSize = y_mult*18;
            app.TestSettingsButton.Position = [x_mult*525 y_mult*343 x_mult*164 y_mult*50];
            app.TestSettingsButton.Text = 'Test Settings';

            % Create GetTransducerDetailsButton
            app.GetTransducerDetailsButton = uibutton(app.TestSettingsTab, 'push');
            app.GetTransducerDetailsButton.ButtonPushedFcn = createCallbackFcn(app, @GetTransducerDetailsButtonPushed, true);
            app.GetTransducerDetailsButton.FontSize = y_mult*18;
            app.GetTransducerDetailsButton.Position = [x_mult*526 y_mult*270 x_mult*163 y_mult*52];
            app.GetTransducerDetailsButton.Text = {'Show Transducer '; 'Details'};


            % Create CheckProcessTab
            app.CheckProcessTab = uitab(app.TabGroup);
            app.CheckProcessTab.Title = 'Check/Process';

            % Create CheckSignalQualityButton
            app.CheckSignalQualityButton = uibutton(app.CheckProcessTab, 'push');
            app.CheckSignalQualityButton.ButtonPushedFcn = createCallbackFcn(app, @CheckSignalQualityButtonPushed, true);
            app.CheckSignalQualityButton.FontSize = y_mult*24;
            app.CheckSignalQualityButton.Position = [x_mult*37 y_mult*279 x_mult*174 y_mult*96];
            app.CheckSignalQualityButton.Text = {'Check Signal'; 'Quality'};

            % Create ProcessDataButton
            app.ProcessDataButton = uibutton(app.CheckProcessTab, 'push');
            app.ProcessDataButton.ButtonPushedFcn = createCallbackFcn(app, @ProcessDataButtonPushed, true);
            app.ProcessDataButton.FontSize = y_mult*36;
            app.ProcessDataButton.Position = [x_mult*37 y_mult*68 x_mult*253 y_mult*54];
            app.ProcessDataButton.Text = 'Process Data';


            

            % Create SNRSettingsButton
            app.SNRSettingsButton = uibutton(app.CheckProcessTab, 'push');
            app.SNRSettingsButton.ButtonPushedFcn = createCallbackFcn(app, @SNRSettingsButtonPushed, true);
            app.SNRSettingsButton.FontSize = y_mult*24;
            app.SNRSettingsButton.Position = [x_mult*43 y_mult*193 x_mult*179 y_mult*61];
            app.SNRSettingsButton.Text = 'SNR Settings';


%-----------------------------------------------------------

            % Create DisplaySNRMapsButton
            app.DisplaySNRMapsButton = uibutton(app.CheckProcessTab, 'push');
            app.DisplaySNRMapsButton.ButtonPushedFcn = createCallbackFcn(app, @DisplaySNRMapsButtonPushed, true);
            app.DisplaySNRMapsButton.FontSize = y_mult*14;
            app.DisplaySNRMapsButton.Position = [x_mult*528 y_mult*360 x_mult*210 y_mult*37];
            app.DisplaySNRMapsButton.Text = 'Display SNR++ Maps';
             
            % Create DisplaySNRBarChartsButton
            app.DisplaySNRBarChartsButton = uibutton(app.CheckProcessTab, 'push');
            app.DisplaySNRBarChartsButton.ButtonPushedFcn = createCallbackFcn(app, @DisplaySNRBarChartsButtonPushed, true);
            app.DisplaySNRBarChartsButton.FontSize = y_mult*14;
            app.DisplaySNRBarChartsButton.Position = [x_mult*528 y_mult*310 x_mult*210 y_mult*37];
            app.DisplaySNRBarChartsButton.Text = 'Display SNR+++ Bar Charts';

            % Create ChanTimeandFreqViewerButton
            app.ChanTimeandFreqViewerButton = uibutton(app.CheckProcessTab, 'push');
            app.ChanTimeandFreqViewerButton.ButtonPushedFcn = createCallbackFcn(app, @ChanTimeandFreqViewerButtonPushed, true);
            app.ChanTimeandFreqViewerButton.FontSize = y_mult*14;
            app.ChanTimeandFreqViewerButton.Position = [x_mult*528 y_mult*260 x_mult*210 y_mult*37];
            app.ChanTimeandFreqViewerButton.Text = 'Chan Time and Freq Viewer';
     
            % Create SignalQualityIndicatorsButton
            app.SignalQualityIndicatorsButton = uibutton(app.CheckProcessTab, 'push');
            app.SignalQualityIndicatorsButton.ButtonPushedFcn = createCallbackFcn(app, @SignalQualityIndicatorsButtonPushed, true);
            app.SignalQualityIndicatorsButton.FontSize = y_mult*14;
            app.SignalQualityIndicatorsButton.Position = [x_mult*528 y_mult*210 x_mult*210 y_mult*37];
            app.SignalQualityIndicatorsButton.Text = 'Signal Quality Indicators';

%-----------------------------------------------------------




            % Create ClearprocesseddataButton
            app.ClearprocesseddataButton = uibutton(app.CheckProcessTab, 'push');
            app.ClearprocesseddataButton.ButtonPushedFcn = createCallbackFcn(app, @ClearprocesseddataButtonPushed, true);
            app.ClearprocesseddataButton.Position = [x_mult*528 y_mult*12 x_mult*210 y_mult*56];
            app.ClearprocesseddataButton.FontSize = y_mult*24;
            app.ClearprocesseddataButton.Text = 'Clear Proc Data';




            % Create PredictionTab
            app.PredictionTab = uitab(app.TabGroup);
            app.PredictionTab.Title = 'Prediction';
    
            % Create SetPredictionOptionsButton
            app.SetPredictionOptionsButton = uibutton(app.PredictionTab, 'push');
            app.SetPredictionOptionsButton.ButtonPushedFcn = createCallbackFcn(app, @SetPredictionOptionsButtonPushed, true);
            app.SetPredictionOptionsButton.FontSize = y_mult*24;
            app.SetPredictionOptionsButton.Position = [x_mult*66 y_mult*301 x_mult*170 y_mult*84];
            app.SetPredictionOptionsButton.Text = {'Set Predict'; 'Options'};


%----------------------------------------------------------------------------------------------
%----------------------------------------------------------------------------------------------
            % Create ModePairViewerFDButton
            app.ModePairViewerFDButton = uibutton(app.PredictionTab, 'push');
            app.ModePairViewerFDButton.ButtonPushedFcn = createCallbackFcn(app, @ModePairViewerFDButtonPushed, true);
            app.ModePairViewerFDButton.FontSize = y_mult*14;
            app.ModePairViewerFDButton.Position = [x_mult*562 y_mult*386 x_mult*171 y_mult*30];
            app.ModePairViewerFDButton.Text = 'Mode Pair Viewer (FD)';
            
            % Create ViewModeMapButton
            app.ViewModeMapButton = uibutton(app.PredictionTab, 'push');
            app.ViewModeMapButton.ButtonPushedFcn = createCallbackFcn(app, @ViewModeMapButtonPushed, true);
            app.ViewModeMapButton.FontSize = y_mult*14;
            app.ViewModeMapButton.Position = [x_mult*562 y_mult*353 x_mult*171 y_mult*30];
            app.ViewModeMapButton.Text = 'View Mode Map';

            % Create ShowPeakFindButton
            app.ShowPeakFindButton = uibutton(app.PredictionTab, 'push');
            app.ShowPeakFindButton.ButtonPushedFcn = createCallbackFcn(app, @ShowPeakFindButtonPushed, true);
            app.ShowPeakFindButton.FontSize = y_mult*14;
            app.ShowPeakFindButton.Position = [x_mult*562 y_mult*320 x_mult*171 y_mult*30];
            app.ShowPeakFindButton.Text = 'Show Peak Find';

            % Create ModeMapTagsButton
            app.ModeMapTagsButton = uibutton(app.PredictionTab, 'push');
            app.ModeMapTagsButton.ButtonPushedFcn = createCallbackFcn(app, @ModeMapTagsButtonPushed, true);
            app.ModeMapTagsButton.FontSize = y_mult*14;
            app.ModeMapTagsButton.Position = [x_mult*562 y_mult*287 x_mult*171 y_mult*30];
            app.ModeMapTagsButton.Text = 'Mode Map Tags';
 
            % Create MPRCvsTagButton
            app.MPRCvsTagButton = uibutton(app.PredictionTab, 'push');
            app.MPRCvsTagButton.ButtonPushedFcn = createCallbackFcn(app, @MPRCvsTagButtonPushed, true);
            app.MPRCvsTagButton.FontSize = y_mult*14;
            app.MPRCvsTagButton.Position = [x_mult*562 y_mult*254 x_mult*171 y_mult*30];
            app.MPRCvsTagButton.Text = 'MP RC vs Tag';  

            % Create DistanceMeanTableButton
            app.DistanceMeanTableButton = uibutton(app.PredictionTab, 'push');
            app.DistanceMeanTableButton.ButtonPushedFcn = createCallbackFcn(app, @DistanceMeanTableButtonPushed, true);
            app.DistanceMeanTableButton.FontSize = y_mult*14;
            app.DistanceMeanTableButton.Position = [x_mult*562 y_mult*221 x_mult*171 y_mult*30];
            app.DistanceMeanTableButton.Text = 'Distance/Mean Table';

            % Create LogLikelyhoodTableButton
            app.LogLikelyhoodTableButton = uibutton(app.PredictionTab, 'push');
            app.LogLikelyhoodTableButton.ButtonPushedFcn = createCallbackFcn(app, @LogLikelyhoodTableButtonPushed, true);
            app.LogLikelyhoodTableButton.FontSize = y_mult*14;
            app.LogLikelyhoodTableButton.Position = [x_mult*562 y_mult*188 x_mult*171 y_mult*30];
            app.LogLikelyhoodTableButton.Text = 'Log Likelyhood Table';

            % Create InteractiveMMViewerButton
            app.InteractiveMMViewerButton = uibutton(app.PredictionTab, 'push');
            app.InteractiveMMViewerButton.ButtonPushedFcn = createCallbackFcn(app, @InteractiveMMViewerButtonPushed, true);
            app.InteractiveMMViewerButton.FontSize = y_mult*14;
            app.InteractiveMMViewerButton.Position = [x_mult*562 y_mult*155 x_mult*171 y_mult*30];
            app.InteractiveMMViewerButton.Text = 'Interactive MM Viewer';

            % Create PredsButton
            app.PredsButton = uibutton(app.PredictionTab, 'push');
            app.PredsButton.ButtonPushedFcn = createCallbackFcn(app, @PredsButtonPushed, true);
            app.PredsButton.FontSize = y_mult*14;
            app.PredsButton.Position = [x_mult*562 y_mult*122 x_mult*171 y_mult*30];
            app.PredsButton.Text = '3 Preds';

             % Create MeanSTDmodesButton
            app.MeanSTDmodesButton = uibutton(app.PredictionTab, 'push');
            app.MeanSTDmodesButton.ButtonPushedFcn = createCallbackFcn(app, @MeanSTDmodesButtonPushed, true);
            app.MeanSTDmodesButton.FontSize = y_mult*14;
            app.MeanSTDmodesButton.Position =[x_mult*562 y_mult*89 x_mult*171 y_mult*30];
            app.MeanSTDmodesButton.Text = 'Mean/STD modes';

            % Create ShowDispersionButton
            app.ShowDispersionButton = uibutton(app.PredictionTab, 'push');
            app.ShowDispersionButton.ButtonPushedFcn = createCallbackFcn(app, @ShowDispersionButtonPushed, true);
            app.ShowDispersionButton.FontSize = y_mult*14;
            app.ShowDispersionButton.Position = [x_mult*562 y_mult*56 x_mult*171 y_mult*30];
            app.ShowDispersionButton.Text = 'Show Dispersion';

            % Create ShowMeshButton
            app.ShowMeshButton = uibutton(app.PredictionTab, 'push');
            app.ShowMeshButton.ButtonPushedFcn = createCallbackFcn(app, @ShowMeshButtonPushed, true);
            app.ShowMeshButton.FontSize = y_mult*14;
            app.ShowMeshButton.Position = [x_mult*562 y_mult*23 x_mult*171 y_mult*30];
            app.ShowMeshButton.Text = 'Show Mesh';

%----------------------------------------------------------------------------------------------
%----------------------------------------------------------------------------------------------


            % Create PREDICTIONButton
            app.PREDICTIONButton = uibutton(app.PredictionTab, 'push');
            app.PREDICTIONButton.ButtonPushedFcn = createCallbackFcn(app, @PREDICTIONButtonPushed, true);
            app.PREDICTIONButton.FontSize = y_mult*36;
            app.PREDICTIONButton.Position = [x_mult*73 y_mult*132 x_mult*285 y_mult*86];
            app.PREDICTIONButton.Text = 'PREDICTION';

            % Create PLampLabel
            app.PLampLabel = uilabel(app.PredictionTab);
            app.PLampLabel.HorizontalAlignment = 'right';
            app.PLampLabel.Position = [x_mult*382 y_mult*164 x_mult*25 y_mult*22];
            app.PLampLabel.Text = 'P:';
            app.PLampLabel.FontSize = 12 * x_mult;

            % Create PLamp
            app.PLamp = uilamp(app.PredictionTab);
            app.PLamp.Position = [x_mult*422 y_mult*164 x_mult*20 y_mult*20];
            app.PLamp.Color = [0.902 0.902 0.902];

            % Create ClearPredictionsButton
            app.ClearPredictionsButton = uibutton(app.PredictionTab, 'push');
            app.ClearPredictionsButton.ButtonPushedFcn = createCallbackFcn(app, @ClearPredictionsButtonPushed, true);
            app.ClearPredictionsButton.Position = [x_mult*370 y_mult*23 x_mult*171 y_mult*30];
            app.ClearPredictionsButton.Text = 'Clear Predictions';
            app.ClearPredictionsButton.FontSize = 14*y_mult;

            % Create PeakLocationmmLabel
            app.PeakLocationmmLabel = uilabel(app.PredictionTab);
            app.PeakLocationmmLabel.Position = [x_mult*274 y_mult*80 x_mult*152 y_mult*22];
            app.PeakLocationmmLabel.Text = 'Peak Location (mm)';
            app.PeakLocationmmLabel.FontSize = 14* y_mult;
            % Create Label_PL
            app.Label_PL = uilabel(app.PredictionTab);
            app.Label_PL.Position = [x_mult*449 y_mult*80 x_mult*95 y_mult*22];
            app.Label_PL.Text = '**';
            app.Label_PL.FontSize = 12 * y_mult;
              
            % Create ProduceareportButton
            app.ProduceareportButton = uibutton(app.PredictionTab, 'push');
            app.ProduceareportButton.ButtonPushedFcn = createCallbackFcn(app, @ProduceareportButtonPushed, true);
            app.ProduceareportButton.Position = [x_mult*40 y_mult*12 x_mult*100 y_mult*43];
            app.ProduceareportButton.Text = 'REPORT ';
            app.ProduceareportButton.FontSize = 16 * y_mult;
           
            % Create CONTACTWireTestLabel
            app.CONTACTWireTestLabel = uilabel(app.UIFigure);
            app.CONTACTWireTestLabel.FontSize = y_mult*30;
            app.CONTACTWireTestLabel.FontWeight = 'bold';
            app.CONTACTWireTestLabel.FontColor = [0 0 1];
            app.CONTACTWireTestLabel.Position = [x_mult*2 y_mult*513 x_mult*334 y_mult*39];
            app.CONTACTWireTestLabel.Text = 'CONTACT Wire- Test';



            % Create ProgMODELabel
            app.ProgMODELabel = uilabel(app.UIFigure);
            app.ProgMODELabel.Text = 'Mode: View';
            app.ProgMODELabel.FontSize = y_mult*18;
            app.ProgMODELabel.FontAngle = 'italic';
            app.ProgMODELabel.FontWeight = 'normal';
            app.ProgMODELabel.Position = [x_mult*600 y_mult*515 x_mult*150 y_mult*26];
            app.ProgMODELabel.FontColor = [0.4 0.4 0.4];
            
            % Create Program_version_label
            app.Program_version_label = uilabel(app.UIFigure);
            app.Program_version_label.FontWeight = 'bold';
            app.Program_version_label.Position = [x_mult*340 y_mult*515 x_mult*25 y_mult*22];
            app.Program_version_label.Text = '2.0';
            app.Program_version_label.FontSize = y_mult*12;


            % Create UserLabel
            app.UserLabel = uilabel(app.UIFigure);
            app.UserLabel.FontAngle = 'italic';
            app.UserLabel.Position = [x_mult*5 y_mult*39 x_mult*54 y_mult*22];
            app.UserLabel.Text = 'User:';
            app.UserLabel.FontSize = y_mult*14;
            
            % Create SentinalLabel_2
            app.SentinalLabel_2 = uilabel(app.UIFigure);
            app.SentinalLabel_2.FontAngle = 'italic';
            app.SentinalLabel_2.Position = [x_mult*5 y_mult*14 x_mult*72 y_mult*22];
            app.SentinalLabel_2.Text = 'Sentinal:';
            app.SentinalLabel_2.FontSize = y_mult*14;

            % Create LoginLampLabel
            app.LoginLampLabel = uilabel(app.UIFigure);
            app.LoginLampLabel.HorizontalAlignment = 'right';
            app.LoginLampLabel.Position = [x_mult*161 y_mult*28 x_mult*64 y_mult*22];
            app.LoginLampLabel.Text = 'Login';
            app.LoginLampLabel.FontSize =  14*y_mult ;
            % Create LoginLamp
            app.LoginLamp = uilamp(app.UIFigure);
            app.LoginLamp.Position = [x_mult*240 y_mult*28 x_mult*20 y_mult*20];

            % Create DataloadedLampLabel
            app.DataloadedLampLabel = uilabel(app.UIFigure);
            app.DataloadedLampLabel.HorizontalAlignment = 'right';
            app.DataloadedLampLabel.Position = [x_mult*290 y_mult*28 x_mult*90 y_mult*22];
            app.DataloadedLampLabel.Text = 'Data loaded';
            app.DataloadedLampLabel.FontSize = y_mult*14; 

            % Create DataloadedLamp
            app.DataloadedLamp = uilamp(app.UIFigure);
            app.DataloadedLamp.Position = [x_mult*391 y_mult*28 x_mult*20 y_mult*20];

            % Create CheckProcessLampLabel
            app.CheckProcessLampLabel = uilabel(app.UIFigure);
            app.CheckProcessLampLabel.HorizontalAlignment = 'right';
            app.CheckProcessLampLabel.Position = [x_mult*427 y_mult*27 x_mult*114 y_mult*22];
            app.CheckProcessLampLabel.Text = 'Check/Process';
            app.CheckProcessLampLabel.FontSize = y_mult*14;
  
            % Create CheckProcessLamp
            app.CheckProcessLamp = uilamp(app.UIFigure);
            app.CheckProcessLamp.Position = [x_mult*548 y_mult*27 x_mult*20 y_mult*20];

            % Create PredictionLampLabel
            app.PredictionLampLabel = uilabel(app.UIFigure);
            app.PredictionLampLabel.HorizontalAlignment = 'right';
            app.PredictionLampLabel.Position = [x_mult*582 y_mult*28 x_mult*74 y_mult*22];
            app.PredictionLampLabel.Text = 'Prediction';
            app.PredictionLampLabel.FontSize = y_mult*14; 

            % Create PredictionLamp
            app.PredictionLamp = uilamp(app.UIFigure);
            app.PredictionLamp.Position = [x_mult*665 y_mult*28 x_mult*20 y_mult*20];

            % Create USERLabel_val2
            app.USERLabel_val2 = uilabel(app.UIFigure);
            app.USERLabel_val2.FontAngle = 'italic';
            app.USERLabel_val2.Position = [x_mult*77 y_mult*40 x_mult*108 y_mult*22];
            app.USERLabel_val2.Text = 'None';
            app.USERLabel_val2.FontSize   =  14*y_mult ;

            % Create Sentinal_LabelVAL2
            app.Sentinal_LabelVAL2 = uilabel(app.UIFigure);
            app.Sentinal_LabelVAL2.FontAngle = 'italic';
            app.Sentinal_LabelVAL2.Position = [x_mult*77 y_mult*15 x_mult*70 y_mult*22];
            app.Sentinal_LabelVAL2.Text = 'None';
            app.Sentinal_LabelVAL2.FontSize   =  14*y_mult;

            % Show the figure after all components are created
            app.UIFigure.Visible = 'on';
           
 

        end
    end

    % App creation and deletion
    methods (Access = public)

        % Construct app
        function app = WPA_V2

            % Create UIFigure and components
            createComponents(app)

            % Register the app with App Designer
            registerApp(app, app.UIFigure)

            % Execute the startup function
            runStartupFcn(app, @startupFcn)

            if nargout == 0
                clear app
            end
        end

        % Code that executes before app deletion
        function delete(app)

            % Delete UIFigure when app is deleted
            delete(app.UIFigure)
        end
    end
end