#include<stdio.h>
#include<stdlib.h>
#include <string.h>


enum ARC_EN_CIEL 
{
    RED,
    ORANGE,
    YELLOW,
    GREEN,
    BLUE,
    INDIGO,
    PURPLE
};


int main ()
{
    enum ARC_EN_CIEL A1 = GREEN ;
    switch (A1)
    {
    case (0):
        printf("\nRED\n");
        break;
    case (1):
        printf("\nORANGE\n");
        break;
    case (2):
        printf("\nYELLOW\n");
        break;
    case (3):
        printf("\nGREEN\n");
        break;
    case (4):
        printf("\nBLUE\n");
        break;
    case (5):
        printf("\nINDIGO\n");
        break;
    case (6):
        printf("\nPURPLE\n");
        break;
    default:
        break;
    }
}

