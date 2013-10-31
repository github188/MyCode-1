#include<stdio.h>
int t,n;
int a[1000000];

int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d",&n);
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        bool check=true;
        for (int i=n-2;i>=0;i--)
        {
            a[i]-=a[i+1];
            if (a[i]<0) {check=false;break;}
        }
        if (a[0]>0) {check=false;}
        if (check) printf("yeah~ I escaped ^_^\n");
        else printf("I will never go out T_T\n");
    }
    return 0;
}
