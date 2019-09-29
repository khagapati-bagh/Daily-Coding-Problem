# Daily Coding Problem: Problem #101 [Easy]

Good morning! Here's your coding interview problem for today.

This problem was asked by Alibaba.

Given an even number (greater than 2), return two prime numbers whose sum will be equal to the given number.

A solution will always exist. See Goldbach’s conjecture.

Example:

Input: 4
Output: 2 + 2 = 4
If there are more than one solution possible, return the lexicographically smaller solution.

If [a, b] is one solution with a <= b, and [c, d] is another solution with c <= d, then

[a, b] < [c, d]
If a < c OR a==c AND b < d.

**Solution** : 

```cpp

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> P;
//Making prime number which are less than n
//O(n*log(log(n))) Time and O(n) Space Coplexity

void SieveOfEratosthenes(vector<bool>&primes){
    int n = primes.size();
    if(n == 0)
        return;
    primes[0] = primes[1] = false;
    for(int i = 2; i*i <= n; i++){
        if(primes[i]){
            for(int p = i*i; p <= n; p +=i){
                primes[p] = false;
            }
        }
    }
}

//Main program
P makePairOfPrime(int n){
    vector<bool> primes(n+1, true);
    SieveOfEratosthenes(primes);
    P res = {-1, -1};
    for(int i = 0; i < n; i++){
        if(primes[i] && primes[n-i]){
            res = {i, n-i};
            return res;
        }
    }
    return res;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        auto p = makePairOfPrime(n);
        cout<<n<<" : "<<p.first<<" "<<p.second<<endl;
    }
    return 0;
}

```
**[Run Code](https://ide.geeksforgeeks.org/2xurRv6GmL)**