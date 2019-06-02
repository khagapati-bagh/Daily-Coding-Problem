/*
Daily Coding Problem: Problem #33 [Easy]
Good morning! Here's your coding interview problem for today.

This problem was asked by Microsoft.

Compute the running median of a sequence of numbers. That is, given a stream of numbers, 
print out the median of the list so far on each new element.

Recall that the median of an even-numbered list is the average of the two middle numbers.

For example, given the sequence [2, 1, 5, 7, 2, 0, 5], your algorithm should print out:

2
1.5
2
3.5
2
2
2
*/
//This code will take O(n) Time and Space Compleixty
//You can get my code in IDE https://ide.geeksforgeeks.org/QibETIVNMj
#include <bits/stdc++.h>
using namespace std;
void print(vector<double>v)
{
    for(auto a : v)
        cout<<a<<endl;
}
void runningMedian(vector<int> a) {

     vector<double>res;
     if(a.size() == 0)
        return;
     priority_queue<double>max_heap;
     priority_queue<double,vector<double>, greater<double>>min_heap;
     
     double median = 0;
    for(int i : a)
    {
        if(i <= median)
            max_heap.push(i);
        else
            min_heap.push(i);
        //when size is differ by 2
        if(max_heap.size() > min_heap.size() + 1){
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if(min_heap.size() > max_heap.size() + 1){
            max_heap.push(min_heap.top());
            min_heap.pop();
        }

        //Median calculation
        if(max_heap.size() == min_heap.size())
            median = (max_heap.top() + min_heap.top())/2.0;
        else if(max_heap.size() > min_heap.size())
            median = (double)max_heap.top();
        else
            median = (double)min_heap.top();

        res.push_back(median);
    }
    print(res);

}

int main()
{
    int n,i;
    cin>>n;
    vector<int>stream(n);
    for(i = 0; i < n; i++)
        cin>>stream[i];
    runningMedian(stream);
    return 0;
}
