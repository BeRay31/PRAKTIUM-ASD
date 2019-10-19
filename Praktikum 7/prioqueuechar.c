#include "prioqueuechar.h"
#include <stdio.h>
#include <stdlib.h>
/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueChar Q)
{
    return Tail(Q) == Nil;
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (PrioQueueChar Q)
{
    return NBElmt(Q)==MaxEl(Q);
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt (PrioQueueChar Q)
{
    if (IsEmpty(Q))
    {
        return 0;
    }
    else if (Tail(Q)>=Head(Q))
    {
        return Tail(Q) - Head(Q) + 1 ; 
    }
    else
    {
        return MaxEl(Q)-(Head(Q)-Tail(Q)-1) ;
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void CreateEmpty (PrioQueueChar * Q, int Max)
{
    (*Q).T = (infotype*)malloc((Max+1)*sizeof(infotype));
    if ((*Q).T != NULL)
    {
        MaxEl(*Q) = Max;
        Head(*Q) = Nil;
        Tail(*Q) = Nil; 
    }
    else
    {
        MaxEl(*Q) = Nil;
    }
    
}
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueueChar * Q)
{
    MaxEl(*Q) = Nil;
    free ((*Q).T);
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Add (PrioQueueChar * Q, infotype X)
{
    int i,j,k;
    if (IsEmpty(*Q))
    {
        Head(*Q) = 1;
        Tail(*Q) = 1;
        InfoTail(*Q) = X;
    }
    else
    {
        i = Tail(*Q);
        while (Prio(X)<Prio(Elmt(*Q,i)) & (i != Head(*Q)))
        {
            i--;
            if (i<1) 
            {
                i = MaxEl(*Q);
            }
        }//cari letak 
        if (Prio(X)<Prio(Elmt(*Q,i)))
        {
            i = Head(*Q);
        }
        else
        {
            i++;
            if(i>MaxEl(*Q))
            {
                i = 1;
            }
        }
        //penambahan
        Tail(*Q)++;
        if (Tail(*Q)>MaxEl(*Q))
        {
            Tail(*Q) = 1;
        }        
        //geser

        j = Tail(*Q);
        while (j!=i)
        {
            k = j -1;
            if(k<1)
            {
                k = MaxEl(*Q);
            }
            Elmt(*Q,j) = Elmt(*Q,k);
            j--;
            if(j<1)
            {
                j = MaxEl(*Q);
            }
        }
        //replace
        Elmt(*Q,i) = X;
    }
}
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut mengecil berdasarkan prio */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Del (PrioQueueChar * Q, infotype * X)
{
    if (Head(*Q)==Tail(*Q))
    {
        *X = InfoHead(*Q);
        Head(*Q) = Nil;
        Tail(*Q) = Nil;
    }
    else
    {
        *X = InfoHead(*Q);
        Head(*Q)++;
        if(Head(*Q)>MaxEl(*Q))
        {
            Head(*Q)=1;
        }
    }
}
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioQueueChar (PrioQueueChar Q)
{
    if (IsEmpty(Q))
    {
        printf("#\n");
    }
    else
    {
        int i = Head(Q);
        while (i!=Tail(Q))
        {
            printf("%d %c\n",Prio(Elmt(Q,i)),Info(Elmt(Q,i)));
            i++;
            if(i>MaxEl(Q))
            {
                i = 1;
            }
        }
        printf("%d %c\n",Prio(Elmt(Q,i)),Info(Elmt(Q,i)));
        printf("#\n");
    }
    
}
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<prio-1> <elemen-1>
...
<prio-n> <elemen-n>
#
*/