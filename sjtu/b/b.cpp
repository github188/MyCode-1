#include<stdio.h>
#include<iostream>
using namespace std;
long long a,b;
long long c;
int main()
{
    while (cin>>a>>b>>c)
    {
        long long ans=a*b;
        if (a>b) {long long tmp=a;a=b;b=tmp;}
        if ((c==0)||(c==a*b)) ans=0;
        long long p=0;
        p=a;if (c%a>0) p++;
        ans=ans<p?ans:p;
        p=b;if (c%b>0) p++;
        ans=ans<p?ans:p;long long i=0;long long one=1;
        do{i++;
        if (((i<=a)&&(c/i+one-(long long)(c%i==0)<=b))||((i+one-(long long)(c%i==0)<=a)&&(c/i<=b)))
        {
            p=i+c/i+one-(long long)(c%i==0)+(long long)(c%i!=0);ans=ans<p?ans:p;
        }
            if ((c%i!=0)&&(((c%i<=b)&&(i+one<=a)&&(c/i<=b))||((c%i<=a)&&(i+one<=b)&&(c/i<=a))))
            {
                p=i+c/i+one;ans=ans<p?ans:p;

            }
        } while (i*i<=c);

        cout<<ans<<endl;
    }
    return 0;
}
