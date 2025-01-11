function [cfg] = GetTestCfg()
    cfg.sample_freq = 500000;
    cfg.a2d_pts = 2048;
    cfg.centre_freq = 500000;
    cfg.cycles = 6;
    cfg.trans_pos = [1 2 3 4 1 2 3 4 1 2 3 4];
    cfg.trans_row = [1 1 1 1 2 2 2 2 3 3 3 3];        
end