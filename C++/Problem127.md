
# Daily Coding Problem: Problem #127 [Easy]

Good morning! Here's your coding interview problem for today.

This problem was asked by Microsoft.

Let's represent an integer in a linked list format by having each node represent a digit in the number. The nodes make up the number in reversed order.

For example, the following linked list:
```
1 -> 2 -> 3 -> 4 -> 5
```
is the number 54321.

Given two linked lists in this format, return their sum in the same linked list format.

For example, given
```
9 -> 9
5 -> 2
```
return 124 (99 + 25) as:
```
4 -> 2 -> 1
```
**Solution** :

```cpp

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
struct Node* addTwoLists(struct Node* first, struct Node* second);
void push(struct Node** head_ref, int new_data) {
    struct Node* new_Node = new Node(new_data);
    new_Node->next = (*head_ref);
    (*head_ref) = new_Node;
}
void printList(struct Node* Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}
void freeList(struct Node* Node) {
    struct Node* temp;
    while (Node != NULL) {
        temp = Node;
        Node = Node->next;
        free(temp);
    }
}
int main(void) {
    int t, n, m, i, x;
    cin >> t;
    while (t--) {
        struct Node* res = NULL;
        struct Node* first = NULL;
        struct Node* second = NULL;
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> x;
            push(&first, x);
        }
        cin >> m;
        for (i = 0; i < m; i++) {
            cin >> x;
            push(&second, x);
        }
        res = addTwoLists(first, second);
        printList(res);
        if (first) freeList(first);
        if (second) freeList(second);
    }
    return 0;
}

Node *insertRem(Node *head, Node *tail, int &carry){
    int x;
    Node *tmp = NULL;
    while(head){
        int x = head->data + carry;
        if(!tail)
            tail = new Node(x%10);
        else{
            tmp = new Node(x%10);
            tail->next = tmp;
            tail = tail->next;
        }
        head = head->next;
        carry = x/10;
    }
    if(carry){
        tmp = new Node(carry);
        tail->next = tmp;
        tail = tail->next;
        carry = 0;
    }
    return tail;
}

Node* addTwoLists(Node* first, Node* second) {
    // Code here
    if(!first)  return second;
    if(!second) return first;
    Node *head = NULL, *tail = NULL, *tmp = NULL;
    int x, carry = 0;
    while(first && second){
        int x = first->data + second->data + carry;
        carry = x / 10;
        if(!head)
            head = tail = new Node(x%10);
        else{
            tmp = new Node(x%10);
            tail->next = tmp;
            tail = tail->next;
        }
        first = first->next, second = second->next;
    }
    
    if(first)
        insertRem(first, tail, carry);
    if(second)
        insertRem(second, tail, carry);
    if(carry){
        tmp = new Node(carry);
        tail->next = tmp;
        tail = tail->next;
        carry = 0;
    }
    return head;
}

```

**[Run Code](https://ide.geeksforgeeks.org/uT4TGS4PQ3)**