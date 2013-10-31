#include<stdio.h>
int a[300][300],b[300],d[300];
int n;
bool c[300],e[300];

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    for (int j=0;j<n;j++) scanf("%d",&a[i][j]);
    for (int i=0;i<n;i++) scanf("%d",&b[i]);
    for (int i=0;i<n;i++)
    {
        bool check=true;
        for (int j=0;j<i;j++) if (b[j]<b[i]) {check=false;break;}
        c[b[i]-1]=check;
    }

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        if (a[i][j]-1<i)
        {
            int l=a[i][j];
            if (c[l-1]) {d[i]=a[i][j];break;}
        } else
        if (a[i][j]-1>i)
        {
            int l=a[i][j];bool check=true;
            for (int k=0;b[k]!=l;k++)
            if ((b[k]-1!=i)&&(b[k]<l)) {check=false;break;}
            if (check) {d[i]=a[i][j];break;}
        }
    }
    for (int i=0;i<n-1;i++) printf("%d ",d[i]);
    printf("%d\n",d[n-1]);

    return 0;
}
