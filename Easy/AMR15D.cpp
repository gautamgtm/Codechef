//AMR15D
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
#define LDB long double
#define MEM(a,b) memset(a,(b),sizeof(a))
#define FOR(i,a,b) for (auto i = (a); i <= (b); i++)
#define FORD(i,a,b) for (auto i = (a); i >= (b); i--)
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
	LL num;
	scanf("%Ld", &num);
	int A[num];
	for(LL i=0; i<num; i++)
	{
		scanf("%d", &A[i]);
	}
	sort(A,A+num);

	LL sumUptoIndex[num] = {0};
	sumUptoIndex[0] = A[0];
	for(LL i=1; i<num; i++)
	{
		sumUptoIndex[i] = sumUptoIndex[i-1]+A[i];
	}
	LL queries;
	scanf("%Ld", &queries);
	while(queries--)
	{
		LL k;
		scanf("%Ld", &k);

		//Solution
		LL steps = ceil(double(num)/(k+1));

		LL answer = sumUptoIndex[steps-1];
		printf("%Ld\n", answer);

	}

}