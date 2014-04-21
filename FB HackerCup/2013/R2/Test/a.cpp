#include<stdlib.h>
#include<algorithm>
#include<stdio.h>
#include<iostream>
using namespace std;
class A{public: A(){a=2;}A(int a){a=1;}  int a;};

int main()
{
    A a(3);
    cout<<a.a;
    return 0;
}
