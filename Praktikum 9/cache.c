/*
NAMA 		: Reyvan Rizky Irsandy
NIM			: 13518136
*/

#include <stdio.h>
#include "listlinier.h"
#include <stdlib.h>
int main()
{
	List C;
	address Elmt,Loc,prec,del,P;
	int N,X,OP;
	N = 0;
	X = 0;
	scanf("%d",&N);
	CreateEmpty (&C);
	for (int i =1 ; i<=N;i++)
	{
		P = Alokasi(i);
		if (P != Nil)
		{
			InsertLast(&C,P);
		}
	}
	scanf("%d",&OP);
	for (int i =1 ; i<= OP ;i++)
	{
		scanf("%d",&X);
		Loc = Search(C,X);
		if (Loc != Nil)
		{
			DelP (&C,X);
			InsVFirst(&C,X);
			printf("hit ");
			PrintInfo(C);
			printf("\n");
		}
		else
		{
			InsVFirst(&C,X);
			DelLast(&C,&del);
			printf("miss ");
			PrintInfo(C);
			printf("\n");
		}
	}
	return 0;
}