# Daily Coding Problem: Problem #151 [Medium]

Good morning! Here's your coding interview problem for today.

Given a 2-D matrix representing an image, a location of a pixel in the screen and a color C, replace the color of the given pixel and all adjacent same colored pixels with C.

For example, given the following matrix, and location pixel of (2, 2), and 'G' for green:
```
    B B W
    W W W
    W W W
    B B B
```
Becomes
```
    B B G
    G G G
    G G G
    B B B
```
**Solution** :

```cpp

#include <bits/stdc++.h>
#define print(v) for(int i  = 0; i < v.size(); i++){for(int j = 0; j < v[i].size(); j++) cout<<v[i][j]<<" "; cout<<endl;}
using namespace std;

bool isSafe(int x, int y, int row, int col){
    return x >= 0 && x < row && y >= 0 && y < col;
}

void changeTheChar(vector<vector<char>>&v, char ch, char old, int x, int y){
    int x_adj [] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int y_adj [] = {-1, 0, 1, -1, 1, -1, 0, 1};
    
    v[x][y] = ch;
    
    for(int k = 0; k < 8; k++){
        int i = x + x_adj[k], j = y + y_adj[k];
        if(isSafe(i, j, v.size(), v[0].size()) && v[i][j] == old)
            changeTheChar(v, ch, old, i, j);
    }
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int row, col, x, y;
        cin>>row>>col;
        char ch;
        vector<vector<char>>matrix;
        for(int i = 0; i < row; i++){
            vector<char>tmp(col);
            for(int j = 0; j < col; j++){
                cin>>tmp[j];
            }
            matrix.push_back(tmp);
        }
        cin>>ch>> x >> y;
        if(isSafe(x, y, row, col)){
            cout<<"Before Change"<<endl;
            print(matrix);
            changeTheChar(matrix, ch, matrix[x][y], x, y);
            cout<<"After Change"<<endl;
            print(matrix);
        }
        else    cout<<"Out of range"<<endl;
    }
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/WDqwzZRB1b)**