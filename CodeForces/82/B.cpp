#include<stdio.h>
int n,k,a;
int b[10],l[10];
double ans;

void work(int o,int p)
{
     if (o==n)
     {
        double ans1=0;
        
        for (int i=0;i<(1<<n);i++)
        {
            double f=1.0;
            int u=0;
            for (int j=0;j<n;j++){double kk=l[j+1];kk=kk/100.0;
            if ((i&(1<<j))>0) {u++;f=f*kk;} else {f=f*(1.0-kk);} }
            if (u>n/2) {ans1=ans1+f;} else
            {
               double uu=0;
               for (int j=0;j<n;j++)
               if ((i&(1<<j))==0)
               {
                  uu=uu+b[j+1];
               }
               uu+=a;
               double aa=a;
               aa=aa/uu;
               ans1+=aa*f;
            }
        }
        
        if (ans1>ans) {ans=ans1;}
     } else
     {
        if (o==n-1)
        {
           int u=l[n];
           l[n]+=10*(k-p);
           if (l[n]>100) {l[n]=100;}
           work(o+1,k);
           l[n]=u;
        } else
        {
           for (int i=0;i<=k-p;i++)
           {
               int u=l[o+1];
               l[o+1]+=10*i;
               if (l[o+1]>100) {l[o+1]=100;}
               work(o+1,p+i);
               l[o+1]=u;
           }
        }
     }
}

int main()
{
    ans=0;
    scanf("%d%d%d",&n,&k,&a);
    for (int i=1;i<=n;i++) {scanf("%d%d",&b[i],&l[i]);}
    work(0,0);
    printf("%.9f\n",ans);
    return 0;
}
