#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include <string.h>


int compterCaractere (char* chaine)
{

    return  strlen(chaine);
}



int main ()
{

    char chaine[100];

    printf("\nVeuillez entrez la chaine de caractere :");
    scanf("%s",chaine);
    int res = compterCaractere (chaine);
    printf("\nLe nombre de caractere est : %d\n",res);


}