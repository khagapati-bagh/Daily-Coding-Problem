/*
Daily Coding Problem: Problem #61 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Implement integer exponentiation. That is, implement the pow(x, y) function, where x and y are integers and returns x^y.

Do this faster than the naive method of repeated multiplication.

For example, pow(2, 10) should return 1024.
Example
input
5
3 5
10 5
11 6
7 8
2 10

output
243 243
100000 100000
1771561 1.77156e+06
5764801 5.7648e+06
1024 1024

*/
//You can get my code in IDE https://ide.geeksforgeeks.org/NgxfxWlfCc
//This code will take O(log y) Time and O(y) Space Complexity
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

long power(int x, int y, vector<int>&v)
{
    if(y == 0)
        v[y] = 1;
    else if(y == 1)
        v[y] = x;
        
    if(v[y] != 0)
        return v[y];
    v[y] = power(x,y/2,v) * power(x, y/2, v);
    if(y & 1)
        v[y] *= x;
    return v[y];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x, y;
        cin>>x>>y;
        vector<int>v(y+1, 0);
        cout<<power(x,y, v)<<" "<<pow(x,y)<<endl;
    }
    return 0;
}