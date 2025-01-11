function   check_LRUD()
% Select the file   
% Left Plot-  put the original node pos  right plot put the new node pos
% Replace  values?
% If so 
close

[file_, path_ , ok_] = uigetfile('*.mat') ;

if(ok_)

load([path_,file_])

mesh_ = reshaped_proc_data.mesh ;
trans_node_list = mesh_.LRUD_node_nos;

figure(1);
subplot(1,2,1)
patch('Faces',mesh_.el.nds,'Vertices',mesh_.nd.pos, 'FaceColor', 'c'); axis equal;
hold on;
plot(mesh_.nd.pos(trans_node_list(1),1), mesh_.nd.pos(trans_node_list(1),2), 'go', 'MarkerFaceColor','g','MarkerSize',10);
plot(mesh_.nd.pos(trans_node_list(2),1), mesh_.nd.pos(trans_node_list(2),2), 'bo', 'MarkerFaceColor','b','MarkerSize',10);
plot(mesh_.nd.pos(trans_node_list(3),1), mesh_.nd.pos(trans_node_list(3),2), 'yo', 'MarkerFaceColor','y','MarkerSize',10);
plot(mesh_.nd.pos(trans_node_list(4),1), mesh_.nd.pos(trans_node_list(4),2), 'ro', 'MarkerFaceColor','r','MarkerSize',10);
legend('mesh',['T1,',num2str(trans_node_list(1))],['T2,',num2str(trans_node_list(2))],['T3,',num2str(trans_node_list(3))],['T4,',num2str(trans_node_list(4))])
title(['Orig vals = ',num2str(trans_node_list)])

[trans_node_list_new]  =  get_SAFE_LRUD(mesh_ , 0);  

figure(1)
subplot(1,2,2)
patch('Faces',mesh_.el.nds,'Vertices',mesh_.nd.pos, 'FaceColor', 'c'); axis equal;
hold on;
plot(mesh_.nd.pos(trans_node_list_new(1),1), mesh_.nd.pos(trans_node_list_new(1),2), 'go', 'MarkerFaceColor','g','MarkerSize' , 10);
plot(mesh_.nd.pos(trans_node_list_new(2),1), mesh_.nd.pos(trans_node_list_new(2),2), 'bo', 'MarkerFaceColor','b','MarkerSize' , 10);
plot(mesh_.nd.pos(trans_node_list_new(3),1), mesh_.nd.pos(trans_node_list_new(3),2), 'yo', 'MarkerFaceColor','y','MarkerSize' , 10);
plot(mesh_.nd.pos(trans_node_list_new(4),1), mesh_.nd.pos(trans_node_list_new(4),2), 'ro', 'MarkerFaceColor','r','MarkerSize' , 10);
legend('mesh',['T1,',num2str(trans_node_list_new(1))],['T2,',num2str(trans_node_list_new(2))],['T3,',num2str(trans_node_list_new(3))],['T4,',num2str(trans_node_list_new(4))])
title(['New vals = ',num2str(trans_node_list_new)])
end %if(ok_)
% do you want to replace the values?

answer_ = questdlg( 'change the LRUD values ?' );

switch(answer_)

    case('Yes')
    reshaped_proc_data.mesh.LRUD_node_nos = trans_node_list_new;
    save ([path_,file_ ],'reshaped_proc_data') 
  % saves only the variables or fields of a structure array specified by variables.
    disp(['File Saved....',[path_,file_ ],'.'])        
    otherwise
    disp(['values not changed....',file_,'.'])        
end %switch(answer_)

end % function   check_LRUD()




