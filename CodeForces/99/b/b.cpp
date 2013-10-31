#include<string.h>
#include<stdio.h>

char s[100000],u[100000],v[100000];
int n;
int a[10],b[10],c[10];

int min(int o,int p)
{
    if (o<p) return o;return p;
}

int main()
{
    gets(s);n=strlen(s);
    for (int i=0;i<n;i++) {a[s[i]-'0']++;}
    int ans=0,k=0;

    for (int i=1;i<=9;i++)
    if ((a[i]>0)&&(a[10-i]>0))
    {
        for (int j=0;j<10;j++) {b[j]=c[j]=a[j];}
        b[i]--;c[10-i]--;int tmp=1;
        for (int i=0;i<10;i++) tmp+=min(b[i],c[9-i]);
        if ((b[0]>c[9])&&(c[0]>b[9])) tmp+=min(b[0]-c[9],c[0]-b[9]);
        if (tmp>ans) {ans=tmp;k=i;}
    }

    if (ans==0)
    {
        if (a[0]==0) {printf("%s\n%s\n",s,s);}
        else
        {
            memset(s,0,sizeof(s));
            int n=0;
            for (int i=1;i<=9;i++) for (int j=0;j<a[i];j++) {s[n]=i+'0';n++;}
            for (int i=0;i<a[0];i++) {s[n]='0';n++;}
            printf("%s\n%s\n",s,s);
        }
    } else
    {
        for (int j=0;j<10;j++) {b[j]=c[j]=a[j];}
        b[k]--;c[10-k]--;
        memset(u,0,sizeof(u));
        memset(v,0,sizeof(v));
        n--;
        if ((b[0]>c[9])&&(c[0]>b[9]))
        {
            for (int i=0;i<min(b[0]-c[9],c[0]-b[9]);i++) {u[n]=v[n]='0';n--;}int t1=min(b[0]-c[9],c[0]-b[9]);
            b[0]-=t1;
            c[0]-=t1;
        }
        u[n]=k+'0';v[n]=10-k+'0';n--;
        for (int i=0;i<=9;i++)
        {
            while ((b[i]>0)&&(c[9-i]>0))
            {
                u[n]=i+'0';
                v[n]=9-i+'0';
                n--;
                b[i]--;
                c[9-i]--;
            }
        }

        int kk=0,l=0;
        for (int i=0;i<=9;i++)
        {
            while (b[i]>0)
            {
                u[kk]=i+'0';
                kk++;
                b[i]--;
            }
            while (c[i]>0)
            {
                v[l]=i+'0';
                l++;
                c[i]--;
            }
        }
        printf("%s\n%s\n",u,v);

    }

    return 0;
}
