#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int MinMaxTab (int *PTableau,int tailleTableau)
{
    int min = *PTableau , max = *PTableau , cpt = 1;

    for (cpt;cpt < tailleTableau;cpt ++)
    {
        if (*(PTableau+cpt)<min)
        {
            min = *(PTableau+cpt);
        }
        if (*(PTableau+cpt)>max)
        {
            max = *(PTableau+cpt);
        }
    }
    printf ("Max : %d ---- Min : %d \n",max,min);


}

int main ()
{
    int TailleTableau = 11 ;
    int Tab[11] = {4,4,3,1,70,7,9,5,20,10,45} ;

    MinMaxTab(&Tab[0],11);
}