#pragma once
#include "global.h"
#include<stdlib.h>
#include<time.h>
#include<vector>
#include<algorithm>
using namespace std;

class RealPoint
{
public:
	RealPoint(void);
	~RealPoint(void);
	vector< pair<int,int> > GetRealPoint( vector< ValuedPoint > );
private:
	int dist(ValuedPoint,ValuedPoint);

	//vector< pair<int,int> > KMeans( vector< ValuedPoint > ,int);
	//bool check(vector<int>);
};

