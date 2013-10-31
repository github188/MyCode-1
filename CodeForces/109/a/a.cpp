#include<stdio.h>
#include<string.h>

int a[26][2];
char s[100000],b[26][26];
    int n;char c[2];
int main()
{

    gets(s);scanf("%d",&n);gets(c);
    for (int i=0;i<n;i++)
    {
        gets(c);
        b[c[0]-'a'][c[1]-'a']=b[c[1]-'a'][c[0]-'a']=true;
    }
    for (int i=0;i<26;i++) a[i][0]=-1;
    a[s[0]-'a'][0]=0;a[s[0]-'a'][1]=0;
    int len=strlen(s);
    for (int i=1;i<len;i++)
    {
        //if (a[s[i]-'a'][0]==-1) {a[s[i]-'a'][0]=i;a[s[i]-'a'][1]=i;}
        int k=i;
        for (int j=0;j<26;j++)
        if (!b[s[i]-'a'][j])
        {
            if (a[j][1]+i-a[j][0]-1<k) k=a[j][1]+i-a[j][0]-1;
        }
        a[s[i]-'a'][0]=i;a[s[i]-'a'][1]=k;
    }
    int ans=len;
    for (int i=0;i<26;i++)
    if (a[i][0]>=0)
    {
        if (a[i][1]+len-1-a[i][0]<ans) ans=a[i][1]+len-1-a[i][0];
    }
    printf("%d\n",ans);

    return 0;
}
