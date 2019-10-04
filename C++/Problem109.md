# Daily Coding Problem: Problem #109 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Cisco.

Given an unsigned 8-bit integer, swap its even and odd bits. The 1st and 2nd bit should be swapped, the 3rd and 4th bit should be swapped, and so on.

For example, 10101010 should be 01010101. 11100010 should be 11010001.

Bonus: Can you do this in one line?

**Solution** : 

```cpp

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//This code will take O(1) Time and Space complexity
int swapBits(int x){
    int even_bit = (x & 0xAAAAAAAA) >> 1;//for 8 bit 0xAA for even bit
    int odd_bit = (x & 0x55555555) << 1; // 0x55 for odd bit
    return (even_bit | odd_bit);// for single line : (((x & 0xAA) >> 1) | ((x & 0x55) << 1))
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        int x;
        cin>>x;
        cout<<swapBits(x)<<endl;
    }
    return 0;
}

```
**[Run Code](https://ide.geeksforgeeks.org/yoHjBwtXph)**