#include <stdio.h>
#include <stdlib.h>

/* Dynamically allocated binary tree 
 * Space dynamically allocated/reallocated when a node is inserted/removed. */

typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} Node;

Node *create_node(int key, Node *left, Node *right) {
    Node *np;
    if ((np = malloc(sizeof(Node))) == NULL) {
        printf("Out of memory!\n");
        exit(1);
    } else {
        np->key = key;
        np->left = left;
        np->right = right;
        return np;
    }
}

void insert(int key, Node **tree) {
    /* Why do we use a pointer to a pointer for tree? 
     * If we were to just use a single pointer to a Node, 
     * then we are passing the pointer address by value - 
     * our changes to tree (a pointer) don't transfer over to code in main. */
    if ((*tree) == NULL) {
        *tree = create_node(key, NULL, NULL);
    } else if (key <= (*tree)->key) insert(key, &((*tree)->left));
    else insert(key, &((*tree)->right));
}

void main() {
    /*  10
     *  /\ 
     * 5 16
     *   /
     *  11 
     */ 
    Node *root = NULL;
    insert(10, &root);
    insert(16, &root);
    insert(5, &root);
    insert(11, &root);
}