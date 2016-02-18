//PLANEDIV
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <set>
using namespace std;
typedef long int ll;
 
int main()
{
	ll t;
	scanf("%ld", &t);
	while(t--)
	{
		ll N;
		scanf("%ld", &N);
		map <double, set<double> > numParallel; //contains distinct slopes and their lines count
 
		for (ll n=0; n<N; n++)
		{
			//Take Input
			ll a,b,c;
			scanf("%ld %ld %ld", &a, &b, &c);
			double s,r;
			if (b!=0)
			{
				s = double(a)/double(b); //Slope != Infinite
				r = double(c)/double(b);
			}
			else
			{
				s = 1000000000007;
				r = double(c)/double(a);  //Slope = Infinite 
			}
 
			map <double, set<double> >::iterator it = numParallel.find(s);
			if( it == numParallel.end()) //Slope Not Found
			{
				set<double> mySet;
				mySet.insert(r);
				numParallel.insert(pair<double, set<double> >(s, mySet));				
			}
			else
			{
				numParallel[s].insert(r);
			}
 
		}
		//find the largest value of key
		ll maxNum = 0;
		for (map<double, set<double> >::iterator it=numParallel.begin(); it!= numParallel.end(); it++ )
		{
			//printf("%ld ", it->second);
			if( (it->second.size()) > maxNum) maxNum = (it->second.size());
		}
		printf("%ld\n", maxNum);
 
	}
} 
