#pragma once
#define SCALE 50
#define PICSCALE 3
#define FIGR 10
struct ValuedPoint
{
	int x,y,value;
	bool operator< (const ValuedPoint &b) const
    {
		return ((value<b.value)||((value==b.value)&&(x<b.x))||((value==b.value)&&(x==b.x)&&(y<b.y)));
    }
};
