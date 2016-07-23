#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    int k ;
    if(argc == 1)
     {
         printf("Enter <key>\n");
         return 1;
     }
    else
     {
         k = atoi(argv[1]);
         k = k % 26;
         string s = GetString();
         for(int i=0 , n=strlen(s) ; i < n ; i++)
         {
             if(s[i] >= 65 && s[i] <= 90) 
             {
                int temp = (int) s[i];
                temp = temp+k;
                if(temp>90)   { temp=temp-26;}
                printf("%c", (char) temp) ;
             }
             else if  (s[i] >= 97 && s[i] <= 122)
             {
                int temp = (int) s[i];
                temp = temp+k;
                if(temp>122)   { temp=temp-26; }
                printf("%c", (char) temp) ;
             }
            else 
            {
                printf("%c",s[i]);
            }
         }
        
     }
     printf("\n");
     return 0;
}