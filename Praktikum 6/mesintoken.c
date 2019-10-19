#include "mesintoken.h"
#include <stdio.h>
/*
Nama     : Reyvan Rizky Irsandy
NIM      : 13518136
Tanggal  : 22 09 2018
*/
boolean EndToken;
Token CToken;

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
void STARTTOKEN()
{
    START();
    IgnoreBlank();
    switch (CC)
    {
        case MARK :
        {
            EndToken = true;
            break;
        }
        default :
        {
            EndToken = false;
            SalinToken();
            break;
        }
    }
}
/* I.S. : CC sembarang
   F.S. : EndToken = true, dan CC = MARK;
          atau EndToken = false, CToken adalah Token yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir Token */

void ADVTOKEN()
{
    IgnoreBlank();
    switch (CC) 
    {
        case MARK:
        {
            EndToken=true;
            break;
        }
        default:
        {
            EndToken = false;
            SalinToken();
            break;
        }
    }
}
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CToken adalah Token terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, maka EndToken = true
   Proses : Akuisisi kata menggunakan procedure SalinKata */
void SalinToken()
{
    if(CC!=MARK)
    {
        int i = 1;
        int temp = 0;
        int res  = 0;
        while( (CC!=BLANK) && CC!=MARK && i<=NMax)
        {
            if ((CC!='+') && (CC!='-') && (CC!='*') && (CC!='/') && (CC!='^'))
            {
                temp = CC - '0';
                res = res*10 + temp;
                CToken.val = res;
                CToken.tkn = 'b';
                
                i++;
            } 
            else
            {
                CToken.tkn = CC;
                CToken.val = -1;
                
            }
            ADV();
        }
    }
}
/* Mengakuisisi Token dan menyimpan hasilnya dalam CToken
   I.S. : CC adalah karakter pertama dari Token
   F.S. : CToken berisi Token yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */