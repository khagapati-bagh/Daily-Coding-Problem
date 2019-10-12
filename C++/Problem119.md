
# Daily Coding Problem: Problem #119 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given a set of closed intervals, find the smallest set of numbers that covers all the intervals. If there are multiple smallest sets, return any of them.

For example, given the intervals [0, 3], [2, 6], [3, 4], [6, 9], one set of numbers that covers all these intervals is {3, 6}.

**Solution** :

```cpp

#include <bits/stdc++.h>
#define vi vector<int>
using namespace std;

void print(vector<vi>interval){
    for(int i = 0; i < interval.size(); i++)
        cout<<"["<<interval[i][0]<<","<<interval[i][1]<<"] ";
    cout<<": ";
}

void minInterval(vector<vi>interval){
    int n = interval.size();
    if(n == 0){
        cout<<endl;
        return;
    }
    int min  = interval[0][1], max = min;
    for(int i = 1; i < n; i++){
        int lowIndex = interval[i][0] < interval[i][1] ? 0 : 1;
        max = interval[i][lowIndex] > max ? interval[i][lowIndex] : max;
        lowIndex = (lowIndex+1)&1;
        min = interval[i][lowIndex] < min ? interval[i][0] : min;
    }
    if(min == max)
        cout<<"["<<min<<"]\n";
    else
    cout<<"["<<min<<","<<max<<"]\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<vi>interval;
        for(int i = 0; i < n; i++){
            int x, y;
            cin>>x>>y;
            interval.push_back({x,y});
        }
        print(interval);
        minInterval(interval);
    }
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/QPn9MmEzVy)**