//CHEFSPL
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
#define lmt 1000000

bool isPossible(string arr, int idx1, int idx2, int lmt1, int lmt2, int common)
{
	
	int count=0;
	while(idx1 <= lmt1 && idx2 <= lmt2)
	{
		if(arr[idx1] == arr[idx2])
		{
			count++; idx1++; idx2++;
		}
		else
		{
			idx2++;
		}
	}

	if(count == common)
		return true;
	else
		return false;
}

int main()
{
	//cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		string arr;
		//scanf("%s", arr);
		cin>>arr;
		int sz = arr.size();
		
		//Base case
		if(sz == 1)
		{
			printf("NO\n");
			continue;
		}

		if(sz%2 == 0)
		{	
			string arr1, arr2;
			arr1 = arr.substr(0, sz/2);
			arr2 = arr.substr(sz/2, sz/2);

			if(arr1 == arr2)
				printf("YES\n");
			else
				printf("NO\n");			
		}
		else
		{
			bool flag1 = isPossible(arr, 0, sz/2, sz/2-1, sz-1, sz/2);
			bool flag2 = isPossible(arr, sz/2+1, 0, sz-1, sz/2, sz/2);
			bool flag3 = (arr.substr(1, sz/2) == arr.substr(sz/2+1, sz/2));

			bool flag = flag1 || flag2 || flag3;

			if(flag)
				printf("YES\n");
			else
				printf("NO\n");	

		}
	}
}