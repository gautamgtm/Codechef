//NOLOGIC
#include <iostream>
#include <stdio.h>
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

int main()
{
	//cin.sync_with_stdio(0);
	int t;
	scanf("%d", &t);
	getchar();
	while(t--)
	{
		string ques;
		getline(cin, ques);
		bool isThere[26]={0};
		//cout<<ques.size()<<endl;
		FOR(i,0,ques.size()-1)
		{
			if(ques[i]>=65 && ques[i]<=90)
				isThere[ques[i]-65] = 1;
			else
			if(ques[i]>=97 && ques[i]<=122)
				isThere[ques[i]-97] = 1;
		}
	
		bool found=0;
		FOR(i,0,25)
		{
			if(isThere[i] == 0)
			{
				printf("%c\n", i+65);
				found = 1;
				break;
			}
				
		}
		if(!found)
			printf("~\n");
	}

}