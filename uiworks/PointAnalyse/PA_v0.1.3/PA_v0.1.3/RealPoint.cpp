#include "RealPoint.h"


RealPoint::RealPoint(void)
{
	times=0;
	PolySet=( vector<Polygen>* )malloc(10*sizeof(vector<Polygen>));
	for (int i=0;i<10;i++) PolySet[i].clear();
}


RealPoint::~RealPoint(void)
{
}

vector < ValuedPoint > RealPoint::Update(vector<Polygen>* s)
{
	vector < ValuedPoint > Ans;Ans.clear();
	for (int i=0;i<10;i++) 
		if (s[i].size()>0)
		{
			PolySet[i].clear();
			for (int j=0;j<s[i].size();j++) PolySet[i].push_back(s[i][j]);
		}

	vector< Polygen > P;P.clear();
	for (int i=0;i<PolySet[0].size();i++)
	  for (int j=0;j<PolySet[0].size();j++)
	return Ans;
}