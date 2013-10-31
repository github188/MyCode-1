#include<iostream>
#include<fstream>
#include<string.h>
#include<vector>
#include"json\json.h"
#include<math.h>
#include"global.h"
#include"line.h"
#include"RealPoint.h"
using namespace std;

vector< Polygen >* ReadFile(Json::Value,int,int,int);
RealPoint Reals;

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
		vector< Polygen >* polys = ReadFile(Jvalue,x,y,th);
		vector< ValuedPoint > ans=Reals.Update(polys);
		os<<ans.size()<<" ";
		for (int i=0;i<ans.size();i++)
		{
			int x=ans[i].x*PICSCALE/SCALE,y=ans[i].y*PICSCALE/SCALE;
			os<<x<<" "<<y<<" ";
		}
		os<<endl;
	}
	is.close();
	os.close();
	return 0;
}

vector< Polygen >* ReadFile(Json::Value Jvalue,int x_len,int y_len,int th)
{
    vector< Polygen > ans[10];
	for (int i=0;i<10;i++) ans[i].clear();
	int type=0;
	for (int i=0;i<Jvalue["data"].size();i++)
	{
		int p=Jvalue["data"][i]["scat"].asInt();
		int x=Jvalue["data"][i]["x_data"].size();
		int y=Jvalue["data"][i]["y_data"].size();
		if (p==0) type=0;
		if (p==16) type=1;
		if (p==32) type=2;
		if (p==-16) type=3;
		if (p==-32) type=4;
		p*=SCALE;
		if (x>0)
		{
			vector< int > tmpv;tmpv.clear();
			for (int j=0;j<x;j++)
				if (Jvalue["data"][i]["x_data"][j]["value"].asInt()<=th) tmpv.push_back(Jvalue["data"][i]["x_data"][j]["pos"].asInt());
			int head=0;
			while (head<tmpv.size())
			{
				int h=head;
				while ((h+1<tmpv.size())&&(tmpv[h+1]=tmpv[h]+1)) h++;
				Polygen tmpp;
				line tmpl;
				int x1,x2;
				x1=(tmpv[head]-1)*SCALE-SCALE/2;x2=(tmpv[h]+1)*SCALE+SCALE/2;
				tmpp.type=type;
				tmpl.dir=false;
				tmpl.x1=x1;tmpl.y1=0;
				tmpl.x2=x2;tmpl.y2=0;
				tmpp.line.push_back(tmpl);
				tmpl.dir=false;
				tmpl.x1=x2;tmpl.y1=0;
				tmpl.x2=x2+p;tmpl.y2=y_len;
				tmpp.line.push_back(tmpl);
				tmpl.dir=false;
				tmpl.x1=x2+p;tmpl.y1=y_len;
				tmpl.x2=x1+p;tmpl.y2=y_len;
				tmpp.line.push_back(tmpl);
				tmpl.dir=false;
				tmpl.x1=x1+p;tmpl.y1=y_len;
				tmpl.x2=x1;tmpl.y2=0;
				tmpp.line.push_back(tmpl);
				tmpp.LtoP();
				ans[i].push_back(tmpp);
				head=h+1;
			}
		}
		if (y>0)
		{
			vector< int > tmpv;tmpv.clear();
			for (int j=0;j<y;j++)
				if (Jvalue["data"][i]["y_data"][j]["value"].asInt()<=th) tmpv.push_back(Jvalue["data"][i]["y_data"][j]["pos"].asInt());
			int head=0;
			while (head<tmpv.size())
			{
				int h=head;
				while ((h+1<tmpv.size())&&(tmpv[h+1]=tmpv[h]+1)) h++;
				Polygen tmpp;
				line tmpl;
				int x1,x2;
				x1=(tmpv[head]-1)*SCALE-SCALE/2;x2=(tmpv[h]+1)*SCALE+SCALE/2;
				tmpp.type=5+type;
				tmpl.dir=false;
				tmpl.x1=x_len;tmpl.y1=x1;
				tmpl.x2=x_len;tmpl.y2=x2;
				tmpp.line.push_back(tmpl);
				tmpl.dir=false;
				tmpl.x1=x_len;tmpl.y1=x2;
				tmpl.x2=0;tmpl.y2=x2+p;
				tmpp.line.push_back(tmpl);
				tmpl.dir=false;
				tmpl.x1=0;tmpl.y1=x2+p;
				tmpl.x2=0;tmpl.y2=x1+p;
				tmpp.line.push_back(tmpl);
				tmpl.dir=false;
				tmpl.x1=0;tmpl.y1=x1+p;
				tmpl.x2=x_len;tmpl.y2=x1;
				tmpp.line.push_back(tmpl);
				tmpp.LtoP();
				ans[i].push_back(tmpp);
				head=h+1;
			}
	   }
	}
	return ans;
}
