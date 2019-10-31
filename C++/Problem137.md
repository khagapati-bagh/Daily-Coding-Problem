
# Daily Coding Problem: Problem #137 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Amazon.

Implement a bit array.

A bit array is a space efficient array that holds a value of 1 or 0 at each index.
```
    init(size): initialize the array with size
    set(i, val): updates index at i with val where val is either 1 or 0.
    get(i): gets the value at index i.
    Return 4.
```
**Solution** :

```cpp

#include <bits/stdc++.h>
using namespace std;
class BitArray{
    vector<bool>bitarray;
  public:
    void init(int size){
        bitarray.resize(size);
    }
    void set(int index, bool val){
        bitarray[index] = val;
    }
    void get(int index){
        cout<<bitarray[index]<<endl;
    }
};
int main() {
    BitArray obj;
    obj.init(32);
    obj.set(1,1);
    obj.set(31,1);
    obj.get(31);
    obj.get(21);
    obj.get(1);
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/BxMdXlwS9r)**