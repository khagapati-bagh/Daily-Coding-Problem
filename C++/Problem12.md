
# Daily Coding Problem: Problem #12 [Hard]
Good morning! Here's your coding interview problem for today.

This problem was asked by Amazon.

There exists a staircase with N steps, and you can climb up either 1 or 2 steps 
at a time. Given N, write a function that returns the number of unique ways you 
can climb the staircase. The order of the steps matters.

For example, if N is 4, then there are 5 unique ways:

1, 1, 1, 1
2, 1, 1
1, 2, 1
1, 1, 2
2, 2
What if, instead of being able to climb 1 or 2 steps at a time, you could climb 
any number from a set of positive integers X? For example, if X = {1, 3, 5}, you 
could climb 1, 3, or 5 steps at a time.

**Solution** : This code will take O(n) Time and Space Complexity

```cpp

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll no_of_ways(int n, vector<int>steps)
{
    vector<ll> jumps(n + 1, 0);
    for(int i = 1; i <= n; i++){
        for(int x : steps){
            if(i - x > 0)
                jumps[i] += jumps[i - x];
        }
        if(find(steps.begin(), steps.end(), i) != steps.end())
            jumps[i] +=1;
    }
    return jumps[n];
}

int main() {
    int t;
    cin>>t; // Test cases
    while(t--)
    {
        int n,sz,i;
        cin>>n>>sz; // sz = you could climb any number from a set of positive integers X
        vector<int>X(sz);
        for(i=0;i<sz; i++)
            cin>>X[i]; //Enter Set element
        cout<<no_of_ways(n,X)<<endl;
    }
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/7tJKMqU7gf)**