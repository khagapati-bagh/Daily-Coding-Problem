
# Daily Coding Problem: Problem #115 [Hard]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.

**Solution** :

```cpp

#include<bits/stdc++.h>
using namespace std;

// Structure of a tree node
struct Node {
    int data;
    struct Node *left;
    struct Node *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/*you are required to
complete this function */
bool identical(Node* t, Node* s){
    if(!s && !t)    return true;
    if(!s || !t || t->data != s->data)
        return false;
    return identical(t->left, s->left) && identical(t->right, s->right);
}

bool isSubtree(Node* T1, Node* T2) {
    // Your code here
    // return 1 if T2 is subtree of T1 else 0
    if(!T1 && !T2)
        return true;
    if(!T1 || !T2)
        return false;
    if(identical(T1, T2))
        return true;
    return identical(T1->left, T2) || identical(T1->right, T2);
}

Node* makeTree(){
    struct Node *child = NULL;
    map<int, Node *> m;
    int n;
    scanf(" %d", &n);
    struct Node *root = NULL;
    while (n--) {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end()) {
            parent = new Node(n1);
            m[n1] = parent;
            if (root == NULL) 
                root = parent;
        } 
        else
            parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
            parent->left = child;
        else
            parent->right = child;
        m[n2] = child;
    }
    return root;
}
// Driver program to test above function
int main() {
    int test;
    scanf("%d", &test);
    while (test--) {
        struct Node *t = makeTree();
        struct Node *s = makeTree();
        if(isSubtree(s, t))
            cout<<"True"<< endl;
        else
        cout << "False" <<endl;
    }
}

```

**[Run Code](https://ide.geeksforgeeks.org/KjWnNb2vy9)**