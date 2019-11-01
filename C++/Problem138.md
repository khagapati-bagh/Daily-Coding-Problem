
# Daily Coding Problem: Problem #138 [Hard]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Find the minimum number of coins required to make n cents.

You can use standard American denominations, that is, 1¢, 5¢, 10¢, and 25¢.

For example, given n = 16, return 3 since we can make it with a 10¢, a 5¢, and a 1¢.

**Solution** :

```cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        int n = coins.size();
        vector<int>dp(amount+1, amount+1);
        dp[0] = 0;
        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < n; j++){
                if(i - coins[j] >= 0)
                    dp[i] = dp[i] < dp[i - coins[j]] + 1 ? dp[i] : dp[i - coins[j]] + 1;
            }
        }
        return amount+1 == dp[amount] ? -1 : dp[amount];
    }
};

int main() {
    int t;
    cin>>t;
    while(t--){
        int n, amount;
        cin>>amount>>n;
        vector<int>coins(n);
        for(int i = 0 ; i < n; i++)
            cin>>coins[i];
        Solution obj;
        cout<<obj.coinChange(coins, amount)<<endl;
    }
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/OkbVzngAhM)**