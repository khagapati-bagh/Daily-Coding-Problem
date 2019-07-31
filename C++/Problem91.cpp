/*
Daily Coding Problem: Problem #91 [Easy]

Good morning! Here's your coding interview problem for today.

This problem was asked by Dropbox.

What does the below code snippet print out? How can we fix the anonymous functions to behave as we'd expect?

functions = []
for i in range(10):
    functions.append(lambda : i)

for f in functions:
    print(f())

Example
output
0 1 2 3 4 5 6 7 8 9 

*/

//You can get my code in IDE https://ide.geeksforgeeks.org/4ydVEdSu7D
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
std::vector<int>functions ;
void helper()
{
    for(int i = 0; i < 10; i++)
        functions.push_back(i);
}
int main() {
	helper();
	for(int i : functions)
	    cout<<i<<" ";
	cout<<endl;
	return 0;
}