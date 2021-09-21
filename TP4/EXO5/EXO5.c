#include<stdio.h>
#include<stdlib.h>
#include <string.h>


typedef struct Date Date ;
struct Date
{
    int jour ;
    char Mois[100] ;
    int annee ;
};



void ModifierDate (Date* date,int jour, int anne,char* mois)
{
    (date->jour) = jour ;
    (date->annee) = anne ;
    strcpy(date->Mois,mois);
}


int main ()
{
    Date date1 ;
    char mois[15]="Juin";
    ModifierDate(&date1,10,1990,mois);
    printf("%s",date1.Mois);
}