#include<stdio.h>
int a[10],b[10][90][30][20][10][10],c[2][10],d[10],e[5],f[100][5];
int tot;

int judge(int ans,int n)
{
    if (n==1) return 0;
    n--;
    int p=1,s=0;
    while (ans!=0)
    {
        int k=(ans%10);
        if (k!=0) p*=k;
        s+=k;
        ans/=10;
    }
    for (int i=1;i<=9;i++)
    {
        int u=p*i,v=s+i;
        if ((u%v)==0) n--;
        if (n==0) return i;
    }
}

int work(int n)
{
    int m=9,ans=0;
    while (a[m]>=n) m--;
    n-=a[m];
    e[0]=e[1]=e[2]=e[3]=e[4]=0;
    bool sw=false;
    if (m==9)
    {
        ans+=d[9];
        e[0]=1;
        sw=true;
    } else {m++;}
    while (m>0)
    {
        if (m==1) {ans+=judge(ans,n);break;}
        if (!sw) {sw=true;}
        else
        {
            if (d[m-1]<n) {n-=d[m-1];} else {ans+=n-1;break;}
        }

        for (int i=1;i<=9;i++)
        {
            int sum=c[0][m-1];

            e[0]+=i;
            if (i==2) e[1]++;
            if (i==3) e[2]++;
            if (i==4) e[1]+=2;
            if (i==5) e[3]++;
            if (i==6) {e[1]++;e[2]++;}
            if (i==7) e[4]++;
            if (i==8) e[1]+=3;
            if (i==9) e[2]+=2;

            for (int i=0;i<tot;i++)
            if (f[i][0]>=m-1+e[0])
            {
                int tmp[5];
                for (int j=1;j<=4;j++) {tmp[j]=f[i][j]-e[j];if (tmp[j]<0) tmp[j]=0;}
                sum+=b[m-1][f[i][0]-e[0]][tmp[1]][tmp[2]][tmp[3]][tmp[4]];
            }

            if (n<=sum)
            {
                ans+=d[m-1]*i;
                break;
            } else {n-=sum;}

            e[0]-=i;
            if (i==2) e[1]--;
            if (i==3) e[2]--;
            if (i==4) e[1]-=2;
            if (i==5) e[3]--;
            if (i==6) {e[1]--;e[2]--;}
            if (i==7) e[4]--;
            if (i==8) e[1]-=3;
            if (i==9) e[2]-=2;
        }
        m--;
    }
    return ans;
}

int main()
{
    a[1]=9;
    a[2]=24;
    a[3]=333;
    a[4]=4008;
    a[5]=47470;
    a[6]=534357;
    a[7]=5845531;
    a[8]=62955906;
    a[9]=670349658;
    b[1][1][0][0][0][0]=1;
    b[1][2][1][0][0][0]=1;
    b[1][3][0][1][0][0]=1;
    b[1][4][2][0][0][0]=1;
    b[1][5][0][0][1][0]=1;
    b[1][6][1][1][0][0]=1;
    b[1][7][0][0][0][1]=1;
    b[1][8][3][0][0][0]=1;
    b[1][9][0][2][0][0]=1;
    for (int i=2;i<=9;i++)
     for (int j=1;j<=9;j++)
     {
      for (int a1=0;a1<=3*i;a1++)
       for (int a2=0;a2<=2*i;a2++)
        for (int a3=0;a3<=i;a3++)
         for (int a4=0;a4<=i;a4++)
          for (int k=0;k<=(i-1)*9;k++)
          {
              if (j==1) b[i][k+1][a1][a2][a3][a4]+=b[i-1][k][a1][a2][a3][a4];
              if (j==2) b[i][k+2][a1+1][a2][a3][a4]+=b[i-1][k][a1][a2][a3][a4];
              if (j==3) b[i][k+3][a1][a2+1][a3][a4]+=b[i-1][k][a1][a2][a3][a4];
              if (j==4) b[i][k+4][a1+2][a2][a3][a4]+=b[i-1][k][a1][a2][a3][a4];
              if (j==5) b[i][k+5][a1][a2][a3+1][a4]+=b[i-1][k][a1][a2][a3][a4];
              if (j==6) b[i][k+6][a1+1][a2+1][a3][a4]+=b[i-1][k][a1][a2][a3][a4];
              if (j==7) b[i][k+7][a1][a2][a3][a4+1]+=b[i-1][k][a1][a2][a3][a4];
              if (j==8) b[i][k+8][a1+3][a2][a3][a4]+=b[i-1][k][a1][a2][a3][a4];
              if (j==9) b[i][k+9][a1][a2+2][a3][a4]+=b[i-1][k][a1][a2][a3][a4];
          }
     }
    for (int i=1;i<=9;i++)
     {
      for (int a1=3*i;a1>=0;a1--)
       for (int a2=2*i;a2>=0;a2--)
        for (int a3=i;a3>=0;a3--)
         for (int a4=i;a4>=0;a4--)
          for (int k=0;k<=i*9;k++)
          {
              if (a1<3*i) b[i][k][a1][a2][a3][a4]+=b[i][k][a1+1][a2][a3][a4];
              if (a2<2*i) b[i][k][a1][a2][a3][a4]+=b[i][k][a1][a2+1][a3][a4];
              if (a3<i) b[i][k][a1][a2][a3][a4]+=b[i][k][a1][a2][a3+1][a4];
              if (a4<i) b[i][k][a1][a2][a3][a4]+=b[i][k][a1][a2][a3][a4+1];
              if ((a1<3*i)&&(a2<2*i)) b[i][k][a1][a2][a3][a4]-=b[i][k][a1+1][a2+1][a3][a4];
              if ((a1<3*i)&&(a3<i)) b[i][k][a1][a2][a3][a4]-=b[i][k][a1+1][a2][a3+1][a4];
              if ((a1<3*i)&&(a4<i)) b[i][k][a1][a2][a3][a4]-=b[i][k][a1+1][a2][a3][a4+1];
              if ((a2<2*i)&&(a3<i)) b[i][k][a1][a2][a3][a4]-=b[i][k][a1][a2+1][a3+1][a4];
              if ((a2<2*i)&&(a4<i)) b[i][k][a1][a2][a3][a4]-=b[i][k][a1][a2+1][a3][a4+1];
              if ((a3<i)&&(a4<i)) b[i][k][a1][a2][a3][a4]-=b[i][k][a1][a2][a3+1][a4+1];
              if ((a1<3*i)&&(a2<2*i)&&(a3<i)) b[i][k][a1][a2][a3][a4]+=b[i][k][a1+1][a2+1][a3+1][a4];
              if ((a1<3*i)&&(a2<2*i)&&(a4<i)) b[i][k][a1][a2][a3][a4]+=b[i][k][a1+1][a2+1][a3][a4+1];
              if ((a1<3*i)&&(a3<i)&&(a4<i)) b[i][k][a1][a2][a3][a4]+=b[i][k][a1+1][a2][a3+1][a4+1];
              if ((a2<2*i)&&(a3<i)&&(a4<i)) b[i][k][a1][a2][a3][a4]+=b[i][k][a1][a2+1][a3+1][a4+1];
              if ((a1<3*i)&&(a2<2*i)&&(a3<i)&&(a4<i)) b[i][k][a1][a2][a3][a4]-=b[i][k][a1+1][a2+1][a3+1][a4+1];
          }
     }
     d[1]=10;d[0]=1;
     for (int i=2;i<=9;i++) d[i]=d[i-1]*10;
     c[0][1]=1;c[1][1]=9;
     for (int i=2;i<=9;i++)
     {
         c[1][i]=c[1][i-1]*9;
         c[0][i]=d[i]-c[1][i];
     }

    tot=1;f[0][0]=1;f[0][1]=f[0][2]=f[0][3]=f[0][4]=0;
    for (int i=2;i<=90;i++)
    {
        int j=i;
        f[tot][0]=f[tot][1]=f[tot][2]=f[tot][3]=f[tot][4]=0;
        while ((j%2)==0)
        {
            f[tot][1]++;
            j/=2;
        }
        while ((j%3)==0)
        {
            f[tot][2]++;
            j/=3;
        }
        while ((j%5)==0)
        {
            f[tot][3]++;
            j/=5;
        }
        while ((j%7)==0)
        {
            f[tot][4]++;
            j/=7;
        }
        if (j==1) {f[tot][0]=i;tot++;}
    }

    while (true)
    {
        int n;
        scanf("%d",&n);
        if (n==0) break;
        if (n<10) {printf("%d\n",n);} else {printf("%d\n",work(n));}
    }

    return 0;
}
