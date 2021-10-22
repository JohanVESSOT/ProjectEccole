#include<stdio.h>
#include<stdlib.h>
#include <string.h>


int compterCaractere (char* chaine)
{
    return  strlen(chaine);
}

char returnVariable (char var)
{
    return var ;
}


void retournerMot(char* chaine,char* res)
{
    int i = 0 ;
    char lettre ;
    int length = compterCaractere(chaine);
    printf("\nLe mot a retourner est : %c\n",chaine[2]);
    printf("\nLa longeur est : %d\n",length);
    for (length;length>0;length--)
    {
        lettre = chaine[length-1];
        res[i]= lettre;
        i++ ;
    }
}


void main ()
{
    char chaine[50], res[50]={0};
    printf("\nVeuillez entrez la chaine de caractere :");
    scanf("%s",chaine);
    retournerMot (chaine,res);
    printf("\nLe mot retourner est : %s\n\n",res);
}