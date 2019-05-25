/*
Daily Coding Problem: Problem #25 [Hard]
Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

Implement regular expression matching with the following special characters:

. (period) which matches any single character
* (asterisk) which matches zero or more of the preceding element
That is, implement a function that takes in a string and a valid regular 
expression and returns whether or not the string matches the regular expression.

For example, given the regular expression "ra." and the string "ray", your function 
should return true. The same regular expression on the string "raymond" should return false.

Given the regular expression ".*at" and the string "chat", your function should return true. 
The same regular expression on the string "chats" should return false.

Example
input

.at
3
hats
chat
hat

output

Case #1: 
hats : false
Case #2: 
chat : false
Case #3: 
hat : true

input
.*at
3
hats
chat
hat

output
Case #1: 
hats : false
Case #2: 
chat : true
Case #3: 
hat : true

*/
//You can get my code on IDE https://ide.geeksforgeeks.org/6YlXv7OtRQ
// resources for regular expression https://www.geeksforgeeks.org/regex-regular-expression-in-c/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    
    string reg;
    cin>>reg;//Enter ther regular expression
    regex r(reg);
    int t;
    cin>>t;//test case
    getchar();
    for(int i = 1; i <= t; i++)
    {
        string s;
        getline(cin, s);//Enter the string 
        cout<<"Case #"<<i<<": "<<endl<<s<<" : ";
        if(regex_match(s, r))
            cout<<"true"<<endl;
        else
            cout<<"false"<<endl;
        /* 
        //for other regular operation
        smatch m;
        regex_search(s, m, r);
        for(auto x : m)
            cout<<x;
        cout<<endl;
        string res;
        regex_replace(back_inserter(res), s.begin(), s.end(), r, "Bagh");
        cout<<res<<endl;
        */
    }
	return 0;
}