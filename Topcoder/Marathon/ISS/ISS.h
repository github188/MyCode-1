#ifndef ISS_H_INCLUDED
#define ISS_H_INCLUDED
#include<vector>
using namespace std;

class ISS
{
    public:
    double getInitialOrientation(double beta);
    vector <double> getStateAtMinute(int minute);

    private:
    double beta,yaw,x,y,z,nowv,nowd;
};

#endif // ISS_H_INCLUDED

