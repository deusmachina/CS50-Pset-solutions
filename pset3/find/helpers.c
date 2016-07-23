/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool binsearch(int x,int values[],int min , int max)
{
    int mid=(min+max)/2;
    if(min>max)   return false;
    if(values[mid]==x)  
      return true;
    else if(x>values[mid])
      return binsearch(x,values,mid+1,max);
    else
      return binsearch(x,values,min,mid-1);
}  
bool search(int value, int values[], int n)
{
    if(n<0)
     return false ;
    else 
    {
        return binsearch(value,values,0,n);
    }
}
  
/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
   int element , j;
   for(int i=1 ; i< n ;i++)
   {
       element =  values[i];
       j = i;
       while(j>0 && values[j-1] > element)
       {
           values[j] = values [j-1];
           j=j-1;
       }
       values[j] = element;
   }
}