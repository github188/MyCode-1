#include "line.h"

point line::CrossPoint(line b)
{
    point Ans;
	/*
    double a1=y1-y2,b1=x2-x1,c1=x1*y2-x2*y1;
    double a2=b.y1-b.y2,b2=b.x2-b.x1,c2=b.x1*b.y2-b.x2*b.y1;
    double D=a1*b2-a2*b1;
    Ans.x=(b1*c2-b2*c1)/D;
    Ans.y=(c1*a2-c2*a1)/D;
	*/
	Ans.ax1=x1;
	Ans.ay1=y1;
	Ans.ax2=x2;
	Ans.ay2=y2;
	Ans.bx1=b.x1;
	Ans.by1=b.y1;
	Ans.bx2=b.x2;
	Ans.by2=b.y2;
    return Ans;
}

bool line::checkPal(line b)
{
    return ((x2-x1)*(b.y2-b.y1)==(b.x2-b.x1)*(y2-y1));
}
