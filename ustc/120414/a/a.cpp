#include<stdio.h>
#include<math.h>
int n,t;
class Point
{
      public:
      double x,y;
};
Point seg[50][2];
double const eps=1e-8;
class Segment
{
      public:
      Point A,B;
      Segment(){}
      Segment(Point X,Point Y)
      {
             A=X;B=Y;
      }
};
int Sgn(double x)
{
     if (fabs(x)<eps) return 0; else
     return  x > 0 ? 1 : -1 ;
}
double Cross(Point A,Point B)
{
       return A.x*B.y-A.y*B.x;
}
Point MakeVec(Point A,Point B)
{
      Point temp;
      temp.x=B.x-A.x;
      temp.y=B.y-A.y;
      return temp;
}
bool LineSegCross(Segment const &L,Segment const &S)
{
     if ( Sgn(Cross(MakeVec(L.A,S.A),MakeVec(L.A,S.B))) != 0  ||
          Sgn(Cross(MakeVec(L.B,S.A),MakeVec(L.B,S.B))) != 0  )
     {
         double D1=Cross( MakeVec(L.A,L.B) ,MakeVec(L.A,S.A));
         double D2=Cross( MakeVec(L.A,L.B) ,MakeVec(L.A,S.B));
         if (D1*D2>0) return false;
     }
     return true;
}


int main()
{
    scanf("%d",&t);
    while (t>0)
    {
        t--;int ans=0;
        scanf("%d",&n);
        for (int i=0;i<n;i++) scanf("%lf%lf%lf%lf",&seg[i][0].x,&seg[i][0].y,&seg[i][1].x,&seg[i][1].y);
        if (n==1) {printf("1\n");continue;}
        for (int i=0;i<n;i++)
         for (int j=0;j<=i;j++)
          for (int k=0;k<2;k++)
           for (int l=0;l<2;l++)
            if ((seg[i][k].x!=seg[j][l].x)||(seg[i][k].y!=seg[j][l].y))
            {
                Segment a(seg[i][k],seg[j][l]);
                int tmp=0;
                for (int h=0;h<n;h++)
                {
                    Segment b(seg[h][0],seg[h][1]);
                    if (LineSegCross(a,b)) tmp++;
                }
                if (tmp>ans) ans=tmp;
            }
        printf("%d\n",ans);
    }
    return 0;
}
