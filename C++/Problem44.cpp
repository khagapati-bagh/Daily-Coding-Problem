/*
Daily Coding Problem: Problem #44 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

We can determine how "out of order" an array A is by counting the number of inversions it has. 
Two elements A[i] and A[j] form an inversion if A[i] > A[j] but i < j. That is, a smaller element appears after a larger element.

Given an array, count the number of inversions it has. Do this faster than O(N^2) time.

You may assume each element in the array is distinct.

For example, a sorted list has zero inversions. The array [2, 4, 1, 3, 5] has three inversions: (2, 1), (4, 1), and (4, 3). 
The array [5, 4, 3, 2, 1] has ten inversions: every distinct pair forms an inversion.
Example
input
2
5
2 4 1 3 5
10
1 2 3 1 0 2 10 5 3 6

output
Inversion count is 3
Inversion count is 11

*/

//You can get my code in IDE https://ide.geeksforgeeks.org/FSZ7GyHg6R
//This code will take O(nlogn) Time and O(n) Space Complexity
#include <stdio.h>
#include<bits/stdc++.h>
using namespace std;
// Merge two sorted subarrays arr[low .. mid] and arr[mid + 1 .. high]
int Merge(int arr[], int aux[], int low, int mid, int high)
{
	int k = low, i = low, j = mid + 1;
	int inversionCount = 0;
	
	// While there are elements in the left and right runs
	while (i <= mid && j <= high) 
	{
	    //cout<<"("<<aux[k]<<", "<<arr[j]<<") ";
		if (arr[i] <= arr[j]) {
			aux[k++] = arr[i++];
		}
		else {
		    //if(aux[k] > arr[j])
		 
			aux[k++] = arr[j++];
			inversionCount += (mid - i + 1);	// NOTE
		}
			
	}

	// Copy remaining elements
	while (i <= mid)
	{	
	    //if(aux[k] > arr[i])
	    //cout<<"("<<aux[k]<<", "<<arr[i]<<
	    aux[k++] = arr[i++];
	}

	// Don't need to copy second half

	// copy back to the original array to reflect sorted order
	for (int i = low; i <= high; i++)
	{
	   /* if(arr[i] != aux[i])
	        cout<<"("<<arr[i]<<","<<aux[i]<<") ";*/
	    arr[i] = aux[i];
	    
	}
		
	return inversionCount;
}

// Sort array arr [low..high] using auxiliary array aux
int MergeSort(int arr[], int aux[], int low, int high)
{
	// Base case
	if (high == low)	// if run size == 1
		return 0;

	// find mid point
	int mid = (low + ((high - low) >> 1));
	int inversionCount = 0;
	
	// recursively split runs into two halves until run size == 1,
	// then merge them and return back up the call chain

	// split / merge left  half
	inversionCount += MergeSort(arr, aux, low, mid);

	// split / merge right half
	inversionCount += MergeSort(arr, aux, mid + 1, high);

	// merge the two half runs
	inversionCount += Merge(arr, aux, low, mid, high);

	return inversionCount;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n], aux[n];
	    for(int i = 0; i < n; i++)
	        cin>>arr[i];
	    for (int i = 0; i < n; i++)
		aux[i] = arr[i];

	// get inversion count by performing merge sort on arr
	    printf("Inversion count is %d\n", MergeSort(arr, aux, 0, n - 1));   
	}

	return 0;
}