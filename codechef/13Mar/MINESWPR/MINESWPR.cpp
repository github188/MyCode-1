#include<stdio.h>
#include<vector>
using namespace std;
bool used[100][100];
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={-1,0,1,1,-1,-1,0,1};
int a[100][100];
int n,m,k;
struct Neu_inf
{
    int x,y;
};

vector< Neu_inf> scan()
{
    vector< Neu_inf> Ans;Ans.clear();
    for (int i=0;i<n;i++)
     for (int j=0;j<n;j++)
      if ((used[i][j])&&(a[i][j]>0))
      {
          int num=0;
          for (int k=0;k<8;k++)
            if ((i+dx[k]>=0)&&(i+dx[k]<n)
              &&(j+dy[k]>=0)&&(j+dy[k]<n)&&(!used[i+dx[k]][j+dy[k]])) num++;
          if (num==a[i][j])
          for (int k=0;k<8;k++)
            if ((i+dx[k]>=0)&&(i+dx[k]<n)
              &&(j+dy[k]>=0)&&(j+dy[k]<n)&&(!used[i+dx[k]][j+dy[k]]))
              {
                  Neu_inf tmp;
                  tmp.x=i+dx[k];
                  tmp.y=j+dy[k];
                  Ans.push_back(tmp);
              }
      }

    return Ans;
}

int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for (int i=n-1;i>=0;i--)
      for (int j=n-1;j>=0;j--)
        if (!used[i][j])
        {
            used[i][j]=true;
            printf("S %d %d\n",i,j);
            fflush(stdout);
            char c;scanf(" %c",&c);
            if (c=='M')
            {
                m--;
                printf("N %d %d\n",i,j);
                fflush(stdout);
                for (int k=0;k<8;k++)
                if ((i+dx[k]>=0)&&(i+dx[k]<n)
                  &&(j+dy[k]>=0)&&(j+dy[k]<n)) a[i+dx[k]][j+dy[k]]--;
            } else a[i][j]+=c-'0';
            vector< Neu_inf > tmp=scan();
            for (int i=0;i<tmp.size();i++)
            if (!used[tmp[i].x][tmp[i].y])
            {
                m--;
                printf("N %d %d\n",tmp[i].x,tmp[i].y);
                used[tmp[i].x][tmp[i].y]=true;
                for (int k=0;k<8;k++)
                if ((tmp[i].x+dx[k]>=0)&&(tmp[i].x+dx[k]<n)
                  &&(tmp[i].y+dy[k]>=0)&&(tmp[i].y+dy[k]<n)) a[tmp[i].x+dx[k]][tmp[i].y+dy[k]]--;
                fflush(stdout);
            }
            if (m==0)
            {
                printf("Done\n");
                return 0;
            }
        }
    return 0;
}
