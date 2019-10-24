
# Daily Coding Problem: Problem #130 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

Given an array of numbers representing the stock prices of a company in chronological order and an integer k, return the maximum profit you can make from k buys and sells. You must buy the stock before you can sell it, and you must sell the stock before you can buy it again.

For example, given k = 2 and the array [5, 2, 4, 0, 1], you should return 3.

**Solution** :

```cpp

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*
    Formula is
        T[i][j] = max(T[i][j-1], prices[j] + maxDiff)
        maxDiff = max(maxDiff, T[i-1][j] - prices[j])
    */
    //Space optimized 
    /*
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k == 0 || n == 0)    return 0;
        if(k >= n/2)    return maxProfit(prices);
        vector<int>curr(n,0), prev(n, 0);
        
        for(int i = 1; i <= k; i++){
            int maxDiff = -prices[0];
            for(int j = 1; j < n; j++){
                curr[j] = max(curr[j-1], prices[j] + maxDiff);
                maxDiff = max(maxDiff, prev[j] - prices[j]);
            }
            prev = curr;
        }
        return curr[n-1];
    }
    */
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if(k == 0 || n == 0)    return 0;
        if(k >= n/2)    return maxProfit(prices);
        vector<vector<int>>stock(k+1, vector<int>(n, 0));
        
        for(int i = 1; i <= k; i++){
            int maxDiff = -prices[0];
            for(int j = 1; j < n; j++){
                stock[i][j] = max(stock[i][j-1], prices[j] + maxDiff);
                maxDiff = max(maxDiff, stock[i-1][j] - prices[j]);
            }
        }
        
        printTransaction(stock, prices);
        return stock[k][n-1];
    }
    
    int maxProfit(vector<int>prices){
        int profit = 0;
        for(int i = 1; i < prices.size(); i++){
            bool flag = false;
            profit += prices[i] > prices[i-1] ? prices[i] - prices[i-1]: 0;
            if(prices[i] > prices[i-1]){
                cout<<"Buy on day "<<i-1<<endl;
                cout<<"Sell on day "<<i<<endl;
            }
        }
        return profit;
    }
    
    void printTransaction(vector<vector<int>>stock, vector<int>prices){
        int i = stock.size()-1, j = i > 0 ? stock[0].size() - 1 : 0;
        stack<int>st;
        while(i > 0 && j > 0){
            if(stock[i][j] == stock[i][j-1])
                j--;
            else{
                st.push(j);
                int maxDiff = stock[i][j] - prices[j];
                for(int k = j-1; k >= 0; k--){
                    if(stock[i-1][k] - prices[k] == maxDiff){
                        i--;
                        j = k;
                        st.push(j);
                        break;
                    }
                }
            }
        }
        while(!st.empty()){
            cout<<"Buy on day "<<st.top()<<endl;    st.pop();
            cout<<"Sell on day "<<st.top()<<endl;    st.pop();
        }
    }
};

int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        int days, k;
        cin>>k>>days;
        vector<int>prices(days);
        for(int i = 0; i < days; i++)
            cin>>prices[i];
        Solution s;
        cout<<"Total profit is : "<<s.maxProfit(k, prices)<<endl<<endl;
    }
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/gg1zTY8XG3)**