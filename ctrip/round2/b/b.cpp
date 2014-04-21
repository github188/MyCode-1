#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

const double eps = 1e-8;

using namespace std;

inline int zeros( double x )
{
	if( x < -eps )	return -1;
	return x > eps;
}

struct point
{
	double x, y;
	point(){}
	point( double _x, double _y ):x(_x), y(_y){}
	point operator-( const point r )	const
	{
		return point(x-r.x, y-r.y);
	}
	point nor()
	{
		double L = sqrt(x*x + y*y);
		return point(x/L, y/L);
	}
};

inline double cross( point a, point b )
{
	return a.x*b.y - a.y*b.x;
}

inline double dot( point a, point b )
{
	return a.x*b.x + a.y*b.y;
}

int cmp( point a, point b )
{
	if( zeros(a.y-b.y) == 0 )	return a.x < b.x;
	return a.y < b.y;
}

void graham( point* p, int n, point* st, int& top )
{
	sort(p, p+n, cmp);
	top = -1;
	for( int i = 0; i < n; ++i )
	{
		while( top >= 1 && zeros(cross(p[i]-st[top-1], st[top]-st[top-1])) >= 0 )
			top--;
		st[++top] = p[i];
	}
	int tmp = top;
	for( int i = n-2; i >= 0; --i )
	{
		while( top > tmp && zeros(cross(p[i]-st[top-1], st[top]-st[top-1])) >= 0 )
			top--;
		st[++top] = p[i];
	}
}

double dis( point a, point b )
{
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

void min_rec( point* p, int n, double& ans )
{
	int l = 1, r = 1, u = 1;
	for( int i = 0; i < n; ++i )
	{
		point edge = (p[(i+1)%n]-p[i]).nor();

		while( dot(edge, p[r%n]-p[i]) < dot(edge, p[(r+1)%n]-p[i]) )	r++;
		while( u < r || cross(edge, p[u%n]-p[i]) < cross(edge, p[(u+1)%n]-p[i]) )	u++;
		while( l < u || dot(edge, p[l%n]-p[i]) > dot(edge, p[(l+1)%n]-p[i]) )	l++;

		double w = dot(edge, p[r%n]-p[i]) - dot(edge, p[l%n]-p[i]);
		double h = fabs(cross(p[i]-p[u%n], p[(i+1)%n]-p[u%n]) / dis(p[i], p[(i+1)%n]));
        ans=min(ans,(w+h)*2.0);
	}
}

point q[10010], p[10010];

int main()
{
	int n,m;

	while( scanf("%d",&n)!=EOF )
	{
		for(int i = 0; i < n; ++i )
			scanf("%lf%lf", &q[i].x, &q[i].y);
		graham(q, n, p, m);

		if( m < 3 )
		{
			printf("%.6f\n",0.0);
			continue;
		}

		double ans = 1e9;
		min_rec(p, m, ans);
		printf("%.6lf\n", ans);
	}

	return 0;
}
