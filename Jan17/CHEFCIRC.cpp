//CHEFCIRC
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#include <climits>
#include <utility>
#include <assert.h>
using namespace std;

#define VI vector <int>
#define PII pair <double, double>
#define LL long long
#define ULL unsigned long long
#define LDB long double
#define MEM(a,b) memset(a,(b),sizeof(a))
#define FOR(i,a,b) for (auto i = (a); i <= (b); i++)
#define FORD(i,a,b) for (auto i = (a); i >= (b); i--)
#define FORV(CAKE,it) for(auto it =CAKE.begin(); it != CAKE.end(); it++)
#define FIT(it,v) for (auto it = v.begin(); it != v.end(); it++)
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x < 0)?-(x):x)
#define IN(A, B, C)  (B) <= (A) && (A) <= (C)
#define AIN(A, B, C) assert(IN(A, B, C))

#define MP make_pair
#define PB push_back

#define FF first
#define SS second
#define PI 3.14159265358979323846
#define MOD 1000000007
#define INF INT_MAX //Infinity
#define epsilon 1e-6

PII findCenterCircle(PII p1, PII p2, PII p3)
{
	double m1 = (p2.second - p1.second) / (p2.first - p1.first);
	double m2 = (p3.second - p2.second) / (p3.first - p2.first);

	double x,y;
	x = (m1 * m2 * (p1.second - p3.second) + m2 * (p1.first + p2.first) - m1 * (p2.first + p3.first)) / (2 * (m2 - m1));
	y = (-1 / m1) * (x - (p1.first + p2.first) / 2) + (p1.second + p2.second) / 2;

	return MP(x,y);

}

double dist(PII a, PII b)
{
	double m = (a.first-b.first), n = (a.second-b.second);
	return (m*m + n*n);
}

bool fequal(double a, double b)
{
    return fabs(a-b) < epsilon;
}

int orientation(PII p1, PII p2, PII p3)
{
    int val = (p2.second - p1.second) * (p3.first - p2.first) -
              (p2.first - p1.first) * (p3.second - p2.second);

    if(val == 0) return 0;  // colinear
		else if(val > 0) return 1; // clock wise
		else return 2; // counterclock wise
}

vector<PII> convexHull(vector<PII> points, int n)
{
	vector<PII> hull;
	if(n<3) return hull;
	int left = 0;
	FOR(i,1,n-1)
		if(points[i].first < points[left].first)
			left = i;

	int idx=left, q;
	do
	{
		hull.PB(points[idx]);
		q = (idx+1)%n;
		FOR(i,0,n-1)
			if(orientation(points[idx],points[i],points[q]) == 2)
				q = i;

		idx = q;

	}while(idx != left);

	return hull;

}

int main()
{
	cin.sync_with_stdio(0);
	cout.precision(10);
	int n,m;
	cin>>n>>m;
	vector<PII > points;
	double minRad = 1000000000;
	FOR(i,0,n-1)
	{
		double a,b;
		cin>>a>>b;
		points.PB(MP(a,b));
	}
	srand(unsigned(time(NULL)));
	random_shuffle(points.begin(), points.end());

	//Base Cases
	if(n==1 || m==1)
	{
		cout<<"0";
		return 0;
	}
	if(m==2)
	{
		FOR(i,0,n-1)
			FOR(j,i+1,n-1)
				minRad = min(minRad, 0.5*dist(points[i],points[j]));
		cout<<minRad;
		return 0;
	}

	PII centerCircle;
	double radius, distance;
	int enclosed, i,j,k,l;
	//Pairs in the Set
	for(i=0;i<=n-1;i++)
	{
		for(j=i+1;j<=n-1;j++)
		{
			centerCircle = MP((points[i].first+points[j].first)/2, (points[i].second+points[j].second)/2);
			radius = dist(centerCircle,points[i]);
			if(radius > minRad)
				continue;
			enclosed = 0;
			for(l=0;l<=n-1;l++)
			{
				if(enclosed>=m || n-l<m-enclosed)
					break;
				distance = dist(centerCircle,points[l]);
				if((radius-distance) > -1*epsilon)
					enclosed++;
			}
			if(enclosed>=m)
			{
				minRad = min(minRad,radius);
				continue;
			}
			//Triplet in the Set
			for(k=j+1;k<=n-1;k++)
			{
				centerCircle = findCenterCircle(points[i],points[j],points[k]);
				radius = dist(centerCircle,points[i]);
				if(radius > minRad)
					continue;
				enclosed = 0;
				for(l=0;l<=n-1;l++)
				{
					if(enclosed>=m || n-l<m-enclosed)
						break;
					distance = dist(centerCircle,points[l]);
					if((radius-distance) > -1*epsilon)
						enclosed++;
				}
				if(enclosed>=m)
					minRad = min(minRad,radius);
			}
		}
	}

	cout<<sqrt(minRad);
}
