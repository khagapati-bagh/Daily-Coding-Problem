#include <bits/stdc++.h>
using namespace std;

//global variable
typedef pair<int, int> P;
unordered_map<char, vector<P>>has;
int row, col;

//Extra code for print the has table
void print(){
    for(auto it = has.begin(); it != has.end(); it++){
        for(auto p = it->second.begin(); p != it->second.end(); p++){
            cout << it->first << " : " << p->first << " " << p->second << endl;
        }
    }
}

//Checking the position is inside to boundary or not
bool isSafe(int x, int y){
    return x >= 0 && x < row && y >= 0 && y < col;
}

//main part
bool dfs(vector<vector<char>>board, vector<vector<bool>>&visited, int x, int y, string str){
    
    visited[x][y] = true;
    str = str.substr(1);//new string
    
    if(str.empty()){//if string is empty
        return true;
    }
    
    vector<int> x_adj {-1, 1, 0, 0};
    vector<int> y_adj {0, 0, -1, 1};
    
    for(int k = 0; k < 4; k++){
        int i = x + x_adj[k], j = y + y_adj[k];
        
        if(isSafe(i, j) && str[0] == board[i][j] && !visited[i][j]){
            if(dfs(board, visited, i, j, str))
                return true;
        }
    }
    visited[x][y] = false;
    
    return false;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        cin>>row>>col;
        getchar();
        
        vector<vector<char>>board;
        
        
        for(int i = 0; i < row; i++){
            vector<char>tmp(col);
            for(int j = 0; j < col; j++){
                cin>>tmp[j];
                has[tmp[j]].push_back({i, j});//building hash map
            }
            board.push_back(tmp);
        }
        
        int n;
        cin>>n;
        getchar();
        for(int i = 0; i < n; i++){
            
            string word, res = "false";
            vector<vector<bool>>visited(row, vector<bool>(col, false));
            
            cin>>word;
            if(has.find(word[0]) != has.end()){
                
                for(auto p = has[word[0]].begin(); p != has[word[0]].end(); p++){
                    if(!visited[p->first][p->second] && dfs(board, visited, p->first, p->second, word)){
                        res = "true";
                        break;
                    }
                }
            }
            cout << word << " : " << res << endl;
        }
    }
    return 0;
}