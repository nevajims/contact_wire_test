function proc_data_out = fn_calc_warp_factors(proc_data_in, suppress_display);
tic;

proc_data_out = proc_data_in;
u1 = proc_data_out.modal_vgrs(proc_data_out.tx_mode(:));
u2 = proc_data_out.modal_vgrs(proc_data_out.rx_mode(:));
v1 = proc_data_out.modal_vgrs(proc_data_out.tx_mode(:)) .* proc_data_out.modal_warps(proc_data_out.tx_mode(:));
v2 = proc_data_out.modal_vgrs(proc_data_out.rx_mode(:)) .* proc_data_out.modal_warps(proc_data_out.rx_mode(:));
proc_data_out.current_warps = proc_data_out.current_warps(:).' .* (1 ./ u1 + 1 ./ u2) ./ (1 ./ v1 + 1 ./ v2);

if ~suppress_display
	disp(['Calculated warp factors for each trace: ',num2str(toc)]);
end;
return;