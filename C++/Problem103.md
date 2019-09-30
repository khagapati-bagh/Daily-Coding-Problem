# Daily Coding Problem: Problem #103 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Square.

Given a string and a set of characters, return the shortest substring containing all the characters in the set.

For example, given the string "figehaeci" and the set of characters {a, e, i}, you should return "aeci".

If there is no substring containing all the characters in the set, return null.

**Solution** : 

```cpp

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string minWindow(string s, string t) {
    vector<int>map(128, 0);
    for(char c : t) map[c]++;
    int counter = t.size(), start = 0, end = 0, len = s.size()+1, begin = 0;
    while(end < s.size()){
        if(map[s[end++]]-- > 0) counter--;
        while(counter == 0){
            if(end - start < len) len = end - (begin = start);
            if(map[s[start++]]++ == 0) counter++;//for other characters
        }
    }
    return len == s.size()+1 ? "NULL" : s.substr(begin, len);
}
    
int main(){
    int t;
    cin>>t;
    while(t--){
        getchar();
        string s, t;
        cin>>s>>t;
        cout<<minWindow(s, t)<<endl;
    }
    return 0;
}

```
**[Run Code](https://ide.geeksforgeeks.org/Z3k5uAzn3d)**