#include<stdio.h>
#include<map>
#include<vector>
#include<iostream>
#include<string.h>
using namespace std;
vector<string> s1,s2;
map<string,int> m1,m2;
string st1,st2;

int work(vector<string> *s,map<string,int> *m,string &st,int l)
{
    int ans=0;s->clear();m->clear();
    int len=st.length();
    int h=0;
    while (h<len)
    {
        while ((h<len)&&((st[h]<'0')||(st[h]>'9'))) h++;
        int num=0;
        while ((h<len)&&((st[h]>='0')&&(st[h]<='9')))
        {
            num=num*10+st[h]-'0';
            h++;
        }
        ans+=num;
    }
    ans/=l;
    int kk;
    kk=s->size();
    for (int i=0;i<ans;i++) s->push_back("");
    kk=s->size();
    h=0;int k=0;
    while (h<len)
    {
        while ((h<len)&&((st[h]<'0')||(st[h]>'9'))) h++;
        int num=0;
        while ((h<len)&&((st[h]>='0')&&(st[h]<='9')))
        {
            num=num*10+st[h]-'0';
            h++;
        }
        while (num--)
        {
            (*s)[k++]+=st[h];
            if (k==ans) k=0;
        }
        h++;
    }
    for (int i=0;i<ans;i++)
    if ((*m)[(*s)[i]]==0)
    {
        (*m)[(*s)[i]]=1;
    } else (*m)[(*s)[i]]=(*m)[(*s)[i]]+1;
    return ans;
}

int main()
{
    int tt;scanf("%d",&tt);
    for (int t=1;t<=tt;t++)
    {
        int l;cin>>l;s1.clear();s2.clear();m1.clear();m2.clear();
        cin>>st1>>st2;
        int n1=work(&s1,&m1,st1,l);
        int n2=work(&s2,&m2,st2,l);
        string qq=s1[0],qq1=s2[0];
        bool check=true;
        if (n1!=n2) {check=false;} else
        {
            for (map<string,int>::iterator it=m1.begin();it!=m1.end();it++)
            {
                string s=it->first;
                if (m2[s]!=it->second) {check=false;break;}
            }
        }
        if (check) printf("Case %d: Yes\n",t); else printf("Case %d: No\n",t);
    }
    return 0;
}
