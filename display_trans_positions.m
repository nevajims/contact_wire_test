function  display_trans_positions(varargin)

switch (nargin)
    case(1)    
TS2 = varargin{1};
tit_text = '';
Pix_SS = get(0,'screensize')              ;
x_mult = (Pix_SS(3)/1920)   ;
y_mult = (Pix_SS(4)/1080 )  ;
mag_fac   =   1;
    
    case(5)
TS2      = varargin{1};
tit_text = varargin{2};
base_width = varargin{3};
base_height = varargin{4};
mag_fac   = varargin{5};

Pix_SS = get(0,'screensize')                ;
x_mult = (Pix_SS(3)/base_width)   * mag_fac ;
y_mult = (Pix_SS(4)/base_height)  * mag_fac ;
end %switch (nargin)

locations_choices = {'top','right','bottom','left'};
orientation_choices = {'X','Y','Z'};


if isnan(TS2.Instrument_attributes.trans_pos_orientation)
TPO_temp   =  TS2.Instrument_attributes.trans_pos_orientation_values{TS2.Instrument_attributes.trans_pos_orientation_choice}  ;
txt_insert = ['(',TS2.Instrument_attributes.trans_pos_orientation_labels{TS2.Instrument_attributes.trans_pos_orientation_choice},')'];
else
TPO_temp =TS2.Instrument_attributes.trans_pos_orientation;
txt_insert = '';
end %if isnan(Instrument_attributes.trans_pos_orientation)


for index_ = 1:length(TS2.Instrument_attributes.trans_row)
name_{index_} = ['Transducer ',num2str(index_)]  ;
row_(index_)  = TS2.Instrument_attributes.trans_row(index_);                            
locations_{index_} = locations_choices{TS2.Instrument_attributes.trans_pos(index_)};

X{index_} = num2str(TPO_temp(index_,1));
Y{index_} = num2str(TPO_temp(index_,2));
Z{index_} = num2str(TPO_temp(index_,3));

%{
orientation_{index_} = orientation_choices{find(dum_==1)};
switch(sum(TS2.Instrument_attributes.trans_pos_orientation(index_,:)))
    case(1)
direction_{index_}   =  '+ve';
    case(-1)
direction_{index_}   =  '-ve';
end
%}
end %for index = 1:length(TS2.Instrument_attributes.trans_row)

%trans_tab = table(categorical(name_'),categorical(row_'),categorical(locations_'),...
%categorical(X'),categorical(Y'),categorical(Z'),'VariableNames',{'#','T Row','Location','X','Y','Z'});

trans_tab = table(name_',row_',locations_',...
X',Y',Z','VariableNames',{'#','ROW','LOCATION','X','Y','Z'});

Cell_tab = [trans_tab.Properties.VariableNames; table2cell(trans_tab)];

fig = uifigure('Resize','on','Units','normalized','Position',[0.1,0.1,0.32*mag_fac,0.24*mag_fac],'Name', ['Transducer Information >',tit_text,' ' ,txt_insert]);
fig.Icon = 'ICON2.png' ;

%uit = uitable(fig,'Data',trans_tab,'Position',[x_mult*20,y_mult*20,x_mult*600,y_mult*308]);
%uit.FontSize = 12 * y_mult;

uitCell = uitable(fig,'data',Cell_tab,'ColumnName',{},'RowName',{},'Position',[x_mult*10,y_mult*5,x_mult*600,y_mult*233.5]);
%'Name', ['Transducer Information (',tit_text,')']

uitCell.FontSize = 11 * y_mult;
uitCell.BackgroundColor = flipud(uitCell.BackgroundColor);

uisCenter = uistyle('HorizontalAlignment','center')  ;
uisBold = uistyle('FontWeight','bold');
addStyle(uitCell , uisCenter)         ;
addStyle(uitCell, uisBold, 'row',1)

end %function display_trans_positions(TS2)