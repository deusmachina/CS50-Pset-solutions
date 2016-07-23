#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc , string argv[])

{
    if(argc==1||argc>=3)
    {
      printf("Enter <alphabetical key>\n");  
      return 1;
    }
    else 
    {
        int m = strlen(argv[1]);
        int k[m];
        for(int i=0 ;i < m; i++)
        {
           if(argv[1][i]>=65 && argv[1][i]<=90)
           {
               k[i] = (int) argv[1][i]- 65;
           }
           else if(argv[1][i]>=97 && argv[1][i]<= 122)
           {
               k[i] = (int) argv[1][i]-97;
           }
           else
           {
               printf("Enter <alphabetical key>\n");
               return 1;
           }
        }
        
        string s = GetString();
        int temp , j=0 ;
        for(int i=0 , n=strlen(s); i<n; i++)
        {
            if(j==m)  j=0;
            if(s[i] >= 65 && s[i] <= 90) 
             {
                temp = (int) s[i];
                temp = temp+k[j];
                if(temp>90)   { temp=temp-26;}
                printf("%c", (char) temp) ;
                j++;
             }
             else if  (s[i] >= 97 && s[i] <= 122)
             {
                temp = (int) s[i];
                temp = temp+k[j];
                if(temp>122)   { temp=temp-26; }
                printf("%c", (char) temp) ;
                j++;
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