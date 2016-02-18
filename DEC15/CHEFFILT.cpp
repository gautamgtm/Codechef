//CHEFFILT
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>
using namespace std;
 
typedef long long int lld;
 
lld divider = 1000000007;
lld numFilter, numDistinctFilter, countFilter[1025], myArray[1025][1024], power[100005];
int filters[1025];
 
void powerTwo()
{
	power[0] = 1;
	for(lld i=1; i<100005; i++)
	{
		power[i] = (power[i-1]*2)%divider;
	}
}
 
lld solve(lld row, int result)
{
	int y = result^(filters[row]);
	
	if (myArray[row+1][result] == -1)
	{
		myArray[row+1][result] = solve(row+1,result)%divider;
	}
 
	if (myArray[row+1][y] == -1)
	{
		myArray[row+1][y] = solve(row+1,y)%divider;
	}
 
	myArray[row][result] = (myArray[row+1][result] + myArray[row+1][y])%divider;
 
	return myArray[row][result];
}
 
int main()
{
	int t;
	scanf("%d", &t);
	powerTwo();
	while(t--)
	{
		char image[11];
		scanf("%s", image);
		for (int i=0; i<10; i++)
		{
			if(image[i] == 'w') image[i]='1';
			else image[i] = '0';
		}
		int pic = strtol(image, NULL,2); // image array represented in integer [sarray in binary]
 
		scanf("%Ld", &numFilter);
		//Initialize
		for (lld i =0; i<1025; i++)
		{
			countFilter[i] = 0;
			filters[i] = -1;
		}
		numDistinctFilter = 0;
 
		for(lld i=0; i<numFilter; i++)
		{
			char inputFilter[11];
			scanf("%s", inputFilter);
			for(int j=0; j<10; j++)
			{
				if(inputFilter[j] == '+') inputFilter[j] = '1';
				else inputFilter[j] = '0';
			}
			int inNumber = strtol(inputFilter, NULL, 2);
 
			if(countFilter[inNumber] == 0)
			{
				filters[numDistinctFilter] = inNumber;
				numDistinctFilter++;
			}
			countFilter[inNumber]++;	
		}
 
		//Efficient solution : DP
		//Initialize array with -1[Cell not calculated yet]
		lld mult = 1;
		for (lld i=0; i<numDistinctFilter; i++)
		{
			for (int j=0;j<1024;j++)
			{
				myArray[i][j] = -1;
			}
			if(countFilter[filters[i]] > 0)
			{
				mult = (mult * power[countFilter[filters[i]] - 1]) % divider;
			}			
		}
		//Last row with result 0 as 1; others as 0
		myArray[numDistinctFilter][0] = 1;
		for(lld i=1; i<1024; i++)
		{
			myArray[numDistinctFilter][i] = 0;
		}
 
		lld set = (solve(0, pic))%divider;
		set = (set*mult)%divider;
 
		printf("%Ld\n", set );
 
	}
 
} 
