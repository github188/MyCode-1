#include<stdio.h>
#include<string.h>

char s[100000];
bool suc[4],use[100000];
int n;

bool check0(int a0,int a1,int a)
{
    if (a1<=n-2-(n-2)/2) return true;
    return false;
}

bool check1(int a0,int a1,int a)
{
    if (s[n-1]=='1')
    {
        int u=n-2-(n-2)/2;
        a1--;
        u-=a1;
        if ((u<0)||(u>a)) return false;
        return true;
    } else
    if (s[n-1]=='?')
    {
        a--;
        int u=n-2-(n-2)/2;
        u-=a1;
        if ((u<0)||(u>a)) return false;
        return true;
    } else
    {
        return false;
    }
}

bool check2(int a0,int a1,int a)
{
    if (s[n-1]=='0')
    {
        int u=n-2-(n-2)/2;
        a1--;
        u-=a1;
        if ((u<0)||(u>a)) return false;
        return true;
    } else
    if (s[n-1]=='?')
    {
        a--;
        int u=n-2-(n-2)/2+1;
        u-=a1;
        if ((u<0)||(u>a)) return false;
        return true;
    } else
    {
        return false;
    }
}

bool check3(int a0,int a1,int a)
{
    if (a0<=(n-2)/2) return true;
    return false;
}

int main()
{
    gets(s);
    n=strlen(s);
    int a1,a0,a;a1=a0=a=0;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='1') a1++;
        if (s[i]=='0') a0++;
        if (s[i]=='?') a++;
    }

    if (check0(a0,a1,a)) suc[0]=true;
    if (check1(a0,a1,a)) suc[1]=true;
    if (check2(a0,a1,a)) suc[2]=true;
    if (check3(a0,a1,a)) suc[3]=true;
    for (int i=0;i<4;i++)
    if (suc[i])
    {
        if ((i&2)>0) {printf("1");} else {printf("0");}
        if ((i&1)>0) {printf("1");} else {printf("0");}printf("\n");
    }
    return 0;
}
