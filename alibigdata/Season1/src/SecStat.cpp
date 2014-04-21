#include "../include/SecStat.h"
bool dd[4][1000][10000];
SecStat::SecStat()
{
    //ctor
}

SecStat::~SecStat()
{
    //dtor
}

void SecStat::work(double a1,double a2,double a3,double a4,int last_month)
{
    FILE* fin=fopen("t_alibaba_data.csv","r");
    std::map <long long,int> status,stat_month[4];
    std::map<int,int> user,item,user_item;
    char s[100];fgets(s,100,fin);
    double item_point[10000];
    int user_rev[30000],item_rev[30000],item_sum[10000],month_sold[4];
    user.clear();item.clear();
    int user_num=0,item_num=0;
    for (int i=0;i<4;i++) {status.clear();stat_month[i].clear();month_sold[i]=0;}
    int us,it,st,line=0;
    FILE* fout;
    fout=fopen("last_week_click_pair.txt","w");
    while (!feof(fin))
    {
        line++;
        fscanf(fin,"%d,%d,%d,\n",&us,&it,&st);
        fgets(s,100,fin);
        if (user[us]==0) {user[us]=++user_num;user_rev[user_num]=us;}
        if (item[it]==0) {item[it]=++item_num;item_rev[item_num]=it;item_sum[item_num]=0;item_point[item_num]=0;}
        if (st==1) item_sum[item[it]]++;
        if (st==0) item_point[item[it]]+=a1;
        if (st==1) item_point[item[it]]+=a2;
        if (st==2) item_point[item[it]]+=a3;
        if (st==3) item_point[item[it]]+=a4;
        long long tmp=(long long)user[us]*(long long)30000+(long long)item[it];
        if ((st==1)&&(status[tmp]==0)) status[tmp]=1; else status[tmp]=status[tmp]+1;
        int month=s[0]-'0'-5;
        //if ((st==1)&&(stat_month[month][tmp]==0)) stat_month[month][tmp]=1; else stat_month[month][tmp]=stat_month[month][tmp]+1;
        if (st==1)
        {
            month_sold[month]++;
            dd[month][user[us]][item[it]]=true;
        }
        /// 这是判断最后一月的规则
        //if (month+5==last_month) fprintf(fout,"%d %d\n",user[us],item[it]);

        /// 最后一天时间戳为262，所以这里只考虑252后的
        int time=(s[0]-'0')*31;
        if (strlen(s)==7) time=time+s[3]-'0'-1;
        else
        {
            int num=(s[3]-'0')*10+s[4]-'0'-1;
            time=time+num;
        }
        if (time>=252) fprintf(fout,"%d %d\n",user[us],item[it]);
    }
    fclose(fout);
    fclose(fin);
    fout=fopen("ItemPoint.txt","w");
    for (int i=1;i<=item_num;i++)
    if (item_sum[i]) fprintf(fout,"%.6f\n",item_point[i]);
    else fprintf(fout,"0\n");
    fclose(fout);
    std::sort(item_sum+1,item_sum+item_num+1);
    fout=fopen("TopPair.txt","w");
    int pair_num = 0;
    for (int i=1;i<=user_num;i++)
        for (int j=1;j<=item_num;j++)
        {
            int temp = 0;
            for (int k=0;k<4;k++)
                if (dd[k][i][j]) temp++;
            if (temp>2)
            {
                fprintf(fout,"%d %d\n",i,j);
                pair_num++;
            }
        }
    fclose(fout);
    fout=fopen("StatisticsInformation.txt","w");
    fprintf(fout,"5月销量：%d\n",month_sold[0]);
    fprintf(fout,"6月销量：%d\n",month_sold[1]);
    fprintf(fout,"7月销量：%d\n",month_sold[2]);
    fprintf(fout,"8月销量：%d\n",month_sold[3]);
    fprintf(fout,"常买对数：%d\n",pair_num);
    fprintf(fout,"下面是出售商品数（降序）：\n");
    for (int i=item_num;i>0;i--) fprintf(fout,"%d\n",item_sum[i]);
    fclose(fout);
}

void SecStat::GetTimeForEachAction()
{
    FILE* fin;
    std::map<int,int> user,item;user.clear();item.clear();
    fin=fopen("user_list.txt","r");
    int n;fscanf(fin,"%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x;fscanf(fin,"%d",&x);
        user[x]=i;
    }
    fclose(fin);

    fin=fopen("item_list.txt","r");
    fscanf(fin,"%d",&n);
    for (int i=1;i<=n;i++)
    {
        int x;fscanf(fin,"%d",&x);
        item[x]=i;
    }
    fclose(fin);

    fin=fopen("t_alibaba_data.csv","r");
    FILE* fout=fopen("data_for_time.txt","w");
    char s[100];
    fgets(s,100,fin);
    while (!feof(fin))
    {
        int x,y,z,t;
        fscanf(fin,"%d,%d,%d,",&x,&y,&z);
        fgets(s,100,fin);
        t=(s[0]-'0')*31;
        if (strlen(s)==7) t=t+s[3]-'0'-1;
        else
        {
            int num=(s[3]-'0')*10+s[4]-'0'-1;
            t=t+num;
        }
        fprintf(fout,"%d %d %d %d\n",user[x],item[y],z,t);
    }
    fclose(fin);
    fclose(fout);
}

struct action
{
    int user,item,status,time;
    bool operator<(action b) const
    {
        return time<b.time;
    }
};

void SecStat::ConditionalPossibility()
{
    std::vector<action> user_item_pair;user_item_pair.clear();
    FILE* fin=fopen("data_for_time.txt","r");
    while (!feof(fin))
    {
        action temp;
        fscanf(fin,"%d%d%d%d",&temp.user,&temp.item,&temp.status,&temp.time);
        user_item_pair.push_back(temp);
    }
    fclose(fin);
    std::sort(user_item_pair.begin(),user_item_pair.end());
    std::map<long long,int> user_item_last_no_buy_time;
    user_item_last_no_buy_time.clear();
    int n=user_item_pair.size();
    int m=user_item_pair[n-1].time;
    double all=0,last_1_week=0,last_2_weeks=0,no_click,others=0;
    for (int i=0;i<n;i++)
    {
        if (user_item_pair[i].status==1)
        {
            all+=1.0;
            int temp=user_item_pair[i].user*10000+user_item_pair[i].item;
            if (user_item_last_no_buy_time[temp]==0)
            {
                no_click+=1.0;
                user_item_last_no_buy_time[temp]=user_item_pair[i].time;
            } else
            if (user_item_pair[i].time-user_item_last_no_buy_time[temp]<8) last_1_week+=1.0; else
            if (user_item_pair[i].time-user_item_last_no_buy_time[temp]<15) last_2_weeks+=1.0; else
            if (user_item_pair[i].time-user_item_last_no_buy_time[temp]>=15) others+=1.0;
        } else
        {
            int temp=user_item_pair[i].user*10000+user_item_pair[i].item;
            if (user_item_last_no_buy_time[temp]==0) user_item_last_no_buy_time[temp]=user_item_pair[i].time;
        }
    }
    FILE* fout=fopen("ConditionalPossibility_About_FirstClickTime.txt","w");
    fprintf(fout,"总数:%.0f\n",all);
    fprintf(fout,"一周内购买:%.0f    百分比：%.4f\n",last_1_week,last_1_week/all);
    fprintf(fout,"一至二周购买:%.0f    百分比：%.4f\n",last_2_weeks,last_2_weeks/all);
    fprintf(fout,"直接购买:%.0f    百分比：%.4f\n",no_click,no_click/all);
    fprintf(fout,"其他:%.0f    百分比：%.4f\n",others,others/all);
    fclose(fout);
}
