%S-function for continuous state equation
 function [sys,x0,str,ts]=indirect(t,x,u,flag)

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
sizes.NumContStates  = 2;      
sizes.NumDiscStates  = 0;       
sizes.NumOutputs     = 1;
sizes.NumInputs      = 3;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;
sys=simsizes(sizes);
x0=[5000 0];          
str=[];
ts=[0 0];

%输入是fm & xm, 输出是ke & xe.
function sys=mdlDerivatives(t,x,u)
fm = u(1);
xm = u(2);
ke_ = x(1);
xe_ = x(2);
gama1=1;gama2=15;gama3=1;

f_=ke_*(xm-xe_);
sys(1)=-(gama1*xm+gama2)*(f_-fm);
sys(2)=((f_-fm)/ke_)*((gama1*xe_+gama2)*xm+gama2*xe_+gama3);


function sys=mdlOutputs(t,x,u)
xe_= x(2);  
ke_ = x(1);
fr = u(3);

xr = xe_+fr/ke_;
sys(1)=xr;
    

