#include<iostream>
#include<fstream>
#include<string.h>
#include<vector>
#include"json\json.h"
#include<math.h>
#include"g_Segment.h"
#include"RawPoint.h"
#include"RealPoint.h"
#include"global.h"
using namespace std;

vector< g_Segment > ReadFile(Json::Value,int,int,int);
RawPoint RawP;
RealPoint RealP;

int main()
{
	Json::Reader Jreader;
	Json::Value Jvalue;
	ifstream is;
	is.open("两点曲线1中.txt");
	ofstream os;
	os.open("两点曲线1中out.txt");
	string in;
	int x,y,th;x=y=-1;
	while (getline(is,in))
	{
		Jreader.parse(in,Jvalue);
		if (x<0) x=Jvalue["x_length"].asInt()*SCALE,y=Jvalue["y_length"].asInt()*SCALE,th=Jvalue["recognize_threshold"].asInt();
		if (Jvalue["data"].size()==0) {os<<0<<endl;continue;}
		vector< g_Segment > seg = ReadFile(Jvalue,x,y,th);
		vector< ValuedPoint > Raws = RawP.GetRawPoint(seg,x,y);
		os<<Raws.size();
		for (int i=0;i<Raws.size();i++) os<<" "<<Raws[i].x<<" "<<Raws[i].y;
		os<<endl;
	}
	is.close();
	os.close();
	return 0;
}

vector< g_Segment > ReadFile(Json::Value Jvalue,int x_len,int y_len,int th)
{
    vector<g_Segment> ans;ans.clear();
	int type=0;
	for (int i=0;i<Jvalue["data"].size();i++)
	{
		int p=Jvalue["data"][i]["scat"].asInt()*SCALE;
		int x=Jvalue["data"][i]["x_data"].size();//*SCALE;
		int y=Jvalue["data"][i]["y_data"].size();//*SCALE;
		if (p==0) type=0;
		if (p==16*SCALE) type=1;
		if (p==32*SCALE) type=2;
		if (p==-16*SCALE) type=3;
		if (p==-32*SCALE) type=4;
		if (x>0)
		{
			int last = -2;
			for (int j=0;j<x;j++)
				if (Jvalue["data"][i]["x_data"][j]["value"].asInt()<=th)
				{
					if (Jvalue["data"][i]["x_data"][j]["pos"].asInt()==last+1)
					{
						for (int k=last*SCALE+1;k<Jvalue["data"][i]["x_data"][j]["pos"].asInt()*SCALE;k++)
						{
					        g_Segment tmp;
					        tmp.X1=k;
					        tmp.Y1=0;
					        tmp.X2=tmp.X1+p;
					        tmp.Y2=y_len;
					        tmp.type=type;
					        ans.push_back(tmp);
					} else
					{
						if (j!=0)
						for (int k=last*SCALE+1;k<=last*SCALE+SCALE/2;k++)
						if ((k+p>=0)&&(k+p<=x_len))
						{
					        g_Segment tmp;
					        tmp.X1=k;
					        tmp.Y1=0;
					        tmp.X2=tmp.X1+p;
					        tmp.Y2=y_len;
					        tmp.type=type;
					        ans.push_back(tmp);
						}

						for (int k=Jvalue["data"][i]["x_data"][j]["pos"].asInt()*SCALE-SCALE/2;k<Jvalue["data"][i]["x_data"][j]["pos"].asInt()*SCALE;k++)
						if ((k+p>=0)&&(k+p<=x_len))
						{
					        g_Segment tmp;
					        tmp.X1=k;
					        tmp.Y1=0;
					        tmp.X2=tmp.X1+p;
					        tmp.Y2=y_len;
					        tmp.type=type;
					        ans.push_back(tmp);
						}
					}

					g_Segment tmp;
					tmp.X1=Jvalue["data"][i]["x_data"][j]["pos"].asInt()*SCALE;
					tmp.Y1=0;
					tmp.X2=tmp.X1+p;
					tmp.Y2=y_len;
					tmp.type=type;
					last=Jvalue["data"][i]["x_data"][j]["pos"].asInt();
					ans.push_back(tmp);
				}
				
			for (int k=last*SCALE+1;k<=last*SCALE+SCALE/2;k++)
			if ((k+p>=0)&&(k+p<=x_len))
			{
		 		        g_Segment tmp;
				        tmp.X1=k;
				        tmp.Y1=0;
				        tmp.X2=tmp.X1+p;
				        tmp.Y2=y_len;
				        tmp.type=type;
				        ans.push_back(tmp);
			}
		}
		if (y>0)
		{
			int last=-2;
			for (int j=0;j<y;j++)
				if (Jvalue["data"][i]["y_data"][j]["value"].asInt()<=th)
				{
					if (Jvalue["data"][i]["y_data"][j]["pos"].asInt()==last+1)
					{
						for (int k=last*SCALE+1;k<Jvalue["data"][i]["y_data"][j]["pos"].asInt()*SCALE;k++)
						{
					        g_Segment tmp;
					        tmp.Y1=k;
					        tmp.X1=x_len;
					        tmp.Y2=tmp.Y1+p;
					        tmp.X2=0;
					        tmp.type=5+type;
					        ans.push_back(tmp);
						}
					} else
					{
						if (j!=0)
						for (int k=last*SCALE+1;k<=last*SCALE+SCALE/2;k++)
						if ((k+p>=0)&&(k+p<=y_len))
						{
					        g_Segment tmp;
					        tmp.Y1=k;
					        tmp.X1=x_len;
					        tmp.Y2=tmp.Y1+p;
					        tmp.X2=0;
					        tmp.type=5+type;
					        ans.push_back(tmp);
						}
						for (int k=Jvalue["data"][i]["y_data"][j]["pos"].asInt()*SCALE-SCALE/2;k<Jvalue["data"][i]["y_data"][j]["pos"].asInt()*SCALE;k++)
						if ((k+p>=0)&&(k+p<=y_len))
						{
					        g_Segment tmp;
					        tmp.Y1=k;
					        tmp.X1=x_len;
					        tmp.Y2=tmp.Y1+p;
					        tmp.X2=0;
					        tmp.type=5+type;
					        ans.push_back(tmp);
						}
					}
					g_Segment tmp;
					tmp.Y1=Jvalue["data"][i]["y_data"][j]["pos"].asInt()*SCALE;
					tmp.X1=x_len;
					tmp.Y2=tmp.Y1+p;
					tmp.X2=0;
					tmp.type=5+type;
					last=Jvalue["data"][i]["y_data"][j]["pos"].asInt();
					ans.push_back(tmp);
				}
					for (int k=last*SCALE+1;k<=last*SCALE+SCALE/2;k++)
					if ((k+p>=0)&&(k+p<=y_len))
					{
				        g_Segment tmp;
				        tmp.Y1=k;
				        tmp.X1=x_len;
				        tmp.Y2=tmp.Y1+p;
				        tmp.X2=0;
				        tmp.type=5+type;
				        ans.push_back(tmp);
					}
		}
	}
	return ans;
}