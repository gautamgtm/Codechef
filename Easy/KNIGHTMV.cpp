//KNIGHTMV
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	getchar();
	while(t--)
	{
		char move[101];
		gets(move);
		if(strlen(move)>5)
		{
			printf("Error\n");
			continue;
		}
		if(move[0]>= 'a' && move[0]<='h' && move[1]>='1' && move[1]<='8' && move[2] =='-')
		{
			int x1= move[0]-'a'; int y1=move[1]-'1';
			if(move[3]>= 'a' && move[3]<='h' && move[4]>='1' && move[4]<='8')
			{
				int x2= move[3]-'a'; int y2=move[4]-'1';

				if((abs(x1-x2)==2 && abs(y1-y2)==1) || (abs(x1-x2)==1 && abs(y1-y2)==2))
					printf("Yes\n");
				else
					printf("No\n");

			}
			else
			{
				printf("Error\n");
			}
		}
		else
		{
			printf("Error\n");
		}
	}

}