
# Daily Coding Problem: Problem #141 [Hard]

Good morning! Here's your coding interview problem for today.

This problem was asked by Microsoft.

Implement 3 stacks using a single list:
```
class Stack:
    def __init__(self):
        self.list = []

    def pop(self, stack_number):
        pass

    def push(self, item, stack_number):
        pass
```
**Solution** :

```cpp

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    struct ListNode *next;
    ListNode(int x, ListNode* ptr) : val(x), next(ptr){}
};

ListNode *stack1 = NULL, *stack2 = NULL, *stack3 = NULL;
ListNode *stack1Last, *stack2Last, *stack3Last;

void display(ListNode *head){
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

void Push(int val, ListNode **head, ListNode **last ){
    if(*head == NULL)
        *head = *last = new ListNode(val, NULL);
    else{
        ListNode *tmp = new ListNode(val, *head);
        *head = tmp;
    }
}

void push(int val, int stack_number){
    if(stack_number == 1){
        Push(val, &stack1, &stack1Last);
        if(stack2)
            stack1Last->next = stack2;
        else if(stack3)
            stack1Last->next = stack3;
    }
    else if(stack_number == 2){
        Push(val, &stack2, &stack2Last);
        if(stack1Last)
            stack1Last->next = stack2;
        if(stack3)
            stack2Last->next = stack3;
    }
    else if(stack_number == 3){
        Push(val, &stack3, &stack3Last);
        if(stack2Last)
            stack2Last->next = stack3;
        else if(stack1Last)
            stack1Last->next = stack3;
    }
}
void Pop(ListNode **head, ListNode **last){
    if(*head){
            cout<<(*head)->val<<endl;
            ListNode *tmp = *head;
            if(*head == *last)
                *head = *last = NULL;
            else
                *head = (*head)->next;
            free(tmp);
        }
}
void pop(int stack_number){
    if(stack_number == 1){
        Pop(&stack1, &stack1Last);
    }
    else if(stack_number == 2){
        Pop(&stack2, &stack2Last);
        if(stack1Last && stack2)
            stack1Last->next = stack2;
        else if(stack1Last && stack3)
            stack1Last->next = stack3;
    }
    else if(stack_number == 3){
        Pop(&stack3, &stack3Last);
        if(stack2Last)
            stack2Last->next = stack3;
        else if(stack1Last)
            stack1Last->next = stack3;
    }
}
int main(){
    while(true){
        int stack_number, val, operation;
        cin>>stack_number>>operation;
        if(stack_number == -1)
            break;
        switch(operation){
            case 1: cin>>val;
                    push(val, stack_number);   break;
            case 2:
                    pop(stack_number);     break;
            case 3: {
                    if(stack1)
                        display(stack1);
                    else if(stack2)
                        display(stack2);
                    else if(stack3)
                        display(stack3);
                    else 
                        cout<<"Three stack are empty"<<endl;
            }
            
        }
    }
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/f7egHntbKV)**