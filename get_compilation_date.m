function compilation_date_str  = get_compilation_date()

if exist('WPA_V2.exe','file') ==2
d = dir('WPA_V2.exe');
compilation_date_str = [', Compiled ',d.date,'.'];
elseif exist([pwd,'\WinAPP\WPA_V2.m'],'file') ==2 
d = dir( [pwd,'\WinAPP\WPA_V2.m']);
compilation_date_str = [', Uncompiled ',d.date,'.'];
else
compilation_date_str = ', Unknown compilation status';
% should not happen
end %if exist('WPA_V2.exe') ==2

end %function compilation_date_str  = get_compilation_date()
