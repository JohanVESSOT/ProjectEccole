#include<stdio.h>
#include<stdlib.h>

double conversion (double x)
{
    return (x * 1.609) ;
}

int main()
{
    int x;
    double res ;
    printf("Entrer la valeur a convertir : ");
    scanf("%d",&x);
    res = conversion(x);
    printf ("La conversion vaut : %f \n",res);
}