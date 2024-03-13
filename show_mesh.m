function show_mesh(rail_tester)

trans_node_list    = rail_tester.array.trans_node_list;
mesh_              = rail_tester.mesh; 

figure;

%keyboard

patch('Faces',mesh_.el.nds,'Vertices',mesh_.nd.pos, 'FaceColor', 'c'); axis equal;
hold on;
title(rail_tester.fe_fname)
plot(mesh_.nd.pos(trans_node_list(1),1), mesh_.nd.pos(trans_node_list(1),2), 'go', 'MarkerFaceColor','g','MarkerSize',10);
plot(mesh_.nd.pos(trans_node_list(2),1), mesh_.nd.pos(trans_node_list(2),2), 'bo', 'MarkerFaceColor','b','MarkerSize',10);
plot(mesh_.nd.pos(trans_node_list(3),1), mesh_.nd.pos(trans_node_list(3),2), 'yo', 'MarkerFaceColor','y','MarkerSize',10);
plot(mesh_.nd.pos(trans_node_list(4),1), mesh_.nd.pos(trans_node_list(4),2), 'ro', 'MarkerFaceColor','r','MarkerSize',10);

legend('Mesh','T1','T2','T3','T4')


end % function  show_mesh()