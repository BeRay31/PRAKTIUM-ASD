#include <stdio.h>
#include "array.h"
/*Nama 		= Reyvan Rizky Irsandy
  NIM		= 13518136
  Tanggal	= 5 09 2019 */
int main()
{
	TabInt T;
	int X,idxmed;
	int jumX = 0;
	boolean sorted;
	BacaIsi(&T);//baca isi
	scanf("%d",&X);//membaca X
	TulisIsiTab(T);//tulis arr
	printf("\n");
	for (int i =1;i<=Neff(T);i++) //mencari berapa banyakX
	{
		if(TI(T)[i] == X)
		{
			jumX++;
		}
	}
	printf("%d\n",jumX);//print banyaknya X
	sorted = true;

	if(jumX>0 && sorted)
		{
			if(Neff(T)%2==0)
		{
			idxmed = Neff(T)/2;
		}
		else
		{
			idxmed =(Neff(T)/2)+1;
		}
		printf("%d\n",Search1(T,X));//print index X pertama kali muncul
		InsSortAsc(&T);
		if(TI(T)[Neff(T)]==X)
		{
			printf("maksimum\n");
		}
		if(TI(T)[IdxMin]==X)
		{
			printf("minimum\n");
		}
		if(TI(T)[idxmed]==X)
		{
			printf("median\n");
		}



	}
	else
	{
		printf("%d tidak ada\n",X);
	}

	return 0;
}
