/*
Daily Coding Problem: Problem #70 [Easy]
Good morning! Here's your coding interview problem for today.

This problem was asked by Microsoft.

A number is considered perfect if its digits sum up to exactly 10.

Given a positive integer n, return the n-th perfect number.

For example, given 1, you should return 19. Given 2, you should return 28.

Example
input
3
4 2 5
output
46
28
55

*/

//You can get my code in IDE https://ide.geeksforgeeks.org/nb3I7NUVOX
#include <bits/stdc++.h> 
using namespace std; 

/*int nth_perfect(int n)
{
    int cnt = 0;
    for(int curr = 19; ; curr +=9)
    {
        int sum = 0, x = curr;
        while(x)
        {
            sum += x%10;
            x /=10;
        }
        if(sum == 10)
            cnt++;
        if(n == cnt)
            return curr;
    }
    return -1;
}*/

int nth_perfect(int n)
{
    int nth_num = 19 + (n - 1) * 9;
    int outlines = (int)log10(nth_num) - 1;
    nth_num += 9 * outlines;
    return nth_num;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        cout<<nth_perfect(n)<<endl;
    }
    return 0;
}