#include<string.h>
#include<map>
#include<stdio.h>
#include<iostream>
using namespace std;
map < string, string > dict;
string s1[2000];
int n,m,k,tt;
char str[10000];

int main()
{
    cin>>tt;int t=0;
    while (tt--)
    {
        cin>>n>>m;
        dict.clear();
        for (int i=0;i<m;i++)
        {
            string s,t;
            cin>>s>>t;
            dict[s]=t;
        }
        int tot=0;gets(str);gets(str);
        for (int i=0;i<strlen(str);i++)
        {
            string s;s.clear();
            while ((str[i]!=' ')&&(i<strlen(str))) {s+=str[i++];}
            s1[tot++]=s;
        }

        for (int i=1;i<n;i++)
        {
            for (int j=0;j<tot;j++)
            if (dict.find(s1[j])!=dict.end()) s1[j]=dict[s1[j]];
        }
        printf("Case #%d: ",++t);
        for (int i=0;i<tot-1;i++) cout<<s1[i]<<" ";cout<<s1[tot-1]<<endl;
    }
    return 0;
}
