#pragma once
#define MAX_LENGTH 30

//Дерево
struct avltree
{
    char* key;
    struct avltree* left;
    struct avltree* right;
    int value;
    int height;
};

int AVLTree_height(struct avltree* tree);

int max(int a, int b);

void avltree_free(struct avltree* tree);

struct avltree* newNode(char* key, int value);

int avltree_lookup(struct avltree* tree, char* key);

struct avltree* AVLTree_RRotate(struct avltree* y);

struct avltree* AVLTree_LRotate(struct avltree* x);

int AVLTree_balance(struct avltree* Node);

struct avltree* avltree_insert(struct avltree* avltree, char* key, int value);

struct avltree* minKeyAVL(struct avltree* avltree);

struct avltree* maxKeyAVL(struct avltree* avltree);

struct avltree* deleteNode(struct avltree* root, char* key);

void AVLtree_print(struct avltree* root);