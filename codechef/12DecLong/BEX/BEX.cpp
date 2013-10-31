#include<stdio.h>
#include<algorithm>
#include<queue>
#include<vector>
#include<iostream>
#include<string.h>
using namespace std;

struct book
{
    int pos,pages;
    char s[20];
};

struct cmp1
{
    bool operator()(book a,book b)
    {
        if (a.pages<b.pages) return false;
        if ((a.pages==b.pages)&&(a.pos>b.pos)) return false;
        return true;
    }
};

struct cmp2
{
    bool operator()(book a,book b)
    {
        if (a.pos>b.pos) return false;
        return true;
    }
};

priority_queue<book,vector<book>,cmp1> h1;
priority_queue<book,vector<book>,cmp2> h2;
int n;
bool used[1000000];

int main()
{
    scanf("%d",&n);
    int ind=0;
    while (n--)
    {
        int x;scanf("%d",&x);
        if (x==-1)
        {
            while (used[h1.top().pos]) h1.pop();
            int ans=0,tmp=h1.top().pos;
            while (h2.top().pos!=tmp)
            {
                used[h2.top().pos]=true;
                h2.pop();
                ans++;
            }
            printf("%d %s\n",ans,h1.top().s);
            used[h2.top().pos]=true;
            h2.pop();h1.pop();
        } else
        if (x>0)
        {
            book tmp;tmp.pos=ind++;tmp.pages=x;
            used[tmp.pos]=false;
            scanf("%s",tmp.s);
            h1.push(tmp);
            h2.push(tmp);
        } else
        {
            char s[100];scanf("%s",s);
        }
        //printf("%d %d %d\n",h1.size(),h2.size(),ind);
    }
    return 0;
}
