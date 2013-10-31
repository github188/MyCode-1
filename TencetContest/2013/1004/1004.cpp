#include<stdio.h>
#include<string.h>
char s[200];
int a[200],b[200],n[200],m[200],p[200];

void stoi(char s[],int a[])
{
    a[0]=strlen(s);
    for (int i=a[0]-1;i>=0;i--) a[a[0]-i]=s[i]-'0';
}

void add()
{
    for (int i=0;i<200;i++) a[i]=0;
    for (int i=0;i<=n[0];i++) a[i]=n[i];
    for (int i=1;i<=p[0];i++)
    {
        a[i]+=p[i];
        if (a[i]>9) {a[i+1]++;a[i]-=10;}
    }
    if (a[0]<p[0]) a[0]=p[0];
    while (a[a[0]+1]>0)
    {
        a[0]++;int i=a[0];
        if (a[i]>9) {a[i+1]++;a[i]-=10;}
    }
}

bool bigger(int a[],int b[])
{
    if (a[0]>b[0]) return true;
    if (a[0]<b[0]) return false;
    for (int i=a[0];i>0;i--)
    {
        if (a[i]>b[i]) return true;
        if (a[i]<b[i]) return false;
    }
    return true;
}

int main()
{
    while (scanf("%s",s)!=EOF)
    {
        stoi(s,n);
        scanf("%s",s);stoi(s,m);
        scanf("%s",s);stoi(s,p);
        add();
        b[0]=1;b[1]=3;
        if (bigger(a,m)&bigger(m,b)) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
