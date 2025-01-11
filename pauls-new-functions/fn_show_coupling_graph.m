function fn_show_coupling_graph(raw_data, array, options)
ang_pts = 90;
% trans_amp=zeros(max([raw_data.tx_row;raw_data.rx_row]), max([raw_data.tx_pos;raw_data.rx_pos]));
trans_amp = zeros(max(array.trans_row), max(array.trans_pos));
freq_step = abs(raw_data.freq(2) - raw_data.freq(1));
freq_start_count = round((options.freq_filter - options.freq_filter_bandwidth) / freq_step);
freq_end_count = round((options.freq_filter + options.freq_filter_bandwidth) / freq_step);
for count=1:size(raw_data.freq_data, 2)
%     trans_amp(raw_data.tx_row(count),raw_data.tx_pos(count))=trans_amp(raw_data.tx_row(count),raw_data.tx_pos(count))+sum(abs(raw_data.freq_data(freq_start_count:freq_end_count,count)));
%     trans_amp(raw_data.rx_row(count),raw_data.rx_pos(count))=trans_amp(raw_data.rx_row(count),raw_data.rx_pos(count))+sum(abs(raw_data.freq_data(freq_start_count:freq_end_count,count)));
    trans_amp(array.trans_row(raw_data.tx(count)), array.trans_pos(raw_data.tx(count))) = ...
        trans_amp(array.trans_row(raw_data.tx(count)), array.trans_pos(raw_data.tx(count))) + ...
        sum(abs(raw_data.freq_data(freq_start_count:freq_end_count, count)));
    trans_amp(array.trans_row(raw_data.rx(count)), array.trans_pos(raw_data.rx(count))) = ...
        trans_amp(array.trans_row(raw_data.rx(count)), array.trans_pos(raw_data.rx(count))) + ...
        sum(abs(raw_data.freq_data(freq_start_count:freq_end_count, count)));
end
figure;
hold on;
trans_amp=trans_amp/max(max(abs(trans_amp)));
ang = linspace(0, 2*pi, ang_pts + 1);
for r_count=1:size(trans_amp,1)
    for c_count=1:size(trans_amp,2)
        amp=trans_amp(r_count,c_count)/2;
        temp = c_count+i*r_count + amp * exp(i * ang);
        patch(real(temp), imag(temp), 'r');
    end
end

row_min = min(find(any(trans_amp'))) - 1;
row_max = max(find(any(trans_amp'))) + 1;
pos_min = min(find(any(trans_amp))) - 1;
pos_max = max(find(any(trans_amp))) + 1;

xlabel('Position');
ylabel('Row');
title('Transducer signal amplitude before compensation');
axis([pos_min, pos_max, row_min, row_max]);
xticks(pos_min+1:pos_max-1);
yticks(row_min+1:row_max-1);
axis equal;
return;