#include <iostream>
#include <math.h>
#include <vector>
#include"kmeans.h"
#define _NUM 20
using namespace std;

int NUM = 3;

double getDistXY(Tuple t1, Tuple t2) 
{
	return sqrt((t1.attr1 - t2.attr1) * (t1.attr1 - t2.attr1) + (t1.attr2 - t2.attr2) * (t1.attr2 - t2.attr2));
}

Tuple getMeansC(vector<Tuple> c)
{
	int num = c.size();
	double meansX = 0, meansY = 0;
	Tuple t;
	for (int i = 0; i < num; i++)
	{
		meansX += c[i].attr1;
		meansY += c[i].attr2;
	}
	t.attr1 = meansX / num;
	t.attr2 = meansY / num;
	return t;
}

double getE(vector<Tuple> classes[], Tuple means[])
{
	double sum = 0;
	for (int i = 0; i < NUM; i++)
	{
		vector<Tuple> v = classes[i];
		for (int j = 0; j< v.size(); j++)
		{
			sum += (v[j].attr1 - means[i].attr1) * (v[j].attr1 - means[i].attr1) + (v[j].attr2 - means[i].attr2) *(v[j].attr2 - means[i].attr2);
		}
	}
	cout<<"sum:"<<sum<<endl;
	return sum;
}
 
int searchMinC(Tuple t, Tuple means[_NUM])
{
	int c = 0;
	int d = (t.attr1 - means[0].attr1) * (t.attr1 - means[0].attr1) + (t.attr2 - means[0].attr2) * (t.attr2 - means[0].attr2);
	for (int i = 1; i < NUM; i++)
	{
		int temp = (t.attr1 - means[i].attr1) * (t.attr1 - means[i].attr1) + (t.attr2 - means[i].attr2) * (t.attr2 - means[i].attr2);
		if (temp < d)
		{
			c = i;
			d = temp;
		}
	}
	return c;
}
 
vector<Tuple> kMeans(vector<Tuple> init,double r,int n)
{
	NUM = n;
	vector<Tuple> classes[_NUM]; 
	int c;
	Tuple means[_NUM]; 
	double newE, oldE = -1; 
	for (int i = 0; i < NUM; i++) 
	{
		classes[i].push_back(init[i]);
		means[i] = getMeansC(classes[i]); 
	}
	newE = getE(classes, means);
	for (int i = 0; i < NUM; i++) classes[i].clear();
	while(abs(newE - oldE) >= 1) 
	{
		for (int j = 0; j < init.size(); j++) 
		{
			int toC = searchMinC(init[j], means);
			classes[toC].push_back(init[j]);
		}
		for (int i = 0; i < NUM; i++) means[i] = getMeansC(classes[i]);
		oldE = newE;
		newE = getE(classes, means); 
		for (int i = 0; i < NUM; i++)  classes[i].clear();
	}

	vector<Tuple> ans;ans.clear();
	for (int i=0;i<NUM;i++) ans.push_back(means[i]);
	return ans;
}