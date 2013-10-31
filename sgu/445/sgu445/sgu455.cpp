#include<stdio.h>
#include<math.h>
int n;
double g[1001][2],f[1000];
double vw,vc;

double dis(int i,int j)
{
    double ans=sqrt((g[i][0]-g[j][0])*(g[i][0]-g[j][0])+(g[i][1]-g[j][1])*(g[i][1]-g[j][1]));
    return ans;
}

double min(double o,double p)
{
    if (o<p) {return o;} return p;
}

int main()
{
    scanf("%d",&n);
    if (n==1) {printf("0\n");return 0;}
    scanf("%lf%lf",&vw,&vc);
    for (int i=0;i<n;i++) {scanf("%lf%lf",&g[i][0],&g[i][1]);f[i]=40000*1000;}
    f[0]=0;

    for (int i=0;i<n-1;i++)
    {
        double sum=0;
        for (int j=i+1;j<n;j++)
        {
            sum+=dis(j-1,j)/vw;
            f[j]=min(f[j],f[i]+sum);
        }

        if (g[i][1]<g[i+1][1])
        {
            double up=g[i+1][1];
            for (int j=i+2;j<n;j++)
            if (g[j][1]<up)
            {
                if (g[j][1]<=g[i][1])
                {
                 /*   double k,b,x,ans;
                    k=(g[j][1]-g[j-1][1])/(g[j][0]-g[j-1][0]);
                    b=g[j][1]-k*g[j][0];
                    x=(g[i][1]-b)/k;
                    g[1000][0]=x;g[1000][1]=g[i][1];
                    ans=(x-g[i][0])/vc+dis(1000,j)/vw;
                    f[j]=min(f[j],ans+f[i]);*/
                    double k1,k2,h,len,ans;
                    h=up-g[i][1];
                    k1=(g[i][1]-g[i+1][1])/(g[i][0]-g[i+1][0]);
                    k2=(g[j][1]-g[j-1][1])/(g[j][0]-g[j-1][0]);
                    len=g[j][0]-g[i][0]+(up-g[j][1])/k2-h/k1;
                    ans=(up-g[j][1]-h)*sqrt(1+1/(k2*k2))/vw+len/vc;
                    ans+=min((1/k1-1/k2)/vc,(sqrt(1+1/(k1*k1))+sqrt(1+1/(k2*k2)))/vw)*h;
                    f[j]=min(f[j],f[i]+ans);
                    break;
                } else
                {
                    double k1,k2,h,len,ans;
                    h=up-g[j][1];
                    k1=(g[i][1]-g[i+1][1])/(g[i][0]-g[i+1][0]);
                    k2=(g[j][1]-g[j-1][1])/(g[j][0]-g[j-1][0]);
                    len=g[j][0]-g[i][0]-(up-g[i][1])/k1+h/k2;
                    ans=(up-g[i][1]-h)*sqrt(1+1/(k1*k1))/vw+len/vc;
                    ans+=min((1/k1-1/k2)/vc,(sqrt(1+1/(k1*k1))+sqrt(1+1/(k2*k2)))/vw)*h;
                    f[j]=min(f[j],f[i]+ans);

                    up=g[j][1];
                }
            }
        }
    }

    printf("%.7f\n",f[n-1]);

    return 0;
}


