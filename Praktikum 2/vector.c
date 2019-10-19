#include <stdio.h>
#include "vector.h"
#include <math.h>
/*  Nama     :  Reyvan Rizky Irsandy
    NIM      :  13518136
    Tanggal  :  02 09 2019
    Topik    :  Vektor */
VECTOR MakeVector(float x, float y)
{
    VECTOR V;
    AbsisComponent(V) = x;
    OrdinatComponent(V) = y;
    return V;
}

void TulisVector(VECTOR v)
{
    printf("<%.2f,%.2f>",AbsisComponent(v),OrdinatComponent(v));
}

float Magnitude(VECTOR v)
{
    float x,y;
    x = AbsisComponent(v);
    y = OrdinatComponent(v);
     return sqrt(x*x+y*y);
}

VECTOR Add(VECTOR a, VECTOR b)
{
    return MakeVector(AbsisComponent(a)+AbsisComponent(b),OrdinatComponent(a)+OrdinatComponent(b));
}

VECTOR Substract(VECTOR a, VECTOR b)
{
    return MakeVector(AbsisComponent(a)-AbsisComponent(b),OrdinatComponent(a)-OrdinatComponent(b));
}

float Dot(VECTOR a, VECTOR b)
{
    return AbsisComponent(a)*AbsisComponent(b)+OrdinatComponent(a)*OrdinatComponent(b);
}

VECTOR Multiply(VECTOR v, float s)
{
    return MakeVector(AbsisComponent(v)*s,OrdinatComponent(v)*s);
}