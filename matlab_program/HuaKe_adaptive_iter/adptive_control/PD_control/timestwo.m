function [sys,x0,str,ts] = timestwo(t,x,u,flag)

switch flag,

  %%%%%%%%%%%%%%%%%%
  % Initialization %
  %%%%%%%%%%%%%%%%%%
  case 0,
    [sys,x0,str,ts]=mdlInitializeSizes;


  case 3,
    sys=mdlOutputs(t,x,u);

  case{1,2,4,9}
    sys=[];
    
  otherwise
    error('Simulink:blocks:unhandledFlag', num2str(flag));

end


function [sys,x0,str,ts]=mdlInitializeSizes


sizes = simsizes;

sizes.NumContStates  = 0;
sizes.NumDiscStates  = 0;
sizes.NumOutputs     = 1;
sizes.NumInputs      = 1;
sizes.DirFeedthrough = 1;
sizes.NumSampleTimes = 1;   % at least one sample time is needed

sys = simsizes(sizes);


x0  = [];

str = [];

ts  = [-1 0];



function sys=mdlOutputs(t,x,u)

sys = 2*u;




