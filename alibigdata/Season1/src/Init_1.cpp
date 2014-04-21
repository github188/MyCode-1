/***
The class is transform the raw data to 4 matrix. Different matrix means the different status.

CreatedBy: Chenjiyuan,20140315
***/
#include "../include/Init_1.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<map>

Init::Init()
{
    //ctor
}

Init::~Init()
{
    //dtor
}

void Init::Work(char* input_file,int last_month)
{
    FILE* fin=fopen(input_file,"r");
    std::map <long long,int> status[4],status_last[4];
    std::map<int,int> user,item;
    char s[100];fgets(s,100,fin);
    int user_rev[30000],item_rev[30000];
    user.clear();item.clear();
    int user_num=0,item_num=0;
    for (int i=0;i<4;i++) {status[i].clear();status_last[i].clear();}
    int us,it,st,line=0;
    while (!feof(fin))
    {
        line++;
        FILE* f1=fopen("q.txt","w");fprintf(f1,"%d\n",line);
        fclose(f1);
        fscanf(fin,"%d,%d,%d,%s\n",&us,&it,&st,s);
        if (user[us]==0) {user[us]=++user_num;user_rev[user_num]=us;}
        if (item[it]==0) {item[it]=++item_num;item_rev[item_num]=it;}
        long long tmp=(long long)user[us]*(long long)30000+(long long)item[it];
        if (status[st][tmp]==0) status[st][tmp]=1; else status[st][tmp]=status[st][tmp]+1;
        if (s[0]==char('0'+last_month)) if (status_last[st][tmp]==0) status_last[st][tmp]=1; else status_last[st][tmp]=status_last[st][tmp]+1;
    }
    FILE *fout;
    fout=fopen("user_list.txt","w");
    fprintf(fout,"%d\n",user_num);
    for (int i=1;i<=user_num;i++) fprintf(fout,"%d\n",user_rev[i]);
    fclose(fout);
    fout=fopen("item_list.txt","w");
    fprintf(fout,"%d\n",item_num);
    for (int i=1;i<=item_num;i++) fprintf(fout,"%d\n",item_rev[i]);
    fclose(fout);
    free(fout);
    char output_file[100]="0.txt";
    char output_file_last[100]="0_0.txt";
    output_file_last[2]=char('0'+last_month);
    FILE* fout_last;
    for (int i=0;i<4;i++)
    {
        FILE *fout;
        FILE* fout_last;
        output_file[0]='0'+i;
        output_file_last[0]='0'+i;
        fout=fopen(output_file,"w");
        fout_last=fopen(output_file_last,"w");
        fprintf(fout,"%d %d\n",user_num,item_num);
        fprintf(fout_last,"%d %d\n",user_num,item_num);
        for (int j=1;j<=user_num;j++)
        {
            for (int k=1;k<=item_num;k++)
            {
                fprintf(fout,"%d ",status[i][(long long)j*(long long)30000+(long long)k]);
                fprintf(fout_last,"%d ",status_last[i][(long long)j*(long long)30000+(long long)k]);
            }
            fprintf(fout,"\n");
            fprintf(fout_last,"\n");
        }
        fclose(fout);
        fclose(fout_last);
        free(fout);
        free(fout_last);
    }
    fclose(fin);
    free(fin);
}
