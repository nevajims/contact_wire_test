function show_mesh(rail_tester)

trans_node_list    = rail_tester.array.trans_node_list;
mesh_              = rail_tester.mesh; 

Pix_SS = get(0,'screensize');
x_mult = Pix_SS(3)/1920;
y_mult = Pix_SS(4)/1080;

fig = uifigure('Resize','off','Units','normalized','Position',[0.1,0.1,0.25,0.42],'Name', 'Mesh and Transducer Locations');
fig.Icon = 'ICON2.png';
px_LH = 10; py_LH = 0; px_SZ = 490; py_SZ = 480;
ax_LH = 0; ay_LH = 0; ax_SZ = 450; ay_SZ = 450;
p1 = uipanel(fig,'Position',[x_mult*px_LH y_mult*py_LH x_mult*px_SZ y_mult*py_SZ]);

p1.BorderColor = [0.9400 0.9400 0.9400];

ax = uiaxes(p1,'Position',[x_mult*ax_LH y_mult*ay_LH x_mult*ax_SZ y_mult*ay_SZ]);


%ax.Box    = 'on' ;
%figure;
%

patch(ax,'Faces',mesh_.el.nds,'Vertices',mesh_.nd.pos, 'FaceColor', 'c');
hold(ax,'on');

dum_tit = rail_tester.fe_fname(max(find(rail_tester.fe_fname=='\'))+1:end-4);
dum_tit(find(dum_tit=='_')) = ' ';
ax.Title.String = dum_tit ; 

plot(ax,mesh_.nd.pos(trans_node_list(1),1), mesh_.nd.pos(trans_node_list(1),2), 'go', 'MarkerFaceColor','g','MarkerSize',10);
plot(ax,mesh_.nd.pos(trans_node_list(2),1), mesh_.nd.pos(trans_node_list(2),2), 'bo', 'MarkerFaceColor','b','MarkerSize',10);
plot(ax,mesh_.nd.pos(trans_node_list(3),1), mesh_.nd.pos(trans_node_list(3),2), 'yo', 'MarkerFaceColor','y','MarkerSize',10);
plot(ax,mesh_.nd.pos(trans_node_list(4),1), mesh_.nd.pos(trans_node_list(4),2), 'ro', 'MarkerFaceColor','r','MarkerSize',10);

legend(ax, {'Mesh','T1','T2','T3','T4'});
ax.Legend.FontSize = 9  * y_mult ;
ax.Visible = 'off';



end % function  show_mesh()
