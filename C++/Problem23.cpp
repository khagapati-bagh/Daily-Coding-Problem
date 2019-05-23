/*

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

You are given an M by N matrix consisting of booleans that represents a board. 
Each True boolean represents a wall. Each False boolean represents a tile you can walk on.

Given this matrix, a start coordinate, and an end coordinate, return the minimum number of 
steps required to reach the end coordinate from the start. If there is no possible path, 
then return null. You can move up, left, down, and right. You cannot move through walls. 
You cannot wrap around the edges of the board.

Example
input
4
3 5
0 1 0 0 0
0 1 0 1 0
0 0 0 1 0
0 0 2 4
4 4
0 0 0 1
1 1 0 1
0 0 0 1
0 0 1 0
3 0 0 0
3 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 0 2 4
3 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 0 3 4

output
10
7
6
0

*/
//This will take O(n*m) Time and  Space Complexity
// You can get my code in IDE https://ide.geeksforgeeks.org/THAMxwLbwn
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define M 10
void print(vector<vector<int>>v){//Adtional function 
    for(int i = 0; i < v.size(); i++)
    {
        for(int j : v[i])
            cout<<j<<' ';
        cout<<endl;
    }
}
struct node{ //for distance
  int dist;
  string color;
};

typedef struct node node;

void print_node(vector<vector<node>>ver){ //Aditional function
    for(int i = 0; i < ver.size(); i++)
    {
        for(int j = 0; j < ver[i].size(); j++)
            cout<<ver[i][j].dist<<' '<<ver[i][j].color<<' ';
        cout<<endl;
    }
}

bool check(int x, int y, int n, int m)
{
    return x >= 0 && x < n && y >= 0 && y < m; //check x and y are within the boundary or not
}

void bfs(vector<vector<int>>graph, int s1, int s2, int d1, int d2, vector<vector<node>>&ver){

    int n = graph.size(), m = graph[0].size(), i, j;
    //initialize
    for(i = 0; i < n; i++)
    {
        vector<node>tmp(m);
        for(j = 0; j < m; j++)
        {
            (tmp[j]).dist = 0;
            (tmp[j]).color = "WHITE";
        }
        ver.push_back(tmp);
    }

    //print_node(ver);
    
    queue<pair<int, int>>Q; 
    Q.push(make_pair(s1,s2));//Source node
    //cout<<Q.front().first<<' '<< Q.front().second<<endl;
    int nei_x[] = {1,-1,0,0,};//All Neighbour in x
    int nei_y[] = {0,0,1,-1}; //All Nieghbour in y
    while(!Q.empty())
    {
        i = Q.front().first, j = Q.front().second; //front element 
        Q.pop();
        for(int k = 0; k < 4; k++)
        {
            int x = i + nei_x[k], y = j + nei_y[k];
            if(check(x, y, n, m) && graph[x][y] == 0 && (ver[x][y]).color == "WHITE") //Check it is visited or not
            {
                (ver[x][y]).color="GREY"; //partially visited
                (ver[x][y]).dist = (ver[i][j]).dist + 1;
                Q.push(make_pair(x,y));
            }
        }
        (ver[i][j]).color = "BLACK";// complete 
        if(i == d1 && j ==d2)//our destination; if you wan to complete traversal then make it comment
            break;
    }
    //print_node(ver);
}

int main() {
    int t;
    cin>>t;
    while(t--)//test cases
	{
	    int n,m,i,j;
    	cin>>n>>m; // size of matrix
    	vector<vector<int>>board;
    	for(i = 0; i < n; i++)
    	{
    	    vector<int>tmp(m);
    	    for(j = 0; j < m; j++)
    	    {
    	        cin>>tmp[j];//input
    	    }
    	    board.push_back(tmp);
    	}
    	//print(board);
    	int s1, s2, d1, d2; //sourc and destination index
    	cin>>s1>>s2>>d1>>d2;
    	if(s1 == d1 && s2 == d2) //if equal
    	    cout<<0<<endl;
    	else if(check(s1, s2, n, m) && check(d1, d2, n, m))//
    	{
    	    vector<vector<node>>ver;
    	    bfs(board, s1, s2, d1, d2,ver);
    	    cout<<ver[d1][d2].dist<<endl;
    	}
    	else cout<<0<<endl;
	}
	return 0;
}

/* //other test cases for varify
4
3 5
0 1 0 0 0
0 1 0 1 0
0 0 0 1 0
0 0 2 4
4 4
0 0 0 1
1 1 0 1
0 0 0 1
0 0 1 0
3 0 0 0
3 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 0 2 4
3 5
0 1 0 0 0
0 1 0 1 0
0 0 0 0 0
0 0 3 4
*/