/*
Daily Coding Problem: Problem #96 [Easy]

Good morning! Here's your coding interview problem for today.

This problem was asked by Microsoft.

Given a number in the form of a list of digits, return all possible permutations.

For example, given [1,2,3], return [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]].

Example
input
2
3
1 2 3
5
1 2 3 4 5

output
[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,2,1],[3,1,2],]
[[1,2,3,4,5],[1,2,3,5,4],[1,2,4,3,5],[1,2,4,5,3],[1,2,5,4,3],[1,2,5,3,4],[1,3,2,4,5],[1,3,2,5,4],[1,3,4,2,5],[1,3,4,5,2],[1,3,5,4,2],[1,3,5,2,4],[1,4,3,2,5],[1,4,3,5,2],[1,4,2,3,5],[1,4,2,5,3],[1,4,5,2,3],[1,4,5,3,2],[1,5,3,4,2],[1,5,3,2,4],[1,5,4,3,2],[1,5,4,2,3],[1,5,2,4,3],[1,5,2,3,4],[2,1,3,4,5],[2,1,3,5,4],[2,1,4,3,5],[2,1,4,5,3],[2,1,5,4,3],[2,1,5,3,4],[2,3,1,4,5],[2,3,1,5,4],[2,3,4,1,5],[2,3,4,5,1],[2,3,5,4,1],[2,3,5,1,4],[2,4,3,1,5],[2,4,3,5,1],[2,4,1,3,5],[2,4,1,5,3],[2,4,5,1,3],[2,4,5,3,1],[2,5,3,4,1],[2,5,3,1,4],[2,5,4,3,1],[2,5,4,1,3],[2,5,1,4,3],[2,5,1,3,4],[3,2,1,4,5],[3,2,1,5,4],[3,2,4,1,5],[3,2,4,5,1],[3,2,5,4,1],[3,2,5,1,4],[3,1,2,4,5],[3,1,2,5,4],[3,1,4,2,5],[3,1,4,5,2],[3,1,5,4,2],[3,1,5,2,4],[3,4,1,2,5],[3,4,1,5,2],[3,4,2,1,5],[3,4,2,5,1],[3,4,5,2,1],[3,4,5,1,2],[3,5,1,4,2],[3,5,1,2,4],[3,5,4,1,2],[3,5,4,2,1],[3,5,2,4,1],[3,5,2,1,4],[4,2,3,1,5],[4,2,3,5,1],[4,2,1,3,5],[4,2,1,5,3],[4,2,5,1,3],[4,2,5,3,1],[4,3,2,1,5],[4,3,2,5,1],[4,3,1,2,5],[4,3,1,5,2],[4,3,5,1,2],[4,3,5,2,1],[4,1,3,2,5],[4,1,3,5,2],[4,1,2,3,5],[4,1,2,5,3],[4,1,5,2,3],[4,1,5,3,2],[4,5,3,1,2],[4,5,3,2,1],[4,5,1,3,2],[4,5,1,2,3],[4,5,2,1,3],[4,5,2,3,1],[5,2,3,4,1],[5,2,3,1,4],[5,2,4,3,1],[5,2,4,1,3],[5,2,1,4,3],[5,2,1,3,4],[5,3,2,4,1],[5,3,2,1,4],[5,3,4,2,1],[5,3,4,1,2],[5,3,1,4,2],[5,3,1,2,4],[5,4,3,2,1],[5,4,3,1,2],[5,4,2,3,1],[5,4,2,1,3],[5,4,1,2,3],[5,4,1,3,2],[5,1,3,4,2],[5,1,3,2,4],[5,1,4,3,2],[5,1,4,2,3],[5,1,2,4,3],[5,1,2,3,4],]

*/

//You can get my code on IDE https://ide.geeksforgeeks.org/3ZdGBJcGwn
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(vector<int>v)
{
    int n = v.size();
    cout<<"[";
    for(int i = 0; i < n; i++) 
    {
        cout<<v[i];
        if(i < n-1)
            cout<<",";
    }
    cout<<"],";
}

//This code will take O(n * n!) Time and O(1) Space Complexity
void permutation(vector<int>&v, int left, int right)
{
    if(left == right)
        print(v);
    else
    {
        for(int i = left; i <= right; i++)
        {
            swap(v[left], v[i]);
            permutation(v, left + 1, right);
            swap(v[left], v[i]);
        }
    }
}

/*
//This code will take O(n * n!) Time and O(1) Space Complexity
void permutation(vector<int>&v, int size, int n)
{
    if(size == 1)
    {
        print(v);
        return;
    }
    
    for(int i = 0; i < size; i++)
    {
        permutation(v, size - 1, n);
        if(size&1)//size is odd
            swap(v[0], v[size-1]);
        else//size is even
            swap(v[i], v[size-1]);
    }
}
*/
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        std::vector<int>v(n);
        for(int i = 0 ; i < n; i++)
            cin>>v[i];
        cout<<"[";
        permutation(v, 0, n-1);
        //permutation(v, n, n);
        cout<<"]"<<endl;
    }
    return 0;
}