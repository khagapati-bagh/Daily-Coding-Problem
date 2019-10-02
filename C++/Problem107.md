# Daily Coding Problem: Problem #107 [Easy]

Good morning! Here's your coding interview problem for today.

This problem was asked by Microsoft.

Print the nodes in a binary tree level-wise. For example, the following should print 1, 2, 3, 4, 5.

  1 
 / \\
 
2   3

   / \\
   
  4   5

**Solution** : 

```cpp

#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode *left, *right;
        TreeNode(int key) : val(key), left(NULL), right(NULL) {}
};

void levelOrderTraversal(TreeNode *root){
    if(!root)   return;
    queue<TreeNode *> Q;
    Q.push(root);
    while(!Q.empty()){
        TreeNode *tmp = Q.front();
        Q.pop();
        cout<<tmp->val<<" ";
        if(tmp->left)   Q.push(tmp->left);
        if(tmp->right)   Q.push(tmp->right);
    }
    cout<<endl;
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2); 
    root->right = new TreeNode(3); 
    root->left->left = new TreeNode(4); 
    root->right->left = new TreeNode(5); 
    root->right->right = new TreeNode(6); 
    root->right->left->right = new TreeNode(7); 
    root->right->right->right = new TreeNode(8); 
    root->right->left->right->left = new TreeNode(9);
    levelOrderTraversal(root);
    return 0;
}

```
**[Run Code](https://ide.geeksforgeeks.org/FvA6qWDxWu)**
