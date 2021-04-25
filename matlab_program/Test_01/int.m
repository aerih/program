%S-function for continuous state equation
function [sys,x0,str,ts]=int(t,x,u,flag)

switch flag,
%Initialization
  case 0,
    [sys,x0,str,ts]=mdlInitializeSizes;
case 1,
    sys=mdlDerivatives(t,x,u);
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
sizes.NumOutputs     = 2;
sizes.NumInputs      = 2;
sizes.DirFeedthrough = 0;
sizes.NumSampleTimes = 1;
sys=simsizes(sizes);
x0=[0 1];           %四个变量
str=[];
ts=[0 0];

function sys=mdlDerivatives(t,x,u)


sys(1)=u(1);    %关节一的角速度
sys(2)=u(2);

function sys=mdlOutputs(t,x,u)
sys(1)=x(1);
sys(2)=x(2);
