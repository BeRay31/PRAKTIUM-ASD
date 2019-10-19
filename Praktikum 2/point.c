#include <stdio.h>
#include "boolean.h"
#include "point.h"
#include <math.h>
/*  Nama     :  Reyvan Rizky Irsandy
    NIM      :  13518136
    Tanggal  :  29 08 2019
    Topik    :  point.h */
POINT MakePOINT (float X, float Y)
{
    POINT P;
    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}

void BacaPOINT (POINT * P)
{
    float a,b;
    scanf("%f %f",&a,&b);
    *P = MakePOINT(a,b);
}

void TulisPOINT (POINT P)
{
    printf("(%.2f,%.2f)",Absis(P),Ordinat(P));
}

boolean EQ (POINT P1, POINT P2)
{
    if ((Absis(P1)==Absis(P2))&&(Ordinat(P1)==Ordinat(P2)))
    {
        return true;
    }
    else return false;
}
boolean NEQ (POINT P1, POINT P2)
{
    if ((Absis(P1)!=Absis(P2))||(Ordinat(P1)!=Ordinat(P2)))
    {
        return true;
    }
    else return false;    
}
boolean IsOrigin (POINT P)
{
    if ((Absis(P)==0 )&&(Ordinat(P)==0)) return true;
    else return false;
}
boolean IsOnSbX (POINT P)
{
    if (Ordinat(P)==0) return true;
    else return false;    
}

boolean IsOnSbY (POINT P)
{
    if (Absis(P)==0) return true;
    else return false;   
}
int Kuadran (POINT P)
{
    int x;
    if(!IsOrigin(P))
    {
        if ((Absis(P)>0)&&(Ordinat(P)>0))
        {
            x =1;
        }
        else if ((Absis(P)<0)&&(Ordinat(P)>0))
        {
            x = 2;
        }
        else if ((Absis(P)<0)&&(Ordinat(P)<0))
        {
            x = 3;
        }
        else if((Absis(P)>0)&&(Ordinat(P)<0))
        {
            x = 4;
        }
    }    
    return x;    
}
POINT NextX (POINT P)
{
    P = MakePOINT(Absis(P)+=1,Ordinat(P));
    return P;
}
POINT NextY (POINT P)
{
    P=MakePOINT(Absis(P),Ordinat(P)+=1);
    return P;
}
POINT PlusDelta (POINT P, float deltaX, float deltaY)
{
    P = MakePOINT(
    Absis(P)+deltaX,
    Ordinat(P)+deltaY);
    return P;
}
POINT MirrorOf (POINT P, boolean SbX)
{
    if(SbX)
    {
        Ordinat(P)= (-1)*Ordinat(P);
    }
    else
    {
        Absis(P)= (-1)*Absis(P);
    }
    MakePOINT(Absis(P),Ordinat(P));
    return P;
}
float Jarak0 (POINT P)
{
    float a,b;
    a = Absis(P);
    b = Ordinat(P);
    return (sqrt((a*a)+(b*b)));
}
float Panjang (POINT P1, POINT P2)
{
    float a,b;
    a = Absis(P1)-Absis(P2);
    b = Ordinat(P1) - Ordinat(P2);
    return sqrt((a*a)+(b*b));
}
void Geser (POINT *P, float deltaX, float deltaY)
{
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}
void GeserKeSbX (POINT *P)
{
    Ordinat(*P) = 0;
}
void GeserKeSbY (POINT *P)
{
    Absis(*P) = 0;
}
void Mirror (POINT *P, boolean SbX)
{
    if(SbX)
    {
        Ordinat(*P)= (-1)*Ordinat(*P);
    }
    else
    {
        Absis(*P)= (-1)*Absis(*P);
    }    
}

void Putar (POINT *P, float Sudut)
{
    Sudut = (-1)*Sudut*3.14159265358979323846/180.00;
    float x = Absis(*P)*cos(Sudut) - Ordinat(*P)*(sin(Sudut));
    float y = Absis(*P)*sin(Sudut) + Ordinat(*P)*(cos(Sudut));
    *P = MakePOINT(x,y);
}