%S-function for continuous state equation
function [sys,x0,str,ts]=iter_learning(t,x,u,flag)
switch flag,
%Initialization
  case 0,
    [sys,x0,str,ts]=mdlInitializeSizes;
%Outputs
  case 2,
    sys=mdlUpdate(t,x,u);
  case 3,
    sys=mdlOutputs(t,x,u);
%Unhandled flags
  case {1,2, 4, 9 }
    sys = [];
%Unexpected flags
  otherwise
    error(['Unhandled flag = ',num2str(flag)]);
end

%mdlInitializeSizes
function [sys,x0,str,ts]=mdlInitializeSizes

sizes = simsizes;
sizes.NumContStates  = 0;       %四个连续变量
sizes.NumDiscStates  = 1;       
sizes.NumOutputs     = 2;
sizes.NumInputs      = 5;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;
sys=simsizes(sizes);
x0=[0];           %四个变量
str=[];
ts = [0.01 0];

function sys=mdlUpdate(t,x,u)
sys=u(1);

function sys=mdlOutputs(t,x,u)
beita_b = 0.001;
beita_k = 0.0005;
to=0.01;
de=(u(1)-x(1))/to;
e = u(1);fe=u(2);fe_=u(3);bd=u(4);kd=u(5);
sys(1)=bd+beita_b*de*(fe-fe_);
sys(2)=kd+beita_k*e*(fe-fe_);

