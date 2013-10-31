#include<stdio.h>
int a[20];
int n,m;

int check()
{
   int ans=0;
   for (int i=0;i<n;i++) if (a[i]==0) ans++;
   return ans;
}

int ch()
{
   int ans=0;
   for (int i=0;i<n;i++) if (a[i]>ans) ans=a[i];
   return ans;
}

int abs(int o)
{
   if (o<0) o=-o;return o;
}

void work()
{
   int b[20];
   for (int i=0;i<n-1;i++) b[i]=abs(a[i+1]-a[i]);
   b[n-1]=abs(a[0]-a[n-1]);
   for (int i=0;i<n;i++) a[i]=b[i];
}

int main()
{
   int tt;
   scanf("%d",&tt);
   while (tt>0)
   {
      tt--;
      scanf("%d",&n);
      for (int i=0;i<n;i++) scanf("%d",&a[i]);
      m=2000;
      while (m>0)
      {
          m--;
          work();
      }
      m=check();
      if (m!=n) {printf("LOOP\n");}
      else {printf("ZERO\n");}
   }
   return 0;
}
