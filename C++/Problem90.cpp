/*
Daily Coding Problem: Problem #90 [Medium]

Good morning! Here's your coding interview problem for today.

This question was asked by Google.

Given an integer n and a list of integers l, write a function that randomly generates a number from 0 to n-1 that isn't in l (uniform).

Example
input
3
6 3
1 3 5
6 0
6 2
1 3

output
| 0.33237 |       0 | 0.33688 |       0 | 0.33075 |       0 
| 0.16593 | 0.16572 | 0.16711 | 0.16601 | 0.16758 | 0.16765 
| 0.24878 |       0 |  0.2514 |       0 | 0.24927 | 0.25055 

*/

//You can get my code in IDE https://ide.geeksforgeeks.org/Nktr6F8iF8

#include <bits/stdc++.h>
using namespace std;
int generate_random(int n, vector<int>list)
{
    int num = rand() % n;
    if(list[num])   return generate_random(n, list);
    return num;
}
void run_experiment(vector<int>list, vector<double>&res, int sample)
{
    int n = list.size();
    for(int i = 0; i < sample; i++)
    {
        int random = generate_random(n, list);
        res[random]++;
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m, x;
        cin>>n>>m;
        unordered_map<int, int>mp;
        vector<int>list(n,0) ;
        for(int i = 0; i < m; i++)
        {
            cin>>x;
            list[x]++;
        }
        vector<double>res(n,0);
        run_experiment(list, res, 100000);
        for(double i : res)
            cout<<"| "<<setw(7)<<(i/100000.0)<<" ";
        cout<<endl;
    }
}