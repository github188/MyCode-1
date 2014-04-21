#include "../include/Measure_1.h"
#include<stdio.h>
double v[5][1000][10000];

Measure::Measure()
{
    //ctor
}

Measure::~Measure()
{
    //dtor
}

/// Value equation: v[i][j]=0rate[i][j]+a1*1rate[i][j]+a2*2rate[i][j]+a3*3rate[i][j];

void Measure::Work(char* output_file,double a1,double a2,double a3)
{
    int n[4],m[4];
    char input_file[100]="0.txt";
    for (int i=0;i<4;i++)
    {
        input_file[0]='0'+i;
        FILE* fin=fopen(input_file,"r");
        fscanf(fin,"%d%d",&n[i],&m[i]);
        for (int k=0;k<n[i];k++) for (int j=0;j<m[i];j++) fscanf(fin,"%lf",&v[i][k][j]);
        fclose(fin);
    }
    for (int i=0;i<m[0];i++)
    {
        double all=0,s1=0,s2=0,s3=0,s0=0;
        for (int j=0;j<n[0];j++)
        {
            s0+=v[0][j][i];
            s1+=v[1][j][i];
            s2+=v[2][j][i];
            s3+=v[3][j][i];
        }
        if (s0==0) s0=1e9;
        if (s1==0) s1=1e9;
        if (s2==0) s2=1e9;
        if (s3==0) s3=1e9;
        for (int j=0;j<n[0];j++) v[4][j][i]=v[0][j][i]/s0+v[1][j][i]/s1*a1+v[2][j][i]/s2*a2+v[3][j][i]/s3*a3;
    }
    FILE* fout=fopen(output_file,"w");
    fprintf(fout,"%d %d\n",n[0],m[0]);
    for (int i=0;i<n[0];i++)
    {
        for (int j=0;j<m[0];j++) fprintf(fout,"%.3f ",v[4][i][j]);
        fprintf(fout,"\n");
    }
}
