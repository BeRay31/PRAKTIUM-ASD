#include <stdio.h>
#include "array.h"
int main()
{
    TabInt T;
    MakeEmpty(&T);
    TI(T)[2,1,4,3,1,23,12,32];
    printf("%d\n",NbElmt(T));
    printf("%d\n",MaxNbEl(T));
    printf("%d\n",GetFirstIdx(T));
    printf("%d\n",GetLastIdx(T));
    return 0;
}