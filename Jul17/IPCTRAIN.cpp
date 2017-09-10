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

int main()
{
	cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
    int n,d;
    scanf("%d %d", &n, &d);
    vector<PII > Arr[d];
    LL sadness = 0;
    FOR(i,0,n-1)
    {
      int di, ti, si;
      scanf("%d %d %d", &di, &ti, &si);
      Arr[di-1].PB(MP(si,ti));
      sadness += 1LL * si * ti;
    }

    priority_queue<PII, vector<PII> > pq;
    FOR(i,0,d-1)
    {
      FIT(it,Arr[i])
        pq.push(*it);
      if(!pq.empty())
      {
        PII t = pq.top();
        pq.pop();
        sadness -= t.first;
        if(t.second > 1)
          pq.push(MP(t.first, t.second-1));
      }
    }
    printf("%Ld\n", sadness);
	}

}
