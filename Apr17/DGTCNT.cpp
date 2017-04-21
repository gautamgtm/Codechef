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

LL solveBF(int A[], LL l, LL r)
{
	LL ans=r-l+1;
	FOR(i,l,r)
	{
		LL num = i;
		int B[10]={};
		while(num)
		{
			B[num%10]++;
			num /= 10;
		}
		FOR(i,0,9)
		{
			if(A[i] == B[i])
			{
				ans--;break;
			}
		}
	}
	return ans;
}

LL solve(LL l, LL r)
{
	if(r < 1023456789)
		return 0;


}

int main()
{
	cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		LL l,r;
		scanf("%Ld %Ld", &l, &r);
		int A[10], num=0;
		FOR(i,0,9)
		{
			scanf("%d", &A[i]);
			if(A[i]) num++;
		}

		LL answer;
		if(num==0)
			answer = solve(l,r);
		else
			answer = solveBF(A,l,r);
		printf("%Ld\n", answer);

	}

}
