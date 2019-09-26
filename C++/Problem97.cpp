/*
Daily Coding Problem: Problem #97 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Stripe.

Write a map implementation with a get function that lets you retrieve the value of a key at a particular time.

It should contain the following methods:

set(key, value, time): sets key to value for t = time.
get(key, time): gets the key at t = time.
The map should work like this. If we set a key at a particular time, it will maintain that value forever or until it gets set at a later time. In other words, when we get a key at a time, it should return the value that was set for that key set at the most recent time.

Consider the following examples:

d.set(1, 1, 0) # set key 1 to value 1 at time 0
d.set(1, 2, 2) # set key 1 to value 2 at time 2
d.get(1, 1) # get key 1 at time 1 should be 1
d.get(1, 3) # get key 1 at time 3 should be 2
d.set(1, 1, 5) # set key 1 to value 1 at time 5
d.get(1, 0) # get key 1 at time 0 should be null
d.get(1, 10) # get key 1 at time 10 should be 1
d.set(1, 1, 0) # set key 1 to value 1 at time 0
d.set(1, 2, 0) # set key 1 to value 2 at time 0
d.get(1, 0) # get key 1 at time 0 should be 2

Output
key value   time
2   12      1
2   21      2
1   2       2
1   1       0
obj-&gt;get(1, 1) : 1
obj-&gt;get(1, 3) : 2
obj-&gt;get(2, 1) : 12

key value   time
1   1       5
obj-&gt;get(1, 0) : NULL
obj-&gt;get(1, 10) : 1

key value   time
1   2       0
obj-&gt;get(1, 0) : 2

*/

//This method will take O(n) Time and Space complexity
//You can get my code on IDE link https://ide.geeksforgeeks.org/1AylItdhlO
#include <iostream>
#include <unordered_map>
#include <bits/stdc++.h>
using namespace std;

class MapIimplementation{
    public:
        unordered_map<int, unordered_map<int, int>>mp;//data structure
        
        //This method will take O(n) Time complexity
        void get(int key, int time1){
            
            if(mp.find(key) != mp.end()){
                
                unordered_map<int, int>tmp;
                int index = -1;
                tmp = mp[key];
                
                //finding the time which is <= to the given time
                for(auto it = tmp.begin(); it != tmp.end(); it++){
                    if(it->first <= time1 && it->first > index)
                        index = it->first;
                }
                //if time is there
                if(index != -1){   
                    cout<<"obj->get("<<key<<", "<<time1<<") : "<<tmp[index]<<endl;
                    return;
                }
            }
            cout<<"obj->get("<<key<<", "<<time1<<") : "<<"NULL"<<endl;
        }
        
        void set(int key, int value, int time1){
            
            unordered_map<int, int>tmp;
            
            //key is already exist
            if(mp.find(key) != mp.end()){
                (mp[key])[time1] = value;
            }
            else{//new key
                tmp[time1] = value;
                mp[key] = tmp;
            }
        }
        
        //print data of the object
        void show(){
            cout<<"key\tvalue\ttime"<<endl;
            for(auto it = mp.begin(); it != mp.end(); it++){
                for(auto i = it->second.begin(); i != it->second.end(); i++){
                    cout<<it->first<<"\t"<<i->second<<"\t"<<i->first<<endl;
                }
            }
        }
};
int main(){
    
    MapIimplementation *obj = new MapIimplementation();
    obj->set(1, 1, 0);
    obj->set(1, 2, 2);
    obj->set(2, 21, 2);
    obj->set(2, 12, 1);
    obj->show();
    obj->get(1, 1);
    obj->get(1, 3);
    obj->get(2, 1);
    cout<<endl;
    
    MapIimplementation *obj2 = new MapIimplementation();
    obj2->set(1, 1, 5);
    obj2->show();
    obj2->get(1, 0);
    obj2->get(1, 10);
    cout<<endl;
    
    MapIimplementation *obj3 = new MapIimplementation();
    obj3->set(1, 1, 0);
    obj3->set(1, 2, 0);
    obj3->show();
    obj3->get(1, 0);

    return 0;
}
