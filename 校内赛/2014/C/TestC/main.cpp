#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;

class WakingUp
{
public:
int maxSleepiness(vector <int> period, vector <int> start, vector <int> volume, int D)
{
	int n=start.size(),m=8*9*5*7;
	long long l=0,r=((long long)(1<<32)-(long long)1);
	while (l<r)
	{
		long long mid=(l+r)/(long long)2+(long long)1;
		long long s=mid;bool check=true;
		for (int i=1;i<=m;i++)
		{
			s+=(long long)D;
			for (int j=0;j<n;j++)
			if ((i>=start[j])&&((i-start[j])%period[j]==0)) s-=(long long)volume[j];
			if (s<0) {check=false;break;}
		}
		if (!check) l=mid; else r=mid-1;
	}
	if (l>=(long long)(1<<31)) return -1;
	return (int)l;
}
}a;
int main()
{
    vector<int>p,s,d;
    p.clear();s.clear();d.clear();
    p.push_back(2);
    p.push_back(3);
    s.push_back(1);
    s.push_back(2);
    d.push_back(3);
    d.push_back(4);
    printf("%d",a.maxSleepiness(p,s,d,3));
    /*freopen("c.in","w",stdout);
    printf("9\n");
    srand(time(NULL));
    for (int i=0;i<9;i++)
    {
        printf("99");
        for (int j=0;j<7;j++)
        {
            int x=rand()%1001;
            if (x==1000) printf(" 1.000"); else
            {
                printf(" 0.");
                if (x<100) printf("0");
                if (x<10) printf("0");
                printf("%d",x);
            }
        }
        printf("\n");
    }*/
    return 0;
}
