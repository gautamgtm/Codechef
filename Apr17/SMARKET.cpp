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
#define lmt 100005

int block, cnt[lmt], toRight[lmt], toLeft[lmt];

struct query{
	int L, R, K, idx;
}Q[lmt];

bool cmp(query q1, query q2)
{
	if(q1.L/block != q2.L/block)
		return q1.L/block < q2.L/block;
	return q1.R < q2.R;
}

void add(int A[], int p, int ptr)
{
	int count;
	if(p>=ptr)
		count = min(toLeft[p], p-ptr+1);
	else
		count = min(toRight[p], ptr-p+1);
	cnt[count]++;
}

void remove(int A[], int p, int ptr)
{
	int count;
	if(p>=ptr)
		count = min(toLeft[p], p-ptr+1);
	else
		count = min(toRight[p], ptr-p+1);
	cnt[count]--;
}

int solveBF(int A[], int l, int r, int k)
{
	int ans=0, curr=1;
	FOR(i,l+1,r)
	{
		if(A[i] == A[i-1])
			curr++;
		else
		{
			if(curr >= k)
				ans++;
			curr = 1;
		}
	}
	if(curr >= k)
		ans++;

	return ans;
}

int main()
{
	cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n,q;
		scanf("%d %d", &n, &q);
		int A[n], ans[q], ansBF[q];
		FOR(i,0,n-1)
			scanf("%d", &A[i]);

		toLeft[0] = 1;
		FOR(i,1,n-1)
		{
			if(A[i] == A[i-1])
				toLeft[i] = 1 + toLeft[i-1];
			else
				toLeft[i] = 1;
		}
		toRight[n-1] = 1;
		FORD(i,n-2,0)
		{
			if(A[i] == A[i+1])
				toRight[i] = 1 + toRight[i+1];
			else
				toRight[i] = 1;
		}

		FOR(i,0,q-1)
		{
			scanf("%d %d %d", &Q[i].L, &Q[i].R, &Q[i].K);
			Q[i].L--; Q[i].R--; Q[i].idx = i;
		}
		block = (int)sqrt((double)n);
		FOR(i,0,n)
			cnt[i] = 0;
		sort(Q,Q+q,cmp);

		int currentL=0, currentR=-1;
		FOR(i,0,q-1)
		{
			int L=Q[i].L, R=Q[i].R, K=Q[i].K;
			while(currentR < R)
			{
				currentR++;
				add(A,currentR,currentL);
			}
			while(currentR > R)
			{
				remove(A,currentR,currentL);
				currentR--;
			}
			while(currentL < L)
			{
				remove(A,currentL,currentR);
				currentL++;
			}
			while(currentL > L)
			{
				currentL--;
				add(A,currentL,currentR);
			}
			ans[Q[i].idx] = cnt[K];
			ansBF[Q[i].idx] = solveBF(A,L,R,K);
		}

		FOR(i,0,q-1)
			printf("%d %d\n", ans[i], ansBF[i]);
	}

}
