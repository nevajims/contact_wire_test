% PDW3_SCRIPT   Generate dynamic library fn_process_rail_data_DLL from
% fn_process_rail_data_DLL.
% 
% Script generated from project 'pdw3.coderprj' on 12-Mar-2026.
% 
% See also CODER, CODER.CONFIG, CODER.TYPEOF, CODEGEN.

%% Create configuration object of class 'coder.EmbeddedCodeConfig'.
cfg = coder.config("dll", "ecoder", true);
cfg.GenCodeOnly = false;
%% Define argument types for entry-point 'fn_process_rail_data_DLL'.
inputTypes = cell(1, 1);
inputTypes{1} = cell(10, 1);
inputTypes{1}{1} = coder.newtype("double", [Inf 1], [1 0]);
inputTypes{1}{2} = coder.newtype("double", [Inf Inf], [1 1]);
inputTypes{1}{3} = coder.newtype("double", [Inf 1], [1 0]);
inputTypes{1}{4} = coder.newtype("double", [Inf 1], [1 0]);
inputTypes{1}{5} = coder.newtype("double", [1 Inf], [0 1]);
inputTypes{1}{6} = coder.newtype("double", [1 Inf], [0 1]);
inputTypes{1}{7} = coder.newtype("double", [1 Inf], [0 1]);
inputTypes{1}{8} = coder.newtype("double", [Inf Inf], [1 1]);
inputTypes{1}{9} = coder.newtype("double", [1 1], [0 0]);
inputTypes{1}{10} = coder.newtype("double", [1 Inf], [0 1]);

%% Invoke MATLAB Coder.
codegen -config cfg fn_process_rail_data_DLL -args inputTypes{1}