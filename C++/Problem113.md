
# Daily Coding Problem: Problem #113 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given a string of words delimited by spaces, reverse the words in string. For example, given "hello world here", return "here world hello"

Follow-up: given a mutable string representation, can you perform this operation in-place?

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
            if(s[i] != ' ')
                s[end++] = s[i];
            else if(i > 0 && s[i-1] != ' '){
                reverse(s, start, end - 1);
                s[end++] = ' ';
                start = end;
            }
        }
        reverse(s, start, end - 1);
        s.erase(end, s.size() - end);
        if(s[s.size() - 1] == ' ')
            s.erase(s.size()-1);
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
/*
//using stringstream
class Solution {
public:
    string reverseWords(string s) {
        string res, word;
        stringstream str(s);
        while(str >> word)
            res = word + " " +res;
        if(res[res.size() -1])
            res.erase(res.size() - 1);
        return res;
    }
};

*/

int main(){
    int t;
    cin>>t;
    while(t--){
        getchar();
        string s;
        getline(cin, s);
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/XY6LuqcMnF)**