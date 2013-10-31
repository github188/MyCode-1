#include<stdio.h>

char c[4][200];

int main()
{
    int n;
    scanf("%d",&n);
    if (n==1) {for (int i=0;i<2;i++) {printf("a\n");}for (int i=0;i<2;i++) {printf("b\n");}} else
    if ((n&1)==0)
    {
         if (n==2)
         {
            for (int i=0;i<4;i++) { c[i][0]=c[i][1]='a'+i; }
         } else
         {
            int l=0;   
            for (int i=0;i<n;i+=2)
            {
                c[0][i]=c[0][i+1]='a'+l;
                c[3][i]=c[3][i+1]='g'+l;
                l=(l^1);
            }
            l=0;
            c[1][0]=c[2][0]='x';
            c[1][n-1]=c[2][n-1]='y';
            for (int i=1;i<n-1;i+=2)
            {
                c[1][i]=c[1][i+1]='c'+l;
                c[2][i]=c[2][i+1]='e'+l;
                l=(l^1);
            }
               
         }        
    } else
    {
          c[0][n-1]=c[1][n-1]='x';
          c[2][0]=c[3][0]='y';
          int l=0;
          for (int i=0;i<n-1;i+=2)
          {
              c[0][i]=c[0][i+1]='a'+l;
              c[1][i]=c[1][i+1]='c'+l;
              l=(l^1);
          }
          l=0;
          for (int i=1;i<n;i+=2)
          {
              c[2][i]=c[2][i+1]='e'+l;
              c[3][i]=c[3][i+1]='g'+l;
              l=(l^1);
          }
    }
    for (int i=0;i<4;i++)
    {
        
        printf("%s\n",c[i]);
    }
    
    return 0;
}
