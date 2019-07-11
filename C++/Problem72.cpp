/*
Daily Coding Problem: Problem #72 [Hard]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

In a directed graph, each node is assigned an uppercase letter. We define a path's value as the number of most frequently-occurring letter along that path. For example, if a path in the graph goes through "ABACA", the value of the path is 3, since there are 3 occurrences of 'A' on the path.

Given a graph with n nodes and m directed edges, return the largest value path of the graph. If the largest value is infinite, then return null.

The graph is represented with a string and an edge list. The i-th character represents the uppercase letter of the i-th node. Each tuple in the edge list (i, j) means there is a directed edge from the i-th node to the j-th node. Self-edges are possible, as well as multi-edges.

For example, the following input graph:

ABACA
[(0, 1),
 (0, 2),
 (2, 3),
 (3, 4)]
Would have maximum value 3 using the path of vertices [0, 2, 3, 4], (A, A, C, A).

The following input graph:

A
[(0, 0)]
Should return null, since we have an infinite loop.

Example
input
3
1 1
A
0 0
3 2
ABC
0 1 
1 2
10 8
ABACARADHE
0 1 
0 2
2 3 
3 4 
5 8
8 9
9 7
7 6

output
NULL
ABC
RHEDA

*/
#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<int>>v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout<<i<<" : ";
        for(int j : v[i])
            cout<<j<<' ';
        cout<<endl;
    }
}

void print_stack(stack<int>st)
{
    while(!st.empty())
    {
        cout<<st.top()<<" -- ";
        st.pop();
    }
    cout<<endl;
}
 struct ListNode {
    int color, dist, par;
    ListNode() : color(0), dist(0), par(-1) {}
 };
 
 void print_node(ListNode *ver[], int n, string s)
{
    int max_depth = 0, v = 0;
    for(int i = 0; i < n; i++)
    {
        if(ver[i]->dist > max_depth)
        {
            max_depth = ver[i]->dist, v = i;
        }
    }
    string res;
   // stack<int>st;
    while(v != -1)
    {
       // st.push(v);
        res= s[v]+res;
        v = ver[v]->par;
    }
    cout<<res<<endl;
    //print_stack(st);
}
void dfs(vector<vector<int>>adj, int v, ListNode *ver[], stack<int>&st, int &cycle)
{
    
    ver[v]->color = 1;
    for(int i : adj[v])
    {
        if(ver[i]->color == 1)
        {
            cycle = 1;
            return;
        }
        if(ver[i]->color == 0)
        {
            ver[i]->par = v;
            ver[i]->dist = ver[v]->dist + 1;
            dfs(adj, i, ver, st, cycle);
        }
        
    }
    //cout<<v<<" "<<ver[v]->dist<<" "<<ver[v]->par<<endl;
    ver[v]->color = 2;
    st.push(v);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,e,u, v, cycle = 0;
        string s;
        cin>>n>>e;
        getchar();
        cin>>s;
        vector<vector<int>>adj(n);
        for(int i = 0; i < e; i++)
        {
            cin>>u>>v;
            adj[u].push_back(v);
        }
        ListNode *ver[n] ;
        
        for(int i =0; i < n; i++) //initialization
        {
            ver[i] = new ListNode();
            //cout<<ver[i]->color<<" "<<ver[i]->dist<<" "<<ver[i]->par<<endl;
        }
        stack<int>st;
        for(int i = 0; i < n; i++)
        {
            if(ver[i]->color == 0)
                dfs(adj, i, ver, st, cycle);
            if(cycle)
            {
                //cout<<"NULL"<<endl;
                break;
            }
        }
        //print(adj);
        //print_stack(st);
        
        if(cycle)
            cout<<"NULL"<<endl;
        else
            print_node(ver, n,s);
        
    }
    return 0;
}