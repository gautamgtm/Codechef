//BINTREE
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

int main()
{
	cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int i,j;
		scanf("%d %d", &i, &j);

		int h1 = floor(double(log(i)/log(2)));
		int h2 = floor(double(log(j)/log(2)));
	
		VI node1, node2;
		while(i)
		{
			node1.PB(i);
			i /= 2;
		}
		while(j)
		{
			node2.PB(j);
			j /= 2;
		}

		int common=-1;
		int m=node1.size()-1, n=node2.size()-1;
		while(true)
		{
			if(node1[m] == node2[n] && m>=0 && n>=0)
			{
				m--;n--;common++;
			}
			else
			{
				break;
			}
		}
		int distance = h1 + h2 - 2*common;

		printf("%d\n", distance);
	}

}