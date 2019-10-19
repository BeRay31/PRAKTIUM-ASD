#include "mesintoken.h"
#include <stdio.h>


int main()
{
    EndToken = false;
    STARTTOKEN();

    do
    {
    printf("%c,%d\n",CToken.tkn,CToken.val);
        ADVTOKEN();
    }while(EndToken !=true);    
}