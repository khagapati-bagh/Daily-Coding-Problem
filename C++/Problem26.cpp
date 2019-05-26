/*
Daily Coding Problem: Problem #26 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given a singly linked list and an integer k, remove the kth last element from the list. k is guaranteed to be smaller than the length of the list.

The list is very long, so making more than one pass is prohibitively expensive.

Do this in constant space and in one pass.
Example
input
3
5 5
1 2 3 4 5
9 2
1 2 3 4 5 6 7 8 9
5 0
10 5 100 5 1

output
2 3 4 5 
1 2 3 4 5 6 7 9 
10 5 100 5 1 

*/
// You can get my code in IDE https://ide.geeksforgeeks.org/RKrYfGhGCw
//This code will take O(n) Time and O(1) Space complexity

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};

void display(ListNode *head){
    if(!head)
        return;
    cout<<head->val<<' ';
    display(head->next);
}

void append(ListNode ** head_ref, ListNode **tail_ref, int new_data)
{
    ListNode * new_node = new ListNode(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}
//in one pass 
ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(n == 0 || !head)
            return head;
        ListNode new_head(-1);
        new_head.next = head; //slow pointer start from begining of head
        ListNode *slow = &new_head, *fast = head;
        for(int i = 1; i < n; i++)
            fast = fast->next;
        while(fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *tmp = slow->next;//node to be deleted
        if(slow->next == head)//when removed node is head
            head = head->next;
        slow->next = tmp->next;//set the next pointer
        delete tmp; //removed
        return head;
        
}
    
int main() {
    int t;
    cin>>t;
    while(t--)
	{
	    int n,i,k,d;
    	cin>>n>>k;
    	ListNode *head = NULL, *tail = NULL;
    	for(i = 0; i < n; i++)
    	{
    	    cin>>d;
    	    append(&head, &tail, d);
    	}
    	/*display(head);
    	cout<<endl;*/
    	head = removeNthFromEnd(head, k);
    	display(head);
    	cout<<endl;
	}
	return 0;
}