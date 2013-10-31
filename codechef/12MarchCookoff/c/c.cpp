#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;
int num=0;
char s[100000];
long long f[70000];

void dfs(int a,int b,int c,int len,int o)
{
    if (a+b+c==0)
    {
        //s[len]=0;
        //printf("%s\n",s);
        long long ten=10;
        for (int i=0;i<len;i++) {long long u=s[i]-'0';f[num]=f[num]*ten+u;}
        num++;
        return;
    }
    if (a>0)
    {
        s[o]='3';
        dfs(a-1,b,c,len,o+1);
        //if (num>=50000) return;
    }
    if (b>0)
    {
        s[o]='5';
        dfs(a,b-1,c,len,o+1);
        //if (num>=50000) return;
    }
    if (c>0)
    {
        s[o]='8';
        dfs(a,b,c-1,len,o+1);
        //if (num>=50000) return;
    }

}

void work(int len)
{
    for (int i=len/3;i>=0;i--)
     for (int j=(len-i)/2;j>=i;j--)
     {
         dfs(i,j,len-i-j,len,0);
         //if (num>=50000) return;
     }
}

int main()
{
    //freopen("1.txt","w",stdout);
    int len=1;
    while (num<50000)
    {
        work(len);
        len++;
    }
    sort(f,f+num);
    for (int i=0;i<50000;i++) cout<<f[i]<<endl;//printf("%I64d\n",f[i]);
    //printf("%d\n",num);
    return 0;
}
