/*
Daily Coding Problem: Problem #48 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given pre-order and in-order traversals of a binary tree, write a function to reconstruct the tree.

For example, given the following preorder traversal:

[a, b, d, e, c, f, g]

And the following inorder traversal:

[d, b, e, a, f, c, g]

You should return the following tree:

    a
   / \
  b   c
 / \ / \
d  e f  g

Example
input
2
4
a b d c
d b c a
7
a b d e c f g
d b e a f c g

output of inorder traversal
a b d c 
a b d e c f g 

*/
//You can get my code in IDE https://ide.geeksforgeeks.org/wN7cVPoLKL
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
     char val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preorder(TreeNode *root)
{
    if(!root)
        return;
    cout<<root->val<<' ';
    preorder(root->left);
    preorder(root->right);
}
void print(vector<char>v)
{
    for(char i : v)
        cout<<i<<' ';
    cout<<endl;
}

int find(char x, vector<char>v)
{
    for(int i = 0; i < v.size(); i++)
        if(v[i] == x)
            return i;
    return -1;
}
TreeNode *make_tree(TreeNode *root, vector<char>in, vector<char>pre, int &pos, int left, int right)
{
    if(left == right)
    {
        pos--;
        return NULL;
    }
    if(root == NULL && pos < in.size())
    {
        root = new TreeNode(pre[pos]);
        int x = find(pre[pos], in);
        pos++;
        root->left = make_tree(root->left, in, pre, pos, left, x);
        pos++;
        root->right = make_tree(root->right, in, pre, pos, x+1, right);
    }
    return root;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, pos = 0;
        cin>>n;
        vector<char>pre(n), in(n);
        for(int i = 0; i < n; i++)
            cin>>pre[i];
        for(int i = 0; i < n; i++)
            cin>>in[i];
        /*print(pre);
        print(in);*/
        TreeNode *root=NULL;
        root = make_tree(root, in, pre, pos, 0, n);
        preorder(root);
        cout<<endl;
    }
    return 0;
}