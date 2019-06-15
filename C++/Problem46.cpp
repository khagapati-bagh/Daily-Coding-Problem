/*
Daily Coding Problem: Problem #46 [Hard]

Good morning! Here's your coding interview problem for today.

This problem was asked by Amazon.

Given a string, find the longest palindromic contiguous substring. If there are more than one with the maximum length, return any one.

For example, the longest palindromic substring of "aabcdcb" is "bcdcb". The longest palindromic substring of "bananas" is "anana".
Example
input
3
banana
aabcdcb
palindromepap

output
anana
bcdcb
pap

*/

//You can get my code in IDE https://ide.geeksforgeeks.org/L5wtKpePIN
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
//This code will take O(2^n) Time and O(n) Space Complexity
bool palindrome(string s)
{
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}
string longest_palindrome(string s)
{
    if(palindrome(s) || s.size() <= 1)
        return s;
    else
    {
        string s1 = longest_palindrome(s.substr(0,s.size()-1));
        string s2 = longest_palindrome(s.substr(1));
        return s1.size() >= s2.size() ? s1 : s2;
    }
    
}
*/
/*
//This code will take O(n^2) Time and Space Complexity
string longest_palindrome(string s)
{
    int n = s.size(), start = 0, maxLen = 1;
    vector<vector<int>>dp(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++)
    {
        dp[i][i] = 1;
        if(i < n-1 && s[i] == s[i+1])//Substring of size 2
        {
            dp[i][i+1] = 1;
            if(start == 0)
                start = i;
            maxLen = 2;
        }
    }
    for(int k = 3; k <= n; k++)
    {
        for(int i = 0; i <= n-k; i++)
        {
            int j = i + k - 1;
            if(dp[i+1][j-1] && s[i] == s[j])
            {
                dp[i][j] = 1;
                if(k > maxLen)
                {
                    start = i;
                    maxLen = k;
                }
            }
        }
    }
    return s.substr(start, maxLen);
}
*/

//This code will take O(n^2) Time and O(1) Space Complexity
void find_longest(string s, int low, int high, int &start, int &maxLen)
{
    int n = s.size();
    while(low >= 0 && high < n && s[low] == s[high])
    {
        if(high - low + 1  > maxLen)
        {
            start = low;
            maxLen = high - low + 1;
        }
        low--, high++;
    }
}
string longest_palindrome(string s)
{
    int maxLen = 1, start = 0, low, high, n = s.size();
    
    for(int i = 1; i < n; i++)
    {
        low = i-1, high = i;
        find_longest(s, low, high, start, maxLen);
        high = i+1;
        find_longest(s, low, high, start, maxLen);
    }
    return s.substr(start, maxLen);
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    cout<<longest_palindrome(s)<<endl;
	}
	return 0;
}