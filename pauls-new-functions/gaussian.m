function window = gaussian(number_of_points, peak_pos_fract, half_width_fract, varargin);
%gaussian(number_of_points, peak_pos_fract, half_width_fract, db_down)
%
%creates a gaussian vector with number_of_points elements
%the peak at the point in the vector specified by peak_pos_fract (as a fraction)
%and half width specified by half_width_fract,
%where db_down (defaults to 40) specifies the number of dB below the peak value at the half width point
%USAGE
%	window = gaussian(number_of_points, peak_pos_fract, half_width_fract, db_down, force_zero)
%AUTHOR
%	Paul Wilcox (2003)
%SUMMARY
%	Creates a Gaussian window
%OUTPUTS
%	window - the generated window function, with amplitude ranging from 0 to 1
%INPUTS
%	number_of_points - how many points are in the window vector
%	peak_pos_fract - whereabouts the peak of the window is as a fraction
%	of the total length of the window vector
%	half_width_fract - how wide the halfwidth of the window is as a fraction of
%	the total length of the window vector
%	(db_down) - number of dB below peak of window used to define the width.
%	Default is 40.
%	(force_zero) - if true, points in window outside defined width are
%	set to zero. Default is false.
%NOTES
%	output is a column vector
%	The function forces window outside half width fraction to be zero

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
default_db_down = 40;
default_force_zero = 0;
if nargin < 4;
   db_down = default_db_down;
else
   db_down = varargin{1};
end;
if nargin < 5;
   force_zero = default_force_zero;
else
   force_zero = varargin{2};
end;

fract = 10.0 ^ (-db_down / 20.0);
r = (linspace(0, 1, number_of_points) - peak_pos_fract)';
r1 = half_width_fract / ((-log(fract)) ^ 0.5);
window = exp(-(r / r1) .^ 2);
if force_zero
	window(find(window < fract)) = 0.0;
end;

return;