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
x0=[2000 1];           %四个变量
str=[];
ts=[0 0];

%输入是pm & xm, 输出是ke & xe.
function sys=mdlDerivatives(t,x,u)
gama1 = 100;
gama2 = 200;
pm = u(1);
xm = u(2);
ke_ = x(1);
xe_ = x(2);
p_=ke_*(xm-xe_);
sys(1)=gama1*(-xm*(p_-pm));
sys(2)=gama1*((p_-pm)/ke_*(xm*xe_+gama2/gama1));


function sys=mdlOutputs(t,x,u)

sys(1)=x(1);
sys(2)=x(2);

