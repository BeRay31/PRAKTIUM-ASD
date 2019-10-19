//Nama : Reyvan Rizky Irsandy
//NIM : 13518136  
//tanggal : 28 08 2019
// Topik : konversi suhu
#include <stdio.h>
int main()
{
    float a;
    char b;
    scanf("%f",&a);
    scanf("%s",&b);
    switch (b)
    {
    case 'R':
        printf("%.2f\n",4.00/5.00*a);
        break;
    case 'F':
        printf("%.2f\n",(9.00/5.00*a)+32.00);
        break;
    case 'K' :
        printf("%.2f\n",a + 273.15);
        break;
    default:
        printf ("%.2f\n",0);
        break;
    }
    return 0;
}