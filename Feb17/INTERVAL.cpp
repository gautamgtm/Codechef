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

#define MP make_pair
#define PB push_back

#define FF first
#define SS second
#define PI 3.14159265358979323846
#define MOD 1000000007
#define INF 1e+18 //Infinity

LL findMax(LL prefixSum[], int len, int &l, int &r)
{
	int u=l+1;
	int v = u+len-1;
	LL maxm = prefixSum[v+1]-prefixSum[u];
	int l1 = u, r1 = v;
	while(v<r-1)
	{
		u++;v++;
		LL temp = prefixSum[v+1]-prefixSum[u];
		if(temp>maxm)
		{
			l1 = u; r1 = v;
			maxm = temp;
		}
	}
	l = l1; r = r1;
	return maxm; // [l1,r1]
}

LL solve(int B[], LL prefixSum[], int m, int step, int l, int r, LL arr[][205])
{
	if(step==m-2)
	{
		int u_ = l+1;
		int v_ = u_+B[step]-1;
		LL ans = arr[u_][step];
		while(v_<r)
		{
			ans = max(ans, arr[u_][step]);
			u_++;v_++;
		}
		if(step%2 == 0)
			return ans;
		else
			return -1 * ans;
	}

	int u=l+1;
	int v = u+B[step]-1;
	LL bestvalue = INF;
	if(step%2 == 0)
		bestvalue = -1*INF;
	while(v<r)
	{
		LL temp = prefixSum[v+1]-prefixSum[u];
		if(step%2==0)
		{
			LL curr;
			if(arr[u][step] != 0)
				curr = arr[u][step];
			else
				curr = solve(B,prefixSum,m,step+1,u,v,arr) + temp;
			bestvalue = max(bestvalue, curr);
			arr[u][step] = curr;
		}
		else
		{
			LL curr;
			if(arr[u][step] != 0)
				curr = arr[u][step];
			else
				curr = solve(B,prefixSum,m,step+1,u,v,arr) - temp;
			bestvalue = min(bestvalue, curr);
			arr[u][step] = curr;
		}
		u++;v++;
	}
	return bestvalue;
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
		int A[n], B[m];
		LL prefixSum[n+1];
		prefixSum[0] = 0;
		FOR(i,0,n-1)
		{
			scanf("%d", &A[i]);
			prefixSum[i+1] = prefixSum[i] + A[i];
		}
		FOR(i,0,m-1)
			scanf("%d", &B[i]);

		LL score;
		if(m == 1)
		{
			int l=-1, r=n;
			printf("%Ld\n", findMax(prefixSum,B[0],l,r));
			continue;
		}
		else
		if(m == 0)
		{
			int u=0;
			int v = u+B[0]-1;
			int l=u, r=v;
			LL ans = prefixSum[v+1]-prefixSum[u];
			LL sub = findMax(prefixSum,B[1],l,r);
			ans = ans - sub;
			u++;v++;
			while(v<n)
			{
				LL temp = prefixSum[v+1]-prefixSum[u];
				if(l > u)
				{
					if(prefixSum[v]-prefixSum[v-B[1]] >= sub)
					{
						r = v-1; l = v-B[1];
						sub = prefixSum[v]-prefixSum[v-B[1]];
					}
				}
				else
				{
					l = u; r = v;
					sub = findMax(prefixSum,B[1],l,r);
				}
				ans = max(ans, temp - sub);
				u++;v++;
			}
			printf("%Ld\n", ans);
			continue;
		}

		LL arr[n][205] = {};
		LL alpha = -1*INF, beta = INF;
		//Pre Populate the last step
		int u=0;
		int v=u+B[m-2]-1;
		int l=u, r=v;
		LL sub = findMax(prefixSum,B[m-1],l,r);
		arr[u][m-2] = prefixSum[v+1]-prefixSum[u] - sub;
		u++;v++;
		while(v<n)
		{
			LL temp = prefixSum[v+1]-prefixSum[u];
			if(l > u)
			{
				if(prefixSum[v]-prefixSum[v-B[m-1]] >= sub)
				{
					r = v-1; l = v-B[m-1];
					sub = prefixSum[v]-prefixSum[v-B[m-1]];
				}
			}
			else
			{
				l = u; r = v;
				sub = findMax(prefixSum,B[m-1],l,r);
			}
			arr[u][m-2] = temp - sub;
			u++;v++;
		}

		score = solve(B,prefixSum,m,0,-1,n,arr);

		printf("%Ld\n", score);
	}

}
