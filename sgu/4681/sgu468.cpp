#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;

struct p
{
    int x,y,z;
};

bool fun1[300];
int ans[300][300],nb[300][300],b[300][300][8][2],a[300][300],v[8][2],d[300][300];
p arr[300][300][10];
int stack[100000][4];
int n,tot,nn;
bool succ;
int limit=7000000;

bool cmp(p a,p b)
{
    if (a.z<b.z) return true;
    if (fun1[n]) {
    if ((a.z==b.z)&&(a.x+a.y<b.x+b.y)) return true;} else {
    if ((a.z==b.z)&&(a.x+a.y>b.x+b.y)) return true;}
    return false;
}

/*
void work(int x,int y,int z)
{
    tot++;
    if (tot>limit) return;
    ans[x][y]=z;
    if (z==nn) {succ=true;return;}
    for (int i=0;i<nb[x][y];i++)
    {
        int xx=b[x][y][i][0],yy=b[x][y][i][1];
        a[xx][yy]--;
    }

    d[x][y]=0;
    for (int i=0;i<nb[x][y];i++)
    {
        int xx=b[x][y][i][0],yy=b[x][y][i][1];
        if ((ans[xx][yy]==-1))
        {
            arr[x][y][d[x][y]].x=xx;
            arr[x][y][d[x][y]].y=yy;
            arr[x][y][d[x][y]].z=a[xx][yy];
            d[x][y]++;
        }
    }
    sort(arr[x][y],arr[x][y]+d[x][y],cmp);
    if (!((arr[x][y][0].z==0)&&(z!=nn-1)))
    {
        for (int i=0;i<d[x][y];i++)
        {
            work(arr[x][y][i].x,arr[x][y][i].y,z+1);
            if ((succ)||(tot>limit)) return;
        }
    }

    ans[x][y]=-1;
    for (int i=0;i<nb[x][y];i++)
    {
        int xx=b[x][y][i][0],yy=b[x][y][i][1];
        a[xx][yy]++;
    }
}
*/

void work()
{
    int top=0;
    stack[0][0]=0;stack[0][1]=0;stack[0][2]=1;stack[0][3]=-1;
    while (top>=0)
    {
      int x=stack[top][0],y=stack[top][1],z=stack[top][2],dl=stack[top][3];
      if (dl==-1)
      {
         top--;
         tot++;
         if (tot>limit) return;
         ans[x][y]=z;
         if (z==nn) {succ=true;return;}
         for (int i=0;i<nb[x][y];i++)
         {
           int xx=b[x][y][i][0],yy=b[x][y][i][1];
           a[xx][yy]--;
         }

         d[x][y]=0;
         for (int i=0;i<nb[x][y];i++)
         {
           int xx=b[x][y][i][0],yy=b[x][y][i][1];
           if ((ans[xx][yy]==-1))
           {
             arr[x][y][d[x][y]].x=xx;
             arr[x][y][d[x][y]].y=yy;
             arr[x][y][d[x][y]].z=a[xx][yy];
             d[x][y]++;
           }
          }
          sort(arr[x][y],arr[x][y]+d[x][y],cmp);
          if (!((arr[x][y][0].z==0)&&(z!=nn-1))) {
          top++;
          stack[top][0]=x;
          stack[top][1]=y;
          stack[top][2]=z;
          stack[top][3]=0;}
      } else
      if (dl<d[x][y])
      {
         stack[top][3]++;
         top++;
         stack[top][0]=arr[x][y][dl].x;
         stack[top][1]=arr[x][y][dl].y;
         stack[top][2]=z+1;
         stack[top][3]=-1;
      } else
      {
         ans[x][y]=-1;
         for (int i=0;i<nb[x][y];i++)
         {
           int xx=b[x][y][i][0],yy=b[x][y][i][1];
           a[xx][yy]++;
         }
         top--;
      }

    }
}

int main()
{
    v[0][0]=-2;v[0][1]=-1;
    v[1][0]=-2;v[1][1]=1;
    v[2][0]=2;v[2][1]=-1;
    v[3][0]=2;v[3][1]=1;
    v[4][0]=-1;v[4][1]=-2;
    v[5][0]=-1;v[5][1]=2;
    v[6][0]=1;v[6][1]=-2;
    v[7][0]=1;v[7][1]=2;
    fun1[5]=true;
fun1[6]=true;
fun1[8]=true;
fun1[9]=true;
fun1[10]=true;
fun1[11]=true;
fun1[12]=true;
fun1[13]=true;
fun1[14]=true;
fun1[15]=true;
fun1[16]=true;
fun1[17]=true;
fun1[18]=true;
fun1[19]=true;
fun1[20]=true;
fun1[21]=true;
fun1[23]=true;
fun1[24]=true;
fun1[25]=true;
fun1[26]=true;
fun1[27]=true;
fun1[28]=true;
fun1[29]=true;
fun1[30]=true;
fun1[31]=true;
fun1[32]=true;
fun1[33]=true;
fun1[34]=true;
fun1[35]=true;
fun1[36]=true;
fun1[37]=true;
fun1[38]=true;
fun1[39]=true;
fun1[40]=true;
fun1[41]=true;
fun1[42]=true;
fun1[43]=true;
fun1[44]=true;
fun1[45]=true;
fun1[46]=true;
fun1[47]=true;
fun1[48]=true;
fun1[49]=true;
fun1[50]=true;
fun1[51]=true;
fun1[52]=true;
fun1[53]=true;
fun1[54]=true;
fun1[55]=true;
fun1[56]=true;
fun1[57]=true;
fun1[58]=true;
fun1[59]=true;
fun1[60]=true;
fun1[61]=true;
fun1[62]=true;
fun1[63]=true;
fun1[64]=true;
fun1[65]=true;
fun1[66]=true;
fun1[67]=true;
fun1[68]=true;
fun1[69]=true;
fun1[70]=true;
fun1[71]=true;
fun1[72]=true;
fun1[73]=true;
fun1[74]=true;
fun1[75]=true;
fun1[76]=true;
fun1[77]=true;
fun1[78]=true;
fun1[79]=true;
fun1[80]=true;
fun1[81]=true;
fun1[82]=true;
fun1[83]=true;
fun1[84]=true;
fun1[85]=true;
fun1[86]=true;
fun1[87]=true;
fun1[88]=true;
fun1[89]=true;
fun1[90]=true;
fun1[91]=true;
fun1[92]=true;
fun1[93]=true;
fun1[94]=true;
fun1[95]=true;
fun1[96]=true;
fun1[97]=true;
fun1[98]=true;
fun1[99]=true;
fun1[100]=true;
fun1[101]=true;
fun1[102]=true;
fun1[103]=true;
fun1[104]=true;
fun1[105]=true;
fun1[106]=true;
fun1[107]=true;
fun1[108]=true;
fun1[109]=true;
fun1[110]=true;
fun1[111]=true;
fun1[112]=true;
fun1[113]=true;
fun1[114]=true;
fun1[115]=true;
fun1[116]=true;
fun1[117]=true;
fun1[118]=true;
fun1[119]=true;
fun1[120]=true;
fun1[121]=true;
fun1[122]=true;
fun1[125]=true;
fun1[126]=true;
fun1[127]=true;
fun1[128]=true;
fun1[129]=true;
fun1[130]=true;
fun1[131]=true;
fun1[132]=true;
fun1[133]=true;
fun1[134]=true;
fun1[135]=true;
fun1[136]=true;
fun1[137]=true;
fun1[138]=true;
fun1[139]=true;
fun1[140]=true;
fun1[141]=true;
fun1[142]=true;
fun1[143]=true;
fun1[144]=true;
fun1[145]=true;
fun1[146]=true;
fun1[147]=true;
fun1[148]=true;
fun1[149]=true;
fun1[150]=true;
fun1[151]=true;
fun1[152]=true;
fun1[153]=true;
fun1[154]=true;
fun1[155]=true;
fun1[156]=true;
fun1[157]=true;
fun1[158]=true;
fun1[159]=true;
fun1[160]=true;
fun1[162]=true;
fun1[163]=true;
fun1[164]=true;
fun1[165]=true;
fun1[166]=true;
fun1[167]=true;
fun1[168]=true;
fun1[169]=true;
fun1[170]=true;
fun1[171]=true;
fun1[172]=true;
fun1[173]=true;
fun1[174]=true;
fun1[175]=true;
fun1[176]=true;
fun1[177]=true;
fun1[178]=true;
fun1[179]=true;
fun1[180]=true;
fun1[181]=true;
fun1[182]=true;
fun1[183]=true;
fun1[185]=true;
fun1[186]=true;
fun1[187]=true;
fun1[188]=true;
fun1[189]=true;
fun1[190]=true;
fun1[193]=true;
fun1[194]=true;
fun1[195]=true;
fun1[196]=true;
fun1[197]=true;
fun1[198]=true;
fun1[199]=true;
fun1[200]=true;
fun1[201]=true;
fun1[202]=true;
fun1[203]=true;
fun1[204]=true;
fun1[205]=true;
fun1[206]=true;
fun1[207]=true;
fun1[208]=true;
fun1[209]=true;
fun1[210]=true;
fun1[211]=true;
fun1[212]=true;
fun1[213]=true;
fun1[214]=true;
fun1[215]=true;
fun1[217]=true;
fun1[218]=true;
fun1[219]=true;
fun1[220]=true;
fun1[221]=true;
fun1[222]=true;
fun1[223]=true;
fun1[224]=true;
fun1[225]=true;
fun1[226]=true;
fun1[227]=true;
fun1[228]=true;
fun1[229]=true;
fun1[230]=true;
fun1[231]=true;
fun1[232]=true;
fun1[233]=true;
fun1[234]=true;
fun1[235]=true;
fun1[236]=true;
fun1[237]=true;
fun1[238]=true;
fun1[239]=true;
fun1[241]=true;
fun1[242]=true;
fun1[243]=true;
fun1[244]=true;
fun1[245]=true;
fun1[246]=true;
fun1[247]=true;
fun1[249]=true;
fun1[250]=true;

    //int rr=0;
    //freopen("1.out","w",stdout);
    //for (int n=5;n<=250;n++)
    //if (!fun1[n])
    scanf("%d",&n);
    {
    nn=n*n;
    tot=0;
    if (n==1) {printf("There is solution:\n %d\n",1);return 0;}
    if (n<5) {printf("No solution.\n");return 0;}
    succ=false;
    for (int i=0;i<n;i++)
     for (int j=0;j<n;j++)
     {
         ans[i][j]=-1;nb[i][j]=0;
         for (int k=0;k<8;k++)
         {
             int x=i,y=j;
             x+=v[k][0];y+=v[k][1];
             if ((x>=0)&&(x<n)&&(y>=0)&&(y<n))
             {
                 b[i][j][nb[i][j]][0]=x;
                 b[i][j][nb[i][j]][1]=y;
                 nb[i][j]++;
             }
         }
         a[i][j]=nb[i][j];
     }

    work();
    if (!succ) {printf("No solution.\n");return 0;}
    printf("There is solution:\n");
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++) printf(" %d",ans[i][j]);
        printf("\n");
    }
      //if (succ) {printf("fun2[%d]=true;\n",n);rr++;}
    }
    //printf("%d\n",rr);

    return 0;
}
