
# Daily Coding Problem: Problem #148 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Apple.

Gray code is a binary code where each successive value differ in only one bit, as well as when wrapping around. Gray code is common in hardware so that we don't see temporary spurious values during transitions.

Given a number of bits n, generate a possible gray code for it.

For example, for n = 2, one gray code would be [00, 01, 11, 10].

**Solution** :

```cpp

#include <bits/stdc++.h>
using namespace std;

void generateCode(int N)
{
     //Your code here
     if(N <= 0) return;
     vector<string>greyCode;
     //for one bit
     greyCode.push_back("0");
     greyCode.push_back("1");
     
     for(int i = 2; i < (1 << N); i<<=1){
         //reverse the content 
         for(int j = i - 1; j >= 0; j--)
            greyCode.push_back(greyCode[j]);
        
         //concatinate '0' to the first half
         for(int j = 0; j < i; j++)
            greyCode[j] = '0' + greyCode[j];
         //concatinate '0' to the second half
         for(int j = i; j < 2*i; j++)
            greyCode[j] = '1' + greyCode[j];
     }
     for(int i = 0; i < greyCode.size(); i++)
        cout<<greyCode[i]<<" ";
}

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        generateCode(n);
        cout<<endl;
    }
    return 0;
}


```

**[Run Code](https://ide.geeksforgeeks.org/7PqXxYGycU)**