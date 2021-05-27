function [dif_fi]=int(x)
global gama1 gama2
n = length(x(:,1));
dif_fi = zeros(n,1)+1;
    for i = 1:n
        
        gama1 = x(i,1);
        gama2 = x(i,2);
        pause(0.01);
        sim('origin_cont.slx');        
        len = length(mfi.time)-10;
        dif_fi(i) = abs(rfi.data(len) - mfi.data(len));
    end
end



    % for i=1:5
    % i
    % sim('origin_cont.slx',[0,3]);
    % gama1 = gama1*5;
    % plot(fm.time,fm.data);
    % hold on
    % end
    % plot(fm.time,35);
    % hold off
    % sim('origin_cont.slx',[0,3]);
    % plot(fm.time,fm.data);
    % hold on