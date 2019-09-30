# Daily Coding Problem: Problem #102 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Lyft.

Given a list of integers and a number K, return which contiguous elements of the list sum to K.

For example, if the list is [1, 2, 3, 4, 5] and K is 9, then it should return [2, 3, 4], since 2 + 3 + 4 = 9.

**Solution** : 

```cpp

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(vector<int>nums, int low, int high){
    for(int i = low; i <= high; i++)
        cout<<nums[i]<<" ";
    cout<<endl;
}
//This code will take O(n) Time and Space Complexity
void subarraySum(vector<int> nums, int target){
    int n = nums.size(), curr_sum = 0;
    unordered_map<int, int>mp;
    
    for(int i = 0; i < n; i++){
        curr_sum += nums[i];
        if(curr_sum == target){
            print(nums, 0, i);
            return;
        }
        if(mp.find(curr_sum - target) != mp.end()){
            print(nums, mp[curr_sum - target], i);
            return;
        }
        mp[curr_sum] = i+1;
    }
    cout<<"Not found"<<endl;
}

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int n, target;
        cin>>n>>target;
        vector<int> nums(n);
        for(int i = 0; i < n; i++)
            cin>>nums[i];
        subarraySum(nums, target);
    }
    return 0;
}

```
**[Run Code](https://ide.geeksforgeeks.org/t6vbIcVpoQ)**