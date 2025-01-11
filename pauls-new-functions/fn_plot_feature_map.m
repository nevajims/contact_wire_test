function data = fn_plot_feature_map(rail_tester, distance, options)
%------------------------------------------------------------------------------   
%add to plot options file :: 
% 2 new functions to replace this:::    seperate the (1)processing and the (2)plotting-  process every point in
% the range rather than just a single one
%------------------------------------------------------------------------------   
%------------------------------------------------------------------------------  
default_options = get_default_options();  %  function defined below
options = set_default_fields(options, default_options);

if ~isfield(rail_tester, 'proc_data')
    disp('No processed data available!');
    return ; % abandon at this point
end %if ~isfield(rail_tester, 'proc_data')


figure
[tx_mode, rx_mode] = meshgrid(options.modes, options.modes);
data = zeros(size(tx_mode));

if distance > 0
    dir = 1;
else
    dir = -1;
end %if distance > 0

dist_tol_m = (2*abs(distance) * (options.dist_tol/100)) ;
for ii = 1:length(tx_mode(:))
    jj = find((rail_tester.proc_data.tx_mode == tx_mode(ii)) ...
        & (rail_tester.proc_data.rx_mode == rx_mode(ii)) ...
        & (rail_tester.proc_data.tx_dir == dir) ...
        & (rail_tester.proc_data.rx_dir == dir));
    if ~isempty(jj)
        if dist_tol_m <= 0
            data(ii) = interp1(rail_tester.proc_data.dist, abs(rail_tester.proc_data.dist_data(:, jj)), abs(distance), 'linear');
        else
            i1 = min(find(rail_tester.proc_data.dist > abs(distance) - dist_tol_m / 2))   ;
            i2 = max(find(rail_tester.proc_data.dist < abs(distance) + dist_tol_m / 2))   ;
            data(ii) = max(abs(rail_tester.proc_data.dist_data(i1:i2, jj)));
                switch (options.max_or_mean)
                case(1)            
                data(ii) = max(abs(rail_tester.proc_data.dist_data(i1:i2,jj)));
                case(2)            
                data(ii) = mean(abs(rail_tester.proc_data.dist_data(i1:i2,jj)));
                end %switch (options.max_or_mean)
        end %if dist_tol_m <= 0
    end %if ~isempty(jj)
end %for ii = 1:length(tx_mode(:))

if options.norm_to_what == 1
    data = data / max(max(abs(data)));
else
    data = data / max(max(abs(rail_tester.proc_data.dist_data)));
end
 
data = 20 * log10(data) + options.db_range;
data(find(data < 0)) = 0;
data(find(isnan(data) | isinf(data))) = 0;


if options.grid_size > length(options.modes)
    x = linspace(1,length(options.modes),options.grid_size);
    y = linspace(1,length(options.modes),options.grid_size);
    [xi, yi] = meshgrid(x, y);
    interp_data = interp2([1:length(options.modes)],[1:length(options.modes)],data,xi,yi);
else
    interp_data = data;
end
interp_data = [interp_data; zeros(1, size(interp_data, 2))];
interp_data = [interp_data, zeros(size(interp_data,1), 1)];

colormap default;
surf(interp_data);
view(2);
axis equal;
shading flat;
axis off;
caxis([0, options.db_range]);
colorbar;
%add title
titletext = ['Distance: ',num2str(distance),'m',', (+/- ',num2str(options.dist_tol/2),'%).'];
title(titletext);

%add mode labels
if options.grid_size > length(options.modes)
    sf = options.grid_size / length(options.modes);
    offset = options.grid_size / 50;
else
    sf = 1;
    offset = length(options.modes) / 50;
end

for ii = 1:length(options.modes)
    a = text((ii - 0.5) * sf + 1, - offset + 1, sprintf('%i', options.modes(ii)));
    set(a, 'HorizontalAlignment', 'center');
    set(a, 'VerticalAlignment', 'top');
    a = text(-offset + 1, (ii - 0.5) * sf + 1, sprintf('%i', options.modes(ii)));
    set(a, 'HorizontalAlignment', 'right');
    set(a, 'VerticalAlignment', 'middle');
end

end

function  default_options = get_default_options()
default_options.norm_to_what = 1   ;  % 1 - normalised to maximum in map, 2 = normalised to maximum in data
default_options.db_range = 30      ; 
default_options.dist_tol = 0       ;  % distance tolerance band around nominal distance to consider set to zero for exact interpolation
default_options.grid_size = 50     ;
default_options.modes = [1,2,3,4]  ;
end %function  default_options = get_default_options()



