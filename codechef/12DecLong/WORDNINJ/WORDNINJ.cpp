#include<stdio.h>
#include<string.h>
char s[1000000];
int n,m;

int main()
{
  scanf("%d",&n);gets(s);
  for (int i=0;i<n;i++) gets(s);
  scanf("%d",&m);
  //for (int i=0;i<m;i++) gets(s);
  for (int i=0;i<m;i++) printf("Take A\n");
  printf("Play AA\n");
  return 0;
}
