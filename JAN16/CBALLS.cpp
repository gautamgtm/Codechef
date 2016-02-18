//CBALLS
#include <iostream>
#include <cstdio>
using namespace std;
typedef unsigned long int ll;
ll MAX = 10000;
bool isPrime[10000];
 
void sieve()
{
	//Init
	for(ll i=0; i<MAX; i++)
	{
		isPrime[i] = 1;
	}
	//Sieve
	isPrime[0] = 0; isPrime[1] = 0;
	//Multiples of 2
	for(ll i = 4; i<=MAX; i+=2) 
	{
		isPrime[i]=0;
	}
	//Rest
	for(ll i = 3; i<=MAX; i+=2)
	{
		if(isPrime[i])
		{
			for(ll j = 2*i; j<=MAX; j += i)
			{
				isPrime[j]=0;
			}
		}
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
		scanf("%ld", &n);
		ll A[n];
		for(ll i=0; i<n; i++)
		{
			scanf("%ld", &A[i]);
		}
 
		ll answer1 = 0, countOdd = 0;
		if(A[0]%2) countOdd++;
		//Step 1 : Make Array Non decreasing
		for(ll i = 1;i<n;i++)
		{
			if(A[i] < A[i-1])
			{
				answer1 += (A[i-1] - A[i]);
				A[i] = A[i-1];
			}
			if(A[i]%2) countOdd++;
		}
		//Step 2 : GCD > 1
		ll answer2 = countOdd; //Case when GCD=2 is optimal soln
 
		for(ll i=3; i<=A[n-1]; i += 2)
		{
			if(isPrime[i])
			{
				ll temp = 0;
				for(ll j=0; j<n;j++)
				{
					if(A[j]%i)
					{
						temp += ( i - (A[j]%i) );
					}
				}
				if(temp < answer2) answer2 = temp;
			}
		}
 
		printf("%ld\n", answer1+answer2);
 
	}
} 
