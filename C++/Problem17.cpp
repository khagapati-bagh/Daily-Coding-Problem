/*
Daily Coding Problem: Problem #17 [Hard]

Good morning! Here's your coding interview problem for today.

This problem was asked by Google.

Suppose we abstract our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

Suppose we abstract our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:
Note:

The name of a file contains at least a period and an extension.

The name of a directory or sub-directory will not contain a period.

My Soution will take O(n) Time complexity
Example 
output 32
*/
// Here you will get my solution in IDE link:  https://ide.geeksforgeeks.org/53RjteYFtT
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int Longest_Absolute_Path(string s)
{
    s +='\n'; // for ending string
    vector<int>tree(20,0); 
    int level=0,length=0,res = 0;
    bool isFile = false;
    
    for(char ch : s)
    {
        switch(ch)
        {
            case '\n': level = 0, length = 0, isFile = false;break; //level start from 0
            case '\t': level++; break;//next level
            case '.' : isFile = true; // we got the file
            default :
                    length++;
                    tree[level]= length;//insert same level max length
                    if(isFile)
                        res = max(res, accumulate(tree.begin(), tree.begin()+level+1, 0)+level);
        }
    }
    return res;
}
int main() {
	string s = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext";
	cout<<Longest_Absolute_Path(s)<<endl;
	return 0;
}