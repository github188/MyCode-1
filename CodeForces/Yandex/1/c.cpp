#include<stdio.h>
double t[200000][2];
int tr[200000][3];
int n,k,ro;

int work(int o,int p,int q)
{
    int ans=0;
    if (tr[o][1]==0) {return 0;}
    if (p==tr[o][0]) {ans+=2;}
    else
    {
        if (p<tr[o][0])
        {
           if (tr[o][1]!=0) {ans=work(tr[o][1],p,q);}
           ans++;
        } else
        {
           if (tr[o][2]!=0) {ans=work(tr[o][2],p,q);}
           ans++;
        }
    }
    return ans;
}

double find(int ro,int p,int q,double r)
{
       
}

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        int j,k;
        scanf("%d%d",&j,&k);
        tr[i][0]=k; 
        if (j!=-1)
        {
           if (tr[j][1]==0) {tr[j][1]=k;} else {tr[j][2]=k;}
        } else {ro=i;}
    }
    
    int m;
    scanf("%d",&m);
    for (int i=0;i<m;i++)
    {
        scanf("%d",&k);
        double ans=work(ro,k,0);
        ans=1.0/ans;
        ans=find(ro,k,0,ans);
        printf("%.9f\n",ans);
    }
    return 0;
}
