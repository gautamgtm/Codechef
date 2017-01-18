//DIGITSEP
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

int gcd(int a, int b)
{
	if(a==0 && b==0)
		return 0;
	if(b==0)
		return a;
	else
		return gcd(b, a%b);
}

int findGCD(string str, int n, int pos[], int sz)
{
	int ans=0, idx=n-1;
	FORD(i,sz-1,0)
	{
		LL num = 0, temp=1;
		FORD(j,idx,pos[i]+1)
		{
			num += (temp)*((str[j]-'0'));
			temp *= 10;
		}
		idx = pos[i];

		//cout<<ans<<" "<<num<<endl;
		ans = gcd(ans, num);
	}
	return ans;
}

void separate(string str, int n, int pos[], int sz, int m, int &maxGCD, int sep)
{
	if(sep == sz)
		maxGCD = max(maxGCD, findGCD(str, n, pos, sz));
	else
	{
		int start = max(1+pos[sep-1], n-1-m*(sz-sep)), end = min(m+pos[sep-1], n-2-(sz-1-sep));
		FOR(i,start, end)
		{
			pos[sep] = i;
			separate(str,n,pos,sz,m,maxGCD,sep+1);
		}
	}
}

int main()
{
	cin.sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		int m,x,y;
		cin>>m>>x>>y;

		int maxGCD = 0;
		//Brute Force
		FOR(i,x,y)
		{
			//Iterate through each option for i separators
			int pos[i+1]={0};
			pos[0] = -1;
			//Find the separators
			separate(str,n,pos,i+1,m,maxGCD,1);
		}

		cout<<maxGCD<<endl;
	}

}
