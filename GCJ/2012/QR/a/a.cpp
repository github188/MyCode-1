#include<stdio.h>
#include<string.h>
char s[200],t[200];

int main()
{
    s['a']='y';
    s['b']='h';
    s['c']='e';
    s['d']='s';
    s['e']='o';
    s['f']='c';
    s['g']='v';
    s['h']='x';
    s['i']='d';
    s['j']='u';
    s['k']='i';
    s['l']='g';
    s['m']='l';
    s['n']='b';
    s['o']='k';
    s['p']='r';
    s['q']='z';
    s['r']='t';
    s['s']='n';
    s['t']='w';
    s['u']='j';
    s['v']='p';
    s['w']='f';
    s['x']='m';
    s['y']='a';
    s['z']='q';
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int n;
    scanf("%d",&n);gets(t);
    for (int i=1;i<=n;i++)
    {
        gets(t);
        for (int j=0;j<strlen(t);j++)
        if ((t[j]>='a')&&(t[j]<='z')) t[j]=s[t[j]];
        printf("Case #%d: %s\n",i,t);
    }
    return 0;
}
