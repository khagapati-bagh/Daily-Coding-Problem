/*
Daily Coding Problem: Problem #24 [Medium]
Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Implement locking in a binary tree. A binary tree node can be locked or unlocked only if all of 
its descendants or ancestors are not locked.

Design a binary tree node class with the following methods:

is_locked, which returns whether the node is locked
lock, which attempts to lock the node. If it cannot be locked, then it should return false. Otherwise, it should lock it and return true.
unlock, which unlocks the node. If it cannot be unlocked, then it should return false. Otherwise, it should unlock it and return true.
You may augment the node to add parent pointers or any other property you would like. 
You may assume the class is used in a single-threaded program, so there is no need for actual locks or mutexes. 
Each method should run in O(h), where h is the height of the tree.

Example

1. Insert to BST
2. Inorder Traversal
3. is_lock
4. lock()
5. unlock()
6. Quit
Enter your choice : 1
No. of node : 5
10
12
11
7
8
1. Insert to BST
2. Inorder Traversal
3. is_lock
4. lock()
5. unlock()
6. Quit
Enter your choice : 4
Enter the node to lock : 13
The node is Node not exits
Can't lock
1. Insert to BST
2. Inorder Traversal
3. is_lock
4. lock()
5. unlock()
6. Quit
Enter your choice : 2
The Inorder Traversal of Tree is
7 : 10
8 : 7
10 : NULL
11 : 12
12 : 10

1. Insert to BST
2. Inorder Traversal
3. is_lock
4. lock()
5. unlock()
6. Quit
Enter your choice : 4
Enter the node to lock : 10
The node is successfully Locked
1. Insert to BST
2. Inorder Traversal
3. is_lock
4. lock()
5. unlock()
6. Quit
Enter your choice : 4
Enter the node to lock : 12
The node is Can't lock
1. Insert to BST
2. Inorder Traversal
3. is_lock
4. lock()
5. unlock()
6. Quit
Enter your choice : 5
Enter the node to lock : 10
The node is successfully unlocked
1. Insert to BST
2. Inorder Traversal
3. is_lock
4. lock()
5. unlock()
6. Quit
Enter your choice : 4
Enter the node to lock : 12
The node is successfully Locked
1. Insert to BST
2. Inorder Traversal
3. is_lock
4. lock()
5. unlock()
6. Quit
Enter your choice : 6

*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode 
{
	int val, count;
	bool lock;
	TreeNode *left, *right, *parent;

	TreeNode(int x, TreeNode *par) : val(x), left(NULL), right(NULL), parent(par), count(0), lock(false) {}
};

TreeNode *insert(TreeNode * root, int val){
	TreeNode **ptr = &root,*par=NULL;
	while(*ptr)
	{
		par = *ptr;
		ptr = (val < (*ptr)->val) ? &(*ptr)->left : &(*ptr)->right;
	}
	*ptr = new TreeNode(val, par);
	return root;
}

TreeNode * find(int x, TreeNode *root){
	if(root == NULL)
		return NULL;
	/*if(root->val == x)
		return root;*/
	TreeNode *tmp =root;
	while(tmp != NULL && tmp->val != x){
		if(x < tmp->val)
			tmp = tmp->left;
		else 
			tmp = tmp->right;
	}
	if(!tmp)
		cout<<"Node not exits"<<endl;
	return tmp;
}

void Inorder(TreeNode *root)
{
	if(!root)
		return;
	Inorder(root->left);
	cout<<root->val<<" : ";
	if(!root->parent)//for root node
		cout<<"NULL"<<endl;
	else
		cout<<root->parent->val<<endl;
	Inorder(root->right);
}

bool is_lock(int x, TreeNode * root)
{
	TreeNode *ptr = find(x, root);
	if(ptr!= NULL && ptr->lock)
		return true;
	return false;
}

TreeNode * can_lock_or_unlock(int x, TreeNode * root){
	TreeNode *ptr = find(x, root);
	TreeNode * tmp =ptr;
	if(!ptr || ptr->count > 0)
		return NULL;
	ptr = ptr->parent;
	while(ptr)
	{
		if(ptr->lock)
			return NULL;
		ptr = ptr->parent;
	}

	return tmp;
}

bool lock(int x, TreeNode *root)
{
	TreeNode *ptr = can_lock_or_unlock(x, root);
	if(ptr != NULL)
	{
		ptr->lock = true;

		ptr = ptr->parent;
		while(ptr)
		{
			ptr->count +=1;
			ptr = ptr->parent;
		}
		return true;
	}
	else
		return false;
}

bool unlock(int x, TreeNode *root){
	TreeNode *ptr = find(x, root);
	if(ptr!= NULL)
	{
		ptr->lock = false;
		ptr = ptr->parent;
		while(ptr)
		{
			ptr->count -=1;
			ptr = ptr->parent;
		}
		return true;
	}
	else
		return false;
}

int main(){
	int ch,x,n;
	TreeNode *root=NULL;
	while(1){
		cout<<"\n1. Insert to BST\n2. Inorder Traversal\n3. is_lock\n4. lock()\n5. unlock()\n6. Quit\nEnter your choice : ";
		cin>>ch;
		switch(ch){
			case 1:cout<<"No. of node : ";
					cin>>n;
					for(int i = 0; i < n; i++)
					{
						cin>>x;
						root = insert(root, x);
					}
					break;
			case 2: cout<<"The Inorder Traversal of Tree is"<<endl;
					Inorder(root);
					cout<<endl;
					break;
			case 3: cout<<"Enter the node ";
					cin>>x;
					cout<<"The node is ";
					if(is_lock(x, root))
						cout<<"Locked"<<endl;
					else
						cout<<"Unlocked"<<endl;
					break;
			case 4: cout<<"Enter the node to lock : ";
					cin>>x;
					cout<<"The node is ";
					if(lock(x, root))
						cout<<"successfully Locked"<<endl;
					else
						cout<<"Can't lock"<<endl;
					break;
			case 5:cout<<"Enter the node to lock : ";
					cin>>x;
					cout<<"The node is ";
					if(unlock(x, root))
						cout<<"successfully unlocked"<<endl;
					else
						cout<<"already unlock"<<endl;
					break;
			case 6: exit(1);
		}
	}
	return 0;
}