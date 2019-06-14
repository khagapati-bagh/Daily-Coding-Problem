/*
Daily Coding Problem: Problem #45 [Easy]

Good morning! Here's your coding interview problem for today.

This problem was asked by Two Sigma.

Using a function rand5() that returns an integer from 1 to 5 (inclusive) with uniform probability, 
implement a function rand7() that returns an integer from 1 to 7 (inclusive).

Output
1 : 0.1438
2 : 0.14186
3 : 0.14327
4 : 0.14208
5 : 0.14179
6 : 0.14441
7 : 0.14279

*/
// You can get my code in IDE https://ide.geeksforgeeks.org/3fc3bswlP6
#include <bits/stdc++.h>
using namespace std;
int rand5()
{
	return rand() % 5 + 1;//random no. between (1 - 5)
}

int rand7()
{
	int n = 5 * rand5() + rand5() - 5; //Uniformly samples between 1 - 25
	if( n < 22)
		return n % 7 + 1; //random no. between (1 - 7)
	return rand7();
}
int main()
{
	int experiment = 100000;
	vector<int> freq(8,0);

	for(int i = 0; i < experiment; i++)
	{
		int num = rand7();
		freq[num]++;
		//cout<<num<<endl;
	}
	for(int i = 1; i <= 7; i++)
	{
	    double x = freq[i]/(double) experiment;
	    //cout<<(double)((int)(x * 100 + .5))/100<<endl;
		cout<<i<<" : "<<x<<endl;
	}
}