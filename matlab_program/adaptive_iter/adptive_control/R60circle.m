% t1 = [-90:0.1:(-90+45)]'*pi/180;
% x1 = 40*cos(t1);
% y1 = 40*sin(t1)+40;
% r1 = sqrt(x1.^2+y1.^2);
% %plot(x,y)
% %hold on
% t2 = [90-45:0.1:90+45]'*pi/180;
% x2 = 60*cos(t2)+50*sqrt(2);
% y2 = 60*sin(t2)-50*sqrt(2)+40;
% r2 = sqrt(x2.^2+y2.^2);
% %plot(x,y);
% %hold on
% t3 = ((180+45:0.1:180+90)*pi/180)';
% x3 = 40*cos(t3)+100*sqrt(2);
% y3 = 40*sin(t3)+40;
% r3 = sqrt(x3.^2+y3.^2);
% r = [r1;r2;r3];
% t = [t1;t2;t3];
% plot(t,r);
% grid on
% axis equal
% circle = [t,r];

a=0;b=40;r=40;    
x=[a:0.01:a+r/sqrt(2)]';
y=b-(r^2-(x-a).^2).^0.5;



% a=35*sqrt(2);b=50*sqrt(2)-40;r=60;
% x2=[a-15*sqrt(2):0.01:a+15*sqrt(2)]';
% y2=b+(r^2-(x2-a).^2).^0.5;
% a=0;b=40;r=40;
% if t<r/sqrt(2)
% y=b+(r^2-(t-a).^2).^0.5;
% else
%     y=0;
% end

t=x;
circle = [t,y];



