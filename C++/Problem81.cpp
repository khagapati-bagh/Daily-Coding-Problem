/*
Daily Coding Problem: Problem #81 [Easy]

Good morning! Here's your coding interview problem for today.

This problem was asked by Yelp.

Given a mapping of digits to letters (as in a phone number), and a digit string, return all possible letters the number could represent. You can assume each valid number in the mapping is a single digit.

For example if {“2”: [“a”, “b”, “c”], 3: [“d”, “e”, “f”], …} then “23” should return [“ad”, “ae”, “af”, “bd”, “be”, “bf”, “cd”, “ce”, “cf"].

Example
input
2
23
245

output
ad ae af bd be bf cd ce cf 
agj agk agl ahj ahk ahl aij aik ail bgj bgk bgl bhj bhk bhl bij bik bil cgj cgk cgl chj chk chl cij cik cil 

*/

// You can get my code in IDE https://ide.geeksforgeeks.org/y4QszORMkn

/*
Time complexity : O(3^N * 4^M) 
where N is the number of digits in the input that maps to 3 letters (e.g. 2, 3, 4, 5, 6, 8) and M is the number of digits in the input that maps to 4 letters (e.g. 7, 9), and N+M is the total number digits in the input.
Space complexity : O(3^N * 4^M)
*/

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//Using backtracking
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>res;
        if(digits.size() == 0)  return res;
        vector<string>letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        backtrack(digits, letters, "", res);
        return res;
    }
private:
    void backtrack(string digits, vector<string>letters, string output, vector<string>&res)
    {
        int sz = output.size();
        if(sz == digits.size())//digits size == output string size
        {
            res.push_back(output);
            return;
        }
        
        int index = digits[sz] - '0';
        string str = letters[index];
        
        for(auto c : str)
        {
            output.push_back(c);
            backtrack(digits, letters, output, res);
            output.pop_back();
        }
    }
};

/*
//Iterative Approach
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        vector<string>res;
        if(n == 0)  return res;
        vector<string> letters ={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.push_back("");
        for(int i = 0; i < n; i++)
        {
            int key = digits[i] - '0';
            if(key < 0 || key > 9) break;//key is not exist
            string str = letters[key];
            if(str.empty()) continue;//when key is 0 or 1
            
            vector<string>tmp;
            for(int j = 0; j < str.size(); j++)
            {
                for(int k = 0; k < res.size(); k++)
                    tmp.push_back(res[k] + str[j]);       
            }
            res = tmp;
        }
        sort(res.begin(), res.end());
        return res;
    }
};
*/
void print(vector<string>res)
{
    for(auto s : res)
        cout<<s<<" ";
    cout<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution obj;
        vector<string>res;
        res = obj.letterCombinations(s);
        print(res);
    }
    return 0;
}