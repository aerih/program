%run('C:\Users\Administrator\git_program\matlab_program\adptive_control\simlink13.slx');
for j=1:150
    [simOut,fm] = sim('simlink13.slx',[0,10]);
    %gama1 = ones(1001,1)*100;
    %gama2 = ones(1001,1)*100;
    %gama1 = gama1+ones(1001,1)*50;
    gama2 = gama2+ones(1001,1)*5;

    simin = [t1,gama1,gama2];

    chaotiao_ptg = 1.1;     %超调百分比
    st_length = 300;        %统计序列的长度
    p_limit = 0.027;            %二乘法限制的阈值

    e=(pm.data-pr).^2;      %这个数组记录了各个数值对应的方差
    [m,n] = size(e);        %获取序列的行和列
    A_pr = pm.data((m-301):(m-1));      %期望力：本来是等于常数50的，但发现数据收敛不到50，总有稳态误差。而稳态误差不应该考虑在内所以选择数据最后的值作为收敛值
    pr = sum(A_pr(:))/300;
    dt = max(pm.time)/length(pm.time);      %采样时间间隔

    %循环采样st_length个采样时间序列，直到发现方差低于某个阈值，停止循环。
    for st_index = 1:m-st_length  %采样序列开始的索引
        index_range = st_index:st_index+st_length;  
        se = e(index_range);        %被采样的那500个序列的方差记录                      
        sum_se = sum(se(:));        %计算出所有方差的和
        average = sum_se/st_length;
        if average <= p_limit
            data_Arr(iend) = st_index*dt;
            iend = iend + 1;
            for i = 1:st_index+st_length    %判断数据是否大于超调的心理预期，超调的话删除记录的值
                if pm.data(i)> pr*chaotiao_ptg
                    iend = iend - 1;
                    data_Arr(iend) = 0;
                    cue1 = "超调了，数据作废"
                    break;
                end
            end
            break;
        end
        if st_index == m-st_length
            cue2 = "未找到收敛点"
        end
    end
    cue3 = j
end