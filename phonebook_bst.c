#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_bst.h"

bst *findName(char lastName[], bst *root)
{
    int val;
    bst *tmp = root;
    while (tmp) {
        if ((val = strcasecmp(lastName, tmp->pEntry->lastName)) == 0)
            return tmp;
        else if (val < 0)
            tmp = tmp->left;
        else
            tmp = tmp->right;
    }
    return NULL;
}

entry *append(char lastName[], entry *e)
{
    e->pNext = (entry *) malloc(sizeof(entry));
    e = e->pNext;
    strcpy(e->lastName, lastName);
    e->pNext = NULL;

    return e;
}

bst *build_bst (entry *e)
{
    int countLength = 0;
    entry *tmp = e;
    while (tmp) {
        countLength++;
        tmp = tmp->pNext;
    }
    return build(&e, countLength);
}

bst *build (entry **e, int length)
{
    if (length <= 0)
        return NULL;
    bst *left = build(e, length/2);
    bst *root = (bst *) malloc(sizeof(bst));
    root->left = left;
    root->pEntry = *e;
    *e = (*e)->pNext;
    root->right = build(e, length - length/2 - 1);
    return root;
}
