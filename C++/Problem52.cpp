/*
Daily Coding Problem: Problem #52 [Hard]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Implement an LRU (Least Recently Used) cache. It should be able to be initialized with a cache size n, and contain the following methods:

set(key, value): sets key to value. If there are already n items in the cache and we are adding a new item, then it should also remove the least recently used item.
get(key): gets the value at key. If no such key exists, return null.
Each operation should run in O(1) time.
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class LRUCache {
private:
    //A list of (key, value) pairs
    list<pair<int, int>>items;
    //map (key, iterator of the above list)
    unordered_map<int, list<pair<int,int>>::iterator> cache;
    int capacity;//capacity of chche/ buffer
public:
    LRUCache(int capacity): capacity(capacity) {}
    
    int get(int key) {
        if(cache.find(key) == cache.end())//key not found
            return -1;
        //Move the element to begining of the list
        items.splice(items.begin(), items, cache[key]);
        return cache[key]->second;
    }
    
    void put(int key, int value) {
        //if key is not in the hash table
        if(cache.find(key) == cache.end())
        {
            //if hash table size equal to capacity then remove the LRU element which is in end of hte list
            if(items.size() == capacity)
            {
                cache.erase(items.back().first);//items.back().first is the key
                items.pop_back();//remove from list
            }
            items.push_front(make_pair(key, value));//push in the front of the list
            cache[key] = items.begin();//add in the hash table
        }
        else
        {
            //update the value associated with the key
            cache[key]->second = value;
            //Move the (key, value) pair to begining of the list
            items.splice(items.begin(), items, cache[key]);
        }
    }

    void display()
    {
    	cout<<"Key\t Value"<<endl;
    	for(auto it = items.begin(); it != items.end(); it++)
    	{
    		cout<<it->first<<"\t"<<it->second<<endl;
    	}
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main()
{
    int ch, n, k, v;
    cout<<"Enter the capacity of cache : ";
    cin>>n;
    LRUCache* cache = new LRUCache(n);
    while(1)
    {
    	cout<<"\n1. Print the cache\n2. Put (Key, Value)\n3. Get (key)\n4. Exit\nEnter your choice : ";
    	cin>>ch;
    	switch(ch)
    	{
    		case 1: cache->display(); break;
    		case 2: cin>>k>>v;cache->put(k,v); break;
    		case 3: cin>>k; cout<<cache->get(k)<<endl; break;
    		case 4: exit(1);
    		default: cout<<"Invalid option try again"<<endl;
    	}
    }
    return 0;
}