
# Daily Coding Problem: Problem #120 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Microsoft.

Implement the singleton pattern with a twist. First, instead of storing one instance, store two instances. And in every even call of getInstance(), return the first instance and in every odd call of getInstance(), return the second instance.

**Solution** :

```cpp

#include <bits/stdc++.h>
using namespace std;

class SingleTon{
    public:
        int count, x, y;
        SingleTon(){};
        SingleTon(int a, int b){
            x = a;
            y = b;
        }
        void getInstance(){
            count++;
            if(count & 1){
                cout<< "Odd Instance\t"<<y<<endl;
            }
            else
                cout<<"Even Instance\t"<<x<<endl;
        }
};

int main() {
    SingleTon *obj = new SingleTon(5, 10);
    obj->getInstance();
    obj->getInstance();
    obj->getInstance();
    obj->getInstance();
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/xZHakHM63R)**