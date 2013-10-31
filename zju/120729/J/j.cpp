#include<stdio.h>
#include<string.h>
int n,m;
bool use[10000001];
int stack[10000001];
int size;

int main()
{
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        memset(use,false,sizeof(use));
        size=1;
        stack[0]=0;
        use[0]=true;
        int ans=m;
        for (int i=0;i<n;i++)
        {
            int r=size;
            int b;scanf("%d",&b);

            if (ans>0) for (int j=0;j<r;j++)
            {
                int x=stack[j]+b;
                if ((x<=m)&&(!use[x]))
                {
                    use[x]=true;
                    stack[size++]=x;
                    if (m-x<ans) ans=m-x;
                    if (ans==0) break;
                }
            }
        }
        printf("%d\n",m-ans);
    }
    return 0;
}
