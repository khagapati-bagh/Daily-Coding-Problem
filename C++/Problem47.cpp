/*
Daily Coding Problem: Problem #47 [Easy]

Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

Given a array of numbers representing the stock prices of a company in chronological order, write a function that calculates 
the maximum profit you could have made from buying and selling that stock once. You must buy before you can sell it.

For example, given [9, 11, 8, 5, 7, 10], you should return 5, since you could buy the stock at 5 dollars and sell it at 10 dollars.

Example
input
2
4
0 6 -3 7
6
7 1 5 3 6 4

output
10
5

*/
//You can get my code in IDE https://ide.geeksforgeeks.org/EkvH1L4vkf
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
//This code will take O(nlogn) Time and O(1) space complexity
int max_profit(vector<int>stock)
{
    int profit = 0, n =stock.size();
    
    for(int i = 1; i < n; i++)
    {
        int mn = *min_element(stock.begin(), stock.begin()+ i);
        int mx = *max_element(stock.begin() + i, stock.end());
        if(mx - mn > profit)
            profit = mx - mn;
    }
    return profit;
}
*/
/*Approach
min_price is the minimum price from day 0 to day i. And profit is the maximum profit we can get from day 0 to day i.
How to get profit (max profit)? Just get the larger one between current profit and prices[i] - min_price.
*/

//This code will take O(n) Time and O(1) space complexity
/*
int max_profit(vector<int>prices)
{
    int min_price = INT_MAX, profit = 0;
    for(int i = 0; i < prices.size(); i++)
    {
        min_price = min(min_price, prices[i]);
        profit = max(profit, prices[i] - min_price);
    }
    return profit;
}

*/

/*
Small changes
We only need to calculate either profit (max profit) or min_price not both in every loop
*/

//This code will take O(n) Time and O(1) space complexity
/*
int max_profit(vector<int>prices)
{
    if(prices.size() <= 1)
            return 0;
    int min_price = prices[0], profit = 0;
    for(int i = 1; i < prices.size(); i++)
    {
        if(prices[i] > prices[i-1])
            profit = max(profit, prices[i] - min_price);
        else
            min_price = min(min_price, prices[i]);
    }
    return profit;
}
*/
/*
Approach
The logic to solve this problem is same as "max subarray problem" using Kadane's Algorithm

Here, the logic is to calculate the difference (curMax += prices[i] - prices[i-1]) of the original array, and find a contiguous subarray giving maximum profit. If the difference falls below 0, reset it to zero.
curMax = Current maximum value
maxSoFar = Maximum value so far
*/
// This code will take O(n) Time and O(1) space complexity
int max_profit(vector<int>prices)
{
    int curMax = 0, maxSoFar = 0;
    for(int i = 1; i < prices.size(); i++)
    {
        curMax = max(0, curMax += prices[i] - prices[i-1]); // current max value
        maxSoFar = max(maxSoFar, curMax);//max profit so far
    }
    return maxSoFar;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int>stock(n);
        for(int i = 0; i < n; i++)
            cin>>stock[i];
        cout<<max_profit(stock)<<endl;
    }
    return 0;
}