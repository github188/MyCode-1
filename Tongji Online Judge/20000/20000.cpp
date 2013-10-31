#include<stdio.h>

int main()
{
    long long n;
    while (scanf("%I64d",&n)!=EOF)
    {
        long long ans=0,res=1,cur=n,one=1,two=2;
        while (cur>1)
        {
            long long tmp=n/(res+one);
            if (tmp!=cur)
            {
                ans+=(cur-tmp)*(n%cur+n%(tmp+one))/two;
                cur=tmp;
                res++;
            } else
            {
                ans+=n%cur;
                cur--;
                res=n/cur;
            }
        }
        printf("%I64d\n",ans);
    }
    return 0;
}
