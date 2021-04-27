function [y] = circle3(t)
a=100*sqrt(2); b=40; r=40;    
%x=[a-r/sqrt(2):0.01:a]';x的范围是80根号2到100根号2
y=b-(r^2-(x-a).^2).^0.5;

end

