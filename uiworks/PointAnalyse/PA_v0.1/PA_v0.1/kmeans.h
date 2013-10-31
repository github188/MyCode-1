#include <iostream>
#include <math.h>
#include <vector>
#define _NUM 20
using namespace std;

struct Tuple
{
	double attr1;
	double attr2;
};

vector<Tuple>  kMeans(vector<Tuple>,double,int);