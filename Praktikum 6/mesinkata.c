
#include <stdio.h>
#include "mesinkata.h"
/*
Nama     : Reyvan Rizky Irsandy
NIM      : 13518136
Tanggal  : 22 09 2018
*/
boolean EndKata;
Kata CKata;
void IgnoreBlank()
{
  while (CC == BLANK)
  {
    ADV();
  }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATA()
{
  START();
  IgnoreBlank();
  switch(CC)
  {
    case MARK : 
    {
      EndKata = true;
      break;
    }
    default : 
    {
      EndKata = false;
      SalinKata();
      break;
    }
  }
}
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA()
{
  IgnoreBlank();
  switch(CC)
  {
    case MARK : EndKata = true;break;
    default : {
      SalinKata();
      break;
      }
  }
}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata()
{
  int i  = 1;
  do
  {
    CKata.TabKata[i] = CC;
    ADV();
    i++;
  } while (CC!=MARK && CC!=BLANK && i<=NMax);
  CKata.Length = i - 1;
}
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

