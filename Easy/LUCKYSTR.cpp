//LUCKYSTR
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
	//cin.sync_with_stdio(0);
	int k,n;
	scanf("%d %d", &k, &n);
	string Lucky[k];
	FOR(i,0,k-1)
		cin>>Lucky[i];
	FOR(i,0,n-1)
	{
		string str;
		cin>>str;
		if(str.size()>=47)
		{
			printf("Good\n");
			continue;
		}
		bool flag = false;
		FOR(i,0,k-1)
		{
			if(str.find(Lucky[i]) != string::npos)
			{
				printf("Good\n");
				flag = true;
				break;
			}
		}
		if(!flag)
		{
			printf("Bad\n");
		}
	}

}