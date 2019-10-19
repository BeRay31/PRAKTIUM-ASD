#include <stdio.h>
/*  Kamus Umum */
#define IdxMax 100
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxMin 1
/* Indeks minimum array */
#define IdxUndef -999 
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IdxType;  /* type indeks */
typedef int ElType;   /* type elemen tabel */
typedef struct { 
  ElType TI[IdxMax+1]; /* memori tempat penyimpan elemen (container) */
  int Neff; /* >=0, banyaknya elemen efektif */
} TabInt;
/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses: 
   T.Neff  untuk mengetahui banyaknya elemen 
   T.TI    untuk mengakses seluruh nilai elemen tabel 
   T.TI[i] untuk mengakses elemen ke-i */
/* Definisi : 
  Tabel kosong: T.Neff = 0
  Definisi elemen pertama : T.TI[i] dengan i=1 
  Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff */
  
/* ********** SELEKTOR ********** */
#define Neff(T)   (T).Neff
#define TI(T)     (T).TI
#define Elmt(T,i) (T).TI[(i)]

void MaxSortDesc (TabInt * T)/////////////////
{
    ElType Temp;
    IdxType i=1,j;
    IdxType imax;
    if(Neff(*T)>0)
    {
        for (i;i<=Neff(*T);i++)
        {
            imax = i;
            for(j=i;j<=Neff(*T);j++)
            {
                if(TI(*T)[imax]<TI(*T)[j])
                {
                    imax = j;
                }
            }
            Temp = TI(*T)[i];
            TI(*T)[i]=TI(*T)[imax];
            TI(*T)[imax]=Temp;
        }
    }
}
void AddEli (TabInt * T, ElType X, IdxType i)
{
    IdxType j;
    if(Neff(*T)!=0 && Neff(*T)!=IdxMax)
    {
        for (j = Neff(*T)+1;j>i;j--)
        {
            TI(*T)[j]=TI(*T)[j-1];
        }
        TI(*T)[i]=X;
        Neff(*T)+=1;
    }
}
int main()
{   
    TabInt J;
    int c[100]={13,22,45,65,78,88,98};
    int neff = 7;
    for (int i=1;i<=neff;i++)
    {
        TI(J)[i]=c[i-1];
    }
    Neff(J)=neff;
    AddEli(&J,21,3);
    for(int i =1 ;i<=neff;i++)
    {
        printf("%d\n",TI(J)[i]);
    }
    return 0;
}