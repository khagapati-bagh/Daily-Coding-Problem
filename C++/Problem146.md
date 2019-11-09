
# Daily Coding Problem: Problem #146 [Medium]

Good morning! Here's your coding interview problem for today.

This question was asked by BufferBox.

Given a binary tree where all nodes are either 0 or 1, prune the tree so that subtrees containing all 0s are removed.

For example, given the following tree:
```
   0
  / \
 1   0
    / \
   1   0
  / \
 0   0
 ````
should be pruned to:
```
   0
  / \
 1   0
    /
   1
```
We do not remove the tree at the root or its left child because it still has a 1 as a descendant.

**Solution** :

```cpp

#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    struct TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL){}
};
void inorder(TreeNode *root){
    if(!root)
        return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}
TreeNode *prune(TreeNode *root){
    if(!root)
        return root;
    if(!root->left && !root->right){
        if(root->val == 0)
            return NULL;
        else 
            return root;
    }
    root->left = prune(root->left);
    root->right = prune(root->right);
    return root;
}
int main() {
    TreeNode *root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(0);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(0);
    root->right->left->left = new TreeNode(0);
    root->right->left->right = new TreeNode(0);
    cout<<"Before prune : ";
    inorder(root);
    cout<<endl;
    prune(root);
    cout<<"After  prune : ";
    inorder(root);
    cout<<endl;
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/0htr6WCWsu)**