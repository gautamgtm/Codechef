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
#define LDB double
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
#define INF INT_MAX //
#define threshold 1E-15

LDB binomialCoeff(int n, int k)
{
	LDB ans = 1;
	FOR(i,1,k)
		ans = ans * (n+1-i) / (k+1-i);

	return ans;
}

LDB expoMult(LDB ans, LDB n, int k)
{
	LDB res = ans, base = n;
	int exp_ = k;
	while(exp_>0)
	{
		if(exp_%2 == 1)
		{
			res *= base;
		}
		base *= base;
		exp_ /= 2;
	}
	return res;
}

LDB cumulativeDistribution(LDB n, LDB k)
{
	LDB ans = 0.000, divisor = 1.0000/sqrt(PI*n/2);
	FORD(i,k,0)
	{
		LDB temp = exp(-2*(i-n/2)*(i-n/2)/n) * divisor;
		if(temp < threshold)
			break;
		ans += temp;
	}
	return ans;
}

int main()
{
	//cin.sync_with_stdio(0);
	setprecision(9);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n,m,p,k;
		scanf("%d %d %d %d", &n, &m, &p, &k);
		if(p==0)
		{
			printf("1\n");
			continue;
		}
		if(m%2==1 && n%2==1)
		{
			printf("0\n");
			continue;
		}
		if(m%2==0 && n%2==0)
		{
			printf("1\n");
			continue;
		}

		bool negate = false;
		if(p < k-p+1)
			negate = true;
		LDB ans = 1, temp = ans;

		if(k > 15000)
		{
			ans = 1.00000000 - cumulativeDistribution((LDB)k, (LDB)p-1);
			cout << fixed;
      cout << setprecision(8);
			cout<<ans<<endl;
			continue;

		}

		if(negate)
		{
			FOR(i,1,p-1)
			{
				temp = (temp * ((k-i+1) / (LDB) i));
				ans = ans + temp;
			}
		}
		else
		{
			FORD(i,k-1,p)
			{
				temp = (temp * ((i+1) / (LDB) (k-i) ));
				ans = ans + temp;
			}
		}
		ans = expoMult(ans, 0.5, k);
		if(negate)
			ans = 1.00000 - ans;
    cout << fixed;
    cout << setprecision(8);
		cout<<ans<<endl;
	}
}
