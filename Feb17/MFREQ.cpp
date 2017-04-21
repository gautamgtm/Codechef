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
#define maxn 1000000005
#define lmt 100005

struct query{
    int l, r, k, idx;
}q[lmt];

int n, m, curr, maxNum=-1, A[lmt], ans[lmt];
map<int, int> cnt;
vector<set<int> > hashSet(lmt);

inline bool cmp(const query& a, const query& b)
{
	int sq = sqrt(n);
	if (a.l/sq != b.l/sq)
		return a.l < b.l;
  return a.r > b.r;
}

void add(int pos)
{
	if(cnt[A[pos]])
		hashSet[cnt[A[pos]]].erase(A[pos]);
	cnt[A[pos]]++;
	hashSet[cnt[A[pos]]].insert(A[pos]);
	if(maxNum != -1)
	{
		if(cnt[A[pos]] > maxNum)
			maxNum++;
	}
	else
		maxNum = cnt[A[pos]];
}

void rmv(int pos)
{
	if(cnt[A[pos]])
		hashSet[cnt[A[pos]]].erase(A[pos]);
	cnt[A[pos]]--;
	hashSet[cnt[A[pos]]].insert(A[pos]);
	if(hashSet[maxNum].size() == 0)
		maxNum--;
}

int main()
{
	cin.sync_with_stdio(0);
	scanf("%d %d", &n, &m);
	FOR(i,0,n-1)
	{
		scanf("%d", &A[i]);
		cnt[A[i]] = 0;
	}

	FOR(i,0,m-1)
	{
		scanf("%d %d %d", &q[i].l, &q[i].r, &q[i].k);
		q[i].l--; q[i].r--; q[i].idx = i;
	}
	sort(q, q + m, cmp);

	int l=0,r=-1;
  FOR(i,0,m-1)
	{
    int nextL=q[i].l, nextR=q[i].r, tmp;
		while(r<nextR)
      add(++r);
    while(l>nextL)
      add(--l);
    while(r>nextR)
      rmv(r--);
    while(l<nextL)
      rmv(l++);

		if(maxNum>q[i].k)
    	ans[q[i].idx] = *hashSet[maxNum].begin();
		else
			ans[q[i].idx]=-1;
  }

	FOR(i,0,m-1)
		printf("%d\n", ans[i]);


}
