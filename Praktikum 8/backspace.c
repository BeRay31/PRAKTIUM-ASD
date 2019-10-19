/*
Nama	 : Reyvan Rizky Irsandy
NIM 	 : 13518136
Tgl 	 : 17 10 2019
*/
#include "stackt.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
	Stack S1,S2;
	int N,M,temp,erase,tempNum;
	int lengthS1,lengthS2;
	int numS1,numS2;
	scanf("%d %d",&N,&M);
	CreateEmpty(&S1);
	CreateEmpty(&S2);
	lengthS1 = 0;
	lengthS2 = 0;
	numS1 = 0;
	numS2 = 0;
	for (int i = 1;i<=N;i++)
	{
		scanf("%d",&temp);
		if (IsEmpty(S1))
		{
			if ( temp != 0)
			{
				Push(&S1,temp);
				lengthS1++;
			}
		}
		else 
		{
			if ( temp != 0)
			{
				Push(&S1,temp);
				lengthS1++;
			}
			else
			{
				Pop(&S1,&erase);
				lengthS1--;
			}
		}
	}//isi stack S1
	for (int i = 1;i<=M;i++)
	{
		scanf("%d",&temp);
		if (IsEmpty(S2))
		{
			if ( temp != 0)
			{
				Push(&S2,temp);
				lengthS2++;
			}
		}
		else 
		{
			if ( temp != 0)
			{
				Push(&S2,temp);
				lengthS2++;
			}
			else
			{
				Pop(&S2,&erase);
				lengthS2--;
			}
		}
	}//isi stack S2
	while (!(IsEmpty (S1)))
	{
		Pop(&S1,&tempNum);
		numS1 = numS1*10 + tempNum;
		
	}//numS1
	while (!(IsEmpty(S2)))
	{
		Pop(&S2,&tempNum);
		numS2 = numS2*10 + tempNum;
		
	}//numS2
	if(numS1==numS2)
	{
		printf("Sama\n");
	}
	else
	{
		printf("Tidak sama\n");
	}
	return 0;
}
