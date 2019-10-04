# Daily Coding Problem: Problem #110 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

Given a binary tree, return all paths from the root to leaves.

For example, given the tree:
```
   1
  / \
 2   3
    / \
   4   5
```
Return [[1, 2], [1, 3, 4], [1, 3, 5]].

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

void print(vector<vector<int>>res){
    cout<<"[ ";
    for(int i = 0; i < res.size(); i++){
        cout<<"[";
        for(int j = 0; j < res[i].size(); j++){
            cout<<res[i][j];
            if(j < res[i].size() - 1)
                cout<<",";
        }
        cout<<"]";
        if(i < res.size() - 1)
            cout<<", ";
    }
    cout<<" ]";
}
void binaryTreePaths(TreeNode* root, vector<vector<int>>&res, vector<int>tmp){
    if(!root->left && !root->right){//leaf node
        res.push_back(tmp);
        return;
    }
    if(root->left){
        tmp.push_back(root->left->val);
        binaryTreePaths(root->left, res, tmp);
    }
    if(root->right){
        tmp.push_back(root->right->val);
        binaryTreePaths(root->right, res, tmp);
    }
}

void binaryTreePaths(TreeNode* root) {
    if(!root)   return;
    vector<vector<int>>res;
    vector<int>tmp;
    tmp.push_back(root->val);
    binaryTreePaths(root, res, tmp);
    print(res);
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
    binaryTreePaths(root);
    return 0;
}

```
**[Run Code](https://ide.geeksforgeeks.org/Ic7xmMtBU0)**
