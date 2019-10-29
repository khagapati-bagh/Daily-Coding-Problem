
# Daily Coding Problem: Problem #135 [Easy]

Good morning! Here's your coding interview problem for today.

This question was asked by Apple.

Given a binary tree, find a minimum path sum from root to a leaf.

For example, the minimum path in this tree is [10, 5, 1, -1], which has sum 15.
```
      10
     /  \
    5    5
     \     \
       2    1
           /
         -1
```

**Solution** :

```cpp

#include <bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};
int minPathSum(TreeNode *root){
    if(!root)   return 999;
    int leftSum = minPathSum(root->left);
    int rightSum = minPathSum(root->right);
    if(rightSum != 999 || leftSum != 999)
        root->val +=  min(leftSum, rightSum);
    return root->val;
}

int main() {
    TreeNode* root;
    root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(5);
    root->left->right = new TreeNode(2);
    root->right->right = new TreeNode(1);
    root->right->right->left = new TreeNode(-1);
    cout<<minPathSum(root)<<endl;;
    
    TreeNode* root1 = new TreeNode(5);
    root1->left = new TreeNode(4);
    root1->right = new TreeNode(8);
    root1->left->left = new TreeNode(11);
    root1->right->left = new TreeNode(13);
    root1->right->right = new TreeNode(4);
    root1->left->left->left = new TreeNode(7);
    root1->left->left->right = new TreeNode(2);
    root1->right->right->right = new TreeNode(1);
    cout<<minPathSum(root1)<<endl;
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/S1QVvniVPf)**