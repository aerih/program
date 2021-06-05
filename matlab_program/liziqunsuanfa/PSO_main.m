global gama1 gama2
bd = 800;
kd = 3000;
ke = 1000;
ke_0 = 500;

f = @int;
dimension = 2; n = 60; m = 50; xmax = 500; xmin = 0; vmax = 30; vmin = -30;
[Pg,fmin] = PSO(f,dimension,n,m,xmax,xmin,vmax,vmin)