//FENWITER
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

int countOne(string s)
{
	int temp = 0;
	FOR(i,0,s.size()-1)
		if(s[i] == '1')
			temp++;
	return temp;
}

int countOneFromEnd(string s)
{
	int temp = 0;
	if(s[s.size()-1] == '1')
	{
		int idx = s.size()-1;
		while(s[idx]=='1' && idx>=0)
		{
			idx--;
			temp++;
		}
	}
	return temp;
}

int main()
{
	//cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		string a,b,c;
		cin>>a>>b>>c;
		int n;
		cin>>n;

		LL t1=countOne(a), t2=countOne(b), t3=countOne(c);
		LL idx1=countOneFromEnd(a), idx2=countOneFromEnd(b), idx3=countOneFromEnd(c);
		LL ans = 0;

		if(idx3 != c.size())
			ans = (t3-idx3+1) + n*t2 + t1;
		else
		{
			if(idx2 != b.size())
				ans = (t2-idx2+1) + (n-1)*t2 + t1;
			else
				ans = (1 + t1 - idx1);
		}

		printf("%Ld\n", ans);
	}

}
