#include<stdio.h>
#include<string.h>
char s[100];
int n,m,i,j,k,l;
int a[6];
bool f[50000];
int b[6];
int d[6];

void check()
{
     int c[6];
     c[0]=5;
     c[1]=3;
     c[2]=4;
     c[3]=1;
     c[4]=2;
     c[5]=0;
     int ans=1000000;
     for (int i=0;i<6;i++)
     {
         
         for (int j=0;j<6;j++)
          if ((j!=i)&&(j!=c[i]))
          {
                                
              int sum=0;
              sum=b[i]*d[5]+b[c[i]];
              
              int k,l;k=0;l=j;
              while (k<4)
              {
                    if ((l!=i)&&(l!=c[i]))
                    {
                       k++;
                       sum+=d[k]*b[l];
                    }
                    l++;
                    if (l>5) {l=0;}
              }           
              
              if (sum<ans) 
              {
                      ans=sum;
              }
          }       
     }
         
     f[ans]=true;
}

void work(int o)
{
     if (o==6) {check();}
     else
     {
         for (int i=0;i<6;i++)
         if (a[i]>0)
         {
             b[o]=i;
             a[i]--;
             work(o+1);
             a[i]++;
         }
     }
}

int main()
{
    gets(s);
    d[0]=1;
    for (int i=1;i<6;i++) {d[i]=d[i-1]*6;}
    for (int i=0;i<6;i++)
    {
        if (s[i]=='R') {a[0]++;}
        if (s[i]=='O') {a[1]++;}
        if (s[i]=='Y') {a[2]++;}
        if (s[i]=='G') {a[3]++;}
        if (s[i]=='B') {a[4]++;}
        if (s[i]=='V') {a[5]++;}
    }
    work(0);
    
    int ans=0;
    for (int i=0;i<50000;i++) {if (f[i]) {ans++;}}
    printf("%d\n",ans);
    
    return 0;
}
