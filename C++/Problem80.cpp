/*
Daily Coding Problem: Problem #80 [Easy]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given the root of a binary tree, return a deepest node. For example, in the following tree, return d.

    a
   / \
  b   c
 /
d

output
9

*/
//You can get my code in IDE https://ide.geeksforgeeks.org/HAnuNLXUCF
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class TreeNode{
public:
    int val;
    TreeNode *left, *right;
    TreeNode(int key){
        val = key;
        left = right = NULL;
    }
};

int height(TreeNode* root)
{
    if(!root)   return 0;
    int left_height = 1 + height(root->left);
    int right_height = 1 + height(root->right);
    return max(left_height, right_height);
}

void depest_node(TreeNode* root, int level)
{
    if(!root)   return;
    if(level == 1)  cout<<root->val<<endl;
    if(level > 1)
    {
        depest_node(root->left, level - 1);
        depest_node(root->right, level - 1);
    }
}
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2); 
    root->right = new TreeNode(3); 
    root->left->left = new TreeNode(4); 
    root->right->left = new TreeNode(5); 
    root->right->right = new TreeNode(6); 
    root->right->left->right = new TreeNode(7); 
    root->right->right->right = new TreeNode(8); 
    root->right->left->right->left = new TreeNode(9);
    int level = height(root);
    //cout<<level<<endl;
    depest_node(root, level);
    return 0;
}