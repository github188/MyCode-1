#include<stdio.h>
#include<math.h>
#include<string.h>
int tt,t,n,m,d;
char ch[100];
int a[1000][1000];

bool in(double x,double y,double a,double b,double c)
{
     if ((x<a)||(x>a+c)) {return false;}
     if ((y<b)||(y>b+c)) {return false;}
     return true;
}

bool check(int len)
{
     double h1=0.5;
     double dd=d;
     for (int i=0;i<=n-len;i++)
      for (int j=0;j<=m-len;j++)
      {
          double sum,ax,ay;
          sum=ax=ay=0;
          for (int k=i;k<i+len;k++)
           for (int l=j;l<j+len;l++)
            {
                double u=a[k][l];u+=dd;
                sum+=u;double x,y;x=k;y=l;x+=h1;y+=h1;
                ax+=u*x;
                ay+=u*y;
            }
         double xx,yy,uu;
         sum=sum-a[i][j]-dd;xx=i;yy=j;xx+=h1;yy+=h1;uu=a[i][j]+dd;ax-=xx*uu;ay-=yy*uu;
         sum=sum-a[i][j+len-1]-dd;xx=i;yy=j+len-1;xx+=h1;yy+=h1;uu=a[i][j+len-1]+dd;ax-=xx*uu;ay-=yy*uu;
         sum=sum-a[i+len-1][j]-dd;xx=i+len-1;yy=j;xx+=h1;yy+=h1;uu=a[i+len-1][j]+dd;ax-=xx*uu;ay-=yy*uu;
         sum=sum-a[i+len-1][j+len-1]-dd;xx=i+len-1;yy=j+len-1;xx+=h1;yy+=h1;uu=a[i+len-1][j+len-1]+dd;ax-=xx*uu;ay-=yy*uu;
            
         double x1,y1;
         x1=ax/sum;y1=ay/sum;
         double ll=len;double x2,y2;ll/=2;
         x2=i;y2=j;x2+=ll;y2+=ll;
         if ((x2==x1)&&(y2==y1)) {return true;}   
       }
      return false;
}

int main()
{
    freopen("B-small-attempt1.in","r",stdin);
    freopen("B-small-attempt1.out","w",stdout);
    scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        scanf("%d%d%d",&n,&m,&d);
        gets(ch);
        for (int i=0;i<n;i++)
        {
            gets(ch);
            for (int j=0;j<m;j++) {a[i][j]=ch[j]-'0';}
        }
        
        int ans=0;
        int lim=n;if (m<n) {lim=m;}
        for (int i=3;i<=lim;i++)
        if (check(i)) {ans=i;}
        printf("Case #%d: ",t);
        if (ans==0) {printf("IMPOSSIBLE\n");}else {printf("%d\n",ans);}
    }
    return 0;
}
