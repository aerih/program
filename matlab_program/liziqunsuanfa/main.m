global gama1 gama2
gama1 = 10;
gama2 = 10;
% bd = 350;
% kd = 1000;
% ke = 505;
% ke_0 = 500;
f = @int;
[Pg,fmin]=PSO(f,2,50,50,0,500,0,500)