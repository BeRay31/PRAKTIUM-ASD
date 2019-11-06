#include "listsirkuler.h"
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
{
    return (First(L) == Nil);
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
{
    First(*L) = Nil;
}
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
{
    address P;
    P = (address)malloc(sizeof(ElmtList));
    if ( P != Nil)
    {
        Next (P) = Nil;
        Info (P) = X;
        return P;
    }
    else
    {
        return Nil;
    }
    
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (address P)
{
    free (P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
{
    address Elmt;
    Elmt = First(L);
    if (First(L)==Nil)
    {
        return Nil;
    }
    if ( Info(Elmt) != X)
    {
        Elmt = Next (Elmt);
        while ((Info(Elmt)!=X) && (Elmt!=First(L)))
        {
            Elmt = Next(Elmt);
            if (Elmt == First(L))
            {
                return Nil;
            }
        }
        return Elmt;
    }
    else
    {
        return Elmt;
    }
    
}
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
{
    address NewElmt;
    NewElmt = Alokasi (X);
    if (NewElmt != Nil)
    {
        InsertFirst(L,NewElmt);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
void InsVLast (List *L, infotype X)
{
    address NewLastElmt;
    NewLastElmt = Alokasi (X);
    if (NewLastElmt != Nil)
    {
        InsertLast(L,NewLastElmt);
    }
}
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype * X)
{
    address Temp;
    DelFirst(L,&Temp);
    *X = Info(Temp);
    Dealokasi(Temp);    
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype * X)
{
    address Temp;
    DelLast(L,&Temp);
    *X = Info (Temp);
    Dealokasi(Temp);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
{
    InsertLast (L,P);
    First(*L) = P;
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLast (List *L, address P)
{
    address Elmt = First(*L);
    if (IsEmpty(*L))
    {
        First(*L) = P;
        Next(P) = P;
    }
    else
    {
        while(Next(Elmt) != First(*L))
        {
            Elmt = Next(Elmt);
        }
        InsertAfter(L, P, Elmt);
    }

}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address P, address Prec)
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)

{
    address last = First(*L);

    if ( Next(last) == First(*L) ){ // only 1 element
        *P = First(*L);
        CreateEmpty(L);
    }
    else{
        while(Next(last) != First(*L)){
            last = Next(last);
        }

        DelAfter(L,P,last);
    }
}

/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, address *P)
{
    address prec = First(*L);

    if ( Next(prec) == First(*L) ){ // only 1 element
        *P = First(*L);
        CreateEmpty(L);
    }
    else{
        while(Next(Next(prec)) != First(*L)){
            prec = Next(prec);
        }
        DelAfter(L,P,prec);
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
void DelAfter (List *L, address *Pdel, address Prec)
{
    if (Next(Prec) == First(*L)){       // shift first(l)
        First(*L) = Next(First(*L));
    }

    if ( Next(First(*L)) == First(*L) ){ // only 1 element
        CreateEmpty(L);
    }

    else{
        *Pdel = Next(Prec);
        Next(Prec) = Next(Next(Prec));
    }
}
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelP (List *L, infotype X)
{
    address P = Search(*L, X);
    address prec = First(*L);
    address del;

    if (P != Nil){ // element found

        if ( Next(prec) == First(*L) ){ // only 1 element
            CreateEmpty(L);
        }

        else{

            /* Search for predecessor of X */
            while(Next(prec) != P){
                prec = Next(prec);
            }

            /* got the prec of P */
            DelAfter(L, &del, prec);
            Dealokasi(del);

        }
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
{
    address prnt;
    if (!IsEmpty(L))
    {
        printf("[");
        prnt = First (L);
        printf("%d",Info(prnt));
        while (Next(prnt) != First(L))
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
