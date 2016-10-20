//SEAARI
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
	int n,k,d;
	scanf("%d %d %d", &n, &k, &d);
	int A[n];
	LL mean=0, variance=0;
	vector<PII> myVec;
	FOR(i,0,n-1)
	{
		scanf("%d", &A[i]);
		myVec.PB(MP(A[i], i));
		mean += A[i];
	}
	mean = mean/n;
	FOR(i,0,n-1)
		variance += ((A[i]-mean)*(A[i]-mean))%MOD;

	variance = variance/n;
	variance = (LL)sqrt((double)variance);

	LL a=(LL)ceil(((double)mean-2*(double)variance)), r=(LL)ceil(4*((double)variance/(n-d)));
	printf("%Ld %Ld\n", a, r);
	sort(myVec.begin(), myVec.end());

	//Swap
	int start = 0, end = n-1;
	FOR(i,0,k-1)
	{
		while(start < end)
		{
			if(myVec[start].second > myVec[end].second)
			{
				printf("1 %d %d\n", 1+myVec[start].second, 1+myVec[end].second);
				int temp = A[myVec[start].second];
				A[myVec[start].second] = A[myVec[end].second];
				A[myVec[end].second] = temp;
				start++;end--;
				break;
			}
			else
			{
				start++;end--;
			}
		}
	}

	myVec.clear();
	FOR(i,0,n-1)
	{
		A[i] = abs(A[i] - a - ((LL)i*r)%MOD);
		myVec.PB(MP(A[i], i));
	}
	sort(myVec.begin(), myVec.end());

	//Delete
	FOR(i,0,d-1)
	{
		printf("2 %d\n", 1+myVec[n-1-i].second);
	}

	printf("-1\n");

}
