# Daily Coding Problem: Problem #111 [Hard]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given a word W and a string S, find all starting indices in S which are anagrams of W.

For example, given that W is "ab", and S is "abxaba", return 0, 3, and 4.

**Solution** : 

```cpp

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void startingIndexOfW(string s, string w){
    int n = s.size(), counter = w.size();
    if(counter > n)
        return;
    int start = 0, end = 0;
    unordered_map<char, int>map;
    for(char c : w)
        map[c]++;
    while(end < n){
        if(map[s[end++]]-- > 0) counter--;
        while(counter == 0){
            if(end - start == w.size())
                cout<<start<<" ";
            if(map[s[start++]]++ == 0)  counter++;
        }
    }
    cout<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        string w, s;
        cin>>s>>w;
        startingIndexOfW(s, w);
    }
    return 0;
}

```
**[Run Code](https://ide.geeksforgeeks.org/1OcTLSAXO8)**
