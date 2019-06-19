/*
Daily Coding Problem: Problem #50 [Easy]

Good morning! Here's your coding interview problem for today.

This problem was asked by Microsoft.

Suppose an arithmetic expression is given as a binary tree. 
Each leaf is an integer and each internal node is one of '+', '−', '∗', or '/'.

Given the root to such a tree, write a function to evaluate it.

For example, given the following tree:

    *
   / \
  +    +
 / \  / \
3  2  4  5
You should return 45, as it is (3 + 2) * (4 + 5).
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    string info;
    node *left = NULL, *right = NULL;
    node(string x)
    {
        info = x;
    }
};

int evalute(node * root)
{
    if(!root)
        return 0;
    if(!root->left && !root->right)
        return stoi(root->info);
    int l_val = evalute(root->left);
    int r_val = evalute(root->right);
    
    //cout<<l_val<<" "<<r_val<<endl; 
    if(root->info == "+")
        return l_val + r_val;
    if(root->info == "-")
        return l_val - r_val;
    if(root->info == "*")
        return l_val * r_val;
    if(root->info == "/")
        return l_val / r_val;
}

int main()
{
    node *root = new node("*");
    root->left = new node("+");
    root->left->left = new node("3");
    root->left->right = new node("2");
    root->right = new node("+");
    root->right->left = new node("4");
    root->right->right = new node("5");
    cout<<evalute(root)<<endl;
    
    delete root;
    
    root = new node("+");  
    root->left = new node("*");  
    root->left->left = new node("5");  
    root->left->right = new node("4");  
    root->right = new node("-");  
    root->right->left = new node("100");  
    root->right->right = new node("/");  
    root->right->right->left = new node("20");  
    root->right->right->right = new node("2");  
    cout<<evalute(root)<<endl;
    
    return 0;
}