x_gama1 = 10:5:350;
y_gama2 = 10:10:700;
[X,Y] = meshgrid(x_gama1,y_gama2);
Z1 = data1_Arr(:,2:70);
Z2 = data2_Arr(:,2:70);

figure(1);
mesh(X,Y,Z1);
xlabel('gama1'),ylabel('gama2'),zlabel('收敛时间')

figure(2);
mesh(X,Y,Z2);
xlabel('gama1'),ylabel('gama2'),zlabel('收敛后的偏差')