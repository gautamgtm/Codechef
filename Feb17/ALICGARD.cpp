//
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
	int n,f,x,y,penalty;
	scanf("%d %d %d %d %d", &n, &f, &x, &y, &penalty);
	x--;y--;
	int A[n][n], B[n][n], C[n][n],T[n][n];
	bool D[n][n]={};
	FOR(i,0,n-1)
		FOR(j,0,n-1)
			scanf("%d", &A[i][j]);
	FOR(i,0,n-1)
		FOR(j,0,n-1)
			scanf("%d", &B[i][j]);
	FOR(i,0,n-1)
		FOR(j,0,n-1)
			scanf("%d", &C[i][j]);
	FOR(i,0,n-1)
		FOR(j,0,n-1)
			T[i][j] = -200;

	FOR(i,0,f-1)
	{
		int x1,x2,y1,y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		x1--;x2--;y1--;y2--;
		FOR(i,x1,x2)
			FOR(j,y1,y2)
				D[i][j] = 1;
	}
	B[x][y]--;
	LL timePassed = 0;
	int isLeft = -1, isUp = -1;
	while(true)
	{
		timePassed++;
		T[x][y] = timePassed;
		vector<PII> possibleMoves;
		FOR(i,-1,1)
			FOR(j,-1,1)
				if(x+i>=0 && x+i<n && y+j>=0 && y+j<n && B[x+i][y+j]>0) && D[x+i][y+j] ==0)
					possibleMoves.PB(MP(x+i,y+j));
		if(!possibleMoves.size())
			break;
		int i = -1, maxm = -1;
		FOR(j,0,possibleMoves.size()-1)
		{
		    if(A[possibleMoves[j].first][possibleMoves[j].second] > maxm && timePassed - T[possibleMoves[j].first][possibleMoves[j].second] >= C[possibleMoves[j].first][possibleMoves[j].second])
		    {
		        maxm = A[possibleMoves[j].first][possibleMoves[j].second];
		        i = j;
						if(possibleMoves[j].first - x == 1)
							isLeft = 0;
						else
							isLeft = 1;
						if(possibleMoves[j].second - y == 1)
							isUp = 1;
						else
							isUp = 0;
		    }
		}
		if(i == -1)
		    i = rand()%possibleMoves.size();
		x = possibleMoves[i].first; y = possibleMoves[i].second;
		B[x][y]--;
		printf("MOVE %d %d\n", 1+x, 1+y);
	}
	printf("EXIT\n");

}
