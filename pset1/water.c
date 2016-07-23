#include <cs50.h>
#include <stdio.h>
int main(void)
{
    printf("minutes: ");
    int x=GetInt();
    printf("bottles: %i\n",(x*12));
}