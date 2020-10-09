// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

int word_count = 0;


// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // Done
    node *cursor = table[hash(word)];
    while (cursor != NULL)
    {
        if (strcasecmp(word, cursor->word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // done
    // https://stackoverflow.com/questions/31930046/what-is-a-hash-table-and-how-do-you-make-it-in-c
    return tolower(word[0]) - 'a';

}




// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // done

    FILE *file = fopen(dictionary, "r");
    if (file == NULL) //check for error and return false if something got wrong
    {
        return false;
    }

    char word[LENGTH + 1];
    while (fscanf(file, "%s", word) != EOF)
    {
        // create a new node
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            unload();
            return false;
        }

        // make new node by copying the word and setting next to NULL
        strcpy(new_node->word, word);
        new_node->next = NULL;

        // каждому слову назначаю номер в зависимости от первой буквы
        int h = hash(new_node->word);

        node *head = table[h];

        //if table is empty, set new_node
        if (head == NULL)
        {
            table[h] = new_node;
            word_count++;
        }
        else // if table is not empty, set next pointer to table[h], and table[h] to new node
        {
            new_node->next = table[h];
            table[h] = new_node;
            word_count++;
        }
    }

    fclose(file);
    // printf("word_count: %i\n", word_count);
    return true;
}


// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // done
    return word_count;
}




// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // done
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
        free(cursor);
    }
    return true;
}
