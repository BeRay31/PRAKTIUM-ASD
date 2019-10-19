#include <stdio.h>
#include "matriks.h"
/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M)
{
    NBrsEff(*M) = NB;
    NKolEff (*M) = NK;
}
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j)
{
    return(i>=BrsMin && i<=BrsMax && j>=KolMin && j<=KolMax);
}
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M)
{
    return (BrsMin);
}
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKol (MATRIKS M)
{
    return(KolMin);
}
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs (MATRIKS M)
{
    return (NBrsEff(M));
}
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol (MATRIKS M)
{
    return (NKolEff(M));
}
/* Mengirimkan indeks kolom terbesar M */
boolean IsIdxEff (MATRIKS M, indeks i, indeks j)
{
    return (i>=BrsMin && i<=NBrsEff(M) && j>=KolMin && j<=NKolEff(M));
}
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
ElType GetElmtDiagonal (MATRIKS M, indeks i)
{
    return Elmt(M,i,i);
}
/* Mengirimkan elemen M(i,i) */

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl)
{
    MakeMATRIKS(NBrsEff(MIn),NKolEff(MIn),MHsl);
    for (int i = GetFirstIdxBrs(MIn);i<=NBrsEff(MIn);i++)
    {
        for (int j = GetFirstIdxKol(MIn);j<=NKolEff(MIn);j++)
        {
            Elmt(*MHsl,i,j) = Elmt(MIn,i,j);
        }
    }
}
/* Melakukan assignment MHsl  MIn */

/* ********** KELOMPOK BACA/TULIS ********** */
void BacaMATRIKS (MATRIKS * M, int NB, int NK)
{
    int temp;
    if (IsIdxValid(NB,NK))
    {
        MakeMATRIKS(NB,NK,M);
        for(int i = GetFirstIdxBrs(*M);i<=NB;i++)
        {
            for(int j = GetFirstIdxKol(*M);j<=NK;j++)
            {
                scanf("%d",&temp);
                Elmt(*M,i,j) = temp;
            }
        }
    }
}
/* I.S. IsIdxValid(NB,NK) */
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10
*/
void TulisMATRIKS (MATRIKS M)
{
    for (int i = GetFirstIdxBrs(M);i<=NBrsEff(M);i++)
    {
        for (int j = GetFirstIdxKol(M);j<=NKolEff(M);j++)
        {
            if(j!=NKolEff(M))
            {
                printf ("%d ",Elmt(M,i,j));
            }
            else if(j==NKolEff(M)&&i!=NBrsEff(M))
            {
                printf ("%d\n",Elmt(M,i,j));
            }
            else if (j==NKolEff(M)&&i==NBrsEff(M))
            {
                printf("%d",Elmt(M,i,j));
            }
        }
    }
}
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2)
{
    MATRIKS M3;
    MakeMATRIKS(NBrsEff(M1),NKolEff(M1),&M3);
    for (int i = GetFirstIdxBrs(M1);i<=NBrsEff(M1);i++)
    {
        for (int j = GetFirstIdxKol(M1);j<=NKolEff(M1);j++)
        {
            Elmt(M3,i,j) = Elmt(M1,i,j) + Elmt(M2,i,j);
        }
    }
    return M3;
}
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2)
{
    MATRIKS M3;
    MakeMATRIKS(NBrsEff(M1),NKolEff(M1),&M3);
    for (int i = GetFirstIdxBrs(M1);i<=NBrsEff(M1);i++)
    {
        for (int j = GetFirstIdxKol(M1);j<=NKolEff(M1);j++)
        {
            Elmt(M3,i,j) = Elmt(M1,i,j) - Elmt(M2,i,j);
        }
    }
    return M3;    
}
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2)
{
    int temp = 0;
    MATRIKS Mout;
    MakeMATRIKS(NBrsEff(M1),NKolEff(M2),&Mout);
    for (int i = GetFirstIdxBrs(M1);i<=NBrsEff(M1);i++)
    {
        for(int j = GetFirstIdxKol(M2);j<=NKolEff(M2);j++)
        {
            for(int k = GetFirstIdxKol(M1);k<=NKolEff(M1);k++)
            {
                temp += Elmt(M1,i,k)*Elmt(M2,k,j);
            }
            Elmt(Mout,i,j) = temp;
            temp = 0;
        }
    }
    return Mout;
}
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
MATRIKS KaliKons (MATRIKS M, ElType X)
{
    MATRIKS Mout;
    MakeMATRIKS(NBrsEff(M),NKolEff(M),&Mout);
    for (int i = GetFirstIdxBrs(M);i<=NBrsEff(M);i++)
    {
        for (int j = GetFirstIdxKol(M);j<=NKolEff(M);j++)
        {
            Elmt(Mout,i,j) = Elmt(M,i,j)*X;
        }
    }
    return Mout;      
}
/* Mengirim hasil perkalian setiap elemen M dengan X */
void PKaliKons (MATRIKS * M, ElType K)
{
    for (int i = GetFirstIdxBrs(*M);i<=NBrsEff(*M);i++)
    {
        for (int j = GetFirstIdxKol(*M);j<=NKolEff(*M);j++)
        {
            Elmt(*M,i,j) *= K;
        }
    }
}
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean EQ (MATRIKS M1, MATRIKS M2)
{
    if (NBrsEff(M1)==NBrsEff(M2)&&NKolEff(M1)==NKolEff(M2))
    {
        int b ;
        for (int i = GetFirstIdxBrs(M1);i<=NBrsEff(M1);i++)
        {
            for (int j = GetFirstIdxKol(M1);j<=NKolEff(M1);j++)
            {
                if(Elmt(M1,i,j)!=Elmt(M2,i,j))
                {
                    return false;
                }
                b = j;
            }
            if (i == NBrsEff(M1) && b == NKolEff(M1))
            {
                if(Elmt(M1,i,b)==Elmt(M2,i,b))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    else
    {
        return false;
    }
}
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2)
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
boolean NEQ (MATRIKS M1, MATRIKS M2)
{
    if (NBrsEff(M1)==NBrsEff(M2)&&NKolEff(M1)==NKolEff(M2))
    {
        int b;
        for (int i = GetFirstIdxBrs(M1);i<=NBrsEff(M1);i++)
        {
            for (int j = GetFirstIdxKol(M1);j<=NKolEff(M1);j++)
            {
                if(Elmt(M1,i,j)!=Elmt(M2,i,j))
                {
                    return true;
                }
                b = j;
            }
            if (i == NBrsEff(M1) && b == NKolEff(M1))
            {
                if(Elmt(M1,i,b)==Elmt(M2,i,b))
                {
                    return false;
                }
                else
                {
                    return true;
                }
            }
        }
    }
    else
    {
        return true;
    }
}
/* Mengirimkan true jika M1 tidak sama dengan M2 */
boolean EQSize (MATRIKS M1, MATRIKS M2)
{
    return ((NBrsEff(M1)==NBrsEff(M2)&&(NKolEff(M1)==NKolEff(M2))));
}
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M)
{
    return (NBrsEff(M)*NKolEff(M));
}
/* Mengirimkan banyaknya elemen M */

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M)
{
    return (NBrsEff(M)==NKolEff(M));
}
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
boolean IsSimetri (MATRIKS M)
{
    int b;
    if (IsBujurSangkar(M))
    {
        for (int i = GetFirstIdxBrs(M);i<=NBrsEff(M);i++)
        {
            for (int j = GetFirstIdxKol(M);j<=NKolEff(M);j++)
            {
                if(Elmt(M,i,j)!=Elmt(M,j,i))
                {
                    return false;
                }
                b=j;
            }
            if(i == NBrsEff(M) && b == NKolEff(M))
            {
                if(Elmt(M,i,b)==Elmt(M,b,i))
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
    }
    else
    {
        return false;
    }
}
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M)
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
boolean IsSatuan (MATRIKS M)
{
    if (IsBujurSangkar(M))
    {
        for (int i = GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++)
        {
            for (int j = GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++)
            {
                if (i!=j && Elmt(M,i,j) != 0)
                {
                    return false;
                }
                else if (i ==j && Elmt(M,i,j) == 0 )
                {
                    return false;
                }
            }
        }
        if(Elmt(M,GetLastIdxBrs(M),GetLastIdxKol(M))!= 0 )
        {
            return true;
        }
    }
    else
    {
        return false;
    }
}
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */
boolean IsSparse (MATRIKS M)
{
    float Neff5Prcnt;
    int count = 0;
    for (int i = GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++)
    {
        for (int j = GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++)
        {
            if(Elmt(M,i,j)!=0)
            {
                count++;
            }
        }
    }
    Neff5Prcnt = NBrsEff(M)*NKolEff(M)*0.05;
    return (count<=Neff5Prcnt);
}
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi:
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */
MATRIKS Inverse1 (MATRIKS M)
{
    MATRIKS Mout;
    MakeMATRIKS (NBrsEff(M),NKolEff(M),&Mout);
    Mout = KaliKons(M,-1);
    return Mout;
}
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
float Determinan (MATRIKS M)
{
    MATRIKS Minor;
    int n = GetLastIdxKol(M);
    float det = 0;
    int c1 = 1;
    int c2 = 1;
    if(n==2)
    {
        det = Elmt(M,1,1)*Elmt(M,2,2)-Elmt(M,1,2)*Elmt(M,2,1);
        return (det);
    }
    else if(n==1)
    {
        return Elmt(M,1,1);
    }
    else
    {
        for (int i = GetFirstIdxBrs(M);i<=GetLastIdxBrs(M);i++)
        {
            MakeMATRIKS(NBrsEff(M)-1,NKolEff(M)-1,&Minor);
            n = NBrsEff(M)-1;
            for(int j = GetFirstIdxKol(M);j<=GetLastIdxKol(M);j++)
            {
                if (j!=1)
                {
                    for (int k =GetFirstIdxBrs(M);k<=GetLastIdxBrs(M);k++)
                    {
                        if(k!=i)
                        {
                            Elmt(Minor,c1,c2) = Elmt(M,k,j) ;
                            c1++;
                        } 
                    }
                    c1 = 1;
                    c2++;
                }
                
            }
            c2 = 1;
            if ((i+1)%2!=0)
            {
                det += Elmt(M,i,1)*Determinan(Minor)*(-1);
            }
            else
            {
                det+= Elmt(M,i,1)*Determinan(Minor);
            }
        }
        return det;
    }
}
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
void PInverse1 (MATRIKS * M)
{
    PKaliKons(M,-1);
}
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
void Transpose (MATRIKS * M)
{
    int temp;
    for (int i = GetFirstIdxBrs(*M);i<=GetLastIdxBrs(*M);i++)
    {
        for( int j = i+1;j<=GetLastIdxKol(*M);j++)
        {
            temp = Elmt(*M,i,j);
            Elmt(*M,i,j) = Elmt(*M,j,i);
            Elmt(*M,j,i)=temp;
        }
    }
}

float RataBrs (MATRIKS M, indeks i)
{
    float count = 0;
    for (int j =1 ; j<=NKolEff(M);j++)
    { 
        count += Elmt(M,i,j);
    }
    return(count/NKolEff(M));
}
/* Menghasilkan rata-rata dari elemen pada baris ke-i */
/* Prekondisi: i adalah indeks baris efektif dari M */
float RataKol (MATRIKS M, indeks j)
{
    float count = 0;
    for (int i=1 ; i<=NBrsEff(M);i++)
    { 
        count += Elmt(M,i,j);
    }
    return(count/NBrsEff(M));

}
/* Menghasilkan rata-rata dari elemen pada kolom ke-j */
/* Prekondisi: j adalah indeks kolom efektif dari M */
void MaxMinBrs (MATRIKS M, indeks i, ElType * max, ElType * min)
{
    if (i>=BrsMin && i<=NBrsEff(M))
    {
        *max = Elmt(M,i,1);
        *min = Elmt(M,i,1);
        for (int j = 1;j<=NKolEff(M);j++)
        {
            if(*max <= Elmt(M,i,j))
            {
                *max = Elmt(M,i,j);
            }
        }
        for (int j =1 ; j<=NKolEff(M);j++)
        {
            if(*min>=Elmt(M,i,j))
            {
                *min = Elmt(M,i,j); 
            }
        }
    }
}
/* I.S. i adalah indeks baris efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada baris i dari M
           min berisi elemen minimum pada baris i dari M */
void MaxMinKol (MATRIKS M, indeks j, ElType * max, ElType * min)
{
    if (j>=KolMin && j<=NKolEff(M))
    {
        *max = Elmt(M,1,j);
        *min = Elmt(M,1,j);
        for (int i = 1;i<=NBrsEff(M);i++)
        {
            if(*max <= Elmt(M,i,j))
            {
                *max = Elmt(M,i,j);
            }
        }
        for (int i =1 ; i<=NBrsEff(M);i++)
        {
            if(*min>=Elmt(M,i,j))
            {
                *min = Elmt(M,i,j); 
            }
        }
    }
}    

/* I.S. j adalah indeks kolom efektif dari M, M terdefinisi */
/* F.S. max berisi elemen maksimum pada kolom j dari M
           min berisi elemen minimum pada kolom j dari M */
int CountXBrs (MATRIKS M, indeks i, ElType X)
{
    int count = 0;
    for (int j =1 ; j<=NKolEff(M);j++)
    {
        if(Elmt(M,i,j) == X)
        {
            count++;
        }
    }
    return count;
}
/* Menghasilkan banyaknya kemunculan X pada baris i dari M */
int CountXKol (MATRIKS M, indeks j, ElType X)
{
    int count = 0;
    for (int i = 0 ; i <=NBrsEff(M);i++)
    {
        if(Elmt(M,i,j)==X)
        {
            count++;
        }
    }
    return count;
}

/* Menghasilkan banyaknya kemunculan X pada kolom j dari M */


/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */