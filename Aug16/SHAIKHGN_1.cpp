//SHAIKHGN
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
  int n;
  scanf("%d", &n);
  bool A[n][n];
  FOR(i,0,n-1)
  {
    FOR(j,0,n-1)
    {
      scanf("%d", &A[i][j]);
    }
  }

  int m;
  scanf("%d", &m);
  FOR(i,0,m-1)
  {
    int k,x;
    scanf("%d %d", &k, &x);
		x--;
		bool ans[n] = {0};
		ans[x] = 1;

		FOR(i,1,k)
		{
			bool temp[n]={0};
			FOR(j,0,n-1)
			{
				if(ans[j])
				{
					FOR(k,0,n-1)
					{
						temp[k] = temp[k] | A[j][k];
					}
				}
			}
			FOR(j,0,n-1)
				ans[j] = temp[j];
		}

		int count = 0;
		FOR(i,0,n-1)
		{
			if(ans[i])
				count++;
		}

		printf("%d\n", count);
		if(count == 0)
		{
			printf("-1\n");
			continue;
		}
		FOR(i,0,n-1)
		{
			if(ans[i])
				printf("%d ", i+1);
		}
		printf("\n");
	}
}
