
# Daily Coding Problem: Problem #125 [Easy]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given the root of a binary search tree, and a target K, return two nodes in the tree whose sum equals K.

For example, given the following tree and K of 20

```
        10
       /   \
     5      15
           /  \
         11    15
```
Return the nodes 5 and 15.

**Solution** :

```cpp

#include <bits/stdc++.h>
#define MAX_SIZE 100
using namespace std;
struct node
{
    int val;
    struct node *left;
    struct node *right;
    
    node(int x){
        val = x;
        left = NULL;
        right = NULL;
    }
};

struct node *insert(struct node *root,int a){
    if(root==NULL)
        return new node(a);
    if(root->val >a){
        root->left = insert(root->left,a);
    }
    if(root->val < a){
        root->right = insert(root->right,a);
    }
    return root;
}

void inorder(struct node *root){
    if(root==NULL)
        return;
    inorder(root->left);
    cout<<root->val<<" ";
    inorder(root->right);
}

bool helper(struct node *root, int target, unordered_map<int, bool>&mp){
    if(!root)   return false;
    if(mp.count(target - root->val)){
        cout<<target- root->val<<" "<<root->val<<endl;
        return true;
    }
    mp[root->val] = true;
    return helper(root->left, target, mp) || helper(root->right, target, mp);
}

void isPairPresent(struct node *root, int target)
{
    unordered_map<int, bool>mp;
    cout<<target<<" : ";
    if(helper(root, target, mp) == false)
        cout<<"No such pair"<<endl;
}


int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,target;
        cin>>n>>target;
        struct node *root =  NULL;
        while(n--){
            int a;
            cin>>a;
            if(root==NULL){
                root = new node(a);
            }
            else{
                insert(root,a);
            }
        }
    isPairPresent(root, target);
    }
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/nVLwvOJC0v)**