#include"matrix.h"
#include<stdio.h>

Matrix::Matrix(elemtype a1 ,elemtype a2 ,elemtype a3 ,elemtype a4 ,
             elemtype a5 ,elemtype a6 ,elemtype a7 ,elemtype a8 ,
             elemtype a9 ,elemtype a10 ,elemtype a11 ,elemtype a12 ,
             elemtype a13 ,elemtype a14 ,elemtype a15 ,elemtype a16 )
             {
                 num[0][0]=a1;num[0][1]=a2;num[0][2]=a3;num[0][3]=a4;
                 num[1][0]=a5;num[1][1]=a6;num[1][2]=a7;num[1][3]=a8;
                 num[2][0]=a9;num[2][1]=a10;num[2][2]=a11;num[2][3]=a12;
                 num[3][0]=a13;num[3][1]=a14;num[3][2]=a15;num[3][3]=a16;
             }

Matrix::Matrix(elemtype a[16])
{

    for (int i=0;i<4;i++)
      for (int j=0;j<4;j++) num[i][j]=a[i*4+j];
}
Matrix::Matrix(int n,int m)
{
}

Matrix Matrix::operator+ ( Matrix a)
{
    elemtype b[16];
    for (int i=0;i<4;i++)
      for (int j=0;j<4;j++)
       b[i*4+j]=this->num[i][j]+a(i,j);
    Matrix m(b);
    return m;
}
Matrix Matrix::operator* ( Matrix a)
{
    elemtype b[16];
    for (int i=0;i<4;i++)
      for (int j=0;j<4;j++) {b[i*4+j]=0;
        for (int k=0;k<4;k++)
        b[i*4+j]+=this->num[i][k]*a(k,j);}
    Matrix m(b);
    return m;
}
void Matrix::operator+=( Matrix a)
{
    for (int i=0;i<4;i++)
      for (int j=0;j<4;j++)
      this->num[i][j]+=a(i,j);
}

void Matrix::print()
{
    for (int i=0;i<4;i++)
    {
        for (int j=0;j<4;j++) printf("%.5f ",num[i][j]);
        printf("\n");
    }
}
elemtype& Matrix::operator()( int r, int c) {return num[r][c];}
elemtype Matrix::operator()( int r, int c) const {return num[r][c];}
