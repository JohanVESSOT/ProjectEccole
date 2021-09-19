#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main ()
{
    int TailleTableau = 20 ;
    int Tab[20] = {1,2,2,5,4,0,2,1,5,0,2,5,2,5,2,5,10,0,45,0};
    int cpt = 0;
    for (cpt =0 ; cpt <TailleTableau;cpt++ )
    {
        if (Tab[cpt]==0)
        {
            printf("\nL'indice %d est un zero ",cpt);
        }
        
    }
    printf("\n");
}