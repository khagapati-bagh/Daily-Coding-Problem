# Daily Coding Problem: Problem #143 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Amazon.

Given a pivot x, and a list lst, partition the list into three parts.

The first part contains all elements in lst that are less than x
The second part contains all elements in lst that are equal to x
The third part contains all elements in lst that are larger than x
Ordering within a part can be arbitrary.

For example, given x = 10 and lst = [9, 12, 3, 5, 14, 10, 10], one partition may be [9, 3, 5, 10, 10, 12, 14].

**Solution** :

```cpp

#include <bits/stdc++.h>
using namespace std;

void print(vector<int>v){
    for(int i : v)
        cout<<i<<" ";
    cout<<endl;
}

void partitionListInto3Parts(vector<int>&v, int pivot){
    int n = v.size() - 1, mid = 0, i;
    bool step = true;
    for(i = 0; i <= n - mid; i++){
        if(mid && step) v[i] = v[i + mid];
        if(v[i] > pivot){
            if(v[n] == pivot){
                v[n--] = v[i];
                v[i] = v[i + (++mid)];
            }
            else{
                swap(v[i], v[n--]);
                step = false;
            }
            i--;
        }
        else if(v[i] == pivot){
            mid++, i--;
        }
    }
    while(mid--)    v[i++] = pivot;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, x;
        cin>>n>>x;
        vector<int>v(n);
        for(int i = 0; i < n; i++)
            cin>>v[i];
        cout<<"before partition : ";
        print(v);
        partitionListInto3Parts(v, x);
        cout<<"After partition  : ";
        print(v);
    }
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/9vvphEBE5R)**