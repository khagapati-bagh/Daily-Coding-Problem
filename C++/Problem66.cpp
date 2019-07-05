/*
Daily Coding Problem: Problem #66 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Square.

Assume you have access to a function toss_biased() which returns 0 or 1 with a probability that's not 50-50 
(but also not 0-100 or 100-0). You do not know the bias of the coin.

Write a function to simulate an unbiased coin toss.

Solution
The observation is that if you have a biased coin that comes up heads with probability p, and if you flip the coin twice, 
then:

The probability that it comes up heads twice is p * p

The probability that it comes up heads first and tails second is p(1-p)

The probability that it comes up tails first ands heads second is (1-p)p

The probability that it comes up tails twice is (1-p) * (1-p)

According to Bayes' theorem,

P(first coin is heads | both coins are different) = P(both coins are different | first coin is heads) P(first coin is heads) 
													/ P(both coins are different), 
P(first coin is heads | both coins are different) = p (1-p) / (2p(1-p)) = 1 / 2.

*/
//Reference https://stackoverflow.com/a/5429219
#include <bits/stdc++.h> 
using namespace std; 

int toss_biased() // given method that returns 0 or 1
{ 
	// some code here 
} 

int toss_unbiased()
{ 
	int val1 = toss_biased(); 
	int val2 = toss_biased(); 
	if(val2 != val1)//50-50 (but also not 0-100 or 100-0)
	    return val1;
	return toss_unbiased();
} 

int main() 
{ 
	cout<<toss_unbiased()<<endl; 
	return 0; 
} 
