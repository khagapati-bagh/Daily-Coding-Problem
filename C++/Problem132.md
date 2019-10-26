
# Daily Coding Problem: Problem #132 [Easy]

Good morning! Here's your coding interview problem for today.

This question was asked by Riot Games.

Design and implement a HitCounter class that keeps track of requests (or hits). It should support the following operations:

record(timestamp): records a hit that happened at timestamp
total(): returns the total number of hits recorded
range(lower, upper): returns the number of hits that occurred between timestamps lower and upper (inclusive)
Follow-up: What if our system has limited memory?

**Solution** :

```cpp

#include <bits/stdc++.h>
using namespace std;
class HitCounter{
    private: vector<int> counter;
    public:
        void record(int timeStamp){
            counter.push_back(timeStamp);
        }
        void total(){
            cout<<"Total no. of HitCounter is : "<<counter.size()<<endl;
        }
        void range(int lower, int upper){
            sort(counter.begin(), counter.end());
            int x = lower_bound(counter.begin(), counter.end(), lower) - counter.begin();
            int y = upper_bound(counter.begin(), counter.end(), upper) - counter.begin();
            /*cout<<*lower_bound(counter.begin(), counter.end(), lower)<<' ';
            cout<<*upper_bound(counter.begin(), counter.end(), upper)<<endl;*/
            cout<<"Total no. of HitCounter in the range of "<<lower<<" and "<<upper<<" is : "<< y - x<<endl;
        }
};
int main(){
    HitCounter *obj = new HitCounter();
    obj->record(1);
    obj->record(2);
    obj->record(8);
    obj->record(5);
    obj->total();
    obj->range(2, 6);
    obj->record(3);
    obj->record(4);
    obj->record(10);
    obj->total();
    obj->range(1, 7);
    return 0;
}

```

**[Run Code](https://ide.geeksforgeeks.org/KozQS9q2WI)**