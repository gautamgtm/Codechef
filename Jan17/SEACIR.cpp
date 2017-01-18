//SEACIR
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
#define lmt 10005

int main()
{
	cin.sync_with_stdio(0);
	int n,s,skip;
	scanf("%d %d %d", &n, &s, &skip);

	VI radius(2*n);
	FOR(i,0,2*n-1)
		scanf("%d", &radius[i]);

	sort(radius.begin(), radius.end());
	reverse(radius.begin(), radius.end());

	int threshold = radius[skip];
	int block = s/(2*radius[0]), idx=0, skipLeft=skip;

	vector<int> empty;
	FOR(i,0,block*block-1)
		empty.PB(i);

	srand(unsigned(time(NULL)));
	random_shuffle(empty.begin(), empty.end());

	//printf("%d %d\n", threshold, block);
	FOR(i,0,n-1)
	{
		int r;
		scanf("%d", &r);

		if(r >= threshold && skipLeft > 0)
		{
			printf("-1 -1\n");
			fflush(stdout);
			skipLeft -= 1;
			continue;
		}

		if(skipLeft >= n-i)
		{
			printf("-1 -1\n");
			fflush(stdout);
			skipLeft -= 1;
			continue;
		}

		//Place the circle
		int a,b, row=empty[idx]/block, column=empty[idx]%block;
		a = (2*row+1)*radius[0];
		b = (2*column+1)*radius[0];


		if(a>s-r || a<r || b>s-r || b<r)
		{
			//Randomly assign
			a = r + (rand()%(s-2*r+1));
			b = r + (rand()%(s-2*r+1));
		}

		printf("%d %d\n", a, b);
		idx += 1;
		fflush(stdout);
	}


}
