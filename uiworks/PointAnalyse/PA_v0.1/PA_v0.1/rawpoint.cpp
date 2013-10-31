#include"rawpoint.h"
#include<map>
#define scale 3
struct seg
{
	double x,y,xx,yy;
};

int calc(int x,int y,seg a,seg b)
{
	if ((b.yy-b.y)*(a.xx-a.x)-(b.xx-b.x)*(a.yy-a.y)==0) return -1;
        if ((b.xx-b.x)*(a.y-b.y)-(b.yy-b.y)*(a.x-b.x)==0&&
                 (a.xx-a.x)*(a.y-b.y)-(a.yy-a.y)*(a.x-b.x)==0) return -1;
          
    double k=((b.xx-b.x)*(a.y-b.y)-(b.yy-b.y)*(a.x-b.x))/((b.yy-b.y)*(a.xx-a.x)-(b.xx-b.x)*(a.yy-a.y));
    double xx=a.x+k*(a.xx-a.x);
    double yy=a.y+k*(a.yy-a.y);
	double xd=xx-(double)(int)xx;
	double yd=xx-(double)(int)yy;
	int xu=(int)xx;
	int yu=(int)yy;
	xu+=xd>0.5?1:0;
	yu+=yd>0.5?1:0;
	return xu*(y+1)+yu;
}

vector<int> get_rawPoint(Json::Value aValue,int th,int x_len,int y_len)
{
	vector<int> Ans;Ans.clear();
    vector<seg> S;S.clear();
	for (int i=0;i<aValue["data"].size();i++)
	{
		int p=aValue["data"][i]["scat"].asInt()*scale;
		int x=aValue["data"][i]["x_data"].size()*scale;
		int y=aValue["data"][i]["y_data"].size()*scale;
		if (x>0)
		{
			for (int j=0;j<x;j++)
				if (aValue["data"][i]["x_data"][j]["value"].asInt()<=th)
				{
					seg tmp;
					tmp.x=aValue["data"][i]["x_data"][j]["pos"].asInt()*scale;
					tmp.y=0;
					tmp.xx=tmp.x+p;
					tmp.yy=y_len;
					S.push_back(tmp);
				}
		}
		if (y>0)
		{
			for (int j=0;j<y;j++)
				if (aValue["data"][i]["y_data"][j]["value"].asInt()<=th)
				{
					seg tmp;
					tmp.y=aValue["data"][i]["y_data"][j]["pos"].asInt()*scale;
					tmp.x=x_len;
					tmp.yy=tmp.y+p;
					tmp.xx=0;
					S.push_back(tmp);
				}
		}
	}

	map<int,int> Map;Map.clear();
	int size=S.size();
	int max=0;
	for (int i=0;i<size;i++)
		 for (int j=i+1;j<size;j++)
		 {
			 int tmp=calc(x_len,y_len,S[i],S[j]);
			 if (tmp<0) continue;
			 Map[tmp]++;
			 max=max>Map[tmp]?max:Map[tmp];
		 }
	for (map<int,int>::iterator i=Map.begin();i!=Map.end();i++)
	{
		if (i->second>=((max-2)<5?(max-2):5)) 
		{
			Ans.push_back(i->first/(y_len+1));
			Ans.push_back(i->first%(y_len+1));
		}
	}
	return Ans;
}