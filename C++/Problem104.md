# Daily Coding Problem: Problem #104 [Easy]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Determine whether a doubly linked list is a palindrome. What if it’s singly linked?

For example, 1 -> 4 -> 3 -> 4 -> 1 returns True while 1 -> 4 returns False.

**Solution** : 

```cpp

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *left, *right;
    ListNode(int x) : val(x), left(NULL), right(NULL) {}
};

void displayForward(ListNode *head){
    while(head){
        cout<<head->val<<" ";
        head = head->right;
    }
    cout<<endl;
}

//print form backword
void displayBackward(ListNode *head){
    while(head){
        cout<<head->val<<" ";
        head = head->left;
    }
    cout<<endl;
}

void insert(ListNode **head, int n){
    ListNode *last = NULL;
    for(int i = 0; i < n; i++){
        int x;
        cin>>x;
        ListNode *tmp = new ListNode(x);
        if(!(*head)){
            *head = last = tmp;
        }
        else{
            last->right = tmp;
            tmp->left = last;
            last = tmp;
        }
    }
}

bool checkPalindrome(ListNode *head){
    if(!head)   return true;
    ListNode *slow = head, *fast = head;
    
    while(fast && fast->right){
        slow = slow->right;
        fast = fast->right->right;
    }
    
    if(!fast)
        fast = slow;
    else
        fast = slow->right;
        
    slow = slow->left;
    while(slow && fast){
        if(slow->val != fast->val)
            return false;
        slow = slow->left;
        fast = fast->right;
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ListNode *head = NULL;
        insert(&head, n);
        displayForward(head);
        if(checkPalindrome(head)){
            cout<<"List is a palindrome"<<endl;
        }
        else{
            cout<<"List is not a palindrome"<<endl;
        }
    }
    return 0;
}

```
**[Run Code](https://ide.geeksforgeeks.org/cWVJOrwjVp)**