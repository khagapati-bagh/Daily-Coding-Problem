/*
Daily Coding Problem: Problem #62 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

There is an N by M matrix of zeroes. Given N and M, write a function to count the number of ways of starting at 
the top-left corner and getting to the bottom-right corner. You can only move right or down.

For example, given a 2 by 2 matrix, you should return 2, since there are two ways to get to the bottom-right:

Right, then down
Down, then right
Given a 5 by 5 matrix, there are 70 ways to get to the bottom-right.

Example
input
3
3 3
32 32
54 12

output
6
271369120
566439616

*/

//You can get my code in IDE https://ide.geeksforgeeks.org/OsPggOkn8A
#include <iostream>
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
/*
//This code will take O(nm) Time and Space Complexity
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 0 || n == 0)
            return 0;
        if(n == 1 || m ==1)
            return 1;
        
        vector<vector<int>>grid(m, vector<int>(n,0));
        for(int i = 0; i < m; i++)
            grid[i][0] = 1;
        for(int i = 0; i < n; i++)
            grid[0][i] = 1;
        
        for(int i = 1; i < m; i++)
        {
            for(int j = 1; j < n; j++)
                grid[i][j] = (grid[i-1][j] + grid[i][j-1]) % MOD;
        }
        return grid[m-1][n-1];
    }
};
*/
//Optimized in Space complexity
//This code will take O(nm) Time and O(max(n, m)) Space Complexity
class Solution {
public:
    long uniquePaths(int m, int n) {
        if(m == 0 || n == 0)
            return 0;
        if(n == 1 || m ==1)
            return 1;
        
        vector<int>row(m,1), col(n,1);
        
        for(int i = 1; i < m; i++)//for row vector
        {
            for(int j = 1; j < n; j++) // for col vector
                row[i] = col[j] = row[i] + col[j];
        }
        return row[m-1]; // you can also return col[n-1]
    }
};


//O(1) Space complexity but it will not work for large input
/*
// Source https://www.youtube.com/watch?v=M8BYckxI8_U
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n + m - 2; // total no. of movement
        int k = m -1; // no. of step need to go down side
        long res = 1; //result
        // here we calculate the total possible path number 
        // Combination(N, k) = n! / (k!(n - k)!)
        // reduce the numerator and denominator and get
        // C = ( (n - k + 1) * (n - k + 2) * ... * n ) / k!
        for(int i = 1; i <= k; i++)
            res = res * (N - k + i)/ i;
        return (int)res;
    }
};

*/
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n, m;
	    cin>>m>>n;
	    Solution *s = new Solution();
	    cout<<s->uniquePaths(m,n)<<endl;
	}
	return 0;
}