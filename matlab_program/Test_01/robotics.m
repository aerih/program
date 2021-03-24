clear; 
clc; 
th(1)=0; d(1)=0; a(1)=0; alp(1)=0; 
th(2)=60; d(2)=0; a(2)=0.33; alp(2)=pi/2; 
th(3)=0;d(3)=1.3; a(3)=0;alp(3)=pi/2;
th(4)=pi/3;d(4)=0; a(4)=0;alp(4)=pi/2; 
th(5)=pi/3;d(5)=1.22;a(5)=-0.115;alp(5)=-pi/2; 
th(6)=20;d(6)=0;a(6)=0;alp(6)=pi/2; 
th(7)=0;d(7)=0.215;a(7)=0;alp(7)=-pi/2; 

L1=Link([th(1),d(1),a(1),alp(1),0],'modified'); 
L2=Link([th(2),d(2),a(2),alp(2),0],'modified'); 
L3=Link([th(3),d(3),a(3),alp(3),0],'modified'); 
L4=Link([th(4),d(4),a(4),alp(4),0],'modified'); 
L5=Link([th(5),d(5),a(5),alp(5),0],'modified'); 
L6=Link([th(6),d(6),a(6),alp(6),0],'modified'); 
L7=Link([th(7),d(7),a(7),alp(7),0],'modified'); 
robot=SerialLink([L1,L2,L3,L4,L5,L6,L7]); 
robot.name='WAM Robot-7-dof'; 
robot.display() 
theta=[0,90,45,80,180,0,0]*pi/180; 
robot.teach(); 
robot.plot(theta); 
t=robot.fkine(theta) %Ä©¶ËÖ´ÐÐÆ÷Î»×Ë
