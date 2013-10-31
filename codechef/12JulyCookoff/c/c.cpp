#include<stdio.h>
#include<string.h>
char s[100000],t[100000];
int n,tt;
bool ok;

bool check()
{

            memset(t,0,sizeof(t));
            int m=strlen(s);
            int n3,n5,n8;
            n3=n5=n8=m/3;
            if ((m%3)>0) {n8++;}
            if ((m%3)>1) {n5++;}
            int u=n;
            if (n8<=u) {u-=n8;n8=0;} else {n8-=u;u=0;}
            if (n5<=u) {u-=n5;n5=0;} else {n5-=u;u=0;}
            if (n3<=u) {u-=n3;n3=0;} else {n3-=u;u=0;}
            if (strlen(s)-n3-n5-n8>0) {t[0]='1';}
            for (int i=1;i<strlen(s)-n3-n5-n8;i++) t[i]='0';
            for (int i=0;i<n3;i++) t[strlen(s)-n3-n5-n8+i]='3';
            for (int i=0;i<n5;i++) t[strlen(s)-n3-n5-n8+n3+i]='5';
            for (int i=0;i<n8;i++) t[strlen(s)-n3-n5-n8+n3+n5+i]='8';
            for (int i=0;i<strlen(s);i++) if (t[i]<s[i]) {return true;} else if (t[i]>s[i]) {return false;}
            return true;
}

bool judge(int o,int n3,int n5,int n8,int p)
{
    int num=strlen(s)-o+p;
    if (n5<n3) {num-=n3+n5;n5=n3;}
    if (num<0) return false;
    n8+=num;
    if (n8<n5) return false;
    return true;
}

void work(int o,int n,int n3,int n5,int n8,bool w,int p)
{
    if (o>=strlen(s)) {ok=true;return;}
    if (w)
    {
        if (n>0)
        {
            t[o]='9';
            work(o+1,n-1,n3,n5,n8,w,p+1);
            if (ok) return;
        }
        if (judge(o+1,n3,n5,n8+1,p)&&(strlen(s)-o-1>=n))
        {
            t[o]='8';
            work(o+1,n,n3,n5,n8+1,w,p);
            if (ok) return;
        }
        if (judge(o+1,n3,n5+1,n8,p&&(strlen(s)-o-1>=n)))
        {
            t[o]='5';
            work(o+1,n,n3,n5+1,n8,w,p);
            if (ok) return;
        }
        if (judge(o+1,n3+1,n5,n8,p)&&(strlen(s)-o-1>=n))
        {
            t[o]='3';
            work(o+1,n,n3+1,n5,n8,w,p);
            if (ok) return;
        }
    }
    if (s[o]=='3')
    {
        if ((judge(o+1,n3+1,n5,n8,p))&&(strlen(s)-o-1>=n))
        {
            t[o]='3';
            work(o+1,n,n3+1,n5,n8,w,p);
            if (ok) return;
        }
        if ((n>0)&&(judge(o+1,n3,n5,n8,p+1)))
        {
            t[o]='2';
            work(o+1,n-1,n3,n5,n8,true,p+1);
            if (ok) return;
        }
    }

    if (s[o]=='5')
    {
        if ((judge(o+1,n3,n5+1,n8,p))&&(strlen(s)-o-1>=n))
        {
            t[o]='5';
            work(o+1,n,n3,n5+1,n8,w,p);
            if (ok) return;
        }
        if ((n>0)&&(judge(o+1,n3,n5,n8,p+1)))
        {
            t[o]='4';
            work(o+1,n-1,n3,n5,n8,true,p+1);
            if (ok) return;
        }
    }

    if (s[o]=='8')
    {
        if ((judge(o+1,n3,n5,n8+1,p))&&(strlen(s)-o-1>=n))
        {
            t[o]='8';
            work(o+1,n,n3,n5,n8+1,w,p);
            if (ok) return;
        }
        if ((n>0)&&(judge(o+1,n3,n5,n8,p+1)))
        {
            t[o]='7';
            work(o+1,n-1,n3,n5,n8,true,p+1);
            if (ok) return;
        }
    }

    if ((n>0)&&(judge(o+1,n3,n5,n8,p+1)))
    {
        t[o]=s[o];
        work(o+1,n-1,n3,n5,n8,w,p+1);
        if (ok) return;
        if ((s[o]!='0')&&(s[o]!='9')&&(s[o]!='6')&&(s[o]!='4'))
        {
           t[o]=s[o]-1;
           work(o+1,n-1,n3,n5,n8,true,p+1);
           if (ok) return;
        }
    }
    if ((s[o]>'8')&&(judge(o+1,n3,n5,n8+1,p))&&(strlen(s)-o-1>=n))
    {
        t[o]='8';
        work(o+1,n,n3,n5,n8+1,true,p);
        if (ok) return;
    }
    if ((s[o]>'5')&&(judge(o+1,n3,n5+1,n8,p))&&(strlen(s)-o-1>=n))
    {
        t[o]='5';
        work(o+1,n,n3,n5+1,n8,true,p);
        if (ok) return;
    }
    if ((s[o]>'3')&&(judge(o+1,n3+1,n5,n8,p))&&(strlen(s)-o-1>=n))
    {
        t[o]='3';
        work(o+1,n,n3+1,n5,n8,true,p);
        if (ok) return;
    }
}

int main()
{
    scanf("%d",&tt);
    while (tt>0)
    {
        tt--;
        scanf("%d %s",&n,&s);
        if (strlen(s)<n) {printf("-1\n");continue;}
        if ((strlen(s)==1)&&(n==0)&&(s[0]<'8')) {printf("-1\n");continue;}
        if (!check())
        {
            if (strlen(s)==n) {printf("-1\n");continue;}
            memset(t,0,sizeof(t));
            int m=strlen(s)-1;
            for (int i=0;i<n;i++) t[i]='9';
            for (int i=n;i<m;i++) t[i]='8';
            printf("%s\n",t);
            continue;
        }
        memset(t,0,sizeof(t));
        int m=strlen(s);
        int n3,n5,n8;
        n3=n5=n8=m/3;
        if ((m%3)>0) {n8++;}
        if ((m%3)>1) {n5++;}
        ok=false;
        work(0,n,0,0,0,false,0);
        printf("%s\n",t);
    }
    return 0;
}
