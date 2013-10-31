#include<stdio.h>
#include<string.h>

char ch[50][50];
int n,m,k,tot;
int step[40001][4],dx[4],dy[4];
bool a[50][50][4][2];

char work(int k)
{
    int u=step[k][2],v=step[k][3];
    int x,y;
    if (u==0)
    {
        if (v==0)
        {
            x=0;
            y=m-1;
        } else
        {

            x=n-1;
            y=m-1;
        }
    }
    if (u==1)
    {
        if (v==0)
        {
            x=n-1;
            y=m-1;
        } else
        {

            x=n-1;
            y=0;
        }
    }

    if (u==2)
    {
        if (v==0)
        {
            x=n-1;
            y=0;
        } else
        {

            x=0;
            y=0;
        }
    }

    if (u==3)
    {
        if (v==0)
        {
            x=0;
            y=0;
        } else
        {

            x=0;
            y=m-1;
        }
    }
    return ch[x][y];
}

int main()
{
    dx[0]=0;dy[0]=1;
    dx[1]=1;dy[1]=0;
    dx[2]=0;dy[2]=-1;
    dx[3]=-1;dy[3]=0;
    scanf("%d%d",&n,&k);gets(ch[0]);
    for (int i=0;i<n;i++)
    {
        gets(ch[i]);
        m=strlen(ch[i]);
    }

    int x,y,dp,cp;
    x=y=0;
    dp=0;
    cp=0;tot=0;
    while (!a[x][y][dp][cp])
    {
        a[x][y][dp][cp]=true;
        step[tot][0]=x;
        step[tot][1]=y;
        step[tot][2]=dp;
        step[tot][3]=cp;
        tot++;
        int nx,ny;
        nx=x+dx[dp];ny=y+dy[dp];
        if ((nx<0)||(nx>=n)||(ny<0)||(ny>=m)||(ch[nx][ny]=='0'))
        {
            if (cp==0) {cp++;}
            else
            {
                cp=0;
                dp++;
                if (dp>3) dp=0;
            }
        } else {x=nx;y=ny;}
    }
    k=k%tot;
    printf("%c\n",work(k));

    return 0;
}
