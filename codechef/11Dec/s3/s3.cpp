#include<stdio.h>
#include<math.h>

int main()
{
    double u,f;
    f=0;u=0;
    while (f<20)
    {
        u+=1;
        f+=1/u;
    }
    printf("%.5f\n",u);
    return 0;
}
