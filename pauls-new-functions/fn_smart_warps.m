function proc_data_out = fn_smart_warps(proc_data_in, smart_warp_ref_mode, smart_warp_trial_range, suppress_display);
tic;

proc_data_out = proc_data_in;
ref_mode = smart_warp_ref_mode;

%identify pulse-echo modes
ii = find(proc_data_in.tx_mode == proc_data_in.rx_mode & proc_data_in.tx_dir == proc_data_in.rx_dir);
pe_modes = unique(proc_data_in.tx_mode(ii));
%check if ref mode is one of the modes!
if ~any(pe_modes == ref_mode)
    disp('No data for refence mode found - unable to do smart warp!');
    return;
end;

%determine the modes for warping
other_modes = pe_modes(find(pe_modes ~= ref_mode));

%get reference p/e signal
fwd_index = find(...
    proc_data_in.tx_mode == ref_mode & ...
    proc_data_in.rx_mode == ref_mode & ...
    proc_data_in.tx_dir == 1 & ...
    proc_data_in.rx_dir == 1 ...
    );
bwd_index = find(...
    proc_data_in.tx_mode == ref_mode & ...
    proc_data_in.rx_mode == ref_mode & ...
    proc_data_in.tx_dir == -1 & ...
    proc_data_in.rx_dir == -1 ...
    );
ref_signal = [flipud(proc_data_in.dist_data(:,bwd_index)); proc_data_in.dist_data(2:end,fwd_index)];
dist = [-flipud(proc_data_in.dist); proc_data_in.dist(2: end)];
max_dist = max(abs(dist)) * min(smart_warp_trial_range);
window = dist < max_dist;
ref_signal = ref_signal .* window;

%get other p/e signals
other_signals = zeros(length(dist), length(other_modes));
for ii = 1:length(other_modes);
    fwd_index = find(...
        proc_data_in.tx_mode == other_modes(ii) & ...
        proc_data_in.rx_mode == other_modes(ii) & ...
        proc_data_in.tx_dir == 1 & ...
        proc_data_in.rx_dir == 1 ...
        );
    bwd_index = find(...
        proc_data_in.tx_mode == other_modes(ii) & ...
        proc_data_in.rx_mode == other_modes(ii) & ...
        proc_data_in.tx_dir == -1 & ...
        proc_data_in.rx_dir == -1 ...
        );
    other_signals(:, ii) = [flipud(proc_data_in.dist_data(:,bwd_index)); proc_data_in.dist_data(2:end,fwd_index)];
end;

%for each other p/e signal, loop through each possible warp and record correlation
correlations = zeros(length(smart_warp_trial_range), size(other_signals, 2));
for ii = 1:size(other_signals, 2)
    for jj = 1:length(smart_warp_trial_range)
        u1 = proc_data_out.modal_vgrs(other_modes(ii));
        u2 = proc_data_out.modal_vgrs(other_modes(ii));
        v1 = proc_data_out.modal_vgrs(other_modes(ii)) .* smart_warp_trial_range(jj);
        v2 = proc_data_out.modal_vgrs(other_modes(ii)) .* smart_warp_trial_range(jj);
        trial_warp = (1 ./ u1 + 1 ./ u2) ./ (1 ./ v1 + 1 ./ v2);
        old_dist = dist / trial_warp;
        trial_signal = interp1(old_dist, other_signals(:, ii), dist, 'linear', 0) .* window;
        correlations(jj, ii) = dot(trial_signal, ref_signal) / sqrt(dot(trial_signal, trial_signal) * dot(ref_signal, ref_signal));
    end;
end;

if 0
    figure;
    hold on;
    for ii = 1:size(correlations, 2);
        plot(smart_warp_trial_range, correlations(:, ii));
    end;
end;

%choose best correlation and set warp factors to the appropriate values
modal_warps = ones(1, max(pe_modes));
for ii = 1:size(correlations, 2);
    [max_corr, jj] = max(correlations(:, ii));
    %could put a check on value of max_corr here to avoid warping on noisey signals?
    modal_warps(other_modes(ii)) = smart_warp_trial_range(jj);
end;
proc_data_out.modal_warps = modal_warps;

if ~suppress_display
    disp(['Calculated smart warps: ',num2str(toc)]);
    for ii = 1:length(pe_modes);
        disp(sprintf('   Mode %i: %.2f %%', pe_modes(ii), (modal_warps(pe_modes(ii)) - 1 ) * 100));
    end;
end;

return;