#include<stdio.h>
#include<stdlib.h>

template<typename elemtype>
class Matrix
{
    public:
      Matrix(elemtype a1=0,elemtype a2=0,elemtype a3=0,elemtype a4=0,
             elemtype a5=0,elemtype a6=0,elemtype a7=0,elemtype a8=0,
             elemtype a9=0,elemtype a10=0,elemtype a11=0,elemtype a12=0,
             elemtype a13=0,elemtype a14=0,elemtype a15=0,elemtype a16=0);
      Matrix(elemtype a[16]);
      Matrix(int n,int m);
      Matrix operator+ ( Matrix );
      Matrix operator* ( Matrix );
      void operator+=( Matrix );
      void print();
      elemtype& operator()( int , int );
      elemtype operator()( int , int ) const;
      ~Matrix() { for (int i=0;i<_row;i++) free(num[i]);free(num); }

    private:
      elemtype** num;
      int _row,_col;
};
