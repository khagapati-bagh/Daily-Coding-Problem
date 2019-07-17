/*
Daily Coding Problem: Problem #78 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given k sorted singly linked lists, write a function to merge all the lists into one sorted singly linked list.

Example
input
2
4
3 1 2 3 2 4 5 2 5 6 2 7 8
3
2 1 3 3 4 5 6 1 8

output
1 2 3 4 5 5 6 7 8 
1 3 4 5 6 8 

*/

//You can get my code in IDE https://ide.geeksforgeeks.org/Bw2NLDd7fv

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void append(ListNode** head, ListNode** tail, ListNode* tmp)
{
    if(!(*head))
        *head = *tail = tmp;
    else
    {
        (*tail)->next = tmp;
        *tail = tmp;
    }
}
void print_list(ListNode* head)
{
    if(!head) return;
    cout<<head->val<<" ";
    print_list(head->next);
}
void print(vector<ListNode*>v)
{
    for(int i = 0; i < v.size(); i++)
    {
        print_list(v[i]);
        cout<<endl;
    }
}

class Solution {
struct compare{
    bool operator()(const ListNode* a, const ListNode* b)
    {
        return a->val > b->val;
    }
};
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare>q;
        for(auto a : lists)
            if(a) q.push(a);
        if(q.empty())   return NULL;
        ListNode *head = q.top();
        q.pop();
        if(head->next)  q.push(head->next);
        ListNode* tail = head;
        while(!q.empty())
        {
            tail->next = q.top();
            q.pop();
            tail = tail->next;
            if(tail->next)  q.push(tail->next);
        }
        return head;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, x;
        cin>>n;
        vector<ListNode*>lists;
        for(int i = 0; i < n; i++)
        {
            ListNode* head = NULL, *tail = NULL;
            int m;
            cin>>m;
            for(int j = 0; j < m; j++)
            {
                cin>>x;
                ListNode* tmp = new ListNode(x);
                append(&head, &tail, tmp);
            }
            lists.push_back(head);
            //print_list(head);
        }
        //print(lists);
        Solution *s = new Solution();
        ListNode *result = s->mergeKLists(lists);
        print_list(result);
        cout<<endl;
    }
    return 0;
}