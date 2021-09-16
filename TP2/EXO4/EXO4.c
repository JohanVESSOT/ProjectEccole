#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


int Is_Bissextile (int y)
{
    if (y%4==0)
    {
        return true ;
    }
    return false ;
}


int main()
{
    bool res ;
    int x ;
    printf("Entrer l'anné : ");
    scanf("%d",&x);
    res = Is_Bissextile(x);
    if (res)
    {
        printf("\nL'anné est paire\n");
    }
    else
    {
        printf("\nL'année est impaire\n");
    }
    
}