#include<stdio.h>
#include<string.h>

int a[26];
char ch[2000];
int use[2000];

int main()
{
    gets(ch);
    int len=strlen(ch);
    if (len==1) {printf("YES\n%s\n",ch);return 0;}
    for (int i=0;i<len;i++) a[ch[i]-'a']++;
    use[1]=1;int tot=2;use[2]=1;
    for (int i=3;i<=len;i++)
    {
        bool check=true;
        for (int j=2;j<=i/2;j++)
        if ((i%j)==0) {check=false;break;}
        if (!check) {use[2]++;} else
        if ((check)&&(i*2<=len)) {use[2]++;} else {use[i]=1;tot++;}
    }
    int sym=-1;bool succ=false;
    for (int i=0;i<26;i++) if (a[i]>=use[2]) {succ=true;sym=i;break;}

    char ans[2000];memset(ans,0,sizeof(ans));
    for (int i=1;i<=len;i++)
    if ((use[i]!=1)||(i==2)) {ans[i-1]='a'+sym;a[sym]--;}
    int k=0;
    for (int i=1;i<=len;i++)
    if (ans[i-1]==0)
    {
        while ((k<26)&&(a[k]==0)) k++;
        ans[i-1]='a'+k;a[k]--;
    }

    if (!succ) {printf("NO\n");}
    else{printf("YES\n%s\n",ans);}

    return 0;
}
