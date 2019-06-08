/*
Daily Coding Problem: Problem #39 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Dropbox.

Conway's Game of Life takes place on an infinite two-dimensional board of square cells. 
Each cell is either dead or alive, and at each tick, the following rules apply:

Any live cell with less than two live neighbours dies.
Any live cell with two or three live neighbours remains living.
Any live cell with more than three live neighbours dies.
Any dead cell with exactly three live neighbours becomes a live cell.
A cell neighbours another cell if it is horizontally, vertically, or diagonally adjacent.

Implement Conway's Game of Life. It should be able to be initialized with a starting list of 
live cell coordinates and the number of steps it should run for. Once initialized, 
it should print out the board state at each step. Since it's an infinite board, print out only the relevant coordinates, 
i.e. from the top-leftmost live cell to bottom-rightmost live cell.

You can represent a live cell with an asterisk (*) and a dead cell with a dot (.).

Example
input
1
5 10
..........
...**.....
....*.....
..........
..........

output
. . . . . . . . . . 
. . . * * . . . . . 
. . . * * . . . . . 
. . . . . . . . . . 
. . . . . . . . . . 

*/

//You can Get my code in IDE https://ide.geeksforgeeks.org/ouvpJTQWFd
//This code will take O(n^2) Time and Space Complexity
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<char>>v)
{
    for(int i = 0; i < v.size(); i++)
    {
        for(auto c : v[i])
            cout<<c<<' ';
        cout<<endl;
    }
}
int count_neighbour(vector<vector<char>>v, int n, int m)
{
    int x_ar[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int y_ar[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    int cnt = 0;
    for(int k = 0; k < 8; k++)
    {
        int i = n + x_ar[k], j = m + y_ar[k];
        if(i >=0 && j >=0 && i < v.size() && j < v[n].size() && v[i][j] == '*')
            cnt++;
    }
    return cnt;
}

void gameOfLife(vector<vector<char>>&board) {
    vector<vector<char>>tmp;
    tmp = board;
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board[i].size(); j++)
        {
            int cnt = count_neighbour(tmp, i, j);//count no. of neighbour
            if(tmp[i][j] == '*' && (cnt < 2 || cnt > 3))
                board[i][j] = '.';
            else if(tmp[i][j] == '.' && cnt == 3)
                board[i][j] = '*';
        }
    }
    //print(board);
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m;
	    cin>>n>>m;
	    vector<vector<char>>board;
	    char c;
	    for(int i =0 ;i < n; i++)
	    {
	        vector<char>tmp;
	        for(int j = 0; j < m; j++)
	        {
	            cin>>c;
	            tmp.push_back(c);
	        }
	        board.push_back(tmp);
	    }
	    gameOfLife(board);
	    print(board);
	}
	return 0;
}