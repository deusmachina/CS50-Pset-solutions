#include <cs50.h>
#include <math.h>
#include <stdio.h>
float getpos()
{
    printf("O hai! How much change is owed?\n");
    float p=GetFloat();
    while(p<0)
    {
        printf("How much change is owed?\n");
        p=GetFloat();
    }
    return p;
}
int main(void)
{
   float f=getpos(),p1;
   int r,c=0,p;
   r=f;
   f=f-r;
   p1=f*100;
   p=round(p1);
   while(p!=0)
    {
     if(p>=25)  {p=p-25;  c++;}
    else if(p>=10)  {p=p-10;  c++;}
    else if(p>=5)  {p=p-5;  c++;}
    else if(p>=1)  {p=p-1;  c++;}
    }
    c=c+(r*4);
   printf("%i\n",c);
}