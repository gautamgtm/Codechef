//SEATSTR2
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
#define lmt 100000

int fact[lmt+5], invFact[lmt+5];

LL degree(LL a, LL x) 
{
    //calculates a^x mod p in logarithmic time.
    LL res = 1;
    while(x > 0) {
        if( x % 2 != 0) {
            res = (res * a) % MOD;
        }
        a = (a * a) % MOD;
        x /= 2;
    }
    return res;
}

LL modInverse(LL a, LL p) 
{
    //calculates the modular multiplicative of a mod m.
    //(assuming p is prime).
    return degree(a, p-2);
}

void sieve()
{
	fact[0]=1; fact[1]=1;
	FOR(i,2,lmt+4)
	{
		LL temp = ( (LL)fact[i-1] * (LL)i )%MOD;
		fact[i] = temp;
	}

	invFact[0]=0; invFact[1]=1;
	FOR(i,2,lmt+4)
	{
		LL temp = ( (LL)invFact[i-1] * (LL)modInverse(i, MOD) )%MOD;
		invFact[i] = temp;
	}
}

void combinationUtil(int arr[], int data[], int start, int end, int index, int r, LL &sum)
{
    if (index == r)
    {
    	LL temp = data[0];
        for (int j=1; j<r; j++)
        	temp = (temp * (LL)data[j] )%MOD;
        sum = (sum + temp)%MOD;
        if(r == 2)
        {
        	LL comb = (((LL)data[0]*(LL)(data[0]-1)/2)%MOD*((LL)data[1]*(LL)(data[1]-1)/2)%MOD)%MOD; 
        	sum = (sum + comb)%MOD;
        }
        if(r == 3)
        {
        	LL comb = (((LL)data[0]*(LL)(data[0]-1)/2)%MOD*((LL)data[1]*(LL)data[2])%MOD)%MOD; 
        	comb = (comb + (((LL)data[1]*(LL)(data[1]-1)/2)%MOD*((LL)data[0]*(LL)data[2])%MOD)%MOD)%MOD;
        	comb = (comb + (((LL)data[2]*(LL)(data[2]-1)/2)%MOD*((LL)data[0]*(LL)data[1])%MOD)%MOD)%MOD;
        	sum = (sum + comb)%MOD;
        }
        return;
    }
 
    for (int i=start; i<=end && end-i+1 >= r-index; i++)
    {
        data[index] = arr[i];
        combinationUtil(arr, data, i+1, end, index+1, r, sum);
    }
}

int main()
{
	cin.sync_with_stdio(0);
	sieve();
	int t;
	scanf("%d", &t);
	while(t--)
	{
		char str[lmt+5];
		scanf("%s", str);
		int count[26]={}, n=strlen(str);
		FOR(i,0,n-1)
		{
			count[str[i]-97]++;
		}

		sort(count, count+26);
		reverse(count, count+26);

		int k=0;
		FOR(i,0,25)
		{
			if(count[i])
				k++;
			else
				break;
		}

		//Ans = n! *(n! - (1 + nC2 + 2* nC3 + 3* nC4))

		//Calculate n!
		LL total = fact[n]%MOD;
		FOR(i,0,k-1)
		{
			total = ( total * (LL)invFact[count[i]] )%MOD;
		}

		LL count2=0, count3=0, count4=0;

		int data[4];
		combinationUtil(count, data, 0, k-1, 0, 2, count2);
		combinationUtil(count, data, 0, k-1, 0, 3, count3);
		combinationUtil(count, data, 0, k-1, 0, 4, count4);

		LL temp = (total%MOD - (1 + count2 + 2*count3 + 3*count4)%MOD )%MOD;
		if(temp < 0)
			temp += MOD;
		LL answer = (total%MOD * temp%MOD )%MOD;
		//LL answer = (total%MOD * (total%MOD - (1 + count2 + 2*count3 + 3*count4)%MOD )%MOD )%MOD;
		//printf("%Ld %Ld %Ld %Ld %Ld %d\n", answer, total, count2, count3, count4, k);
		printf("%Ld\n", answer);
	}

}