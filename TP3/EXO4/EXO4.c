#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main ()
{
    int Tab[10] = {9,8,7,6,5,4,3,2,1,0};
    int TabInverse[10] ;
    int cpt1 = 0 ;
    int cpt2 = 9 ;

    for (cpt1 =0;cpt1<10;cpt1++)
    {
        printf("%d\n",Tab[cpt1]);
        TabInverse[cpt2]=Tab[cpt1];
        cpt2 -- ;
        printf ("%d\n",TabInverse[cpt2]);
    }
    

}