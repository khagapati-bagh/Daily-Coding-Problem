/*
Daily Coding Problem: Problem #30 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

You are given an array of non-negative integers that represents a two-dimensional elevation map where each element 
is unit-width wall and the integer is the height. Suppose it will rain and all spots between two walls get filled up.

Compute how many units of water remain trapped on the map in O(N) time and O(1) space.

For example, given the input [2, 1, 2], we can hold 1 unit of water in the middle.

Given the input [3, 0, 1, 3, 0, 5], we can hold 3 units in the first index, 2 in the second, and 3 in the fourth index 
(we cannot hold 5 since it would run off to the left), so we can trap 8 units of water.

Example 
input

3
6
3 0 1 3 0 5
4
7 4 0 9
3
6 9 9

output

8
10
0

*/
//You can get my code in IDE https://ide.geeksforgeeks.org/q9wMIj5xZp
//This code will take O(n) Time and O(1) Space Complexity
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int total_water_trapped(vector<int>height){
    int low = 0, high = height.size() - 1, left_max = 0, right_max = 0;
    //left_max = left max wall, right_max = right max wall
    int res = 0;
    while(low < high){
        if(height[low] < height[high]){
            if(height[low] > left_max) //we change our left max to current max
                left_max = height[low];
            else //add to result 
                res += left_max - height[low];
            low++;
        }
        else{
            if(height[high] > right_max)//we change our right max to current max
                right_max = height[high];
            else
                res += right_max - height[high];
            high--;//move to previous wall
        }
    }
    return res;
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n,i,x;
	    cin>>n;
	    vector<int>height(n);
	    for(i = 0; i < n; i++)
	        cin>>height[i];
	    cout<<total_water_trapped(height)<<endl;
	}
	return 0;
}