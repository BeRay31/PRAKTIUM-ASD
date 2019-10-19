#include <stdio.h>
#include "arraydinpos.h"
#include <stdlib.h>
/*Nama      : Reyvan Rizky Irsandy
NIM         : 13518136
Tanggal     : 13 09 2019*/
/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong  */
void MakeEmpty(TabInt *T, int maxel)
{
    MaxEl(*T) = maxel;
    TI(*T) = (int *) malloc ((MaxEl(*T)+1)*sizeof(int));
    for(int i=1;i<=maxel;i++)
    {
        Elmt(*T,i) = ValUndef;
    }    
}
/* I.S. T sembarang, maxel > 0 */
/* F.S. Terbentuk tabel T kosong dengan kapasitas maxel + 1 */
/* Proses: Inisialisasi semua elemen tabel T dengan ValUndef */

void Dealokasi(TabInt *T)
{
    MaxEl(*T)=0;
    free(T);
}
/* I.S. T terdefinisi; */
/* F.S. TI(T) dikembalikan ke system, MaxEl(T)=0; Neff(T)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmt(TabInt T)
{
    int count = 0;
    for (int i=1;i<=MaxEl(T);i++)
    {
        if(Elmt(T,i)!=ValUndef)
        {
            count+=1;
        }
    }
    return count;
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxElement(TabInt T)
{
    return (MaxEl(T));
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx(TabInt T)
{
    return IdxMin;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx(TabInt T)
{
    int a;
    for(int i=1;i<=MaxEl(T);i++)
    {
        if(Elmt(T,i)==ValUndef && Elmt(T,i)==0)
        {
            return i-1;
        }
    }

}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid(TabInt T, IdxType i)
{
    return (i>=IdxMin && i<=MaxEl(T));
}
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxEff(TabInt T, IdxType i)
{
    return (i>=GetFirstIdx(T)&&i<=GetLastIdx(T));
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty(TabInt T)
{
    return (NbElmt(T)==0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFull(TabInt T)
{
    return (NbElmt(T)==MaxEl(T));
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi tabel dari pembacaan *** */
void BacaIsi(TabInt *T)
{
    int N;
    for(;;)
    {   
        scanf("%d",&N);
        if(N>=0 && N<=MaxEl(*T))
        {
            break;
        }
    }
    if (N>0)
    {
        for(int i=1;i<=N;i++)
        {
            scanf("%d",(TI(*T)+i));
        }
    }
}
/* I.S. T sembarang dan sudah dialokasikan sebelumnya */
/* F.S. Tabel T terdefinisi */
/* Proses : membaca banyaknya elemen T dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= MaxElement(T) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= MaxElement(T); Lakukan N kali: Baca elemen mulai dari indeks
      IdxMin satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk T kosong */
void TulisIsiTab(TabInt T)
{
    int i;
    if(!(IsEmpty(T)))
    {
        printf("[");
        for( i=GetFirstIdx(T);i<NbElmt(T);i++)
        {
            printf("%d,",Elmt(T,i));
        }
            printf("%d]",Elmt(T,NbElmt(T)));
    }
    else
    {
        printf("[]");
    }

/* Proses : Menuliskan isi tabel dengan traversal, tabel ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika tabel kosong : menulis [] */
}
/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusMinusTab(TabInt T1, TabInt T2, boolean plus)
{
    TabInt T3;
    if(NbElmt(T1)==NbElmt(T2) && !(IsEmpty(T1)))
    {
        if(plus==true)
        {
            MakeEmpty(&T3,MaxEl(T1));
            for (int i=GetFirstIdx(T1);i<=NbElmt(T1);i++)
            {
                Elmt(T3,i)=Elmt(T1,i)+Elmt(T2,i);
            }
        }
        else if (plus==false)
        {
            MakeEmpty(&T3,MaxEl(T1));
            for (int i=GetFirstIdx(T1);i<=NbElmt(T1);i++)
            {
                Elmt(T3,i)=Elmt(T1,i)-Elmt(T2,i);
            }            
        }
    }
    return T3;    
}
/* Prekondisi : T1 dan T2 memiliki Neff sama dan tidak kosong */
/*              Jika plus=false, tidak ada elemen T1-T2 yang menghasilkan nilai <= 0 */
/* Jika plus = true, mengirimkan  T1+T2, yaitu setiap elemen T1 dan T2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan T1-T2, yaitu setiap elemen T1 dikurangi elemen T2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan tabel : < =, > *** */
boolean IsEQ(TabInt T1, TabInt T2)
{
    boolean EQ;
    if(NbElmt(T1)==NbElmt(T2))
    {
        for (int i=GetFirstIdx(T1);i<=GetLastIdx(T1);i++)
        {
            if(Elmt(T1,i)!=Elmt(T2,i))
            {
                EQ = false;
                break;
            }
            else
            {
                EQ = true;
            }
        }
    }
    else
    {
        EQ = false;
    }
    return EQ;    
}
/* Mengirimkan true jika T1 sama dengan T2 yaitu jika Neff T1 = T2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : Tabel boleh kosong!! *** */
IdxType Search1(TabInt T, ElType X)
{
    if (IsEmpty(T))
    {
        return IdxUndef;
    }
    else
    {
        int i = GetFirstIdx(T);
        while (i<NbElmt(T)&&Elmt(T,i)!=X)
        {
            i++;
        }
        if(Elmt(T,i)==X)
        {
            return i;
        }
        else
        {
            return IdxUndef;
        }
    }
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = X */
/* Jika tidak ada, mengirimkan IdxUndef */
/* Menghasilkan indeks tak terdefinisi (IdxUndef) jika tabel T kosong */
/* Skema Searching yang digunakan bebas */
boolean SearchB(TabInt T, ElType X)
{
    boolean found = false ;
    int i = GetFirstIdx(T);
    while (i<NbElmt(T)&&!(found))
    {
        if (Elmt(T,i)==X)
        {
            found = true;
        }
        else
        {
            found = false;
            i++;
        }
    if(Elmt(T,i)==X)
    {
        found = true;
    }
    else
    {
        found = false;
    }
    }
    return found;
}
/* Search apakah ada elemen tabel T yang bernilai X */
/* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
/* Skema searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void MaxMin(TabInt T, ElType *Max, ElType *Min)
{
    IdxType i,j;
    ElType a,b;
    a = Elmt(T,GetFirstIdx(T));
    if(NbElmt(T)!=0)
    {
        for(i=GetFirstIdx(T)+1;i<=NbElmt(T);i++)
        {
            if(a<Elmt(T,i))
            {
                a=Elmt(T,i);
            }
        }
    }
    *Max = a;
    b = Elmt(T,GetFirstIdx(T));
    if(NbElmt(T)!=0)
    {
        for(j=GetFirstIdx(T)+1;j<=NbElmt(T);j++)
        {
            if(b>Elmt(T,j))
            {
                b=Elmt(T,j);
            }
        }
    } 
    *Min = b;
}
/* I.S. Tabel T tidak kosong */
/* F.S. Max berisi nilai maksimum T;
        Min berisi nilai minimum T */

/* ********** OPERASI LAIN ********** */
void CopyTab(TabInt Tin, TabInt *Tout)
{
    MakeEmpty(&*Tout,MaxEl(Tin));
    for (int i=GetFirstIdx(Tin);i<=NbElmt(Tin);i++)
    {
        Elmt(*Tout,i)=Elmt(Tin,i);
    }
}
/* I.S. Tin terdefinisi tidak kosong, Tout sembarang */
/* F.S. Tout berisi salinan dari Tin (identik, Neff dan MaxEl sama) */
/* Proses : Menyalin isi Tin ke Tout */
ElType SumTab(TabInt T)
{
    ElType sum =0;
    if (IsEmpty(T))
    {
        return 0;
    }
    else
    {
        for (int i = GetFirstIdx(T);i<=GetLastIdx(T);i++)
        {
            if(Elmt(T,i)!=ValUndef)
            {
                sum+=Elmt(T,i);
            }
        }
    }
    return sum;
}
/* Menghasilkan hasil penjumlahan semua elemen T */
/* Jika T kosong menghasilkan 0 */
int CountX(TabInt T, ElType X)
{
    int count = 0;
    for (int i=GetFirstIdx(T);i<=GetLastIdx(T);i++)
    {
        if(Elmt(T,i)==X)
        {
            count ++;
        }
    }
    return count;
}
/* Menghasilkan berapa banyak kemunculan X di T */
/* Jika T kosong menghasilkan 0 */
boolean IsAllGenap(TabInt T)
{
    boolean IsGenap;
    if(IsEmpty(T))
    {
        return false;
    }
    else
    {
        for (int i = GetFirstIdx(T) ;i<=GetLastIdx(T);i++)
        {
            if(Elmt(T,i)%2!=0)
            {
                return false;
            }
            else
            {
                IsGenap =true;
            }
        }

    }
    return IsGenap;
}
/* Menghailkan true jika semua elemen T genap. T boleh kosong */

/* ********** SORTING ********** */
void Sort(TabInt *T, boolean asc)
{
    if (asc == true)
    {
        IdxType i,j;
        ElType Temp;
        if (NbElmt(*T)>0)
        {
            for(i=GetFirstIdx(*T)+1;i<=NbElmt(*T);i++)
            { 
                Temp = Elmt(*T,i);
                j=i-1;
                while(j>0 && Elmt(*T,j)>=Temp)
                {
                    Elmt(*T,j+1) = Elmt(*T,j);
                    Elmt(*T,j) = Temp;
                    j--;
                }
            }
        }          
    }
    else
    {
        IdxType i,j;
        ElType Temp;
        if (NbElmt(*T)>0)
        {
            for(i=GetFirstIdx(*T)+1;i<=NbElmt(*T);i++)
            { 
                Temp = Elmt(*T,i);
                j=i-1;
                while(j>0 && Elmt(*T,j)<=Temp)
                {
                    Elmt(*T,j+1) = Elmt(*T,j);
                    Elmt(*T,j) = Temp;
                    j--;
                }
            }
        }  
    }
}
/* I.S. T boleh kosong */
/* F.S. Jika asc = true, T terurut membesar */
/*      Jika asc = false, T terurut mengecil */
/* Proses : Mengurutkan T dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */   
void AddAsLastEl(TabInt *T, ElType X)
{
    if (NbElmt(*T) != MaxEl(*T))
    {
        Elmt(*T,NbElmt(*T)+1)=X;
    }
}
/* Proses: Menambahkan X sebagai elemen terakhir tabel */
/* I.S. Tabel T boleh kosong, tetapi tidak penuh */
/* F.S. X adalah elemen terakhir T yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void DelLastEl(TabInt *T, ElType *X)
{
    if (!(IsEmpty(*T)))
    {
        *X=Elmt(*T,NbElmt(*T));
        Elmt(*T,NbElmt(*T))=ValUndef;
    }
}
/* Proses : Menghapus elemen terakhir tabel */
/* I.S. Tabel tidak kosong */
/* F.S. X adalah nilai elemen terakhir T sebelum penghapusan, */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void GrowTab(TabInt *T, int num)
{
    TI(*T) =(int*)realloc(TI(*T),(MaxEl(*T)+num+1)*sizeof(int));
    MaxEl(*T) +=num;
}
/* Proses : Menambahkan max element sebanyak num */
/* I.S. Tabel sudah terdefinisi */
/* F.S. Ukuran tabel bertambah sebanyak num */

void ShrinkTab(TabInt *T, int num)
{
    TI(*T) =(int*)realloc(TI(*T),(MaxEl(*T)-num+1)*sizeof(int));
    MaxEl(*T)-=num;
}
/* Proses : Mengurangi max element sebanyak num */
/* I.S. Tabel sudah terdefinisi, ukuran MaxEl > num, dan Neff < MaxEl - num. */
/* F.S. Ukuran tabel berkurang sebanyak num. */

void CompactTab(TabInt *T)
{
    TI(*T) =(int*)realloc(TI(*T),(NbElmt(*T)+1)*sizeof(int));
    MaxEl(*T)=NbElmt(*T);
}

/* Proses : Mengurangi max element sehingga Neff = MaxEl */
/* I.S. Tabel tidak kosong */
/* F.S. Ukuran MaxEl = Neff */
