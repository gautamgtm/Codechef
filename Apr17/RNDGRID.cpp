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
#define PRINTV(it,v) for (auto it = v.begin(); it != v.end(); it++) printf("%d ", *it);
#define PRINTA(A, n) for (auto i = 0; i <= (a); i++) printf("%d ", A[i]);

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
	cin>>t;
	while(t--)
	{
		int l,n, blocker=0;
		cin>>l>>n;
		string str, temp;
		bool A[n][n]={};
		cin>>str;
		vector<PII> myVec;
		FOR(i,0,n-1)
		{
			cin>>temp;
			FOR(j,0,n-1)
				if(temp[j] == '#')
					A[i][j] = 1, myVec.PB(MP(i,j));
		}

		int ans[n][n], answer=0, sz=myVec.size();
		vector<PII> len(l);
		len[0] = MP((str[0]=='R') - (str[0]=='L'), (str[0]=='D') - (str[0]=='U'));
		FOR(i,1,l-1)
			len[i] = MP(len[i-1].first + (str[i]=='R') - (str[i]=='L'), len[i-1].second + (str[i]=='D') - (str[i]=='U'));

		if(sz < 0.1 * n * n)
		{
			FOR(i,0,n-1)
				FOR(j,0,n-1)
					ans[i][j] = l;

			FOR(i,0,l-1)
			{
				if(str[i]=='L' || str[i]=='R')
				{
					FOR(j,0,n-1)
					{
						if(len[i].first==0 || len[i].first > n || len[i].first < -1*n)
							continue;
						else
						if(len[i].first < 0)
							ans[j][-1-len[i].first] = min(ans[j][-1-len[i].first], i);
						else
							ans[j][n-len[i].first] = min(ans[j][n-len[i].first], i);
					}
					FOR(j,0,sz-1)
						if((myVec[j].first - len[i].second)>=0  && (myVec[j].first - len[i].second)<n && (myVec[j].second - len[i].first)>=0 && (myVec[j].second - len[i].first)<n)
							ans[myVec[j].first - len[i].second][myVec[j].second - len[i].first] = min(i, ans[myVec[j].first - len[i].second][myVec[j].second - len[i].first]);
				}
				else
				{
					FOR(j,0,n-1)
					{
						if(len[i].second==0 || len[i].second > n || len[i].second < -1*n)
							continue;
						else
						if(len[i].second < 0)
							ans[-1-len[i].second][j] = min(ans[-1-len[i].second][j], i);
						else
							ans[n-len[i].second][j] = min(ans[n-len[i].second][j], i);
					}
					FOR(j,0,sz-1)
						if((myVec[j].second - len[i].first)>=0  && (myVec[j].second - len[i].first)<n && (myVec[j].first - len[i].second)>=0 && (myVec[j].first - len[i].second)<n)
							ans[myVec[j].first - len[i].second][myVec[j].second - len[i].first] = min(i, ans[myVec[j].first - len[i].second][myVec[j].second - len[i].first]);
				}
			}

			FOR(i,0,n-1)
				FOR(j,0,n-1)
					if(!A[i][j])
						answer ^= ans[i][j];
			cout<<answer<<endl;
			continue;
		}

		FOR(i,0,n-1)
		{
			FOR(j,0,n-1)
			{
				if(A[i][j])
					continue;
				int x=i, y=j, steps=0;
				FOR(k,0,l-1)
				{
					if(str[k] == 'L')
					{
						if(y!=0 && A[x][y-1] != 1)	y--;
						else	break;
					}
					else
					if(str[k] == 'R')
					{
						if(y!=n-1 && A[x][y+1] != 1) y++;
						else break;
					}
					else
					if(str[k] == 'U')
					{
						if(x!=0 && A[x-1][y] != 1) x--;
						else break;
					}
					else
					{
						if(x!=n-1 && A[x+1][y] != 1) x++;
						else break;
					}
					steps++;
				}
				ans[i][j] = steps;
				answer ^= steps;
			}
		}

		cout<<answer<<endl;
	}

}
