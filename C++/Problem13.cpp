/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Amazon.

Given an integer k and a string s, find the length of the longest substring that contains at most k distinct characters.

For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".

example :
input:
2
abcba  3
abcabcaaabbbcbcbbcbccaddddbbbcccd 3

output:
abcba
abcabcaaabbbcbcbbcbcca


*/
// You can get my code directyly on the ide by this link https://ide.geeksforgeeks.org/JxcJLQkM68
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string longest_substring(string str, int k)
{
    if(str.empty())
        return str;
    unordered_map<char, bool>mp; //for checking 
    string res = "",tmp;
    int cnt=0;
    for(int i = 0; i < str.size(); i++)
    {
        char  c = str[i];
        
        if((cnt < k) || (cnt >= k && mp.find(c) != mp.end())) // if char. < k or char. <= k and they are same char.
        {
            tmp += c;
            if(cnt < k && mp.find(c) == mp.end()) //if not present  in map
            {
                cnt++;
                mp[c]=true;
            }
        }
        else
        {
            res = (res.size() < tmp.size() ? tmp : res); //logest string
            auto it = tmp.rfind(tmp[0]); //last occurance of first char.
            mp.erase(tmp[0]);   //erase from map
            tmp.erase(tmp.begin(),tmp.begin()+it+1);//erase the tmp string upto the last occurance of first char.
            tmp += c; //add new char
            mp[c] = true; //insert in map
        }
    }
    
    res = (res.size() < tmp.size() ? tmp : res);
    return res;
}

int i;
int main() {
    int t;
    cin>>t; // Test case
    while(t--)
    {
        string str;
        cin>>str; //input string
        int k;
        cin>>k;
        cout<<longest_substring(str,k)<<endl;
    }
    return 0;
}