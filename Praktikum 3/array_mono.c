#include <stdio.h>
#include "array.h"
/*Nama 		= Reyvan Rizky Irsandy
  NIM		= 13518136
  Tanggal	= 5 09 2019 */
int main()
{
	boolean status,status2,status3;
	TabInt T;
	BacaIsi(&T);//baca isi
	for(int i =1;i<Neff(T);i++)
	{
			if(TI(T)[i]>TI(T)[i+1])
			{
				status = false;
				break;
			}
			else
			{
				status = true;
			}
		
	}

	for(int i =1;i<Neff(T);i++)
	{
			if(TI(T)[i]<TI(T)[i+1])
			{
				status2 = false;
				break;
			}
			else
			{
				status2 = true;
			}
	}
	for(int i =1;i<Neff(T);i++)
	{
			if(TI(T)[i]==TI(T)[i+1])
			{
				status3 = true;

			}
			else
			{
				status3 = false;
				break;
			}
		
	}
	if(status3){printf("Array monotonik statik\n");}
	else if(status){printf("Array monotonik tidak mengecil\n");}
	else if(status2){printf("Array monotonik tidak membesar\n");}
	else {printf("Array tidak monotonik\n");}

	return 0;
}
