#ifndef _PHONEBOOK_H
#define _PHONEBOOK_H

#define MAX_LAST_NAME_SIZE 16

#define BST 1
#define BIGNODE_BST 1
#define ENTRY_NUM 6
typedef struct __PHONE_BOOK_DETAIL {
    char lastName[MAX_LAST_NAME_SIZE];
    char firstName[16];
    char email[16];
    char phone[10];
    char cell[10];
    char addr1[16];
    char addr2[16];
    char city[16];
    char state[2];
    char zip[5];
    struct __PHONE_BOOK_DETAIL *pNext;
} entry_detail;

typedef struct __PHONE_BOOK_ENTRY {
    char lastName[MAX_LAST_NAME_SIZE];
    entry_detail *detail;
    struct __PHONE_BOOK_ENTRY *pNext;
} entry;

typedef struct __BST_NODE {
    struct __BST_NODE *left;
    struct __BST_NODE *right;
    entry *pEntry[6];
} bst;

entry *findName (char lastName[], bst *root);
bst *findnode(char lastName[], bst *root);
entry *append(char lastName[], entry *e);
bst *build_bst (entry *e);
bst *build (entry **e, int length);
#endif
