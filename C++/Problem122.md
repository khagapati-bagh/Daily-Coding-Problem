
# Daily Coding Problem: Problem #122 [Medium]

Good morning! Here's your coding interview problem for today.

This question was asked by Zillow.

You are given a 2-d matrix where each cell represents number of coins in that cell. Assuming we start at matrix[0][0], and can only move right or down, find the maximum number of coins you can collect by the bottom right corner.

For example, in this matrix

0 3 1 1
2 0 0 4
1 5 3 1
The most we can collect is 0 + 2 + 1 + 5 + 3 + 1 = 12 coins.

**Solution** :

```cpp

#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>v){
    for(int i = 0; i < v.size(); i++){
        for(int j : v[i])
            cout<<j<<" ";
        cout<<endl;
    }
}

int maximumNumberOfCoins(vector<vector<int>>grid, int row, int col){
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            if(i == 0){
                if(j > 0)
                    grid[i][j] += grid[i][j-1];
            }
            else if(j == 0){
                if(i > 0)
                    grid[i][j] += grid[i-1][j];
            }
            else
                grid[i][j] += max(grid[i-1][j], grid[i][j-1]);
        }
    }
    //print(grid);
    return grid[row-1][col-1];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int row, col, x;
        cin>>row>>col;
        vector<vector<int>>grid(row);
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                cin>>x;
                grid[i].push_back(x);
            }
        }
        cout<<maximumNumberOfCoins(grid, row, col)<<endl;
    }
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/zkPtcAKyez)**