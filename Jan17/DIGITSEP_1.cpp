//DIGITSEP
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

LL gcd(LL a, LL b)
{
	if(a<0 || b<0)
		return 0;
	if(a==0 && b==0)
		return 0;
	if(b==0)
		return a;
	else
		return gcd(b, a%b);
}

int main()
{
	cin.sync_with_stdio(0);
	LL t;
	cin>>t;
	while(t--)
	{
		LL n;
		cin>>n;
		string str;
		cin>>str;
		LL m,x,y;
		cin>>m>>x>>y;
    if(m>n)
      m = n;

		LL maxGCD = 0;
		vector<vector<set<LL>>> DP(n+1, vector<set<LL>>(n));

		//K numbers with (K-1) partitions
		DP[1][0].insert(str[0]-'0');
		FOR(i,2,n)
		{
			LL getGCD = gcd(*(DP[i-1][i-2].begin()), (str[i-1]-'0'));
			DP[i][i-1].insert(getGCD);
		}

    //No partition
    FOR(i,2,m)
    	DP[i][0].insert(10*(*(DP[i-1][0].begin())) + (str[i-1]-'0'));


		FOR(i,1,n)
		{
			int minPart = max((int)(ceil((double)i/m))-1,1), maxPart = i-2;
			FOR(j,minPart,maxPart)
			{
				LL num=0, mult=1;
				set<LL> mySet;
				FOR(k,1,m)
				{
					if(i-k < 1 || j-1 > (i-k-1))
						break;
					num += mult*(str[i-k]-'0');
					mult *= 10;

					FIT(it,DP[i-k][j-1])
						mySet.insert(gcd(*it, num));
				}
				DP[i][j] = mySet;
			}
		}

		FOR(i,x,y)
		{
			if(!DP[n][i].empty())
				maxGCD = max(maxGCD, *(DP[n][i].rbegin()));
		}
		cout<<maxGCD<<endl;

	}

}
