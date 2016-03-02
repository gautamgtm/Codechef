//PCYCLE
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

int main()
{
	cin.sync_with_stdio(0);
	int n;
	scanf("%d", &n);
	int num[n+1];
	FOR(i,1,n)
	{
		scanf("%d", &num[i]);
	}

	int cycle = 0; bool visited[n+1]={0};visited[0]=1;
	VI newNum;
	while(true)
	{
		int start=1;
		while(visited[start] && start<=n)
		{
			start++;
		}
		if(start == n+1)
			break;

		visited[start]=1;newNum.PB(start);
		int end=num[start];
		while(end != start)
		{
			newNum.PB(end);
			visited[end] = 1;
			end = num[end];
		}
		newNum.PB(end);
		cycle++;
	}

	//Print
	printf("%d\n", cycle);
	int start=0;
	while(start<newNum.size())
	{
		printf("%d ", newNum[start]);
		int end = start+1;
		while(newNum[end] != newNum[start])
		{
			printf("%d ", newNum[end]);
			end++;
		}
		printf("%d\n", newNum[start]);
		start = end+1;
	}

}