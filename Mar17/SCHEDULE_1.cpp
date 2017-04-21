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

int getflips(int l, int r)
{
	int ans = ceil((double)(l-r)/(double)(r+1));
	return ans;
}

int main()
{
	cin.sync_with_stdio(0);
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,ans=MOD,idx=1,sz=1,temp=0,minm=MOD;
		cin>>n>>k;
		string str;
		cin>>str;

		FOR(i,0,n-1)
			temp = temp + (str[i] == '0'+ i%2);
		minm = min(minm, temp);
		temp = 0;
		FOR(i,0,n-1)
			temp = temp + (str[i] == '0'+ (i+1)%2);
		minm = min(minm, temp);
		//cout<<minm<<endl;
		if(k>=minm)
		{
			printf("1\n");
			continue;
		}

		VI vec;
		while(idx<n)
		{
			if(str[idx] == str[idx-1])
				sz++;
			else
			{
				if(sz>1)
					vec.PB(sz);
				sz=1;
			}
			idx++;
		}
		if(sz>1)
			vec.PB(sz);
		sort(vec.begin(), vec.end());
		reverse(vec.begin(), vec.end());

		if(k==0)
		{
			printf("%d\n", vec[0]);
			continue;
		}
		vector<PII> myVec;
		idx=0;sz=1;
		while(idx<vec.size()-1)
		{
			if(vec[idx] == vec[idx+1])
				sz++;
			else
			{
				myVec.PB(MP(vec[idx],sz));
				sz=1;
			}
			idx++;
		}
		myVec.PB(MP(vec[idx],sz));

		int start=0, end=myVec.size()-1;
		while(start<=end)
		{
			int mid = (start+end)/2, flips=0;
			FOR(i,0,mid-1)
				flips += myVec[i].second * getflips(myVec[i].first, myVec[mid].first);
			printf("%d %d\n", flips, myVec[mid].first);
			if(flips <= k)
			{
				if(ans > myVec[mid].first)
				{
					ans = myVec[mid].first;
					idx = mid;
				}
				start = mid + 1;
			}
			else
				end = mid - 1;
		}

		start = myVec[idx].first, end = 2;
		if(idx != myVec.size()-1)
			end = myVec[idx + 1].first;
		while(start<=end)
		{
			int mid = (start+end)/2, flips=0;
			FOR(i,0,idx)
				flips += myVec[i].second * getflips(myVec[i].first, mid);
			if(flips <= k)
			{
				ans = min(ans, mid);
				start = mid + 1;
			}
			else
				end = mid - 1;
		}

		printf("%d\n", ans);
	}

}
