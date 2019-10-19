#include <stdio.h>
#include "jam.h"
/*  Nama     :  Reyvan Rizky Irsandy
    NIM      :  13518136
    Tanggal  :  02 09 2019
    Topik    :  Merecord lama waktu telpon */

int main()
{
	JAM a,b,c,d;
	c = MakeJAM(0,0,0);
	d = MakeJAM(23,59,59);
	long deta,detb;
	int N;
	scanf("%d",&N);
	for(int i =1;i<=N;i++)
	{
		printf("[%d]\n",i);
		BacaJAM(&a);
		BacaJAM(&b);
		deta = JAMToDetik(a);
		detb = JAMToDetik(b);
		if (deta>detb) 
		{
			 printf("%d\n",deta-detb);
			 if(deta>JAMToDetik(c)) c=a;
			 if(detb<JAMToDetik(d)) d=b;
		}
		else 
		{
			printf("%d\n",detb-deta);
			 if(detb>JAMToDetik(c)) c=b;
			 if(deta<JAMToDetik(d)) d=a;
		}
	}
	TulisJAM(d);
	printf("\n");
	TulisJAM(c);
	printf("\n");
}
