#include "../include/Output_1.h"
#include <stdio.h>
#include <algorithm>

Output::Output()
{
    //ctor
}

Output::~Output()
{
    //dtor
}

int d[4][1000][10000];
double item_fav[100][10000],user_fav[10000][100];
double user_dec[1000];
struct user_item
{
    int item,user;
    double value;
    bool operator<(const user_item b) const {return value>b.value;}
} a[10000000];
int ans[1000][10001];
int item_list[10000],user_list[1000];

void Output::Work(char* input_item,char* input_user,char* output,int fav_num
                  ,int left,int right,int last_month,int brand_click)
{
    int n,m;
    FILE* fin;
    fin=fopen(input_user,"r");
    fscanf(fin,"%d%d",&n,&m);
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) fscanf(fin,"%lf",&user_fav[i][j]);
    fclose(fin);
    fin=fopen(input_item,"r");
    fscanf(fin,"%d%d",&n,&m);
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) fscanf(fin,"%lf",&item_fav[i][j]);
    fin=fopen(input_user,"r");
    fscanf(fin,"%d%d",&n,&m);
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++) fscanf(fin,"%lf",&user_fav[i][j]);
    fclose(fin);
    char filedir[10]="0_8.txt";
    filedir[2]=char('0'+last_month);
    for (int i=0;i<4;i++)
    {
        filedir[0]='0'+i;
        fin=fopen(filedir,"r");
        fscanf(fin,"%d%d",&n,&m);
        for (int j=0;j<n;j++)
            for (int k=0;k<m;k++) fscanf(fin,"%d",&d[i][j][k]);
        fclose(fin);
    }
    int tot=0;
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        {
            a[tot].user=i;
            a[tot].item=j;
            a[tot].value=0;
            for (int k=0;k<fav_num;k++) a[tot].value+=user_fav[i][k]*item_fav[k][j];
            tot++;
        }
    std::sort(a,a+(n*m));
    for (int k=0;k<tot;k++)
    {
        int i=a[tot].user,j=a[tot].item;
        if (((d[1][i][j]==0)&&((d[0][i][j]!=0)||(d[2][i][j]!=0)||(d[3][i][j]!=0)))
           &&(brand_click-->0)) a[k].value+=100;
    }
    std::sort(a,a+(n*m));
    for (int i=0;i<n;i++) user_dec[i]=1;
    for (int i=0;i<n*m;i++)
    {
        a[i].value*=user_dec[a[i].user];
        user_dec[a[i].user]/=2.0;
    }
    std::sort(a,a+(n*m));
    for (int i=0;i<n;i++) ans[i][0]=0;
    for (int i=0;i<(left+right)/2;i++) ans[a[i].user][++ans[a[i].user][0]]=a[i].item;
    fin=fopen("user_list.txt","r");
    fscanf(fin,"%d",&n);
    for (int i=0;i<n;i++) fscanf(fin,"%d",&user_list[i]);
    fclose(fin);
    fin=fopen("item_list.txt","r");
    fscanf(fin,"%d",&m);
    for (int i=0;i<m;i++) fscanf(fin,"%d",&item_list[i]);
    fclose(fin);
    FILE* fout=fopen(output,"w");
    for (int i=1;i<=n;i++)
    if (ans[i][0]>0)
    {
        fprintf(fin,"%d\t",user_list[i]);
        for (int j=1;j<=ans[i][0];j++)
        {
            if (j!=1) fprintf(fin,",");
            fprintf(fin,"%d",item_list[ans[i][j]]);
        }
        fprintf(fin,"\n");
    }
    fclose(fout);
}
