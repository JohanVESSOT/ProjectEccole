#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main ()
{

    int cpt , sommeTab=0, tailleTableau ;

    printf("Entrez la taille du Tableau : ") ;
    scanf("%d",&tailleTableau) ;
    printf ("\n");


    int Tab[tailleTableau] ;

    for (cpt = 0 ; cpt <tailleTableau;cpt++)
    {
        Tab[cpt] = 1 ;
        sommeTab =sommeTab+Tab[cpt] ;
    }


    printf("La somme du Tableau vaut : %d\n",sommeTab);

}