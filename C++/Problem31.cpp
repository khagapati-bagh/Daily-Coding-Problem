/*
Daily Coding Problem: Problem #31 [Easy]
Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

The edit distance between two strings refers to the minimum number of character insertions, deletions, and substitutions required to change one string to the other. For example, the edit distance between “kitten” and “sitting” is three: substitute the “k” for “s”, substitute the “e” for “i”, and append a “g”.

Given two strings, compute the edit distance between them.
Example
input
3
geek gesek
sitting kitten
abccabddd baccbad

output
1
3
5

*/

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
//Anather approach it'll take O(nm) Time and Space Complexity
int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size(), i, j;
        if(n == 0)
            return m;
        if(m == 0)
            return n;
        //Here m =row, n = column
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));//to store result of size (m+1)*(n+1)
        for(i = 1; i < n+1; i++)
            dp[0][i] = i;//store length 1 to n into first row
        for(i = 1; i < m+1; i++)
            dp[i][0] = i; //store 1 to m into first column
        
        for(i = 1; i < m+1; i++)//main loop for row
        {
            for(j = 1; j < n+1; j++) //for colunmn
            {
                if(word1[j-1] == word2[i-1])//if match, put the diagonal value
                    dp[i][j] = dp[i-1][j-1];
                else //put min among left, top and diagonal + 1
                    dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
            }
        }
        //print(dp);      
        return dp[m][n];//result
}*/

// This code will take O(nm) Time and O(n) Space complexity
int minDistance(string word1, string word2) {
    int n = word1.size(), m = word2.size(), i, j, diag;
    if(n == 0)
        return m;
    if(m == 0)
        return n;
    
    vector<int>dp(n+1,0);
    for(i = 1; i <= n; i++)
        dp[i] = i;      
    for(i = 1; i <= m; i++)
    {
        diag = dp[0];//strore diagonal value
        dp[0] = i;
        for(j = 1; j <= n; j++)
        {
            int tmp = dp[j];
            if(word1[j-1] == word2[i-1])
                dp[j] = diag;
            else
                dp[j] = min(diag, min(dp[j-1], dp[j])) + 1 ;
            diag = tmp;
        }
    }
    return dp[n];
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    string str1, str2;
	    cin>>str1>>str2;
	    cout<<minDistance(str1,str2)<<endl;
	}
	return 0;
}