/*
Daily Coding Problem: Problem #15 [Medium]
Good morning! Here's your coding interview problem for today.

This problem was asked by Facebook.

Given a stream of elements too large to store in memory, pick 
a random element from the stream with uniform probability.

This Proble is the variation of Reservoir Sampling https://www.geeksforgeeks.org/reservoir-sampling/
Example: 
input :
5
1 2 3 4 5

output:
For 1 random value is 1
For 2 random value is 1
For 3 random value is 1
For 4 random value is 1
For 5 random value is 1

*/
//Here you will get the code in IDE : https://ide.geeksforgeeks.org/ZhCVfpzWee
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int Select_random(int n)
{
    static int res,cnt=0; //Res = result, cnt = no. of element visited so far
    cnt++;
    
    if(cnt == 1) //If first element of stream
        res = cnt;
    else
    {
        int x = rand() % cnt; //Generate a random no. between 0 to cnt-1
        if(x == cnt-1)
            res = n;	//replace the result value
    }
    return res;
}

int main() {
	//cout<<"GfG!";
	int n,x; // size of iostream and element
	cin>>n;
	srand(time(NULL)); //Time stamp for rand generation
	for(int i=0;i<n;i++)
	{    
	    cin>>x;
	    cout<<"For "<<x<<" random value is "<<Select_random(x)<<endl;
	}
	return 0;
}