function [y] = circle1(t)
a=0;b=40;r=40;    
%x=[a:0.01:a+r/sqrt(2)]';x的范围是0到20根号2
y=b-(r^2-(x-a).^2).^0.5;

end

