//CHMTDV
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

int Arr[505][505];

LL findMax(int n, vector<int>& row, vector<int>& col)
{
	LL temp = 0;
	FOR(i,0,row.size())
	{
		int i1,i2,j1,j2;
		if(i==0)
		{
			i1 = 0; i2 = row[i];
		}
		else
		if(i==row.size())
		{
			i1 = row[i-1]+1; i2 = n-1;
		}
		else
		{
			i1 = row[i-1]+1; i2 = row[i];
		}
		FOR(j,0,col.size())
		{
			LL sum = 0;
			if(j==0)
			{
				j1 = 0; j2 = col[j];
			}
			else
			if(j==col.size())
			{
				j1 = col[j-1]+1; j2 = n-1;
			}
			else
			{
				j1 = col[j-1]+1; j2 = col[j];
			}
			//printf("%d %d %d %d\n", i1, i2, j1, j2);
			FOR(a,i1,i2)
			{
				FOR(b,j1,j2)
				{
					sum += Arr[a][b];
				}
			}
			temp = max(temp, sum);
		}
	}

	return temp;
}

//Returns True if it is possible to partition the array within *part* partitions with max Sum less than maxSum.
bool isPossible(LL A[], LL maxSum , vector<int> &ans, int n, int part)
{
	vector<int> temp;
	int idx=0;
	while(idx<n-1)
	{
		LL sum=0;
		while(sum+A[idx]<maxSum && idx<n-1)
		{
			sum += A[idx];
			idx++;
		}
		if(idx<n-1)
			temp.PB(idx);
		idx++;
	}

	if(temp.size() == part)
		ans = temp;

	if(temp.size() <= part)
		return true;
	else
		return false;

}

void solvePartitionGreedy(LL A[], int n, int p, vector<int> &ans)
{
		//All possible sum of sumsets
		vector<LL> sumPossible;
		FOR(i,0,n-1)
		{
			LL temp = 0;
			FOR(j,i,n-1)
			{
				temp += A[j];
				sumPossible.PB(temp);
			}
		}

		sort(sumPossible.begin(), sumPossible.end());

		//Iterate through all the sums values using binary search and check if it is possible in p partitions
		LL left=0, right=sumPossible.size()-1;
		while(left<=right)
		{
			LL mid=(left+right)/2;
			if(isPossible(A,sumPossible[mid],ans,n,p))
				right = mid-1;
			else
				left = mid+1;
		}
}

int main()
{
	cin.sync_with_stdio(0);
	int n,p;
	scanf("%d %d", &n, &p);
	FOR(i,0,n-1)
		FOR(j,0,n-1)
			scanf("%d", &Arr[i][j]);

	//solveRandom(n,p);

	LL row[n]={}, column[n]={};
	FOR(i,0,n-1)
		FOR(j,0,n-1)
			row[i] += Arr[i][j];

	FOR(i,0,n-1)
		FOR(j,0,n-1)
			column[i] += Arr[j][i];

	vector<int> rowAns(p-1), colAns(p-1);
	rowAns[0] = (n-1)/(p);
	FOR(i,1,p-2)
		rowAns[i] = rowAns[i-1] + (n-1-rowAns[i-1])/(p-i);
	colAns = rowAns;

	vector<int> ansRand(p-1), ansRow(p-1), ansCol(p-1);
	ansRand = rowAns;

	solvePartitionGreedy(row, n, p-1, rowAns);
	solvePartitionGreedy(column, n, p-1, colAns);

	LL minm = findMax(n, rowAns, colAns);
	ansRow = rowAns; ansCol = colAns;
	LL temp = findMax(n, ansRand, ansRand);
	if(temp < minm)
	{
		ansRow = ansRand;
		ansCol = ansRand;
		minm = temp;
	}
	temp = findMax(n, ansRand, colAns);
	if(temp < minm)
	{
		ansRow = ansRand;
		ansCol = colAns;
		minm = temp;
	}
	temp = findMax(n, rowAns, ansRand);
	if(temp < minm)
	{
		ansRow = rowAns;
		ansCol = ansRand;
		minm = temp;
	}

	FOR(i,0,p-2)
		printf("%d ", ansRow[i]+1);
	printf("\n");
	FOR(i,0,p-2)
		printf("%d ", ansCol[i]+1);
	printf("\n");

}
