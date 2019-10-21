#include "listlinier.h"
#include <stdlib.h>
#include <stdio.h>
/*
Nama    : Reyvan Rizky Irsandy
NIM     : 13518136
TGL     : 19 10 2019
*/
/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
{
    return First(L) == Nil;
}
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
{
    First(*L) = Nil;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
{
    address P;
    P = (address)malloc(sizeof(ElmtList));
    if (P == NULL)
    {
        return Nil;
    }
    else
    {
        Info(P) = X;
        Next(P) = Nil;
        return P;
    }
    
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address *P)
{
    free(*P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
{
    address P;
    P = First(L);
    if (First(L)==Nil)
    {
        return Nil;
    }
    else
    {
        while ((Info(P) != X) && (P != Nil))
        {
            P = Next(P);
            if (P == Nil)
            {
                return Nil;
            }
        }
        return P;
    }
}
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
{
    address P;
    P = Alokasi (X);
    if (P != Nil)
    {
        InsertFirst(L,P);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X)
{
    address P,Last;
    P = Alokasi (X);
    if ( P != Nil)
    {
        InsertLast(L,P);
    }
    
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
{
    address P;
    P = First(*L);
    *X = Info(P);
    First(*L) = Next(First(*L));
    Next(P) = Nil;
    Dealokasi (&P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X)
{
    address P;
    DelLast(L,&P);
    *X = Info(P);
    P = Nil;
    Dealokasi (&P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
{
    Next (P) = First(*L);
    First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertAfter (List *L, address P, address Prec)
{
    Next (P) = Next(Prec);
    Next (Prec) = P;    
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertLast (List *L, address P)
{
    address Last;
    if (!IsEmpty(*L))
    {
        Last = First(*L);
        while (Next(Last)!=Nil)
        {
            Last = Next (Last);
        }
        Next (P) = Next (Last);
        Next (Last) = P;
    }
    else
    {
        InsertFirst(L,P);
    }
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
{
    *P = First (*L);
    First(*L) = Next(Next(First(*L)));
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelP (List *L, infotype X)
{
    address P,del,Prec;
    Prec = First (*L);
    P = Search (*L,X);
    if (P != Nil)
    {
        if (P == First(*L))
        {
            del = First(*L);
            First(*L) = Next(First(*L));
            Dealokasi (&del);
        }
        else
        {
            while ((Next(Prec)!=P) && (Next(Prec)!=Nil))
            {
                Prec = Next (Prec);
            }
            if(Next(Prec)== P)
            {
                del = Next (Prec);
                Next (Prec) = Next ( Next (Prec));
                Dealokasi (&del);
            }
        }
    }
}//18 -- 21
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika ada lebih dari satu elemen list dengan Info bernilai X */
/* maka yang dihapus hanya elemen pertama dengan Info = X */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelLast (List *L, address *P)
{
    address Last;
    if ( First (*L)!=Nil)
    {
        Last = First (*L);
        if (Next(Last) == Nil)
        {
            *P = Last;
            First(*L) = Next(Last);
        }
        else
        {
            while (Next(Next(Last))!=Nil)
            {
                Last = Next (Last);
            }
            *P = Next(Last);
            Next (Last) = Next (Next (Last));
        }
    }
}//22 23
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen terakhir yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec)
{
    *Pdel = Next (Prec);
    Next(Prec) = Next (Next (Prec));
    Next(*Pdel) = Nil;
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
{
    address prnt;
    if (!IsEmpty(L))
    {
        printf("[");
        prnt = First (L);
        printf("%d",Info(prnt));
        while (Next(prnt) != Nil)
        {
            prnt = Next(prnt);
            printf(",%d",Info(prnt));
        }
        printf ("]");
    }
    else
    {
        printf ("[]");
    }
    
}
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
int NbElmt (List L)
{
    address P;
    infotype count;
    count = 0;
    if (IsEmpty(L))
    {
        return 0;
    }
    else
    {
        P = First(L);
        while (P!=Nil)
        {
            count++;
            P = Next(P);
        }
    }
    return count;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
infotype Max (List L)
{
    infotype max;
    address P;
    P = First (L);
    max = Info(P);
    while (Next (P)!=Nil)
    {
        P = Next(P);
        if (max<Info(P))
        {
            max = Info(P);
        }
    }
    return max;
}
/* Mengirimkan nilai Info(P) yang maksimum */

/****************** PROSES TERHADAP LIST ******************/
void Konkat1 (List *L1, List *L2, List *L3)
{
    CreateEmpty(L3);
    address temp;
    if(First(*L1) != Nil)
    {
        temp =First (*L1);
        First (*L3) = temp;
        while (Next(temp)!=Nil)
        {
            temp = Next(temp);
        }
        Next(temp) = First(*L2);
        while (Next(temp)!=Nil)
        {
            temp = Next(temp);
        }
    }
    else
    {
        temp = First (*L2);
        First (*L3) = temp;
        while(Next(temp)!=Nil)
        {
            temp = Next(temp);
        }
    }
    First(*L1) = Nil;
    First (*L2) = Nil;
}
/* I.S. L1 dan L2 sembarang */
/* F.S. L1 dan L2 kosong, L3 adalah hasil konkatenasi L1 & L2 */
/* Konkatenasi dua buah list : L1 dan L2    */
/* menghasilkan L3 yang baru (dengan elemen list L1 dan L2) */
/* dan L1 serta L2 menjadi list kosong.*/
/* Tidak ada alokasi/dealokasi pada prosedur ini */