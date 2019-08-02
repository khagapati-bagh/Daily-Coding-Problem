/*
Daily Coding Problem: Problem #92 [Hard]
Good morning! Here's your coding interview problem for today.

This problem was asked by Airbnb.

We're given a hashmap associating each courseId key with a list of courseIds values, which represents that the prerequisites of courseId are courseIds. Return a sorted ordering of courses such that we can finish all courses.

Return null if there is no such ordering.

For example, given {'CSC300': ['CSC100', 'CSC200'], 'CSC200': ['CSC100'], 'CSC100': []}, should return ['CSC100', 'CSC200', 'CSCS300'].

Example
input
2
4
CSC100 CSC200 CSC300 CSC400
0 0
1 1 0
2 2 0 1
3 1 2
3
CSC100 CSC200 CSC300
2 2
0 1
1 1
0
0 0

output
CSC100 CSC200 CSC300 CSC400 
CSC100 CSC200 CSC300 

*/

//You can get my code in IDE https://ide.geeksforgeeks.org/m1cJh9T2xX
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>>v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout<<i<<" : ";
        for(int j : v[i])
            cout<<j<<" ";
        cout<<endl;
    }
}

void dfs(vector<vector<int>>adj, int src, vector<int>&color, vector<int>&res)
{
    color[src] = 1;
    for(int i = 0; i < adj[src].size(); i++)
    {
        if(color[i] == 0)
            dfs(adj, i, color, res);
    }
    color[src] = 2;
    res.push_back(src);
}

void print_result(vector<int>st, vector<string>v)
{
    for(int i = 0; i < st.size(); i++)
    {
        cout<<v[st[i]]<<" ";
    }
    cout<<endl;
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n, x, m, val;
	    cin>>n;
	    getchar();
	    vector<string>map(n);
	    vector<vector<int>>adj(n);
	    for(int i = 0; i < n; i++)
	    {
	        cin>>map[i];
	        //cout<<map[i]<<" ";
	    }
	    for(int i = 0; i < n; i++)
	    {
	        cin>>x>>m;
	        for(int j = 0; j < m; j++)
	        {
	            cin>>val;
	            adj[x].push_back(val);
	        }
	    }
	    //print(adj);
	    vector<int>color(n, 0);
	    vector<int>st;
	    for(int i = 0; i < n; i++)
	    {
	        if(color[i] == 0)
	            dfs(adj, i, color, st);
	    }
	    print_result(st, map);
	}
	return 0;
}
