/*
Daily Coding Problem: Problem #20 [Easy]
Solution in C++
Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given two singly linked lists that intersect at some point, find the intersecting node. The lists are non-cyclical.

For example, given A = 3 -> 7 -> 8 -> 10 and B = 99 -> 1 -> 8 -> 10, return the node with value 8.

In this example, assume nodes with the same value are the exact same node objects.

Do this in O(M + N) time (where M and N are the lengths of the lists) and constant space.

Example
input
1
2 3 3
4 1
5 0 1
8 4 5
output
8

*/
/*
This code will tak Max(m,n) Time and O(1)
You can get my code directly in IDE link : https://ide.geeksforgeeks.org/C2dqCRRU8A 

Different Approach
By using two stack it takes O(m+n) Time and Space Complexity.
Algo.
	push all the node pointer to first stack
	push all the node pointer to second stack
	
	intialize a tmp variable with NULL
	Check the top of both the stack are same 
		if yes then store it in tmp variable and pop the top from both the stack
		else return the tmp variable 
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
typedef struct Node Node;

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

void display(struct Node *head){ //Aditional function
    if(head == NULL)
        return;
    cout<<head->data<<' ';
    display(head->next);
}

int count(struct Node *head){//No.of Node
        int cnt = 0;
        while(head){
            cnt++;
            head = head->next;
        }
        return cnt;
}

struct Node* intersectPoint(Node* headA, Node* headB)//main function
{
    // Your Code Here
    if(headA == NULL || headB == NULL) //anyone of they is empty then return null
            return nullptr;
        int l1 = count(headA), l2= count(headB), diff; //count no. of node
        struct Node *list1, *list2;//temporary list
        if(l1 < l2)
            list1 = headB, list2 = headA, diff = l2 - l1; // no. of node in (headB > headA)
        else
            list1 = headA, list2 = headB, diff = l1 - l2; //no. of node in (headA > headB)
        
        for(int i = 0; i < diff; i++) // from the longest list skip the first diff node
            list1 = list1->next;
        
        while(list1 != NULL && list2 != NULL){
            
            if(list1 == list2) //If pointer same
                return list1;
            
            list1 = list1->next;
            list2 = list2->next;
        }
        return nullptr;//else
}

/* Driver program to test above function*/
int main()
{
    int T,i,n1, n2, n3,l,k;
    cin>>T;
    while(T--)
    {
        cin>>n1>>n2>>n3; //n1 and n2 first and second list befor intersectiion. n3 after intersection
        struct Node *head1 = NULL,  *tail1 = NULL;
        for(i=1; i<=n1; i++)
        {
            cin>>l;
            append(&head1, &tail1, l);
        }
        struct Node *head2 = NULL,  *tail2 = NULL;
        for(i=1; i<=n2; i++)
        {
            cin>>l;
            append(&head2, &tail2, l);
        }
        struct Node *head3 = NULL,  *tail3 = NULL;
        for(i=1; i<=n3; i++)
        {
            cin>>l;
            append(&head3, &tail3, l);
        }

        if (tail1 != NULL)
        	tail1->next = head3; //third list append to the first list
        if (tail2 != NULL)
        	tail2->next = head3; // third list append to the second list
        cout << (intersectPoint(head1, head2))->data << endl;
        /*display(head1);
        cout<<endl;
        display(head2);*/
    }
    return 0;
}
