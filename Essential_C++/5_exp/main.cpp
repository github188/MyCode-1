#include"fib.h"
#include"sqr.h"

void print(seq *a,int p)
{
    cout<<a->what_I_am()<<" "<<a->elem(p)<<endl;
    a->printf(p+1);
}

int main()
{
    fib b;
    sqr c;
    print(&b,2);
    print(&c,9);
    return 0;
}
