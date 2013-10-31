#pragma once
#include<vector>
#include<map>
#include"g_Segment.h"
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include"global.h"
using namespace std;

class GoodPoint
{
public:
	GoodPoint() {v.clear();time=num=0;t.clear();}
	int x,y;
	vector< pair <int,int> > v;
	vector< int > t;
	int time,num;
};

class RawPoint
{
public:
	RawPoint(void);
	~RawPoint(void);
	vector< pair<int,int> > GetRawPoint( vector< g_Segment > ,int,int);
private:
	vector< g_Segment > SegSet[10];
	vector< GoodPoint > gp;
	int time;
};

