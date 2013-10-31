#include<stdio.h>
#include<string.h>
int a[1000001],f[1000001],way[1000001];
char ch[1000000];
int len,n,h1,h2;
bool d[1000001];

int main()
{
    gets(ch);
    len=strlen(ch);
    a[0]=0;
    for (int i=1;i<=len;i++)
    {
        a[i]=a[i-1];
        if (ch[i-1]=='1') a[i]++;
    }
    f[0]=0;
    h1=h2=0;n=1;
    for (int i=1;i<=len;i++)
    {
        int a1,a2;
        a1=f[h1]+a[i]-a[h1];
        a2=f[h2]+2+(i-h2)-(a[i]-a[h2]);
        if (a1<a2)
        {
            f[i]=a1;
            way[i]=h1;
            d[i]=true;
            if (a1+2<a2) h2=i;
        } else
        {
            f[i]=a2;
            way[i]=h2;
            d[i]=false;
            h1=i;
        }
        n++;
    }

    printf("%d\n",f[len]);
    int i=len;
    while (i>0)
    {
        int k=way[i];
        if (d[i])
        {
            for (int j=k+1;j<=i;j++)
            if (ch[j-1]=='1') printf("+%d^%d\n",2,len-j);
        } else
        {
            printf("+%d^%d\n",2,len-k);
            printf("-%d^%d\n",2,len-i);
            for (int j=k+1;j<=i;j++)
            if (ch[j-1]=='0') printf("-%d^%d\n",2,len-j);
        }
        i=k;
    }

    return 0;
}
