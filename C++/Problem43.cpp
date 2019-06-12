/*
Daily Coding Problem: Problem #43 [Easy]

Good morning! Here's your coding interview problem for today.

This problem was asked by Amazon.

Implement a stack that has the following methods:

push(val), which pushes an element onto the stack
pop(), which pops off and returns the topmost element of the stack. 
If there are no elements in the stack, then it should throw an error or return null.
max(), which returns the maximum value in the stack currently. 
If there are no elements in the stack, then it should throw an error or return null.
Each method should run in constant time.

Example
input
1
60
91 99 988 2 6868 79 655 61 34 5575 76 99 8 4354 58 6078 71 6583 6 91 97 421 7 67 7 333 52 20 453 940 3 95 68 5 922 24 43 4 51 7 58 95 401 674 698 1466 8121 392 7 6 564 40 2960 188 692 5 7787 536 22 628

output
2
*/
//You can get my code in IDE https://ide.geeksforgeeks.org/3f1hBTJPxX
// All operation will take O(1) Time complexity
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void push(int a);
bool isFull(int n);
bool isEmpty();
int pop();
int getMin();

//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty()){
		    pop();
		}
		while(!isFull(n)){
			cin>>a;
			push(a);
		}
		cout<<getMin()<<endl;
	}
}
/*This is a function problem.You only need to complete the function given below*/
/*Complete the function(s) below*/
int mn;

void push(int a)
{
     //add code here.
     if(s.size() == 0 || a < mn)
        mn = a;
     s.push(a);
}

bool isFull(int n)
{
     //add code here.
     return s.size() == n;
}

bool isEmpty()
{
    //add code here.
    return s.size() == 0;
}

int pop()
{
    //add code here.
    if(!s.empty())
    {
        int t = s.top();
        s.pop();
        return t;
    }
    return -1;
}

int getMin()
{
   //add code here.
   if(!s.empty())
    return mn;
}