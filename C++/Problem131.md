
# Daily Coding Problem: Problem #131 [Medium]

Good morning! Here's your coding interview problem for today.

This question was asked by Snapchat.

Given the head to a singly linked list, where each node also has a “random” pointer that points to anywhere in the linked list, deep clone the list.

**Input:**
First line of input contains number of testcases T. For each testcase, first line of input contains two integers N and M. Next line of input contains values of N nodes of the linked list and last line contains M pairs denoting arbitrary connecting  nodes, for which each ith node is connected to any jth node. ( ith->arb = jth ).

**NOTE** : If their is any node whose arbitrary pointer is not given then its by default null.

**Output:**
For each testcase, clone the given linked list.

**Solution** :

```cpp

#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node *arb;
    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};
void print(Node *root) {
    Node *temp = root;
    cout<<"Node and random pointer\n";
    while (temp != NULL) {
        int k;
        if (temp->arb == NULL)
            k = -111;
        else
            k = temp->arb->data;
        cout << temp->data << " " << k << " ";
        temp = temp->next;
    }
}
Node *copyList(Node *head);
void append(Node **head_ref, Node **tail_ref, int new_data) {
    Node *new_node = new Node(new_data);
    if (*head_ref == NULL) {
        *head_ref = new_node;
    } else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
bool validation(Node *head, Node *res, Node *cloned_addr,
                Node *generated_addr) {
    if (generated_addr == cloned_addr) return false;
    Node *temp1 = head;
    Node *temp2 = res;
    int len1 = 0, len2 = 0;
    while (temp1 != NULL) {
        len1++;
        temp1 = temp1->next;
    }
    while (temp2 != NULL) {
        len2++;
        temp2 = temp2->next;
    }
    /*if lengths not equal */
    if (len1 != len2) return false;
    temp1 = head;
    temp2 = res;
    while (temp1 != NULL) {
        if (temp1->data != temp2->data) return false;
        if (temp1->arb != NULL and temp2->arb != NULL) {
            if (temp1->arb->data != temp2->arb->data) return false;
        } else if (temp1->arb != NULL and temp2->arb == NULL)
            return false;
          else if (temp1->arb == NULL and temp2->arb != NULL)
            return false;
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
}
/* Driver program to test above function*/
int main() {
    int T, i, n, l, k;
    Node *generated_addr = NULL;
    /*reading input stuff*/
    cin >> T;
    while (T--) {
        generated_addr = NULL;
        struct Node *head = NULL, *tail = NULL;
        cin >> n >> k;
        for (i = 1; i <= n; i++) {
            cin >> l;
            append(&head, &tail, l);
        }
        for (int i = 0; i < k; i++) {
            int a, b;
            cin >> a >> b;
            Node *tempA = head;
            int count = -1;
            while (tempA != NULL) {
                count++;
                if (count == a - 1) break;
                tempA = tempA->next;
            }
            Node *tempB = head;
            count = -1;
            while (tempB != NULL) {
                count++;
                if (count == b - 1) break;
                tempB = tempB->next;
            }
            // when both a is greater than N
            if (a <= n) tempA->arb = tempB;
        }
        /*read finished*/
        generated_addr = head;
        Node *res = copyList(head);
        Node *cloned_addr = res;
        if(validation(head, res, cloned_addr, generated_addr))
            cout<<"\nCloned is successfull\n";
        else
            cout<<"\nCloned is unsuccessfull\n";
    }
    return 0;
}

// Should return the head of the copied linked list the
// output will be 1 if successfully copied
Node *copyList(Node *head) {
    // Your code here
    if(!head)   return head;
    Node *newHead = NULL, *l1, *l2;
    //Copy all the node value and their next pointer
    for(l1 = head; l1 != NULL; l1 = l1->next->next){
        l2 = new Node(l1->data);
        l2->next = l1->next;
        l1->next = l2;
    }
    newHead = head->next;
    //Copy all the random pointer
    for(l1 = head; l1 != NULL; l1 = l1->next->next){
        if(l1->arb) l1->next->arb = l1->arb->next;
    }
    //Change the next pointer of both the list
    
    for(l1 = head; l1 != NULL; l1 = l1->next){
        l2 = l1->next;
        l1->next = l2->next;
        if(l2->next)    l2->next = l2->next->next;
    }
    print(newHead);
    return newHead;
}

int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        int days, k;
        cin>>k>>days;
        vector<int>prices(days);
        for(int i = 0; i < days; i++)
            cin>>prices[i];
        Solution s;
        cout<<"Total profit is : "<<s.maxProfit(k, prices)<<endl<<endl;
    }
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/Vmd8SMFaBm)**