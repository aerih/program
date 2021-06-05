function [f_infty,tp,ts,sigma]=para_cal(y,delt_err)
    N = length(y.data);
    f_infty = y.data(N);
    err = y.data-f_infty;
    err = err';
    ferr = fliplr(abs(err));
    [~,ts_i]=max(ferr>delt_err*f_infty,[],2);
    ts_i=N-ts_i;
    ts = y.time(ts_i);
    [fp,tp] = max(y.data);
    tp = y.time(tp);
    sigma=(fp-f_infty)/f_infty;

end







