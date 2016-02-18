//CHEFST
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef unsigned long long int ll;
 
ll min(ll a, ll b, ll c)
{
	ll minm = a;
	if (b<minm) minm = b;
	if (c<minm) minm = c;
 
	return minm;
}
 
int main()
{
	int t;
	scanf("%d", &t);
 
	while (t--)
	{
		ll n1,n2,m,maxRemove,lowest,rem;
		scanf("%Ld %Ld %Ld", &n1, &n2, &m);
 
		lowest = n1; 
		if (n2 < lowest) lowest = n2;
 
		maxRemove = m*(m+1)/2;
 
		if (maxRemove >= lowest) 
		{
			rem = lowest;
		}
		else rem = maxRemove;
 
 
 
 
 
/*		maxRemove = min(n1,n2,m);
		rem = 0;
		while (maxRemove > 0 && (rem+maxRemove) <= lowest)
		{
			rem += maxRemove;
			maxRemove--;
		}
		if(maxRemove != 0) rem = lowest;
*/
		n1 = n1-rem; n2 = n2-rem;
		/*while (n1!=0 && n2!=0 && maxRemove!=0)
		{
			int sub = min(n1,n2,maxRemove);
			n1 = n1-sub;
			n2 = n2-sub;
			maxRemove = maxRemove-1;
		}*/
 
		printf("%Ld\n", n1+n2);
	}
	
 
} 
