#include<stdio.h>
#include<string.h>
int main()
{
	int n;
	while(true)
	{
	    scanf("%d",&n);
	    if (n==0) break;
	    int a[101];
	    for (int i=0;i<101;i++) a[i]=0;
		for(int i=0;i<n;i++)
		{
		    int x;scanf("%d",&x);
		    a[x]++;
		}
		int ans=0;
		for(int i=0;i<101;i++) if(a[i]%2==1) ans=1;
		if (ans) printf("Win\n");
		else printf("Lose\n");
	}
	return 0;
}
