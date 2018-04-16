/**
 * Implements a dictionary's functionality.
 */
#include <cs50.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>
#include "dictionary.h"
#include <ctype.h>
#define SIZE 65536

typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;
node *hashtable[SIZE];

unsigned int count = 0;

/**
 * Hash function is taken from reddit user delipity:
 * https://www.reddit.com/r/cs50/comments/1x6vc8/pset6_trie_vs_hashtable/cf9nlkn
 */
int hash_it(char* needs_hashing)
{
    unsigned int hash = 0;
    for (int i=0, n=strlen(needs_hashing); i<n; i++)
        hash = (hash << 2) ^ needs_hashing[i];
    return hash % SIZE;
}

/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char *word)
{
    int len = strlen(word);
    char wc[len + 1];
    for (int i = 0; i < len; i++)
    {
       wc[i] = tolower(word[i]);
    }
    wc[len] = '\0';
    int h = hash_it(wc);
    node* point = hashtable[h];
    while (point != NULL)
    {
        if (strcmp(point -> word, wc) == 0)
        {
            return true;
        }
        else
        {
            point = point -> next;
        }
    }
    return false;
}

bool loaded = false;
/**
 * Loads dictionary into memory. Returns true if successful else false.
 */
bool load(const char *dictionary)
{
    int i;
    for(i = 0; i < SIZE; i++)
    {
        hashtable[i] = NULL;
    }
    FILE *fp = fopen(dictionary, "r");
    if(fp == NULL)
    {
        printf("Could not open file\n");
        return false;
    }
    while(true)
    {
        node* new_node = malloc(sizeof(node));
        if(new_node == NULL)
        {
            printf("Could not create a new node\n");
            return false;
        }
        fscanf(fp, "%s", new_node -> word);
        new_node -> next = NULL;
        if(feof(fp))
        {
            free(new_node);
            break;
        }
        count ++;
        int h = hash_it(new_node->word);
        node* top = hashtable[h];
        if (top == NULL)
        {
            hashtable[h] = new_node;
        }
        else
        {
            new_node->next = hashtable[h];
            hashtable[h] = new_node;
        }
    }
    fclose(fp);
    loaded = true;
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    if (loaded)
        return count;
    else
        return 0;
}

/**
 * Unloads dictionary from memory. Returns true if successful else false.
 */
bool unload(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        node* cursor = hashtable[i];
        while (cursor != NULL)
        {
            node* temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    loaded = false;
    return true;
}