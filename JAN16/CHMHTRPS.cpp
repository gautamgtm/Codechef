//CHMHTRPS
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <bitset>
#include <vector>
#include <utility>
#include <ctime>
using namespace std;
typedef long long int ll;
 
ll maxm = 1000000005;
 
int main()
{
	clock_t tStart = clock();
	ll n;
	scanf("%Ld", &n);
	vector< pair<ll, ll> > myVector;
	for(ll i=1; i<=3*n; i++)
	{
		ll temp;
		scanf("%Ld", &temp);
		myVector.push_back(make_pair(temp, i));
	}
 
	//Solution
	vector<ll> ans;
	sort(myVector.begin(), myVector.end());
	bool isUsed[3*n+1]={0};
	ll totalSum = (myVector[0].first+myVector[3*n-1].first)/2;
	double timeDiff=0;
	for(ll it=0; it<myVector.size()-2 && timeDiff <4.8; it++)
	{		
		if(isUsed[myVector[it].second] == 0) //If index not used yet
		{
			ll a = myVector[it].first;
			ll start = it+1;
			ll end = myVector.size()-1;
			while(start<end)
			{
				ll b = myVector[start].first;
				ll c = myVector[end].first;
				if(a+b+c == totalSum)
				{
					if(isUsed[myVector[it].second] == 0 && isUsed[myVector[start].second] == 0 && isUsed[myVector[end].second] == 0)
					{
						ans.push_back(myVector[it].second);
						ans.push_back(myVector[start].second);
						ans.push_back(myVector[end].second);
						isUsed[myVector[it].second] = 1;
						isUsed[myVector[start].second] = 1;
						isUsed[myVector[end].second] = 1;
					}		
					start += 1;
					end -= 1;
				}
				else if (a+b+c < 0)
				{
					start += 1;
				}
				else
				{
					end -= 1;
				}
			}
			timeDiff = (double)(clock() - tStart)/CLOCKS_PER_SEC;			
		}
	}
 
	if(ans.size())
	{
		cout<<ans.size()/3<<endl;
		for(ll i=0; i<ans.size(); i++)
		{
			printf("%Ld ", ans[i]);
		}		
	}
	else
	{
		cout<<"1"<<endl;
		printf("1 2 3");
	}
 
}
 
