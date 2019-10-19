#include "mesinkata.h"
#include <stdio.h>
/*
Nama     : Reyvan Rizky Irsandy
NIM      : 13518136
Tanggal  : 22 09 2018
*/
void Salin(Kata *dest,Kata src)
{
    dest->Length = src.Length;
    for ( int i = 1;i<=src.Length;i++)
    {
        dest->TabKata[i] = src.TabKata[i];
    }
}
int main()
{
    boolean sama;
    int count = 0;
    Kata temp;
    Kata Subs;
    int j = 1;
    int k;
    STARTKATA();//cuma salin bila ga mark
    Salin(&temp,CKata);
    ADVKATA();//adv dulu baru di cek
    while(EndKata!=true) //kalo mark ga jadi loop
    {
        if(CKata.Length<temp.Length)
        {
            count+=0;
        }
        else if(CKata.Length == temp.Length)
        {
            sama = true;
            for(int i =1 ;i<=CKata.Length;i++)
            {
                if(CKata.TabKata[i]!=temp.TabKata[i])
                {
                    sama = false;
                    break;
                }
            }
            if(sama)
            {
                count ++;
            }
        }
        else
        {
            for(int i = 0 ;i<=CKata.Length - temp.Length;i++)
            {
                sama = true;
                j = 1;
                while((sama)&&(j<=temp.Length))
                {
                    if(CKata.TabKata[j+i] == temp.TabKata[j])
                    {
                        j++;
                    }
                    else
                    {
                        sama = false;
                    }
                }
                if (sama==true)
                {
                    count+=1;
                }
            }
        }
        ADVKATA();

    }
    printf("%d\n",count);
}