# Daily Coding Problem: Problem #149 [Hard]

Good morning! Here's your coding interview problem for today.

This problem was asked by Goldman Sachs.

Given a list of numbers L, implement a method sum(i, j) which returns the sum from the sublist L[i:j] (including i, excluding j).

For example, given L = [1, 2, 3, 4, 5], sum(1, 3) should return sum([2, 3]), which is 5.

You can assume that you can do some pre-processing. sum() should be optimized over the pre-processing step.

**Solution** :

```cpp

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, q;
        cin>>n>>q;
        vector<int>list(n);
        for(int i = 0; i < n; i++){
            cin>>list[i];
            if(i > 0)
                list[i] += list[i-1];
        }
        for(int k = 0; k < q; k++){
            int i, j;
            cin>>i>>j;
            assert(i >= 0 && i <= j && j <= n);
            int res = i > 0 ? list[j-1] - list[i-1] : list[j-1];
            cout<<res<<endl;
        }
    }
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/aodVkv8kFT)**