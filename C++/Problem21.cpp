/*
Daily Coding Problem: Problem #21 [Easy]
Good morning! Here's your coding interview problem for today.

This problem was asked by Snapchat.

Given an array of time intervals (start, end) for classroom lectures (possibly overlapping), find the minimum number of rooms required.

For example, given [(30, 75), (0, 50), (60, 150)], you should return 2.

Example
input
2
6 
900  910
940 1200
950 1120
1100 1130
1500 1900
1800 2000
4
30 75
0 50
60 150
160 180

output
3
2
*/

//Both the approach will Take O(nlogn) Time and O(n) Space Complexity
//Yoc can get my code in IDE link : https://ide.geeksforgeeks.org/8fZnIZ2nsm
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int>>v){
    for(int i = 0; i < v.size(); i++)
    {
        for(int j : v[i])
            cout<<j<<' ';
        cout<<endl;
    }
}

int minimum_evnts(vector<vector<int>>interval){
    if(interval.size() == 0)
        return 0;

    //Using priority queue
    sort(interval.begin(), interval.end());
    priority_queue<int>pq;
    int res = 0;
    for(int i =0; i < interval.size(); i++)
    {
        while(!pq.empty() && -pq.top() < interval[i][0])
            pq.pop();
        pq.push(-interval[i][1]);
        res = max(res, (int)pq.size());
    }
    return res;

    // this is another approach you can comment the above code and uncomment the below code and check

    /*
    //Using map
    map<int, int>mp;
    int res = 0, cnt = 0;
    for(int i = 0; i < interval.size(); i++){
        mp[interval[i][0]]++;
        mp[interval[i][1]]--;
    }
    for(auto it : mp){
        //cout<<it.first<<" "<<it.second<<endl;
        cnt += it.second;
        res = max(res, cnt);
    }
    return res;
    */
}
int main(){
    int t;
    cin>>t; // test case
    while(t--){
        int n,i,start,end;
        cin>>n;
        vector<vector<int>>interval(n);
        for(i = 0; i < n; i++)
        {
            cin>>start>>end;
            interval[i].push_back(start);
            interval[i].push_back(end);
        }
        //print(interval);
        cout<<minimum_evnts(interval)<<endl;
    }
    return 0;
}