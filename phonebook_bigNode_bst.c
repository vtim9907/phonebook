#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_bigNode_bst.h"

entry *findName (char lastName[], bst *root)
{
    int count;
    bst *result = findnode(lastName, root);
    if (result) {
        count = -1;
        while (++count < ENTRY_NUM) {
            if (strcasecmp(lastName, result->pEntry[count]->lastName) == 0)
                return result->pEntry[count];
        }
    }
    return NULL;
}

bst *findnode (char lastName[], bst *root)
{
    int val, count;
    bst *tmp = root;
    while (tmp) {
        count = -1;
        while (++count < ENTRY_NUM) {
            if (tmp->pEntry[count]) {
                if ((val = strcasecmp(lastName, tmp->pEntry[count]->lastName)) == 0)
                    return tmp;
            }
        }
        if (val < 0)
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
    if (countLength % ENTRY_NUM)
        return build(&e, countLength / 6 + 1);
    return build(&e, countLength / 6);
}

bst *build (entry **e, int length)
{
    int count = -1;
    if (length <= 0)
        return NULL;
    bst *left = build(e, length/2);
    bst *root = (bst *) malloc(sizeof(bst));
    root->left = left;
    while (++count < ENTRY_NUM) {
        if ((*e)->pNext) {
            root->pEntry[count] = *e;
            *e = (*e)->pNext;
        } else
            root->pEntry[count] = NULL;
    }
    root->right = build(e, length - length/2 - 1);
    return root;
}
