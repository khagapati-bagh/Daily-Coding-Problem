/*
Daily Coding Problem: Problem #28 [Medium]
Good morning! Here's your coding interview problem for today.

This problem was asked by Palantir.

Write an algorithm to justify text. Given a sequence of words and an integer line length k, return a list of strings which represents each line, fully justified.

More specifically, you should have as many words as possible in each line. There should be at least one space between each word. Pad extra spaces when necessary so that each line has exactly length k. Spaces should be distributed as equally as possible, with the extra spaces, if any, distributed starting from the left.

If you can only fit one word on a line, then you should pad the right-hand side with spaces.

Each word is guaranteed not to be longer than k.

For example, given the list of words ["the", "quick", "brown", "fox", "jumps", "over", "the", "lazy", "dog"] and k = 16, you should return the following:

["the  quick brown", # 1 extra space on the left
"fox  jumps  over", # 2 extra spaces distributed evenly
"the   lazy   dog"] # 4 extra spaces distributed evenly

Example
input

7 16
This
is
an
example
of
text
justification

output

The given string : This is an example of text justification 
This    is    an
example  of text
justification   

*/
//You can get my code in IDE https://ide.geeksforgeeks.org/a0jW8SjeQw
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void print(vector<string>s, int flag)
{
    for(auto a : s)
    {
        cout<<a;
        if(flag)
            cout<<" ";
        else
            cout<<endl;
    }
    cout<<endl;
}

vector<string> fullJustify(vector<string>& words, int maxWidth) {
        if(words.size() == 0)
            return words;
        vector<string>res;//result
        for(int i = 0, k,len; i < words.size(); i +=k)
        {//k = no. of words from i 
            for(k = len = 0; i + k < words.size() && len + words[i+k].size() <= maxWidth - k; k++)
                len += words[i+k].size(); // sum of words size which are <= maxWidth
            
            string str = words[i];//first word
            for(int j = 0; j < k-1; j++)//adding space from i to i+k-1
            {
                if(i+k >= words.size())
                    str += " ";
                else //making space of size = remaing len / no. of words + if remainder is there then (+1)
                    str += string((maxWidth - len)/ (k -1) + (j < (maxWidth - len) % (k - 1)),' ');
                str += words[i+j+1]; // next word
            }
            str += string(maxWidth - str.size(), ' ');//padding to right
            res.push_back(str);//push into vector
        }
        return res;
        
}

int main() {
	int n,i,k;
	cin>>n>>k;//size of words and length of line
	string s;
	vector<string>word ;
	for(i = 0; i < n; i++)
	{
	    cin>>s;
	    word.push_back(s);
	}
	cout<<"The given string : ";
	print(word, 1);
	word = fullJustify(word, k);
	print(word, 0);
	return 0;
}