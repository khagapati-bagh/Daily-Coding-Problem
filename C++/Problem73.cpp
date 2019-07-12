/*
Daily Coding Problem: Problem #73 [Easy]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given the head of a singly linked list, reverse it in-place.

Example
input
2
10
3 66 54 8 5 6 9 4 8 5
5
1 2 3 4 5

output
Before Reverse : 3 66 54 8 5 6 9 4 8 5 
After Reverse  : 5 8 4 9 6 5 8 54 66 3 
Before Reverse : 1 2 3 4 5 
After Reverse  : 5 4 3 2 1 

*/

// You can get my code in IDE https://ide.geeksforgeeks.org/ianImKIVlX
//This code will take O(n) Time and Space Complexity
#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL){}
};
void display(ListNode *head)
{
    if(!head)
        return;
    cout<<head->val<<" ";
    display(head->next);
}
void append(ListNode **head, ListNode ** last, int x)
{
    //cout<<x<<endl;
    ListNode *tmp = new ListNode(x);
    if(*head == NULL)
        *head = *last = tmp;
    else
    {
        (*last)->next = tmp;
        *last = tmp;
    }
}

ListNode *reverse_inplace(ListNode *head)
{
    stack<int>st;
    ListNode *tmp = head;
    while(tmp)
        st.push(tmp->val), tmp = tmp->next;
    tmp = head;
    while(!st.empty() && tmp)
        tmp->val = st.top(), tmp= tmp->next, st.pop();
    return head;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {    
        int n, x;
        cin>>n;
        ListNode *head = NULL, *last = NULL;
        for(int i = 0; i < n; i++)
        {
            cin>>x;
            append(&head, &last, x);
        }
        cout<<"Before Reverse : ";
        display(head);
        head = reverse_inplace(head);
        cout<<endl<<"After Reverse : ";
        display(head);
        cout<<endl;
    }
    return 0;
}