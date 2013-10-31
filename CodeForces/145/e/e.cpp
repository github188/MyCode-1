#include<stdio.h>
#include<algorithm>
using namespace std;
struct team
{
    char s[50];
    int score;
} f[100];
int n,x,a,b,c;
bool use[100];

bool cmp(team a,team b)
{
    return a.score>b.score;
}

int find(int o,int p)
{
    while (true)
    {
        if (!use[o]) p--;
        if (p==0) return o;
        o++;
    }
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d%d%d%d",&n,&x,&a,&b,&c);
    for (int i=0;i<n;i++) scanf("%s%d",f[i].s,&f[i].score);
    sort(f,f+n,cmp);
    int m=n/4;
    for (int i=m;i>0;i--)
    {
        int tmp;
        printf("Group %c:\n",'A'+m-i);
        x=(a*x+b)%c;
        tmp=find(0,x%i+1);
        use[tmp]=true;
        printf("%s\n",f[tmp].s);
        x=(a*x+b)%c;
        tmp=find(m,x%i+1);
        use[tmp]=true;
        printf("%s\n",f[tmp].s);
        x=(a*x+b)%c;
        tmp=find(m+m,x%i+1);
        use[tmp]=true;
        printf("%s\n",f[tmp].s);
        x=(a*x+b)%c;
        tmp=find(m+m+m,x%i+1);
        use[tmp]=true;
        printf("%s\n",f[tmp].s);
    }
    return 0;
}
