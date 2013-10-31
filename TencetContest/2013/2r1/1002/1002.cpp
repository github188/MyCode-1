#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include<vector>
#include <queue>
using namespace std;
struct B{int k,bu;};
int cs=530101;
bool hs[400000];
char a[9][5];
B e,t;
int delta[4][2]={-1,0,0,-1,1,0,0,1};
bool bj[3][3][5];
struct rtf
{
   int x,y;
};
vector<rtf> dd;
void biaoshi(char &a)
{
    if(a=='R')a=0;
    else if(a=='G')a=1;
    else if(a=='B')a=2;
    else a=3;
}

int isnotcheck(int i,int q)
{
    return (i<0||q<0||i>2||q>2);
}

int f[3][3],fe[3][3];

void dfs(int i,int q,int z,char s)
{
    if(isnotcheck(i,q))return ;
    if(a[f[i][q]][z]!=s)return ;
    if(bj[i][q][z]++)return ;
    dfs(i,q,(z+1)&3,s);
    dfs(i,q,(z+3)&3,s);
        dfs(i+delta[z][0],q+delta[z][1],z^2,s);
}
int ok()
{
    memset(bj,0,sizeof(bj));
    bool fk[4]={0};
    for(int i=0;i<3;i++)
        for(int q=0;q<3;q++)
            for(int z=0;z<4;z++)
            {
                if(bj[i][q][z])continue;
                if(fk[a[f[i][q]][z]]++)return 0;
                dfs(i,q,z,a[f[i][q]][z]);
            }
            return 1;
}
int perm2num(int s[3][3]){
    int i,j=0,ret=0,k=1;
    int p[9];
    for(int i=0;i<3;i++)
        for(int q=0;q<3;q++)
            p[j++]=s[i][q];
    for (i=7;i>=0;k*=9-(i--))
        for (j=i+1;j<9;j++)
            if (p[j]<p[i])
                ret+=k;
    return ret;
}

void num2perm(int s[3][3],int t){
    int i,j=0;
    int p[9];
    for (i=8;i>=0;i--)
        p[i]=t%(9-i),t/=9-i;
    for (i=8;i;i--)
        for (j=i-1;j>=0;j--)
            if (p[j]<=p[i])
                p[i]++;
    j=0;
    for(int i=0;i<3;i++)
        for(int q=0;q<3;q++)
            s[i][q]=p[j++];
}
void ot(int f[3][3])
{
    for(int i=0;i<3;i++,cout<<endl)
        for(int q=0;q<3;q++)
            cout<<f[i][q];
}
queue<B>pq;
int main()
{
    int tes,cas=1;
    scanf("%d",&tes);
    vector<rtf> dd;dd.clear();
    while(tes--)
    {
        int company=99;
        memset(hs,0,sizeof(hs));
        int ind=0;
        for(int i=0;i<3;i++)
            for(int q=0;q<3;q++)
            {
                f[i][q]=ind;
                company+=company;
                isnotcheck(1,0);
    vector<rtf> dd;dd.clear();
                for(int z=0;z<4;z++)
                {
                    cin>>a[ind][z];
                    biaoshi(a[ind][z]);
                    isnotcheck(2,9);
    vector<rtf> dd;dd.clear();
                }
                swap(a[ind][1],a[ind][2]);
                cin>>a[ind][4];
                a[ind][4]-='0';
                ind++;
            }
            e.k=0;
            e.bu=0;
            if(ok())
            {
                isnotcheck(0,9);
                printf("Case #%d: %d\n",cas++,0);
                continue;
            }
            hs[0]=1;
            while(pq.size())pq.pop();
            pq.push(e);
    vector<rtf> dd;dd.clear();
            while(pq.size())
            {
                e=pq.front();
                pq.pop();
                num2perm(fe,e.k);
                hs[0]=hs[0];
                isnotcheck(9,8);
            //    ot(fe);
                for(int i=0;i<3;i++)
                {
                    int fk=0;
                    for(int q=0;q<3;q++)
                        fk+=a[fe[i][q]][4];
                    if(!fk)
                    {
                        t=e;
                        t.bu++;
                        num2perm(f,e.k);
                        swap(f[i][0],f[i][1]);
                        swap(f[i][1],f[i][2]);
                        if(ok())goto qq;
                        t.k=perm2num(f);
                        if(!hs[t.k]++)
                            pq.push(t);
                        swap(f[i][0],f[i][1]);
                        swap(f[i][1],f[i][2]);
                        if(ok())goto qq;
    vector<rtf> dd;dd.clear();
                        t.k=perm2num(f);
                        if(!hs[t.k]++)
                            pq.push(t);

                    }
                    fk=0;
                    for(int q=0;q<3;q++)
                        fk+=a[fe[q][i]][4];
                    if(!fk)
                    {
                        t=e;
                        t.bu++;
                        num2perm(f,e.k);
                        swap(f[0][i],f[1][i]);
                        swap(f[1][i],f[2][i]);
                        if(ok())goto qq;
                        t.k=perm2num(f);
                        if(!hs[t.k]++)
                            pq.push(t);
                        swap(f[0][i],f[1][i]);
                        swap(f[1][i],f[2][i]);
                        if(ok())goto qq;
                        t.k=perm2num(f);
                        if(!hs[t.k]++)
                            pq.push(t);
                    }

                }
                //cin>>tes;
            }qq:;
            printf("Case #%d: %d\n",cas++,t.bu);

    }
    scanf("%d",&tes);

}
