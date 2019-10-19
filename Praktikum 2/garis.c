#include <stdio.h>
#include "garis.h"
#include <math.h>
void MakeGARIS (POINT P1, POINT P2, GARIS * L)
{
    GARIS G;
    G.PAw = P1;
    G.PAkh = P2;
    *L = G;
}
void BacaGARIS (GARIS * L)
{
    POINT c,d;
    GARIS a;
    c = MakePOINT(0,0);
    d = MakePOINT(0,0);
    do
    {
        BacaPOINT(&c);
        BacaPOINT(&d);
        if(c.X==d.X&&c.Y==d.Y) printf("Garis tidak valid\n");
    } while (c.X==d.X&&c.Y==d.Y);
    MakeGARIS(c,d,&a);
    *L = a;
}

void TulisGARIS (GARIS L)
{
    printf("((%.2f,%.2f),(%.2f,%.2f))",L.PAw.X,L.PAw.Y,L.PAkh.X,L.PAkh.Y);
}

float PanjangGARIS (GARIS L)
{
    float a,b,c,d,x,y;
    a = L.PAw.X;
    b = L.PAw.Y;
    c = L.PAkh.X;
    d = L.PAkh.Y;
    x = a - c;
    y = b - d;
    return sqrt(x*x+y*y);
}

float Gradien (GARIS L)
{
    float a,b,c,d,x,y;
    a = L.PAw.X;
    b = L.PAw.Y;
    c = L.PAkh.X;
    d = L.PAkh.Y;
    x = c - a;
    y = d - b;
    if(x!=0)
    {
    return (y/x);
    }    
}
void GeserGARIS (GARIS * L, float deltaX, float deltaY)
{
    POINT P1,P2;
    GARIS a;
    P1 = PlusDelta(L->PAw,deltaX,deltaY);
    P2 = PlusDelta(L->PAkh,deltaX,deltaY);
    MakeGARIS(P1,P2,&a);
    *L = a;
}

boolean IsTegakLurus (GARIS L1, GARIS L2)
{
    return (Gradien(L1)*Gradien(L2)==-1);
}

boolean IsSejajar (GARIS L1, GARIS L2)
{
    return (Gradien(L1)==Gradien(L2));
}
