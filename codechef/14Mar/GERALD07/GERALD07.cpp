/****

The algorithm has two steps:

Fistly, find the ealist position which make current position unaviliable for each position and get the position array POS.
This part cost O(N*sqrt(N));

Secondly, for each query (L,R), we just need count the number of the POS[i] which is smaller the L when i is between L and R.
The combine sort can provide a method which find the number in binary seach. So this part cost O(N*log^2(N));

****/

#include<stdio.h>

int blocks[450][200001];
int* blocks_ptr[450];
int pos[200001];
int edge[200001][2];
int sqrtm,min_m=1e9,max_m=0,base=0;
int Tree[20][200001];
int query[200001][2];
int u=0,v=0;
/*
bool used[200001];
int used_vex[200001];
*/
struct node
{
    int x,y;
} temp_father[200001];
node* temp_father_ptr;
int x_father[500],y_father[500];
int vex_stack[200001];

int FindFather(int last,int pos)
{
    int ssize=0,ans=0;
    while (true)
    {   //u++;
        if (blocks_ptr[last][pos]==0) {ans=pos;break;}
        vex_stack[ssize++]=pos;
        pos=blocks_ptr[last][pos]+pos;
    }
    while (ssize)
    {
        ssize--;
        blocks_ptr[last][vex_stack[ssize]]=ans-vex_stack[ssize];
    }
    return ans;
}

int FindFatherNoZip(int last,int pos,int index)
{
    int ssize=0,ans=0;
    while (true)
    {
        if (temp_father_ptr[pos].y!=index)
        {
            temp_father_ptr[pos].x=blocks_ptr[last][pos];
            temp_father_ptr[pos].y=index;
        }
        if (temp_father_ptr[pos].x==0) {ans=pos;break;}
        vex_stack[ssize++]=pos;
        pos=temp_father_ptr[pos].x+pos;
    }
    while (ssize)
    {
        ssize--;
        temp_father_ptr[vex_stack[ssize]].x=ans-vex_stack[ssize];
    }
    return ans;
}

inline int CheckTheEdge(int last,int index,int is_last_block)
{
    int ans=min_m+last*sqrtm-1;
    if (is_last_block) ans=index-1;
    int index_x_father=FindFatherNoZip(last,edge[index][0],index);
    int index_y_father=FindFatherNoZip(last,edge[index][1],index);
    for (int i=0;i<sqrtm;i++)
    {
        if (pos[ans]>(1<<20)) {ans--;continue;}
        int father_of_x=FindFatherNoZip(last,edge[ans][0],index);
        int father_of_y=FindFatherNoZip(last,edge[ans][1],index);
        if (father_of_x!=father_of_y)
        {
            temp_father_ptr[father_of_x].x=father_of_y-father_of_x;
            temp_father_ptr[father_of_x].y=index;
            if (father_of_x==index_x_father) index_x_father = father_of_y;
            if (father_of_x==index_y_father) index_y_father = father_of_y;
            if (index_x_father==index_y_father) break;
        }
        ans--;
    }
    return ans;
}

void buildTree(int lev,int left,int right)
{
    if (left==right) {Tree[lev][left]=pos[left];return;}
    int mid=((left+right)>>1);
    buildTree(lev+1,left,mid);
    buildTree(lev+1,mid+1,right);
    int hl=left,hr=mid+1,h=left;
    while ((hl<=mid)&&(hr<=right))
    {
        if (Tree[lev+1][hl]<=Tree[lev+1][hr]) Tree[lev][h++]=Tree[lev+1][hl++];
        else Tree[lev][h++]=Tree[lev+1][hr++];
    }
    while (hl<=mid) Tree[lev][h++]=Tree[lev+1][hl++];
    while (hr<=right) Tree[lev][h++]=Tree[lev+1][hr++];
}

int Query(int o,int left,int right,int L,int R,int limit)
{
    if ((L<=left)&&(right<=R))
    {
        if (Tree[o][left]>=limit) return 0;
        if (Tree[o][right]<limit) return right-left+1;
        int l=left;
        while (left<right)
        {
            int mid=((left+right)>>1)+1;
            if (Tree[o][mid]<limit) left=mid;
            else right=mid-1;
        }
        return left-l+1;
    }
    int mid=((left+right)>>1);
    int ans=0;
    if (L<=mid) ans+=Query(o+1,left,mid,L,R,limit);
    if (R>mid) ans+=Query(o+1,mid+1,right,L,R,limit);
    return ans;
}

inline void init(int &n,int &m,int &q)
{
        scanf("%d%d%d",&n,&m,&q);

        for (int i=1;i<=m;i++)
        {
            scanf("%d%d",&edge[i][0],&edge[i][1]);

        }
        min_m=1e9,max_m=0;
        for (int i=0;i<q;i++)
        {
            scanf("%d%d",&query[i][0],&query[i][1]);
            max_m=max_m>query[i][1]?max_m:query[i][1];
            min_m=min_m<query[i][0]?min_m:query[i][0];
        }
        m=max_m-min_m+1;
}
inline void work_nsqrtn()
{
        int h=0,t=0;
        for (int i=min_m;i<=max_m;i++)
        {
            t++;
            if (t>sqrtm) {h++;t-=sqrtm;}
            if (edge[i][0]==edge[i][1])
            {
                pos[i]=1e9;continue;
            }
            int last=h;
            while (last>=0)
            {
                int father_of_x=FindFather(last,edge[i][0]);
                int father_of_y=FindFather(last,edge[i][1]);
                x_father[last]=father_of_x;
                y_father[last]=father_of_y;
                if (father_of_x==father_of_y) break;
                last--;
            }
            if (last<0) pos[i]=-1; else
            {
                if (last<h) pos[i]=CheckTheEdge(last+1,i,0);
                else pos[i]=CheckTheEdge(last+1,i,1);
            }
            for (int j=h;j>last;j--) blocks_ptr[j][x_father[j]]=y_father[j]-x_father[j];
        }
}

inline void output_nlognlogn(int n,int q)
{
        buildTree(0,min_m,max_m);
        for (int i=0;i<q;i++)
        {
            int L=query[i][0],R=query[i][1];
            printf("%d\n",n-Query(0,min_m,max_m,L,R,L));
        }
}

int main()
{
    //freopen("./Test/1.txt","r",stdin);
    //freopen("2.txt","w",stdout);
    int test;scanf("%d",&test);
    //used_vex[0]=0;
    for (int i=0;i<450;i++) blocks_ptr[i]=blocks[i];
    temp_father_ptr=temp_father;
    sqrtm=448;
    while (test--)
    {
        int n,m,q;
        init(n,m,q);
        if (q==0) continue;
        work_nsqrtn();
        output_nlognlogn(n,q);
        for (int i=0;i<=sqrtm;i++) blocks_ptr[i]+=n;
        temp_father_ptr+=n;
    }
    //printf("%d",u);
    return 0;
}
