
# Daily Coding Problem: Problem #118 [Easy]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given a sorted list of integers, square the elements and give the output in sorted order.

For example, given [-9, -2, 0, 2, 3], return [0, 4, 4, 9, 81].

**Solution** :

```cpp

#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

void print(vi v){
    for(int i : v)
        cout<<i<<" ";
    cout<<endl;
}

//This code will take O(n) Time and Space Complexity
vi sortedSquares(vi& A) {
    int n = A.size(), j = 0, k = n-1;//two pointer pointing to first and last
    if(n == 0)  return A;
    vector<int>res(n);
    for(int i = n-1; i >= 0; i--)//check which absulute value is greater and put that one
        res[i] = abs(A[k]) > abs(A[j]) ? pow(A[k--], 2) : pow(A[j++], 2);
    return res;
}
    
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vi v(n);
        for(int i = 0; i < n; i++)
            cin>>v[i];
        v = sortedSquares(v);
        print(v);
    }
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/W69cJVNURP)**