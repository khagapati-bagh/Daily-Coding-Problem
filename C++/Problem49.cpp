/*
Daily Coding Problem: Problem #49 [Medium]
Good morning! Here's your coding interview problem for today.

This problem was asked by Amazon.

Given an array of numbers, find the maximum sum of any contiguous subarray of the array.

For example, given the array [34, -50, 42, 14, -5, 86], the maximum sum would be 137, since we would take elements 42, 14, -5, and 86.

Given the array [-5, -1, -8, -9], the maximum sum would be 0, since we would not take any elements.

Do this in O(N) time.
Example 
input
2
5
1 2 3 -2 5
4
-1 -2 -3 -4

output
9
0

*/
//You can get my code in IDE https://ide.geeksforgeeks.org/YESXIJ5pX4
//This code will take O(n) Time and O(1) Space Complexity
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int max_contigeous_sum(vector<int>v)
{
    int curSum = 0, maxSum = 0;
    for(int i = 0; i < v.size(); i++)
    {
        curSum = max(v[i], curSum += v[i]);
        maxSum = max(curSum, maxSum);
    }
    return maxSum;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int>A(n);
	    for(int i = 0; i < n ; i++)
	        cin>>A[i];
	    cout<<max_contigeous_sum(A)<<endl;
	}
	return 0;
}