#include<stdio.h>

int main()
{
    int a[2500];a[0]=0;
    for (int i=2;i<=2500;i++)
    {
        bool check=true;
        for (int j=2;j*j<=i;j++) if (i%j==0) check=false;
        if (check) a[++a[0]]=i;
    }
    int t;scanf("%d",&t);
    while (t--)
    {
        int x,y;scanf("%d%d",&x,&y); x+=y;
        int l=1,r=a[0];
        while (l<r)
        {
            int mid=(l+r)/2;
            if (a[mid]>x) r=mid; else l=mid+1;
        }
        printf("%d\n",a[l]-x);
    }
    return 0;
}
