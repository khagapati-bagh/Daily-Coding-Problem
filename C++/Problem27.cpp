/*
Daily Coding Problem: Problem #27 [Easy]
Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

Given a string of round, curly, and square open and closing brackets, return whether the brackets are balanced (well-formed).

For example, given the string "([])[]({})", you should return true.

Given the string "([)]" or "((()", you should return false.

Example
input

4
{([])}
()[]{}
([)]
{[]}

output

Valid Parentheses
Valid Parentheses
Not Valid Parentheses
Valid Parentheses

*/
// You can get my code in IDE https://ide.geeksforgeeks.org/3upCsTARkT
// https://leetcode.com/problems/valid-parentheses/discuss/293397/Simple-Solution-using-Stack-O(n)-Time-and-Space-Complexity-Runtime-4ms-97-faster
// This code will take O(n) Time and Space Complexity
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.empty()) return true;
        stack<char>paren;
        for(char c : s)
        {
            if(c=='[' || c == '{' || c == '(')
                paren.push(c);// when c is open bracket
            else
            {   //when c= ] || } || )
                if(!paren.empty() && Match(paren.top(),c))
                    paren.pop();
                else
                    return false;
            }
        }
        if(paren.empty()) //Stack must be empty for valid parentheses
            return true;
        return false;
    }
private:
    bool Match(char a, char b)
    {   // Corresponding bracket
        if((a =='[' && b ==']') || (a == '{' && b =='}') || (a == '(' && b == ')'))
            return true;
        return false;
            
    }
};

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution s;
        if(s.isValid(str))
            cout<<"Valid Parentheses"<<endl;
        else
            cout<<"Not Valid Parentheses"<<endl;
    }
	return 0;
}