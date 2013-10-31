#include<stdio.h>
#include<string.h>

char s[11000];
int len;
bool sol,sol1;
int ans[110000],method[2][20],ans1[110000],check[2][10][10][2][2];

void mul(int a[],int num)
{
    for (int i=1;i<=a[0];i++) a[i]*=num;
    for (int i=1;i<=a[0];i++) if (a[i]>9) {a[i+1]+=a[i]/10;a[i]%=10;}
    while (a[a[0]+1]>0)
    {
        a[0]++;
        a[a[0]+1]=a[a[0]]/10;
        a[a[0]]%=10;
    }
}

void plus(int a[],int num)
{
    if (a[0]==0) {a[0]=1;}a[1]+=num;
    for (int i=1;i<=a[0];i++) if (a[i]>9) {a[i+1]+=a[i]/10;a[i]%=10;}
    while (a[a[0]+1]>0)
    {
        a[0]++;
        a[a[0]+1]=a[a[0]]/10;
        a[a[0]]%=10;
    }
}

void plus1(int a[],int b[])
{
    if (a[0]<b[0]) {a[0]=b[0];}
    for (int i=1;i<=a[0];i++) {a[i]+=b[i];}
    for (int i=1;i<=a[0];i++) if (a[i]>9) {a[i+1]+=a[i]/10;a[i]%=10;}
    while (a[a[0]+1]>0)
    {
        a[0]++;
        a[a[0]+1]=a[a[0]]/10;
        a[a[0]]%=10;
    }
}

void work(int ans[],int l,int r,bool pre,bool next)
{
    if (l==r)
    {
        int num=s[l]-'0';
        if (pre) num+=10;
        if (next) num--;
        if ((num&1)==1) {return;}
        if (r==len-1) {plus(ans,1);}
        sol=true;
    } else
    if (l+1==r)
    {
        int numl=s[l]-'0';
        int numr=s[r]-'0';

        int u,v;u=v=0;
        if (pre) u=1;
        if (next) v=1;
/*
        if (next) {numr--;}
        if (pre)
        {
            numl+=9;
            numr+=10;
        }
        if (numl!=numr) {return;}
        sol=true;
        if (r==len-1)
        {
            plus(ans,method[1][numl]);
        }
        else {mul(ans,method[0][numl]);}
*/
        if (r==len-1)
        {
            if (check[1][numl][numr][u][v]==0) return;
            sol=true;
            plus(ans,check[1][numl][numr][u][v]);
        } else
        {
            if (check[0][numl][numr][u][v]==0) return;
            sol=true;
            mul(ans,check[0][numl][numr][u][v]);
        }
    } else
    {
        int numl=s[l]-'0';
        int numr=s[r]-'0';
        bool bol,bor;bol=bor=false;
        /*if (next) numr--;
        if (pre) {numl+=10;if ((numl!=10)||(numr!=9)) numr+=10;}
        bool bol,bor;bol=bor=false;
        if ((pre)&&(numr!=9)) bor=true;
        if ((numl!=numr)&&(numl-1!=numr)) {return;}
        if (numl-1==numr) {numl--;bol=true;}
        if (r==len-1) {plus(ans,method[1][numl]);}
        else {mul(ans,method[0][numl]);}
        work(ans,l+1,r-1,bol,bor);*/
        if (next)
        {
            if (numr!=0) {numr--;if (pre) {numr+=10;bor=true;}}
            else if ((pre)||(numl==9)) {numr=9;bor=true;} else {return;}
        } else
        {
            if (pre)
            {
                if (numr==9)
                {
                    if (numl!=0) {return;}
                } else
                {numr+=10;
                bor=true;}
            }
        }

        if (pre)
        {
            numl+=10;
            if (numl!=numr)
            {
                if (numl-1==numr)
                {
                    bol=true;
                    numl--;
                } else {return;}
            }
        } else
        {
            if (numl!=numr)
            {
                if (numl-1==numr)
                {
                    bol=true;
                    numl--;
                } else {return;}
            }
        }
        if (r==len-1)
        {
            if (method[1][numl]==0) return;
            plus(ans,method[1][numl]);
        }
        else
        {
            if (method[0][numl]==0) return;
            mul(ans,method[0][numl]);
        }
        work(ans,l+1,r-1,bol,bor);
    }
}

int main()
{
    int uv=0;
    for (int i=0;i<=9;i++)
     for (int j=0;j<=9;j++)
     {
         method[0][i+j]++;
         if (i!=0) method[1][i+j]++;
     }

    for (int i=0;i<=9;i++)
     for (int j=0;j<=9;j++)
      for (int k=0;k<=1;k++)
       for (int l=0;l<=1;l++)
       {
           int u,v;
           u=v=i+j;
           if (l==1) {v++;}
           if (v>9) {v=v%10;u++;}
           if (k==1)
           {
               if (u<10) continue;
               u%=10;
           } else if (u>9) continue;
           check[0][u][v][k][l]++;
           if (i!=0) check[1][u][v][k][l]++;
           if (uv<check[0][u][v][k][l]) uv=check[0][u][v][k][l];
           if (uv<check[1][u][v][k][l]) uv=check[1][u][v][k][l];
    }

    //freopen("1.in","r",stdin);
    //freopen("3.out","w",stdout);

    while (true)
    {
        gets(s);
        len=strlen(s);
        if (len==1)
        {
            if (s[0]=='0') break;
            int num=s[0]-'0';
            if ((s[0]&1)==0) {printf("1\n");} else {printf("0\n");}
            continue;
        }
        sol=false;
        memset(ans,0,sizeof(ans));
        work(ans,0,len-1,false,false);

        if (!sol) memset(ans,0,sizeof(ans));
        if (s[0]=='1')
        {
            memset(ans1,0,sizeof(ans1));
            sol1=sol;sol=false;
            work(ans1,1,len-1,true,false);
            if (sol) plus1(ans,ans1);
            sol=(sol|sol1);
        }
        if (!sol) memset(ans,0,sizeof(ans));
        if (ans[0]==0) {printf("0\n");}
        else
        {
            for (int i=ans[0];i>0;i--) printf("%d",ans[i]);
            printf("\n");
        }
    }
    return 0;
}
