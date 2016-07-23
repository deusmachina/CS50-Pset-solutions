#include <cs50.h>
#include <stdio.h>
int getpos()
{
    printf("Height: ");
    int n=GetInt();
    while(n<0 || n>23)
    {
        printf("Height: ");
        n=GetInt();
    }
    return n;
}
int main(void)
{
    int i,x=getpos(),k;
    if(x==0)  exit(0);
    else
    {
       for(int j=x;j>0;j--)
       {
           for(i=0;i<j-1;i++)
           {
               printf(" ");
           }
           k=x-j+2;
           while(k>0)
           {
               printf("#");
               k--;
           }
           printf("\n");
       }    
    }
}