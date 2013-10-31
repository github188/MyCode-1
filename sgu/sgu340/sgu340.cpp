#include<iostream>
#include<string.h>
#include<stack>
using namespace std;

stack<int> a;

int main()
{
    string s,t;
    while (cin>>s)
    {
        a.empty();
        t="";t+=s;
        if ((s.length()==2)&&(s[0]==s[1])) {cout<<endl;continue;}
        if ((s[s.length()-1]!='$')||(s.length()==1))
        do
        {
            cin>>s;
            t+=s;
        } while (s[s.length()-1]!='$');

        int len=t.length()-1,h=1;
        s=t;
        while (h<len)
        {
            if ((s[h]=='+')||(s[h]=='-')||(s[h]=='*')||(s[h]=='/'))
            {
                cout<<"&nbsp;"<<s[h]<<"&nbsp;";
                h++;
            } else
            if (((s[h]>='A')&&(s[h]<='Z'))||((s[h]>='a')&&(s[h]<='z')))
            {
                cout<<"<i>";
                while ((h<len)&&(((s[h]>='A')&&(s[h]<='Z'))||((s[h]>='a')&&(s[h]<='z'))))
                {
                    cout<<s[h];
                    h++;
                }
                cout<<"</i>";
            } else
            if ((s[h]=='}')&&(a.size()>0))
            {
                int u=a.top();
                a.pop();
                if (u==0) {cout<<"</sub>";}
                else {cout<<"</sup>";}
                h++;
            } else
            if (s[h]=='_')
            {
                cout<<"<sub>";h++;
                if (s[h]=='{')
                {
                    h++;
                    a.push(0);
                } else
                {
                    if ((s[h]>='0')&&(s[h]<='9'))
                    {
                                        while ((h<len)&&((s[h]>='0')&&(s[h]<='9')))
                                        {
                                            cout<<s[h];
                                            h++;
                                        }
                    }
                    else
                    {
                                        cout<<"<i>";
                                        while ((h<len)&&(((s[h]>='A')&&(s[h]<='Z'))||((s[h]>='a')&&(s[h]<='z'))))
                                        {
                                            cout<<s[h];
                                            h++;
                                        }
                                        cout<<"</i>";
                    }
                    cout<<"</sub>";
                }
            } else
            if (s[h]=='^')
            {
                cout<<"<sup>";h++;
                if (s[h]=='{')
                {
                    h++;
                    a.push(1);
                } else
                {
                    if ((s[h]>='0')&&(s[h]<='9'))
                    {
                                        while ((h<len)&&((s[h]>='0')&&(s[h]<='9')))
                                        {
                                            cout<<s[h];
                                            h++;
                                        }
                    }
                    else
                    {
                                        cout<<"<i>";
                                        while ((h<len)&&(((s[h]>='A')&&(s[h]<='Z'))||((s[h]>='a')&&(s[h]<='z'))))
                                        {
                                            cout<<s[h];
                                            h++;
                                        }
                                        cout<<"</i>";
                    }
                    cout<<"</sup>";
                }
            } else {cout<<s[h];h++;}
        }
        cout<<endl;
    }
    return 0;
}
