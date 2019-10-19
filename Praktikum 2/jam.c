#include <stdio.h>
#include "boolean.h"
#include "jam.h"
/*  Nama     :  Reyvan Rizky Irsandy
    NIM      :  13518136
    Tanggal  :  29 08 2019
    Topik    :  jam.h */
boolean IsJAMValid (int H, int M, int S)
{
    /* Mengirim true  jika H,M,S dapat membentuk J yang valid */
    return (((H>=0)&&(H<24))&&((M>=0)&&(M<60))&&((S>=0)&&(S<60)));
}

JAM MakeJAM (int HH, int MM, int SS)
{
    if (IsJAMValid(HH,MM,SS))
    {
        /* Membentuk sebuah JAM dari komponen-komponennya yang valid */
        JAM J;
        J.HH = HH;
        J.MM = MM;
        J.SS = SS;
        return J;
    }
}


void BacaJAM (JAM * J)
{   int a,b,c;
    for(;;)
    {
        scanf("%d %d %d",&a,&b,&c);
        if (IsJAMValid(a,b,c))
        {
            break;
        }
        else {printf("Jam tidak valid\n");}
    }
    *J = MakeJAM(a,b,c);
    
}

void TulisJAM (JAM J)
{
    printf("%d:%d:%d",Hour(J),Minute(J),Second(J));
}

long JAMToDetik (JAM J)
{
    long detik;
    detik = (3600*Hour(J))+(60*Minute(J)+Second(J));
    return detik;
}

JAM DetikToJAM (long N)
{
    JAM J;
    if (N>=86400)
    {
        N = N%86400;
        Hour(J) = (N/3600);
        Minute(J) = (N%3600)/60;
        Second(J) = (N%3600)%60;
    }
    else
    {
        Hour(J) = (N/3600)%24;
        Minute(J) = (N/60)%60;
        Second(J) = N%60;
    }
    J = MakeJAM(Hour(J),Minute(J),Second(J));
    return J;
}

boolean JEQ (JAM J1, JAM J2)
{
    if (JAMToDetik(J1)==JAMToDetik(J2))
    {
    return (true);
    }
    else
    {
        return (false);
    }
}

boolean JNEQ (JAM J1, JAM J2)
{
    if (JAMToDetik(J1)!=JAMToDetik(J2))
    {
    return (true);
    }
    else
    {
        return (false);
    }
}
boolean JLT (JAM J1, JAM J2)
{
    if (JAMToDetik(J1)<JAMToDetik(J2))
    {
    return (true);
    }
    else
    {
        return (false);
    }   
}
boolean JGT (JAM J1, JAM J2)
{
    if (JAMToDetik(J1)>JAMToDetik(J2))
    {
    return (true);
    }
    else
    {
        return (false);
    }  
}
JAM NextDetik (JAM J)
{
    long detik;
    detik = JAMToDetik(J);
    detik +=1;
    J = DetikToJAM(detik);
    return J;
}
JAM NextNDetik (JAM J, int N)
{
    long detik;
    detik = JAMToDetik(J);
    detik +=N;
    J = DetikToJAM(detik);
    return J;  
}
JAM PrevDetik (JAM J)
{
    long detik;
    detik = JAMToDetik(J);
    detik -=1;
    J = DetikToJAM(detik);
    return J;     
}
JAM PrevNDetik (JAM J, int N)
{
    long detik;
    detik = JAMToDetik(J);
    detik -=N;
    J = DetikToJAM(detik);
    return J;     
}
long Durasi (JAM JAw, JAM JAkh)
{
    long det1,det2,selisih;
    det1 = JAMToDetik(JAw);
    det2 = JAMToDetik(JAkh);
    if (det1>det2)
    {
        selisih = 86400+ det2 - det1;
    }
    else
    {
        selisih = det2 - det1;
    }
    return selisih;
}