/*
Daily Coding Problem: Problem #76 [Medium]
Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

You are given an N by M 2D matrix of lowercase letters. Determine the minimum number of columns that can be removed to ensure that each row is ordered from top to bottom lexicographically. That is, the letter at each column is lexicographically later as you go down each row. It does not matter whether each row itself is ordered lexicographically.

For example, given the following table:

cba
daf
ghi
This is not ordered because of the a in the center. We can remove the second column to make it ordered:

ca
df
gi
So your function should return 1, since we only needed to remove 1 column.

As another example, given the following table:

abcdef
Your function should return 0, since the rows are already ordered (there's only one row).

As another example, given the following table:

zyx
wvu
tsr
Your function should return 3, since we would need to remove all the columns to order it.

Example
input
4
1 6
abcdef
3 3
zyx
wvu
tsr
3 3
cba
daf
ghi
3 2
ca
df
gi

output
0
3
1
0

*/
//You can get my code in IDE https://ide.geeksforgeeks.org/HNKLxoMWxG
//This code will take O(n^2) Time and O(1) Space Complexity
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int count_min(vector<string>v)
{
    int n = v.size(), m = n > 0 ? v[0].size() : 0, cnt = 0;
    
    for(int i = 0; i < m; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(v[j][i] < v[j-1][i])
            {
                cnt++;
                break;
            }
        }
    }
    return cnt;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin>>n>>m;
        vector<string>v;
        string s;
        for(int i = 0; i < n; i++)
        {
            cin>>s;
            v.push_back(s);
        }
        cout<<count_min(v)<<endl;
    }
    return 0;
}