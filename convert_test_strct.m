function [old_TS_struct] = convert_test_strct(new_struct_) 
% ------------------------------------------------------
old_TS_struct.Sampling.Sample_RateHz  = new_struct_.Sampling.Sample_Rate_options(new_struct_.Sampling.Sample_RateHz) ;
old_TS_struct.Sampling.Num_Samples    = new_struct_.Sampling.Num_Samples_options(new_struct_.Sampling.Num_Samples)   ;
old_TS_struct.Sampling.Start_Offset      = new_struct_.Sampling.Start_Offset                                         ;
old_TS_struct.Sampling.Num_Averages   = new_struct_.Sampling.Num_Averages_options(new_struct_.Sampling.Num_Averages) ;
old_TS_struct.Sampling.RepeatDelay_mS    = new_struct_.Sampling.RepeatDelay_mS                                       ;
old_TS_struct.Sampling.adc_Range_options = new_struct_.Sampling.adc_Range_options                                    ;
old_TS_struct.Sampling.adc_Range_        = new_struct_.Sampling.adc_Range_                                           ;
% ------------------------------------------------------
old_TS_struct.Impedence =  new_struct_.Impedence;
% ------------------------------------------------------
old_TS_struct.Toneburst.Shape_options      = new_struct_.Toneburst.Shape_options                                        ;
old_TS_struct.Toneburst.Shape              = new_struct_.Toneburst.Shape                                                ;
old_TS_struct.Toneburst.Frequency          = new_struct_.Toneburst.Frequency_options(new_struct_.Toneburst.Frequency)   ;
old_TS_struct.Toneburst.num_cycles         = new_struct_.Toneburst.num_cycles_options(new_struct_.Toneburst.num_cycles) ;
old_TS_struct.Toneburst.Phase_deg          = new_struct_.Toneburst.Phase_deg                                            ;
old_TS_struct.Toneburst.Tx_mute_samples    = new_struct_.Toneburst.Tx_mute_samples                                      ;
old_TS_struct.Toneburst.Tx_Channel         = new_struct_.Toneburst.Tx_Channel                                           ;
old_TS_struct.Toneburst.Attenuation_dB     = new_struct_.Toneburst.Attenuation_dB                                       ;
% ------------------------------------------------------
old_TS_struct.Instrument_attributes.number_of_transducers   = new_struct_.Instrument_attributes.number_of_transducers;
old_TS_struct.Instrument_attributes.trans_row               = new_struct_.Instrument_attributes.trans_row;
old_TS_struct.Instrument_attributes.trans_pos               = new_struct_.Instrument_attributes.trans_pos;
old_TS_struct.Instrument_attributes.trans_row_pos           = new_struct_.Instrument_attributes.trans_row_pos;
old_TS_struct.Instrument_attributes.trans_pos_orientation   = new_struct_.Instrument_attributes.trans_pos_orientation_values{new_struct_.Instrument_attributes.trans_pos_orientation_choice};
% ------------------------------------------------------
old_TS_struct.TIPI_LEGACY = new_struct_.TIPI_LEGACY                                                 ;
% ------------------------------------------------------
old_TS_struct.Model_data  = new_struct_.Model_data                                                  ;
% ------------------------------------------------------
end % function [old_TS_struct, new_pass_file] = convert_test_strct(new_file_) 

