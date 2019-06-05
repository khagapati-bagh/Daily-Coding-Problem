/*
Daily Coding Problem: Problem #36 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Dropbox.

Given the root to a binary search tree, find the second largest node in the tree.

Example
input
2
30
26 85 28 37 6 47 30 14 58 25 96 83 46 15 68 35 65 44 51 88 9 77 79 89 85 4 52 55 100 33 
1
30
21 37 45 27 23 66 9 17 83 59 25 38 63 25 1 37 53 100 80 51 69 72 74 32 82 31 34 95 61 64 
10

output
100
64

*/
// You can get my code in IDE https://ide.geeksforgeeks.org/QencAvB7N1

#include<iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    Node *left, *right;
};
Node *newNode(int item)
{
    Node *temp = new Node;
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}   

void kthLargest(Node *root, int k);

Node* insert(Node* node, int key)
{
    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}

int main()
{
    int t;
	cin>>t;
	while(t--)
	{
		Node *root = NULL;
		int n;
		cin>>n;
		int a;
		cin>>a;
		root = insert(root, a);
		for(int i=0;i<n-1;i++)
		{
			cin>>a;
			insert(root,a);
		}
		int k;
		cin>>k;
		kthLargest(root, k);
	}
    return 0;
}


void helper(Node *root, int k, int &cnt)
{
    if(root!=NULL)
    {
        helper(root->right,k,cnt);
        cnt++;
        if(cnt == k)
        {    
            cout << root->key<<endl;
            return;
        }
        helper(root->left,k,cnt);
    }
}
void kthLargest(Node *root, int k)
{
    //Your code here.
    int cnt  = 0;
    helper(root, k, cnt);
    
}