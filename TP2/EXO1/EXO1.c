#include<stdio.h>
#include<stdlib.h>

int min (int x,int y)
{
    if (x<y)
    {
        return x;
    }
    return y ;

}

int max (int x,int y)
{
    if (x<y)
    {
        return y;
    }
    return x ;

}

void MinMax (int* Tab,int x,int y)
{
    Tab[0]=min(x,y);
    Tab[1]=max(x,y);
}


int main()
{

    int x,y ;
    int Tab[2] ;

    printf("\nSaisir la valeur de x :");
    scanf("%d",&x);
    printf("\nSaisir la valeur de y :");
    scanf("%d",&y);
    printf("\n");

    MinMax(&Tab,x,y);

    printf("\nLa valeur min est : %d \n",Tab[0]);
    printf("\nLa valeur max est : %d \n",Tab[1]);
 
}