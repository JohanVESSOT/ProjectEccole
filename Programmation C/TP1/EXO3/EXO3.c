#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>


int R_pair (int y)
{
    if (y%2==0)
    {
        return true ;
    }
    return false ;
}


int main()
{
    bool Res ;
    int x;

    printf("\nSaisir la valeur de X : ");
    scanf("%d",&x) ;
    
    Res = R_pair(x);

    if (Res)
    {
        printf("La Valeur saisi : %d est paire \n",x);
    }
    else 
    {
        printf("La Valeur de X saisi (%d) est impaire \n\n",x);
    }

}