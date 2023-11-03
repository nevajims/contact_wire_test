function showdispersion(plot_options,rail_tester)

if plot_options.showdispersion %plot dispersion curves for referencerail_tester.raw_data.tx = rail_tester.raw_data.tx(:); 
rail_tester.raw_data.rx = rail_tester.raw_data.rx(:);

    figure; 
    for i = 1:length(rail_tester.disperse.mode)
%disp(num2str(i))        
        plot(rail_tester.disperse.mode(i).freq / 1e3,rail_tester.disperse.mode(i).vph);
        temp_(i)= max(rail_tester.disperse.mode(i).freq); %find the limit of the frequency range
        legend_text{i} = sprintf('%s',rail_tester.disperse.mode(i).name); 
        hold on; 
    end
    ylim([0,5e3]); xlabel('Frequency (kHz)'); ylabel('Phase velocity (m/s)');
    xlim([0,min(temp_)/1e3]);
    legend(legend_text);
end % if plot_options.showdispersion %plot dispersion curves for reference

end %  function   showdispersion
