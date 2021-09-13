#include<stdio.h>
#include<stdlib.h>

int main()
{
    int x, y, z ;
    x = -3 + 4 * 5 - 6 ;
    printf("%d\n", x) ;
    x = 3 + 4 % 5 - 6 ;
    printf("%d\n", x) ;
    x = -3 * 4 % -6 / 5 ;
    printf("%d\n", x) ;
    x = (7 + 6) % 5 / 2 ;
    printf("%d\n", x) ;
    x = 2 ;
    x *= 3 + 2 ;
    printf("%d\n", x) ;
    x *= y = z = 4 ;
    printf("%d\n", x) ;
}