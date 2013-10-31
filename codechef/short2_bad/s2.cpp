#include<stdio.h>

int p=619;

int main()
{
    int ans=0,fault=0;
    int pp=(p+1)*(p+1),ul=p*3+p/2;
int uuu=0;
    for (int a=p+1;a<=ul;a++)
     for (int k=2;k<=pp;k++)
     if (k*(a-p)-a>0)
     if ((((a-p)*k*p)%(k*(a-p)-a))==0)
     {
         int b=(((a-p)*k*p)/(k*(a-p)-a));
         //printf("%d..%d\n",a,b);
         if (b<a) continue;
         if (((a*b)%((a-p)*(b-p)))!=0) {fault++;continue;}
         ans++;if (a!=b) ans++;
         if (((a%p)!=0)&&((b%p)!=0)) {printf("%d,%d\n",a,b);if (a!=b) uuu++;}
     }
     printf("%d\n%d\n",uuu,ans);

    return 0;
}
