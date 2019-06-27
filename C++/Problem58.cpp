/*
Daily Coding Problem: Problem #58 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Amazon.

An sorted array of integers was rotated an unknown number of times.

Given such an array, find the index of the element in the array in faster than linear time. If the element doesn't exist in the array, return null.

For example, given the array [13, 18, 25, 2, 8, 10] and the element 8, return 4 (the index of 8 in the array).

You can assume all the integers in the array are unique.
Example
input
5
6 2
13 18 25 2 8 10
6 1
13 18 25 2 8 10
6 8
13 18 25 2 8 10
6 18
13 18 25 2 8 10
6 25
13 18 25 2 8 10

output
3
-1
4
1
2

*/

//You can get my code in IDE https://ide.geeksforgeeks.org/ozlCHNH6j8
//This code will take O(log n) Time and O(1) Space Complexity
#include<bits/stdc++.h>
using namespace std;

int find_peak(vector<int>v)
{
    int low =0, high = v.size()-1;
    while(low < high)
    {
        int mid = (low + high)/2;
        if(v[mid+1] > v[mid])
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int binay_search(vector<int>v, int low, int high, int x)
{
    if (high >= low) { 
        int mid = low + (high - low) / 2; 
  
        // If the element is present at the middle 
        // itself 
        if (v[mid] == x) 
            return mid; 
  
        // If element is smaller than mid, then 
        // it can only be present in left subarray 
        if (v[mid] > x) 
            return binay_search(v, low, mid - 1, x); 
  
        // Else the element can only be present 
        // in right subarray 
        return binay_search(v, mid + 1, high, x); 
    } 
  
    // We reach here when element is not 
    // present in array 
    return -1; 
}

int find_index(vector<int>v, int k)
{
    int x = find_peak(v), n = v.size();
    if(v[x] == k)
        return x;
    if(v[n-1] >= k)
        return binay_search(v, x+1, n-1, k);
    else
        return binay_search(v, 0, x-1, k);
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        vector<int>v(n);
        for(int i = 0; i < n; i++)
            cin>>v[i];
        cout<<find_index(v, k)<<endl;
    }
    return 0;
}