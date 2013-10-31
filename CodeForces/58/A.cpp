#include<stdio.h>
int a,b,c,d;

bool f(int b,int a)
{
     if (b-1>a) {return false;}
     if (2*b+2<a) {return false;}
     return true;
}

int main()
{
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if (f(a,d)|f(b,c)) {printf("YES\n");} else {printf("NO\n");}
    return 0;
}
