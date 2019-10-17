
# Daily Coding Problem: Problem #123 [Hard]

Good morning! Here's your coding interview problem for today.

This problem was asked by LinkedIn.

Given a string, return whether it represents a number. Here are the different kinds of numbers:

"10", a positive integer
"-10", a negative integer
"10.1", a positive real number
"-10.1", a negative real number
"1e5", a number in scientific notation
And here are examples of non-numbers:

"a"
"x 1"
"a -2"
"-"

**Solution** :

```cpp

#include <bits/stdc++.h>
using namespace std;

bool checkForNumber(string s){
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '.' || (s[i] >= '0' && s[i] <= '9') || (s[i] == 'e' && i > 0 && i < s.size()-1) ||
        (s[i] == '-' && i == 0 && s.size() > 1))
        {
            
        }
        else 
            return false;
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        string number;
        cin>>number;
        cout<<number<<"\t";
        checkForNumber(number) ? cout<<" is a number"<<endl : cout<<" is not a number"<<endl;
    }
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/XyvC4RHOZY)**