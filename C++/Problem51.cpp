/*
Daily Coding Problem: Problem #51 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

Given a function that generates perfectly random numbers between 1 and k (inclusive), where k is an input, write a function that shuffles a deck of cards represented as an array using only swaps.

It should run in O(N) time.

Hint: Make sure each one of the 52! permutations of the deck is equally likely.
Example 
output
10 20 22 14 19 9 2 51 38 13 12 8 27 26 1 15 39 32 42 43 3 16 11 6 45 25 31 52 44 36 4 49 41 33 34 18 23 46 5 30 28 47 21 17 37 7 40 29 50 24 35 48 
13 43 16 26 42 38 20 35 46 27 8 51 31 25 10 1 5 49 47 21 22 15 12 9 37 45 4 48 17 18 14 50 28 41 33 32 11 7 19 36 52 40 3 39 23 2 30 44 24 6 34 29 
27 21 15 25 47 46 43 34 7 31 51 35 4 45 13 10 19 50 40 3 16 1 8 38 23 37 14 29 39 32 26 24 52 28 41 49 12 2 42 18 48 30 22 5 11 20 36 17 6 9 33 44 
31 3 1 45 40 7 21 33 2 4 35 34 14 37 27 13 42 24 30 22 15 10 51 46 11 23 26 44 5 49 25 6 48 52 28 50 8 20 47 32 29 36 16 19 12 43 18 39 9 38 41 17 
4 22 10 37 30 2 3 41 20 14 34 33 26 23 31 27 47 6 36 16 1 13 35 7 12 11 25 17 19 50 45 9 29 48 52 24 51 43 40 49 44 18 15 42 8 21 32 5 38 46 28 39 
14 16 13 23 36 20 22 28 43 26 33 41 25 11 4 31 40 9 18 15 10 27 34 2 8 12 45 39 42 24 37 38 44 29 48 6 35 21 30 50 17 32 1 47 51 3 49 19 46 7 52 5 
26 15 27 11 18 43 16 52 21 25 41 28 45 12 14 4 30 38 32 1 13 31 33 20 51 8 37 5 47 6 23 46 17 44 29 9 34 3 36 24 39 49 10 40 35 22 50 42 7 2 48 19 
25 1 31 12 32 21 15 48 3 45 28 52 37 8 26 14 36 46 49 10 27 4 41 43 35 51 23 19 40 9 11 7 39 17 44 38 33 22 18 6 5 50 13 30 34 16 24 47 2 20 29 42 
45 10 4 8 49 3 1 29 22 37 52 48 23 51 25 26 18 7 50 13 31 14 28 21 34 35 11 42 30 38 12 2 5 39 17 46 41 16 32 9 19 24 27 36 33 15 6 40 20 43 44 47 
37 13 14 51 50 22 10 44 16 23 48 29 11 35 45 25 32 2 24 27 4 26 52 3 33 34 12 47 36 46 8 20 19 5 39 7 28 15 49 38 42 6 31 18 41 1 9 30 43 21 17 40 

*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void print(vector<int>v)
{
    for(int i : v)
        cout<<i<<' ';
    cout<<endl;
}
void initialize(vector<int>&v)
{
    for(int i = 1; i <= 52; i++)
        v.push_back(i);
}
void suffle(vector<int>&card)
{
    srand(time(0));
    
    for(int i = 0; i < 52; i++)
    {
        //remaining position
        int j = i + rand() % (52-i);
        swap(card[i], card[j]);
    }
}
int main()
{
    vector<int>card;
    initialize(card);
    for(int i = 0; i< 10; i++)
    {
        suffle(card);
        print(card);
    }
    return 0;
}