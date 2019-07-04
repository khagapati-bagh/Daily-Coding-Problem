/*
Daily Coding Problem: Problem #65 [Easy]

Good morning! Here's your coding interview problem for today.

This problem was asked by Amazon.

Given a N by M matrix of numbers, print out the matrix in a clockwise spiral.

For example, given the following matrix:

[[1,  2,  3,  4,  5],
 [6,  7,  8,  9,  10],
 [11, 12, 13, 14, 15],
 [16, 17, 18, 19, 20]]
You should print out the following:

1
2
3
4
5
10
15
20
19
18
17
16
11
6
7
8
9
14
13
12

Example
input
2
4 4
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
3 4
1 2 3 4 5 6 7 8 9 10 11 12

output
1 2 3 4 8 12 16 15 14 13 9 5 6 7 11 10 
1 2 3 4 8 12 11 10 9 5 6 7 


*/

// You can get my code in IDE https://ide.geeksforgeeks.org/PHOpMTjY4C
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = n > 0 ? matrix[0].size() : 0;
        vector<int>res;
        if(m == 0 || n == 0)
            return;
        vector<vector<int>>Dirs {{0,1}, {1,0}, {0,-1}, {-1,0}};
        vector<int>steps{m, n-1};
        int i = 0, j = -1, idir = 0; // ider = direction
        while(steps[idir%2])
        {
            for(int k = 0; k < steps[idir%2]; k++)
            {
                i += Dirs[idir][0], j += Dirs[idir][1];
                res.push_back(matrix[i][j]);
            }
            steps[idir % 2]--;
            idir = (idir + 1 )%4;//four direction
        }
        print(res);
    }
    
private:
    void print(vector<int>v)
    {
        for(int i : v)
            cout<<i<<' ';
        cout<<endl;
    }
};

int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n, m;
	    cin>>n>>m;
	    vector<vector<int>>matrix;
	    for(int i = 0; i < n; i++)
	    {
	        vector<int>tmp(m);
	        for(int j = 0; j < m; j++)
	            cin>>tmp[j];
	        matrix.push_back(tmp);
	    }
	    Solution *s = new Solution();
	    s->spiralOrder(matrix);
	}
	return 0;
}