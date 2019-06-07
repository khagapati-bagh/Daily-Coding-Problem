/*
Daily Coding Problem: Problem #38 [Hard]

Good morning! Here's your coding interview problem for today.

This problem was asked by Microsoft.

You have an N by N board. Write a function that, given N, returns the number of possible arrangements of the board where 
N queens can be placed on the board without threatening each other, i.e. no two queens share the same row, column, or diagonal.
Example
input
1
4

output
[
.Q..
...Q
Q...
..Q.

..Q.
Q...
...Q
.Q..

]

*/
//You can get my code in IDE https://ide.geeksforgeeks.org/AvCy0LJSxl
// https://leetcode.com/problems/n-queens/discuss/307082/Simple-Solution-beats-100-(2-codes)
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solveNQueens(int n) {
        vector<vector<string>>res;
        vector<string>n_queen(n,string(n,'.'));
        vector<int>flag_col(n,1), flag_45(2 * n - 1, 1), flag_135(2 * n - 1, 1);
        solve(res, n_queen, flag_col, flag_45, flag_135, 0, n);
        print(res);
    }
private:
    void print(vector<vector<string>>v)
    {
        cout<<"["<<endl;
        for(int i = 0; i < v.size(); i++)
        {
            for(auto a : v[i])
                cout<<a<<endl;
            cout<<endl;
        }
        cout<<"]"<<endl;
    }
    void solve(vector<vector<string>>&res, vector<string>&n_queen, vector<int>&f_col, vector<int>&f_45, vector<int>&f_135, int row, int n)
    {
        if(row == n)
        {
            res.push_back(n_queen);
            return;
        }
        
        for(int i = 0; i < n; i++)//i = column
        {
            if(f_col[i] && f_45[row + i] && f_135[n - 1 + i -row])
            {
                f_col[i] = f_45[row + i] = f_135[n - 1 + i - row] = 0;
                n_queen[row][i] = 'Q';
                solve(res, n_queen, f_col, f_45, f_135, row + 1, n);
                n_queen[row][i] = '.';
                f_col[i] = f_45[row + i] = f_135[n - 1 + i - row] = 1;
            }
        }
    }
};
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    Solution s1;
	    s1.solveNQueens(n);
	    cout<<endl;
	    
	}
	return 0;
}