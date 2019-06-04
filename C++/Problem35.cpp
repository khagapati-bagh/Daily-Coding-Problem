/*
Daily Coding Problem: Problem #35 [Hard]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Given an array of strictly the characters 'R', 'G', and 'B', segregate the values of the array so that all the 
Rs come first, the Gs come second, and the Bs come last. You can only swap elements of the array.

Do this in linear time and in-place.

For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B'].
Example
input
3
10
GBGBGBGBGB
5
GBRBB
7
GBRRBRG

output
G G G G G B B B B B 
R G B B B 
R R R G G B B 

*/
//You can get my code in IDE https://ide.geeksforgeeks.org/EsJMlNcUeP
//This code will take O(n) Time and O(1) Space Complexity

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void make_charnge(char *ptr)
{
    int len = strlen(ptr), r_cnt = 0, g_cnt = 0, b_cnt = 0;
    for(int i = 0; i < len; i++)
    {
        if(ptr[i] == 'R')
            r_cnt++;
        else if(ptr[i] == 'G')
            g_cnt++;
        else
            b_cnt++;
    }
    for(int i = 0; i < len; i++)
    {
        if(i < r_cnt)
            ptr[i] = 'R';
        else if(i < r_cnt + g_cnt)
            ptr[i] = 'G';
        else
            ptr[i] = 'B';
        //cout<<ptr[i]<<' ';
    }
    //cout<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--){
        int n,i;
        cin>>n;
        char color[n];
        for(i = 0; i < n; i++)
            cin>>color[i];
        
        make_charnge(color);
        for(i = 0; i < n; i++)
        printf("%c ", color[i]);
        printf("\n");
    }
    return 0;
}