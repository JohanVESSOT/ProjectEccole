#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>



int main()
{
    int x=12;
    printf("\nBoucle for : \n\n");
    for (int i=12;i<21;i++)
    {
        printf("La valeur est : %d \n",i);
    }
    printf("\nBoucle while : \n\n");
    while (x<20)
    {
        x++;
        printf("La valeur est : %d \n",x);
    }
}