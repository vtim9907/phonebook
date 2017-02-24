#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_hash.h"

entry *findName(char lastName[], entry *e[])
{
    unsigned int hash_index = (BKDR_hash(lastName) % TABLE_SIZE);
    entry *pHead = e[hash_index]->pNext;
    while (pHead) {
        if (strcasecmp(lastName, pHead->lastName) == 0)
            return pHead;
        pHead = pHead->pNext;
    }
    return NULL;
}

void append(char lastName[], entry *e[])
{
    unsigned int hash_index = (BKDR_hash(lastName) % TABLE_SIZE);
    e[hash_index]->pNext = (entry *) malloc(sizeof(entry));
    entry *pHead = e[hash_index]->pNext;
    strcpy(pHead->lastName, lastName);
    pHead->pNext = NULL;
    e[hash_index] = pHead;
}

unsigned int BKDR_hash(char *str)
{
    unsigned int seed = 31;
    unsigned int hash = 0;

    while (*str) {
        hash = hash * seed + (*str++);
    }

    return (hash & 0x7FFFFFFF);
}

void free_list(entry *pHead)
{
    while (pHead->pNext) {
        entry *temp = pHead->pNext;
        pHead->pNext = temp->pNext;
        free(temp);
    }
}
