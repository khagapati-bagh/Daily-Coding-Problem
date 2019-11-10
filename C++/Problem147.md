
# Daily Coding Problem: Problem #147 [Hard]

Good morning! Here's your coding interview problem for today.

Given a list, sort it using this method: reverse(lst, i, j), which reverses lst from i to j.

**Solution** :

```cpp

#include <bits/stdc++.h>
#define print(v) for(int i : v) cout<<i<<" ";
using namespace std;

void reverse(vector<int>&v, int i, int j){
    if(i >= j)
        return;
    v[i] ^= v[j];
    v[j] ^= v[i];
    v[i] ^= v[j];
    return reverse(v, i+1, j-1);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, i, j;
        cin>>n>>i>>j;
        assert(i >= 0 && j < n);// abort if i and j out of range
        vector<int> v(n);
        for(int i = 0; i < n; i++)
            cin>>v[i];
        cout<<"Before reverse "<<i<<" to "<<j<<" : ";
        print(v);
        cout<<endl;
        reverse(v, i, j);
        cout<<"After  reverse "<<i<<" to "<<j<<" : ";
        print(v);
        cout<<endl;
    }
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/qlGqbr73RL)**