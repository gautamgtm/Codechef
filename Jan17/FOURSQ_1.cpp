//FOURSQ
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
#define PII pair <long long int, long long int>
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
#define lmt 1000005

LL squareNum[lmt];

struct CmpPair
{
    bool operator()(const pair<LL,PII>& a, const pair<LL,PII>& b)
    { return a.first < b.first; }
};

void sieve()
{
	FOR(i,0,lmt-1)
		squareNum[i] = i*i;
}

LL multiply(LL a, LL b, LL p)
{
	return ((a%p)*(b%p))%p;
}

void buildTree(LL A[], LL tree[], LL node, LL a, LL b, LL p)
{
	if(a>b)
		return;
	if(a==b)
	{
		tree[node] = A[a];
		return;
	}

	buildTree(A,tree,2*node,a,(a+b)/2,p);
	buildTree(A,tree,2*node+1,1+(a+b)/2,b,p);

	tree[node] = multiply(tree[2*node],tree[2*node+1],p);
}

void updateTree(LL A[], LL tree[], LL node, LL a, LL b, LL idx, LL value, LL p)
{
	if(a > b || a > idx || b < idx)
		return;

	if(a == b)
	{
		tree[node] = value;
		return;
	}

	updateTree(A,tree,2*node,a,(a+b)/2,idx,value,p);
	updateTree(A,tree,2*node+1,1+(a+b)/2,b,idx,value,p);

	tree[node] = multiply(tree[2*node],tree[2*node+1],p);
}

LL queryTree(LL A[], LL tree[], LL node, LL a, LL b, LL i, LL j, LL p)
{
	if(a > b || a > j || b < i) return 1;

	if(a>=i && b<=j)
		return tree[node];

	LL q1 = queryTree(A,tree,2*node,a,(a+b)/2,i,j,p);
	LL q2 = queryTree(A,tree,2*node+1,1+(a+b)/2,b,i,j,p);

	return multiply(q1,q2,p);
}

map<LL, PII> twoSquaresLessN(LL num)
{
	map<LL, PII> myVector;
	LL numRoot = (LL)sqrt((double)num);
	FORD(i,numRoot,0)
	{
		FOR(j,0,i)
		{
			LL sum = squareNum[i] + squareNum[j];
			if(sum > num)
				break;
			else
				myVector.insert(MP(sum,MP(i,j)));
		}
	}
	return myVector;
}

void fourSquare(LL num)
{
  LL numRoot = (LL)sqrt((double)num);
	map<LL, PII> sumTwoSquares = twoSquaresLessN(num);

	auto low=sumTwoSquares.begin();
  auto high=sumTwoSquares.rbegin();
	while(high->first != low->first)
	{
		if(high->first + low->first == num)
		{
			//Numbers found
			printf("%Ld %Ld %Ld %Ld\n", (high->second).first, (high->second).second, (low->second).first, (low->second).second);
			return;
		}
		else
		if(high->first + low->first < num)
			low++;
		else
			high++;
	}

}

int main()
{
	cin.sync_with_stdio(0);
	LL t;
	scanf("%Ld", &t);
	sieve();
	while(t--)
	{
		LL n,q,p;
		scanf("%Ld %Ld %Ld", &n, &q, &p);
		LL A[n];
		FOR(i,0,n-1)
			scanf("%Ld", &A[i]);

		LL tree[4*n];
		FOR(i,0,4*n-1)
			tree[i] = 1;
		buildTree(A,tree,1,0,n-1,p);

		FOR(i,0,q-1)
		{
			LL a,b,c;
			scanf("%Ld %Ld %Ld", &a, &b, &c);

			if(a==1)
				updateTree(A,tree,1,0,n-1,b-1,c,p);
			else
			{
				//Output 4 reqd numbers
				LL prod = queryTree(A,tree,1,0,n-1,b-1,c-1,p);
				//printf("%Ld\n", prod);
				fourSquare(prod);
			}
		}
	}

}
