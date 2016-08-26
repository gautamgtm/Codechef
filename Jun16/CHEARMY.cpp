//CHEARMY
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

	LL arr[20];
	arr[0] = 5, arr[1] = 20;
	FOR(i,2,19)
		arr[i] = arr[i-1] * 5;

	FOR(i,1,19)
		arr[i] = arr[i] + arr[i-1];

	int t;
	scanf("%d", &t);
	while(t--)
	{
		LL n;
		scanf("%Ld", &n);

		LL idx;
		FOR(i,0,19)
		{
			idx = i;
			if(n <= arr[i])
				break;
		}

		if (idx == 0)
		{
			printf("%d\n", 2*(n-1));
			continue;
		}

		n = n - arr[idx-1];
		int A[idx+1]={};
		n--;
		A[0] = ((int)floor(n/pow(5,idx)) + 1) * 2;
		n = n % (LL)pow(5, idx);
		FOR(i,1,idx)
		{
			A[i] = (int)floor(n/pow(5, idx-i)) * 2;
			n = n % (LL)pow(5, idx-i);
		}

		FOR(i,0,idx)
			printf("%d", A[i]);
		printf("\n");
	}

}
