#include<iostream>
#include<fstream>
#include<string.h>
#include"rawpoint.h"
#include<vector>
#include"json\json.h"
#include<math.h>
#define r 5000
#define scale 3
using namespace std;

double dis(double dX1,double dY1,double dX2,double dY2)
{
	return sqrt((dX1-dX2)*(dX1-dX2)+(dY1-dY2)*(dY1-dY2));
}

vector<int> work(vector<int> aData)
{
	vector<int> aAns;aAns.clear();
	while (aData.size()>0)
	{
		vector<int> aTmpData;aTmpData.clear();
		int iSize=aData.size();
		int k=0,l=1;
		double dMax=0;
		for (int i=0;i<iSize;i+=2)
			for (int j=i+2;j<iSize;j+=2)
				if (dis(aData[i],aData[i+1],aData[j],aData[j+1])>dMax) 
				{
					k=i;l=j;
					dMax=dis(aData[i],aData[i+1],aData[j],aData[j+1]);
				}
		double ox,oy;ox=oy=0;
		int sx,sy;sx=sy=0;
		for (int i=0;i<iSize;i+=2)
		if (dis(aData[i],aData[i+1],aData[k],aData[k+1])<=r)
		{
			ox+=aData[i];oy+=aData[i+1];
			sx++;sy++;
		} else
		{
			aTmpData.push_back(aData[i]);
			aTmpData.push_back(aData[i+1]);
		}
		aData=aTmpData;
		aTmpData.clear();
		ox/=(double)sx;
		oy/=(double)sy;
		double dx=ox-(double)(int)ox;
		double dy=oy-(double)(int)oy;
		int ux=(int)ox;
		int uy=(int)oy;
		if (dx>0) ux++;
		if (dy>0) uy++;
		aAns.push_back(ux);
		aAns.push_back(uy);
	}
	return aAns;
}

int main()
{
	Json::Reader Jreader;
	Json::Value Jvalue;
	ifstream is;
	is.open("单点曲线1中.txt");
	ofstream os;
	os.open("单点曲线1中out.txt");
	string in;
	int x,y,th;x=y=-1;
	while (getline(is,in))
	{
		Jreader.parse(in,Jvalue);
		if (x<0) x=Jvalue["x_length"].asInt()*scale,y=Jvalue["y_length"].asInt()*scale,th=Jvalue["recognize_threshold"].asInt();
		if (Jvalue["data"].size()==0) {os<<0<<endl;continue;}
		vector<int> tmp=get_rawPoint(Jvalue,th,x,y);
		vector<int> ans=work(tmp);
		os<<ans.size()/2;
		for (int i=0;i<ans.size();i+=2) os<<" "<<ans[i]<<" "<<ans[i+1];
		os<<endl;
	    //cout<<out<<endl;
	}
	is.close();
	os.close();
	return 0;
}