#include<stdio.h>
bool f[32000];
int a[32000];

int fun(int o,int p)
{
    if (o<a[p]) {return 0;}
    int sum=o/a[p];int kk=o/a[p];
    for (int i=1;i<p;i++) {sum-=fun(kk,i);}
    return sum;
}

int main()
{
    a[0]=0;
    for (int i=2;i<32000;i++)
    if (!f[i])
    {
        int j=i;
        while (j+i<32000)
        {
              j+=i;
              f[j]=true;
        }
        a[0]++;a[a[0]]=i;
    }
    
    int aa,b,c,fa,fb;
    scanf("%d%d%d",&aa,&b,&c);
    int k=-1;
    for (int i=1;i<=a[0];i++)
    if (a[i]==c) {k=i;break;}
    if (k==-1) 
    {
       bool ff=true;
       for (int i=1;i<=a[0];i++)
       if ((c%a[i])==0) {ff=false;break;}
       if (!ff) 
       {
          printf("0\n");
       }
       else
       {
        int fb1,fa1;fb1=fa1=0;
        if (aa>=c) {fa1=1;}
        if (b>=c) {fb1=1;}
        printf("%d\n",fb1-fa1);
       }
    }
    else
    {
        fa=fun(aa-1,k);
        fb=fun(b,k);
        printf("%d\n",fb-fa);
    }
    return 0;
}
