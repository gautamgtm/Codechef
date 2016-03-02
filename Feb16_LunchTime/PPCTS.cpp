//PPCTS
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
#define count 1000000

int n,m;
int posX=0, posY=0;
int disX[2*count+1]={}, disY[2*count+1]={};
LL length=0;

void solve(bool a, bool b)
{
	int small, large,answer;
	if(a == 0)
	{
		if(b==0)
		{
			small = disX[posX+count];	
			large = disX[2*count] - disX[posX+count];
			posX++;
			answer = small - large;
		}	
		else
		{
			posX--;
			small = disX[posX+count];
			large = disX[2*count] - disX[posX+count];		
			answer = large - small;
		}
	}
	else
	{
		if(b==0)
		{
			small = disY[posY+count];	
			large = disY[2*count] - disY[posY+count];
			posY++;
			answer = small - large;
		}	
		else
		{
			posY--;
			small = disY[posY+count];
			large = disY[2*count] - disY[posY+count];		
			answer = large - small;
		}
	}

	length += answer;

}

int main()
{
	//cin.sync_with_stdio(0);
	scanf("%d %d", &n, &m);	
	FOR(i,1,n)
	{
		int a,b;
		scanf("%d %d", &a, &b);
		disX[count+a]++; disY[count+b]++;
		length += (abs(a) + abs(b));
	}

	FOR(i,1,2*count)
	{
		disX[i] += disX[i-1];
		disY[i] += disY[i-1];
	}

	char path[m];
	FOR(i,0,m-1)
		scanf("%s", &path[i]);
	FOR(i,0,m-1)
	{
		bool a,b;
		if(path[i] == 'D')
		{
			a = 1; b = 1;
		}
		else if(path[i] == 'U')
		{
			a = 1; b = 0;
		}
		else if(path[i] == 'L')
		{
			a = 0; b = 1;
		}
		else if(path[i] == 'R')
		{
			a = 0; b = 0;
		}
		
		solve(a,b);
		printf("%Ld\n", length);
	}
}