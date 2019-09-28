# Daily Coding Problem: Problem #99 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Microsoft.

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example, given [100, 4, 200, 1, 3, 2], the longest consecutive element sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.

**Solution** :

```cpp

#include <bits/stdc++.h>
using namespace std;

//This code will take O(n) Time and Space Complexity
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int res = 0;
        unordered_map<int, int>mp;
        for(int i : nums){
            if(mp.find(i) != mp.end())
                continue;
            int left = mp.find(i - 1) != mp.end() ? mp[i - 1] : 0;
            int right = mp.find(i + 1) != mp.end() ? mp[i + 1] : 0;
            int sum = left + right + 1;
            res = sum > res ? sum : res;
            if(left > 0) mp[i - left] = sum;
            if(right > 0) mp[i + right] = sum;
            mp[i] = sum;
        }
        return res;
    }
};

//This code will take O(n log n) Time and O(1) Space Complexity
class Solution1 {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        sort(nums.begin(), nums.end());
        int max_length = 0, cnt = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] == nums[i]) continue;
            if(nums[i-1] + 1 == nums[i])
                cnt++;
            else{
                max_length = max_length < cnt ? cnt : max_length;
                cnt = 1;
            }
        }
        max_length = max_length < cnt ? cnt : max_length;
        return max_length;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i = 0; i < n; i++)
            cin>>v[i];
        Solution *obj = new Solution();
        cout<<obj->longestConsecutive(v)<<endl;
        /*Solution1 *obj1 = new Solution1();
        cout<<obj1->longestConsecutive(v)<<endl;*/
    }
    return 0;
}

```
**[Run Code](https://ide.geeksforgeeks.org/zYCSwiXgPQ)**{:target="_blank"}
