/*
Daily Coding Problem: Problem #42 [Hard]
Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given a list of integers S and a target number k, write a function that returns a subset of S that adds up to k. 
If such a subset cannot be made, then return null.

Integers can appear more than once in the list. You may assume all numbers in the list are positive.

For example, given S = [12, 1, 61, 5, 9, 2] and k = 24, return [12, 9, 2, 1] since it sums up to 24.
Example
input
3
6 24
12 8 61 5 9 5
10 17
3 2 4 19 3 7 13 10 6 11
6 24
12 8 61 5 9 3

output
NO : -1
YES : 7 3 4 3 
YES : 3 9 12 

*/
//You can get my code in IDE https://ide.geeksforgeeks.org/e31qQ19o92
//This code will take O(nt) Time and Space Complexity where n = no. of input and t = target
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void print(vector<vector<bool>>v)
{
    for(int i =0; i < v.size(); i++)
    {
        for(auto a : v[i])
            cout<<a<<' ';
        cout<<endl;
    }
}
void isSubsetSum(vector<int>set, int sum) 
{ 
    int n = set.size();
    //bool subset[n+1][sum+1]; 
    vector<vector<bool>>subset(n+1,vector<bool>(sum+1));
   
    // If sum is 0, then answer is true 
    for (int i = 0; i <= n; i++) 
        subset[i][0] = true; 
   
    // If sum is not 0 and set is empty, then answer is false 
    for (int i = 1; i <= sum; i++) 
        subset[0][i] = false; 
     // Fill the subset table in botton up manner 
    for (int i = 1; i <= n; i++) 
    { 
        for (int j = 1; j <= sum; j++) 
        { 
            if(j < set[i-1]) 
                subset[i][j] = subset[i-1][j]; 
            if (j >= set[i-1]) 
                subset[i][j] = subset[i-1][j] || subset[i - 1][j-set[i-1]]; //max
        } 
    } 
    
    int res = subset[n][sum];
    int w = sum; 
    if(res != 0)
    {
        cout<<"YES : ";
        for (int i = n; i > 0 && res > 0; i--) { 
            if (res == subset[i - 1][w])  
                continue;         
            else { 
                cout<<set[i - 1]<<' ' ;
                w = w - set[i - 1]; 
            } 
        } 
        cout<<endl;
    }
    else
    cout<<"NO : "<<-1<<endl;
    //return subset[n][sum]; 
} 

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k, i;
	    cin>>n>>k;
	    vector<int>v(n);
	    for(i = 0; i < n; i++)
	        cin>>v[i];
	    isSubsetSum(v, k);
	}
	return 0;
}