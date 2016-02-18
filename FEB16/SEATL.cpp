//SEATL
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
#define MI map<int, int>
#define MMI multimap<int, int>
#define LL long long
#define LLd long
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
 
int A[1000005];
VI row[1000005], column[1000005], distinct;
 
int main()
{
	cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n,m;
		scanf("%d %d", &n, &m);		
		//Input
		FOR(i,0,m*n-1)
		{
			scanf("%d", &A[i]);
		}
		
		//Init Row and Column Vectors
		distinct.clear();
		FOR(i,0,n-1)
		{		
			FOR(j,0,m-1)
			{
				int temp = j + i*m;
				int num = A[temp];
				
				if(row[num].empty())
					distinct.PB(num);
 
				row[num].PB(i);
			}
		}
 
		FOR(j,0,m-1)
		{		
			FOR(i,0,n-1)
			{
				int temp = j + i*m;
				int num = A[temp];
				
				column[num].PB(j);
			}
		}
		//Find the max count for each distinct value
		int answer = 0;
		FORV(distinct, it)
		{
			int rowMaxCount=0, columnMaxCount=0;
			VI rowMax, columnMax;
			int num = (*it);
			for(int itt = 0; itt < row[num].size();)
			{
				int j = itt+1;
				while(j < row[num].size() && row[num][itt] == row[num][j])
				{
					j++;
				}
				int equal = j-itt;
				if(equal > rowMaxCount)
				{
					rowMaxCount = equal;
					rowMax = {row[num][itt]};
				}
				else if (equal == rowMaxCount)
				{
					rowMax.PB(row[num][itt]);
				}
				itt=j;
			}
			row[num].clear();
 
			for(int itt = 0; itt < column[num].size();)
			{
				int j = itt+1;
				while(j < column[num].size() && column[num][itt] == column[num][j])
				{
					j++;
				}
				int equal = j-itt;
				if(equal > columnMaxCount)
				{
					columnMaxCount = equal;
					columnMax = {column[num][itt]};
				}
				else if (equal == columnMaxCount)
				{
					columnMax.PB(column[num][itt]);
				}
				itt=j;
			}
			column[num].clear();
 
			int tempAnswer = rowMaxCount+columnMaxCount;
			bool found = 0;
			for(auto it1 = 0; it1 < rowMax.size(); it1++)
			{
				for(auto it2 = 0; it2 < columnMax.size(); it2++)
				{
					if(A[columnMax[it2] + rowMax[it1]*m] != num)
					{
						found = 1; break;
					}
				}
				if(found) break;
			}
 
			if(!found)
				tempAnswer--;
 
			answer = max(answer, tempAnswer);
		}
		
		printf("%d\n", answer);
	}
}
 
