/*
Daily Coding Problem: Problem #77 [Easy]

Good morning! Here's your coding interview problem for today.

This problem was asked by Snapchat.

Given a list of possibly overlapping intervals, return a new list of intervals where all overlapping intervals have been merged.

The input list is not necessarily ordered in any way.

For example, given [(1, 3), (5, 8), (4, 10), (20, 25)], you should return [(1, 3), (4, 10), (20, 25)].

Example
input
2
4
1 5
6 7
8 9
9 11
4
4 10
1 3
5 8
20 25

output
[(1, 5), (6, 7), (8, 11)]
[(1, 3), (4, 10), (20, 25)]

*/

//You can get my code in IDE https://ide.geeksforgeeks.org/iAXOtA0APs
//This code will take O(n log n) Time and O(n) Space Complexity
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;

void print(vector<P>v)
{
    cout<<"[";
    for(int i = 0; i < v.size(); i++)
    {
        cout<<"("<<v[i].first<<", "<<v[i].second<<")";
        if(i < v.size() -1)
            cout<<", ";
    }
    cout<<"]"<<endl;
}

vector<P> merge_interval(vector<P>v)
{
    sort(v.begin(), v.end());
    //print(v);
    int n = v.size();
    if(n <= 1)
        return v;
    vector<P>res;
    P a = v[0];
    for(int i =1; i < n; i++)
    {
        if(v[i].first <= a.second)
            a.second = max(v[i].second, a.second);
        else
            res.push_back(a), a = v[i];
    }
    if(a != res.back())
        res.push_back(a);
    return res;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, x, y;
        cin>>n;
        vector<P>v;
        for(int i = 0; i < n; i++)
        {
            cin>>x>>y;
            v.push_back({x,y});
        }
        v = merge_interval(v);
        print(v);
    }
    return 0;
}