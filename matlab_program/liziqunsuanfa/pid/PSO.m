function [Pg,fmin]=PSO(f,dimension,n,m,xmax,xmin,vmax,vmin)
%全局粒子群算法,f为目标函数,dimension为维度,n为代数,m为种群规模
%位置限幅为[xmin,xmax]，速度限幅为[vmin,vmax]
    Savef=zeros(n+1,1);
    SaveData=zeros(m,dimension,10);%记录11代种群的位置
    w=1;c1=2;c2=2;%速度惯性系数
    dt=0.3;%位移仿真间隔
    v=zeros(m,dimension);%初始速度为0
    X=(xmax-xmin)*rand(m,dimension)+xmin;%初始位置满足(-xmax,xmax)内均匀分布
    P=X;%P为每个粒子每代的最优位置
    last_f=f(X);
    [fmin,min_i]=min(last_f);%Pg为所有代中的最优位置 
    Pg=X(min_i,:);
    Savef(1)=fmin;
    N=0;
    for i=1:n
        v=w*v+c1*rand*(P-X)+c2*rand*(ones(m,1)*Pg-X);
        v=(v>vmax).*vmax+(v>=vmin & v<=vmax).*v+(v<vmin).*vmin;
        X=X+v*dt;
        X=(X>xmax).*xmax+(X>=xmin & X<=xmax).*X+(X<xmin).*xmin;
        new_f=f(X);%新的目标函数值
        update_j=find(new_f<last_f);
        P(update_j,:)=X(update_j,:);%修正每个粒子的历史最优值
        [new_fmin,min_i]=min(new_f);
        new_Pg=X(min_i,:);
        Pg=(new_fmin<fmin)*new_Pg+(new_fmin>=fmin)*Pg;
        last_f=new_f;%保存当前的函数值
        fmin=min(new_fmin,fmin);%更新函数最小值
         Savef(i)=fmin;
         if mod(i,floor(n/10))==0%每10代记录一次种群参数
             N=N+1;
            SaveData(:,:,N)=X;
         end
         w=w-i/n*0.7*w;
    end
    for j=1:10
        figure(j)
        plot(SaveData(:,1,j),SaveData(:,2,j),'o');
        xlim([-xmax,xmax])
        ylim([-xmax,xmax])
        axis tight
    end
    figure
    plot(Savef','b-')
    disp(Pg)
    disp(fmin)
end
