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
#define lmt 1000005

int minLength(string str, int n, int ans)
{
	int idx=1, sz=1, maxm=1;
	while(idx<n)
	{
		if(str[idx] == str[idx-1])
			sz++;
		else
		{
			maxm = max(maxm,sz);
			if(maxm >= ans)
				return MOD;
			sz=1;
		}
		idx++;
	}
	maxm = max(maxm,sz);
	return maxm;
}

void solve(string str, int idx, int k, int n, int &ans)
{
	if(k==0 || idx==n)
	{
		ans = min(ans, minLength(str,n,ans));
		return;
	}
	if(minLength(str,idx,ans) < ans)
		solve(str,idx+1,k,n,ans);
	str[idx] = str[idx] ^ 1;
	if(minLength(str,idx,ans) < ans)
		solve(str,idx+1,k-1,n,ans);
}

int main()
{
	cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n,k,ans=MOD,minm=MOD,temp=0,idx=1,sz=1;
		scanf("%d %d", &n, &k);
		char str_[lmt];
		scanf("%s", str_);
		string str = str_;
		FOR(i,0,n-1)
			temp = temp + (str[i] == '0'+ i%2);
		minm = min(minm, temp);
		temp = 0;
		FOR(i,0,n-1)
			temp = temp + (str[i] == '0'+ (i+1)%2);
		minm = min(minm, temp);
		//printf("%d\n", minm);
		if(k>=minm)
		{
			printf("1\n");
			continue;
		}
		priority_queue<int> q;
		while(idx<n)
		{
			if(str[idx] == str[idx-1])
				sz++;
			else
			{
				q.push(sz);
				sz=1;
			}
			idx++;
		}
		q.push(sz);
		int k_ = k;
		while(k_>0)
		{
			int temp = q.top();
			if(temp <=2)
			    break;
			q.pop();
			q.push(temp/2); q.push((temp-1)/2);
			k_--;
		}
		ans = q.top();

		solve(str,0,k,n,ans);
		printf("%d\n", ans);
	}

}
