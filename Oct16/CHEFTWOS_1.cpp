//CHEFTWOS
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

LL powerTwo(int n)
{
	LL ans = 1;
	FOR(i,0,n-1)
		ans = (ans * 2)%MOD;
	return ans;
}

void swapChar(string a, string b, int idx)
{
	a[idx] = a[idx] + b[idx];
	b[idx] = a[idx] - b[idx];
	a[idx] -= b[idx];
}

bool isGood(string A)
{
	int i = 0, n = A.size();
	while(i < n-1)
	{
		if(A[i] == '2')
		{
			if(!(i<n-3 && A[i+1] == '2' && A[i+2] == '1'))
				return false;
			i += 3;
		}
		else
			i++;
	}
	return true;
}

int countPairs(string a, string b)
{
	int temp = 0, idx = 0, n = a.size();
	while(idx < n-1)
	{
		if(a[idx]=='1' && b[idx]=='1')
		{
			temp++;idx++;
		}
		else
		if(a[idx] == '2')
		{
			if(idx<n-3 && a[idx+1]=='2' && a[idx+2]=='1')
			{
				if((b[idx]=='2' && b[idx+1]=='2' && b[idx+2]=='1') || (b[idx]=='1' && b[idx+1]=='1' && b[idx+2]=='1'))
					temp += 1;
			}
			idx += 1;
		}
		else
		if(b[idx] == '2')
		{
			if(idx<n-3 && b[idx+1]=='2' && b[idx+2]=='1')
			{
				if((a[idx]=='2' && a[idx+1]=='2' && a[idx+2]=='1') || (a[idx]=='1' && a[idx+1]=='1' && a[idx+2]=='1'))
					temp += 1;
			}
			idx += 1;
		}
	}
	return temp;
}

bool makeGood(string a, string b)
{
	int cnt1=0, cnt2=0, n=a.size();
	FOR(i,0,n-2)
	{
		if(a[i]=='2')
			cnt1++;
		if(b[i]=='2')
			cnt2++;
	}
	if((cnt1+cnt2)%2)
		return false;

	int idx=0;
	while(idx < n-1)
	{
		if(a[idx]=='1' && b[idx]=='1')
			idx++;
		else
		if(a[idx]=='2')
		{
			if(b[idx]=='2')
			{
				if(idx<n-3 && (a[idx+1]=='2' && a[idx+2]=='1') && (b[idx+1]=='2' && b[idx+2]=='1'))
					idx += 3;
				else
					return false;
			}
			else
			{
				if(idx<n-3 && a[idx+1]=='2'&& a[idx+2]=='1')
				{
					if((b[idx+1]=='1' && b[idx+2]=='1'))
						idx += 3;
					else
					if()
				}
				else
				if(idx<n-4 && a[idx+1]=='2' && a[idx+2]=='2' && a[idx+3]=='1')
				{
					if(b[idx+1]=='2' && b[idx+2]=='1')
					{
						swapChar(a,b,idx);
						idx += 3;
					}
					else
						return false;
				}
				else
					return false;
			}
		}
		else
		if(b[idx]=='2')
		{
			if(a[idx]=='2')
			{
				if(idx<n-3 && (b[idx+1]=='2' && b[idx+2]=='1') && (a[idx+1]=='2' && a[idx+2]=='1'))
					idx += 3;
				else
					return false;
			}
			else
			{
				if(idx<n-3 && b[idx+1]=='2'&& b[idx+2]=='1')
				{
					if(!(a[idx+1]=='1' && a[idx+2]=='1'))
						return false;
					else
						idx += 3;
				}
				else
				if(idx<n-4 && b[idx+1]=='2' && b[idx+2]=='2' && b[idx+3]=='1')
				{
					if(a[idx+1]=='2' && a[idx+2]=='1')
					{
						swapChar(a,b,idx);
						idx += 3;
					}
					else
						return false;
				}
				else
					return false;
			}
		}
	}
	return true;
}

int main()
{
	//cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	while(t--)
	{
		string a,b;
		cin>>a>>b;

		bool isPossible = true;
		//Make both good first
		if(!(isGood(a) && isGood(b)))
			isPossible = makeGood(a,b);

		if(!isPossible)
		{
			printf("0\n");
			continue;
		}
		int count = countPairs(a,b);
		LL ans = powerTwo(count+1);
		printf("%d\n", ans);
	}

}
