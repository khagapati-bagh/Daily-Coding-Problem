
# Daily Coding Problem: Problem #126 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

Write a function that rotates a list by k elements. For example, [1, 2, 3, 4, 5, 6] rotated by two becomes [3, 4, 5, 6, 1, 2]. Try solving this without creating a copy of the list. How many swap or move operations do you need?

**Solution** :

```cpp

#include <bits/stdc++.h>
using namespace std;

void print(vector<int>v){
    for(int i : v)
        cout<<i<<" ";
    cout<<endl;
}

void reverse(vector<int>&v, int left, int right){
    while(left < right){
        int tmp = v[left];
        v[left] = v[right];
        v[right] = tmp;
        left++, right--;
    }
}

void leftRotate(vector<int>&v, int n, int k){
    if(k >= n)
        return;
    reverse(v, 0, k-1);
    reverse(v, k, n-1);
    reverse(v, 0, n-1);
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        vector<int>v(n);
        for(int i = 0 ; i < n; i++)
            cin>>v[i];
        leftRotate(v, n, k);
        print(v);
    }
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/gmDVDqIlRf)**