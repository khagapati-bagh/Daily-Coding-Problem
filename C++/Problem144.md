# Daily Coding Problem: Problem #144 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given an array of numbers and an index i, return the index of the nearest larger number of the number at index i, where distance is measured in array indices.

For example, given [4, 1, 3, 5, 6] and index 0, you should return 3.

If two distances to larger numbers are the equal, then return any one of them. If the array at i doesn't have a nearest larger integer, then return null.

Follow-up: If you can preprocess the array, can you do this in constant time?

**Solution** :

```cpp

#include <bits/stdc++.h>
using namespace std;

void nearestLargeNumberIndex(vector<int>v, int index){
    int n = v.size(), left = index != 0 ? index - 1 : 0, right = n-1 != index ? index + 1 : index;
    while((left >= 0 || right < n) && ((left >= 0 && v[left] < v[index]) || (right < n && v[right] < v[index]))){
        if(left >= 0)
            left--;
        if(right)
            right++;
    }
    if(right < n && v[right] > v[index])
        cout<<right<<endl;
    else if(left >= 0 && v[left] > v[index])
        cout<<left<<endl;
    else 
        cout<<-1<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, index;
        cin>>n>>index;
        vector<int>v(n);
        for(int i = 0; i <n; i++)
            cin>>v[i];
        nearestLargeNumberIndex(v, index);
    }
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/fYgq4bWi7K)**