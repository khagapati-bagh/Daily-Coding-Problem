/*
Daily Coding Problem: Problem #95 [Hard]
Good morning! Here's your coding interview problem for today.

This problem was asked by Palantir.

Given a number represented by a list of digits, find the next greater permutation of a number, in terms of lexicographic ordering. If there is not greater permutation possible, return the permutation with the lowest value/ordering.

For example, the list [1,2,3] should return [1,3,2]. The list [1,3,2] should return [2,1,3]. The list [3,2,1] should return [1,2,3].

Can you perform the operation without allocating extra memory (disregarding the input memory)?

Example
input
5
4
1 2 4 3
3
1 2 3
3
3 2 1
3
1 3 2
5
1 1 2 3 4

output
1 3 2 4 
1 3 2 
1 2 3 
2 1 3 
1 1 2 4 3 

*/

//You can get my code in IDE https://ide.geeksforgeeks.org/yyfxOtoXGI
//This code will take O(n log n) Time and O(1) Space complexity
#include<bits/stdc++.h>
using namespace std;
void nextpermutation(vector<int>&v)
{
    int n = v.size(), i;
    for(i = n-1; i > 0; i--)
        if(v[i] > v[i-1])
            break;
    if(i == 0) {
        sort(v.begin(), v.end());
        return;
    }
    int x = i-1;
    int smalest = i;
    for(int j = i + 1; j < n; j++)
        if(v[j] > v[x] && v[j] < v[smalest])
            smalest = j;
    swap(v[x], v[smalest]);
    sort(v.begin()+i, v.end());
    
}
int main(){

    int t;
    cin>>t;
    while(t--){
    
        int n;
        cin>>n;
        vector<int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        nextpermutation(v);
        for(int i : v)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}