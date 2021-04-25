%Adaptive switching Learning Control for 2DOF robot manipulators
clear all;
close all;

t=[0:0.01:3]';
k(1:length(t))=0;    %Total initial points
k=k';
T1(1:length(t))=0;
T1=T1';
T2=T1;
fe_(1:length(t))=0;
fe_=fe_';
T=[T1 T2];
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% M=20;
% for i=1:1:M    % Start Learning Control
% i
% pause(0.01);
% 
% sim('iter_impedance',[0,3]);
% 
% 
% figure(1);
% subplot(311);
% hold on;
% plot(t,T(:,1),'r');
% xlabel('time(s)');ylabel('T1');
% 
% subplot(312);
% hold on;
% plot(t,T(:,2),'b');
% xlabel('time(s)');ylabel('T2');
% 
% subplot(313);
% hold on;
% plot(t,fe_(:),'g');
% xlabel('time(s)');ylabel('fe_');
% 
% T(:,1)=T(length(t),1);
% T(:,2)=T(length(t),2);
% %fe_(:)=fe_(length(t)-1);
% 
% % j=i+1;
% % times(j)=i;
% % e1i(j)=max(abs(e1));
% % e2i(j)=max(abs(e2));
% % de1i(j)=max(abs(de1));
% % de2i(j)=max(abs(de2));
% end          %End of i
% %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% figure(2);
% subplot(211);
% plot(t,q1d,'r',t,q1,'b');
% xlabel('time(s)');ylabel('Position tracking of Link 1');
% subplot(212);
% plot(t,q2d,'r',t,q2,'b');
% xlabel('time(s)');ylabel('Position tracking of Link 2');
% 
% figure(3);
% plot(times,e1i,'*-r',times,e2i,'o-b');
% title('Change of maximum absolute value of error1 and error2 with times i');
% xlabel('times');ylabel('error 1 and error 2');