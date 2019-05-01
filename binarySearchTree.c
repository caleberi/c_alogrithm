#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    // value of a node
    int value;
    // pointer to another node
    struct Node *left_child;
    // pointer to the previous node
    struct Node *right_child;
};

// an alias for node
typedef struct Node Node;

// binary tree structure
struct BST
{
    // node pointer
    Node *nroot;
    // bst size;
    int size;
};

// an alias for binary search tree
typedef struct BST BST;

// create a binary search tree
BST *createBST()
{
    BST *t = (BST *)malloc(sizeof(BST *));
    t->nroot = NULL;
    t->size = 0;
    return t;
}

// create rootNode or else attach the newNode
void insert(BST *b, int value)
{
    Node *nodeDelete = (Node *)malloc(sizeof(Node *));
    nodeDelete->value = value;
    nodeDelete->left_child = nodeDelete->right_child = NULL;
    if (b->nroot == NULL)
    {
        b->nroot = nodeDelete;
        b->size++;
    }
    Node *root = b->nroot;
    while (true)
    {
        if (value < root->value)
        {
            if (root->left_child == NULL)
            {
                root->left_child = nodeDelete;
                b->size++;
                return;
            }
            else
            {
                root = root->left_child;
            }
        }
        else if (value > root->value)
        {

            if (root->right_child == NULL)
            {
                root->right_child = nodeDelete;
                b->size++;
                return;
            }
            else
            {
                root = root->right_child;
            }
        }
        else
        {
            break;
        };
    }
}

bool contains(BST *b, Node *root, int value)
{
    if (root == NULL)
    {
        return false;
    }
    if (root->value == value)
    {
        return true;
    }
    else if (value < root->value)
    {
        root = root->left_child;
        return contains(b, root, value);
    }
    else if (value > root->value)
    {
        root = root->right_child;
        return contains(b, root, value);
    }
    else
    {
        return false;
    }
};

// Node *findParent(BST *b,Node *nodeDelete, int value)
// {
//     if (value == b->nroot->value)
//     {
//         return NULL;
//     }
//     if (value < b->nroot->value)
//     {
//         if (b->nroot->left_child == NULL)
//         {
//             return NULL;
//         }
//         else if (b->nroot->left_child->value == nodeDelete->value && b->nroot->left_child->value == value)
//         {
//             return b->nroot;
//         }
//         else
//         {
//             return findParent(b,nodeDelete, value);
//         }
//     }
//     else
//     {
//         if (b->nroot->right_child == NULL)
//         {
//             return NULL;
//         }
//         else if (b->nroot->right_child->value == nodeDelete->value && b->nroot->right_child->value == value)
//         {
//             return b->nroot;
//         }
//         else
//         {
//             return findParent(b,nodeDelete, value);
//         }
//     }
// };

Node *findNode(BST *b, Node *root, int value)
{
    if (b->nroot == NULL)
    {
        return NULL;
    }
    if (b->nroot->value == value)
    {
        return b->nroot;
    }
    else if (value < b->nroot->value)
    {
        b->nroot = b->nroot->left_child;
        return findNode(b, b->nroot, value);
    }
    else
    {
        b->nroot = b->nroot->right_child;
        return findNode(b, b->nroot, value);
    }
};

// bool erase(BST *b, int value)
// {
//     Node *nodeDelete = (Node *)malloc(sizeof(Node *));
//     nodeDelete = findNode(b, b->nroot, value);
//     if (nodeDelete == NULL)
//     {
//         return false;
//     };

//     Node *parent = (Node *)malloc(sizeof(Node *));
//     parent = findParent(b,nodeDelete, value);

//     if (b->size == 1 && b->nroot->value == value)
//     {
//         free(b->nroot);
//         b->nroot = NULL;
//     }
//     else if (nodeDelete->left_child == NULL && nodeDelete->right_child == NULL)
//     {
//         if (nodeDelete->value < parent->value)
//         {
//             parent->left_child = NULL;
//         }
//         else
//         {
//             parent->right_child = NULL;
//         }
//     }
//     else if (nodeDelete->left_child == NULL && nodeDelete->right_child != NULL)
//     {
//         if (nodeDelete->value < parent->value)
//         {
//             parent->left_child = nodeDelete->right_child;
//         }
//         else
//         {
//             parent->right_child = parent->left_child;
//         }
//     }
//     else if (nodeDelete->left_child != NULL && nodeDelete->right_child == NULL)
//     {
//         if (nodeDelete->value < parent->value)
//         {
//             parent->left_child = nodeDelete->left_child;
//         }
//         else
//         {
//             parent->right_child = nodeDelete->left_child;
//         }
//     }
//     else
//     {
//         Node *largest = (Node *)malloc(sizeof(Node *));
//         while (largest->right_child != NULL)
//         {
//             largest = largest->right_child;
//         }
//         findParent(b,nodeDelete, largest->value)->right_child = NULL;
//         nodeDelete->value = largest->value;
//         b->size--;
//     }
//     return true;
// };

void print_Tree(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    print_Tree(root->left_child);
    printf("%d\t\n", root->value);
    print_Tree(root->right_child);
}

int min(BST *b, Node *root)
{
    if (b->nroot->left_child == NULL)
    {
        return b->nroot->value;
    }
    b->nroot = b->nroot->left_child;
    return min(b, b->nroot);
};

int max(BST *b, Node *root)
{
    if (b->nroot->right_child == NULL)
    {
        return b->nroot->value;
    }
    b->nroot = b->nroot->right_child;
    return max(b, b->nroot);
};

void pre_order(BST *b, Node *root)
{
    if (root != NULL)
    {
        printf("\t%d\n", root->value);
        pre_order(b, root->left_child);
        pre_order(b, root->right_child);
    }
};

void post_order(BST *b, Node *root)
{
    if (root != NULL)
    {
        post_order(b, root->left_child);
        post_order(b, root->right_child);
        printf("\t%d\n", root->value);
    }
};

void in_order(BST *b, Node *root)
{
    if (root != NULL)
    {
        in_order(b, root->left_child);
        printf("\t%d\n",root->value);
        in_order(b, root->right_child);
    }
};

// void breadthFirst(BST *b,Node *root){
//     // create a queue instance 
//     while(root!=NULL){
//         printf("%d",root->value);
//         if(root->left_child != NULL){
//             q->enqueue(root->left_child);
//         }
//         if(root->right_child != NULL){
//             q->enqueue(root->right_child);
//         }
//         if(!q->isEmpty(q)){
//             q->enqueue(root->left_child);
//         }
//         else
//         {
//             root = NULL;
//         }
        
//     }
// };

int main()
{
    BST *b = createBST();

    insert(b, 5);
    insert(b, 9);
    insert(b, 10);
    insert(b, 2);
    insert(b, 16);
    insert(b, 20);
    // insert(b, 2);

    Node *nroot = b->nroot;
    in_order(b, nroot);
    return 0;
}