/*
Daily Coding Problem: Problem #40 [Hard]
Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given an array of integers where every integer occurs three times except for one integer, which only occurs once, 
find and return the non-duplicated integer.

For example, given [6, 1, 3, 3, 3, 6, 6], return 1. Given [13, 19, 13, 13], return 19.

Do this in O(N) time and O(1) space.
*/
// You can get my code in IDE https://ide.geeksforgeeks.org/UZh2gMbcky
//Resource for the code https://leetcode.com/problems/single-number-ii/discuss/43295/Detailed-explanation-and-generalization-of-the-bitwise-operation-method-for-single-numbers
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int singleNumber(vector<int>& nums) {
    int x1 = 0, x2 = 0, mask; 
    for(int i: nums)
    {
       x2 ^=x1 & i;
       x1 ^=i;
       mask = ~(x1 & x2);
       x1 &=mask;
       x2 &=mask;
    }
    return x1;
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int>v(n);
	    for(int i = 0; i < n; i++)
	        cin>>v[i];
	    cout<<singleNumber(v)<<endl;
	}
	return 0;
}