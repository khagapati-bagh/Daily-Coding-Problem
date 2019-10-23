
# Daily Coding Problem: Problem #129 [Medium]

Good morning! Here's your coding interview problem for today.

Given a real number n, find the square root of n. For example, given n = 9, return 3.

**Solution** :

```cpp

#include <bits/stdc++.h>
using namespace std;

double squareRoot(int n){
    int left= 0, right = n, precision = 5;
    double ans = 0;
    
    // for computing integral part of square root of number 
    while(left <= right){
        int mid = (left + right)/2;
        int x = mid * mid;
        if(x == n){
            ans = mid;
            break;
        }
        else if(x < n){
            left = mid + 1;
            ans = mid;
        }
        else 
            right = mid - 1;
    }
    // For computing the fractional part of square root upto given precision
    float increment = 0.1;
    for(int i = 0; i < precision; i++){
        while(ans * ans <= n){
            ans += increment;
        }
        //loop terminates when ans * ans > n
        ans -= increment;
        increment /=10;
    }
    return ans;
}

int main(){
    int testCase;
    cin>>testCase;
    while(testCase--){
        int n;
        cin>>n;
        cout<<"Square Root of "<<n<<"\tis "<<squareRoot(n)<<endl;
    }
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/UOHBKnigg0)**