/*
Daily Coding Problem: Problem #60 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

Given a multiset of integers, return whether it can be partitioned into two subsets whose sums are the same.

For example, given the multiset {15, 5, 20, 10, 35, 15, 10}, it would return true, 
since we can split it up into {15, 5, 10, 15, 10} and {20, 35}, which both add up to 55.

Given the multiset {15, 5, 20, 10, 35}, it would return false, 
since we can't split it up into two subsets that add up to the same sum.

Example
input
4
7
15 5 20 10 35 15 10
5
15 5 20 10 35
4
1 2 3 5
4
1 5 11 5

output
True
False
False
True

*/
//You can get my code in IDE https://ide.geeksforgeeks.org/gjwuvifGpa
//This code will take O(n) Time and Space Complexity
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool can_split(vector<int>v)
{
    int total = accumulate(v.begin(), v.end(), 0); //sum of vector
    bitset<10001>bts(1);
    //cout<<bts<<endl;
    for(int i : v)
        bts |= bts<<i;///left shift to bts and add bts
    return !(total & 1) && bts[total>>1];// total must be even and bts[total/2] should be set
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i = 0; i < n; i++)
            cin>>v[i];
        if(can_split(v))
            cout<<"True"<<endl;
        else 
            cout<<"False"<<endl;
    }
    return 0;
}