
# Daily Coding Problem: Problem #133 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Amazon.

Given a node in a binary search tree, return the next bigger element, also known as the inorder successor.

For example, the inorder successor of 22 is 30.
```
       10
      /  \
     5    30
         /  \
       22    35
```
You can assume each node has a parent pointer.

**Solution** :

```cpp

#include <stdio.h> 
#include <stdlib.h> 

/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct node 
{ 
    int data; 
    struct node* left; 
    struct node* right; 
    struct node* parent; 
}; 

struct node * minValue(struct node* node); 

struct node * inOrderSuccessor(struct node *root, struct node *n) 
{ 
// step 1 of the above algorithm 
if( n->right != NULL ) 
    return minValue(n->right); 

// step 2 of the above algorithm 
struct node *p = n->parent; 
while(p != NULL && n == p->right) 
{ 
    n = p; 
    p = p->parent; 
} 
return p; 
} 

struct node * minValue(struct node* node) { 
    struct node* current = node; 
    
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) { 
        current = current->left; 
    } 
    return current; 
} 

/* Helper function that allocates a new node with the given data and 
    NULL left and right pointers. */
struct node* newNode(int data) 
{ 
    struct node* node = (struct node*) 
                        malloc(sizeof(struct node)); 
    node->data = data; 
    node->left = NULL; 
    node->right = NULL; 
    node->parent = NULL; 
        
    return(node); 
} 

/* Give a binary search tree and a number, inserts a new node with   
    the given number in the correct place in the tree. Returns the new 
    root pointer which the caller should then use (the standard trick to 
    avoid using reference parameters). */
struct node* insert(struct node* node, int data) 
{ 
    /* 1. If the tree is empty, return a new, 
        single node */
    if (node == NULL) 
        return(newNode(data)); 
    else
    { 
        struct node *temp; 
    
        /* 2. Otherwise, recur down the tree */
        if (data <= node->data) 
        {    
            temp = insert(node->left, data); 
            node->left = temp; 
            temp->parent= node; 
        } 
        else
        { 
            temp = insert(node->right, data); 
            node->right = temp; 
            temp->parent = node; 
        }    
    
        /* return the (unchanged) node pointer */
        return node; 
    } 
} 
void successor(node *root, node *temp){
    node *succ = inOrderSuccessor(root, temp); 
    if(succ != NULL) 
        printf("Inorder Successor of %d is %d\n", temp->data, succ->data);   
    else
        printf("Inorder Successor doesn't exit\n"); 
}
/* Driver program to test above functions*/
int main() 
{ 
    struct node* root = NULL, *temp, *succ, *min; 
    
    //creating the tree given in the above diagram 
    root = insert(root, 20); 
    root = insert(root, 8); 
    root = insert(root, 22); 
    root = insert(root, 4); 
    root = insert(root, 12); 
    root = insert(root, 10); 
    root = insert(root, 14);     
    temp = root->left->right->right; 
    successor(root, root->left->right->right);
    successor(root, root->left->left);
    //successor(root, root->left->right->right->right);
    return 0; 
} 


```

**[Run Code](https://ide.geeksforgeeks.org/urQYNevTao)**