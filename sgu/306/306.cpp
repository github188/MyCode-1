#include<stdio.h>

void out(int o)
{
    for (int i=0;i<o;i++) printf(" ");
}
int u;
void work(int l,int r,int o)
{
    if (l==r) {out(o*2);printf("fake %d\n",l);} else
    if (r-l==1)
    {
        int u=1;if (l==1) u=r+1;
        out(o*2);printf("weigh %d vs %d\n",l,u);
        out(o*2);printf("case =:\n");
        out(o*2+2);printf("fake %d\n",r);
        out(o*2);printf("case <:\n");
        out(o*2+2);printf("fake %d\n",l);
        out(o*2);printf("case >:\n");
        out(o*2+2);printf("fake %d\n",l);
        out(o*2);printf("end\n");
        return;
    } else
    {
        int u,v,w;
        w=(r-l+1)/3;
        if (((r-l+1)%3)==2) w++;
        int cw=(r-l+1)-w-w;
        out(o*2);printf ("weigh %d",l);
        for (int i=1;i<w;i++) printf("+%d",l+i);
        printf(" vs %d",l+w);
        for (int i=1;i<w;i++) printf("+%d",l+w+i);
        printf("\n");
        out(o*2);printf("case =:\n");
        work(l+w+w,r,o+1);

        out(o*2);printf("case <:\n");

            o++;
            out(o*2);printf ("weigh %d",l);
            for (int i=1;i<w;i++) printf("+%d",l+i);
            printf(" vs %d",l+w+w);
            for (int i=l+w+w+1;i<l+w+w+cw;i++) printf("+%d",i);
            printf("\n");
            out(o*2);printf("case =:\n");
            work(l+w,l+w+w-1,o+1);
            out(o*2);printf("case <:\n");
            work(l,l+w-1,o+1);
            out(o*2);printf("case >:\n");
            work(l,l+w-1,o+1);
            out(o*2);printf("end\n");
            o--;

        out(o*2);printf("case >:\n");
            o++;
            out(o*2);printf ("weigh %d",l);
            for (int i=1;i<w;i++) printf("+%d",l+i);
            printf(" vs %d",l+w+w);
            for (int i=l+w+w+1;i<l+w+w+cw;i++) printf("+%d",i);
            printf("\n");
            out(o*2);printf("case =:\n");
            work(l+w,l+w+w-1,o+1);
            out(o*2);printf("case <:\n");
            work(l,l+w-1,o+1);
            out(o*2);printf("case >:\n");
            work(l,l+w-1,o+1);
            out(o*2);printf("end\n");
            o--;

        out(o*2);printf("end\n");
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int j=0,k=1;
    while (k<2*n) {j++;k*=3;}
    printf("need %d weighings\n",j);
    work(1,n,0);
    return 0;
}
