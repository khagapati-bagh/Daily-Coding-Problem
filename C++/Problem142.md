
# Daily Coding Problem: Problem #142 [Hard]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

You're given a string consisting solely of (, ), and *. * can represent either a (, ), or an empty string. Determine whether the parentheses are balanced.
For example, (()* and (*) are balanced. )*( is not balanced.

**Solution** :

```cpp

#include <bits/stdc++.h>
using namespace std;

bool checkParenthesis(string s, stack<char>st){
    if(s.empty() && st.empty()) return true;
    else if(s.empty())  return false;
    char c = s[0];
    string rem = s.substr(1);
    if(c == '*')
        return checkParenthesis('('+rem, st) || checkParenthesis(')' + rem, st) || checkParenthesis(rem, st);
    stack<char>cstack= st;
    if(c == ')' && st.empty())
        return false;
    else if(c == ')')
        cstack.pop();
    else
        cstack.push(c);
    return checkParenthesis(rem, cstack);
}

int main() {
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        stack<char>st;
        checkParenthesis(s, st) ? cout<<"Balanced"<<endl : cout<<"Unbalanced"<<endl;
    }
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/gcPMa81DUx)**