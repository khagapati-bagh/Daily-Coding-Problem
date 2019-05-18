/*
Daily Coding Problem: Problem #18 [Hard]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given an array of integers and a number k, where 1 <= k <= length of the array, 
compute the maximum values of each subarray of length k.

For example, given array = [10, 5, 2, 7, 8, 7] and k = 3, we should get: [10, 7, 8, 8], since:

10 = max(10, 5, 2)
7 = max(5, 2, 7)
8 = max(2, 7, 8)
8 = max(7, 8, 7)
Do this in O(n) time and O(k) space. You can modify the input array in-place and you do not 
need to store the results. You can simply print them out as you compute them.

Example 
input 
2
6 3
10 5 2 7 8 7
8 3
1 3 -1 -3  5 3 6 7

output
10 7 8 8 
3 3 5 5 6 7 

*/ // Here you will get my code in IDE link : https://ide.geeksforgeeks.org/pIYJEKi73l
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.empty()) return nums; //if nums is empty
        deque<int>slide; //storing index
        for(int i = 0; i < k; i++)
        {   //first make window of size k and only put which is greater
            while(!slide.empty() && nums[i] >= nums[slide.back()])
                slide.pop_back(); //if the current value is greater than old value of dequeue
            slide.push_back(i);
        }
        vector<int>res;
        for(int i = k; i < nums.size(); i++)
        {
            res.push_back(nums[slide.front()]); // result 
            while(!slide.empty() && nums[i] >= nums[slide.back()])
                slide.pop_back();// same as above
            
            //When the front index not lies in the window 
            while(!slide.empty() && slide.front() <= i - k)
                slide.pop_front();
            slide.push_back(i);
        }
        res.push_back(nums[slide.front()]);//for last windows
        return res;
    }
};

int main()
{
    /* code */
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n>>k;
        vector<int> v(n);
        for(i=0;i<n;i++)
            cin>>v[i];
        Solution *res = new Solution; //Create object
        vector<int>ans;
        ans = res->maxSlidingWindow(v,k);
        for(int a : ans)
            cout<<a<<' ';
        cout<<endl;
        delete res;
    }
    return 0;
}
