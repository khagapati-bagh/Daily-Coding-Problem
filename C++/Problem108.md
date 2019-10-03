# Daily Coding Problem: Problem #108 [Easy]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given two strings A and B, return whether or not A can be shifted some number of times to get B.

For example, if A is abcde and B is cdeab, return true. If A is abc and B is acb, return false.

**Solution** : 

```cpp

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool rotateString(string A, string B) {
    return A.size() == B.size() && (A+A).find(B) != string :: npos;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        getchar();
        string a, b;
        cin>>a>>b;
        if(rotateString(a, b))
            cout<<"True"<<endl;
        else
            cout<<"False"<<endl;
    }
    return 0;
}

```
**[Run Code](https://ide.geeksforgeeks.org/GP3VbdmT7g)**