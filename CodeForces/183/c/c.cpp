#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

int a[5000];
int n,k;
int f[1000001];

int main()
{
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    std::sort(a,a+n);
    int m=n-k+1;if (m<1) m=1;
    int i=0;int kk=k;
    while (true)
    {
        int sum=0;
        bool check=true;
        while (i<n)
        {
            while (sum+m<=a[i]) sum+=m;
            if (f[a[i]-sum]==0) f[a[i]-sum]++; else
            {
                f[a[i]-sum]++;
                kk--;
                if (kk<0) {check=false;break;}
            }
            i++;
        }
        if (check) break;
        if (i>=n-1) i=n;
        while (i>0)
        {
            i--;
            if (a[i]<m) {i++;break;}
            while (sum>a[i]) sum-=m;
            f[a[i]-sum]--;
            if (f[a[i]-sum]>0) kk++;
        }
        m++;
    }
    printf("%d\n",m);
    return 0;
}
