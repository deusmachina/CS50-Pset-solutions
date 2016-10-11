/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#include <string.h>

//struct used
typedef struct node
{
    char word[LENGTH+1];
    struct node* next;
}node;

//table to check beginning and end of each pointer
node* table[HASHTABLE_SIZE] = {NULL};

//word counter
int cntwrd=0;

//append to ll
void append(node* ptr, int n ,char* tmp)
{
    if(table[n]==NULL)
    {
        table[n]=ptr;
        ptr->next=NULL;
        strcpy(ptr->word,tmp);
    }
    else
    {
        ptr->next=table[n];
        table[n]=ptr;
        strcpy(ptr->word,tmp);
    }
}

//hash func SRC- cs50 discuss
int hash_it(char* needs_hashing)
{
    unsigned int hash = 0;
    for (int i=0, n=strlen(needs_hashing); i<n; i++)
        hash = (hash << 2) ^ needs_hashing[i];
    return hash % HASHTABLE_SIZE;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    char nword[LENGTH+1];
    int i,n=strlen(word);
    for(i = 0 ; i < n ; i++)
    {
        nword[i]=(char)tolower(word[i]);
    }
    nword[n] = '\0';
    n = hash_it(nword);
    node* crawler=table[n];
    while(crawler!=NULL)
    {
        if((strcmp(nword,crawler->word))==0)
            return true;
        crawler=crawler->next;
    }
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    FILE* fp=fopen(dictionary,"r");
    if(fp==NULL)
        return false;
    char tmp[LENGTH+1];
    int index=0 , n;
    node *crawler;
    for (int c = fgetc(fp); c != EOF; c = fgetc(fp))
    {
        // allow only alphabetical characters and apostrophes
        if (isalpha(c) || c == '\'')
        {
            tmp[index] = c;
            index++;
        }

        else
        {
            tmp[index] = '\0';
            cntwrd++;
            index=0;
            n = hash_it(tmp);
            crawler=malloc(sizeof(node));
            append(crawler,n,tmp);
        }
    }  
    fclose(fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return cntwrd;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    node* crawler;
    for(int i = 0; i< HASHTABLE_SIZE ;i++)
    {
        crawler=table[i];
        while(crawler!=NULL)
        {
            node* tmp=crawler;
            crawler=crawler->next;
            free(tmp);
        }
    }
    return true;
}

