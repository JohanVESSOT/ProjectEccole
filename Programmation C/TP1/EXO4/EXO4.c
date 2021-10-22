#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int NbrOppose (int y)
{
    return y - (2*y);
}

double NbrMoitier (int y)
{
    return (double)y/2;
}


int main()
{
    float m ;
    int x,y;

    printf("\nSaisir la valeur de X : ");
    scanf("%d",&x) ;
    
    y = NbrOppose(x);
    m = NbrMoitier(x);

    printf("La Valeur opposé est %d \n",y);
    printf("La moitié est %lf \n\n",m);
}