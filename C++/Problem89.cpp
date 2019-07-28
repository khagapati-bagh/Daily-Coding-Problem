/*
Daily Coding Problem: Problem #89 [Medium]
Good morning! Here's your coding interview problem for today.

This problem was asked by LinkedIn.

Determine whether a tree is a valid binary search tree.

A binary search tree is a tree with two children, left and right, and satisfies the constraint that the key in the left child must be less than or equal to the root and the key in the right child must be greater than or equal to the root.

Example
input
2
2
1 2 R 1 3 L
4
10 20 L 10 30 R 20 40 L 20 60 R

output
0
0

*/

//You can get my code in IDE https://ide.geeksforgeeks.org/W2eeEyz8bT
#include <bits/stdc++.h>
using namespace std;
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};
/* Returns true if the given tree is a binary search tree
 (efficient version). */
bool isBST(struct Node* node);
int isBSTUtil(struct Node* node, int min, int max);
/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout << isBST(root) << endl;
  }
  return 0;
}

bool inorder(Node* root, Node* &prev)
{
    if(!root)   return true;
    
    if(!inorder(root->left, prev))  return false;
    if(prev && (root->data <= prev->data)) return false;
    prev = root;
    return inorder(root->right, prev);
}
bool isBST(Node* root) {
    // Your code here
    Node* prev = NULL;
    return inorder(root, prev);
}
