#include<stdio.h>
int ans;

int gcd(int o,int p)
{
    if (p==0) {return o;} else {return gcd(p,o%p);}
}

int main()
{
    for (int i=2;i<=60;i++)
    {
        int a[100];
        a[0]=0;
        int sum=0;
        for (int j=2;j<=i;j++)
         if (i%j==0) {a[0]++;a[a[0]]=j;}
        for (int j=1;j<i;j++)
        {
            bool b=false;
            for (int k=1;k<=a[0];k++)
            if ((a[k]>j)&&(gcd(a[k],j)==1)) {b=true;break;}
            if (b) {sum++;}
        }
        if (sum>ans) {ans=sum;}
    }
    
    printf("%d\n",ans);
    return 0;
}
