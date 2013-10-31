#include "RealPoint.h"

RealPoint::RealPoint(void)
{
	srand(time(NULL));
}


RealPoint::~RealPoint(void)
{
}

vector< pair<int,int> > RealPoint::KMeans( vector< pair<int,int> > Point,int K)
{
	vector< pair<int,int> > Ans;Ans.clear();
	for (int i=0;i<K;i++) Ans.push_back(Point[i]);
	while (true)
	{
		vector< pair<int,int> > tmpAns;tmpAns.clear();
	    for (int i=0;i<K;i++) tmpAns.push_back(pair<int,int>(0,0));
		vector< int > Num;Num.clear();
		for (int i=0;i<K;i++) Num.push_back(0);
		for (int i=0;i<Point.size();i++)
		{
			int tmpR=1e9,Cid=-1;
			for (int j=0;j<Ans.size();j++)
			{
				int tmpR1=(Point[i].first-Ans[j].first)*(Point[i].first-Ans[j].first)
					     +(Point[i].second-Ans[j].second)*(Point[i].second-Ans[j].second);
				if (tmpR1<tmpR) {tmpR=tmpR1;Cid=j;}
			}
			Num[Cid]++;
			tmpAns[Cid].first+=Point[i].first;
			tmpAns[Cid].second+=Point[i].second;
		}
		for (int i=0;i<Ans.size();i++) if (Num[i]!=0) {tmpAns[i].first/=Num[i];tmpAns[i].second/=Num[i];}
		
		int max=0;
		for (int i=0;i<Ans.size();i++) 
		{
				int u=abs(tmpAns[i].first-Ans[i].first)+abs(tmpAns[i].second-Ans[i].second);
				if (u>max) max=u;
		}
		
		Ans=tmpAns;
		if (max<=SCALE) break;
	}
	
	vector< pair<int,int> > Ans1;Ans1.clear();
	for (int i=0;i<Ans.size();i++) 
		if (Ans[i].first+Ans[i].second>0) Ans1.push_back(Ans[i]);
	return Ans1;
}

vector< pair<int,int> > RealPoint::GetRealPoint( vector< pair<int,int> > RawPoint)
{
	vector< pair<int,int> > Ans;Ans.clear();
	
	int R=0,K=0;
	do
	{
		R=0;
		if (K+1>RawPoint.size()) break;
		K++;Ans.clear();
		Ans = KMeans(RawPoint,K);
		for (int i=0;i<RawPoint.size();i++)
		{
			int tmpR=1e9;
			for (int j=0;j<Ans.size();j++)
			{
				int tmpR1=(RawPoint[i].first-Ans[j].first)*(RawPoint[i].first-Ans[j].first)
					     +(RawPoint[i].second-Ans[j].second)*(RawPoint[i].second-Ans[j].second);
				if (tmpR1<tmpR) tmpR=tmpR1;
			}
			if (tmpR>R) R=tmpR;
		}

	} while (R>SCALE*SCALE*FIGR);
	if (Ans.size()>1)
	{
		int o=0;
	}
	for (int i=0;i<Ans.size();i++)
	{
		Ans[i].first=Ans[i].first*PICSCALE/SCALE;
		Ans[i].second=Ans[i].second*PICSCALE/SCALE;
	}
	/*
	Ans.push_back(pair<int,int>(0,0));
	for (int i=0;i<RawPoint.size();i++)
	{
		Ans[0].first+=RawPoint[i].first;
		Ans[0].second+=RawPoint[i].second;
	}
	Ans[0].first=(Ans[0].first*PICSCALE/SCALE)/RawPoint.size();
	Ans[0].second=(Ans[0].second*PICSCALE/SCALE)/RawPoint.size();
	*/
	return Ans;
}