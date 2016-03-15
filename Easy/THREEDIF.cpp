//THREEDIF
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

#define MP make_pair
#define PB push_back

#define FF first
#define SS second
#define PI 3.14159265358979323846
#define MOD 1000000007
#define INF INT_MAX //Infinity

ULL solve(ULL a, ULL b, ULL c)
{
	ULL ans = a%MOD;
	ans = (ans * ((b-1)%MOD))%MOD;
	ans = (ans * ((c-2)%MOD))%MOD;	
	return ans%MOD;
}

int main()
{
	//cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		ULL A[3];
		cin>>A[0]>>A[1]>>A[2];

		sort(A,A+3);
		ULL a = A[0], b = A[1], c = A[2];

		ULL ans = solve(a,b,c);
		//ULL ans=((((a%1000000007)*((b-1)%1000000007))%1000000007)*((c-2)%1000000007))%1000000007;

		cout<<ans<<endl;
	}

}