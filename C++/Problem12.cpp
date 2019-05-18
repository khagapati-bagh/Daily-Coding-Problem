/*
Daily Coding Problem: Problem #12 [Hard]
Good morning! Here's your coding interview problem for today.

This problem was asked by Amazon.

There exists a staircase with N steps, and you can climb up either 1 or 2 steps 
at a time. Given N, write a function that returns the number of unique ways you 
can climb the staircase. The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2
What if, instead of being able to climb 1 or 2 steps at a time, you could climb 
any number from a set of positive integers X? For example, if X = {1, 3, 5}, you 
could climb 1, 3, or 5 steps at a time.

Code Example : This will take O(n) Time and Space Complexity
input 
2
5
2
1 2
5
3
1 3  5

output
8
5

*/
//You can Check this in IDE: https://ide.geeksforgeeks.org/7MgMUNyQVE
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int no_of_ways(int n, vector<int>X)
{
    vector<int>arr(n+1); // Storing sub value
    arr[0]=arr[1]=1;
    for(int i=2; i <= n; i++)
    {
        int total = 0;
        for(int j : X)
            if(i - j >= 0) // Acces array element greater than 0
                total += arr[i-j];
        arr[i] = total; 
    }
    return arr[n];
}

int main() {
    int t;
    cin>>t; // Test cases
    while(t--)
    {
        int n,sz,i;
        cin>>n>>sz; // sz = you could climb any number from a set of positive integers X
        vector<int>X(sz);
        for(i=0;i<sz; i++)
            cin>>X[i]; //Enter Set element
        cout<<no_of_ways(n,X)<<endl;
    }
    return 0;
}