global gama1 gama2 ke
bd = 300;
kd = 1000;
ke = 1000;
ke_0 = 500;


f = @int;
M = 20;
data_f = zeros(M,2);
for j = 1:M
    j
    ke = 1000+M*100;
    dimension = 2; n = 40; m = 35; xmax = 500; xmin = 0; vmax = 30; vmin = -30;
    [Pg,fmin] = PSO(f,dimension,n,m,xmax,xmin,vmax,vmin)
    data_f(j,:) = Pg;
end