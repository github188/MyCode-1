#include<string.h>
#include<iostream>
using namespace std;

string c[100];
int d[100],e[100];
int n,m;
double k;

int main()
{
    cin>>n>>m>>k;k=(k+0.005)*100;
    int sum=0;int kk=k;
    for (int i=0;i<n;i++)
    {
        string s;
        cin>>s>>d[i];
        d[i]=d[i]*kk;
        if (d[i]>=10000) {c[sum]=s;e[sum]=d[i]/100;sum++;}
    }
    for (int i=0;i<m;i++)
    {
        bool bo=true;
        string s;
        cin>>s;
        for (int j=0;j<sum;j++) if (c[j]==s) {bo=false;break;}
        if (bo)
        {
               c[sum]=s;e[sum]=0;
               sum++;
        }
    }
    for (int i=0;i<sum-1;i++)
     for (int j=i+1;j<=sum-1;j++)
      if (c[i]>c[j])
      {
        string s=c[i];
        c[i]=c[j];c[j]=s;
        int u=e[i];e[i]=e[j];e[j]=u;
      }
    
    cout<<sum<<endl;
    for (int i=0;i<sum;i++)
    {
        cout<<c[i]<<" "<<e[i]<<endl;
    }
    
    return 0;
}
