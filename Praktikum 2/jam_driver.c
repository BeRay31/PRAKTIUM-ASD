#include <stdio.h>
#include "jam.h"
#include "boolean.h"
/*  Nama     :  Reyvan Rizky Irsandy
    NIM      :  13518136
    Tanggal  :  29 08 2019
    Topik    :  jam.h */
int main()
{
    //test IsJamValid
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    printf("%d\n",IsJAMValid(a,b,c));
    //Test MakeJam
    JAM jamtest;
    jamtest = MakeJAM(a,b,c);
    //Test BacaJAM
    JAM jamtest2;
    BacaJAM(&jamtest2);
    //test TulisJam
    TulisJAM(jamtest);
    printf("\n");
    TulisJAM(jamtest2);
    printf("\n");
    //test JamToDetik
    printf("%d\n",JAMToDetik(jamtest));
    //test detiktojam
    long d;
    JAM e;
    scanf("%d",&d);
    e = DetikToJAM(d);
    TulisJAM(e);
    printf("\n");
    //test JEQ
    printf("%d\n",JEQ(jamtest2,jamtest));
    //testJNEQ
    printf("%d\n",JNEQ(jamtest2,jamtest));
    //testJLET
    printf("%d\n",JLT(jamtest2,jamtest));
    //testJGT
    printf("%d\n",JGT(jamtest2,jamtest));
    //testNextDetik
    TulisJAM(NextDetik(jamtest));
    printf("\n");
    //testNextNdetik
    TulisJAM(NextNDetik(jamtest,30));
    printf("\n");;
    //test prevDetik
    TulisJAM(PrevDetik(jamtest));
    printf("\n");
    //testPrevNDtik
    TulisJAM(PrevNDetik(jamtest,60));
    printf("\n");
    //testDurasi
    printf("%d",Durasi(jamtest,jamtest2));
    printf("\n");
    
    return 0 ;
}
