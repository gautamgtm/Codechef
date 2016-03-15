//PRGIFT
#include <iostream>
#include <cstdio>
using namespace std;


int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n,k;
		scanf("%d %d", &n, &k);
		int A[n], numEven = 0;
		for(int i=0; i<n;i++)
		{
			scanf("%d", &A[i]);
			if(A[i]%2 == 0)
				numEven++;
		}

		if(numEven >= k && k>0)
			printf("YES\n");
		else if(k == 0 && numEven < n)
			printf("YES\n");
		else
			printf("NO\n");

	}
}