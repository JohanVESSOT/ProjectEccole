#include<stdio.h>
#include<stdlib.h>
#include <string.h>



void declaration (int *pTab, int *pTabRes,int tailleTab)
{
    int cpt1=0,cpt2=0;
    for (cpt1;cpt1<tailleTab;cpt1++)
    {
        if (*(pTab+cpt1)>0)
        {
            *(pTabRes+cpt2) = *(pTab+cpt1);
            cpt2++;
        }
    }
}



int main ()
{
    int Tab [10] = {-1,5,0,7,-3,4,0,-2,9,-6};
    int TabRes [10] = {0,0,0,0,0,0,0,0,0,0};
    declaration(&Tab[0],&TabRes[0],10);
    for (int i =0;i<4;i++)
    {
        printf("%d ",TabRes[i]);
    }
}