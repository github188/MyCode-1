#include "RealPoint.h"
#include <set>

RealPoint::RealPoint(void)
{
	srand(time(NULL));
}


RealPoint::~RealPoint(void)
{
}

//2013/1/29
vector< pair<int,int> > RealPoint::GetRealPoint( vector< ValuedPoint > RawPoint)
{
	set< ValuedPoint > PointSet;PointSet.clear();
	vector< ValuedPoint > ACPoint;ACPoint.clear();
	for (int i=0;i<RawPoint.size();i++) 
	{
		ValuedPoint tmp=RawPoint[i];
		PointSet.insert(tmp);
	}
	int MaxValue=0;
	while (PointSet.size()>0)
	{
		ValuedPoint tmpPoint;tmpPoint.value=-1;
		for (set< ValuedPoint >::iterator i=PointSet.begin();i!=PointSet.end();i++)
			if (i->value>tmpPoint.value) tmpPoint=*i;
		if (MaxValue==0) MaxValue=tmpPoint.value;
		else if (tmpPoint.value<MaxValue-4) break;

		set< ValuedPoint > CurPointSet;CurPointSet.clear();
		CurPointSet.insert(tmpPoint);
		PointSet.erase(tmpPoint);
		int Num=tmpPoint.value;
		ValuedPoint AnsP;AnsP.x=AnsP.y=AnsP.value=0;
		ACPoint.push_back(tmpPoint);
		int pos=ACPoint.size()-1;
		ACPoint[pos].x*=ACPoint[pos].value;
		ACPoint[pos].y*=ACPoint[pos].value;
		while (true)
		{
			bool isUpdated=false;
			set< ValuedPoint >::iterator i=PointSet.begin();
			while (i!=PointSet.end())
			{
				bool isIns=false;
				for (set< ValuedPoint >::iterator j=CurPointSet.begin();j!=CurPointSet.end();j++)
				if (dist(*i,*j)<=100)
				{
					isIns=true;
					ACPoint[pos].x+=i->x * i->value;
					ACPoint[pos].y+=i->y * i->value;
					ACPoint[pos].value+=i->value;
					ValuedPoint tmp=*i++;
					PointSet.erase(tmp);
					Num+=tmpPoint.value;
					if (tmp.value==tmpPoint.value) CurPointSet.insert(tmp);
					break;
				}

				if (!isIns) i++; else {isUpdated=true;}
			}	   
			if (!isUpdated) break;
		}
		ACPoint[pos].x/=Num;
		ACPoint[pos].y/=Num;
		//MaxValue=MaxValue>ACPoint[pos].value?MaxValue:ACPoint[pos].value;
	}

	sort(ACPoint.begin(),ACPoint.end());
	vector< pair<int,int> > Ans;Ans.clear();
	//for (int i=0;i<ACPoint.size();i++)
		//if (ACPoint[i].value>MaxValue/2)
		//	Ans.push_back(pair<int,int>(ACPoint[i].x*PICSCALE/SCALE,ACPoint[i].y*PICSCALE/SCALE));
	if (ACPoint.size()==1) {Ans.push_back(pair<int,int>(ACPoint[0].x*PICSCALE/SCALE,ACPoint[0].y*PICSCALE/SCALE));}
	else
	{
		int tmp=ACPoint.size();
		Ans.push_back(pair<int,int>(ACPoint[tmp-1].x*PICSCALE/SCALE,ACPoint[tmp-1].y*PICSCALE/SCALE));
		Ans.push_back(pair<int,int>(ACPoint[tmp-2].x*PICSCALE/SCALE,ACPoint[tmp-2].y*PICSCALE/SCALE));
	}
	return Ans;
}

int RealPoint::dist(ValuedPoint a,ValuedPoint b)
{
	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

//2013/1/24
/*
vector< pair<int,int> > RealPoint::KMeans( vector< ValuedPoint > Point,int K)
{
	vector< pair<int,int> > Ans;Ans.clear();
	for (int i=0;i<K;i++) Ans.push_back(pair<int,int>(rand()%10000,rand()%5000));
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
				int tmpR1=(Point[i].x-Ans[j].first)*(Point[i].x-Ans[j].first)
					+(Point[i].y-Ans[j].second)*(Point[i].y-Ans[j].second);
				//tmpR1*=Point[i].value*Point[i].value;
				if (tmpR1<tmpR) {tmpR=tmpR1;Cid=j;}
			}
			Num[Cid]+=Point[i].value;
			tmpAns[Cid].first+=Point[i].x*Point[i].value;
			tmpAns[Cid].second+=Point[i].y*Point[i].value;
		}
		for (int i=0;i<Ans.size();i++) if (Num[i]!=0) {tmpAns[i].first/=Num[i];tmpAns[i].second/=Num[i];}
		
		int max=0;
		for (int i=0;i<Ans.size();i++) 
		{
				int u=abs(tmpAns[i].first-Ans[i].first)+abs(tmpAns[i].second-Ans[i].second);
				if (u>max) max=u;
		}
		
		Ans=tmpAns;
		if (max<=SCALE*FIGR) break;
	}
	
	vector< pair<int,int> > Ans1;Ans1.clear();
	for (int i=0;i<Ans.size();i++) 
		if (Ans[i].first+Ans[i].second>0) Ans1.push_back(Ans[i]);
	return Ans1;
}
   
vector< pair<int,int> > RealPoint::GetRealPoint( vector< ValuedPoint > RawPoint)
{
	vector< pair<int,int> > Ans;Ans.clear();
		vector<int>Num;
	
	int R=0,K=0;
	do
	{
		R=0;
		if (K+1>RawPoint.size()) break;
		K++;Ans.clear();
		Ans = KMeans(RawPoint,K);
		Num.clear();
		for (int i=0;i<Ans.size();i++) Num.push_back(0);
		for (int i=0;i<RawPoint.size();i++)
		{
			int tmpR=1e9;int Cid=-1;
			for (int j=0;j<Ans.size();j++)
			{
				int tmpR1=(RawPoint[i].x-Ans[j].first)*(RawPoint[i].x-Ans[j].first)
					     +(RawPoint[i].y-Ans[j].second)*(RawPoint[i].y-Ans[j].second);
				//tmpR1*=RawPoint[i].value*RawPoint[i].value;
				if (tmpR1<tmpR) {tmpR=tmpR1;Cid=j;}
			}
			Num[Cid]+=RawPoint[i].value;
			if (tmpR>R) {R=tmpR;}
		}

	} while ((R>SCALE*SCALE*FIGR)&&(!check(Num)));
	
	int tot=0,num=0,sum=0;
	vector<int> tmpNum=Num;
	for (int i=0;i<Num.size();i++) tot+=Num[i];tot=tot*8/10;
	sort(tmpNum.begin(),tmpNum.end());
	for (int i=tmpNum.size()-1;i>=0;i--)
	{
		sum+=tmpNum[i];
		num++;
		if (sum>=tot) break;
	} 

	vector< pair<int,int> > tAns;tAns.clear();
	for (int i=0;i<Ans.size();i++)
		if (Num[i]>=tmpNum[tmpNum.size()-num]) tAns.push_back(Ans[i]);
	for (int i=0;i<tAns.size();i++)
	{
		tAns[i].first=tAns[i].first*PICSCALE/SCALE;
		tAns[i].second=tAns[i].second*PICSCALE/SCALE;
	}
	return tAns;
}

bool  RealPoint::check(vector<int> a)
{
	if (a.size()==1) return false;
	int tot=0,num=0,sum=0;
	for (int i=0;i<a.size();i++) tot+=a[i];tot=tot*8/10;
	sort(a.begin(),a.end());
	for (int i=a.size()-1;i>=0;i--)
	{
		sum+=a[i];
		num++;
		if (sum>=tot) break;
	}
	if ((num<=a.size()/3)||(a.size()<3)) return true;
	return false;
}
*/