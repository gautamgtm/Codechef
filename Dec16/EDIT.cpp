//EDIT
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
	int t;
	cin>>t;
	while(t--)
	{
		string a,b;
		cin>>a>>b;
		int l,d,w;
		cin>>l>>d>>w;
		int R[26][26];
		FOR(i,0,25)
			FOR(j,0,25)
				cin>>R[i][j];

		vector<string> ans;
		FOR(i,0,min(a.size(),b.size())-1)
		{
			if(a[i]!=b[i])
			{
				if( (d+l) >= R[a[i]-'A'][b[i]-'A'])
					ans.PB("R "+to_string(i+1)+" "+b[i]);
				else
				{
					ans.PB("D "+to_string(i+1));
					ans.PB("I "+to_string(i)+" "+b[i]);
				}
			}
		}

		if(a.length()<b.length())
			FOR(i,a.size(),b.size()-1)
				ans.PB("I "+to_string(i)+" "+b[i]);

		if(a.length()>b.length())
			FOR(i,b.size(),a.size()-1)
				ans.PB("D "+to_string(b.size()+1));

		cout<<ans.size()<<endl;
		FIT(it,ans)
			cout<<*it<<endl;

	}

}
