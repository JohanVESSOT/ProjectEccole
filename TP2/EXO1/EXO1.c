#include<stdio.h>
#include<stdlib.h>


void Min (int x,int y,int *min)
{
    if (x<y)
    {
        *min = x ;
        return ;
    }
    *min = y ;
    return ;
}

void Max (int x,int y, int *max)
{
    if (x<y)
    {
        *max = y ;
        return ;
    }
    *max = x ;
    return ;

}

void MinMax (int *Pmin,int *Pmax,int x,int y)
{
    Min (x,y,Pmin) ;
    Max (x,y,Pmax) ;
}


int main()
{

    int min,max,x,y;


    printf ("\nVeuillez entrer la valeur de X :") ;
    scanf("%d",&x) ;

    printf ("\nVeuillez entrer la valeur de Y :") ;
    scanf("%d",&y) ;

    int *Pmin = &min ;
    int *Pmax = &max ;
    
    MinMax (Pmin,Pmax,x,y);
    printf("\nMin : %d",min);
    printf("\nMax : %d \n",max); 

}