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

#define VI vector <long long>
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

struct Query{
  int l,r,type;
};

void build(VI& B, int node, int l, int r)
{
  if(l==r) return;

  B[2*node] = (B[2*node]+B[node])%MOD;
  B[2*node+1] = (B[2*node+1]+B[node])%MOD;
  B[node] = 0;
}

void update(VI& B, int node, int l, int r, int a, int b, LL val)
{
  build(B,node,l,r);
  if(l>b || r<a) return;
  if(l>=a && r<=b)
  {
    B[node] = (B[node]+val)%MOD;
    return;
  }
  update(B,2*node,l,(l+r)/2,a,b,val);
  update(B,2*node+1,1+(l+r)/2,r,a,b,val);
}

LL query(VI& B, int node, int l, int r, int idx)
{
  if(l==r) return B[node];
  build(B,node,l,r);

  if(idx<=(l+r)/2)
    return query(B,2*node,l,(l+r)/2,idx);
  return query(B,2*node+1,1+(l+r)/2,r,idx);
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
    VI A(n+1,0), B(4*m);
    Query q[m];
    FOR(i,0,m-1)
    {
      scanf("%d %d %d", &q[i].type, &q[i].l, &q[i].r);
      q[i].l--; q[i].r--;
    }

    FORD(i,m-1,0)
    {
      LL num = (1 + query(B,1,0,m-1,i))%MOD;
      if(q[i].type == 1)
      {
        A[q[i].l] = (A[q[i].l] + num)%MOD;
        A[q[i].r+1] = (A[q[i].r+1] + MOD - num)%MOD;
      }
      else
        update(B,1,0,m-1,q[i].l,q[i].r,num);
    }

    LL ans = 0;
    FOR(i,0,n-1)
    {
      ans = (ans + A[i])%MOD;
      printf("%Ld ", ans);
    }
    printf("\n");
  }

}
