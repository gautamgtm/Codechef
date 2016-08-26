//CHEFRRUN
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

inline void read(int &x)
{
	x=0;
	register char c=getchar_unlocked();
	for(;c<'0' || c>'9';c=getchar_unlocked());
	 for(;c>='0' && c<='9';c=getchar_unlocked())
	  x=(x<<3)+(x<<1)+(c-'0');
}

int main()
{
	cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		int A[n];
		FOR(i,0,n-1)
		{
			read(A[i]);
		}

		int found[n], skip = 0;
		FOR(i,0,n-1)
		{
			found[i] = -1;
		}

		FOR(i,0,n-1)
		{
			A[i] = (i + A[i] + 1)%n;
			found[A[i]] = 0;
		}

		FOR(i,0,n-1)
		{
			if(found[i] == -1)
				skip++;
		}

		FOR(i,0,n-1)
		{
			if(found[i] == 0)
			{
				//bool seq[n] = {0};
				int count = 0, idx = i;
				VI connected;
				connected.PB(idx);
				//seq[idx] = 1;

				while(count<=(n-skip))
				{
					idx = A[idx];
					//Fell in some older loop
					if(found[idx])
					{
						for(int j = connected.size()-1; j>=0; j--)
						{
							if(found[connected[j]] == 0)
								skip++;
							found[connected[j]] = -1;
						}
						break;
					}

					count++;
					connected.PB(idx);

					//Found a loop in the path
					if(find(connected.begin(), connected.end()-1, idx) != connected.end()-1 && idx != i)
					{
						found[connected[connected.size()-1]] = 1;
						for(int j = connected.size()-2; j>=0; j--)
						{
							if(connected[j] == idx)
							{
								FORD(k,j-1,0)
								{
									if(found[connected[k]] == 0)
										skip++;
									found[connected[k]] = -1;
								}
								break;
							}
							if(found[connected[j]] == 0)
								skip++;
							found[connected[j]] = 1;
						}
						break;
					}

					//seq[idx] = 1;
					//Found a loop from the start
					if(idx == i)
					{
						FIT(it,connected)
						{
							if(found[*it] == 0)
								skip++;
							found[*it] = 1;
						}
						break;
					}
				}
			}
		}

		int ans = 0;
		FOR(i,0,n-1)
		{
			if(found[i] == 1)
				ans++;
		}

		printf("%d\n", ans);
	}

}
