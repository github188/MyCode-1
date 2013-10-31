#include<functional>
#include<iostream>
using namespace std;
template <typename ab>

class wcw
{
    public:
    ab plus(ab a,ab b) {return a+b;}
};

int main()
{/*
    plus<int> a;
    bind2nd(a,9);
    int b=0;
    b=a(b,2)
    cout<<" "<<b<<endl;
    */
    wcw<int> a;
    cout<<a.plus(1,2)<<endl;
    return 0;
}
