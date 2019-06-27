/*
Daily Coding Problem: Problem #57 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Amazon.

Given a string s and an integer k, break up the string into multiple lines such that each line has a length of k or less. 
You must break it up so that words don't break across lines. Each line has to have the maximum possible amount of words. 
If there's no way to break the text up, then return null.

You can assume that there are no spaces at the ends of the string and that there is exactly one space between each word.

For example, given the string "the quick brown fox jumps over the lazy dog" and k = 10, you should return: 
["the quick", "brown fox", "jumps over", "the lazy", "dog"]. No string in the list has a length of more than 10.

Example
input
2
Please write comments if you find anything incorrect, or you want to share more information about the topic discussed above.
10
the quick brown fox jumps over the lazy dog amoun
9

output
NULL
the quick
brown fox
jumps
over the
lazy dog
amoun

*/

//You can get my code in IDE https://ide.geeksforgeeks.org/ZHxH4Xbvcm
//O(n) Time and Space Complexity

#include<bits/stdc++.h>
using namespace std;
void print(vector<string>s)
{
    for(auto a : s)
        cout<<a<<endl;
}
void break_string(string s, int k)
{
    vector<string>res;
    if(s.size() == 0)
    {
        cout<<"NULL"<<endl;
        return;
    }
    stringstream ss(s);
    string word, str="";
    while(ss >> word)
    {
        if(word.size() > k)//when word size is > k
        {
            cout<<"NULL"<<endl;
            return;
        }
        if(str.size() == 0)
            str = word;
        else
        {
            if(str.size() + word.size() < k)
                str = str + " " + word;
            else
            {
                res.push_back(str);
                str= word;
            }
        }
    }
    if(str.size() > 0)
        res.push_back(str);
    print(res);
}
int main()
{
    int t;
    cin>>t;
    getchar();
    while(t--)
    {
        getchar();
        string s;
        getline(cin, s); 
        int k;
        cin>>k;
        //cout<<s<<endl<<k<<endl;;
        break_string(s, k);
        
    }
    return 0;
}