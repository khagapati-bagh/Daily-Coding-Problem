/*
Daily Coding Problem: Problem #56 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given an undirected graph represented as an adjacency matrix and an integer k, write a function to determine whether each vertex in the graph can be colored such that no two adjacent vertices share the same color using at most k colors.
*/

//You can get my code in IDE https://ide.geeksforgeeks.org/MvPr0Dfwwv

/*
Example
input
3
4
3
14
2 4 3 4 2 1 3 2 3 4 1 3 1 3 4 1 4 1 3 2 2 4 2 3 2 4 4 1
4
3
5
1 2 2 3 3 4 4 1 1 3
3
2
3
1 2 2 3 1 3

output
It's not possible
BLUE GREEN RED YELLOW RED 
It is possible
It's not possible

*/
#include<bits/stdc++.h>

using namespace std;

bool isSafe(vector<int> adjlist[], int s, int c, vector<int> color)
{
    for(int j=0;j<adjlist[s].size();j++)
    {
        int v = adjlist[s][j];
        
        if(v == s || color[v] == 0)
            continue;
        
        if(color[v] == c)
            return 0;
    }
    return 1;
}

bool isKColorableUtil(int s, vector<int> adjlist[], vector<bool> visited, vector<int> &color, int m)
{
    visited[s] = 1;
    
    for(int c=1;c<=m;c++)
    {
        if(isSafe(adjlist, s, c, color))
        {
            //cout<<s<<","<<c<<endl;
            color[s] = c;
            
            bool remaining = 0;
            
            for(int j=0;j<adjlist[s].size();j++)
            {
                int v = adjlist[s][j];
                
                if(visited[v])
                    continue;
                
                remaining = 1;
                if(isKColorableUtil(v, adjlist, visited, color, m))
                    return 1;
            }
            
            if(!remaining)
                return 1;
            
            color[s] = 0;
        }
    }
    return 0;
}
string COLORS[] = {"BLUE", "GREEN", "RED", "YELLOW", "ORANGE", "PINK", "BLACK", "BROWN", "WHITE", "PURPLE"};
void print(vector<int>v)
{
    for(int i : v)
        cout<<COLORS[i]<<' ';
    cout<<endl;
}
bool isKColorable(vector<int> adjlist[], int n, int m)
{
    vector<int> color(n+1, 0);
    vector<bool> visited(n+1, 0);
    
    bool sol = 1;
    
    for(int i=1;i<=n;i++)
    {
        if(color[i] == 0)
        {
            sol = sol & isKColorableUtil(i, adjlist, visited, color, m);
        }
    }
    if(sol)
        print(color);
    return sol;
}

int main()
 {
    //code
    int t;
    cin>>t;
    
    while(t--)
    {
        int n, m, e;
        cin>>n>>m>>e;
       //adjlist for graph
        vector<int> adjlist[n+1];
        
        for(int i=0;i<e;i++)
        {
            int from, to;
            cin>>from>>to;
            
            adjlist[from].push_back(to);
            adjlist[to].push_back(from);
        }
        
        if(isKColorable(adjlist, n, m))
            cout<<"It is possible"<<endl;
        else
            cout<<"It's not possible"<<endl;
    }
    return 0;
}


//You can get my code in IDE https://ide.geeksforgeeks.org/0V3ZStQNAT

/*
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//structure to store Graph Edge
struct Edge{
    int src, dest;
};
//class to represent a Graph object
class Graph
{
    public:
        //An array of vectors to represent adjacency list
        vector<vector<int>>adj;
        //Constructor
        Graph(vector<Edge>const &edge, int N)
        {
            //resize the vector to N 
            adj.resize(N);
            // add edges to the undirected graph
            for(int i = 0; i < edge.size(); i++)
            {
                int src = edge[i].src, dest = edge[i].dest;
                adj[src].push_back(dest);
                adj[dest].push_back(src);
            }
        }
};
// string array to store colors (10-colorable graph)
string COLORS[] = {"", "BLUE", "GREEN", "RED", "YELLOW", "ORANGE",
                "PINK", "BLACK", "BROWN", "WHITE", "PURPLE"};
bool isSafe(Graph &graph, vector<int>color, int v, int c)
{
    for(int u : graph.adj[v])
        if(color[u] == c)
            return false;
    return true;
}

bool kColorable(Graph &graph, vector<int> &color, int k, int v, int N)
{
    if(v == N)
    {
        for(int v = 0; v < N; v++)
            cout<<setw(8)<<left<<COLORS[color[v]];
        cout<<endl;
        return true;
    }
    for(int c = 1; c <= k; c++)
    {
        if(isSafe(graph, color, v, c))
        {
            color[v] = c;
            return kColorable(graph, color, k, v+1, N);
            color[v] = 0;
        }
    }
    return false;
}

int main()
{
    // vector of graph edges as per above diagram
    vector<Edge> edges = {
        {0, 1}, {0, 4}, {0, 5}, {4, 5}, {1, 4}, {1, 3}, {2, 3}, {2, 4}
    };

    // Number of vertices in the graph
    int N = 6;

    // create a graph from edges
    Graph g(edges, N);

    int k = 3;

    vector<int> color(N, 0);

    // print all k-colorable configurations of the graph
    if(kColorable(g, color, k, 0, N))
        cout<<"It is possible"<<endl;
    else
        cout<<"It's not possible"<<endl;

    return 0;
}
*/