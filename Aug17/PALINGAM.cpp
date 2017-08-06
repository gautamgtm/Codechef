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

int main()
{
	cin.sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
	{
		string s,t;
		cin>>s;
		cin>>t;

		int A[26]={0}, B[26]={0}, flag=0;
		FOR(i,0,s.length()-1) A[s[i]-'a']++;
		FOR(i,0,t.length()-1) B[t[i]-'a']++;

		FOR(i,0,25)
		{
			if(A[i]>=2 && B[i]==0)
			{
				flag = 1;
				break;
			}
		}

		bool AhasAllB = true,
		FOR(i,0,25)
			if(B[i] && A[i]==0) AhasAllB = false;

		if(AhasAllB)
		{
			FOR(i,0,25)
			{
				if(A[i] && B[i]==0)
				{
					flag = 1;
					break;
				}
			}
		}

		if(flag) cout<<"A\n";
		else cout<<"B\n";
	}

}
