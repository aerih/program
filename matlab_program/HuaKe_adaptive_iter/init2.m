clear
gama1 = 20;
gama2 = 100;
bd = 800;
kd = 3000;
t = zeros(1000,1);
error = zeros(1000,1);
deta_f = zeros(1000,1);

M=20;
for i=1:1:M    % Start Learning Control
i
sim('baseon_xr_iter',[0,1]);
gama1 = gama1+30

figure(1);plot(fm.time,fm.data,'r');
xlabel('time(s)');ylabel('fm/N');

hold on;


pause(0.01);

end