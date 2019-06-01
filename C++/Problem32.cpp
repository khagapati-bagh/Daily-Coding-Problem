/*
Daily Coding Problem: Problem #32 [Hard]

Good morning! Here's your coding interview problem for today.

This problem was asked by Jane Street.

Suppose you are given a table of currency exchange rates, represented as a 2D array. 
Determine whether there is a possible arbitrage: that is, whether there is some sequence of trades you can make, 
starting with some amount A of any currency, so that you can end up with some amount greater than A of that currency.

There are no transaction costs and you can trade fractional quantities.

Example
input
2
3
0 .5 4.9
1.99 0 10
.19 .09 0
3
0 .5 0
0 0 10
.205 0 0

output
No
Yes
*/

//You can get my code in IDE https://ide.geeksforgeeks.org/3cOfIqUI9s
//This code will take O(n^3) Time and O(n^2) Space Complexity
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void print(vector<vector<float>>v)//additional function
{
    for(int i = 0; i < v.size(); i++)
    {
        for(auto j : v[i])
            cout<<j<<' ';
        cout<<endl;
    }
}
void print_mn(vector<float>v) //additional function
{
    for(auto a : v)
        cout<<a<<' ';
    cout<<endl;
}
void change_to_log(vector<vector<float>>&v){
    for(int i = 0; i < v.size(); i++)
        for(int j = 0; j < v.size(); j++)
            v[i][j] = -log(v[i][j]);
}

bool check_arbitage(vector<vector<float>>currrency)
{
    //Here I'm using Bellman Ford Algo
    //-log(x) < 0 if x > 1
    //it will detect -ve edge cycle 
    int n = currrency.size(), i, j, k;
    vector<float>min_dist(n,INT_MAX);
    change_to_log(currrency);
    //print(currrency);
    //print_mn(min_dist);
    min_dist[0] = 0;//source
    for(k = 0; k < n-1; k++)//No of edges
    {
        for(i = 0; i < n; i++)//Rows
        {
            for(j = 0; j < n; j++)//columns
            {
                if(min_dist[j] > min_dist[i] + currrency[i][j])
                    min_dist[j] = min_dist[i] + currrency[i][j];
            }
        }
    }
    // Checking -ve edges cycle
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
            if(min_dist[j] > min_dist[i] + currrency[i][j])
                return true;
    }
    return false;
}

int main() {//This problem is the application of Bellman Ford Algo
    int t;
    cin>>t;//Test cases
    while(t--){
        int n,i,j;
        float x;
        cin>>n;
        vector<vector<float>>currrency(n,vector<float>(n,0));
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                cin>>x;
                currrency[i][j] = x;
            }
        }
        //print(currrency);
        if(check_arbitage(currrency))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}