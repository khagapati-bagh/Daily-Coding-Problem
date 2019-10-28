
# Daily Coding Problem: Problem #134 [Easy]

Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

You have a large array with most of the elements as zero.

Use a more space-efficient data structure, SparseArray, that implements the same interface:
```
    init(arr, size): initialize with the original large array and size.
    set(i, val): updates index at i with val.
    get(i): gets the value at index i.
```

**Solution** :

```cpp

#include <bits/stdc++.h>
using namespace std;

class SpaceEfficient{
    private:
        int size;
        unordered_map<int, int>arr;
    public:
        void init(int x){
            size = x;
        }
        void set(int index, int value){
            arr[index] = value;
        }
        void get(int index){
            if(index >= 0 && index < size){
                arr.count(index) == 0 ? cout<<0<<endl : cout<<arr[index]<<endl;
            }
            else
                cout<<"Out of range"<<endl;
        }
};

int main() {
    SpaceEfficient s;
    s.init(100);
    s.set(3,15);
    s.set(1,5);
    s.set(7,20);
    s.set(11,55);
    s.get(25);
    s.get(1);
    s.get(3);
    s.get(102);
    s.get(99);
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/7m7lpOnlTs)**