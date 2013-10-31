#include<stdio.h>
bool prime[1000001];
long long num[200][2],list[1000000],tnum[200][2];
int size=0,tsize=0;

inline void work(long long num[][2],long long nn,int &size)
{
 //   nn=n;
    for (int i=1;i<=list[0];i++)
    {
        long long tmp=list[i];
        if ((nn%tmp)==0)
        {
            num[size][0]=list[i];
            num[size][1]=0;
            while ((nn%tmp)==0)
            {
                num[size][1]++;
                nn/=tmp;
            }
            size++;
        }
        if (tmp*tmp>nn) break;
        if (nn==0)break;
    }
    if (nn>1)
    {
        num[size][0]=nn;
        num[size][1]=1;
        size++;
    }
}


inline void work1(long long tnum[][2],long long nn,int &tsize)
{
 //   nn=n;
    for (int i=0;i<size;i++)
    {
        long long tmp=num[i][0];
        if ((nn%tmp)==0)
        {
            tnum[tsize][0]=tmp;
            tnum[tsize][1]=0;
            while ((nn%tmp)==0)
            {
                tnum[tsize][1]++;
                nn/=tmp;
            }
            tsize++;
        }
        if (tmp*tmp>nn) break;
        if (nn==0)break;
    }
    if (nn>1)
    {
        tnum[tsize][0]=nn;
        tnum[tsize][1]=1;
        tsize++;
    }
}


long long gcd(long long o,long long p)
{
    if (p==0) return o;
    return gcd(p,o%p);
}

inline long long euler(long long num[][2],int size)
{
    long long ans=1,one=1,tmp=0;
    for (int i=0;i<size;i++)
    {
        tmp=num[i][1]+one;
        ans*=tmp;
    }
    return ans;
}

int main()
{
    for (int i=2;i<=1000000;i++)
    if (!prime[i])
    {
        list[++list[0]]=i;
        int j=i+i;
        while (j<=1000000)
        {
            prime[j]=true;
            j+=i;
        }
    }
    long long n,nn;int tt;
    scanf("%lld%d",&n,&tt);
    work(num,n,size);
    long long neu=euler(num,size);

    while (tt>0)
    {
        tt--;
        int t;long long k;
        scanf("%d%lld",&t,&k);
        if (t==1)
        {
            if (n==k) {printf("%lld\n",neu);continue;}
            long long tmp=gcd(n,k);
            tsize=0;
            work1(tnum,tmp,tsize);
            printf("%lld\n",euler(tnum,tsize));
        }
        if (t==2)
        {
            if (n==k) {printf("1\n");continue;}
            long long tmp=0;
            if (n<k) {tmp=0;} else
            if ((n%k)==0)
            {
                tsize=0;
                long long tmp1=n/k;
                work1(tnum,tmp1,tsize);
                tmp=euler(tnum,tsize);
            }
            printf("%lld\n",tmp);
        }
        if (t==3)
        {
            long long tmp=0;
            if (n==k) {tmp=1;} else
            if (n<k) {tmp=0;}
            if ((n%k)==0)
            {
                tsize=0;
                long long tmp1=n/k;
                work1(tnum,tmp1,tsize);
                tmp=euler(tnum,tsize);
            }
            long long ans=neu-tmp;
            printf("%lld\n",ans);
        }
    }
    return 0;
}
