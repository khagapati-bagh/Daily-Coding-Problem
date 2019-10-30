
# Daily Coding Problem: Problem #136 [Medium]

Good morning! Here's your coding interview problem for today.

This question was asked by Google.

Given an N by M matrix consisting only of 1's and 0's, find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:
```
    [[1, 0, 0, 0],
     [1, 0, 1, 1],
     [1, 0, 1, 1],
     [0, 1, 0, 0]]
```
Return 4.

**Solution** :

```cpp

#include <bits/stdc++.h>
using namespace std;

void helper(stack<int>&st, int i, int  &maxArea, vector<int>hist){
    int top, area;
    top = st.top();
    st.pop();
    if(st.empty())
        area = hist[top] *i;
    else
        area = hist[top] * (i - st.top() - 1);
    maxArea = maxArea > area ? maxArea : area;
}
int largestRectangle(vector<int>hist){
    int top, maxArea = -1, area, i;
    stack<int>st;
    for(i = 0; i < hist.size(); i++){
        while(!st.empty() && hist[i] < hist[st.top()]){
            helper(st, i, maxArea, hist);
        }
        st.push(i);
    }
    while(!st.empty()){
        helper(st, i, maxArea, hist);
    }
    return maxArea;
}

int maximalRectangle(vector<vector<int> > &A) {
    int row = A.size(), col = row > 0 ? A[0].size() : 0;
    if(row == 0 || col == 0)    return 0;
    bool flag = false;
    if(row > col){
        swap(row, col);
        flag = true;
    }
    
    int maxArea = 0;
    vector<int>hist(col, 0);
    for(int i = 0; i < row; i++){
        for(int j = 0 ; j < col; j++){
            int x;
            if(flag)
                x = A[j][i];
            else
                x = A[i][j];
            hist[j] = x == 0 ? 0 : hist[j] + 1;
        }
        maxArea = max(maxArea, largestRectangle(hist));
    }
    return maxArea;
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int row, col, value;
        cin>>row>>col;
        vector<vector<int>> grid(row);
        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                cin>>value;
                grid[i].push_back(value);
            }
        }
        cout << maximalRectangle(grid) <<endl;
    }
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/3W4ZeqE2ge)**