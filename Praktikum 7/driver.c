#include "prioqueuechar.h"
#include <stdlib.h>
#include <stdio.h>
int main()
{
    PrioQueueChar Q;
    infotype X,Y;
    CreateEmpty (&Q,10);
    Head(Q) = 5;
    Tail(Q) = 1;
    Prio(Elmt(Q,5)) = 1;//head
    Info(Elmt(Q,5)) = 'b';
    Prio(Elmt(Q,6)) = 2;
    Info(Elmt(Q,6)) = 'c';
    Prio(Elmt(Q,7)) = 3;
    Info(Elmt(Q,7)) = 'd';
    Prio(Elmt(Q,8)) = 4;
    Info(Elmt(Q,8)) = 'e';
    Prio(Elmt(Q,9)) = 4;
    Info(Elmt(Q,9)) = 'a';
    Prio(Elmt(Q,10)) = 5;
    Info(Elmt(Q,10)) = 'z';
    Prio(Elmt(Q,1)) = 5;
    Info(Elmt(Q,1)) = 'u';//tail
    Prio(X) = 1;
    Info(X) = 'z';
    Add(&Q,X);
    printf("%d %d %d %d\n",Tail(Q),Head(Q),MaxEl(Q),NBElmt(Q));
    PrintPrioQueueChar(Q);
    return 0;
}