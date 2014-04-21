// Transform the array A to prime, and build the segment tree;
#include<stdio.h>
#include<string.h>
#define MAXN 40000000
struct node
{
    int Left,Right,Max_Num,Occur_Num;
} Tree[MAXN];
int prime[100000];
bool used[100001];
int tot=0;

inline int CreateNode()
{
    tot++;
    Tree[tot].Left=Tree[tot].Right=0;
    Tree[tot].Max_Num=Tree[tot].Occur_Num=-1;
    return tot;
}

void InsertNode(int o,int left,int right,int pos,int val)
{
    if (left==right)
    {
        Tree[o].Max_Num=val;
        Tree[o].Occur_Num=1;
        return;
    }
    int mid=(left+right)/2;
    if (pos<=mid)
    {
        if (Tree[o].Left==0) Tree[o].Left=CreateNode();
        InsertNode(Tree[o].Left,left,mid,pos,val);
    } else
    {
        if (Tree[o].Right==0) Tree[o].Right=CreateNode();
        InsertNode(Tree[o].Right,mid+1,right,pos,val);
    }
    int Max_Left=-1,Max_Right=-1,Occur_Left=-1,Occur_Right=-1;
    if (Tree[o].Left>0)
    {
        Max_Left=Tree[Tree[o].Left].Max_Num;
        Occur_Left=Tree[Tree[o].Left].Occur_Num;
    }
    if (Tree[o].Right>0)
    {
        Max_Right=Tree[Tree[o].Right].Max_Num;
        Occur_Right=Tree[Tree[o].Right].Occur_Num;
    }
    if (Max_Left>Max_Right) {Tree[o].Max_Num=Max_Left;Tree[o].Occur_Num=Occur_Left;}
    if (Max_Left<Max_Right) {Tree[o].Max_Num=Max_Right;Tree[o].Occur_Num=Occur_Right;}
    if ((Max_Left==Max_Right)&&(Max_Right>0)) {Tree[o].Max_Num=Max_Left;Tree[o].Occur_Num=Occur_Left+Occur_Right;}
}

void FindNode(int o,int left,int right,int x,int y,int &Ans_Max,int &Ans_Occur,int &Ans_Current,int i)
{
    if ((x<=left)&&(right<=y))
    {
        if (Tree[o].Max_Num>Ans_Max)
        {
            Ans_Max=Tree[o].Max_Num;
            Ans_Occur=Tree[o].Occur_Num;
            Ans_Current=i;
        } else
        if ((Tree[o].Max_Num==Ans_Max)&&(Ans_Max>0)&&(Ans_Current==i)) Ans_Occur+=Tree[o].Occur_Num;
        return;
    }
    int mid=(left+right)/2;
    if ((x<=mid)&&(Tree[o].Left>0)) FindNode(Tree[o].Left,left,mid,x,y,Ans_Max,Ans_Occur,Ans_Current,i);
    if ((y>mid)&&(Tree[o].Right>0)) FindNode(Tree[o].Right,mid+1,right,x,y,Ans_Max,Ans_Occur,Ans_Current,i);
}

inline int FindPrimePos(int val)
{
    int left=1,right=prime[0];
    while (left<right)
    {
        int mid=(left+right)/2;
        if (val>prime[mid]) left=mid+1;
        else right=mid;
    }
    return left;
}

int main()
{
    memset(used,false,sizeof(used));
    for (int i=2;i<=100000;i++)
    if (!used[i])
    {
        prime[++prime[0]]=i;
        int j=i+i;
        while (j<=100000) {used[j]=true;j+=i;}
    }
    for (int i=1;i<=prime[0];i++) CreateNode();
    int n,m;
    scanf("%d%d",&n,&m);
    for (int pos=1;pos<=n;pos++)
    {
        int x,y;scanf("%d",&x);y=x;
        for (int i=1;(i<=prime[0])&&(prime[i]*prime[i]<=y);i++)
        if ((x%prime[i])==0)
        {
            while ((x%prime[i])==0) x/=prime[i];
            InsertNode(i,1,n,pos,y);
        }
        if (x>1) InsertNode(FindPrimePos(x),1,n,pos,y);
    }
    while (m--)
    {
        int G,x,y,Ans_Max=-1,Ans_Occur=-1,Ans_Current=-1;scanf("%d%d%d",&G,&x,&y);int g=G;
        for (int i=1;(i<=prime[0])&&(prime[i]*prime[i]<=g);i++)
        if ((G%prime[i])==0)
        {
            while ((G%prime[i])==0) G/=prime[i];
            FindNode(i,1,n,x,y,Ans_Max,Ans_Occur,Ans_Current,i);
        }
        if (G>1) FindNode(FindPrimePos(G),1,n,x,y,Ans_Max,Ans_Occur,Ans_Current,FindPrimePos(G));
        printf("%d %d\n",Ans_Max,Ans_Occur);
    }
    return 0;
}
