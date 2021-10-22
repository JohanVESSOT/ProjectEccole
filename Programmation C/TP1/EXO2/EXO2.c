#include<stdio.h>
#include<stdlib.h>


int produit (int x,int y)
{
    return x*y ;
}


int main()
{
    int x,y,z ;
    printf("\nSaisir la valeur de X :");
    scanf("%d",&x) ;
    printf("\nSaisir la valeur de y :");
    scanf("%d",&y) ;
    z = produit(x,y);
    printf("\nLa valeur du produit est : %d\n\n",z);
}