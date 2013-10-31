//#include <QtCore/QCoreApplication>
#include<stdio.h>
#include"filsys.h"
#include"file.h"
#include"inode.h"
#include"string.h"

inode node[200];
file ofile[200];
int no_ofile;
FILE* stream;
char direction[100];
int no_dirway;
int dirway[20];    //存放当前路径inode
filsys superblock;

bool check(char* s,char* s1)
{
    int len,len1;
    len=strlen(s);
    len1=strlen(s1);
    if (len!=len1) {return false;}
    for (int i=0;i<len;i++) if (s[i]!=s1[i]) return false;
    return true;
}

int get_free_block()       //获取自由块
{
    if (superblock.s_nfree!=0)
    {
        if (superblock.s_nfree<199)
        {
            superblock.s_nfree--;
            return superblock.s_free[superblock.s_nfree+1];
        } else
        {
            if (superblock.s_nfree==200)
            {
                superblock.s_nfree--;
                int u=superblock.s_free[0];
                superblock.s_free[0]=0;
                return u;
            }
            superblock.s_nfree--;
            int u=superblock.s_free[0];
            int v=superblock.s_nfree-200;
            while (true)
            {
                char buf[1024];
                fseek(stream,(201+u)*1024,0);
                fread(buf,1,1024,stream);
                if (v>100)
                {
                    u=buf[0]*64+buf[1];
                    v-=100;
                    continue;
                }
                if (v==100) {return buf[0]*64+buf[1];}
                return buf[v*2]*64+buf[v*2+1];
            }
        }
    } else
    {
        char buf[1024];
        memset(buf,0,sizeof(buf));
        fseek(stream,0,2);
        fwrite(buf,1,1024,stream);
        superblock.s_fsize++;
        return superblock.s_fsize-1;
    }
}

void Init()    //初始化载入文件系统
{
    //memset(direction,0,sizeof(direction));
    //direction = "root\\";
    direction[0]='r';
    direction[1]='o';
    direction[2]='o';
    direction[3]='t';
    direction[4]='\\';
    stream=fopen("filevolume.sys","rb+");
    fseek(stream,0,0);
    char buf[1024];
    fread(buf,1,1024,stream);
    //fread(&superblock,2,sizeof(filsys)/2,stream);
    for (int i=0;i<200;i++)
    {
        fseek(stream,1024*(i+1),0);
        fread(&node[i],2,sizeof(inode)/2,stream);
    }
    no_dirway=1;
    dirway[0]=0;
    no_ofile=200;
    for (int i=0;i<200;i++) {ofile[i].f_inode=4096;}
}

void help()   //显示帮助信息
{
    printf("0.查看当前文件夹下文件----------dir\n");
    printf("1.创建文件夹------------------md\n");
    printf("2.创建文件--------------------vi\n");
    printf("3.删除文件--------------------del\n");
    printf("4.删除文件夹------------------deldir\n");
    printf("5.进入指定文件夹---------------cd\n");
    printf("6.返回上级文件夹---------------back\n");
    printf("7.显示帮助--------------------help\n");
    printf("8.打开文件--------------------open\n");
    printf("9.关闭文件--------------------close\n");
    printf("10.读文件内容-----------------read\n");
    printf("11.写文件内容-----------------write\n");
    printf("12.格式化--------------------format\n");
    printf("13.退出----------------------exit\n");
}

unsigned short namei(char fname[])    //在当前目录下查找文件/文件夹
{
    int item=0,all=node[dirway[no_dirway-1]].i_size;
    all=all/32;
    int count=0;

    while (item<all)
    {
        int u=32;
        if (item+32>=all) {u=all-item;}

        char buf[1024];
        fseek(stream,(201+node[dirway[no_dirway-1]].i_addr[count])*1024,0);
        int offset=(201+node[dirway[no_dirway-1]].i_addr[count])*1024;
        fread(buf,1,1024,stream);

        for (int i=0;i<u;i++)
        {
            char record[32];
            fseek(stream,offset,0);
            fread(record,1,32,stream);

            int len1,len2;
            len1=strlen(fname);
            len2=strlen(record);
            if (len1==len2)
            {
                bool check=true;
                for (int i=0;i<len1;i++)
                    if (record[i]!=fname[i]) {check=false;break;}
                if (check) {return record[30]*64+record[31];}
            }

            offset+=32;
        }
        item+=u;

        count++;
    }
    return 4096;
}

void dir()                 //察看文件夹目录
{
    int item=0,all=node[dirway[no_dirway-1]].i_size;
    all=all/32;

    int count=0;
    while (item<all)
    {
        int u=32;
        if (item+32>=all) {u=all-item;}

        char buf[1024];
        fseek(stream,(201+node[dirway[no_dirway-1]].i_addr[count])*1024,0);
        int offset=(201+node[dirway[no_dirway-1]].i_addr[count])*1024;
        fread(buf,1,sizeof(buf),stream);

        for (int i=0;i<u;i++)
        {
            char record[32];
            fseek(stream,offset,0);
            fread(record,1,32,stream);
            int node1=record[30]*64+record[31];
            int uu=(node[node1].i_mode & 16);
            if (uu==0) 
            {
                printf("%s",record);
                if ((node[node1].i_mode & IDIR)!=0) {printf("\\");}
                printf("\n");
                offset+=32;
            }
        }
        item+=u;

        count++;
    }
}

void ins_node(int fa,int child,char fname[])/**/
{
    int block,ptr;
    block=node[fa].i_size/1024;
    ptr=(node[fa].i_size%1024)/32;
    if (block>7) {printf("文件已满\n");return;}
    if (node[fa].i_addr[block]==4096) {node[fa].i_addr[block]=get_free_block();}
    int fa_block=node[fa].i_addr[block];

    char seg[32];
    memset(seg,0,sizeof(seg));
    for (int i=0;i<30;i++) {seg[i]=fname[i];}
    seg[30]=child/64;
    seg[31]=child%64;
    fseek(stream,(201+fa_block)*1024+32*ptr,0);
    fwrite(seg,1,32,stream);
    node[fa].i_size+=32;
}

int md(char fname[])       //增加文件夹
{
    if (namei(fname)!=4096) {return -1;}

    superblock.s_ninode--;
    int unode=superblock.s_inode[superblock.s_ninode];

    for (int i=0;i<8;i++) node[unode].i_addr[i]=0;
    node[unode].i_size=0;
    node[unode].i_mode=IDIR;
    ins_node(dirway[no_dirway-1],unode,fname);
}

int vi(char* fname,int mode)   //增加文件
{
    if (namei(fname)!=4096) {return -1;}

    superblock.s_ninode--;
    int unode=superblock.s_inode[superblock.s_ninode];
    for (int i=0;i<8;i++) node[unode].i_addr[i]=0;

    node[unode].i_size=0;
    node[unode].i_mode = ( IFILE | mode );
    ins_node(dirway[no_dirway-1],unode,fname);
}

void set_free_block(int id)   //添加自由块
{
    int u=superblock.s_nfree;
    if (u<199)
    {
        superblock.s_free[superblock.s_nfree+1]=id;
        superblock.s_nfree++;
        return;
    }
    if (u==199)
    {
        superblock.s_free[0]=id;
        superblock.s_nfree++;
        return;
    }
    int v=superblock.s_free[0];u-=200;
    while (u>=0)
    {
        char buf[1024];
        fseek(stream,(201+v)*1024,0);
        fread(buf,1,1024,stream);
        if (u<99)
        {
            buf[(u+1)*2]=id/64;
            buf[(u+1)*2+1]=id%64;
            fseek(stream,(201+v)*1024,0);
            fwrite(buf,1,1024,stream);
            break;
        }
        if (u==99)
        {
            buf[0]=id/64;
            buf[1]=id%64;
            fseek(stream,(201+v)*1024,0);
            fwrite(buf,1,1024,stream);
            break;
        }
        u-=100;
        v=buf[0]*64+buf[1];
    }
    superblock.s_nfree++;
}

void del(char* fname)    //删除文件
{
    int node_id=namei(fname);
    if (node_id<0) {printf("该目录下没有此文件！\n");}
    superblock.s_inode[superblock.s_ninode]=node_id;
    superblock.s_ninode++;
    for (int i=0;i<8;i++)
        if (node[node_id].i_addr[i]!=0) {set_free_block(node[node_id].i_addr[i]);}
    node[node_id].i_mode+=IDELETE;

}

void deldir(char* deldir1)  //删除文件夹
{
    int node_id=namei(deldir1);
    if (node_id==4096) {printf("该目录下没有此文件夹！\n");return;}
    int item=0,all=node[dirway[no_dirway-1]].i_size;
    all=all/32;
    int count=0;

    while (item<all)
    {
        int u=32;
        if (item+32>=all) {u=all-item;}

        char buf[1024];
        fseek(stream,(201+node[dirway[no_dirway-1]].i_addr[count])*1024,0);
        int offset=(201+node[dirway[no_dirway-1]].i_addr[count])*1024;
        fread(buf,1,1024,stream);

        for (int i=0;i<u;i++)
        {
            char record[32];
            fseek(stream,offset,0);
            fread(record,1,32,stream);

            int len2=strlen(record);
            char name[30];
            for (int j=0;j<len2;j++) {name[j]=record[j];}
            int id=record[30]*64+record[31];
            dirway[no_dirway]=id;
            no_dirway++;
            if ((node[id].i_mode & IFILE)!=0) {del(name);}
            else {deldir(name);}
            no_dirway--;

            offset+=32;
        }
        item+=u;

        count++;
    }
    for (int i=0;i<8;i++)
        if (node[node_id].i_addr[i]!=0) {set_free_block(node[node_id].i_addr[i]);}
    superblock.s_inode[superblock.s_ninode]=node_id;
    superblock.s_ninode++;
}

void cd(char fname[])  //进入下一层文件
{
    int node_id=namei(fname);
    if (node_id==4096) {printf("该目录下没有此文件夹！\n");return;}
    
    int len1,len2;len1=strlen(direction);len2=strlen(fname);
    for (int i=0;i<len2;i++) {direction[len1+i]=fname[i];}
    direction[strlen(direction)]='\\';
    
    dirway[no_dirway]=node_id;
    no_dirway++;
}

void back()    //返回上一层
{
    if (no_dirway==0) {return;}
    no_dirway--;
    int i=strlen(direction)-1;
    i--;
    while (direction[i]!='\\') {i--;}
    direction[i+1]=0;
}

int open(char* fname)  //打开文件
{
    int id=namei(fname);
    if (id<0) {printf("该目录下没有此文件！\n");return -1;}
    bool bo=false;int i;
    for (i=0;i<no_ofile;i++)
        if (ofile[i].f_inode==4096) {bo=true;break;}
    if (!bo) {printf("打开文件数过多！\n");return -1;}
    ofile[i].f_inode=id;
    return i;
}

void close(int id)  //关闭文件
{
    ofile[id].f_inode=-1;
}

void read(int id)   //读取文件
{
    if (ofile[id].f_inode<0) {printf("该编号没有打开文件\n");return;}
    if ((node[ofile[id].f_inode].i_mode & IREAD)==0) {printf("没有读权限\n");return;}
    int nodei=ofile[id].f_inode;
    int all=node[nodei].i_size;
    for (int i=0;i<7;i++)
    {
        int u=1024;
        if (u>all) {u=all;}
        if (u==0) {break;}
        fseek(stream,(201+node[nodei].i_addr[i])*1024,0);
        char buf[1024];
        memset(buf,0,sizeof(0));
        fread(buf,1,u,stream);
        printf("%s",buf);
        all-=u;
    }
    if (node[nodei].i_size>8*1024)
    {
        int cur_block=node[nodei].i_addr[7];
        int u=node[nodei].i_size-8*1024;
        while (true)
        {
            if (u<=0) {break;}
            char buf[1024];
            fseek(stream,(201+cur_block)*1024,0);
            fread(buf,1,1024,stream);
            if (u>99*1024)
            {
                for (int i=0;i<99;i++)
                {
                    char buf1[1024];
                    fseek(stream,(201+buf[(i+2)*2]*64+buf[(i+2)*2+1])*1024,0);
                    fread(buf1,1,1024,stream);
                    printf("%s",buf1);
                }
            } else
            {
                int i=0;
                while (u>0)
                {
                    int f=1024;
                    if (u<1024) {u=f;}
                    char buf1[1024];
                    fseek(stream,(201+buf[(i+2)*2]*64+buf[(i+2)*2+1])*1024,0);
                    fread(buf1,1,1024,stream);
                    printf("%s",buf1);
                    i++;
                }

            }
            cur_block=buf[2]*64+buf[3];
            u-=99*1024;
        }
    }
    printf("\n");
}

void write(int id)  //写入文件
{
    if (ofile[id].f_inode==4096) {printf("该编号没有打开文件\n");return;}
    if ((node[ofile[id].f_inode].i_mode & IWRITE)==0) {printf("没有写权限\n");return;}
    printf("输入文件内容，按回车结束。输入内容将写在文件末尾。\n");
    char buf[1000];
    gets(buf);
    int len=strlen(buf);
    int nodei=ofile[id].f_inode;
    int point=0;
    if (node[nodei].i_size+len>=8*1024) {printf("文件过大!\n");}
    {
        int u=node[nodei].i_size/1024;
        if (node[nodei].i_addr[u]==4096) {node[nodei].i_addr[u]=get_free_block();}
        int v=node[nodei].i_size%1024;
        while ((point<len)&&(u<7))
        {
            fseek(stream,(201+node[nodei].i_addr[u])*1024+v,0);
            fwrite(&buf[point],1,1,stream);
            v++;
            point++;
            if (v==1024)
            {
                u++;v=0;
                if ((u!=8)&&(point<len)) node[nodei].i_addr[u]=get_free_block();
            }
        }
    }

    node[nodei].i_size+=len;
}

void format()  //格式化
{
    //fclose(stream);
    stream=fopen("filevolume.sys","w");
    superblock.s_fsize=0;
    superblock.s_nfree=0;
    for (int i=0;i<200;i++) {superblock.s_free[i]=0;}
    superblock.s_isize=200;
    superblock.s_ninode=199;
    for (int i=0;i<199;i++) {superblock.s_inode[i]=i+1;}
    char buf[1024];
    memset(buf,0,sizeof(buf));
    //memcpy(buf,&superblock,sizeof(filsys));
    int uu=strlen(buf);
    //for (int i=0;i<1024;i++) {fprintf(stream,"%c",buf[i]);}
    fseek(stream,0,0);
    fwrite(&superblock,2,sizeof(filsys)/2,stream);

    node[0].i_size=0;node[0].i_mode=IDIR;
    for (int i=0;i<8;i++) {node[0].i_addr[i]=4096;}
    memset(buf,0,sizeof(buf));
    memcpy(buf,&node[0],sizeof(inode));
   // for (int i=0;i<1024;i++) {fprintf(stream,"%c",buf[i]);}
    fseek(stream,1024,0);
    fwrite(buf,1,1024,stream);

    node[0].i_mode=0;
    for (int i=0;i<8;i++) {node[0].i_addr[i]=-1;}
    memset(buf,0,sizeof(buf));
    memcpy(buf,&node[0],sizeof(inode));
    for (int i=0;i<199;i++)
    {
        //for (int i=0;i<1024;i++) {fprintf(stream,"%c",buf[i]);}
        fseek(stream,(2+i)*1024,0);
        fwrite(buf,1,1024,stream);
        node[i]=node[0];
    }
    node[199]=node[0];
    fclose(stream);
    memset(direction,0,sizeof(direction));
    direction[0]='r';
    direction[1]='o';
    direction[2]='o';
    direction[3]='t';
    direction[4]='\\';
}

void exit()   //退出文件系统
{
    char buf[1024];
    memset(buf,0,sizeof(buf));
    fseek(stream,0,0);
    fwrite(&superblock,2,sizeof(filsys)/2,stream);

    for (int i=0;i<200;i++)
    {
        memset(buf,0,sizeof(buf));
        memcpy(buf,&node[i],sizeof(inode));
        fseek(stream,(i+1)*1024,0);
        fwrite(buf,1,1024,stream);
    }
}

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);
    //format();
    Init();
    help();
    while (true)
    {
        char getin[100];
        printf("%s",direction);
        gets(getin);
        if (check(getin,"help")) {help();continue;}
        if (check(getin,"dir")) {dir();continue;}
        if ((getin[0]=='m')&&(getin[1]=='d'))
        {
            char fname[30];
            int len=strlen(getin);
            for (int i=3;i<len;i++) {fname[i-3]=getin[i];}
            if (md(fname)==-1) {printf("有重名文件夹！\n");}
            continue;
        }
        if ((getin[0]=='v')&&(getin[1]=='i'))
        {
            char fname[30];
            int len=strlen(getin);int i;
            for (i=3;i<len;i++) {if (getin[i]==' ') {break;}fname[i-3]=getin[i];}
            int mode=0;
            i++;
            for (;i<len;i++) {mode=mode*10+getin[i]-'0';}
            if (vi(fname,mode)==-1) {printf("有重名文件！\n");}
            continue;
        }
        if (check(getin,"back")) {back();continue;}
        if (check(getin,"format")) {format();Init();continue;}
        if ((getin[0]=='c')&&(getin[1]=='d'))
        {
            char fname[30];
            int len=strlen(getin);
            for (int i=3;i<len;i++) {fname[i-3]=getin[i];}
            cd(fname);
            continue;
        }
        if (check(getin,"exit")) {exit();break;}
        if ((getin[0]=='r')&&(getin[1]=='e')&&(getin[2]=='a')&&(getin[3]=='d'))
        {
            int len=strlen(getin);
            int id=0;
            for (int i=5;i<len;i++) {id=id*10+getin[i]-'0';}
            read(id);
            continue;
        }
        if ((getin[0]=='w')&&(getin[1]=='r')&&(getin[2]=='i')&&(getin[3]=='t')&&(getin[4]=='e'))
        {
            int len=strlen(getin);
            int id=0;
            for (int i=6;i<len;i++) {id=id*10+getin[i]-'0';}
            write(id);
            continue;
        }
        if ((getin[0]=='o')&&(getin[1]=='p')&&(getin[2]=='e')&&(getin[3]=='n'))
        {
            int len=strlen(getin);
            char fname[30];
            memset(fname,0,sizeof(fname));
            for (int i=5;i<len;i++) {fname[i-5]=getin[i];}
            printf("分配到的文件号：%d\n",open(fname));
            continue;
        }
        if ((getin[0]=='c')&&(getin[1]=='l')&&(getin[2]=='o')&&(getin[3]=='s')&&(getin[4]=='e'))
        {
            int len=strlen(getin);
            int id=0;
            for (int i=6;i<len;i++) {id=id*10+getin[i]-'0';}
            read(id);
            continue;
        }
        if ((getin[0]=='d')&&(getin[1]=='e')&&(getin[2]=='l')&&(getin[3]==' '))
        {
            int len=strlen(getin);
            char fname[30];
            memset(fname,0,sizeof(fname));
            for (int i=4;i<len;i++) {fname[i-4]=getin[i];}
            del(fname);
            continue;
        }
        if ((getin[0]=='d')&&(getin[1]=='e')&&(getin[2]=='l')&&(getin[3]=='d')&&(getin[4]=='i')&&(getin[5]=='r'))
        {
            int len=strlen(getin);
            char fname[30];
            memset(fname,0,sizeof(fname));
            for (int i=7;i<len;i++) {fname[i-7]=getin[i];}
            deldir(fname);
            continue;
        }
        printf("命令错误。显示提示信息请输入\"help\"命令\n");
    }
    return 0;
}
