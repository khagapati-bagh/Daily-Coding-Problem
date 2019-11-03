
# Daily Coding Problem: Problem #140 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

Given an array of integers in which two elements appear exactly once and all other elements appear exactly twice, find the two elements that appear only once.

For example, given the array [2, 4, 6, 8, 10, 2, 6, 10], return 4 and 8. The order does not matter.

Follow-up: Can you do this in linear time and constant space?

**Solution** :

```cpp

#include <bits/stdc++.h>
using namespace std;

void twoUniqueNumber(vector<int>v){
    int Xor = 0, x = 0, y = 0;
    for(int i : v)
        Xor ^= i;
    int rightMostSetbit = Xor & ~(Xor - 1);
    for(int i : v){
        if(i&rightMostSetbit)
            x ^= i;
        else 
            y ^= i;
    }
    cout<<x<<" "<<y<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i = 0; i < n; i++)
            cin>>v[i];
        twoUniqueNumber(v);
    }
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/fLzb3D37e2)**