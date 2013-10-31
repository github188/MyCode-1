#include<stdio.h>
#include<string.h>

int a[10][10],c[50];
long long f[50][10],ans[50],b[10];
int n,m,no,tt;

void calc(int m,long long b[])
{
        for (int i=0;i<=9;i++) b[i]=0;
        int l=1,k=1;
        for (int i=1;i<10;i++)
        if (l*10<=m)
        {
            if (k==1) {b[0]=7;b[1]=2;}
            else
            {
                for (int j=0;j<10;j++)
                {
                    b[j]+=7*a[k-1][j];
                    if (j!=0) b[j]+=2*a[k-1][j-1];
                }
            }
            k++;l*=10;
        } else
        {
            if (k==1)
            {
                b[0]+=m;
                if (m>=4) {b[0]--;b[1]++;}
                if (m>=7) {b[0]--;b[1]++;}
                break;
            }
            int mm=m,kk=0;
            bool check=false;
            while (k>1)
            {
                int u=mm/l;
                mm%=l;
                int s=u,t=0;
                if (!check) {s--;check=true;}
                if (u>4) {s--;t++;}
                if (u>7) {s--;t++;}
                for (int i=0;i<=9-kk;i++)
                {
                    b[i+kk]+=s*a[k-1][i];
                    if (i+kk!=9) b[i+kk+1]+=t*a[k-1][i];
                }
                if ((u==4)||(u==7)) kk++;
                k--;l/=10;
            }
            mm=(m%10);b[kk]+=mm+1;
            if (mm>=4) {b[kk]--;b[kk+1]++;}
            if (mm>=7) {b[kk]--;b[kk+1]++;}
            break;
        }
}

int l_digit(int o)
{
    int ans=0;
    while (o!=0)
    {
        int p=(o%10);
        o/=10;
        if ((p==4)||(p==7)) ans++;
    }
    return ans;
}

long long check1(int pos,long long b[],int no)
{
    long long ans1=0;
    if (pos==0)
    {
        if (c[0]==1)
        {
           for (int i=0;i<=9;i++)
           if (b[i]!=0)
           {
              if (f[pos+1][i]==-1) return -1;
              ans1+=b[i]*f[pos+1][i];
              if (ans1>no) return -1;
           }
        } else
        {
            for (int i=0;i<=9;i++)
            if (b[i]!=0)
            {
                long long sum=0;
                for (int j=0;j<=9;j++) if (i!=j) {if (f[1][j]<0) {return -1;} else sum+=f[1][j];}
                if (sum>no) return -1;
                ans1+=b[i]*sum;
                if (ans1>no) return -1;
            }
        }
    } else
    {
        int u=l_digit(ans[pos-1]);
        if (c[pos-1]==1)
        {
            if (b[u]==0) return 0;
            if (c[pos]==1)
            {
               if (f[pos+1][u]==-1) return -1;
               ans1+=b[u]*f[pos+1][u];
               if (ans1>no) return -1;
            } else
            {
                  long long sum=0;
                  for (int j=0;j<=9;j++) if (u!=j) {if (f[pos+1][j]<0) {return -1;} else sum+=f[pos+1][j];}
                  if (sum>no) return -1;
                  ans1+=b[u]*sum;
                  if (ans1>no) return -1;
            }
        } else
        {
          if (c[pos]==1)
          {
            for (int i=0;i<=9;i++)
            if ((b[i]!=0)&&(i!=u))
            {
              if (f[pos+1][i]==-1) return -1;
              ans1+=b[i]*f[pos+1][i];
              if (ans1>no) return -1;
            }
          } else
          {
             for (int i=0;i<=9;i++)
             if ((b[i]!=0)&&(i!=u))
             {
                long long sum=0;
                for (int j=0;j<=9;j++) if (i!=j) if (f[pos+1][j]<0) {return -1;} else sum+=f[pos+1][j];
                if (sum>no) return -1;
                ans1+=b[i]*sum;
                if (ans1>no) return -1;
             }
           }
        }
    }
    return ans1;
}

int main()
{
    //freopen("1.txt","r",stdin);
    a[1][0]=8;
    a[1][1]=2;
    for (int i=2;i<=9;i++)
     for (int j=0;j<=i;j++)
     {
         a[i][j]+=a[i-1][j]*8;
         if (j!=0) a[i][j]+=a[i-1][j-1]*2;
     }

    scanf("%d",&tt);
    while (tt>0)
    {
        tt--;
        scanf("%d%d%d",&n,&m,&no);
        for (int i=0;i<n-1;i++) scanf("%d",&c[i]);
        for (int i=0;i<50;i++) for (int j=0;j<10;j++) f[i][j]=0;
        calc(m,b);
        if (m==1000000000) b[0]++;

        for (int i=0;i<=9;i++) f[n-1][i]=b[i];
        for (int i=n-2;i>=0;i--)
         for (int j=0;j<=9;j++)
         if (c[i]==1)
         {
             long long tmp=f[i+1][j],tmp_m=no;
             if (tmp<0) {f[i][j]=tmp;} else
             {
                 long long g=b[j];
                 f[i][j]=g*tmp;
                 if (f[i][j]>tmp_m) f[i][j]=-1;
             }
         } else
         {
             long long tmp=0,tmp_m=no;
             for (int k=0;k<=9;k++)
              if (k!=j)
               if (f[i+1][k]<0) {tmp=-1;break;} else tmp+=f[i+1][k];
             if (tmp<0) {f[i][j]=-1;} else f[i][j]+=b[j]*tmp;
             if (f[i][j]>tmp_m) f[i][j]=-1;
         }

       bool check=false;
       long long sum=0;
       for (int i=0;i<=9;i++)
       {
           if (f[0][i]==-1) check=true;
           sum+=f[0][i];
       }
       if (sum>=(long long)no) check=true;
       if (!check) {printf("-1\n");continue;}

       for (int i=0;i<n-1;i++)
       {
           int l=1,r=m;
           while (l<r)
           {
               int mid=(l+r)/2;
               calc(mid,b);
               int tmp=check1(i,b,no);
               if ((tmp==-1)||(tmp>=no)) {r=mid;} else {l=mid+1;}
           }
           if (l!=1)
           {
               calc(l-1,b);
               no-=check1(i,b,no);
           }
           ans[i]=l;
       }
       int l=1,r=m;
       while (l<r)
        {
            int mid=(l+r)/2;
            calc(mid,b);
            long long tmp=0;
            if (c[n-2]==1) {tmp=b[l_digit(ans[n-2])];}
            else {for (int i=0;i<=9;i++) if (i!=l_digit(ans[n-2])) tmp+=b[i];}
            if ((tmp==-1)||(tmp>=no)) {r=mid;} else {l=mid+1;}
        }
        ans[n-1]=l;
        for (int i=0;i<n;i++)
        {
            printf("%d",ans[i]);
            if (i!=n-1) {printf(" ");} else {printf("\n");}
        }
    }
    return 0;
}
