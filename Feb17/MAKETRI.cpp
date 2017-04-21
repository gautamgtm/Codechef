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

int main()
{
	cin.sync_with_stdio(0);
	LL n, l ,r;
  scanf("%Ld %Ld %Ld", &n, &l, &r);
  LL A[n];
  FOR(i,0,n-1)
    scanf("%Ld", &A[i]);

	vector<pair<LL,LL> > myVec, finalVec;
  sort(A, A+n);
  FOR(i,0,n-2)
	{
		LL a = A[i] + A[i+1] - 1, b = A[i+1] - A[i] + 1;
		myVec.PB(MP(b,a));
	}

	sort(myVec.begin(), myVec.end());
	LL start = 0, ans = 0;
	while(start<myVec.size()-1)
	{
		int next = start+1;
		if(myVec[next].first > myVec[start].second)
		{
			finalVec.PB(MP(myVec[start].first, myVec[start].second));
			start++;
		}
		else
		if(myVec[next].first <= myVec[start].second && myVec[next].second >= myVec[start].second)
		{
			myVec[next].first = myVec[start].first;
			start = next;
		}
		else
		{
			myVec[next].first = myVec[start].first;
			myVec[next].second = myVec[start].second;
			start = next;
		}
	}

	FIT(it,finalVec)
	{
		printf("%Ld %Ld\n", it->first, it->second);
		if(!(l>it->second || r<it->first))
    	ans += min(it->second,r)-max(l,it->first)+1;
	}

  printf("%Ld", ans);

}
