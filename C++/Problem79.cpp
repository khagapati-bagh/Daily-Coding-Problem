/*
Daily Coding Problem: Problem #79 [Medium]
Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

Given an array of integers, write a function to determine whether the array could become non-decreasing by modifying at most 1 element.

For example, given the array [10, 5, 7], you should return true, since we can modify the 10 into a 1 to make the array non-decreasing.

Given the array [10, 5, 1], you should return false, since we can't modify any one element to get a non-decreasing array.

Example
input
2
10 5 1
10 5 7

output
False
True

*/
//You can get my code in IDE https://ide.geeksforgeeks.org/ZYyc66ycG7

//This code will take O(n) Time and O(1) Space Complexity

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
//With modifying the input
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int flag = 0;
        for(int i = 1, prev = nums[0]; i < nums.size(); i++)
        {
            if(nums[i] < nums[i-1])
            {
                if(flag++)  return false;
                (i - 2 < 0 || nums[i-2] <= nums[i]) ? nums[i-1] = nums[i] : nums[i] = nums[i-1];
            }
        }
        return true;
    }
};*/
//Without modifying the input
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int flag = 0;
        for(int i = 1, prev = nums[0]; i < nums.size(); i++)
        {
            if(nums[i] < prev && flag++)   return false;
            if(nums[i] < prev && i - 2 >= 0 && nums[i-2] > nums[i]) continue;
            prev = nums[i];
        }
        return true;
    }
};

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
        Solution *s = new Solution();
        if(s->checkPossibility(v))
            cout<<"True"<<endl;
        else
            cout<<"False"<<endl;
    }
    return 0;
}