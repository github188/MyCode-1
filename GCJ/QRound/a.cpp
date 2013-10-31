#include<stdio.h>
int a[101],b[101],c[101][2];
int n,tt,x,y;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    scanf("%d",&tt);
    for (int ttt=1;ttt<=tt;ttt++)
    {
        scanf("%d",&n);
        a[0]=b[0]=0;
        x=y=1;
        for (int i=1;i<=n;i++)
        {
            char ch;scanf("%c",&ch);
            while (ch==' ') {scanf("%c",&ch);}
            if (ch=='O') 
            {
               c[i][0]=0;
               scanf("%d",&c[i][1]);
               a[0]++;
               a[a[0]]=c[i][1];
            } else
            {
               c[i][0]=1;
               scanf("%d",&c[i][1]);
               b[0]++;
               b[b[0]]=c[i][1];
            }
        }
        int p,s,t,ans;
        s=t=1;
        ans=0;p=1;
        while (p<=n)
        {
              ans++;
              bool mark=false;
              if (s<=a[0])
              {
                 if ((a[s]==x)&&(c[p][0]==0)) {s++;mark=true;} else
                 {
                    if (a[s]>x) {x++;} else if (a[s]<x) {x--;}
                 }
              }
              
              if (t<=b[0])
              {
                 if ((b[t]==y)&&(c[p][0]==1)) {t++;mark=true;} else
                 {
                    if ( b[t]>y) {y++;} else if (b[t]<y) {y--;}
                 }
              }
              
              if (mark) {p++;}
        }
        
        printf("Case  #%d: %d\n",ttt,ans);
    }
    return 0;
}
