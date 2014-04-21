#include<stdio.h>
#include<string.h>
#include"../include/CalcF1.h"
#include<map>

int d1[1000][10000];

void CalcF1(char* result_file)
{
    double right_band=0,real_all_band=0,my_all_band=0,p=0,r=0,f1=0;

    int n,m;
    FILE* fin=fopen("1.txt","r");
    fscanf(fin,"%d%d",&n,&m);
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) {fscanf(fin,"%d",&d1[i][j]); if (d1[i][j]) real_all_band+=1.0;}
    fclose(fin);

    std::map<int,int> user,item;user.clear();item.clear();
    fin=fopen("user_list.txt","r");
    fscanf(fin,"%d",&n);
    for (int i=0;i<n;i++)
    {
        int x;fscanf(fin,"%d",&x);
        user[x]=i+1;
    }
    fclose(fin);
    fin=fopen("item_list.txt","r");
    fscanf(fin,"%d",&n);
    for (int i=0;i<n;i++)
    {
        int x;fscanf(fin,"%d",&x);
        item[x]=i+1;
    }
    fclose(fin);

    char s[1000];
    fin=fopen(result_file,"r");
    while (fscanf(fin,"%d\t%s",&n,s)!=EOF)
    {
        int x=user[n]-1;
        int len=strlen(s),h=0;
        while (h<len)
        {
            int y=0;
            while ((h<len)&&(s[h]!=',')) y=y*10+s[h++]-'0';h++;
            y=item[y]-1;
            my_all_band+=1.0;
            if (d1[x][y]) right_band+=1.0;
        }
    }
    p=right_band/my_all_band;
    r=right_band/real_all_band;
    f1=(2.0*p*r)/(p+r);
    printf("p=%.5f%\nr=%.5f%\nf1=%.5f%\n",100.0*p,100.0*r,100.0*f1);
}
