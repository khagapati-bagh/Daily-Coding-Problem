/*
Daily Coding Problem: Problem #19 [Medium]
Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

A builder is looking to build a row of N houses that can be of K different colors. 
He has a goal of minimizing cost while ensuring that no two neighboring houses are of the same color.

Given an N by K matrix where the nth row and kth column represents the cost to build 
the nth house with kth color, return the minimum cost which achieves this goal.

Example
input
2 3
11 12 13
14 15 16

output
26

input
3 3
17 2 17
16 16 5
14 3 19

output
10
*/
// You can get my code in IDE link : https://ide.geeksforgeeks.org/ZYselQDzfm
// Video reference to the problem : https://www.youtube.com/watch?v=fZIsEPhSBgM
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print_1d(vector<int>v) //Additional function for printing 1D
{
    for(int a:v)
        cout<<a<<' ';
    cout<<endl;
}
void print(vector<vector<int>>v) // Additional function for printing 2D
{
    for(int i = 0 ; i < v.size(); i++)
    {
        for(int j : v[i])
            cout<<j<<' ';
        cout<<endl;
    }
}

int minCost(vector<vector<int>>cost){
    if(cost.size() == 0) 
        return 0;
    int n = cost.size();;
    
    for(int i = 1; i < n; i++) //I start from 2nd row because first row is as it is
    {
        int m =cost[i].size();
        for(int j = 0; j < m; j++)
        {
            vector<int>tmp;
            copy(cost[i-1].begin(), cost[i-1].end(),back_inserter(tmp)); // Previeous row
            tmp.erase(tmp.begin()+j); //erase the current row value
            auto it = min_element(tmp.begin(), tmp.end()); // min value from previeous row
            cost[i][j] +=*it; //add to the current value
        }
    }
    auto it = min_element(cost[n-1].begin(), cost[n-1].end()); //Min element from last row
    return *it;
}

int main() {
    int n,k;
    cin>>n>>k;
    vector<vector<int>>cost;
    for(int i =0 ; i < n; i++)
    {
        vector<int>tmp(k);
        for(int j = 0; j < k; j++)
        {
            cin>>tmp[j];
        }
        cost.push_back(tmp);
    }
    cout<<minCost(cost)<<endl;
    
	return 0;
}