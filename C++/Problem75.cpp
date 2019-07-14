/*
Daily Coding Problem: Problem #75 [Hard]
Good morning! Here's your coding interview problem for today.

This problem was asked by Microsoft.

Given an array of numbers, find the length of the longest increasing subsequence in the array. The subsequence does not necessarily have to be contiguous.

For example, given the array [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15], the longest increasing subsequence has length 6: it is 0, 2, 6, 9, 11, 15.

Example
input
2
16
0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
6
5 8 3 7 9 1

output
6
3

*/
//You can get my code in IDE https://ide.geeksforgeeks.org/5hxOhvDIXJ
//This code will take O(n) Time and Space Complexity
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int lengthofLIS(vector<int>v)
{
    vector<int>res;
    for(int i : v)
    {
        auto it = lower_bound(res.begin(), res.end(), i);
        if(it == res.end())
            res.push_back(i);
        else *it = i;
    }
    return res.size();
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int>v(n);
	    for(int i = 0; i < n; i++)
	        cin>>v[i];
	    cout<<lengthofLIS(v)<<endl;
	}
	return 0;
}