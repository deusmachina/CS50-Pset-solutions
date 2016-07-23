#include <cs50.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
    string name = GetString();
    int temp = (int) name[0];
    if(temp >=  97)  
      printf("%c", (char) temp - 32);
    else 
      printf("%c" , name[0]);
    for(int i=1, n=strlen(name) ; i<n ; i++)
    {
        if(name[i]==' ')
        {
            i++;
            temp = (int) name[i];
            if(temp >=  97)  
              printf("%c", (char) temp - 32);
            else 
              printf("%c" , name[i]);
        }
    }
    printf("\n");
}