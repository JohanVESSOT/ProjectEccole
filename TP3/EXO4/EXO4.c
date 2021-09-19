#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


void TabInverseFunction (int *Ptableau,int *PtableauInverse)
{
    int cpt = 0 ;
    int cpt2 = 9 ;
    for (cpt ; cpt <10 ; cpt++)
    {
        *(PtableauInverse+cpt2) = *(Ptableau+cpt) ; 
        cpt2-- ;
    }
}



int main ()
{
    int Tab [10] = {9,8,7,6,5,4,3,2,1,0} ;
    int TabInverse [10]= {0,0,0,0,0,0,0,0,0,0} ;
    TabInverseFunction(&Tab[0],&TabInverse[0]);
    for (int i =0 ;i<10 ;i++)
    {
        printf("%d\n",TabInverse[i]);
    }
}