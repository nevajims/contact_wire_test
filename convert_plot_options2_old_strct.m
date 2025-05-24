function old_  = convert_plot_options2_old_strct(new_ )

old_.Data_path_choice   = new_.Data_path_choice;
old_.Data_path_options  = new_.Data_path_options;

switch(new_.mode_pairs_to_Use_options{new_.mode_pairs_to_Use})
    case('2_5_8_14')
temp_ = [2,5,8,14]; 
    case('8_14')
temp_ = [8,14];
    case('ALL')
temp_ = 1:16;
end        

old_.mode_pairs_to_Use  = temp_;
old_.NumNeighbors       = new_.NumNeighbors_options(new_.NumNeighbors);
old_.num_slices         = new_.num_slices_options(new_.num_slices_index);
old_.thresh_val         = new_.thresh_val_options(new_.thresh_val_index);
old_.initial_thresh     = new_.initial_thresh_options(new_.initial_thresh_index);
old_.window_start       = new_.window_start_options(new_.window_start_index);
old_.db_range           = new_.db_range;
old_.MM_interp_res      = new_.MM_interp_res;

switch(new_.AI_pred_options{new_.AI_pred_choice})
    case('Use_AI')
        val_1 = 1;
    case('Omit')   
        val_1 = 0;
end
switch(new_.DM_pred_options{new_.DM_pred_choice})
    case('Use_DM')
        val_2 = 1;
    case('Omit')   
        val_2 = 0;
end
switch(new_.LL_pred_options{new_.LL_pred_choice})
    case('Use_LL')
        val_3 = 1;
    case('Omit')   
        val_3 = 0;
end
old_.predictions2use    = [val_1,val_2,val_3];

old_.showdispersion     = new_.showdispersion;
old_.norm_to_what       = new_.norm_to_what;
old_.modes              = new_.modes;
old_.dist_tol           = new_.dist_tol;
old_.interp_or_val      = new_.interp_or_val;

end %function old_  = convert_plot_options2_old_strct(new_ )