#include<stdio.h>
#include<algorithm>
using namespace std;
int t,a,b;
int c[100];

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&t);
    for (int i=1;i<=t;i++)
    {
        scanf("%d%d",&a,&b);
        int l=0,k=1;
        while (k<b) {k*=10;l++;}
        long long ans=0;k/=10;
        for (int i=a;i<=b;i++)
        {
            int num=i;long long tmp=0;
            bool check=true;
            for (int j=0;j<l;j++)
            {
                num=(num%10)*k+num/10;
                if ((num>i)&&(num<=b)) {check=false;break;}
                if ((num<i)&&(num>=a)) {c[tmp]=num;tmp++;}
            }
            int u=tmp;
            sort(c,c+tmp);
            for (int i=1;i<tmp;i++) if (c[i]==c[i-1]) tmp--;
            long long two=2;
            tmp=(tmp*tmp+tmp)/two;
            if (check) ans+=tmp;
        }
        printf("Case #%d: %I64d\n",i,ans);
    }
    return 0;
}
