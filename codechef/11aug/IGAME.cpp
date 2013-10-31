#include<stdio.h>

bool a[1001][1001],b[1001][1001],c[1001][1001],d[1001][1001];

int min(int o,int p)
{
    if (o<p) {return o;}return p;
}

int main()
{
    b[0][0]=c[0][0]=d[0][0]=true;
    for (int i=0;i<=1000;i++)
     for (int j=0;j<=1000;j++)
     {
         if (i==j)
         {
             if (i==0) {a[i][j]=false;} else {a[i][j]=true;}
             continue;     
         }
         
         if (i*j==0)
         {
             a[i][j]=true;
             continue;       
         }
         
         if (b[0][j]|c[i][0]|d[i-min(i,j)][j-min(i,j)])
         {
              a[i][j]=true;
         } else
         {
              a[i][j]=false;
              b[0][j]=c[i][0]=d[i-min(i,j)][j-min(i,j)]=true;
         }
         
     }
     
    int t;scanf("%d",&t);
    while (t>0)
    {
          t--;
          int m,n,p,q;
          scanf("%d%d%d%d",&m,&n,&p,&q);
          if (a[m-p][n-q]) {printf("Alice\n");} else {printf("Bob\n");}
    } 
     
    return 0;
}
