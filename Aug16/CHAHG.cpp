//CHAHG
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

bool isZigZag(LL A[], int sz)
{
	if(sz==1)
		return false;
	if(A[0] == A[1])
		return false;

	bool start = (A[0]>A[1]);
	FOR(i,1,sz-2)
	{
		if(A[i] == A[i+1])
			return false;
		else
		if((A[i]>A[i+1]) == start)
			return false;
		else
			start = !start;
	}
	return true;
}

int main()
{
	cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		LL h[n], r[n];
		FOR(i,0,n-1)
		{
			scanf("%Ld %Ld", &h[i], &r[i]);
		}
		if(n==1)
		{
			printf("1\n");
			printf("0 Inf\n");
			continue;
		}

		bool count = isZigZag(h,n);

		set<double> mySet1;
		bool isPossible = true;

		FOR(i,0,n-2)
		{
			if(r[i] != r[i+1])
			{
				double temp = double(h[i]-h[i+1])/(r[i+1]-r[i]);
				if(temp == 0)
					mySet1.insert(0.1);
				else
				if(temp>0)
					mySet1.insert(temp);
			}
		}

		vector<double> mySet;
		FIT(it,mySet1)
		{
			mySet.PB(*it);
		}

		vector<LL> tm;
		if(count == true)
			tm.PB(0);
		FIT(it,mySet)
		{
			LL temp1 = (LL)floor(*it)+1, temp2 = (LL)ceil(*it)-1;

			LL temp[n];
			FOR(j,0,n-1)
				temp[j] = h[j] + (r[j]*temp1);
			bool isZ = isZigZag(temp, n);

			if(isZ == true)
			{
				if(count == true)
				{
					if(temp1 != (temp2 + 1))
					{
						tm.PB(temp2);
						tm.PB(temp1);
					}
					continue;
				}
				tm.PB(temp1);
				count = true;
			}
			else
			{
				if(count == false)
					continue;

				tm.PB(temp2);
				count = false;
			}
		}

		if(tm.size() == 0)
		{
			printf("0\n");
			continue;
		}
		int ans = (int)ceil(double(tm.size())/2);
		printf("%d\n", ans);
		if(tm.size()%2 == 0)
		{
			FOR(i,0,ans-1)
			{
				printf("%Ld %Ld\n", tm[2*i], tm[2*i+1]);
			}
		}
		else
		{
			FOR(i,0,ans-2)
			{
				printf("%Ld %Ld\n", tm[2*i], tm[2*i+1]);
			}
			printf("%Ld Inf\n", tm[2*ans-2]);
		}
	}
}
