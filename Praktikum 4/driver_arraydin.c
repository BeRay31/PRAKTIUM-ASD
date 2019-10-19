#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"



int main ()
{
    TabInt T ;
    TI(T)[1]= 23;
    TI(T)[3] = 34;
    TI(T)[2] =32;
    TI(T)[4] = 12;
    TI(T)[5]= 21;
    TI(T)[6]=44;
    printf("baca isi kelar\n");
    Sort(&T,true);
    TulisIsiTab(T);
    return 0;
}