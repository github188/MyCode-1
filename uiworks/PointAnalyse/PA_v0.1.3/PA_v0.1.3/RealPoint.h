#pragma once
#include<vector>
#include<string.h>
#include"ConvexPolyCross.h"
#include<malloc.h>
using namespace std;

struct PolySet
{
	vector< vector< point > > poly[10];
	int size,num,time;

	PolySet() 
	{ 
		for (int i=0;i<10;i++) poly[i].clear(); 
	}
};

class RealPoint
{
public:
	RealPoint(void);
	~RealPoint(void);
	vector < ValuedPoint > Update(vector<Polygen>*);
private:
	vector<Polygen>* PolySet;
	int times;
};
