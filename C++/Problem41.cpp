/*
Daily Coding Problem: Problem #41 [Medium]
Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

Given an unordered list of flights taken by someone, each represented as (origin, destination) pairs, 
and a starting airport, compute the person's itinerary. If no such itinerary exists, return null. 
If there are multiple possible itineraries, return the lexicographically smallest one. All flights must be used in the itinerary.

For example, given the list of flights [('SFO', 'HKO'), ('YYZ', 'SFO'), ('YUL', 'YYZ'), ('HKO', 'ORD')] and 
starting airport 'YUL', you should return the list ['YUL', 'YYZ', 'SFO', 'HKO', 'ORD'].

Given the list of flights [('SFO', 'COM'), ('COM', 'YYZ')] and starting airport 'COM', you should return null.

Given the list of flights [('A', 'B'), ('A', 'C'), ('B', 'C'), ('C', 'A')] and starting airport 'A', 
you should return the list ['A', 'B', 'C', 'A', 'C'] even though ['A', 'C', 'A', 'B', 'C'] is also a valid itinerary. 
However, the first one is lexicographically smaller.

Example
input
3
4
A B
A C
B C
C A
A
2
SFO COM
COM YYZ
COM
4
YUL ORD
HNL AKL
ORD SFO
SFO HNL
YUL

output
A --&gt; B --&gt; C --&gt; A --&gt; C
No route is possible
YUL --&gt; ORD --&gt; SFO --&gt; HNL --&gt; AKL

*/

//You can get my code in IDE https://ide.geeksforgeeks.org/G6Mmi7IgK2
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
//Additional function for print multimap
void print(multimap<string, string>mp) 
{
    for(auto it = mp.begin(); it != mp.end(); it++)
        cout<<it->first<<" : "<<it->second<<endl;
}
//final route print
void print_route(vector<string>v)
{
    if(v.size() == 0)
    {
        cout<<"No route is possible"<<endl;
        return;
    }
    for(int i = 0; i < v.size(); i++)
    {
         cout<<v[i];
         if(i < v.size()-1)
            cout<<" --> ";
         else
            cout<<endl;
    }
}


//main logic 
vector<string> get_itinerary(multimap<string, string>flight, vector<string>&itinerary)
{
    if (flight.size() <= 0) //when we cover all flight
        return itinerary;
    
    string last_dest = itinerary.back();//last destion upto which we reached
    for(auto it = flight.begin(); it != flight.end(); it++)
    {
        string org = it->first, dest = it->second;//current flight
        multimap<string, string>tmp(flight);//copy
        auto itr = tmp.find(org);
        while(itr->second != dest && itr != tmp.end())//finding the current flight
            itr++;
        if(itr != tmp.end())//erease the current flight
            tmp.erase(itr);
        
        itinerary.push_back(dest);//new destionation
        
        if(last_dest == org)//org and last destionation is same
            return get_itinerary(tmp, itinerary);
        itinerary.pop_back();//org and last destionation is not same
    }
    return vector<string>();//whene no route possible
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n, i;
	    cin>>n;//no. of flight;
	    string org, dest;
	    multimap<string, string>flight;
	    for(i = 0; i < n; i++)
	    {
	        cin>>org>>dest;//src dest
	        flight.insert({org, dest});
	    }
	    cin>>org;
	    vector<string>itinerary;
	    itinerary.push_back(org);//starting point
	    itinerary = get_itinerary(flight, itinerary);
	    print_route(itinerary);
	}
	return 0;
}