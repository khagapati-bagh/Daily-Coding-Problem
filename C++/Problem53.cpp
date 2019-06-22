/*
Daily Coding Problem: Problem #53 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Apple.

Implement a queue using two stacks. Recall that a queue is a FIFO (first-in, first-out) data structure with the following 
methods: enqueue, which inserts an element into the queue, and dequeue, which removes it.
Example
input
2
5
1 2 1 3 2 1 4 2
4
1 2 2 2 1 4

output
2 3 
2 -1 

*/
//You can get my code in IDE https://ide.geeksforgeeks.org/6F9pIFiB5F
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class StackQueue{
private:   
    // These are STL stacks ( http://goo.gl/LxlRZQ )
    stack<int> s1;
    stack<int> s2;
public:
    void push(int);
    int pop();
};

//This code will take O(1) Time Complexity
void StackQueue :: push(int x)
 {
        // Your Code
        s1.push(x);
 }
//This code will take O(n) Time Complexity
int StackQueue :: pop()
{
        // Your Code       
        int res = -1;
        if(s2.empty())
        {
            while(!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        if(!s2.empty())
        {
            res = s2.top();
            s2.pop();
        }
        return res;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        StackQueue *sq = new StackQueue();
        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";
        }
        }
        cout<<endl;
    }
}