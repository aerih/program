function [f_infty,tp,ts,sigma]=parameter_cal(y,T0,delt_err,debug)
%y是系统输出序列
%T0是采样时间，可以结合时间序列点序号算出实际时间
%delt_err是调节时间的误差精度
    M=size(y,1);N=size(y,2);%M为运算维度，N为时间序列长度
    f_infty=y(:,N);%稳态值序列
    err=y-f_infty*ones(1,N);%通过稳态值计算误差序列
    ferr=fliplr(abs(err));%倒序并取绝对值
    [~,ts_i]=max(ferr>delt_err*f_infty,[],2);
    ts_i=N*ones(M,1)-ts_i;
    ts=ts_i*T0;%调节时间
    [fp,tp]=max(y,[],2);%峰值和函数峰值
    tp=tp*T0;
    tp(abs(fp-f_infty)<1e-5)=NaN; %过阻尼无超调，没有峰值时间
    sigma=(fp-f_infty)./f_infty;
    if debug && M==1 %非调试模式下不显示
        disp(['系统稳态值为',num2str(f_infty)])
        disp(['系统超调量为',num2str(sigma*100),'%'])
        if isnan(tp)
            disp('系统不存在峰值时间')
        else
            disp(['系统峰值时间为',num2str(tp),'s'])
        end
        disp(['系统的调节时间为',num2str(ts),'s'])      %num2str将数字转换为字符串
    end
end
