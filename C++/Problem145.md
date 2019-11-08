
# Daily Coding Problem: Problem #145 [Easy]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given the head of a singly linked list, swap every two nodes and return its head.

For example, given 1 -> 2 -> 3 -> 4, return 2 -> 1 -> 4 -> 3.

**Solution** :

```cpp

#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void insert(ListNode **head, ListNode **tail, int x){
    if(*head == NULL)
        *head = *tail = new ListNode(x);
    else{
        ListNode *tmp = new ListNode(x);
        (*tail)->next = tmp;
        (*tail) = tmp;
    }
}
void display(ListNode* head){
    while(head->next){
        cout<<head->val<<" -> ";
        head = head->next;
    }
    if(head)
        cout<<head->val;
    cout<<endl;
}

ListNode *reverseKBlockOfNode(ListNode* head, int k){
    int count = 0;
    ListNode *current = head, *next = NULL, *prev = NULL;
    while(current && count < k){//reverse the k nodes
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    if(next)
        head->next = reverseKBlockOfNode(next, k);
    return prev;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, k, x;
        cin>>n>>k;
        ListNode *head = NULL, *tail = NULL;
        for(int i = 0; i < n; i++){
            cin>>x;
            insert(&head, &tail, x);
        }
        cout<<"Before reverse of "<<k<<" nodes : ";
        display(head);
        head = reverseKBlockOfNode(head, k);
        cout<<"After reverse of  "<<k<<" nodes : ";
        display(head);
    }
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/tObokgHHg2)**