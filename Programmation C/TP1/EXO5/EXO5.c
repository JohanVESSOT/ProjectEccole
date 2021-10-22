#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>



int main()
{
    double z ;

    int x;

    for (int i=0;i<5;i++)
    {
        scanf("%d",&x);
        z=z+x;
    }
    z=z/5;


    printf("La Valeur moyenne est %f \n",z);
    

}