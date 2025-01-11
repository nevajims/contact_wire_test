function raw_data = fn_coupling_comp(raw_data, array, options);
tic;

if options.show_coupling_graph
    fn_show_coupling_graph(raw_data, array, options);
end

% max_row = max([raw_data.tx_row; raw_data.rx_row]);
% max_pos = max([raw_data.tx_pos; raw_data.rx_pos]);
max_row = max(array.trans_row);
max_pos = max(array.trans_pos);
% trans_amp=zeros(max_row, max_pos);
max_trans_index = max([raw_data.tx(:); raw_data.rx(:)]);
trans_amp=zeros(max_trans_index, 1);

freq_step = abs(raw_data.freq(2) - raw_data.freq(1));
freq_start_count = round((options.freq_filter - options.freq_filter_bandwidth) / freq_step);
freq_end_count = round((options.freq_filter + options.freq_filter_bandwidth) / freq_step);

if options.raw_data_coupling_comp == 1
    for count=1:size(raw_data.freq_data, 2)
        raw_data.freq_data(:,count) = raw_data.freq_data(:,count) / sum(abs(raw_data.freq_data(freq_start_count:freq_end_count,count)));
    end
end

if options.raw_data_coupling_comp == 2
    ideal_amplitude=ones(size(trans_amp));%change this later to suit energy distribution in all modes of interest
    trans_weight=ones(size(trans_amp));
    amplitude=sum(abs(raw_data.freq_data(freq_start_count:freq_end_count,:)));
    amplitude=amplitude/mean(amplitude);
    for i_count=1:10
        trans_amp=zeros(size(trans_amp));
        for count=1:size(raw_data.freq_data, 2)
%             trans_amp(raw_data.tx_row(count),raw_data.tx_pos(count))=trans_amp(raw_data.tx_row(count),raw_data.tx_pos(count)) + ...
%                 amplitude(count)*trans_weight(raw_data.tx_row(count),raw_data.tx_pos(count))*trans_weight(raw_data.rx_row(count),raw_data.rx_pos(count));
%             trans_amp(raw_data.rx_row(count),raw_data.rx_pos(count))=trans_amp(raw_data.rx_row(count),raw_data.rx_pos(count)) + ...
%                 amplitude(count)*trans_weight(raw_data.tx_row(count),raw_data.tx_pos(count))*trans_weight(raw_data.rx_row(count),raw_data.rx_pos(count));
            trans_amp(raw_data.tx(count))=trans_amp(raw_data.tx(count)) + ...
                amplitude(count)*trans_weight(raw_data.tx(count))*trans_weight(raw_data.rx(count));
            trans_amp(raw_data.rx(count))=trans_amp(raw_data.rx(count)) + ...
                amplitude(count)*trans_weight(raw_data.tx(count))*trans_weight(raw_data.rx(count));
        end
        trans_amp(find(trans_amp==0)) = 1; %avoid divide by zero errors where there are no transducers
        trans_weight=trans_weight .* (ideal_amplitude ./ trans_amp) .^ 0.5;
    end
    for count=1:size(raw_data.freq_data, 2)
%         raw_data.freq_data(:,count)=raw_data.freq_data(:,count)*trans_weight(raw_data.tx_row(count),raw_data.tx_pos(count))*trans_weight(raw_data.rx_row(count),raw_data.rx_pos(count));
        raw_data.freq_data(:,count)=raw_data.freq_data(:,count) * trans_weight(raw_data.tx(count)) * trans_weight(raw_data.rx(count));
    end
end

if ~options.suppress_display
	disp(['Coupling compensation applied: ',num2str(toc)]);
end
return