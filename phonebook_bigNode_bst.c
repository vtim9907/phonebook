#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "phonebook_bigNode_bst.h"

entry *findName(char lastName[], bst *root)
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

bst *findnode(char lastName[], bst *root)
{
    while (root) {
        int val, node_num = ENTRY_NUM;
        do {
            if (root->pEntry[node_num--]) {
                if (!(val = strcasecmp(lastName, root->pEntry[node_num]->lastName)))
                    return root;
            }
        } while (node_num);
        if (val < 0)
            root = root->left;
        else
            root = root->right;
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

bst *build_bst(entry *e)
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

bst *build(entry **e, int length)
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
