#include<iostream>
using namespace std;

int main()
{
    int n=500009;int o=0;
    for (int i=2;i<500009;i++) if ((n%i)==0) {o=i;break;}
    cout<<o<<endl;
    return 0;
}
