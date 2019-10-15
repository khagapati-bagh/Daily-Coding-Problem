
# Daily Coding Problem: Problem #121 [Hard]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given a string which we can delete at most k, return whether you can make a palindrome.

For example, given 'waterrfetawx' and a k of 2, you could delete f and x to get 'waterretaw'.

**Solution** :

```cpp

#include <bits/stdc++.h>
using namespace std;

int editDistance(string str1, string str2){
    int n = str1.size();
    vector<vector<int>>dp(n+1, vector<int>(n+1));
    
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            if(i == 0)
                dp[i][j] = j;
            else if(j == 0)
                dp[i][j] = i;
            else if(str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[n][n];
}

bool checkKPalindrome(string s, int k){
    string r(s.rbegin(), s.rend());
    return editDistance(s, r) <= 2 * k;
}

int main() {
  //code
  int t;
  cin>>t;
  while(t--){
      int k;
      string s;
      cin>>s>>k;
      checkKPalindrome(s, k) ? cout<<"Yes"<<endl : cout<<"No"<<endl;
  }
  return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/8hOuyqR9Q2)**