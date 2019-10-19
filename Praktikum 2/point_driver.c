#include <stdio.h>
#include "boolean.h"
#include "point.h"
int main()
{
    //testmakepoint
    int a,b;
    scanf("%d %d",&a,&b);
    POINT c;
    c = MakePOINT(a,b);
    //test baca
    POINT d;
    BacaPOINT(&d);
    //tulispoint
    TulisPOINT(c);
    TulisPOINT(d);
    //test eq
    printf("%d\n",EQ(c,d));
    //test neq
    printf("%d\n",NEQ(c,d));
    //testISorigin
    printf("%d\n",IsOrigin(d));
    //testIsonsby & x
    printf("%d\n",IsOnSbX(c));
    printf("%d\n",IsOnSbY(d));
    //test kkuadran
    POINT f;
    f = MakePOINT(4,-6);
    printf("%d\n",Kuadran(f));
    //test next
    printf("\n");
    TulisPOINT(NextX(f));
    printf("\n");
    TulisPOINT(NextY(f));
    printf("\n");
    TulisPOINT(PlusDelta(f,4,-8));
    printf("\n");
    //mirror of
    TulisPOINT(MirrorOf(f,true));
    printf("\n");
    //jarak0
    printf("%f\n",Jarak0(c));
    //panjang
    printf("%f\n",Panjang(c,d));
    //geser
    Geser(&f,-8,-9);
    printf("\n");
    TulisPOINT(f);
    printf("\n");
    //geserkesbx
    GeserKeSbX(&c);
    printf("\n");
    TulisPOINT(c);
    printf("\n");
    //GeserkeSBy
    GeserKeSbY(&d);
    printf("\n");
    TulisPOINT(d);
    printf("\n");
    //mirror
    Mirror(&f,IsOnSbX(f));
    TulisPOINT(f);
    printf("\n");
    //putar
    Putar(&f,90);
    printf("\n");
    TulisPOINT(f); 
    return 0;
}