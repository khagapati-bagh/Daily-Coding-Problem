/*
Daily Coding Problem: Problem #34 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Quora.

Given a string, find the palindrome that can be made by inserting the fewest number of characters as 
possible anywhere in the word. If there is more than one palindrome of minimum length that can be made, 
return the lexicographically earliest one (the first one alphabetically).

For example, given the string "race", you should return "ecarace", since we can add three letters to it 
(which is the smallest amount to make a palindrome). There are seven other palindromes that can be made 
from "race" by adding three letters, but "ecarace" comes first alphabetically.

As another example, given the string "google", you should return "elgoogle".

Example
input
7
google
egoogle
race
abc
lool
elgoog
racecar

output
elgoogle
elgoogle
racecar
abcba
lool
elgoogle
racecar
*/
//You can get my code in IDE https://ide.geeksforgeeks.org/t8ud7H7HiW
//O(2^n) will be the time complexity
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool is_palindrome(string s)
{
    string s1 = s;
    reverse(s.begin(), s.end());
    return s == s1 ? true : false;
}
string get_nearest_palindrome(string s)
{
    if(is_palindrome(s))
        return s;
    int n = s.size();
    if(s[0] == s[n-1])//first and last char are same
        return s[0] + get_nearest_palindrome(s.substr(1,n-2)) + s[n-1];
    else
    {
        string s1 = s[0] + get_nearest_palindrome(s.substr(1)) + s[0];//append first char at end
        string s2 = s[n-1] + get_nearest_palindrome(s.substr(0, n-1)) + s[n-1];//append last char at begin
        if(s1.size() > s2.size())//return the smallest palindrome
            return s2;
        else
            return s1;
    }
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    cout<<get_nearest_palindrome(s)<<endl;
	}
	return 0;
}