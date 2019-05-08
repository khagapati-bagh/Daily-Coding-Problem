/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Jane Street.

cons(a, b) constructs a pair, and car(pair) and cdr(pair) returns the first and last element of that pair. For example, car(cons(3, 4)) returns 3, and cdr(cons(3, 4)) returns 4.

Given this implementation of cons:

def cons(a, b):
    def pair(f):
        return f(a, b)
    return pair
Implement car and cdr.
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int car(pair<int, int>p)
{
    return p.first;
}
int cdr(pair<int,int>p)
{
    return p.second;
}

pair<int,int> cons(int a, int b)
{
    pair<int,int>p(a,b);
    return p;
}

int main() {
	//cout<<"GfG!";
	int t;
	cin>>t;
	while(t--)
	{
	    int a,b;
	    cin>>a>>b;
    	cout<<car(cons(a,b))<<endl;
    	cout<<cdr(cons(a,b))<<endl;
	}
	return 0;
}