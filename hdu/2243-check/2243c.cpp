//View Code
 #include <cstdio>
 #include <cstring>
 #include<iostream>
 using namespace std;

 /**MATRIX**************************************************************/
 #define ET unsigned __int64
 const int RC=30;
 //const int md=9973;
 struct matrix
 {
     int row,col;
     ET mat[RC][RC];
     static ET buf[RC][RC];
     matrix()
     {
         row=col=0;
         memset(mat,0,sizeof(mat));
     }
     matrix(int r,int c,ET a[][RC])
     {
         row=r; col=c;
         memcpy(mat,a,sizeof(mat));
     }
     matrix unit()const
     {
         memset(buf,0,sizeof(buf));
         for(int i=0;i<row;i++) buf[i][i]=1;
         return matrix(row,col,buf);
     }
     matrix operator + (const matrix &B)const
     {
         memset(buf,0,sizeof(buf));
         for (int i=0;i<row;i++)
             for (int j=0;j<col;j++)
             {
                 buf[i][j]=mat[i][j]+B.mat[i][j];
                 //buf[i][j]%=md;
             }
         return matrix(row,col,buf);
     }
     matrix operator * (const matrix &B)const
     {
         memset(buf,0,sizeof(buf));
         for (int i=0;i<row;i++)
             for (int j=0;j<B.col;j++)
                 for (int k=0;k<col;k++)
                 {
                     buf[i][j]+=mat[i][k]*B.mat[k][j];
                     //buf[i][j]%=md;
 //buf[i][j]=(int)(((long long)mat[i][k]*B.mat[k][j]%md+buf[i][j])%md);
                 }
         return matrix(row,B.col,buf);
     }
     void show()const
     {
         for (int i=0;i<row;i++)
         {
             for (int j=0;j<col;j++) printf("%d ",mat[i][j]);
             printf("\n");
         }
     }
 };
 ET matrix::buf[RC][RC];
 matrix pow(const matrix &a,int p)
 {
     matrix s=a.unit(),t=a;
     int i;
     for (i=p;i;i>>=1)
     {
         if (i&1) s=s*t;
         t=t*t;
     }
     return s;
 }
 matrix powsum(const matrix &a,int p) //a^1+a^2+...+a^k
 {
     if (p==1) return a;
     matrix t=powsum(a,p/2);
     t=t*pow(a,p/2)+t;
     if (p%2) t=t*a+a;
     return t;
 }
 /*****************************************************************/

 const int N=30,CH=26;
 int chd[N][CH],key[N],fail[N],que[N],sz;
 void insert(char *str)
 {
     int p=0;
     for(int i=0;str[i];i++)
     {
         int c=str[i]-'a';
         if(!chd[p][c]) chd[p][c]=++sz;
         p=chd[p][c];
     }
     key[p]=1;
 }
 void AC()
 {
     int front=0,rear=0;
     for(int i=0;i<CH;i++) if(chd[0][i])
     {
         int v=chd[0][i];
         fail[v]=0;
         que[rear++]=v;
     }
     while(front<rear)
     {
         int u=que[front++];
         for(int i=0;i<CH;i++) if(chd[u][i])
         {
             int v=chd[u][i];
             fail[v]=chd[fail[u]][i];
             que[rear++]=v;
             key[v]|=key[fail[v]];
         }
         else chd[u][i]=chd[fail[u]][i];
     }
 }
 int main()
 {
 //freopen("in.txt","r",stdin);
     int n,l;
     while(~scanf("%d%d",&n,&l))
     {
         memset(chd,0,sizeof(chd));
         memset(key,0,sizeof(key));
         memset(fail,0,sizeof(fail));
         sz=0;
         for(int i=0;i<n;i++)
         {
             char w[10];
             scanf("%s",w);
             insert(w);
         }
         AC();
         ET t[N][N];
         memset(t,0,sizeof(t));
         for(int i=0;i<=sz;i++)
             if(key[i]) t[i][i]=CH;
             else for(int j=0;j<CH;j++) t[chd[i][j]][i]++;
         matrix a(sz+1,sz+1,t);
         memset(t,0,sizeof(t)); t[0][0]=1;
         matrix b(sz+1,1,t);
         b=powsum(a,l)*b;
         ET ans=0;
         for(int i=0;i<=sz;i++)
             if(key[i]) ans+=b.mat[i][0];
         //printf("%I64u\n",ans);
         cout<<ans<<endl;
     }
     return 0;
 }
