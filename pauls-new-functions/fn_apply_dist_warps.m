function proc_data_out = fn_apply_dist_warps(proc_data_in, suppress_display)
tic;

proc_data_out = fn_calc_warp_factors(proc_data_in, suppress_display);

for ii = 1:size(proc_data_out.dist_data, 2)
    old_dist = proc_data_out.dist / proc_data_out.current_warps(ii);
    proc_data_out.dist_data(:, ii) = interp1(old_dist, proc_data_out.dist_data(:, ii), proc_data_out.dist, 'linear', 0);
end;

if ~suppress_display
	disp(['Applied distance warps: ',num2str(toc)]);
end;
return;