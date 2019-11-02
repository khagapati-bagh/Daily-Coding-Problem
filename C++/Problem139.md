
# Daily Coding Problem: Problem #139 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given an iterator with methods next() and hasNext(), create a wrapper iterator, PeekableInterface, which also implements peek(). peek shows the next element that would be returned on next().

Here is the interface:
```
class PeekableInterface(object):
    def __init__(self, iterator):
        pass

    def peek(self):
        pass

    def next(self):
        pass

    def hasNext(self):
        pass
```
**Solution** :

```cpp

#include <bits/stdc++.h>
using namespace std;

class PeekableInterface{
        vector<int>v{1,2,3,4,5};
        vector<int>::iterator it = v.begin();
    public:
        int peak(){
            if(it != v.end())
                return *it;
            return -1;
        }
        int next(){
            if(it != v.end()){
                int x = *it;
                v.erase(it);
                it = v.begin();
                return x;
            }
            return -1;
        }
        bool hasNext(){
            if(it != v.end())
                return true;
            return false;
        }
};

int main() {
    PeekableInterface obj;
    cout<<"peak() : "<<obj.peak()<<endl;
    obj.hasNext() ? cout<<"hasNext() : True"<<endl : cout<<"hasNext() : False"<<endl;
    cout<<"next() : "<<obj.next()<<endl;
    cout<<"next() : "<<obj.next()<<endl;
    cout<<"next() : "<<obj.next()<<endl;
    cout<<"peak() : "<<obj.peak()<<endl;
    obj.hasNext() ? cout<<"hasNext() : True"<<endl : cout<<"hasNext() : False"<<endl;
    cout<<"next() : "<<obj.next()<<endl;
    cout<<"next() : "<<obj.next()<<endl;
    cout<<"peak() : "<<obj.peak()<<endl;
    obj.hasNext() ? cout<<"hasNext() : True"<<endl : cout<<"hasNext() : False"<<endl;
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/PV4l0OJaBe)**