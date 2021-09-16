#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


double Volume (double y)
{
    return (3.14*y*y*y*1.3);
}


int main()
{
    double res = Volume();
    printf("Le resultat est : %lf\n",res);
}