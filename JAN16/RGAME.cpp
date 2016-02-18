//RGAME
#include <iostream>
#include <cstdio>
using namespace std;
typedef unsigned long long int ll;
 
ll mod = 1000000007;
ll powTwo[100005];
void sieve()
{
	powTwo[0] = 1;
	for(ll i=1; i<100005;i++)
	{
		powTwo[i] = (powTwo[i-1]*2)%mod;
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	sieve();
	while(t--)
	{
		ll n;
		scanf("%Ld", &n);
		ll A[n+1], B[n+1]; // B[i] contains sum of 1st i+1 elements of A
		for(ll i=0;i<=n;i++)
		{
			scanf("%Ld ", &A[i]);
			if(i==0)
			{
				B[0] = 2*A[0];
			}
			else
			{
				B[i] = ( B[i-1] + ( powTwo[i]*A[i] )%mod )%mod;
			}
		}
 
		//Solution
		ll ans = 0;
		for(ll i=1; i<=n;i++)
		{
			ll add = (A[i]*B[i-1])%mod;
			add = (add*powTwo[n-i])%mod;
			ans = (ans+add)%mod;
		}
 
		printf("%Ld\n", ans);
 
	}
} 
