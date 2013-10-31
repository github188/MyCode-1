#include<stdio.h>
long long a[1000001];
bool used[1000001];

int main()
{
    long long ans=0,n=0;
    scanf("%I64d",&n);long long nn=n;
    for (int i=19;i>=0;i--)
    if ((1<<i)<=nn)
    {
        long long k=0;
        for (long long j=(1<<i);j<=nn;j++)
        {
            k++;
            a[j]=(1<<i)-k;a[(1<<i)-k]=j;
            ans+=(j^((long long)(1<<i)-k))+(j^((long long)(1<<i)-k));
        }
        nn-=k+k;
    }
    printf("%I64d\n",ans);
    for (int i=0;i<n;i++) printf("%I64d ",a[i]);printf("%I64d\n",a[n]);
    return 0;
}
