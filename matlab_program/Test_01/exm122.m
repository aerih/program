function Hr=exm122(flag)
t=(0:50)/50*2*pi;
x=sin(t);
y=cos(t);
Hr=@cirline;
feval(Hr,flag,x,y,t)

function cirline(wd,x,y,t)
switch wd
    case 'line'
        plot(t,x,'b',t,y,'r','LineWidth',2)
    case 'circle'
        plot(x,y,'-g','LineWidth',8)
    otherwise
        error('输入变量只取')
end
shg