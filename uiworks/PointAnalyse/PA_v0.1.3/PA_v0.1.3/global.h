#pragma once
#include<stdio.h>
#include<math.h>
#include<vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;
#define SCALE 30
#define PICSCALE 3
#define FIGR 10

struct point
{
    int ax1,ay1,ax2,ay2;
	int bx1,by1,bx2,by2;

    bool xless(point b) /* <= */
	{
		return getX()<=b.getX();
	}
    bool yless(point b) /* <= */
	{
		return getY()<=b.getY();
	}
	int getX()
	{
      long long a1=ay1-ay2,b1=ax2-ax1,c1=ax1*ay2-ax2*ay1;
      long long a2=by1-by2,b2=bx2-bx1,c2=bx1*by2-bx2*by1;
      long long D=a1*b2-a2*b1;
      int f=(b1*c2-b2*c1)/D;
	  return f;
	}
	int getY()
	{
      long long a1=ay1-ay2,b1=ax2-ax1,c1=ax1*ay2-ax2*ay1;
      long long a2=by1-by2,b2=bx2-bx1,c2=bx1*by2-bx2*by1;
      long long D=a1*b2-a2*b1;
      int f=(c1*a2-c2*a1)/D;
	  return f;
	}
};

struct ValuedPoint
{
	int x,y,value;
	bool operator< (const ValuedPoint &b) const
    {
		return ((value<b.value)||((value==b.value)&&(x<b.x))||((value==b.value)&&(x==b.x)&&(y<b.y)));
    }
};