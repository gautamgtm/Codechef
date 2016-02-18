//RECTLOVE
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
#define LLd long
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
 
int main()
{
	cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		LL n,m,k;
		scanf("%Ld %Ld %Ld", &n, &m, &k);
		long double answer = 0;
		long double total = n*(n+1)*m*(m+1)/4;
		FOR(a,1,k)
		{
			LL temp,i,j;
			scanf("%Ld", &temp);
			temp--;
			i = temp/m;
			j = temp%m;
 
			//(i+1)*(n-i)*(j+1)*(m-j);
			long double mult;
			//mult = (i+1)*(n-i)*(j+1)*(m-j);
			
			mult = 4;
			mult *= ((i+1)*(n-i));
			mult /= (n*(n+1));
			mult *= ((j+1)*(m-j));
			mult /= (m*(m+1));
 
			//mult /= total;
			answer += mult;
		}
 
		printf("%.15Lf\n", answer);
	}
} 
