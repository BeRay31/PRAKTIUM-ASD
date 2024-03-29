#include "listdp.h"
#include <stdlib.h>

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
{
    return ((First(L) == Nil) && (Last(L) == Nil));
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
{
    First(*L) = Nil;
    Last(*L) = Nil;
}
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
{
    address P;
    P = (address)malloc(sizeof(ElmtList));
    if (P != Nil)
    {
        Info(P) = X;
        Next(P) = Nil;
        Prev (P) =Nil;
        return P;
    }
    else
    {
        return Nil;
    }
}
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
void Dealokasi (address P)
{
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
{
    address P;
    P = First(L);
    if (First(L) == Nil)
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
/* Mencari apakah ada elemen list dengan Info(P)=X */
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
    address P;
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
    DelFirst(L,&P);
    *X = Info(P);
    Dealokasi (P);
}
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
void DelVLast (List *L, infotype *X)
{
    address P;
    DelLast(L,&P);
    *X = Info(P);
    Dealokasi (P);
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */

/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
{
    if (!IsEmpty(*L))
    {
        InsertBefore(L,P,First(*L));
    }
    else
    {
        First(*L) = P;
        Last(*L) = P; ///first and last is a pointer to address
        Prev(P) = Nil;
        Next(P) = Nil; 
    }
  
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
void InsertLast (List *L, address P)
{
    if (!IsEmpty(*L))
    {
        InsertAfter(L,P,Last(*L));
    }
    else
    {
        First(*L) = P;
        Last(*L) = P; ///first and last is a pointer to address
        Prev(P) = Nil;
        Next(P) = Nil; 
    }
    
}
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
void InsertAfter (List *L, address P, address Prec)
{
    Next (P) = Next (Prec);
    if (Next(Prec)!=Nil) //Not Last Elmt
    {
        Prev(Next(Prec)) = P;
    }
    else //last elmt
    {
        Last (*L) = P;
    }
    Next (Prec) = P;
    Prev (P) = Prec;
}
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
void InsertBefore (List *L, address P, address Succ)
{
    Prev (P) = Prev (Succ);
    if (Prev(Succ)!=Nil)//Not Last Elmt
    {
        Next(Prev(Succ)) = P;
    }
    else // Last Elmt
    {
        First(*L) = P;
    }
    Prev (Succ) = P;
    Next (P) = Succ;
}
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
{

    *P = First (*L);
    First(*L) = Next(First(*L));
    if (First(*L)==Nil)
    {
        CreateEmpty (L);
    }
    else
    {
        Prev(First(*L)) = Nil;
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
void DelLast (List *L, address *P)
{
    *P = Last(*L);
    Last(*L) = Prev(Last(*L));
    if (Last(*L)==Nil)
    {
        CreateEmpty(L);
    }
    else
    {
        Next(Last(*L)) = Nil;    
    }
}
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */
void DelP (List *L, infotype X)
{
    address P = Search(*L, X);

    if (P != Nil){

        if (Prev(P) != Nil) // if it's not first element
            DelAfter(L, P, Prev(P));

        else if (Next(P) != Nil)   // if it's first element
            DelBefore(L, P, Next(P));

        else // if deleted element is singular
            CreateEmpty(L);

        Dealokasi(P);
    }
}
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
void DelAfter (List *L, address *Pdel, address Prec)
{
    address Temp;
    Temp = Next(Prec);//Delted elmt
    *Pdel = Next(Prec);
    Next(Prec) = Next(Temp);
    if (Next(*Pdel)==Nil)//Next (prec) is Last Elmt
    {
        Last(*L) = Prec;
    }
    else //next Prec isnt last Elmt
    {
        Prev(Next(Temp)) = Prec;
    }
}
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
void DelBefore (List *L, address *Pdel, address Succ)
{
    address Temp;
    Temp = Prev(Succ);//Delted elmt
    *Pdel = Prev(Succ);
    Prev(Succ) = Prev(Temp);
    if (Prev(*Pdel)==Nil)//Prev (prec) is First Elmt
    {
        First(*L) = Succ;
    }
    else //next Prec isnt last Elmt
    {
        Next(Prev(Temp)) = Succ;
    }
}
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L)
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
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
void PrintBackward (List L)
{
    address prnt;
    if (!IsEmpty(L))
    {
        printf("[");
        prnt = Last (L);
        printf("%d",Info(prnt));
        while (Prev(prnt) != Nil)
        {
            prnt = Prev(prnt);
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
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
