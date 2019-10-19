
#include <stdio.h>
#include "arraydin.h"
#include <stdlib.h>
/*Nama    : Reyvan Rizky Irsandy
NIM     : 13518136
Tanggal : 12 09 2019*/
int main()
{
	TabInt T;
	int maxel,op,Q,num;
	scanf("%d",&maxel);
	MakeEmpty(&T,maxel);
	BacaIsi(&T);
	scanf("%d",&Q);
	for (int i =1;i<=Q;i++)
	{
		scanf("%d",&op);
		switch(op)
		{
			case 1 :
			{
				scanf("%d",&num);
				if(IsFull(T))
				{
					printf("array sudah penuh\n");
				}
				else
				{
					AddAsLastEl(&T,num);
					printf("%d ",MaxEl(T));
					TulisIsiTab(T);
					printf("\n");
				}
				break;
			}
			case 2 :
			{
				scanf("%d",&num);
				GrowTab(&T,num);
				printf("%d ",MaxEl(T));
				TulisIsiTab(T);
				printf("\n");
				break;
			}
			case 3 :
			{
				scanf("%d",&num);
				if(MaxEl(T)<num)
				{
					printf("array terlalu kecil\n");
				}
				else
				{
					ShrinkTab(&T,num);
					printf("%d ",MaxEl(T));
					TulisIsiTab(T);
					printf("\n");					
				}
				break;
			}
			case 4 :
			{
				CompactTab(&T);
				printf("%d ",MaxEl(T));
				TulisIsiTab(T);
				printf("\n");
				break;
			}
		}
	}
	
	
	return 0;
}
