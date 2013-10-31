#include<stdio.h>
#include<string.h>
long long f[100][4];
char s[100];
int a[100];

int work(int o,int p)
{
   if (o==0)
   {
      if (p==1) return 2;
      return 1;
   }
   if (o==1)
   {
      if (p==0) return 2;
      return 0;
   }
   if (o==2)
   {
      if (p==1) return 0;
      return 1;
   }

}

int main()
{
  gets(s);
  while (s[0]!='X')
  {
     int n=strlen(s);
     f[0][0]=f[0][1]=f[0][2]=1;
     f[0][s[0]-'A']--;
     for (int i=1;i<n;i++)
       for (int j=0;j<3;j++)
         if (s[i]-'A'==j) {f[i][j]=f[i-1][j];}
         else
         {
             long long one = 1;
             long long tmp=(one<<(i));
             //tmp++;
             f[i][j]=f[i-1][work(s[i]-'A',j)]+tmp;
         }
     printf("%I64d\n",f[n-1][1]);
     gets(s);
  }
  return 0;
}
