//FORESTGA
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
#define lmt 100005

LL int_div ( LL numerator, LL denominator )
{
    return numerator / denominator
             + (((numerator < 0) ^ (denominator > 0)) && (numerator%denominator));
}

int main()
{
	cin.sync_with_stdio(0);
	LL n,w,l;
	scanf("%Ld %Ld %Ld", &n, &w, &l);
 	
 	
	LL h[n], r[n], t[n];
	FOR(i,0,n-1)
	{
		scanf("%Ld %Ld", &h[i], &r[i]);
		t[i] = max((LL)0, int_div(l-h[i], r[i]));
	}

	pair<LL, LL> arr[n];
	FOR(i,0,n-1)
		arr[i] = MP(t[i], i);
 
	sort(arr, arr + sizeof arr / sizeof *arr);
 
	LL wood=0, rate=0, ans=0;
	FOR(i,0,n-1)
	{
		if(wood>=w) break;
 
		if(rate != 0)//Included trees may grow in the meantime
		{
			//Check if before the next tree is ready to be cut, can the required wood be collected.
			LL temp = int_div(w-wood, rate);
			if(ans + temp < arr[i].first)
			{
				ans += temp; wood += temp*rate;
				break;
			}
		}
		
		wood += rate*(arr[i].first-ans) + (h[arr[i].second] + r[arr[i].second]*arr[i].first);
 
		ans = arr[i].first; rate += r[arr[i].second];
		//printf("%Ld %Ld %Ld\n", ans, wood, rate);
		
	}
	if(wood<w)
	{
		ans += int_div(w-wood, rate);
	}
	printf("%Ld\n", ans);
 
} 