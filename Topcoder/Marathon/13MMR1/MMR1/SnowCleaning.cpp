#include "SnowCleaning.h"

int n,sal,sFine,m,k,tot,totid;
int t=0;
int x[100000],y[100000],dx[100],dy[100],map[100][100],id[100];
bool used[100];
set< pair < int, int > > set1[100];

int abs(int o)
{
    if (o<0) o=-o;
    return o;
}

string itos(int o)
{
    string ans;ans.clear();
    if (o==0) return "0";
    while (o>0)
    {
        ans=char((o%10)+'0')+ans;
        o/=10;
    }
    return ans;
}

SnowCleaning::SnowCleaning()
{
    //ctor
}

SnowCleaning::~SnowCleaning()
{
    //dtor
}

int SnowCleaning::init(int boardSize, int salary, int snowFine)
{
    n=boardSize;
    sal=salary;
    sFine=snowFine;
    totid=0;

    int del=3;
    if (n>30) del++;
    if (n>40) del++;
    del=round(double(del)*1.0*sqrt((double)salary/(double)snowFine));
    //if (del<2) del=2;
    while (del*10<n) del++;

    for (int i=0;i<n;i+=del)
      for (int j=0;j<n;j+=del)
      {
          set1[tot].clear();
          for (int k=0;k<del && i+k<n;k++)
            for (int l=0;l<del && j+l<n;l++) map[i+k][j+l]=tot;
          used[tot]=false;
          tot++;
      }
    return 0;
}

vector< string > CheapsnowFine()
{
    vector< string > Ans;Ans.clear();
    for (int i=0;i<m;i++)
    {
        pair< int, int > tmpp;
        tmpp.first=x[i];
        tmpp.second=y[i];
        set1[map[x[i]][y[i]]].insert(tmpp);
    }
    for (int i=0;i<tot;i++)
    if (set1[i].size()>0)
    {
        if (!used[i])
        {
            string tmpans;tmpans.clear();
            id[i]=totid++;
            pair< int, int > tmpp=*set1[i].begin();
            dx[i]=tmpp.first;
            dy[i]=tmpp.second;
            used[i]=true;
            tmpans="H "+itos(tmpp.first)+" "+itos(tmpp.second);
            set< pair<int,int> >::iterator j=set1[i].begin();
            for (;j!=set1[i].end();j++)
            if ((j->first==tmpp.first)&&(j->second==tmpp.second)) {set1[i].erase(j);break;}
            Ans.push_back(tmpans);
            continue;
        }
        set< pair<int,int> >::iterator j=set1[i].begin();
        int tx,ty,dis;dis=1e9;
        for (;j!=set1[i].end();j++)
        {
            int xx=j->first,yy=j->second;
            if (abs(dx[i]-xx)+abs(dy[i]-yy)<dis)
            {
                tx=xx;ty=yy;
                dis=abs(dx[i]-xx)+abs(dy[i]-yy);
            }
        }

        if ((dx[i]==tx)&&(dy[i]==ty))
        {
            pair < int, int > tmpp;
            tmpp.first=tx;
            tmpp.second=ty;
            set< pair<int,int> >::iterator j=set1[i].begin();
            for (;j!=set1[i].end();j++)
            if ((j->first==tmpp.first)&&(j->second==tmpp.second)) {set1[i].erase(j);break;}
            continue;
        }

        string ans;ans.clear();
        if ((dx[i]!=tx)&&((abs(dx[i]-tx)<abs(dy[i]-ty))||(dy[i]==ty)))
        {
            if (dx[i]<tx)
            {
                ans="M "+itos(id[i])+" D";
                dx[i]++;
            }
            else
            {
                ans="M "+itos(id[i])+" U";
                dx[i]--;
            }
        } else
        {
            if (dy[i]<ty)
            {
                ans="M "+itos(id[i])+" R";
                dy[i]++;
            }
            else
            {
                ans="M "+itos(id[i])+" L";
                dy[i]--;
            }
        }
        Ans.push_back(ans);
        if ((dx[i]==tx)&&(dy[i]==ty))
        {
            pair < int, int  > tmpp;
            tmpp.first=tx;
            tmpp.second=ty;
            set< pair<int,int> >::iterator j=set1[i].begin();
            for (;j!=set1[i].end();j++)
            if ((j->first==tmpp.first)&&(j->second==tmpp.second)) {set1[i].erase(j);break;}
        }
    }
    return Ans;
}

vector< string >  SnowCleaning::nextDay(vector < int  > snowFalls)
{
    vector< string > Ans;Ans.clear();
    m=snowFalls.size()/2;
    for (int i=0;i<m;i++) {x[i]=snowFalls[i*2];y[i]=snowFalls[i*2+1];}
    Ans=CheapsnowFine();
    return Ans;
}
