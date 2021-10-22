#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>



double PuissanceIterratif (int nombre,int puissance)
{
    int i ;
    double res;
    for (i=1;i<puissance;i++)
    {
        res = res*res ;
    }
}

double PuissanceRecursif (double horraire,double paye)
{
    if (horraire>=35)
    {
        return((35*paye)+((horraire-35)*1.5*paye));
    }
    return (horraire*paye) ;
}




int main()
{
    float res ;
    float horraire,paye ;
    printf("Entrer les horraire effectué : ");
    scanf("%f",&horraire);
    printf("Entrer la paye effectué : ");
    scanf("%f",&paye);

    res = Horraire(horraire,paye);
    printf("\nLa paye sera de : %f\n",res);
}