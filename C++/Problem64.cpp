/*
Daily Coding Problem: Problem #64 [Hard]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

A knight's tour is a sequence of moves by a knight on a chessboard such that all squares are visited once.

Given N, write a function to return the number of knight's tours on an N by N chessboard.

Example
input
4
10
2
4
8

output
  1  12   3  10   7  20  17  26  23  32 
  4   9   6  19  16  25  22  31  28  73 
 13   2  11   8  21  18  27  24  33  30 
 40   5  36  15  46  43  34  29  72  59 
 37  14  39  42  35  48  45  58  76  83 
 54  41  50  47  44  57  77  71  60  74 
 51  38  53  56  49  70  61  75  82  92 
 64  55  66  69  62  78  81  91  88  85 
 67  52  63  79  95  90  87  84  93  96 
100  65  68  97  99  80  94  89  86  98 
  1  -1 
 -1  -1 
  1   8   3  10 
  4  11   6  14 
  7   2   9  15 
 12   5  13  16 
  1  12   3  10   7  20  17  26 
  4   9   6  19  16  25  22  41 
 13   2  11   8  21  18  27  24 
 30   5  32  15  28  23  40  37 
 33  14  29  43  39  36  54  61 
 45  31  47  35  55  42  38  52 
 48  34  44  58  50  53  60  59 
 64  46  49  56  62  57  51  63 

*/
//You can get my code in IDE https://ide.geeksforgeeks.org/qweKD1afXb
#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>v)
{
    for(int i = 0; i < v.size(); i++)
    {
        for(int j : v[i])
            cout<<setw(3)<<j<<" ";
        cout<<endl;
    }
}
bool is_safe(int i, int j, int n)
{
    return (i>=0 && i < n && j >= 0 && j < n);
}
void Knight_tour(vector<vector<int>>&board, int x, int y, int &cnt)
{
    int n = board.size();
    board[x][y] = cnt;
    if(cnt == n*n)
        return;
    cnt++;
    int arr_x [] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int arr_y [] = {-2, -1, 1, 2, -2, -1, 1, 2};
    
    for(int k = 0; k < 8; k++)
    {
        int i = x + arr_x[k], j = y + arr_y[k];
        if(is_safe(i, j, n) && board[i][j] == -1)
        {
            Knight_tour(board, i, j, cnt);
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, cnt = 1;
        cin>>n;
        vector<vector<int>>board(n, vector<int>(n,-1));
        Knight_tour(board, 0, 0, cnt);
        print(board);
    }
    return 0;
}
