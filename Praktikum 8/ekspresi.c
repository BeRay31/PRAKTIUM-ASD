/*
Nama	 : Reyvan Rizky Irsandy
NIM 	 : 13518136
Tgl 	 : 17 10 2019
*/
#include "stackt.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mesintoken.h"
int main()
{
	Stack S1;
	CreateEmpty(&S1);
	int opr1,opr2,vale,hasil;
	opr1 =0;
	opr2 =0;
	vale = 0;
	hasil =0;
	STARTTOKEN();
	if (EndToken)
	{
		printf("Ekspresi kosong\n");
	}
	while (!EndToken)
	{
		
		if(CToken.tkn == 'b')
		{
			Push(&S1,CToken.val);
			printf("%d\n",CToken.val);
		}
		else
		{
			Pop(&S1,&opr2);
			Pop(&S1,&opr1);
			printf("%d %c %d\n",opr1,CToken.tkn,opr2);
			if (CToken.tkn == '+')
			{
				vale = opr1 + opr2;
			}
			else if (CToken.tkn == '-')
			{
				vale = opr1 - opr2;
			}
			else if (CToken.tkn == '*')
			{
				vale = opr1 * opr2;
			}
			else if (CToken.tkn == '/')
			{
				vale = opr1/ opr2;
			}
			else if (CToken.tkn == '^')
			{
				vale = pow(opr1,opr2);
			}
			Push(&S1,vale);
			printf("%d\n",vale);
		}
		ADVTOKEN();
	}
	if (!IsEmpty(S1))
	{
		Pop(&S1,&hasil);
		printf("Hasil=%d\n",hasil);
	}
	return 0;
}

