function y=int(x)
global gama1 gama2
 delt_err = 2e-2;
n = length(x(:,1));
y = zeros(n,1)+1;
    for i = 1:n
        gama1 = x(i,1);
        gama2 = x(i,2);
        pause(0.01);
        sim('origin_cont.slx'); 
        inf = length(fm.data)-1;
%         y = abs(dec_ar.data(inf)+inc_ar.data(inf));
        [f_infty,tp,ts,sigma]=para_cal(fm,delt_err);
        y=log(ts/0.7+1)+log(sigma/0.1+1);
            
    end
end


