//CHEFTWOS
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

bool isGood(string A)
{
	int i = 0, n = A.size();
	while(i < n-1)
	{
		if(A[i] == '2')
		{
			if(!(i<n-3 && A[i+1] == '2' && A[i+2] == '1'))
				return false;
			i += 3;
		}
		else
			i++;
	}
	return true;
}


int solve(string a, string b, int idx)
{
	if(idx==a.size())
	{
		return isGood(a) && isGood(b);
	}

	int s1 = solve(a,b,idx+1);

	//Swap the characters
	a[idx] = a[idx] + b[idx];
	b[idx] = a[idx] - b[idx];
	a[idx] -= b[idx];
	int s2 = solve(a,b,idx+1);

	return s1 + s2;
}

int main()
{
	//cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		string a,b;
		cin>>a>>b;
		int count = solve(a,b,0);

		printf("%d\n", count);
	}

}
