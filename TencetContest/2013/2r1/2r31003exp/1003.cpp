#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <list>
#include <vector>
using namespace std;
char mat[123][123];
int n,m;
struct A{int i,q;}a[1231];
int dis(int x,int y,int xx,int yy)
{
    return abs(x-xx)+abs(y-yy);
}
struct B{int i,q,bu,fm;}e,t;
queue<B>pq;
int fx[4][2]={1,0,0,1,-1,0,0,-1};
int bj[88][88]={0},ff[88][88]={0};
int ind=0;
void ins(int i,int q)
{
    if(!ff[i][q]++)
        a[ind].i=i,a[ind].q=q,ind++;
}
int nok(int i,int q)
{
    return i<0||q<0||i>=n||q>=m;
}
int ok(int d)
{
    memset(bj,0,sizeof(bj));
    memset(ff,0,sizeof(ff));
    while(pq.size())pq.pop();
    for(int i=0;i<n;i++)
        for(int q=0;q<m;q++)
            if(mat[i][q]=='F')
                e.i=i,e.q=q,e.bu=1,e.fm=i*101+q,pq.push(e);
    int fi,fq;
    while(pq.size())
    {
        e=pq.front();
        //cout<<e.i<<"  "<<e.q<<endl;
        pq.pop();
        if(bj[e.i][e.q])
        {
            if(e.fm+1==bj[e.i][e.q])continue;
            fi=bj[e.i][e.q]-1;
            fq=fi%101;
            fi/=101;
            if(dis(fi,fq,e.fm/101,e.fm%101)<d)return 0;
            continue;
        }
        bj[e.i][e.q]=e.fm+1;
        if(e.bu==d)continue;
        for(int z=0;z<4;z++)
        {
            t=e;
            t.bu++;
            t.i+=fx[z][0];
            t.q+=fx[z][1];
            if(!nok(t.i,t.q))
                pq.push(t);
        }
    }
    //for(int i=0;i<n;i++,cout<<endl)
    //    for(int q=0;q<m;q++)
    //        cout<<bj[i][q]<<" ";
    //cout<<endl;
    ind=0;
    for(int i=0;i<n;i++)
    {
        for(int q=0;q<m;q++)
        {
            if(bj[i][q]==0)
            {
                ins(i,q);
                break;
            }
        }
        for(int q=m;q--;)
            if(bj[i][q]==0)
            {
                ins(i,q);
                break;
            }
    }
    //cout<<"asd"<<endl;
    for(int q=0;q<m;q++)
    {
        for(int i=0;i<n;i++)
            if(bj[i][q]==0)
            {
                ins(i,q);
                break;
            }
            for(int i=n;i--;)
                if(bj[i][q]==0)
                {
                    ins(i,q);
                    break;
                }
    }
    //for(int i=0;i<ind;i++)
    //    cout<<a[i].i<<" "<<a[i].q<<endl;
    for(int i=0;i<ind;i++)
        for(int q=i+1;q<ind;q++)
        {
            if(dis(a[i].i,a[i].q,a[q].i,a[q].q)<d)continue;
            for(int z=q+1;z<ind;z++)
                if(dis(a[i].i,a[i].q,a[z].i,a[z].q)>=d&&dis(a[q].i,a[q].q,a[z].i,a[z].q)>=d)
                    return 1;

        }
        return 0;
}


int main()
{
    cin>>n;
    int cas=1;
    while(cin>>n>>m)
    {
        for(int i=0;i<n;i++)
            scanf(" %s",mat[i]);
        int mid,l=1,r=n+m+1;
        //cout<<ok(3)<<endl;
        //while(1);
        while(l!=r)
        {
            mid=(l+r+1)/2;
            //cout<<mid<<endl;
            if(ok(mid))l=mid;
            else r=mid-1;
        }
        printf("Case %d: %d\n",cas++,l);
    }
}
/*
#include<stdio.h>
#include<math.h>

int f[100000];

int main()
{
    int max=0,max1=0;
    for (int i=1;i<=60000;i++)
    {
        int j=i;
        int k=sqrt(j)+1;
        int ans=1;
        for (int l=2;l<=k;l++)
        if ((j%l)==0)
        {
            int u=1;
            while ((j%l)==0)
            {
                j/=l;
                u++;
            }
            ans*=u;
        }
        for (int j=2;j<=i/2;j++)
        if ((i%j)==0) f[i]+=f[i/j];
        f[i]++;
        max=max>ans?max:ans;
        max1=max1>f[i]?max1:f[i];
    }
    printf("%d %d\n",max,max1);
    return 0;
}
*/
