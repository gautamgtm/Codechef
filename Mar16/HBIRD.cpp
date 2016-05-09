//HBIRD
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

vector<int> birds, sumBirds;

int main()
{
	cin.sync_with_stdio(0);
	int n,m,t;
	scanf("%d %d %d", &n, &m, &t);
	int A[n][m], rowSum[n][m+1], columnSum[n+1][m];
	memset(rowSum,0,sizeof(rowSum));
	memset(columnSum,0,sizeof(columnSum));

	FOR(i,0,n-1)
	{
		FOR(j,0,m-1)
		{
			scanf("%d", &A[i][j]);
		}
	}
	
	FOR(i,0,n-1)
	{
		rowSum[i][0] = 0;
		FOR(j,0,m-1)
		{
			rowSum[i][j+1] = rowSum[i][j] + A[i][j];
		}
	}
	FOR(j,0,m-1)
	{
		columnSum[0][j] = 0;
		FOR(i,0,n-1)
		{
			columnSum[i+1][j] = columnSum[i][j] + A[i][j];
		}
	}

	//Right Triangles lying downwards
	FOR(row,0,n-1)
	{
		int size = 1;
		while(row+size < n)
		{
			FOR(column,size,m-1)
			{
				int food=0;
				FOR(i,0,size)
					food += rowSum[row+i][column-i+1]-rowSum[row+i][column-size];			

				birds.PB(food);
			}
			FORD(column,m-1-size,0)
			{
				int food=0;
				FOR(i,0,size)
					food += rowSum[row+i][column+size+1]-rowSum[row+i][column+i];	

				birds.PB(food);
			}
			size++;
		}	

	}
	//Right Triangles lying upwards
	FORD(row,n-1,0)
	{
		int size = 1;
		while(row-size >= 0)
		{
			FOR(column,size,m-1)
			{
				int food=0;
				FOR(i,0,size)
					food += rowSum[row-i][column-i+1]-rowSum[row-i][column-size];			

				birds.PB(food);
			}
			FORD(column,m-1-size,0)
			{
				int food=0;
				FOR(i,0,size)
					food += rowSum[row-i][column+size+1]-rowSum[row-i][column+i];		

				birds.PB(food);
			}
			size++;
		}	

	}

	//Downward Facing Triangles
	FOR(row,0,n-1)
	{
		int size = 2;
		while(row+size/2 < n)
		{
			FOR(column,size/2,m-1-size/2)
			{
				int food=0;
				FOR(i,0,size/2)
					food += rowSum[row+i][column+size/2-i+1]-rowSum[row+i][column-size/2+i];			

				birds.PB(food);
			}
			size+=2;
		}	

	}

	//Upward Facing Triangles
	FORD(row,n-1,0)
	{
		int size = 2;
		while(row-size/2 >= 0)
		{
			FOR(column,size/2,m-1-size/2)
			{
				int food=0;
				FOR(i,0,size/2)
					food += rowSum[row-i][column+size/2-i+1]-rowSum[row-i][column-size/2+i];			

				birds.PB(food);
			}
			size+=2;
		}	

	}

	//Rightward Facing Triangles
	FOR(column,0,m-1)
	{
		int size = 2;
		while(column+size/2 < m)
		{
			FOR(row,size/2,n-1-size/2)
			{
				int food=0;
				FOR(i,0,size/2)
					food += columnSum[row+size/2-i+1][column+i]-columnSum[row-size/2+i][column+i];			

				birds.PB(food);
			}
			size+=2;
		}	

	}

	//Leftward Facing Triangles
	FORD(column,m-1,0)
	{
		int size = 2;
		while(column-size/2 >= 0)
		{
			FOR(row,size/2,n-1-size/2)
			{
				int food=0;
				FOR(i,0,size/2)
					food += columnSum[row+size/2-i+1][column-i]-columnSum[row-size/2+i][column-i];			

				birds.PB(food);
			}
			size+=2;
		}	

	}
	/*
	FOR(i,0,birds.size()-1)
	{
		printf("%d ", birds[i]);
	}
	printf("\n");*/

	sort(birds.begin(), birds.end());

	sumBirds.PB(birds[0]);
	FOR(i,1,birds.size()-1)
	{
		sumBirds.PB(sumBirds[i-1] + birds[i]);
	}
	
	LL zero = upper_bound(sumBirds.begin(), sumBirds.end(), 0) - sumBirds.begin();
	while(t--)
	{
		int grain;
		scanf("%d", &grain);

		LL ans = upper_bound(sumBirds.begin(), sumBirds.end(), grain) - sumBirds.begin();
		
		printf("%Ld\n", ans-zero);
		
	}

}