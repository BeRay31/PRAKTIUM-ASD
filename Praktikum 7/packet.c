#include <stdio.h>
#include "prioqueuechar.h"
/*
Nama = Reyvan Rizky Irsandy
NIM = 13518136
TGL = 17 10 2019
*/
typedef struct {
    char cChar[100 + 1];//arr of char
} packet;

int main() {
    int t, i, n, icopy;
    char c,temp;
    packet pckt;
    scanf("%d", &n);
    for (i = 1; i <= 101; i++) {
        pckt.cChar[i] = ' ';
    }//inisiasi array
    icopy = 1;//inisiasi
    for (t = 1; t <= n; t++) {//second
        scanf("%d %c", &i, &c);//scan
        pckt.cChar[i] = c;//isi array of char indeks i
        temp = pckt.cChar[icopy]; //temporary memory for print ready packet
        while (temp != ' ')
        {
            printf("%d %c\n",t,temp);
            icopy++;
            temp = pckt.cChar[icopy];
        }
    } // End of For

    }
