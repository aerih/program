%S-function for continuous state equation
 function [sys,x0,str,ts]=dir_impetance(t,x,u,flag)
m = 1;b = 65;kexi = 0.01;
switch flag,
%Initialization
  case 0,
    [sys,x0,str,ts]=mdlInitializeSizes;
  case 1,
    sys=mdlDerivatives(t,x,u,m,b);
  case 2,
    sys=mdlUpdate(t,x,u,b,kexi);
%Outputs
  case 3,
    sys=mdlOutputs(t,x,u);
%Unhandled flags
  case {4, 9 }
    sys = [];
%Unexpected flags
  otherwise
    error(['Unhandled flag = ',num2str(flag)]);
end

%mdlInitializeSizes
function [sys,x0,str,ts]=mdlInitializeSizes
sizes = simsizes;
sizes.NumContStates  = 2;      
sizes.NumDiscStates  = 1;       
sizes.NumOutputs     = 1;
sizes.NumInputs      = 2;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 2;
sys=simsizes(sizes);
x0=[-0.05 0 60];          
str=[];
ts=[0 0;
    0.005 0];

%输入是fm & xm, 输出是ke & xe.
function sys=mdlDerivatives(t,x,u,m,b)

A = [0,1;
    0,-b/m];
B = [0;1/m];

sys = A*[x(1);x(2)]+B*u(1);

function sys=mdlUpdate(t,x,u,b,kexi)
e = x(1);
xita = x(3);
% xc = x(4);
deta_b = (b/e)*xita;
b = b + deta_b;
sys = xita + kexi*u(1)/b;
% sys(2) = xc + e;


function sys=mdlOutputs(t,x,u)
sys(1) = x(1)+u(2);

