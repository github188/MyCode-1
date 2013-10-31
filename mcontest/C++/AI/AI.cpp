#include "MSTCOSSDK.h"
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include<math.h>
#include<stdio.h>
#pragma comment(lib,"MSTCOSSDK.lib")
using namespace std;

struct point
{
	double x,y;
} tar;

vector<ShipInfo> ships,a,b,c;

double dist(ShipInfo a,ShipInfo b)
{
    return sqrt((a.PositionX - b.PositionX) * (a.PositionX - b.PositionX) + (a.PositionY - b.PositionY) * (a.PositionY - b.PositionY));
}

double dist(point a,point b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

point GetCent(vector<ShipInfo> a)
{
	point tmp;tmp.x=tmp.y=0;
	for (int i=0;i<a.size();i++)
	{
		tmp.x+=a[i].PositionX;
		tmp.y+=a[i].PositionY;
	}
	tmp.x/=(double)a.size();
	tmp.y/=(double)a.size();
	return tmp;
}

bool check(vector<ShipInfo> a)
{
	ShipInfo tmp(0,0,0,0,0,0,0,0,0,0,0,0,0,0,0);
	tmp.PositionX=tar.x;
	tmp.PositionY=tar.y;
	for (int i=0;i<a.size();i++) if (dist(a[i],tmp)>50) return false;
	return true;
}

double getsin(double x1,double y1,double x2,double y2)
{
	return x1*y2-x2*y1;
}

double getcos(double x1,double y1,double x2,double y2)
{
	return x1*x2+y2*y1;
}

bool check_att(ShipInfo a,ShipInfo b)
{
	if (dist(a,b)>CannonRange) return false;
	double sin1,cos1;
	sin1=getsin(a.DirectionX,a.DirectionY,b.PositionX-a.PositionX,b.PositionY-a.PositionY);
	cos1=getcos(a.DirectionX,a.DirectionY,b.PositionX-a.PositionX,b.PositionY-a.PositionY)
		/(sqrt(a.DirectionX*a.DirectionX+a.DirectionY*a.DirectionY)
		*sqrt((b.PositionX-a.PositionX)*(b.PositionX-a.PositionX)+(b.PositionY-a.PositionY)*(b.PositionY-a.PositionY)));
	if (sin1>0)
	{
		if (a.CooldownRemain[0]!=0) return false;
		if ((cos1>-sqrt(2.0)/2.0)&&(cos1<sqrt(2.0)/2.0)) return true;
		return false;
	} else
	{
		if (a.CooldownRemain[1]!=0) return false;
		if ((cos1>-sqrt(2.0)/2.0)&&(cos1<sqrt(2.0)/2.0)) return true;
		return false;
	}
}

double calc(ShipInfo a,ShipInfo b)
{
	double ans=200;
	ans*=sqrt(1.0-(dist(a,b)/CannonRange)*(dist(a,b)/CannonRange));
	ans*=(1.0-(getcos(a.PositionX,a.PositionY,a.VelocityX-b.VelocityX,a.VelocityY-b.VelocityY)/sqrt(a.PositionX*a.PositionX+a.PositionY*a.PositionY))/300);
	return ans;
}

point rot(double x,double y,double ang)
{
	double s=acos(-1.0)*(ang/180.0);
	point ans;
	ans.x=(x*cos(s)-y*sin(s))*100.0;
	ans.y=(x*sin(s)+y*cos(s))*100.0;
	return ans;
}

void Iteration(OSInterface* const Interface)
{
    int i, j, k;
    float t, d;
    Interface->Data();
    ships = Interface->Ship;
    a.clear();
    b.clear();
    for (i = 0; i<ships.size(); i++)
    {
        if (ships[i].Faction == Interface->Faction) a.push_back(ships[i]);
        else b.push_back(ships[i]);
    }

    if (b.size()==0)
	{/*
		for (int i=0;i<a.size();i++)
		{
			int k=-1;
			double v=0.0;
			for (int j=0;j<Interface->Resource.size();j++)
				if (Interface->Faction!=Interface->Resource[j].Faction)
			{
					point t;t.x=Interface->Resource[j].PositionX;t.y=Interface->Resource[j].PositionY;
					point tt;tt.x=a[i].PositionX;tt.y=a[i].PositionY;
					if ((k<0)||(dist(t,tt)<v))
					{
						k=j;
						v=dist(t,tt);
					}
			}
			Interface->MoveTo(a[i].ID,Interface->Resource[k].PositionX,Interface->Resource[k].PositionY);
		}*/
		
		//if ((tar.x<0)||(check(a)))
		//{
			point tmp=GetCent(a),tmptar;
			tmptar.x=-1;
			for (int i=0;i< Interface->Resource.size();i++)
				if (Interface->Resource[i].Faction!=Interface->Faction)
				{
					point t;t.x=Interface->Resource[i].PositionX;t.y=Interface->Resource[i].PositionY;
					if ((tmptar.x<0)||(dist(tmp,t)<dist(tmp,tmptar))) tmptar=t;
				}
			if (tmptar.x<0) return;
			tar=tmptar;
			for (int i=0;i<a.size();i++)
			{
				point t;t.x=a[i].PositionX;t.y=a[i].PositionY;
				if (dist(t,tar)>50) Interface->MoveTo(a[i].ID,tar.x,tar.y);
			}
			return;
 		//}
			/*
		for (int i=0;i<a.size();i++)
		if (a[i].IsBlocked)
		{
			   if (!a[i].IsRotating)
			   {
				Interface->StartRotating(a[i].ID,AngularRate/10.0);
				double len=sqrt(a[i].VelocityX*a[i].VelocityX+a[i].VelocityY*a[i].VelocityY);
				Interface->MoveTo(a[i].ID,a[i].PositionX-a[i].DirectionY*200/len,a[i].PositionY+a[i].DirectionX *200/len);
			   }
		} else
		{
			if ((tar.x-a[i].PositionX)*a[i].VelocityY != (tar.y-a[i].PositionY)*a[i].VelocityX) Interface->MoveTo(a[i].ID,tar.x,tar.y);
		}

*/
	} else
	{
		for (int i=0;i<a.size();i++)
		{
			
			int tmpID=-1;
			double tmpV=0;
			for (int j=0;j<b.size();j++)
				if (check_att(a[i],b[j])&&((tmpID==-1)||(tmpV<calc(a[i],b[j]))))  //攻击可打最多的值
			{
				tmpID=j;
				tmpV=calc(a[i],b[j]);
			}

			if (tmpID!=-1) 
			{
				Interface->Attack(a[i].ID,b[tmpID].ID);
				//continue;
			}
/*
			if (a[i].IsBlocked)
		    {
			   if (!a[i].IsRotating)
			   {
				Interface->StartRotating(a[i].ID,AngularRate/10.0);
				double len=sqrt(a[i].VelocityX*a[i].VelocityX+a[i].VelocityY*a[i].VelocityY);
				Interface->MoveTo(a[i].ID,a[i].PositionX-a[i].DirectionY*200/len,a[i].PositionY+a[i].DirectionX *200/len);
			   }
			   //continue;
		    }*/
		/*
			if (a[i].Armor<300)
			{
				//vector<ShipInfo> c;c.clear();c=b;c.in
				point vec,tmp=GetCent(b);
				tmp.x=a[i].DirectionX;
				tmp.y=a[i].DirectionY;
				vec.x=a[i].PositionX-tmp.x;
				vec.y=a[i].PositionY-tmp.y;
				double l=sqrt(vec.x*vec.x+vec.y+vec.y);
				vec.x/=l;
				vec.y/=l;
				//tmp.x=a[i].PositionX;tmp.y=a[i].PositionY;
				int uu=0;
				while (true)
				{
					if (uu>30) break;uu++;
					if ((tmp.x+vec.x*100<0)||(tmp.x+vec.x*100>2048)) break;
					if ((tmp.y+vec.y*100<0)||(tmp.y+vec.y*100>2048)) break;
					tmp.x+=vec.x*100;
					tmp.y+=vec.y*100;
				}
				Interface->MoveTo(a[i].ID,a[i].PositionX,0);
				continue;
			}*/

			
			double v=0;
			tmpID=-1;
			for (int j=0;j<b.size();j++)
				if ((tmpID==-1)||(b[j].Armor<v))
			{
					tmpID=j;
					v=b[j].Armor;
			}

			double xx=b[tmpID].PositionX-a[i].PositionX,yy=b[tmpID].PositionY-a[i].PositionY;
			double ux=xx,uy=yy;
			double sin1,cos1;
			if (dist(b[tmpID],a[i])>CannonRange) 
			{
				sin1=sqrt(2.0)/2.0;
			cos1=sin1;
			} else {
			sin1=sqrt(3.0)/2.0;
			cos1=1.0/2.0;}
			xx=ux*cos1+uy*sin1;
			yy=ux*(-sin1)+uy*cos1;
			double tx,ty;
			tx=xx+a[i].PositionX;
			ty=yy+a[i].PositionY;
			if (tx<50) tx=50;
			if (tx>2000) tx=200;
			if (ty<50) ty=50;
			if (ty>2000) ty=2000;
			Interface->MoveTo(a[i].ID,xx+a[i].PositionX,yy+a[i].PositionY);
		}
	}
}

int main(int argc, char* argv[])
{
	tar.x=tar.y=-1;
    char* temp[2];
    temp[0] = "wcwswswws";
    temp[1] = "5.9.45";
    srand(0);
    MSTCOSSDK::StartGame(2, temp, Iteration);
    return 0;
}