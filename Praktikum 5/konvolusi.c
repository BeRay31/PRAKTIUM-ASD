/*Nama    : Reyvan Rizky Irsandy
NIM     : 13518136
Tanggal : 12 09 2019*/
#include <stdio.h>
#include "matriks.h"
int main()
{
    MATRIKS A,C,B;
    int N,M,K,sum,delta_i,delta_j,idxCent;
    sum =0;
    scanf("%d",&N);
    scanf("%d",&M);
    BacaMATRIKS(&A,N,M);
    scanf("%d",&K);
    BacaMATRIKS(&B,K,K);
    MakeMATRIKS(N,M,&C);
    idxCent = (K+1)/2;
    for (int i = 1; i <=N;i++)
    {
        for(int j =1;j<=M;j++)
        {
            for(int i2 = 1;i2<=K;i2++)
            {
                for(int j2 = 1;j2<=K;j2++)
                {
                     delta_i = i - idxCent;
                     delta_j = j - idxCent;
                    if(IsIdxEff(A,i2+delta_i,j2+delta_j))
                    {
                        sum+= Elmt(A,i2+delta_i,j2+delta_j)*Elmt(B,i2,j2); 
                    }
                }
            }
            Elmt(C,i,j) = sum;
            sum = 0;
        }
    }
    TulisMATRIKS(C);
    return 0;
}