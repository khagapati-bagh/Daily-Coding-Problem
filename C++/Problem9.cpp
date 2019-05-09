/*Good morning! Here's your coding interview problem for today.

This problem was asked by Airbnb.

Given a list of integers, write a function that returns the largest sum of non-adjacent numbers. Numbers can be 0 or negative.

For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should return 10, since we pick 5 and 5.

Follow-up: Can you do this in O(N) time and constant space?

The Recursive formula is 
	{ max(res[i-1], res[i-2] + v[i]) 	if i>=2	
res[i]= { max(v[0],v[1])  			if i=1
	{ v[0]					if i=0

This program will take O(n) Time and Space Complexity
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int max_sum(vector<int>v)
{
    int i,n = v.size();
    vector<int>res(n+1);
    res[0] = v[0];
    res[1] = (v[1] > v[0] ? v[1] : v[0]); //check first or 2nd 
    for(i = 2; i < n; i++)
        res[i] = (res[i-1] > res[i-2] + v[i] ? res[i-1] : res[i-2]+v[i]); // check previous is greater or previos of previous + current
    return res[n-1];
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n;
	    vector<int>v(n);
	    for(i = 0;i < n; i++)
	    {
	        cin>>v[i];
	    }
	    cout<<max_sum(v)<<endl;
	}
	return 0;
}
