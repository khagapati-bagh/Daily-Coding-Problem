/*
Daily Coding Problem: Problem #85 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

Given three 32-bit integers x, y, and b, return x if b is 1 and y if b is 0, using only mathematical or bit operations. You can assume b can only be 1 or 0.

Example
input
4
45666666666666
6666666666666666666
1
45666666666666
6666666666666666666
0
1212121
32323232 
0
11111111111111
33333333333
1

output
45666666666666
6666666666666666666
32323232
11111111111111


*/
//You can get my code in IDE https://ide.geeksforgeeks.org/oEacyy7awU
//This code will take O(1) Time and Space Complexity
#include <bits/stdc++.h>
using namespace std;
unsigned long helper(unsigned long x, unsigned long y, unsigned long b)
{
    return x * b + y * (1-b);
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        unsigned long x, y, b;
        cin>>x>>y>>b;
        /*if(b & 1)
            cout<<x<<endl;
        else
        cout<<y<<endl;*/
        cout<<helper(x, y, b)<<endl;
    }
    return 0;
}