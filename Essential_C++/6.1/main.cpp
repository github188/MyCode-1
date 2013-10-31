#include"example.h"
#include<stdio.h>

int main()
{
    example<int> a(1,5);
    a.insert(6);
    example<double> b(1.9,2.4);
    printf("%d\n %.5f\n",a.max(),b.min());
    return 0;
}
