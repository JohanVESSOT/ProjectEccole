#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


double Horraire (double horraire,double paye)
{
    if (horraire>=35)
    {
        return((35*paye)+((horraire-35)*1.5*paye));
        printf("BOITE");
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