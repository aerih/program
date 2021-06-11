function y=int(x)
global gama1 gama2 P I D
delt_err = 1e-2;
n = length(x(:,1));
y = zeros(n,1);
    for i = 1:n
        gama1 = x(i,1);
        gama2 = x(i,2);
        P = x(i,3);
        I = x(i,4);
        D = x(i,5);
        sim('origin_cont.slx'); 
%         inf = length(mfi.data)-1;
%         dif_int(i) = abs(rfi.data(inf)-1.012*mfi.data(inf));
%        inf = length(fm.data)-1;
%         y = abs(dec_ar.data(inf)+inc_ar.data(inf));
        [f_infty,tp,ts,sigma]=para_cal(fm,delt_err);
        y(i)=log(ts/0.3+1)+log(sigma/0.5+1);
    end
end


