
# Daily Coding Problem: Problem #114 [Hard]

Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

Given a string and a set of delimiters, reverse the words in the string while maintaining the relative order of the delimiters. For example, given "hello/world:here", return "here/world:hello"

Follow-up: Does your solution work for the following cases: "hello/world:here/", "hello//world:here"

**Solution** :

```cpp

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//This code will take O(n) Time and O(1) Space complexity
class Solution {
public:
    string reverseWords(string s) {
        reverse(s, 0, s.size() - 1);
        int start = 0, end = 0;
        for(int i = 0; i < s.size(); i++){
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
                s[end] = s[i];
            else{
                reverse(s, start, end-1);
                start = i + 1;
            }
            end++;
        }
        reverse(s, start, end - 1);
        return s;
    }
    void reverse(string &s, int left, int right){
        while(left < right){
            char tmp = s[left];
            s[left++] = s[right];
            s[right--] = tmp;
        }
    }
};

int main(){
    int t;
    cin>>t;
    getchar();
    while(t--){
        string s;
        getline(cin, s);
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/lckynK14yw)**