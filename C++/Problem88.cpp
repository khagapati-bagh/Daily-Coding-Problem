/*
Daily Coding Problem: Problem #88 [Medium]
Good morning! Here's your coding interview problem for today.

This question was asked by ContextLogic.

Implement division of two positive integers without using the division, multiplication, or modulus operators. Return the quotient as an integer, ignoring the remainder.

Example
input
3
10 3
100000000 -55
2 19

output
3
-1818181
0

*/
//You can get my code in IDE https://ide.geeksforgeeks.org/8hHDKStxeH

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == 0)   return 0;
        long long res = double(exp(log(fabs(dividend)) - log(fabs(divisor))));
        if((dividend < 0) ^ (divisor < 0))  res = -res;
        if(res > INT_MAX) res = INT_MAX;
        return res;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x, y;
        cin>>x>>y;
        Solution s;
        cout<<s.divide(x,y)<<endl;
    }
    return 0;
}