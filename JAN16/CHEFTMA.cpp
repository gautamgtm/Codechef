//CHEFTMA
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
typedef unsigned long int ll;
 
int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		ll n,k,m;
		scanf("%ld %ld %ld", &n, &k, &m);
		ll A[n],B[n],C[k],D[m],Rem[n], Bucket[k+m];
		for(ll i=0; i<n; i++)
		{
			scanf("%ld", &A[i]);
		}
		for(ll i=0; i<n; i++)
		{
			scanf("%ld", &B[i]);
		}
		for(ll i=0; i<k; i++)
		{
			scanf("%ld", &C[i]);
			Bucket[i] = C[i];
		}
		for(ll i=0; i<m; i++)
		{
			scanf("%ld", &D[i]);
			Bucket[k+i] = D[i];
		}
		for(ll i=0; i<n; i++)
		{
			Rem[i] = A[i] - B[i];
		}
 
		//Solution
		//sort(Rem.begin(),Rem.end());
		sort(Rem, Rem+n);
		reverse(Rem, Rem+n);
		sort(Bucket, Bucket+k+m);
		reverse(Bucket, Bucket+k+m);
 
		ll idx = 0;
		for(ll i=0; i<n; i++)
		{	
			while(Bucket[idx] > Rem[i] && idx <(k+m) )
			{
				idx++;
			}
 
			if(idx <(k+m) )
			{
				Rem[i] -= Bucket[idx]; idx++;
			}
			else
			{
				break;
			} 
		}
 
		ll answer = 0;
		for(ll i=0; i<n; i++)
		{
			answer += Rem[i];
		}
		printf("%ld\n", answer);
	}
} 
