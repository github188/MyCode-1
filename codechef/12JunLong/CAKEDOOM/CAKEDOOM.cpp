#include<stdio.h>
#include<string.h>
char s[200],ss[200];

bool check(char s[],int k)
{
    int j=0;
    int n=strlen(s);
    while (j<n)
    {
        while ((j<n)&&(s[j]!='?')) j++;
        if (j>=n) break;
        int l=j;
        while ((l+1<n)&&(s[l+1]=='?')) l++;
        if ((k==2)&&(((s[j-1]!=s[l+1])&&(((l-j+1)&1)==1))||((s[j-1]==s[l+1])&&(((l-j+1)&1)==0)))) return false;
        if (s[j-1]=='0') {s[j]='1';} else {s[j]='0';}
        for (int u=j+1;u<=l;u++) s[u]=((s[u-1]-'0')^1)+'0';
        while ((s[l]==s[l-1])||(s[l]==s[l+1])) {s[l]++;}
        j=l+1;
    }
    return true;
}

bool work(int k)
{
   int n=strlen(s);
   if (n==1)
   {
       if (s[0]=='?') s[0]='0';
       return true;
   }

   for (int i=1;i<n;i++) if ((s[i]!='?')&&(s[i]==s[i-1])) return false;
   int tmp=0;
   if ((s[0]!='?')&&(s[n-1]==s[0])) return false;
   for (int i=0;i<n;i++) if (s[i]!='?') tmp++;
   if (tmp==n) return true;
   if (k==1) return false;

   int h=0;
   while ((h<n)&&(s[h]=='?')) h++;
   if (h==n)
   {
     if (n==1) {s[0]='0';s[n]=0;return true;}
     if (k==1) {return false;}
     if ((k==2)&&((n&1)==1)) return false;
     for (int i=0;i<n;i++) {s[i]='0'+(i&1);}
     if (s[n-1]==s[0]) s[n-1]='2';
     s[n]=0;
     return true;
   }

   if (s[0]=='?')
   {
       for (int i=0;i<k;i++)
       if ((s[n-1]!='0'+i)&&(s[1]!='0'+i))
       {
           for (int j=0;j<n;j++) ss[j]=s[j];
           ss[0]=ss[n]='0'+i;
           ss[n+1]=0;
           if (check(ss,k))
           {
               for (int j=0;j<n;j++) s[j]=ss[j];
               return true;
           }
       }
   } else
    {
        for (int j=0;j<n;j++) ss[j]=s[j];
        ss[0]=ss[n]=s[0];
        ss[n+1]=0;
        if (check(ss,k))
        {
            for (int j=0;j<n;j++) s[j]=ss[j];
            return true;
        }
    }

   return false;
}

int main()
{
  int tt;
  scanf("%d",&tt);
  while (tt>0)
  {
    tt--;
    int k;scanf("%d",&k);gets(s);gets(s);
    int i=0,n=strlen(s);
    if (!work(k)) {printf("NO\n");} else {printf("%s\n",s);}
  }
  return 0;
}
