%S-function for continuous state equation
function [sys,x0,str,ts]=int(t,x,u,flag,bd,kd)

switch flag,
%Initialization
  case 0,
    [sys,x0,str,ts]=mdlInitializeSizes;
case 1,
    sys=mdlDerivatives(t,x,u,bd,kd);
%Outputs
  case 3,
    sys=mdlOutputs(t,x,u);
%Unhandled flags
  case {2, 4, 9 }
    sys = [];
%Unexpected flags
  otherwise
    error(['Unhandled flag = ',num2str(flag)]);
end 

%mdlInitializeSizes
function [sys,x0,str,ts]=mdlInitializeSizes
sizes = simsizes;
sizes.NumContStates  = 2;       %四个连续变量
sizes.NumDiscStates  = 0;       
sizes.NumOutputs     = 1;
sizes.NumInputs      = 2;
sizes.DirFeedthrough = 0;
sizes.NumSampleTimes = 1;
sys=simsizes(sizes);
x0=[0 0];           %四个变量
str=[];
ts=[0 0];

function sys=mdlDerivatives(t,x,u,bd,kd)
A = [0,1;-kd,-bd];
B = [0,0;kd,-1];
sys=A*x+B*u;

function sys=mdlOutputs(t,x,u)
sys(1)=x(1);
