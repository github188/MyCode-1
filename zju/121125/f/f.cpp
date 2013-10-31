#include<stdio.h>
#include<string.h>
char s[100];
int a[100][100];

bool check1()
{
    for (int i=0;i<100;i++)
      for (int j=0;j<100;j++) if ((a[i][j]!=0)&&(a[i][j]!=2)) return false;
    return true;
}

bool check2()
{
    int s1,s2;s1=s2=0;
    if (a[1]['p'-'a']>0) {s1++;s2+=a[1]['p'-'a'];}
    if (a[9]['p'-'a']>0) {s1++;s2+=a[9]['p'-'a'];}
    if (a[1]['s'-'a']>0) {s1++;s2+=a[1]['s'-'a'];}
    if (a[9]['s'-'a']>0) {s1++;s2+=a[9]['s'-'a'];}
    if (a[1]['m'-'a']>0) {s1++;s2+=a[1]['m'-'a'];}
    if (a[9]['m'-'a']>0) {s1++;s2+=a[1]['m'-'a'];}
    for (int i=1;i<=7;i++)
    if (a[i]['z'-'a']>0) {s1++;s2+=a[i]['z'-'a'];}
    if ((s1==13)&&(s2==14)) return true;
    return false;
}

int main()
{
    while (gets(s))
    {
        memset(a,0,sizeof(a));
        int len=strlen(s);
        for (int i=0;i<len;i+=2) a[s[i]-'0'][s[i+1]-'a']++;
        bool mark=false;
        if (check1()) {mark=true;printf("Seven Pairs\n");}
        if (check2()) {mark=true;printf("Thirteen Orphans\n");}
        if (!mark) printf("Neither!\n");
    }
    return 0;
}
