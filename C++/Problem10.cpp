/*
Daily Coding Problem: Problem #10 [Medium]
Good morning! Here's your coding interview problem for today.

This problem was asked by Apple.

Implement a job scheduler which takes in a function f and an integer n, and calls f after n milliseconds.

Example: 
5000
Before : Fri May 10 05:21:30 2019
After  : Fri May 10 05:21:35 2019


*/
#include <iostream>
#include <unistd.h>
#include <ctime>
using namespace std;
void job_sedule(int n)
{
	sleep(n/1000); //Sleep takes parameter in Second 1 s = 1000 ms
}
int main()
{
	int n;
	cin>>n;
	time_t curr_time = time(NULL);
	cout << "Before : " << ctime(&curr_time); //Show current time
	job_sedule(n);
	time_t p_time = time(NULL);
	cout << "After  : " << ctime(&p_time); //current time
	return 0;
}