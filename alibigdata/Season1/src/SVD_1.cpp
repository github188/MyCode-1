#include "../include/SVD_1.h"
#include<stdio.h>
#include "../Eigen/Dense"
#include<iostream>
using namespace std;

SVD::SVD()
{
    //ctor
}

SVD::~SVD()
{
    //dtor
}

void SVD::Work(char* input_file,char* output_item,char* output_user,int k)
{
    FILE* fin=fopen(input_file,"r");
    int n,m;
    fscanf(fin,"%d%d",&n,&m);
    Eigen::MatrixXf matrix(n, m);
    for (int i=0;i<n;i++)
        for (int j=0;j<m;j++)
        {
            double x;fscanf(fin,"%lf",&x);
            matrix(i,j)=x;
        }
    fclose(fin);
    int tmp=(n<m)?n:m;
    printf("Start...\n");
    Eigen::JacobiSVD<Eigen::MatrixXf> svd(matrix, Eigen::ComputeFullU | Eigen::ComputeFullV);
    printf("End...\n");
    Eigen::MatrixXf U(n, tmp);
    U = svd.matrixU();
    Eigen::MatrixXf V(tmp, m);V = svd.matrixV();
    FILE* fout=fopen(output_user,"w");
    fprintf(fout,"%d %d\n",n,k);
    cout<<U.innerSize()<<endl;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<k;j++) fprintf(fout,"%.6f ",U(i,j));
        fprintf(fout,"\n");
    }
    fclose(fout);
    cout<<V.innerSize()<<endl;
    fout=fopen(output_item,"w");
    fprintf(fout,"%d %d\n",k,m);
    for (int i=0;i<k;i++)
    {
        for (int j=0;j<m;j++)
        {
            //cout<<i<<" "<<j<<endl;
            fprintf(fout,"%lf ",V(i,j));
        }
        fprintf(fout,"\n");
    }
    fclose(fout);
}
