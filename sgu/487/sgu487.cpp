#include<stdio.h>
bool use[5000];
int a[5000],path[5000];
int n;

void work(int o)
{
    for (int i=o*4;i>=o*4-3;i--)
    if (!use[a[i]])
    {
        //path[0]++;
        //path[path[0]]=i;
        use[i]=true;

        //path[0]++;
        //path[path[0]]=a[i];
        use[a[i]]=true;
        work((a[i]+3)/4);
    }
    path[0]++;
    path[path[0]]=o;
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<2*n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        a[x]=y;a[y]=x;
    }
    for (int i=1;i<=4*n;i++) {use[i]=false;}
    path[0]=0;

    work(1);
    if (path[0]<2*n+1) {printf("NO\n");}
    else
    {
        printf("YES\n");
        for (int i=1;i<=4*n;i++) use[i]=true;
        for (int i=2;i<=path[0];i++)
        {
            for (int j=path[i]*4-3;j<=path[i]*4;j++)
            if ((use[j]&use[a[j]])&&((a[j]+3)/4==path[i-1]))
            {
                use[j]=use[a[j]]=false;
                printf("%d %d ",a[j],j);
                break;
            }
        }
    }

    return 0;
}
