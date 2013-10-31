#include<iostream>
#include<string.h>
#include<set>
using namespace std;
string s[100],mask[100],tmp_s[100];
set<string> st;
int n,m;
bool check;
string ans;

void rotate()
{
    for (int i=0;i<n;i++) tmp_s[i].clear();
    for (int i=0;i<n;i++)
     for (int j=0;j<n;j++) tmp_s[i]+=mask[n-1-j][i];
    for (int i=0;i<n;i++)
     for (int j=0;j<n;j++) mask[i][j]=tmp_s[i][j];
}

int main()
{
    int tt,t;
    cin>>tt;
    for (int t=1;t<=tt;t++)
    {
        check=false;
        ans="";
        cin>>n;
        st.clear();
        for (int i=0;i<n;i++) cin>>s[i];
        for (int i=0;i<n;i++) cin>>mask[i];
        cin>>m;
        for (int i=0;i<m;i++)
        {
            string tmp;
            cin>>tmp;
            st.insert(tmp);
        }
        for (int i=0;i<4;i++)
        {
            string tmp="";
            for (int j=0;j<4;j++)
            {
                if (j!=0) rotate();
                for (int x=0;x<n;x++)
                  for (int y=0;y<n;y++)
                    if (mask[x][y]=='*') tmp+=s[x][y];
            }
            string t1="";
            int j=0;
            while ((j<tmp.length())&&(tmp[j]=='.')) j++;
            bool check1=true;
            while (j<tmp.length())
            {
                string s="";
                while ((j<tmp.length())&&(tmp[j]!='.')) s+=tmp[j++];
                if (st.find(s)==st.end())
                {
                    check1=false;
                    break;
                }
                t1+=s;
                while ((j<tmp.length())&&(tmp[j]=='.')) s+=tmp[j++];
                if (j<tmp.length()) t1+=' ';
            }
            if (check1)
            {
                check=true;
                if (ans.length()==0) ans=t1;
                if (t1<ans) ans=t1;
            }
        }

        cout<<"Case #"<<t<<": ";
        if (check) {cout<<ans<<endl;}
        else {cout<<"FAIL TO DECRYPT"<<endl;}
    }
    return 0;
}
