#include<stdio.h>
#include<string.h>
#include<vector>
#include<iostream>
using namespace std;

string s;
int n,k;
int a[3000];

bool check(vector<int> aa,vector<int> b)
{
    int len=s.length();
    for (int i=0;i<n;i++)
    {
        int l=i*4;
        string t[4];
        for (int j=0;j<4;j++)
        {
            t[j]="";
            int pos=a[l+j+1]-1;if (l+j+1>=4*n) pos=len-1;
            int kk=k;int ul=pos;
            while ((kk>0)&&(pos>=a[l+j]))
            {
                if ((s[pos]=='a')||(s[pos]=='e')||(s[pos]=='i')||(s[pos]=='o')||(s[pos]=='u'))
                {
                    kk--;if (kk==0) break;
                }
                pos--;
            }
            if (kk>0) return false;
            for (int l=pos;l<=ul;l++) t[j]+=s[l];
        }

        for (int j=1;j<aa.size();j++) if (t[aa[0]]!=t[aa[j]]) return false;
        for (int j=1;j<b.size();j++) if (t[b[0]]!=t[b[j]]) return false;
    }
    return true;
}

int main()
{
    scanf("%d%d",&n,&k);s="";
    for (int i=0;i<n*4;i++)
    {
        a[i]=s.length();
        string t;cin>>t;
        s+=t;
    }

    vector<int> a,b;

    a.clear();b.clear();
    a.push_back(0);
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    if (check(a,b))
    {
        printf("aaaa\n");
        return 0;
    }

    a.clear();b.clear();
    a.push_back(0);
    a.push_back(1);
    b.push_back(2);
    b.push_back(3);
    if (check(a,b))
    {
        printf("aabb\n");
        return 0;
    }

    a.clear();b.clear();
    a.push_back(0);
    a.push_back(2);
    b.push_back(1);
    b.push_back(3);
    if (check(a,b))
    {
        printf("abab\n");
        return 0;
    }

    a.clear();b.clear();
    a.push_back(0);
    a.push_back(3);
    b.push_back(2);
    b.push_back(1);
    if (check(a,b))
    {
        printf("abba\n");
        return 0;
    }
    printf("NO\n");

    return 0;
}
