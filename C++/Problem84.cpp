/*
Daily Coding Problem: Problem #84 [Medium]
Good morning! Here's your coding interview problem for today.

This problem was asked by Amazon.

Given a matrix of 1s and 0s, return the number of "islands" in the matrix. A 1 represents land and 0 represents water, so an island is a group of 1s that are neighboring whose perimeter is surrounded by water.

For example, this matrix has 4 islands.

1 0 0 0 0
0 0 1 1 0
0 1 1 0 0
0 0 0 0 0
1 1 0 0 1
1 1 0 0 1

Example
input
3
3 3
1 1 0 
0 0 1 
1 0 1
4 4
1 1 0 0 
0 0 1 0 
0 0 0 1 
0 1 0 0
6 5
1 0 0 0 0
0 0 1 1 0
0 1 1 0 0
0 0 0 0 0
1 1 0 0 1
1 1 0 0 1

output
3
4
4

*/

// You can get my code in IDE https://ide.geeksforgeeks.org/m4xRH679eT

//This code will take O(n) Time and Space Complexity
#include <bits/stdc++.h>
using namespace std;
//Position this line where user code will be pasted.

bool is_safe(int x, int y, int N, int M)
{
    return x >= 0 && x < N && y >= 0 && y < M;
}

void dfs(vector<vector<bool>>&visited, vector<int>A[], int x, int y, int N, int M)
{
    visited[x][y] = true;
    
    //if only four direction can check 
    vector<int>adj_x {-1, 0, 0, 1};
    vector<int>adj_y {0, -1, 1, 0};
       
    
    /*
    //when we check 8 direction
    vector<int>adj_x {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int>adj_y {-1, 0, 1, -1, 1, -1, 0, 1};
    */
    for(int k = 0; k < adj_x.size(); k++)
    {
        int i = x + adj_x[k], j = y + adj_y[k];
        if(is_safe(i, j, N, M) && !visited[i][j] && A[i][j])
            dfs(visited, A, i, j, N, M);
    }
}

int findIslands(vector<int> A[], int N, int M)
{
    
    // Your code here
    vector<vector<bool>>visited(N,vector<bool>(M, false));
    int cnt = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(!visited[i][j] && A[i][j])
            {
                cnt++;
                dfs(visited, A, i, j, N, M);
            }
        }
    }
    return cnt;
}

int main() 
{
    int T;
    cin>>T;
    while(T--)
    {
        int N,M;
        cin>>N>>M;
        vector<int> A[N];
        for(int i=0;i<N;i++){
            vector<int> temp(M);
            A[i] = temp;
            for(int j=0;j<M;j++){
                cin>>A[i][j];
            }
        }
        cout<<findIslands(A,N,M)<<endl;
    }
    return 0;
}
