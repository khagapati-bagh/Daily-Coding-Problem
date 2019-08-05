/*
Daily Coding Problem: Problem #94 [Easy]
Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given a binary tree of integers, find the maximum path sum between two nodes. The path must go through at least one node, and does not need to go through the root.

Example
input
3
12
-15 5 L -15 6 R 5 -8 L 5 1 R -8 2 L -8 -3 R 6 3 L 6 9 R 9 0 R 0 4 L 0 -1 R -1 10 L
6
0 1 L 0 2 R  1 3 L 1 4 R  2 5 L 2 6 R  
6
0 1 L 0 2 R  1 3 L 1 4 R  2 5 L 2 6 R

output
27
13
13

*/

//You can get my code in IDE https://ide.geeksforgeeks.org/WVuRsXoCvx
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *left, *right;
};
Node *newNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}
void insert(Node *root, int a1,int a2, char lr){
	if(root==NULL)
		return ;
	if(root->data==a1){
		switch(lr){
			case 'L':root->left=newNode(a2);
					break;
			case 'R':root->right=newNode(a2);
					break;
		}
	}
	insert(root->left,a1,a2,lr);
	insert(root->right,a1,a2,lr);
}

void inorder(Node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int helper(Node* root, int &res)
{
    if(!root)   return 0;
    int l_child = helper(root->left, res);
    int r_child = helper(root->right, res);
    if(l_child < 0) l_child = 0;
    if(r_child < 0) r_child = 0;
    res = l_child + r_child + root->data > res ? l_child + r_child + root->data : res;
    return root->data += max(l_child, r_child);
}
int maxPathSum(struct Node *root)
{
//add code here.
    int res = INT_MIN;
    helper(root, res);
    return res;
}

int main(){
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Node *root=NULL;
		while(n--){
			int a1,a2;
			char lr;
			cin>>a1>>a2>>lr;
			if(root==NULL){
				root=newNode(a1);
				switch(lr){
					case 'L':root->left=newNode(a2);
							break;
					case 'R':root->right=newNode(a2);
							break;
				}
			}
			else
				insert(root,a1,a2,lr);
		}
		//inorder(root);
		//cout<<endl;
		cout<<maxPathSum(root)<<endl;		
	}
}