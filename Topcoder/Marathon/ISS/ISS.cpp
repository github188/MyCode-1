#include"ISS.h"
#include<math.h>

double ISS::getInitialOrientation(double beta)
{
    ISS::beta=beta;
    yaw=0;
    y=nowd=0;z=1;
    return 0;
}

vector <double> ISS::getStateAtMinute(int minute)
{
    vector<double> Ans;Ans.clear();
    for (int i=0;i<4;i++) Ans.push_back(0.05);

    double alpha = (double)minute*360.0/92.0;
    double to_sunx=cos(beta)*sin(alpha)*cos(yaw)-sin(beta)*sin(yaw);
    double to_suny=-cos(beta)*sin(alpha)*sin(yaw)-sin(beta)*cos(yaw);
    double to_sunz=-cos(beta)*cos(alpha);

    double d,v;
    d=asin(to_suny/(sqrt(to_suny*to_suny+to_sunz*to_sunz)));
    if (beta>0) d=-d;
    if (nowd<d)
    {
        v=min(0.25,d-nowd);
        nowd+=v*0.6;
    }
    else
    {
        v=max(-0.25,d-nowd);
        nowd+=v*0.6;
    }

    for (int i=0;i<16;i+=2)
    {
        Ans.push_back(nowd);
        Ans.push_back(v);
        //Ans.push_back(0.05);
        //Ans.push_back(0.05);
    }
    return Ans;
}

