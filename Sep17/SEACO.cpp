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

struct query{
  int l,r,type;
};

int main()
{
  cin.sync_with_stdio(0);
  int t;
  scanf("%d", &t);
  while(t--)
  {
    int n,m,ans=0;
    scanf("%d %d", &n, &m);
    VI A(n+1,0), B(m,1);
    query q[m];
    FOR(i,0,m-1) scanf("%d %d %d", &q[i].type, &q[i].l, &q[i].r);

    FORD(i,m-1,0)
    {
      if(q[i].type == 2)
      {
        FOR(j,q[i].l-1,q[i].r-1)
        {
          B[j] += B[i];
          if(B[j] >= MOD) B[j] -= MOD;
        }
      }
    }

    FOR(i,0,m-1)
    {
      if(q[i].type == 1)
      {
        A[q[i].l - 1] += B[i];
        if(A[q[i].l - 1] >= MOD) A[q[i].l - 1] -= MOD;

        if(A[q[i].r] >= B[i]) A[q[i].r] -= B[i];
        else A[q[i].r] = A[q[i].r] + MOD - B[i];
      }
    }

    FOR(i,0,n-1)
    {
      ans += A[i];
      if(ans >= MOD) ans -= MOD;
      printf("%d ", ans);
    }
    printf("\n");
  }

}
