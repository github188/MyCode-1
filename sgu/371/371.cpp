#include<stdio.h>
int n,m,num;
int a[500000][2],b[100000][2],rad[100000][2];
bool use[500000];

int main()
{
    scanf("%d%d",&n,&m);
    if ((m<n)||(n<3)) {printf("No solution\n");return 0;}
    int k=m-n+1,n1=1,m1=0,s=1;
    bool check=true;
    for (int i=0;i<k;i++)
    {
        b[i][0]=3;b[i][1]=s;

        a[s][0]=n1;
        a[s][1]=s+1;
        m1++;
        if (i!=0) a[s][0]*=-1;
        s++;

        n1++;
        a[s][0]=n1;
        a[s][1]=s+1;
        s++;
        m1++;

        n1++;
        a[s][0]=n1;
        a[s][1]=0;
        m1++;
        if (i!=k-1) a[s][0]*=-1;
        s++;
    }
    if ((n1>n)||(m1>m)) check=false;
    num=0;
    int h=0;
    while ((h<k)&&(n1<n))
    {
        if (b[h][0]==10) {h++;continue;}
        n1++;m1++;
        a[s][0]=n1;
        a[s][1]=b[h][1];
        b[h][0]++;
        b[h][1]=s;
        s++;
    }
    h=0;
    while ((n1<n)&&(h<k))
    {
        int t=b[h][1];
        while ((t!=0)&&(n1<n))
        {
            if (a[t][0]>0)
            {
                n1++;m1++;
                rad[num][0]=a[t][0];
                rad[num][1]=n1;
                num++;
            }
            t=a[t][1];
        }
        h++;
    }
    if ((n1!=n)||(m1!=m)) check=false;

    if (!check) {printf("No solution\n");return 0;}

    printf("%d\n",k);
    for (int i=0;i<k;i++)
    {
        printf("%d",b[i][0]);
        int t=b[i][1];
        while (t!=0)
        {
            if (a[t][0]<0)
            {
                a[t][0]*=-1;
            }
            printf(" %d",a[t][0]);
            t=a[t][1];
        }
        printf("\n");
    }
    printf("%d\n",num);
    for (int i=0;i<num;i++) printf("%d %d\n",rad[i][0],rad[i][1]);

    return 0;
}
