/*
Daily Coding Problem: Problem #83 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Invert a binary tree.

For example, given the following tree:

    a
   / \
  b   c
 / \  /
d   e f
should become:

  a
 / \
 c  b
 \  / \
  f e  d

Example
input
2
6
a b c d e f null
6
4 2 7 1 null 6

output
Before : a b d e c f 
After  : a c f b e d 
Before : 4 2 1 7 6 
After  : 4 7 6 2 1 

*/
//You can get my code in IDE https://ide.geeksforgeeks.org/YnYMEUeNCC
//This code will take O(n) Time and O(h) Space complexity


#include <bits/stdc++.h>
using namespace std;

struct TreeNode{
    string val;
    TreeNode *left, *right;
    TreeNode(string x): val(x), left(NULL), right(NULL){}
};

void display(TreeNode* root)
{
    if(!root)   return;
    cout<<root->val<<" ";
    display(root->left);
    display(root->right);
}

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)   return nullptr;
        TreeNode* left_child = root->left, *right_child = root->right;
        root->left = invertTree(right_child);
        root->right = invertTree(left_child);
        return root;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        getchar();
        int n;
        cin>>n;
        TreeNode* root;
        string x, y;
        cin>>x;
        root = new TreeNode(x);
        queue<TreeNode*>Q;
        Q.push(root);
        for(int i = 0; i < n/2; i++)
        {
            cin>>x>>y;
            TreeNode *tmp = Q.front();
            Q.pop();
            if(x != "null")
            {
                tmp->left = new TreeNode(x);
                Q.push(tmp->left);
            }
            if(y != "null"){
                tmp->right = new TreeNode(y);
                Q.push(tmp->right);
            }
        }
        cout<<"Before : ";
        display(root);
        cout<<endl;
        Solution obj;
        root = obj.invertTree(root);
        cout<<"After  : ";
        display(root);
        cout<<endl;
    }
    return 0;
}