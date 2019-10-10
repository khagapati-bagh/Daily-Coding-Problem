
# Daily Coding Problem: Problem #117 [Easy]

Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

Given a binary tree, return the level of the tree with minimum sum.

```
            10
           /  \
          2    3
         /    / \
        4    5   6
              \    \
               7    8
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

void dfs(TreeNode* root, vector<int>&res, int level){
    if(!root)   return;
    if(res.size() < level) res.push_back(root->val);
    else res[level - 1] += root->val;
    dfs(root->left, res, level+1);
    dfs(root->right, res, level+1);
}

int minimumLevelSum(TreeNode* root){
    vector<int>res;
    dfs(root, res, 1);
    return min_element(res.begin(), res.end()) - res.begin();
}

int main(){
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(2); 
    root->right = new TreeNode(3); 
    root->left->left = new TreeNode(4); 
    root->right->left = new TreeNode(5); 
    root->right->right = new TreeNode(6); 
    root->right->left->right = new TreeNode(7); 
    root->right->right->right = new TreeNode(8); 
    root->right->left->right->left = new TreeNode(9);
    cout<<minimumLevelSum(root)<<endl;
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/HmoQU3eRu4)**