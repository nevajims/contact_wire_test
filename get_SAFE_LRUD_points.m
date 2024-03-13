
function [SAFE_LRUD]  =  get_SAFE_LRUD_points(reshaped_proc_data,show_mesh) 


[min_x_val ,~] =      min(reshaped_proc_data.mesh.nd.pos(:,1)) ;
[max_x_val ,~] =      max(reshaped_proc_data.mesh.nd.pos(:,1)) ;
[min_y_val ,~] =      min(reshaped_proc_data.mesh.nd.pos(:,2)) ;
[max_y_val ,~] =      max(reshaped_proc_data.mesh.nd.pos(:,2)) ;

L_ideal_point = [min_x_val,0];
R_ideal_point = [max_x_val,0];
U_ideal_point = [0,max_y_val];
D_ideal_point = [0,min_y_val];
          
[L_dist_to_ideal,L_node ] =  min((((reshaped_proc_data.mesh.nd.pos(:,1))- L_ideal_point(1)).^2 + (reshaped_proc_data.mesh.nd.pos(:,2)- L_ideal_point(2)).^2).^0.5);
[R_dist_to_ideal,R_node ] =  min((((reshaped_proc_data.mesh.nd.pos(:,1))- R_ideal_point(1)).^2 + (reshaped_proc_data.mesh.nd.pos(:,2)- R_ideal_point(2)).^2).^0.5);
[U_dist_to_ideal,U_node ] =  min((((reshaped_proc_data.mesh.nd.pos(:,1))- U_ideal_point(1)).^2 + (reshaped_proc_data.mesh.nd.pos(:,2)- U_ideal_point(2)).^2).^0.5);
[D_dist_to_ideal,D_node ] =  min((((reshaped_proc_data.mesh.nd.pos(:,1))- D_ideal_point(1)).^2 + (reshaped_proc_data.mesh.nd.pos(:,2)- D_ideal_point(2)).^2).^0.5);

SAFE_LRUD         =  [L_node,R_node,U_node,D_node]  ; 
disp(['L node, R node, U node, D node (nos in the hist file)   =  '  ,   num2str(L_node),', ', num2str(R_node),', ',num2str(U_node),', ',num2str(D_node)'.'])  

if show_mesh    == 1
figure
fv.Vertices   = reshaped_proc_data.mesh.nd.pos;
fv.Faces      = reshaped_proc_data.mesh.el.nds ;
patch(fv, 'FaceColor', 'c');
axis equal;
axis off;
hold on
plot([min_x_val*1.2,max_x_val*1.2],[0,0])
plot([0,0],[min_y_val*1.2,max_y_val*1.2])

plot(reshaped_proc_data.mesh.nd.pos(L_node,1) , reshaped_proc_data.mesh.nd.pos(L_node,2),'ro','markersize',20)
plot(reshaped_proc_data.mesh.nd.pos(R_node,1) , reshaped_proc_data.mesh.nd.pos(R_node,2),'ro','markersize',20)
plot(reshaped_proc_data.mesh.nd.pos(U_node,1) , reshaped_proc_data.mesh.nd.pos(U_node,2),'ro','markersize',20)
plot(reshaped_proc_data.mesh.nd.pos(D_node,1) , reshaped_proc_data.mesh.nd.pos(D_node,2),'ro','markersize',20)

plot (L_ideal_point(1),L_ideal_point(2),'kx','markersize',20)
plot (R_ideal_point(1),R_ideal_point(2),'kx','markersize',20)
plot (U_ideal_point(1),U_ideal_point(2),'kx','markersize',20)
plot (D_ideal_point(1),D_ideal_point(2),'kx','markersize',20)

end % if show_mesh    == 1
disp(['Left node: ',  num2str(L_node),'(',num2str(L_dist_to_ideal*1000),'mm, SAFE_node: ',num2str(L_node),')'])
disp(['Right node:',  num2str(R_node),'(',num2str(R_dist_to_ideal*1000),'mm, SAFE_node: ',num2str(R_node),')'])
disp(['Up node:   ',  num2str(U_node),'(',num2str(U_dist_to_ideal*1000),'mm, SAFE_node: ',num2str(U_node),')'])
disp(['Down node: ',  num2str(D_node),'(',num2str(D_dist_to_ideal*1000),'mm, SAFE_node: ',num2str(D_node),')'])


end  %function [SAFE_LRUD]  =  get_SAFE_LRUD_points(reshaped_proc_data,show_mesh) 