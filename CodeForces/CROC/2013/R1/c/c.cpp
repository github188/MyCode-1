#include<vector>
#include<iostream>
#include<string>
using namespace std;
vector < string > vs;
int n,m;
int a[10];

inline string itos(int o)
{
    string ans="";
    while (o>0) {ans=char(o%10+48)+ans;o/=10;}
    if (ans=="") ans="0";
    return ans;
}

void judge(string s,int pos,int cur,int num,int size,string ans)
{
    if (size==0) return;
    if (cur==3)
    {
        if (size>3) return;
        if (s[pos]=='0') return;
        if ((s[pos]>'2')&&(size==3)) return;
        int tmp=0;int pp=pos,ss=size;
        while (size--) {tmp=tmp*10+s[pos++]-'0';}
        if (tmp>255) return;
        size=ss;pos=pp;
        while (size--) {ans+=s[pos++];}
        vs.push_back(ans);
        return;
    }
    if ((s[pos]=='0')&&(num==0))
    {
        //if (size-1<=(3-cur)*3)
        judge(s,pos+1,cur+1,0,size-1,ans+"0.");
    }
    //else
    {
        if ((size<=(3-cur)*3)&&(num>0)) judge(s,pos,cur+1,0,size,ans+itos(num)+".");
        if ((num*10+s[pos]-'0'<=255)&&((3-cur)<=size-1)) judge(s,pos+1,cur,num*10+s[pos]-'0',size-1,ans);
    }
}

void dfs(int o,int p,string st)
{
    if ((p==m)&&(o>=2))
    {
        string str=st;
        for (int i=st.size()-1;i>=0;i--) str+=st[i];
        judge(str,0,0,0,str.size(),"");
        if (o>2)
        {
            str=st;
            for (int i=st.size()-2;i>=0;i--) str+=st[i];
            judge(str,0,0,0,str.size(),"");
        }
    }
    if (o==6) return;
    for (int i=0;i<n;i++)
    {
        string s=" ";s[0]=char(a[i]+48);
        dfs(o+1,p|(1<<i),st+s);
    }
}

int main()
{
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    if (n>6) {cout<<0<<endl;return 0;}
    vs.clear();
    m=(1<<n)-1;
    dfs(0,0,"");
    if ((n==1)&&(a[0]==0)) {vs.push_back("0.0.0.0");}
    //judge("4444",0,0,0,4,"");
    cout<<vs.size()<<endl;
    for (int i=0;i<vs.size();i++) cout<<vs[i]<<endl;
    return 0;
}
