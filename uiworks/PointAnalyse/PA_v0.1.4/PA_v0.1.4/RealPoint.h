#pragma once
#include "global.h"
#include<stdlib.h>
#include<time.h>
#include<vector>
using namespace std;

class RealPoint
{
public:
	RealPoint(void);
	~RealPoint(void);
	vector< pair<int,int> > GetRealPoint( vector< pair<int,int> > );
	vector< pair<int,int> > KMeans( vector< pair<int,int> > ,int);
};

