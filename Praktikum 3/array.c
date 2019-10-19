#include <stdio.h>
#include "array.h"
#include "boolean.h"
void MakeEmpty (TabInt * T)
{
    Neff(*T) = 0;
}
int NbElmt (TabInt T)
{
    return Neff(T);
}
int MaxNbEl (TabInt T)
{
    return(IdxMax-IdxMin+1);
}
IdxType GetFirstIdx (TabInt T)
{
    return IdxMin;
}
IdxType GetLastIdx (TabInt T)
{
    return Neff(T);
}
boolean IsIdxValid (TabInt T, IdxType i)
{
    return (i>=IdxMin && i<=IdxMax);//0 atau idxmin
}
boolean IsIdxEff (TabInt T, IdxType i)
{
    return  (i>=GetFirstIdx(T) && i<=GetLastIdx(T));
}
boolean IsEmpty (TabInt T)
{
    return (T.Neff==0);
}
boolean IsFull (TabInt T)
{
    return (T.Neff==MaxNbEl(T));
}
void BacaIsi (TabInt * T)
{
    int N;
    for (;;)
    {
        scanf("%d",&N);
        if (N>=0 && N<=MaxNbEl(*T))
        {
            Neff(*T)=N;
            break;
        }
        
    }
    if(N>0)
    {
        for (IdxType i = IdxMin; i <=N; i++)
        {
            scanf("%d",&T->TI[i]);
        }
    }
    else if (N ==0)
    {
        MakeEmpty(&*T);
    }
    
}

void BacaIsiTab (TabInt * T)
{
    ElType Temp;
    IdxType i=IdxMin;
    for(;;)
    {
        scanf("%d",&Temp);
        if (Temp == -9999 || i>=IdxMax)
        {
            break;
        }
        else
        {
            T->TI[i] = Temp;
            i++;
            T->Neff++;
        }
    }
    if (Neff(*T)==0)
    {
        MakeEmpty(&*T);
    }
}

void TulisIsi (TabInt T)
{
    if (Neff(T)==0)
    {
        printf("Tabel kosong");
    }
    else
    {
        for (IdxType i=1;i<=Neff(T);i++)
        {
            printf("[%d]%d\n",i,TI(T)[i]);
        }
    }
}

void TulisIsiTab (TabInt T)
{
    if (Neff(T)==0)
    {
        printf("[]");
    }
    else
    {
        printf("[");
        for(IdxType i =1;i<Neff(T);i++)
        {
            printf("%d,",TI(T)[i]);
        }
        printf("%d]",TI(T)[Neff(T)]);
    }
}
TabInt PlusTab (TabInt T1, TabInt T2)
{
    TabInt T;
    Neff(T)=Neff(T1);
    if(Neff(T1)!=0 && Neff(T2)!=0 && Neff(T1)==Neff(T2))
    {
        for(IdxType i =1 ;i<=Neff(T);i++)
        {
            TI(T)[i]=TI(T1)[i]+TI(T2)[i];
        }
    }
    return T;
}
TabInt MinusTab (TabInt T1, TabInt T2)
{
    TabInt T;
    Neff(T)=Neff(T1);
    if(Neff(T1)!=0 && Neff(T2)!=0 && Neff(T1)==Neff(T2))
    {
        for(IdxType i =1 ;i<=Neff(T);i++)
        {
            TI(T)[i]=TI(T1)[i]-TI(T2)[i];
        }
    }
    return T;    
}
TabInt KaliTab (TabInt T1, TabInt T2)
{
    TabInt T;
    Neff(T)=Neff(T1);
    if(Neff(T1)!=0 && Neff(T2)!=0 && Neff(T1)==Neff(T2))
    {
        for(IdxType i =1 ;i<=Neff(T);i++)
        {
            TI(T)[i]=TI(T1)[i]*TI(T2)[i];
        }
    }
    return T;     
}
TabInt KaliKons (TabInt Tin, ElType c)
{
    TabInt T;
    if(Neff(Tin)!=0)
    {
        Neff(T)=Neff(Tin);
                for(IdxType i =1 ;i<=Neff(T);i++)
        {
            TI(T)[i]=TI(Tin)[i]*c;
        }
    }
    return T;     
}
boolean IsEQ (TabInt T1, TabInt T2)
{
    boolean same;
    if (Neff(T1)==Neff(T2))
    {
        for(IdxType i=1;i<=Neff(T1);i++)
        {
            if (TI(T1)[i]!=TI(T2)[i])
            {
                same = false;
                break;
            }
            else
            {
                same = true;
            }
        }
        return same;
    }
    else
    {
        return false;
    }
}
boolean IsLess (TabInt T1, TabInt T2)//////
{
    boolean less;
    for(IdxType i=1;i<=Neff(T1);i++)
    {
        if (TI(T1)[i]>TI(T2)[i])
        {
            less = false;
            break;
        }
        else if (TI(T1)[i]<TI(T2)[i])
        {
            less = true;
            break;
        }
        else
        {
            less = true;
        }
        return less;
    }
}
IdxType Search1 (TabInt T, ElType X)
{
    IdxType i=1;
    if(Neff(T)==0)
    {
        return IdxUndef;
    }
    else
    {
        while (i<Neff(T) && TI(T)[i] != X)
        {
            i++;
        }
        if(i<=Neff(T)&&TI(T)[i]==X)
        {
            return i;
        }
        else
        {
            return IdxUndef;
        }

    }    
}
IdxType Search2 (TabInt T, ElType X)
{
    boolean Found = false ;
    IdxType i=1;
    if(Neff(T)==0)
    {
        return IdxUndef;
    }
    else
    {
        do
        {
            if(TI(T)[i]==X)
            {
                Found = true;
            }
            else
            {
                i++;
            }
        } while (!(Found) && i<=Neff(T));
        if (Found)
        {
            return i;
        }
        else
        {
            return IdxUndef;
        }
        
    }
    
}
boolean SearchB (TabInt T, ElType X)
{
    boolean Found = false ;
    IdxType i=1;
    if(Neff(T)==0)
    {
        return false;
    }
    else
    {
        do
        {
            if(TI(T)[i]==X)
            {
                Found = true;
            }
            else
            {
                i++;
            }
        } while (!(Found) && i<=Neff(T));
        if (Found)
        {
            return true;
        }
        else
        {
            return false;
        }      
    }
}
boolean SearchSentinel (TabInt T, ElType X)
{
    TI(T)[0] = X;
    IdxType i = 1;
    if(Neff(T)==0)
    {
        return false;
    }
    else
    {
        while (i<Neff(T) && TI(T)[i] != TI(T)[0])
        {
            i++;
        }
        if(i<=Neff(T)&&TI(T)[i]==TI(T)[0])
        {
            return true;
        }
        else
        {
            return false;
        }

    }     
}
ElType ValMax (TabInt T)
{
    IdxType i=1;
    ElType a = TI(T)[1];
    if(Neff(T)!=0)
    {
        for(i+1;i<=Neff(T);i++)
        {
            if(a<TI(T)[i])
            {
                a=TI(T)[i];
            }
        }
    }
    return a;
}
ElType ValMin (TabInt T)
{
    IdxType i=1;
    ElType a = TI(T)[1];
    if(Neff(T)!=0)
    {
        for(i=2;i<=Neff(T);i++)
        {
            if(a>TI(T)[i])
            {
                a=TI(T)[i];
            }
        }
    }
    return a;    
}
IdxType IdxMaxTab (TabInt T)
{
    ElType a;
    IdxType i;
    a = ValMax(T);
    i = Search2(T,a);
    return i;
}
IdxType IdxMinTab (TabInt T)
{
    ElType a;
    IdxType i;
    a = ValMin(T);
    i = Search2(T,a);
    return i;   
}
void CopyTab (TabInt Tin, TabInt * Tout)
{
    Tout->Neff=Neff(Tin);
    IdxType i=1;
    for (i;i<=Neff(Tin);i++)
    {
        Tout->TI[i]=TI(Tin)[i];
    }
}
TabInt InverseTab (TabInt T)
{
    TabInt Tout;
    Neff(Tout)=Neff(T);
    IdxType i=1;
    for (i;i<=Neff(T);i++)
    {
        Tout.TI[i]=TI(T)[Neff(T)+1-i];
    }
    return Tout;
}
boolean IsSimetris (TabInt T)
{
    if(Neff(T)==0)
    {
        return true;
    }
    else
    {
        return(IsEQ(T,InverseTab(T)));
    }
    
}
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
            for(j=i+1;j<=Neff(*T);j++)
            {
                if(TI(*T)[imax]<TI(*T)[j])
                {
                    imax = j;
                }
            }
            Temp = TI(*T)[imax];
            TI(*T)[imax]=TI(*T)[i];
            TI(*T)[i]=Temp;
        }
    }
}
void InsSortAsc (TabInt * T)
{
    IdxType pass,i,j;
    ElType Temp;
    if (Neff(*T)>0)
    {
        for(i=2;i<Neff(*T);i++)
        { 
            Temp = TI(*T)[i];
            j=i-1;
            while(j>0 && TI(*T)[j]>Temp)
            {
                TI(*T)[j+1] = TI(*T)[j];
                TI(*T)[j] = Temp;
                j--;
            }
        }
    }    
}
void AddAsLastEl (TabInt * T, ElType X)
{
    if(Neff(*T)!=IdxMax)
    {
        TI(*T)[Neff(*T)+1] = X;
        Neff(*T) +=1;  
    }
}
void AddEli (TabInt * T, ElType X, IdxType i)
{
    IdxType j;
    if(Neff(*T)!=0 && Neff(*T)!=IdxMax)
    {
        for (j = Neff(*T)+1;j>=i;j--)
        {
            TI(*T)[j]=TI(*T)[j-1];
        }
        TI(*T)[i]=X;
        Neff(*T)+=1;
    }
}
void DelLastEl (TabInt * T, ElType * X)
{
    if(Neff(*T)!=0)
    {
        TI(*T)[Neff(*T)]=*X;
        Neff(*T)-=1;;
    }
}
void DelEli (TabInt * T, IdxType i, ElType * X)
{
    if(Neff(*T)!=0)
    {
        TI(*T)[i]=*X;
        for (i;i<Neff(*T);i++)
        {
            TI(*T)[i]=TI(*T)[i+1];
        }
    }
    Neff(*T)-=1;
}
void AddElUnik (TabInt * T, ElType X)
{
    if(Neff(*T)!=0)
    {
        if(SearchB(*T,X))
        {
            printf("nilai sudah ada\n");
        }
        else
        {
            AddAsLastEl(&*T,X);
        }
    }
}
IdxType SearchUrut (TabInt T, ElType X)
{
    if(Neff(T)!=0)
    {
        IdxType i=1;
        while (i<Neff(T) && TI(T)[i]!=X)
        {
            if(TI(T)[i]==X)
            {
                return i;
            }
            i++;
        }
        if(TI(T)[i]!=X)
        {
            return IdxUndef;
        }
        else
        {
            return i;
        }
    }
    else
    {
        return IdxUndef;
    }
}
ElType MaxUrut (TabInt T)
{
    return (TI(T)[Neff(T)]);
}
ElType MinUrut (TabInt T)
{
    return (TI(T)[1]);
}
void MaxMinUrut (TabInt T, ElType * Max, ElType * Min)
{
    *Max = MaxUrut(T);
    *Min = MinUrut(T);
}
void Add1Urut (TabInt * T, ElType X)
{
    AddAsLastEl(&*T,X);
    InsSortAsc(&*T);
}
void Del1Urut (TabInt * T, ElType X)
{
    int i;
    i = Search1(*T,X);
    DelEli(&*T,i,&X);
}

