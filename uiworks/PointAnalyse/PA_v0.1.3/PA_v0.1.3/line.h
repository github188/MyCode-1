#pragma once
#include"global.h"

struct line
{
    int x1,y1,x2,y2;
    bool dir;
    bool operator<(const line b) const
    {
        if (dir&(!b.dir)) return false;
        if (b.dir&(!dir)) return true;
        return ((x2-x1)*(b.y2-b.y1)>(b.x2-b.x1)*(y2-y1));
    }
    bool checkPal(line);
    point CrossPoint(line);
};

struct Polygen
{
	vector< line > line;
	vector< point > point;
	int type;
	Polygen() {line.clear();}
	void LtoP()
	{
		point.clear();
		for (int i=0;i<line.size();i++)
		{
			int j=i+1;if (j==line.size()) j=0;
			point.push_back(line[i].CrossPoint(line[j]));
		}
	}
};