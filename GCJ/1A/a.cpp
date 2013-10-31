#include<stdio.h>
int tt;
long long n,pd,pg;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&tt);int t=0;
    while (tt>0)
    {
          t++;
          tt--;
          printf("Case #%d: ",t);
          scanf("%lld%lld%lld",&n,&pd,&pg);
          
          if (pg==0)
          {
                    if (pd==0) {printf("Possible\n");} else {printf("Broken\n");}
          
          } else
          if (pg==100)
          {
             if (pd==100) {printf("Possible\n");} else {printf("Broken\n");}
          } else
          if (n>=100) {printf("Possible\n");} else
          {
                int nn=n;bool bo=false;
                for (int i=1;i<=nn;i++)
                if (((i*pd)%100)==0)
                {
                   bo=true;
                   break;
                }      
                if (bo) {printf("Possible\n");} else {printf("Broken\n");}
          } 
    }
    
    return 0;
}
