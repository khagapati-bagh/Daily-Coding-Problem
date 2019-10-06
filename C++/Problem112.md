# Daily Coding Problem: Problem #112 [Hard]

Good morning! Here's your coding interview problem for today.

This problem was asked by Twitter.

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree. Assume that each node in the tree also has a pointer to its parent.

According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be a descendant of itself).”

```
           1
          / \
         2   3
        /   / \
       4   5   6
            \   \
             7   8
            /
           9
```

**Solution** : 

```cpp

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode *left, *right;
        TreeNode(int key) : val(key), left(NULL), right(NULL) {}
};

TreeNode* LCA(TreeNode* root, TreeNode* p, TreeNode* q){
    if(!root || root == p || root == q) return root;
    TreeNode* left_child = LCA(root->left, p, q);
    TreeNode* right_child = LCA(root->right, p, q);
    return !left_child ? right_child : (!right_child ? left_child : root);
}

int main(){
    TreeNode* root = new TreeNode(1);
    TreeNode* x, *y;
    root->left = new TreeNode(2); 
    root->right = new TreeNode(3); 
    root->left->left = new TreeNode(4); 
    x = root->right->left = new TreeNode(5); 
    root->right->right = new TreeNode(6); 
    root->right->left->right = new TreeNode(7); 
    root->right->right->right = new TreeNode(8); 
    y = root->right->left->right->left = new TreeNode(9);
    
    x = LCA(root, x, y);
    cout<<x->val<<endl;
    return 0;
}

```
**[Run Code](https://ide.geeksforgeeks.org/NwlsZoG9u7)**
