//
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
#define PII pair <int, int>
#define LL long long
#define ULL unsigned long long
#define LDB long double
#define MEM(a,b) memset(a,(b),sizeof(a))
#define FOR(i,a,b) for (auto i = (a); i <= (b); i++)
#define FORD(i,a,b) for (auto i = (a); i >= (b); i--)
#define FORV(CAKE,it) for(auto it =CAKE.begin(); it != CAKE.end(); it++)
#define FIT(it,v) for (auto it = v.begin(); it != v.end(); it++)
#define FITD(it,v) for (auto it = v.rbegin(); it != v.rend(); it++)
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define ABS(x) ((x < 0)?-(x):x)
#define IN(A, B, C)  (B) <= (A) && (A) <= (C)
#define AIN(A, B, C) assert(IN(A, B, C))
#define PRINTV(it,v) for (auto it = v.begin(); it != v.end(); it++) printf("%d ", *it);
#define PRINTA(A, n) for (auto i = 0; i <= (a); i++) printf("%d ", A[i]);

#define MP make_pair
#define PB push_back

#define FF first
#define SS second
#define PI 3.14159265358979323846
#define MOD 1000000007
#define INF INT_MAX //Infinity

int main()
{
	cin.sync_with_stdio(0);
	int n;
	scanf("%d", &n);
	vector<pair<int, PII> > A[n];
	FOR(i,0,n-1)
	{
		FOR(j,0,n-1)
		{
			int temp;
			scanf("%d", &temp);
			A[i].PB(MP(temp, MP(i,j)));
		}
	}

	FOR(i,0,n/2-1)
	{
		vector<pair<int, PII> > myVec;
		FOR(j,0,n-1)
		{
			myVec.PB(A[2*i][j]);
			myVec.PB(A[2*i+1][j]);
		}
		sort(myVec.begin(), myVec.end());
		int option[4]={0};
		FOR(j,0,n-1)
		{
			option[0] = (myVec[j].second.first - 2*i)*(myVec[j].second.first - 2*i) + (myVec[j].second.second - j)*(myVec[j].second.second - j);
			option[2] = option[0];
			option[1] = (myVec[j].second.first - 2*i)*(myVec[j].second.first - 2*i) + (myVec[j].second.second - (n-j-1))*(myVec[j].second.second - (n-j-1));
			option[3] = option[1];
		}

		FOR(j,n,2*n-1)
		{
			option[0] += (myVec[j].second.first - (2*i+1))*(myVec[j].second.first - (2*i+1)) + (myVec[j].second.second - j)*(myVec[j].second.second - j);
			option[1] += (myVec[j].second.first - (2*i+1))*(myVec[j].second.first - (2*i+1)) + (myVec[j].second.second - j)*(myVec[j].second.second - j);
			option[2] += (myVec[j].second.first - (2*i+1))*(myVec[j].second.first - (2*i+1)) + (myVec[j].second.second - (n-j-1))*(myVec[j].second.second - (n-j-1));
			option[3] += (myVec[j].second.first - (2*i+1))*(myVec[j].second.first - (2*i+1)) + (myVec[j].second.second - (n-j-1))*(myVec[j].second.second - (n-j-1));
		}
		int minm = option[0], minIdx=0;
		if(option[1] < minm)
			minm = option[1], minIdx = 1;
		if(option[2] < minm)
			minm = option[2], minIdx = 2;
		if(option[3] < minm)
			minm = option[3], minIdx = 3;

		if(minIdx == 0 || minIdx == 2)
			FOR(i,0,n-1)
				printf("%d ", myVec[i].first);
		else
			FORD(i,n-1,0)
				printf("%d ", myVec[i].first);
		printf("\n");

		if(minIdx == 0 || minIdx == 1)
			FOR(i,n,2*n-1)
				printf("%d ", myVec[i].first);
		else
			FORD(i,2*n-1,n)
				printf("%d ", myVec[i].first);
		printf("\n");
	}
	if(n%2)
	{
		vector<PII> row(n);
		FOR(j,0,n-1)
			row[j] = MP(A[n-1][j].first,j);

		sort(row.begin(), row.end());
		int sorted=0, revSorted=0;
		FOR(j,0,n-1)
		{
			sorted += abs(j - row[j].second);
			revSorted += abs(n-j-1 - row[j].second);
		}
		if(sorted < revSorted)
		{
			FIT(it,row)
				printf("%d ", it->first);
		}
		else
		{
			FITD(it,row)
				printf("%d ", it->first);
		}
		printf("\n");
	}
}
