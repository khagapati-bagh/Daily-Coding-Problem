/*
Daily Coding Problem: Problem #69 [Easy]
Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

Given a list of integers, return the largest product that can be made by multiplying any three integers.

For example, if the list is [-10, -10, 5, 2], we should return 500, since that's -10 * -10 * 5.

You can assume the list has at least three integers.

Example
input
2
4
-10 5 -10 0
6
0 -1 3 100 70 50

output
500
350000


*/

// You can get my code in IDE https://ide.geeksforgeeks.org/HrFURAt51n
#include <bits/stdc++.h> 
using namespace std; 
//This code will take O(n) Time complexity
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size(), max_element = 0;
        if(n < 3)
            return 0;
        else if(n == 3)
            return accumulate(nums.begin(), nums.end(), 1, multiplies<int>());
        priority_queue<int>max_heap;
        priority_queue<int, vector<int>, greater<int>>min_heap;
        for(int i : nums)
        {
            if(i >= 0)
            {
                if(min_heap.size()== 3)
                {
                    if(min_heap.top() < i)
                        min_heap.pop();
                    else
                        continue;
                }
                max_element = i > max_element ? i : max_element;
                min_heap.push(i);
            }
            else
            {
                if(max_heap.size() == 2)
                {
                    if(max_heap.top() > i)
                        max_heap.pop();
                    else
                        continue;
                }
                max_heap.push(i);
            }
        }
        int min_res = 1;
        while(!min_heap.empty())
        {
            min_res *= min_heap.top();
            min_heap.pop();
        }
        if(max_heap.size() == 2)
        {
            while(!max_heap.empty())
            {
                max_element *= max_heap.top();
                max_heap.pop();
            }
            min_res = max_element > min_res ? max_element : min_res;
        }
        return min_res;
    }
};
/*
// This code will take O(n log n) Time complexity
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        if(n < 3)
            return 0;
        else if(n == 3)
            return accumulate(nums.begin(), nums.end(), 1, multiplies<int>());
        sort(nums.begin(), nums.end());
        int res = nums[n-1] * nums[n-2] * nums[n-3];
        int n_res = nums[0] * nums[1] * nums[n-1];
        res = res > n_res ? res : n_res;
        return res;
    }
};
*/
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n, x, max_element = 0;
	    cin>>n;
	    vector<int>v(n);
	    for(int i = 0; i < n; i++)
	        cin>>v[i];
	    Solution *p = new Solution();
	    cout<<p->maximumProduct(v)<<endl;
	}
	return 0;
}