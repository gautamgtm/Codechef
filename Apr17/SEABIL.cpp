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

void pushBack(vector<VI> &A,int a, int b, int c, int d, int e)
{
	VI temp;
	temp.PB(a);temp.PB(b);temp.PB(c);temp.PB(d);temp.PB(e);
	A.PB(temp);
}

void printVector(vector<VI> A)
{
	printf("%d\n", A.size());
	FOR(i,0,A.size()-1)
	{
		FOR(j,0,4)
			printf("%d ", A[i][j]);
		printf("\n");
	}
}

int main()
{
	cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n,m;
		scanf("%d %d", &n, &m);
		vector<VI> A(m);
		vector<VI> ans1, ans2;
		FOR(i,0,m-1)
		{
			int a,b,c;
			scanf("%d %d %d", &a, &b, &c);
			A[i].PB(a); A[i].PB(b); A[i].PB(c);
		}

		//Sort according to X-coordinates and then Y-coordinates
		sort(A.begin(), A.end());
		int idx=-1;
		FOR(i,0,m-1)
		{
			int x=A[i][0], y=A[i][1];
			if(A[i][2] < 1 && x==y)
				continue;
			else
			if(A[i][2] < 2 && x!=y)
				continue;
			//Move x first, then y : 0,0
			if(x==y)
				idx = x;
			else
			{
				if(x > y)
				{
					pushBack(ans1, x, y, -1, 0, x-y);
					idx = y;
				}
				else
				{
					pushBack(ans1, x, y, 0, -1, y-x);
					idx = x;
				}
			}
		}
		if(idx != -1)
			pushBack(ans1, idx, idx, -1, -1, idx+1);
		idx = -1;
		FORD(i,m-1,0)
		{
			int x=A[i][0], y=A[i][1];
			if(A[i][2] < 1 && x==y)
				continue;
			else
			if(A[i][2] < 2 && x!=y)
				continue;
			//Move x first, then y : n,n
			if(x==y)
				idx = x;
			else
			{
				if(x > y)
				{
					pushBack(ans2, x, y, 0, 1, x-y);
					idx = x;
				}
				else
				{
					pushBack(ans2, x, y, 1, 0, y-x);
					idx = y;
				}
			}
		}
		if(idx != -1)
			pushBack(ans2, idx, idx, 1, 1, n-idx+1);

		if(ans1.size() == 0 && ans2.size() == 0)
			printf("0\n");
		else
		if(ans1.size() < ans2.size())
			printVector(ans1);
		else
			printVector(ans2);
	}

}
