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
#define INF INT_MAX //Infinity
#define lmt 100005

int n, m, A[lmt];

void solveBruteForce(int l, int r, int k)
{
	int temp=1, idx=l, maxm=1, maxElement=A[l];
	while(idx<r)
	{
		if(r-idx < k-maxm)
			break;
		if(A[idx+1] == A[idx])
			temp++;
		else
			temp=1;
		if(temp>maxm)
		{
			maxm = temp; maxElement = A[idx+1];
		}
		idx++;
	}
	if(maxm >= k)
		printf("%d\n", maxElement);
	else
		printf("-1\n");
}

int main()
{
	cin.sync_with_stdio(0);
	scanf("%d %d", &n, &m);
	FOR(i,0,n-1)
	 scanf("%d", &A[i]);

	VI startIdx, count;
	int temp=1, idx=0, lastIdx=0;
	while(idx<n-1)
	{
		if(A[idx+1] == A[idx])
			temp++;
		else
		{
			startIdx.PB(lastIdx); count.PB(temp);
			lastIdx = idx+1; temp=1;
		}
		idx++;
	}
	startIdx.PB(lastIdx); count.PB(temp);

  FOR(i,0,m-1)
	{
    int l, r, k;
    scanf("%d %d %d", &l, &r, &k);
    l--;r--;

		//solveBruteForce(l,r,k);
		auto a=upper_bound(startIdx.begin(), startIdx.end(), l)-startIdx.begin();
		auto b=upper_bound(startIdx.begin(), startIdx.end(), r)-startIdx.begin();
		a--;b--;
		
		if(b-a+1 > (r-l+1)-k+1)
		{
			printf("-1\n");
			continue;
		}
		int temp = count[a] - (l-startIdx[a]), ans = -1;
		bool isPossible = false;
		if(temp>=k)
		{
			ans = A[startIdx[a]];
			printf("%d\n", ans);
			continue;
		}
		temp = r-startIdx[b]+1;
		if(temp>=k)
		{
			ans = A[startIdx[b]];
			printf("%d\n", ans);
			continue;
		}
		FOR(j,a+1,b-1)
		{
			temp = count[j];
			if(temp>=k)
			{
				ans = A[startIdx[j]];
				printf("%d\n", ans);
				isPossible = true;
				break;
			}
		}
		if(!isPossible)
			printf("-1\n");
  }

}
