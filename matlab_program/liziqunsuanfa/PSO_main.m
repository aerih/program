global gama1 gama2 ke P I D
bd = 500;
kd = 1000;
ke = 1000;
ke_0 = 500;
P = 1;
I = 1;
D = 1;

f = @int;
M = 20;
data_f = zeros(M,5);
for j = 1:M
    j
    ke = 1000+M*100;
    dimension = 5; n = 30; m = 40; xmax = 600; xmin = 5; vmax = 30; vmin = -30;
    [Pg,fmin] = PSO(f,dimension,n,m,xmax,xmin,vmax,vmin)
    data_f(j,:) = Pg;
end