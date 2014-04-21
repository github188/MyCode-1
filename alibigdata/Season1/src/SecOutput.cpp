#include "../include/SecOutput.h"

SecOutput::SecOutput()
{
    //ctor
}

SecOutput::~SecOutput()
{
    //dtor
}

double item_point[10000];
bool compare_item_point(const std::pair<int,int> a,const std::pair<int,int> b)
{
    return item_point[a.second]>item_point[b.second];
}

void SecOutput::work(int brand_num,char* Output_File)
{
    int ans[1000][200];
    for (int i=0;i<1000;i++) ans[i][0]=0;
    FILE* fin;
    FILE* fout;
    fin=fopen("TopPair.txt","r");
    while (!feof(fin))
    {
        int x,y;fscanf(fin,"%d %d",&x,&y);
        ans[x][++ans[x][0]]=y;brand_num--;
    }
    fclose(fin);
    std::pair<int,int>ui_pair[30000];
    int num=0;
    fin=fopen("last_week_click_pair.txt","r");
    while (!feof(fin))
    {
        fscanf(fin,"%d %d",&ui_pair[num].first,&ui_pair[num].second);
        num++;
    }
    fclose(fin);
    //sort(ui_pair,ui_pair+num,compare_item_point);
    for (int i=0;i<num;i++)
    {
        if (brand_num==0) break;
        bool check=true;
        for (int j=1;j<=ans[ui_pair[i].first][0];j++)
        if (ans[ui_pair[i].first][j]==ui_pair[i].second) {check=false;break;}
        if ((check)&&(ans[ui_pair[i].first][0]<100))
        {
            ans[ui_pair[i].first][++ans[ui_pair[i].first][0]]=ui_pair[i].second;
            brand_num--;
        }
    }
    printf("ready for output.\n");
    int user[1000],item[10000];
    fin=fopen("user_list.txt","r");
    int n;fscanf(fin,"%d",&n);
    for (int i=1;i<=n;i++) fscanf(fin,"%d",&user[i]);
    fclose(fin);
    fin=fopen("item_list.txt","r");
    fscanf(fin,"%d",&n);
    for (int i=1;i<=n;i++) fscanf(fin,"%d",&item[i]);
    fclose(fin);
    fout=fopen(Output_File,"w");
    for (int i=1;i<1000;i++)
    if (ans[i][0])
    {
        fprintf(fin,"%d\t",user[i]);
        for (int j=1;j<=ans[i][0];j++)
        {
            if (j>1) fprintf(fin,",");
            fprintf(fin,"%d",item[ans[i][j]]);
        }
        fprintf(fin,"\n");
    }
}
