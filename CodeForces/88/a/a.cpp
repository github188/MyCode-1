#include<stdio.h>

int main()
{
    int n,m;
    scanf("%d%d",&n,&m);

    for (int i=0;i<n;i++)
    {
        int s,f,t;
        scanf("%d%d%d",&s,&f,&t);int tt=t/(2*m-2)*(2*m-2);
        if (s==f) {printf("%d\n",t);continue;}t=t%(2*m-2);
        int ans=0;
        if (t<=s-1)
        {
            if (f>s)
            {
                ans=tt+f-1;
            } else {ans=tt+m-1+m-f;}
        } else
        if (t<=2*m-1-s)
        {
            if (f>s)
            {
                ans=tt+2*m-2+f-1;
            } else {ans=tt+2*m-1-f;}

        } else
        {
            ans=tt+2*m-2;
            if (f>s) {ans+=f-1;} else {ans+=2*m-1-f;}
        }

        printf("%d\n",ans);
    }

    return 0;
}
