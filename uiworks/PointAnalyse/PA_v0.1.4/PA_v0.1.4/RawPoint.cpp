#include "RawPoint.h"


RawPoint::RawPoint(void)
{
	for (int i=0;i<10;i++) SegSet[i].clear();
	time=0;
	gp.clear();
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

int pred(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3,long long x4)
{
	long long a1,b1,c1,a2,b2,c2;  //a=a1/a2, b,c and so on
	a1=(y3-y2)*(x2-x1)-(y2-y1)*(x3-x2);
	a2=(x3*x3-x2*x2)*(x2-x1)-(x2*x2-x1*x1)*(x3-x2);
	b1=a2*(y2-y1)-a1*(x2*x2-x1*x1);
	b2=a2*(x2-x1);
	c1=y1*a2*b2-a1*b2*x1*x1-b1*a2*x1;
	c2=a2*b2;
	long long ans=(b2*a1*x4*x4+b1*a2*x4+c1)/c2;
	int tmp=ans;
	if (tmp<0)
	{
		int o=0;
	}
	return tmp;
}

vector< pair<int,int> > RawPoint::GetRawPoint( vector< g_Segment > Segment,int x_len,int y_len)
{
	vector< pair< int, int> > Ans;Ans.clear();
	sort(Segment.begin(),Segment.end(),typecmp);
	int head=0;
	bool changeStd=false;
	time++;
	while (head<Segment.size())
	{
		int h=head;head++;
		while ((head<Segment.size())&&(Segment[head].type==Segment[h].type)) head++;
		SegSet[Segment[h].type].clear();
		if ((Segment[h].type==0)||(Segment[h].type==5)) changeStd=true;
		for (int i=h;i<head;i++) SegSet[Segment[i].type].push_back(Segment[i]);
		if (Segment[h].type<5) sort(SegSet[Segment[h].type].begin(),SegSet[Segment[h].type].end(),xcmp0);
		else sort(SegSet[Segment[h].type].begin(),SegSet[Segment[h].type].end(),ycmp5);
	}
	if (SegSet[0].size()+SegSet[5].size()==0) return Ans;
	for (int i=0;i<gp.size();i++) {gp[i].num=0;gp[i].time++;}

	for (int j=0;j<gp.size();j++)
		{
			bool check=false;
			for (int i=1;i<10;i++)
		    if (i!=5)
				for (int k=0;k<SegSet[i].size();k++)
				{
					int dx=SegSet[i][k].X1-gp[j].x,dy=SegSet[i][k].Y1-gp[j].y;
					int ex=SegSet[i][k].X2-gp[j].x,ey=SegSet[i][k].Y2-gp[j].y;
					long long area=(long long)dx*(long long)ey-(long long)ex*(long long)dy;area*=area;
					long long dis=((long long)SegSet[i][k].X1-(long long)SegSet[i][k].X2)*((long long)SegSet[i][k].X1-(long long)SegSet[i][k].X2)+((long long)SegSet[i][k].Y1-(long long)SegSet[i][k].Y2)*((long long)SegSet[i][k].Y1-(long long)SegSet[i][k].Y2);
					if (area<=(long long)10*dis) gp[j].num++;
				}
			if (gp[j].num>=MINLINE) gp[j].time=0;
		}

	for (int i=0;i<gp.size();i++)
		if (gp[i].time>=TIME_DELAY)
		{
			for (int j=i;j<gp.size()-1;j++) gp[j]=gp[j+1];
			gp.pop_back();
			i--;
		}

	for (int i=0;i<gp.size();i++)  // µ÷Õû
		if (gp[i].v.size()>2)
		{
			int x=gp[i].v.size()-1;
			int tmpx=gp[i].x;
			gp[i].x=pred(gp[i].t[x],gp[i].v[x].first,gp[i].t[x-1],gp[i].v[x-1].first,gp[i].t[x-2],gp[i].v[x-2].first,time);
			int tmpy=gp[i].y;
			gp[i].y=pred(gp[i].t[x],gp[i].v[x].second,gp[i].t[x-1],gp[i].v[x-1].second,gp[i].t[x-2],gp[i].v[x-2].second,time);
			if ((gp[i].y<0)||(gp[i],x<0)) 
			{
				gp[i].x=tmpx;
				gp[i].y=tmpy;
			}
		}
	
	if (changeStd)
	{
		for (int i=0;i<SegSet[0].size();i++)
		{
			int ii=i;
			while ((i+1<SegSet[0].size())&&(SegSet[0][i+1].X1==SegSet[0][i].X1+PICSCALE)&&(i-ii<=1)) i++;
			ii=(ii+i)/2;
			for (int j=0;j<SegSet[5].size();j++)
			{
			    int jj=j;
			    while ((j+1<SegSet[5].size())&&(SegSet[5][j+1].Y1==SegSet[5][j].Y1+PICSCALE)&&(j-jj<=1)) j++;
			    jj=(jj+j)/2;
				long long dis=1e9;
				int mark=-1;
				int x=SegSet[0][ii].X1,y=SegSet[5][jj].Y1;
				for (int k=0;k<gp.size();k++)
					if (((long long)x-(long long)gp[k].x)*((long long)x-(long long)gp[k].x)+((long long)y-(long long)gp[k].y)*((long long)y-(long long)gp[k].y)<=dis)
					{
						dis=((long long)x-(long long)gp[k].x)*((long long)x-(long long)gp[k].x)+((long long)y-(long long)gp[k].y)*((long long)y-(long long)gp[k].y);
						mark=k;
					}

				if (dis==0) continue;
				if (dis<=DIFF_R*DIFF_R)
				{
					gp[mark].time==0;
					if (gp[mark].t[gp[mark].v.size()-1]==time) continue;
					if (gp[mark].v.size()==BUF_SIZE)
					{
						for (int k=0;k<BUF_SIZE-1;k++) {gp[mark].v[k]=gp[mark].v[k+1];gp[mark].t[k]=gp[mark].t[k+1];}
						gp[mark].v.pop_back();gp[mark].t.pop_back();
					}
					pair<int,int> tmpp;tmpp.first=x;tmpp.second=y;
					gp[mark].v.push_back(tmpp);
					gp[mark].t.push_back(time);
					gp[mark].x=x;gp[mark].y=y;
					continue;
				}

				if (gp.size()==MAX_CUR_POINT) continue;
				GoodPoint tmpgp;tmpgp.x=x;tmpgp.y=y;tmpgp.time=0;
				tmpgp.v.push_back(pair<int,int>(x,y));
				tmpgp.t.push_back(time);
				for (int l=1;l<10;l++) if (l!=5)
				for (int k=0;k<SegSet[l].size();k++)
				{
					long long dx=SegSet[l][k].X1-x,dy=SegSet[l][k].Y1-y;
					long long ex=SegSet[l][k].X2-x,ey=SegSet[l][k].Y2-y;
					long long area=(long long)dx*(long long)ey-(long long)ex*(long long)dy;area*=area;
					long long dis=((long long)SegSet[l][k].X1-(long long)SegSet[l][k].X2)*((long long)SegSet[l][k].X1-(long long)SegSet[l][k].X2)+((long long)SegSet[l][k].Y1-(long long)SegSet[l][k].Y2)*((long long)SegSet[l][k].Y1-(long long)SegSet[l][k].Y2);
					if (area<=(long long)4*dis)
					{
						tmpgp.time=0;
						tmpgp.num++;
					}
				}
				if (tmpgp.num>=MINLINE) gp.push_back(tmpgp);
			}
		}

	} 
	/*else
	{
		for (int mark=0;mark<gp.size();mark++)
		if ((gp[mark].v[gp[mark].v.size()-1].first!=gp[mark].x)||(gp[mark].v[gp[mark].v.size()-1].second!=gp[mark].y))
		{
				if (gp[mark].v.size()==BUF_SIZE)
				{
					for (int k=0;k<BUF_SIZE-1;k++) gp[mark].v[k]=gp[mark].v[k+1];
					gp[mark].v.pop_back();
				}
				pair<int,int> tmpp;tmpp.first=gp[mark].x;tmpp.second=gp[mark].y;
				gp[mark].v.push_back(tmpp);
		}
	}*/

	for (int i=0;i<gp.size();i++)
	{
		pair<int,int> tmpp;tmpp.first=gp[i].x;tmpp.second=gp[i].y;
		Ans.push_back(tmpp);
	}
	return Ans;
}
