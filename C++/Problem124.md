
# Daily Coding Problem: Problem #124 [Easy]

Good morning! Here's your coding interview problem for today.

This problem was asked by Microsoft.

You have n fair coins and you flip them all at the same time. Any that come up tails you set aside. The ones that come up heads you flip again. How many rounds do you expect to play before only one coin remains?

Write a function that, given n, returns the number of rounds you'd expect to play until one coin remains.

**Solution** :

```
    Since the probability of getting Head is 1/2, after every round the number of coins will probably halved.
    So let's C(i) the number of coins at the i-th round.
            C(i) = n / 2^i
            The game ends when: C(i) < 1
                                2^i > n
                                i > log2(n)
            So the expected value of F(n) searched is:
                                F(n) ~ log2 (n)
```

```cpp

#include <bits/stdc++.h>
using namespace std;
/*
int flipCoins(int n){
    if(n < 1) return -1;
    return ceil(log2(n));
}
*/
int flipCoins(int n){
    if(n < 1) return -1;
    if(n == 1)
        return 1;
    int totalRound = flipCoins(n/2) + 1;
    return totalRound;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x = flipCoins(n);
        if(x != -1)
            cout<<"It takes "<<x<<" round to change "<<n<<" coins to 1"<<endl;
        else 
            cout<<"It is not possible to change "<<n<<" coins to 1"<<endl;
    }
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/DdA8Df61XZ)**