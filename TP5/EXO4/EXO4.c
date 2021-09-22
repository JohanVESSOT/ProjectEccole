#include<stdio.h>
#include<stdlib.h>
#include <string.h>


int Comparatif (int *pTab,int val,int tailletableau)
{
    int res =0, cpt=0 ;
    for (cpt;cpt<tailletableau;cpt++)
    {
        if ( (*(pTab+cpt)) == val )
        {
            res ++ ;
        }
    }
    return res ;
}




int main ()
{
   int Tab [10] = {5,10,15,14,89,15,15,18,10,5};
   int aChercher = 0 ;

   printf("\nEntrer l'entier a chercher dans le tableau : ") ;
   scanf("%d",&aChercher);
   int res = Comparatif(&Tab[0],aChercher,10);
   printf("\nIl y a %d nombre de fois la valeur %d dans le tableau\n",res,aChercher);
}