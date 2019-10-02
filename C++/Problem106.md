# Daily Coding Problem: Problem #106 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Pinterest.

Given an integer list where each number represents the number of hops you can make, determine whether you can reach to the last index starting at index 0.

For example, [2, 0, 1, 0] returns True while [1, 1, 0, 1] returns False.

**Solution** : 

```cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //This code will take O(n) Time and O(1) Space Complexity
    bool canReach(vector<int>& nums) {
        /*//another solution
        int left_g = nums.size()-1;
        for(int i = nums.size()-2; i >= 0; i--)
        {
            if(i + nums[i] >= left_g)
                left_g = i;
        }
        return left_g == 0;
        */
        int end = 0, curfar = 0, n = nums.size();
        for(int i = 0; i < n - 1; i++){
            curfar = max(curfar, i + nums[i]);
            if(i == end)
                end = curfar;
        }
       return end >= n-1;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++)
            cin>>nums[i];
        Solution *obj = new Solution();
        if(obj->canReach(nums))
            cout<<"True"<<endl;
        else
            cout<<"False"<<endl;
    }
    return 0;
}

```
**[Run Code](https://ide.geeksforgeeks.org/jfpVRXfn0m)**