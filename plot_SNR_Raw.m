function  rejection_indicators   =  plot_SNR_Raw(varargin)

% ---------------------------------------------------------------------- %
% for use with single result of Raw data file 
% Jim 11/7/2024
% ---------------------------------------------------------------------- %
% To Do:
% Put the numbers into quality indicators
%
% ---------------------------------------------------------------------- %
%INPUTS
% 2 options :  
% (a) nargin==0   --- no inputs parameters   plot_SNR_Raw()  select the file /  and  select what to plot 
% (b) nargin==3   --- 3 input paramenets     plot_SNR_Raw(test_data,do_plots,snr_settings)
% ---------------------------------------------------------------------- %
%NOTES
% ------------ all these properties should be in processing settings
% ---------------------------------------------------------------------- %
%  do_plots = [1 1 1 1]  %  to plot everything
%{
settings.RMS_boundaries     =  [0.1  , 0.25 , 0.6]                             ;
settings.SNR_boundaries     =  [ 0.3 , 1    ,   2]                             ;
settings.LFN_boundaries     =  [-1   ,-2    ,  -5]                             ; 
settings.HFN_boundaries     =  [-1   ,-2    ,  -5]                             ;

settings.exitation_freq_kHz  =  50                                              ;  
settings.SNR_bandwidth_kHz   =  21                                              ;  
settings.time_gate           =  60                                              ;
settings.time_gate2          =                                                  ;
settings.time_gate3          =                                                  ;
settings.diagonal_time_gate  =  200                                             ;

%}

%  TO DO
%  First put in the vertical line for the third timegate



% ------------------------------------------------------------------------------------------------------------------------------- %
% ------------------------------------------------------------------------------------------------------------------------------- %
% ------------------------------------------------------------------------------------------------------------------------------- %
% ------------------------------------------------------------------------------------------------------------------------------- %



switch(nargin)
    case(0)  %------------------------------------
% FORMAT::   rejection_indicators   = plot_SNR_Raw()
snr_settings       = load_structure_from_file('snr_settings.dat')  ;
RMS_boundaries   = snr_settings.RMS_boundaries                       ;
SNR_boundaries   = snr_settings.SNR_boundaries                     ;
LFN_boundaries   = snr_settings.LFN_boundaries                     ;  %  Green / Yellow / Orange / Red   ---- GOOD :: BAD 
HFN_boundaries   = snr_settings.HFN_boundaries                     ;
exitation_freq_kHz = snr_settings.exitation_freq_kHz               ;  
SNR_bandwidth_kHz = snr_settings.SNR_bandwidth_kHz                 ;  
time_gate    = snr_settings.time_gate                              ;
time_gate2    = snr_settings.time_gate2                            ;
time_gate3    = snr_settings.time_gate3                            ;
diagonal_time_gate  = snr_settings.diagonal_time_gate              ;
starting_dir  = 'P:\GITHUBS\AIDATA'                                ;

P_W_D =   pwd;
if (exist(starting_dir)) == 7  
cd(starting_dir)
end
[file_name,file_path_] = uigetfile('*.mat',  'Selec the comp file','MultiSelect','off') ;

cd (P_W_D);

%--------------------------
% choose what to plot
%--------------------------

plot_list =   {'Maps','Bar Charts','indicators','time_freq_traces' } ;

do_plots =[0 0 0 0];
do_plots_dum =  choose_plots_to_show(plot_list);
do_plots(find(do_plots_dum ==1)) = 1;
[ALL_time_d,time_d,ALL_time,time_,All_noise_d,noise_d ]  = load_the_data_from_file(file_path_,file_name,time_gate,time_gate2);

    case(2) %------------------------------------
        
%rejection_indicators   =  plot_SNR_Raw('C:\Users\Dev\SLAB_data\2024\00 NEW HEAD\CW_test_Mark_Evans__H0CE-107$1$.mat','P:\GITHUBS\contact_AI\SETTINGS_FILES\snr_settings2.dat')

test_data_path       = varargin{1}  ; 
do_plots             = varargin{2}  ; 
snr_settings_N         = load_structure_from_file('P:\GITHUBS\contact_AI\SETTINGS_FILES\snr_settings2.dat');
snr_settings        = convert_to_snr_struct(snr_settings_N);
dummy_1              = load(test_data_path)        ;
test_data            =  dummy_1.test_data     ;

    case(3) %------------------------------------
        
%rejection_indicators   =  plot_SNR_Raw('C:\Users\Dev\SLAB_data\2024\00 NEW HEAD\CW_test_Mark_Evans__H0CE-107$1$.mat','P:\GITHUBS\contact_AI\SETTINGS_FILES\snr_settings2.dat')

test_data_path       = varargin{1}  ; 
do_plots             = varargin{2}  ; 
snr_settings       = varargin{3}  ;
%snr_settings        = convert_to_snr_struct(snr_settings_N);
dummy_1              = load(test_data_path)        ;
test_data            =  dummy_1.test_data     ;

mag_fac                   =  1.9531;
base_width                = 1920                  ; 
base_height               = 1080                  ; 
Pix_SS = get(0,'screensize')                ;
x_mult = (Pix_SS(3)/base_width)   * mag_fac ;
y_mult = (Pix_SS(4)/base_height)  * mag_fac ;

    case(6) %------------------------------------
% FORMAT::   rejection_indicators   = plot_SNR_Raw(test_data,do_plots,snr_settings)

%rejection_indicators   =  plot_SNR_Raw(td ,do_plots,snr_s);
test_data       = varargin{1}  ; 
do_plots        = varargin{2}  ; 
snr_settings    = varargin{3}  ; 

base_width = varargin{4};
base_height = varargin{5};
mag_fac   = varargin{6};

Pix_SS = get(0,'screensize')                ;
x_mult = (Pix_SS(3)/base_width)   * mag_fac ;
y_mult = (Pix_SS(4)/base_height)  * mag_fac ;

end %switch(narargin)

if nargin ==2 || nargin ==3 || nargin ==6
RMS_boundaries     = snr_settings.RMS_boundaries     ;
SNR_boundaries     = snr_settings.SNR_boundaries     ;
LFN_boundaries     = snr_settings.LFN_boundaries     ;  %  Green / Yellow / Orange / Red   ---- GOOD :: BAD 
HFN_boundaries     = snr_settings.HFN_boundaries     ;
exitation_freq_kHz = snr_settings.exitation_freq_kHz ;  
SNR_bandwidth_kHz  = snr_settings.SNR_bandwidth_kHz  ;  
time_gate          = snr_settings.time_gate          ;
time_gate2          = snr_settings.time_gate2          ;
time_gate3          = snr_settings.time_gate3          ;

diagonal_time_gate = snr_settings.diagonal_time_gate ;


[ALL_time_d,time_d,ALL_time,time_,All_noise_d,noise_d ] =  load_the_data_from_structure(test_data,time_gate,time_gate2);


file_name = test_data.file_with_path(max(find(test_data.file_with_path=='\'))+1:end-4);

end %if nargin ==2 || nargin ==3

% give option to plot time/frequecy traces   -  for selected send and
%------------------------------------------------
% Calculate matrix properties
%-----------------------------------------------

[samp_freq,freq_axis_KHz,fft_d_temp,fft_n_temp ,RMS_mat,SNR_mat_DB,LFN_mat_DB,HFN_mat_DB]  =  calculate_mat_properties(time_,ALL_time_d,time_d,exitation_freq_kHz,SNR_bandwidth_kHz,All_noise_d,noise_d);

%------------------------------------------------
% PLOT COLORMAPS
%-----------------------------------------------

if do_plots(1) ==1
plot_colourmaps(RMS_mat,SNR_mat_DB,LFN_mat_DB,HFN_mat_DB,file_name,x_mult,y_mult,mag_fac)
end %if do_plots(1) ==1

%------------------------------------------------
% CREATE THE DATA FOR THE BARCHART
%-----------------------------------------------
ALL_bars = create_ALL_Bars(ALL_time_d,RMS_mat,SNR_mat_DB,LFN_mat_DB,HFN_mat_DB);
%------------------------------------------------
% PLOT BARCHART
%------------------------------------------------

if do_plots(2) ==1
plot_Barcarts(ALL_bars,RMS_boundaries,SNR_boundaries,LFN_boundaries,HFN_boundaries,file_name,x_mult,y_mult,mag_fac);
end %if do_plots(2) ==1

% ----------------------------------------------------------
% Calcutate REJECTION INDICATORS 
% ----------------------------------------------------------
rejection_indicators = Calcutate_REJECTION_INDICATORS(ALL_bars,RMS_boundaries,SNR_boundaries,LFN_boundaries,HFN_boundaries); 
% ----------------------------------------------------------
% Plot REJECTION INDICATORS 
% ----------------------------------------------------------
if do_plots(3) == 1  
Plot_REJECTION_INDICATORS (rejection_indicators,file_name,ALL_bars,x_mult,y_mult,mag_fac )
end %if do_plots(3) == 1

% ----------------------------------------------------------
% Plot selected_time/freq_traces
% ----------------------------------------------------------

if do_plots(4) == 1
row_ind = 1;   % start val 
col_ind = 2;   % start val 

plot_time_and_frequencies(ALL_time_d,ALL_time,All_noise_d,freq_axis_KHz,fft_d_temp,fft_n_temp,exitation_freq_kHz,SNR_bandwidth_kHz,time_gate,time_gate2,time_gate3,file_name,row_ind,col_ind,x_mult,y_mult,mag_fac)

end %if do_plots(4) == 1

end %function   plot_SNR_Raw(raw_data)

%------------------------------------------------------------------------------------------------------------------------------------------------------
%------------------------------------------------------------------------------------------------------------------------------------------------------
%------------------FUNCTIONS---------------------------------------------------------------------------------------------------------------------------  
%------------------------------------------------------------------------------------------------------------------------------------------------------
%------------------------------------------------------------------------------------------------------------------------------------------------------


                                       
function plot_time_and_frequencies(ALL_time_d,ALL_time, All_noise_d, freq_axis_KHz,fft_d_temp, fft_n_temp, exitation_freq_kHz,SNR_bandwidth_kHz,time_gate,time_gate2,time_gate3,file_name,row_ind,col_ind,x_mult,y_mult,mag_fac)
%

fig = uifigure('Resize','off','Units','normalized','Position',[0.05,0.05,0.29*mag_fac,0.435*mag_fac],'Name', 'Channel Pair Viewer (Send/Receive)' );
fig.Icon = 'ICON2.png';
px_LH = 20; py_LH = 10; px_SZ = 550; py_SZ = 450;
p1 = uipanel(fig,'Position',[x_mult*px_LH y_mult*py_LH x_mult*px_SZ y_mult*py_SZ],'AutoResizeChildren','off');

% fH3 = figure('units','normalized');
sbH1 = subplot(2,1,1, 'Parent', p1);
sbH2 = subplot(2,1,2, 'Parent', p1);

R_menu_string = {'R=1','R=2','R=3','R=4','R=5','R=6','R=7','R=8','R=9','R=10','R=11','R=12'};

if length(fft_n_temp) == 0
C_menu_string = {'C=1','C=2','C=3','C=4','C=5','C=6','C=7','C=8','C=9','C=10','C=11','C=12'};
else
C_menu_string = {'C=Noise','C=1','C=2','C=3','C=4','C=5','C=6','C=7','C=8','C=9','C=10','C=11','C=12'};
end %if length(fft_n_temp) == 0



Popup1 = uidropdown(fig,"Items",R_menu_string,'Position', [x_mult*1 y_mult*120 x_mult*74 y_mult*25],'FontSize',y_mult*11,'Value',R_menu_string{row_ind},'ValueChangedFcn',@change_row);
Popup2 = uidropdown(fig,"Items",C_menu_string,'Position', [x_mult*1 y_mult*80 x_mult*74 y_mult*25],'FontSize',y_mult*11,'Value',C_menu_string{col_ind},'ValueChangedFcn',@change_col);
PushButton = uibutton(fig,'Position',[x_mult*5,y_mult*20,x_mult*60,y_mult*30],'Text','Replot','FontSize',y_mult*12,'ButtonPushedFcn',@Replot_signals);

plot_data_structure.y_mult                         = y_mult             ;
plot_data_structure.R_menu_string                  = R_menu_string      ;
plot_data_structure.C_menu_string                  = C_menu_string      ;
plot_data_structure.p1                             = p1                 ;
plot_data_structure.ALL_time                       = ALL_time           ; 

plot_data_structure.row_ind                        = row_ind            ;
plot_data_structure.col_ind                        = col_ind            ;
plot_data_structure.time_gate                      = time_gate          ;          
plot_data_structure.time_gate2                     = time_gate2         ;          
plot_data_structure.time_gate3                     = time_gate3         ;          
plot_data_structure.sbH1                           = sbH1               ;
plot_data_structure.sbH2                           = sbH2               ;
plot_data_structure.fig                            = fig                ;
plot_data_structure.freq_axis_KHz                  = freq_axis_KHz      ; 


if length(fft_n_temp) ~=0
temp_1  (:,:,1) = All_noise_d(:,:);
temp_1  (:,:,2:13) = ALL_time_d(:,:,1:12);
plot_data_structure.ALL_time_d = temp_1;
temp_2  (:,:,1) = fft_n_temp(:,:);
temp_2  (:,:,2:13) = fft_d_temp(:,:,1:12);
plot_data_structure.fft_d_temp = temp_2;
else
plot_data_structure.fft_d_temp                     = fft_d_temp         ;       
plot_data_structure.ALL_time_d                     = ALL_time_d         ;
end


plot_data_structure.exitation_freq_kHz             = exitation_freq_kHz ; 
plot_data_structure.SNR_bandwidth_kHz              = SNR_bandwidth_kHz  ; 
plot_data_structure.file_name                      = file_name          ; 





fig.UserData                                       = plot_data_structure;
update_time_plot(plot_data_structure)  

end % function plot_time_and_frequencies(ALL_time_d,time_d,ALL_time,time_ )


function change_row(hObject, ~)
new_value =  get(hObject,'Value');
plot_data_structure  =  get(get(hObject,'Parent'),'UserData');
dummy = find(ismember(plot_data_structure.R_menu_string,new_value));

plot_data_structure.row_ind = dummy;
set(get(hObject,'Parent'),'UserData',plot_data_structure);
end %function change_row(hObject, ~)

function change_col(hObject, ~)
new_value =  get(hObject,'Value');
plot_data_structure  =  get(get(hObject,'Parent'),'UserData');
dummy = find(ismember(plot_data_structure.C_menu_string,new_value));
plot_data_structure.col_ind = dummy;
set(get(hObject,'Parent'),'UserData',plot_data_structure);
end %function change_row(hObject, ~)

function Replot_signals(hObject, ~)
plot_data_structure  =  get(get(hObject,'Parent'),'UserData');
update_time_plot(plot_data_structure)  
end %function change_row(hObject, ~)

function  update_time_plot(plot_data_structure)
y_mult             = plot_data_structure.y_mult             ;
p1                 = plot_data_structure.p1                 ;   
ALL_time           = plot_data_structure.ALL_time           ; 
row_ind            = plot_data_structure.row_ind            ;
col_ind            = plot_data_structure.col_ind            ;
time_gate          = plot_data_structure.time_gate          ;
time_gate2          = plot_data_structure.time_gate2        ;
time_gate3          = plot_data_structure.time_gate3        ;

sbH1               = plot_data_structure.sbH1               ;
sbH2               =  plot_data_structure.sbH2              ;
fig                =  plot_data_structure.fig               ;
freq_axis_KHz      = plot_data_structure.freq_axis_KHz      ; 
fft_d_temp         = plot_data_structure.fft_d_temp         ;   
exitation_freq_kHz = plot_data_structure.exitation_freq_kHz ; 
SNR_bandwidth_kHz  = plot_data_structure.SNR_bandwidth_kHz  ; 
file_name          = plot_data_structure.file_name          ; 
ALL_time_d         = plot_data_structure.ALL_time_d         ;

hold(sbH1,'off')
plot(sbH1,ALL_time*1000 ,ALL_time_d(:,row_ind,col_ind))
hold(sbH1,'on')
plot(sbH1,[ALL_time(time_gate)*1000,ALL_time(time_gate)*1000],[sbH1.YLim(1),sbH1.YLim(2)])
plot(sbH1,[ALL_time(time_gate2)*1000,ALL_time(time_gate2)*1000],[sbH1.YLim(1),sbH1.YLim(2)])
plot(sbH1,[ALL_time(time_gate3)*1000,ALL_time(time_gate3)*1000],[sbH1.YLim(1),sbH1.YLim(2)])


sbH1.XLabel.String = 'Time (ms)';
legend(sbH1, {'Data','T Gate 1','T Gate 2','T Gate 3'})
sbH1.FontSize =9.5  *y_mult;

%|subplot(sbH2)
hold(sbH2,'off')
plot(sbH2,freq_axis_KHz,fft_d_temp(:,row_ind,col_ind))
hold(sbH2,'on')

plot(sbH2,[exitation_freq_kHz + SNR_bandwidth_kHz , exitation_freq_kHz + SNR_bandwidth_kHz] , [sbH2.YLim(1),sbH2.YLim(2)],'r')
plot(sbH2,[exitation_freq_kHz - SNR_bandwidth_kHz , exitation_freq_kHz - SNR_bandwidth_kHz] , [sbH2.YLim(1),sbH2.YLim(2)],'r')
legend(sbH2, {'Data','L band',' U band'})
sbH2.XLabel.String = 'Freq (kHz)';
sbH2.FontSize =9.5  *y_mult;

p1.Title= (['Time/Freq, ',plot_data_structure.R_menu_string{row_ind},', ',plot_data_structure.C_menu_string{col_ind},'    ::   ',remove_(file_name)]);
p1.BorderColor  = [0.9400 0.9400 0.9400];
p1.TitlePosition ='centertop';
p1.FontSize = 14*y_mult;
p1.FontWeight = 'bold';

end %function  update_time_plot(plot_data_structure)

function  Plot_REJECTION_INDICATORS (rejection_indicators,file_name,ALL_bars,x_mult,y_mult,mag_fac)

fig = uifigure('Resize','off','Units','normalized','Position',[0.05000 0.05000 0.2900*mag_fac 0.2450*mag_fac],'Name', 'Quality indicators' );
fig.Icon = 'ICON2.png';

px_LH = 10; py_LH = 10; px_SZ = 540; py_SZ = 230;
p1 = uipanel(fig,'Position',[x_mult*px_LH y_mult*py_LH x_mult*px_SZ y_mult*py_SZ],'AutoResizeChildren','off');
mycolors                  =     [1, 0, 0 ;  1, 0.55, 0.01  ; 1, 1, 0.3 ;  0,1,0];

ax1 = subplot(1,1,1, 'Parent', p1);
ax1.CLim =[1 4];
hold(ax1,'on')
imagesc(ax1,rejection_indicators);
ax1.Colormap = mycolors;
ax1.XTick = 1:12;
ax1.YTick = 1:4;
ax1.YTickLabel = {'RMS','SNR','LFN','HFN'};
ax1.YLim =[0.5 4.5];
ax1.XLim= [0.5 12.5];


ax1.FontSize = 9.5 * y_mult;
xLL = ax1.XLim;
yLL = ax1.YLim;
xtt =ax1.XTick;
ytt = ax1.YTick;

%rejection_indicators(file_inds(index_2),:,:)
%  for each on create  a set of indicator lights  RMS / SNR / LFN / HFN 
% for each one there are 4 x 12 values  plot as an image or colormap
% G / O / Y / R      1 / 2 / 3 / 4
% axis equal

%vertical
%keyboard
for indexa = 1: length(ytt)
plot(ax1,[xLL(1),xLL(end)],[ytt(indexa)-0.5,ytt(indexa)-0.5],'k')
if indexa == length(ytt)
plot(ax1,[xLL(1),xLL(end)],[ytt(indexa)+0.5,ytt(indexa)+0.5],'k')
end %if indexa == length(ytt)
end %for index = 1: length(xtt)

%horizontal lines
for indexb = 1: length(xtt)
plot(ax1,[xtt(indexb)-0.5,xtt(indexb)-0.5],[yLL(1),yLL(end)],'k')
if indexb == length(xtt)
plot(ax1,[xtt(indexb)+0.5,xtt(indexb)+0.5],[yLL(1),yLL(end)],'k')
end %if indexa == length(ytt)
end %for index = 1: length(ytt)


for n=1:numel(ALL_bars)
    [x,y]=ind2sub(size(ALL_bars),n);
    text(ax1,y,x,num2str( (round(ALL_bars(n)*10)/10)),"FontSize",y_mult*8,"Color",'k','HorizontalAlignment', 'center')
end %for n=1:numel(ALL_bars)

ax1.XLabel.String = 'Channel #';
p1.Title = ['Quality indicators:: ' , remove_(remove_(file_name))   ,'.'];
p1.BorderColor  = [0.9400 0.9400 0.9400];
p1.TitlePosition ='centertop';
p1.FontSize = 14 * y_mult;
p1.FontWeight = 'bold';
end %function  Plot_REJECTION_INDICATORS (rejection_indicators )

function rejection_indicators = Calcutate_REJECTION_INDICATORS(ALL_bars,RMS_boundaries,SNR_boundaries,LFN_boundaries,HFN_boundaries) 
rejection_indicators      =     zeros(size(ALL_bars)) ;
all_boundaries = zeros(4,3);
all_boundaries(1,:) = RMS_boundaries ;
all_boundaries(2,:) = SNR_boundaries ;
all_boundaries(3,:) = LFN_boundaries ;
all_boundaries(4,:) = HFN_boundaries ;


for index_pre = 1: 2
rejection_indicators(index_pre,:) = ALL_bars(index_pre,:) < all_boundaries(index_pre,1);
rejection_indicators(index_pre,:) = rejection_indicators(index_pre,:) +  2*(ALL_bars(index_pre,:) >= all_boundaries(index_pre,1) & ALL_bars(index_pre,:) < all_boundaries(index_pre,2));
rejection_indicators(index_pre,:) = rejection_indicators(index_pre,:) +  3*(ALL_bars(index_pre,:) >= all_boundaries(index_pre,2) & ALL_bars(index_pre,:) < all_boundaries(index_pre,3));
rejection_indicators(index_pre,:) = rejection_indicators(index_pre,:) +  4*(ALL_bars(index_pre,:) >= all_boundaries(index_pre,3));
end % for index_pre = 1: size(ALL_bars,3)

for index_pre = 3: 4
rejection_indicators(index_pre,:) = ALL_bars(index_pre,:) > all_boundaries(index_pre,1);
rejection_indicators(index_pre,:) = rejection_indicators(index_pre,:) +  2*(ALL_bars(index_pre,:) <= all_boundaries(index_pre,1) & ALL_bars(index_pre,:) > all_boundaries(index_pre,2));
rejection_indicators(index_pre,:) = rejection_indicators(index_pre,:) +  3*(ALL_bars(index_pre,:) <= all_boundaries(index_pre,2) & ALL_bars(index_pre,:) > all_boundaries(index_pre,3));
rejection_indicators(index_pre,:) = rejection_indicators(index_pre,:) +  4*(ALL_bars(index_pre,:) <= all_boundaries(index_pre,3));
end % for index_pre = 3: 4
end %function rejection_indicators = Calcutate_REJECTION_INDICATORS(ALL_bars,RMS_mat,SNR_mat_DB,LFN_mat_DB,HFN_mat_DB); 


function plot_Barcarts(ALL_bars,RMS_boundaries,SNR_boundaries,LFN_boundaries,HFN_boundaries,file_name,x_mult,y_mult,mag_fac)
%---------------------------------------------
% Bar DATA -----------------------------------
%---------------------------------------------
temp_amps = ALL_bars (1,:);
bars_temp = ALL_bars (2,:); 
bars2_temp= ALL_bars (3,:);
bars3_temp= ALL_bars (4,:); 
%---------------------------------------------
% Bar DATA -----------------------------------
%---------------------------------------------
fig = uifigure('Resize','off','Units','normalized','Position',[0.05,0.05,0.29*mag_fac,0.435*mag_fac],'Name', 'Channel Bar Charts' );
fig.Icon = 'ICON2.png';
px_LH = 10; py_LH = 10; px_SZ = 540; py_SZ = 450;
p1 = uipanel(fig,'Position',[x_mult*px_LH y_mult*py_LH x_mult*px_SZ y_mult*py_SZ],'AutoResizeChildren','off');

%f2H = figure; 
%hold on
% (1) RMS

ax1 = subplot(2,2,1, 'Parent', p1);
hold(ax1,'on')
bar(ax1,temp_amps)

ax1.XLim = [0.5,12.5]                 ;
ax1.YLim = [0,  2 * mean(temp_amps)]  ;

%RMS_boundaries
xLi = ax1.XLim;
plot(ax1,[xLi(1),xLi(2)] , [ RMS_boundaries(1),RMS_boundaries(1)],'r')
plot(ax1,[xLi(1),xLi(2)] , [ RMS_boundaries(2),RMS_boundaries(2)],'y')
plot(ax1,[xLi(1),xLi(2)] , [ RMS_boundaries(3),RMS_boundaries(3)],'g')

ax1.XTick = 1:size(ALL_bars,2);
ax1.XTickLabelRotation = 0 ;
ax1.Title.String = 'RMS/ each channel (averaged)';
ax1.YLabel.String = 'normalised';
ax1.XLabel.String = 'chan#';
ax1.FontSize = 8.5 * y_mult;
% (2) SNR
ax2 = subplot(2,2,2, 'Parent', p1);
hold(ax2,'on')
bar(ax2,bars_temp)
ax2.XLim = [0.5,12.5]                 ;
if mean(bars_temp)>0
ax2.YLim = [0,  2 * mean(bars_temp)];
else
ax2.YLim = [2 * mean(bars_temp) , 0];  
end    

%RMS_boundaries
xLi = ax1.XLim;

plot(ax2,[xLi(1),xLi(2)] , [ SNR_boundaries(1),SNR_boundaries(1)],'r')
plot(ax2,[xLi(1),xLi(2)] , [ SNR_boundaries(2),SNR_boundaries(2)],'y')
plot(ax2,[xLi(1),xLi(2)] , [ SNR_boundaries(3),SNR_boundaries(3)],'g')

ax2.XTick  = 1:size(ALL_bars,2);
ax2.XTickLabelRotation = 0 ;

ax2.Title.String  =  'SNR/ each channel (averaged)';
ax2.YLabel.String = 'dB' ;
ax2.XLabel.String = 'chan#';
ax2.FontSize = 8.5 * y_mult;

% (3) LFN
ax3 = subplot(2,2,3, 'Parent', p1);
hold(ax3,'on')
bar(ax3,bars2_temp)
ax3.XLim = [0.5,12.5];

if mean(bars2_temp)>0
ax3.YLim = [0,  2 * mean(bars2_temp)] ;
else
ax3.YLim = [2 * mean(bars2_temp), 0]  ; 
end

%RMS_boundaries
xLi = ax1.XLim;

plot(ax3,[xLi(1),xLi(2)] , [ LFN_boundaries(1),LFN_boundaries(1)],'r')
plot(ax3,[xLi(1),xLi(2)] , [ LFN_boundaries(2),LFN_boundaries(2)],'y')
plot(ax3,[xLi(1),xLi(2)] , [ LFN_boundaries(3),LFN_boundaries(3)],'g')

ax3.XTick  = 1:size(ALL_bars,2);
ax3.XTickLabelRotation = 0 ;
ax3.Title.String  =  'LFN/ each channel (averaged)';
ax3.YLabel.String = 'dB' ;
ax3.XLabel.String = 'chan#';
ax3.FontSize = 8.5 * y_mult;

% (4) HFN
ax4 = subplot(2,2,4, 'Parent', p1);
hold(ax4,'on')
bar(ax4,bars3_temp)
ax4.XLim = [0.5,12.5]                 ;

if mean(bars3_temp) >0
ax4.YLim = [0,  2 * mean(bars3_temp)];
else
ax4.YLim = [2 * mean(bars3_temp) ,0 ];
end



%RMS_boundaries
xLi = ax1.XLim;

plot(ax4,[xLi(1),xLi(2)] , [ HFN_boundaries(1),HFN_boundaries(1)],'r')
plot(ax4,[xLi(1),xLi(2)] , [ HFN_boundaries(2),HFN_boundaries(2)],'y')
plot(ax4,[xLi(1),xLi(2)] , [ HFN_boundaries(3),HFN_boundaries(3)],'g')

ax4.XTick  = 1:size(ALL_bars,2);
ax4.XTickLabelRotation = 0 ;
ax4.Title.String  =  'HFN/ each channel (averaged)';
ax4.YLabel.String = 'dB' ;
ax4.XLabel.String = 'chan#';
ax4.FontSize = 8.5 * y_mult;

p1.Title = ['Bar charts: ' remove_(file_name),'.'];
p1.BorderColor  = [0.9400 0.9400 0.9400];
p1.TitlePosition ='centertop';
p1.FontSize = 14 * y_mult ;
p1.FontWeight = 'bold';
end %function  plot_Barcarts(ALL_bars)


function ALL_bars = create_ALL_Bars(ALL_time_d,RMS_mat,SNR_mat_DB,LFN_mat_DB,HFN_mat_DB)

m1_temp =  RMS_mat ; 
m2_temp =  SNR_mat_DB ;
m3_temp =  LFN_mat_DB;
m4_temp =  HFN_mat_DB;

ALL_bars = zeros (4 ,   size(ALL_time_d,3))    ;

% RMS
%

%for index_3 = 1: length(m1_temp)
%temp_amps(index_3)   =  mean([temp_(index_3,:),temp_(:,index_3)'])  ;
%end %for index_3 = 1: length(temp_ )

m1_temp (eye(size(m1_temp ))==1) = nan;
barsa_temp = (mean(m1_temp,1,'omitnan')+mean(m1_temp,2,'omitnan')') / 2;
barsa_temp = barsa_temp /mean(barsa_temp);
ALL_bars(1,:)  = barsa_temp; 

% SNR
%

m2_temp (eye(size(m2_temp ))==1) = nan;
bars_temp = (mean(m2_temp,1,'omitnan')+mean(m2_temp,2,'omitnan')') / 2;
ALL_bars (2,:)   =bars_temp; 

% LFN
%

%ALL_bars (3,:)   =bars_temp; 
m3_temp (eye(size(m3_temp ))==1) = nan;
bars2_temp = (mean(m3_temp,1,'omitnan')+mean(m3_temp,2,'omitnan')') / 2;
ALL_bars (3,:)   =bars2_temp; 

% HFN
%

m4_temp (eye(size(m4_temp ))==1) = nan;
bars3_temp = (mean(m4_temp,1,'omitnan')+mean(m4_temp,2,'omitnan')') / 2;
ALL_bars (4,:)   =bars3_temp; 
end



function plot_colourmaps(RMS_mat,SNR_mat_DB,LFN_mat_DB,HFN_mat_DB,file_name,x_mult,y_mult,mag_fac)

fig = uifigure('Resize','off','Units','normalized','Position',[0.05,0.05,0.29*mag_fac,0.435*mag_fac],'Name', 'Channel Colourmaps' );
fig.Icon = 'ICON2.png';

px_LH = 10; py_LH = 10; px_SZ = 540; py_SZ = 450;
p1 = uipanel(fig,'Position',[x_mult*px_LH y_mult*py_LH x_mult*px_SZ y_mult*py_SZ],'AutoResizeChildren','off');

%---------------------
% COLORMAPS
%---------------------
m1_temp =  RMS_mat ; 
m2_temp =  SNR_mat_DB ;
m3_temp =  LFN_mat_DB;
m4_temp =  HFN_mat_DB;


% (1) RMS  ---------------------------------------------------------------
ax1 = subplot(2,2,1, 'Parent', p1);
imagesc (ax1,m1_temp)
%imagesc (m1_temp)
hold(ax1,'on')
ax1.YTick = [1:size(m1_temp,1)];
ax1.YLabel.String = 'Channel #' ;
ax1.XTick = [1:size(m1_temp,2)];
ax1.XLabel.String = 'Channel #' ;
ax1.FontSize = 8.5 * y_mult;

%clim([1 6])
for n=1:numel(m1_temp)
    [x,y]=ind2sub(size(m1_temp),n);
    if m1_temp(n)>0
    text(ax1,y,x,num2str( abs(round(m1_temp(n)*10)/10)),"FontSize",y_mult*6,"Color",'k','HorizontalAlignment', 'center')
    else
    text(ax1,y,x,num2str( abs(round(m1_temp(n)*10)/10)),"FontSize",y_mult*6,"Color",'w','HorizontalAlignment', 'center')
    end
end %for n=1:numel(m1_temp)

ax1.Title.String = 'RMS(black# +ve white# -ve)';



% (2) SNR  ---------------------------------------------------------------

ax2 = subplot(2,2,2, 'Parent', p1);
imagesc (ax2,m2_temp)
hold(ax2,'on')
ax2.YTick = [1:size(m1_temp,1)] ;
ax2.YLabel.String = 'Channel #' ;
ax2.XTick = [1:size(m1_temp,2)] ;
ax2.XLabel.String = 'Channel #' ;
ax2.FontSize = 8.5 * y_mult;
ax2.CLim = [-1 10] ;

for n=1:numel(m2_temp)
    [x,y]=ind2sub(size(m2_temp),n);
    if m2_temp(n)>0
    text(ax2,y,x,num2str( abs(round(m2_temp(n)*10)/10)),"FontSize",y_mult*6,"Color",'k','HorizontalAlignment', 'center')
    else
    text(ax2,y,x,num2str( abs(round(m2_temp(n)*10)/10)),"FontSize",y_mult*6,"Color",'w','HorizontalAlignment', 'center')
    end
end %for n=1:numel(m2_temp)

ax2.Title.String =  'SNR(black# +ve white# -ve)';

% (3) LFN  ---------------------------------------------------------------
ax3 = subplot(2,2,3, 'Parent', p1);
imagesc (ax3,m3_temp)

hold(ax3,'on')
ax3.YTick = [1:size(m1_temp,1)] ;
ax3.YLabel.String = 'Channel #' ;
ax3.XTick = [1:size(m1_temp,2)] ;
ax3.XLabel.String = 'Channel #' ;
ax3.CLim = [-12 3];
ax3.FontSize = 8.5 * y_mult;
for n=1:numel(m3_temp)
    [x,y]=ind2sub(size(m3_temp),n);
    if m3_temp(n)>0
    text(ax3,y,x,num2str( abs(round(m3_temp(n)*10)/10)),"FontSize",y_mult*6,"Color",'k','HorizontalAlignment', 'center')
    else
    text(ax3,y,x,num2str( abs(round(m3_temp(n)*10)/10)),"FontSize",y_mult*6,"Color",'w','HorizontalAlignment', 'center')
    end
end %for n=1:numel(m3_temp)

%title('LFN(black# +ve white# -ve)')
ax3.Title.String = 'LFN(black# +ve white# -ve)';

% (4) HFN  ---------------------------------------------------------------

ax4 = subplot(2,2,4, 'Parent', p1);
imagesc (ax4,m4_temp)
hold(ax4,'on')
ax4.YTick = [1:size(m1_temp,1)] ;
ax4.YLabel.String = 'Channel #' ;
ax4.XTick = [1:size(m1_temp,2)] ;
ax4.XLabel.String = 'Channel #' ;
ax4.CLim = [-12 3];
ax4.FontSize = 8.5 * y_mult;
for n=1:numel(m4_temp)
    [x,y]=ind2sub(size(m4_temp),n);
    if m4_temp(n)>0
    text(ax4,y,x,num2str( abs(round(m4_temp(n)*10)/10)),"FontSize",y_mult*6,"Color",'k','HorizontalAlignment', 'center')
    else
    text(ax4,y,x,num2str( abs(round(m4_temp(n)*10)/10)),"FontSize",y_mult*6,"Color",'w','HorizontalAlignment', 'center')
    end
 
end %for n=1:numel(m4_temp)

ax4.Title.String = 'HFN(black# +ve white# -ve)';

ax1.XTickLabelRotation = 0;
ax2.XTickLabelRotation = 0;
ax3.XTickLabelRotation = 0;
ax4.XTickLabelRotation = 0;

p1.Title = ['Maps : ' remove_(file_name),'.'];
p1.BorderColor  = [0.9400 0.9400 0.9400];
p1.TitlePosition ='centertop';
p1.FontSize = 14* y_mult;
p1.FontWeight = 'bold';

end %plot_colourmaps(RMS_mat,SNR_mat_DB,LFN_mat_DB,HFN_mat_DB)

function [samp_freq,freq_axis_KHz,fft_d_temp,fft_n_temp,RMS_mat,SNR_mat_DB,LFN_mat_DB,HFN_mat_DB]  =  calculate_mat_properties(time_,ALL_time_d,time_d,exitation_freq_kHz,SNR_bandwidth_kHz,All_noise_d,noise_d)

samp_freq  = 1/(time_(2)- time_(1));
temp_f = [1:length(time_)]/length(time_)*samp_freq/1000 ;


freq_axis_KHz = temp_f(1:floor(length(temp_f)/2));

tem_f_d = abs(fft(time_d));
fft_d_temp = tem_f_d(1: floor(length(tem_f_d)/2),:,:);




if length(noise_d) ~=0
tem_n_d = abs(fft(noise_d));  
fft_n_temp = tem_n_d(1: floor(length(tem_n_d)/2),:);
use_base_noise = 1;
else
fft_n_temp = [];
use_base_noise = 0;
end

SNR_mat_DB  =  zeros(size((fft_d_temp),2),size((fft_d_temp),3));


% Get the noise ------------------------------- 

% prob use 


%rms_square_response_tmp    =  squeeze(sqrt(mean((time_d(:,:,:)).^2)));
%RMS_mat =   rms_square_response_tmp -diag(diag(rms_square_response_tmp));

%keyboard


for index_a = 1:size((fft_d_temp),2)
for index_b = 1:size((fft_d_temp),3)
current_fft_tmp =  fft_d_temp(: ,index_a,index_b);


sig_tmp = sum(current_fft_tmp(find(freq_axis_KHz< (exitation_freq_kHz +SNR_bandwidth_kHz)  & freq_axis_KHz> (exitation_freq_kHz -SNR_bandwidth_kHz))));

if use_base_noise ==1
current_fft_n_tmp =  fft_n_temp(:,index_a);
noise_tmp = sum(current_fft_n_tmp(find(freq_axis_KHz< (exitation_freq_kHz +SNR_bandwidth_kHz)  & freq_axis_KHz> (exitation_freq_kHz -SNR_bandwidth_kHz))));
else
noise_tmp = sum(current_fft_tmp((find(freq_axis_KHz> (exitation_freq_kHz +SNR_bandwidth_kHz) | freq_axis_KHz < (exitation_freq_kHz -SNR_bandwidth_kHz)))));
end

%LFN
Low_freq_temp     = sum(current_fft_tmp(find(freq_axis_KHz< (exitation_freq_kHz -SNR_bandwidth_kHz))));
not_Low_freq_temp = sum(current_fft_tmp(find(freq_axis_KHz> (exitation_freq_kHz -SNR_bandwidth_kHz))));

%HFN
High_freq_temp     = sum(current_fft_tmp(find(freq_axis_KHz> (exitation_freq_kHz +SNR_bandwidth_kHz))));
not_High_freq_temp = sum(current_fft_tmp(find(freq_axis_KHz< (exitation_freq_kHz +SNR_bandwidth_kHz)))); 

RMS_mat_LIN(index_a,index_b) = sig_tmp;
SNR_mat_DB(index_a,index_b) =  20*log10(sig_tmp /noise_tmp);

LFN_mat_DB(index_a,index_b) =  20*log10(Low_freq_temp/not_Low_freq_temp);
HFN_mat_DB(index_a,index_b) =  20*log10(High_freq_temp/not_High_freq_temp);

end % for index_b = 1:size((fft_d_temp),3)
end % for index_a = 1:size((fft_d_temp),2)

RMS_mat =  RMS_mat_LIN ;
RMS_mat (eye(size(RMS_mat ))==1)=0;
RMS_mat = RMS_mat/mean(mean(RMS_mat));

end %function [samp_freq,freq_axis_KHz,fft_d_temp,RMS_mat,SNR_mat_DB,LFN_mat_DB,HFN_mat_DB]  =  calculate_mat_properties(time_,ALL_time_d,time_d,exitation_freq_kHz,SNR_bandwidth_kHz);

function do_plots =  choose_plots_to_show(plot_list)
[ones_,~] = listdlg('ListString',plot_list);
do_plots(ones_) = 1;
end %function do_plots =  choose_plots_to_show(plot_list);


function [ALL_time_d,time_d,ALL_time,time_,All_noise_d,noise_d ] =  load_the_data_from_structure(test_data,time_gate,time_gate2)

ALL_time_d   =   test_data.raw_data.time_data             ; 
time_d       =  ALL_time_d(time_gate:time_gate2,:,:)      ;
ALL_time     = test_data.raw_data.time                    ;
time_        = ALL_time(time_gate:time_gate2)             ;

if isfield(test_data.raw_data,'noise_data')
All_noise_d  =  test_data.raw_data.noise_data             ;
noise_d      =  test_data.raw_data.noise_data(time_gate:time_gate2,:);
else
All_noise_d  = [];
noise_d      = [];
end %if isfield(test_data.raw_data,'noise_data')



end %function [ALL_time_d,time_d,ALL_time,time_ ]     =  load_the_data_from_structure(test_data,time_gate) ;  



function [ALL_time_d,time_d,ALL_time,time_,All_noise_d,noise_d ]  = load_the_data_from_file(file_path_,file_name,time_gate,time_gate2) 

dummy =  load([file_path_,file_name]);
ALL_time_d   =   dummy.test_data.raw_data.time_data   ; 
time_d     =  ALL_time_d(time_gate:time_gate2,:,:)           ;

ALL_time   = dummy.test_data.raw_data.time            ;
time_      = ALL_time(time_gate:time_gate2)                  ;

if isfield(test_data.raw_data,'noise_data')
All_noise_d  =  test_data.raw_data.noise_data             ;
noise_d      =  test_data.raw_data.noise_data(time_gate:time_gate2,:);
else
All_noise_d  =    [];
noise_d      =    [];
end %if isfield(test_data.raw_data,'noise_data')

end %function [ALL_time_d,time_d,ALL_time,time_ ]  = load_the_data_from_file(file_path_,file_name) 


function  name_ = remove_(name_)
name_(find(name_=='_'))= ' ';
end






