/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Microsoft.

Given a 2D matrix of characters and a target word, write a function that returns whether the word can be found in 
the matrix by going left-to-right, or up-to-down.

For example, given the following matrix:

[['F', 'A', 'C', 'I'],
 ['O', 'B', 'Q', 'P'],
 ['A', 'N', 'O', 'B'],
 ['M', 'A', 'S', 'S']]
and the target word 'FOAM', you should return true, since it's the leftmost column. Similarly, 
given the target word 'MASS', you should return true, since it's the last row.

Examaple
input
4 4 6
F A C I
OBQP
ANOB
MASS
FOAM
MASS
ANB
IPB
AD
ABN

output
FOAM is present.
MASS is present.
ANB is not present.
IPB is present.
AD is not present.
ABN is present.

*/

//You can get my code in IDE https://ide.geeksforgeeks.org/ge8aIFNIJE
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
void print_1d(vector<char>v)
{
    for(char c : v)
            cout<<c<<' ';
    cout<<endl;
}
void print(vector<vector<char>>v)
{
    for(int i = 0; i < v.size(); i++)
    {
        print_1d(v[i]);
    }
}


bool check(vector<vector<char>>grid, int n,int m, string word)
{
    int len = word.size(), flag = 0;
    if(m <= grid[0].size() - len )
    {
        flag = 1;
        for(int k= 0, i = m; i < m + len; i++, k++)//check in column wise
        {
            //cout<<grid[n][i]<<' ';
            if(grid[n][i] != word[k])
            {
                flag = 0;
                break;
            }
            
        }
    }
    
    if(flag)
        return true;
        
    if(n <= grid.size() - len)
    {    
        flag = 1;
        for(int k= 0, i = n; i < n + len; i++, k++)//check in row wise
        {
            if(grid[i][m] != word[k])
            {
                flag = 0;
                break;
            }
            
        }
    }
    
    if(flag)
        return true;
    
    return false;
}


bool check_word(vector<vector<char>>grid, string word)
{
    int n = grid.size(), m = n > 0 ? grid[0].size() : 0, len = word.size(), k = 0;
    if(n ==0 || m == 0)
        return false;
        
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(grid[i][j] == word[0] && check(grid, i, j, word))
            {
                return true;
            }
        }
    }
    
    return false;
}

int main()
{
    int n, m, q;
    cin>>n>>m>>q;
    vector<vector<char>>grid;
    
    for(int i = 0; i < n; i++)
    {
        vector<char>tmp(m);
        for(int j = 0; j < m; j++)
            cin>>tmp[j];
        grid.push_back(tmp);
    }
    string word;
    for(int i = 0; i < q; i++)
    {
        cin>>word;
        if(check_word(grid, word))
            cout<<word<<" is present."<<endl;
        else 
            cout<<word<<" is not present."<<endl;
    }
    return 0;
}
