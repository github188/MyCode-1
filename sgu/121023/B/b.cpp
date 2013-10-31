#include<stdio.h>

int n,d,h,t;
int a[200000][2],b[200000][2];

int main()
{
    scanf("%d%d",&n,&d);
    h=0;t=-1;
    for (int i=0;i<n;i++) {scanf("%d%d",&a[i][0],&a[i][1]);}
    for (int i=n-1;i>=0;i--)
    if ((t<0)||(a[i][1]>b[t][1])) {b[++t][0]=i;b[t][1]=a[i][1];}
    int ans=0,u=-1,v=-1;
    for (int i=0;i<n;i++)
    {
        while ((t>=0)&&(a[i][0]+d>a[b[t][0]][0])) {t--;}
        if (t<0) break;
        if (ans<a[i][1]+b[t][1])
        {
            ans=a[i][1]+b[t][1];
            u=i+1;
            v=b[t][0]+1;
        }
    }
    printf("%d %d\n",u,v);

    return 0;
}
