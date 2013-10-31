#include<stdio.h>
#include<string.h>
int ans[6],x[6][6],mat[6][6],v[6],h[7];
int len=-1;
char s[4][5000000];

int work(int len)
{
    for (int i=0;i<6;i++)
     for (int j=0;j<6;j++)
     {
         mat[i][j]=x[i][j];
         v[j]=ans[j];
     }
    for (int i=0;i<6;i++)
    {
        int j=0;
        while ((j<6)&&(mat[j][i]==0)) j++;
        if (j>=6) return -1;
        for (int k=0;k<6;k++) {if ((mat[j][k]%mat[j][i])>0) return -1;mat[j][k]/=mat[j][i];}
        if ((v[j]%mat[j][i])>0) {return -1;} else {v[j]/=mat[j][i];}
        for (int k=0;k<6;k++)
        if ((k!=j)&&(mat[k][i]!=0))
        {
            v[k]-=mat[k][i]*v[j];
            for (int l=0;l<6;l++)
            if (l!=i) mat[k][l]-=mat[j][l];
            mat[k][i]=0;
        }
    }
    for (int i=0;i<6;i++) len+=v[i];
    return len;
}

int main()
{
    memset(s,0,sizeof(s));
    for (int i=0;i<6;i++) scanf("%d",&ans[i]);
    x[0][0]=x[0][4]=x[0][5]=1;
    x[1][1]=x[1][3]=x[1][5]=1;
    x[2][2]=x[2][3]=x[2][4]=1;
    x[3][0]=x[3][1]=x[3][3]=x[3][4]=1;
    x[4][0]=x[4][2]=x[4][3]=x[4][5]=1;
    x[5][1]=x[5][2]=x[5][4]=x[5][5]=1;
    int up=ans[0];
    if (ans[1]<up) up=ans[1];
    if (ans[2]<up) up=ans[2];
    for (int i=0;i<=up;i++)
    {
        if (i!=0)
        {
            ans[0]--;
            ans[1]--;
            ans[2]--;
        }
        int tmp=work(i);
        if ((tmp!=-1)&&((len==-1)||(len>tmp)))
        {
            len=tmp;
            h[0]=i;
            for (int j=0;j<6;j++)
             for (int k=0;k<6;k++)
              if (mat[j][k]==1) h[k+1]=v[k];
        }
    }
    int u=0;
    for (int i=0;i<h[0];i++)
    {
        s[0][u+i]='a';
        s[1][u+i]='b';
        s[2][u+i]='b';
        s[3][u+i]='b';
    }
    u+=h[0];
    for (int i=0;i<h[1];i++)
    {
        s[0][u+i]='b';
        s[1][u+i]='a';
        s[2][u+i]='b';
        s[3][u+i]='b';
    }
    u+=h[1];
    for (int i=0;i<h[2];i++)
    {
        s[0][u+i]='b';
        s[1][u+i]='b';
        s[2][u+i]='a';
        s[3][u+i]='b';
    }
    u+=h[2];
    for (int i=0;i<h[3];i++)
    {
        s[0][u+i]='b';
        s[1][u+i]='b';
        s[2][u+i]='b';
        s[3][u+i]='a';
    }
    u+=h[3];
    for (int i=0;i<h[4];i++)
    {
        s[0][u+i]='a';
        s[1][u+i]='a';
        s[2][u+i]='b';
        s[3][u+i]='b';
    }
    u+=h[4];
    for (int i=0;i<h[5];i++)
    {
        s[0][u+i]='a';
        s[1][u+i]='b';
        s[2][u+i]='a';
        s[3][u+i]='b';
    }
    u+=h[5];
    for (int i=0;i<h[6];i++)
    {
        s[0][u+i]='a';
        s[1][u+i]='b';
        s[2][u+i]='b';
        s[3][u+i]='a';
    }
    u+=h[6];
    if (len==-1) {printf("-1\n");}
    else printf("%d\n%s\n%s\n%s\n%s\n",len,s[0],s[1],s[2],s[3]);
    return 0;
}
