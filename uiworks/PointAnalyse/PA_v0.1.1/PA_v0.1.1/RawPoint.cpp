#include "RawPoint.h"


RawPoint::RawPoint(void)
{
	for (int i=0;i<10;i++) SegSet[i].clear();
	time=0;
}

bool xcmp0(g_Segment a,g_Segment b)
{
	return a.X1<b.X1;
}

bool ycmp5(g_Segment a,g_Segment b)
{
	return a.Y1<b.Y1;
}
bool typecmp(g_Segment a,g_Segment b)
{
	return a.type<b.type;
}

RawPoint::~RawPoint(void)
{
}

struct ValuedPoint
{
	int x,y;
	int xx[3],yy[3];
	int num;
};

vector< pair<int,int> > RawPoint::GetRawPoint( vector< g_Segment > Segment,int x_len,int y_len)
{
	vector< pair< int, int> > Ans;Ans.clear();
	sort(Segment.begin(),Segment.end(),typecmp);
	int head=0;
	while (head<Segment.size())
	{
		int h=head;head++;
		while ((head<Segment.size())&&(Segment[head].type==Segment[h].type)) head++;
		SegSet[Segment[h].type].clear();
		for (int i=h;i<head;i++) SegSet[Segment[i].type].push_back(Segment[i]);
		if (Segment[h].type<5) sort(SegSet[Segment[h].type].begin(),SegSet[Segment[h].type].end(),xcmp0);
		else sort(SegSet[Segment[h].type].begin(),SegSet[Segment[h].type].end(),ycmp5);
	}

	vector< ValuedPoint > tmpS;tmpS.clear();
	for (int i=0;i<SegSet[0].size();i++)
	{
		int ii=i;
		while ((ii+1<SegSet[0].size())&&(ii-i<=5)&&((SegSet[0][ii+1].X1==SegSet[0][ii].X1+1)||(SegSet[0][ii+1].Y1==SegSet[0][ii].Y1+1)))ii++;
		i=(i+ii)/2;
		for (int j=0;j<SegSet[5].size();j++)
		{
		    int jj=j;
		    while ((jj+1<SegSet[5].size())&&(jj-j<=5)&&((SegSet[5][jj+1].X1==SegSet[5][jj].X1+1)||(SegSet[5][jj+1].Y1==SegSet[5][jj].Y1+1)))jj++;
		    j=(j+jj)/2;
			ValuedPoint tmpV;
			tmpV.x=SegSet[0][i].X1;tmpV.y=SegSet[5][j].Y1;
			tmpV.xx[0]=tmpV.xx[1]=tmpV.xx[2]=0;
			tmpV.yy[0]=tmpV.yy[1]=tmpV.yy[2]=0;
			tmpV.num=0;
			tmpS.push_back(tmpV);
			j=jj;
		}
		i=ii;
	}
	if (tmpS.size()==0) return Ans;
	for (int i=1;i<10;i++)
	{
		if (i==5) {i++;continue;}
		for (int k=0;k<SegSet[i].size();k++)
		{
			int f=k;
			while ((f+1<SegSet[i].size())&&((SegSet[i][f+1].X1==SegSet[i][f].X1+1)||(SegSet[i][f+1].Y1==SegSet[i][f].Y1+1))) f++;
		    int min=0;k=(k+f)/2;
		    for (int j=1;j<tmpS.size();j++)
		    {
				int area2=(tmpS[j].x-SegSet[i][k].X1)*(SegSet[i][k].Y2-SegSet[i][k].Y1)-(tmpS[j].y-SegSet[i][k].Y1)*(SegSet[i][k].X2-SegSet[i][k].X1);
				bool check=(area2*area2<(SegSet[i][k].Y2-SegSet[i][k].Y1)*(SegSet[i][k].Y2-SegSet[i][k].Y1)+(SegSet[i][k].X2-SegSet[i][k].X1)*(SegSet[i][k].X2-SegSet[i][k].X1));
				if (check) tmpS[j].num++; 
		    }
			int xt=2*(SegSet[i][k].X2-SegSet[i][k].X1)*tmpS[min].y-2*(SegSet[i][k].X2-SegSet[i][k].X1)*SegSet[i][k].Y1-2*(tmpS[min].x-SegSet[i][k].X1)*(SegSet[i][k].Y2-SegSet[i][k].Y1);
			int yt=2*(SegSet[i][k].Y2-SegSet[i][k].Y1)*tmpS[min].x-2*(SegSet[i][k].Y2-SegSet[i][k].Y1)*SegSet[i][k].X1-2*(tmpS[min].y-SegSet[i][k].Y1)*(SegSet[i][k].X2-SegSet[i][k].X1);
			if (xt>1) tmpS[min].xx[2]++;
			else if (xt<-1) tmpS[min].xx[0]++;
			else tmpS[min].xx[1]++;
			if (yt>1) tmpS[min].yy[2]++;
			else if (yt<-1) tmpS[min].yy[0]++;
			else tmpS[min].yy[1]++;
			k=f;
		}
	}
	/*
	vector< g_Segment > Shadow;Shadow.clear();
	g_Segment tmpg;
	tmpg.X1=0;tmpg.Y1=0;tmpg.X2=x_len;tmpg.Y2=16;Shadow.push_back(tmpg);
	tmpg.X1=0;tmpg.Y1=0;tmpg.X2=x_len;tmpg.Y2=32;Shadow.push_back(tmpg);
	tmpg.X1=x_len;tmpg.Y1=y_len-16;tmpg.X2=0;tmpg.Y2=y_len;Shadow.push_back(tmpg);
	tmpg.X1=x_len;tmpg.Y1=y_len-32;tmpg.X2=0;tmpg.Y2=y_len;Shadow.push_back(tmpg);
	tmpg.X1=16;tmpg.Y1=0;tmpg.X2=0;tmpg.Y2=y_len;Shadow.push_back(tmpg);
	tmpg.X1=32;tmpg.Y1=0;tmpg.X2=0;tmpg.Y2=y_len;Shadow.push_back(tmpg);
	tmpg.X1=x_len-16;tmpg.Y1=0;tmpg.X2=x_len;tmpg.Y2=y_len;Shadow.push_back(tmpg);
	tmpg.X1=x_len-32;tmpg.Y1=0;tmpg.X2=x_len;tmpg.Y2=y_len;Shadow.push_back(tmpg);
	for (int i=0;i<Shadow.size();i++)
		for (int j=0;j<tmpS.size();j++)
			if ((Shadow[i].X2-Shadow[i].X1)*(tmpS[j].y-Shadow[i].Y1)<(tmpS[j].x-Shadow[i].X1)*(Shadow[i].Y2-Shadow[i].Y1)) tmpS[j].num++;
	*/
	int max=0;
	for (int i=0;i<tmpS.size();i++) if (tmpS[i].num>max) max=tmpS[i].num;
	for (int i=0;i<tmpS.size();i++)
		if ((tmpS[i].num>=max)||(tmpS.size()<3))
		{
			pair<int ,int> tmpP;
			tmpP.first=tmpS[i].x*3-1;
			tmpP.second=tmpS[i].y*3-1;
			int maxx=0,maxy=0;
			for (int j=1;j<3;j++)
			{
				if (tmpS[i].xx[j]>tmpS[i].xx[maxx]) maxx=j;
				if (tmpS[i].yy[j]>tmpS[i].yy[maxy]) maxy=j;
			}
			tmpP.first+=maxx;
			tmpP.second+=maxy;
			Ans.push_back(tmpP);
		}
	return Ans;
}
