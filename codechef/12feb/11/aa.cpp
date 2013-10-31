#include<string.h>
#include<vector>
#include<iostream>
using namespace std;

int a[100][3];
class DengklekMakingChains
{
public:
int maxBeauty(vector <string> chains)
{
int n=chains.size(),ans=0;
for (int i=0;i<n;i++)
{
a[i][0]=a[i][1]=a[i][2]=-1;
string s=chains[i];
int b[3];
if (s[0]=='.') {b[0]=-1;} else {b[0]=s[0]-'0';}
if (s[1]=='.') {b[1]=-1;} else {b[1]=s[1]-'0';}
if (s[2]=='.') {b[2]=-1;} else {b[2]=s[2]-'0';}
if ((b[0]>=0)&&(b[1]>=0)&&(b[2]>=0)) a[i][2]=b[0]+b[1]+b[2];
if (b[0]>=0)
{
a[i][0]=b[0];
if (b[1]>=0) a[i][0]+=b[1];
if (b[2]>=0) a[i][0]+=b[2];
}
if (b[2]>=0)
{
a[i][1]=b[2];
if (b[1]>=0) a[i][1]+=b[1];
if (b[0]>=0) a[i][1]+=b[0];
}

int sum=-1;
if (s[1]!='.'){
for (int j=0;j<2;j++)
if (s[j]!='.')
{
if (sum<0) sum=0;
sum+=s[j]-'0';
}} else {sum=a[i][0];if (a[i][1]>sum) sum=a[i][1];}
if (sum>ans) ans=sum;
}
int sum=0,s1=0;
for (int i=0;i<n;i++)
if (a[i][2]>=0) sum+=a[i][2];
for (int i=0;i<n;i++)
if ((a[i][2]<0)&&(a[i][0]>=0))
for (int j=0;j<n;j++)
if ((i!=j)&&(a[j][2]<0)&&(a[j][1]>=0)&&(a[i][0]+a[j][1]>s1)) s1=a[i][0]+a[j][1];
for (int i=0;i<n;i++)
if ((a[i][2]<0)&&(a[i][0]>=0)&&(a[i][0]>s1)) s1=a[i][0];
for (int i=0;i<n;i++)
if ((a[i][2]<0)&&(a[i][1]>=0)&&(a[i][1]>s1)) s1=a[i][1];

if (sum+s1>ans) {ans=sum+s1;}
return ans;

}

} aa;

int main()
{
    vector<string> s;s.clear();
    s.push_back("16.");
    s.push_back("9.8");
    s.push_back(".24");
    s.push_back("52.");
    s.push_back("3.1");
    s.push_back("532");
    s.push_back("4.4");
    s.push_back("111");
    aa.maxBeauty(s);
    return 0;
}
