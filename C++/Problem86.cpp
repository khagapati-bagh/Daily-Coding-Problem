/*
Daily Coding Problem: Problem #86 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given a string of parentheses, write a function to compute the minimum number of parentheses to be removed to make the string valid (i.e. each open parenthesis is eventually closed).

For example, given the string "()())()", you should return 1. Given the string ")(", you should return 2, since we must remove all of them.

Example
input
3
()())()
()())()))
)()((

output
1
3
3

*/
//You can get my code in IDE https://ide.geeksforgeeks.org/uuCBnWaCmp

//This code will take O(n) Time and Space Complexity
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

bool check_paranthesis(char a, char b)
{
    return (a == '{' && b == '}') || (a == '(' && b ==')') || (a == '[' && b ==']');
}
int char_remove(string s)
{
    stack<char>st;
    for(auto c : s)
    {
        if(c == ')' || c == '}' || c == ']')
        {
            if(!st.empty() && check_paranthesis(st.top(), c))
            {   
                st.pop();
                continue;
            }
        }
        st.push(c);
    }
    return st.size();
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        getchar();
        string s;
        cin>>s;
        cout<<s<<endl;
        cout<<char_remove(s)<<endl;
    }
    return 0;
}