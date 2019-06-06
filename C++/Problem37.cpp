/*
Daily Coding Problem: Problem #37 [Easy]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

The power set of a set is the set of all its subsets. Write a function that, given a set, generates its power set.

For example, given the set {1, 2, 3}, it should return {{}, {1}, {2}, {3}, {1, 2}, {1, 3}, {2, 3}, {1, 2, 3}}.

You may also use a list or array to represent a set.
Example
input
2
4
1 2 3 4
3
1 2 3

output
{{}, {1}, {1, 2}, {1, 2, 3}, {1, 2, 3, 4}, {1, 2, 4}, {1, 3}, {1, 3, 4}, {1, 4}, {2}, {2, 3}, {2, 3, 4}, {2, 4}, {3}, {3, 4}, {4}}
{{}, {1}, {1, 2}, {1, 2, 3}, {1, 3}, {2}, {2, 3}, {3}}

*/

//You can get my code in IDE https://ide.geeksforgeeks.org/m5fJx33NEk
//This code will take O(n 2^n) Time and O(n^2) Space Complexity
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<int>>v)
{
    cout<<"{";
    for(int i = 0; i < v.size(); i++)
    {
        cout<<"{";
        for(int j =0; j < v[i].size(); j++)
        {
            cout<<v[i][j];
            if(j < v[i].size() -1)
                cout<<", ";
        }
        cout<<"}";
        if(i < v.size() -1)
                cout<<", ";
    }
    cout<<"}"<<endl;
}


//using Bit-manipulation

void subsets(vector<int>& nums) {
    int n = nums.size();
    int p = 1<<n;//power set size
    vector<vector<int>>res(p);   //initialize powerset     
    for(int i = 0; i < p; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if((i >> j) & 1)//if bit is set 
            {
                //cout<<nums[j]<<" : "<<i<<", "<<j<<" : "<<(i >>j)<<" ";
                res[i].push_back(nums[j]);
            }
        }
    }
    print(res);
}

/*
// using recursive
void make_subset(vector<int>&nums, vector<vector<int>>&res, vector<int>&tmp, int ind)
{
    res.push_back(tmp);//res;
    for(int i = ind; i < nums.size(); i++)
    {
        tmp.push_back(nums[i]);
        make_subset(nums, res, tmp, i+1);
        tmp.pop_back();
    }
}
void subsets(vector<int>& nums) {
    vector<vector<int>>res;
    vector<int>tmp;
    make_subset(nums, res, tmp, 0);
    print(res);
}

*/
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector<int>input_set(n);
	    for(int i =0; i < n; i++)
	        cin>>input_set[i];
	    subsets(input_set);
	}
	return 0;
}