#pragma once
#include<vector>
#include<map>
#include"g_Segment.h"
#include<string.h>
#include<algorithm>
#include<stdlib.h>
#include"global.h"
using namespace std;

class RawPoint
{
public:
	RawPoint(void);
	~RawPoint(void);
	vector< ValuedPoint > GetRawPoint( vector< g_Segment > ,int,int);
private:
	vector< g_Segment > SegSet[10];
};

