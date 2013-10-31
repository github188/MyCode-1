#include"matrix.h"

int main()
{
    Matrix<double> a(1,2,3,4,5);
    double b[16]={3,3,3,3,
                  3,3,3,3,
                  3,3,3,3,
                  3,3,3,3};
    Matrix c(b);
    Matrix d=a+b;
    d.print();
    return 0;
}
