#include "RawPoint.h"


RawPoint::RawPoint(void)
{
	hash.clear();
	for (int i=0;i<10;i++) SegSet[i].clear();
}


RawPoint::~RawPoint(void)
{
}

vector< ValuedPoint > RawPoint::GetRawPoint( vector< g_Segment > Segment,int x_len,int y_len)
{
	bool used[10];for (int i=0;i<10;i++) used[i]=false;

	for (int i=0;i<Segment.size();i++)
	{
		if (!used[Segment[i].type])
		{
			int type=Segment[i].type;
			while (SegSet[type].size()>0)
			{
				g_Segment tmpSeg=SegSet[type][SegSet[type].size()-1];SegSet[type].pop_back();
				ChangePointValue(tmpSeg,-1,x_len,y_len);
			}
		}

		ChangePointValue(Segment[i],1,x_len,y_len);
		used[Segment[i].type]=true;
		SegSet[Segment[i].type].push_back(Segment[i]);
	}

	int MaxPointValue=0;
	for (map<int,int>::iterator i=hash.begin();i!=hash.end();i++)
		if (i->second>MaxPointValue) {MaxPointValue=i->second;}

	vector< ValuedPoint > Ans;Ans.clear();
	MaxPointValue-=MaxPointValue/7;

	for (map<int,int>::iterator i=hash.begin();i!=hash.end();i++)
	if (i->second >= MaxPointValue)
	{
		ValuedPoint tmp;
		tmp.x= i->first / (y_len+2);
		tmp.y= i->first % (y_len+2);
		tmp.value=i->second;
		Ans.push_back(tmp);
	}
	return Ans;
}
