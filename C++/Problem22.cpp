/*
Daily Coding Problem: Problem #22 [Medium]

Good morning! Here's your coding interview problem for today.

This problem was asked by Microsoft.

Given a dictionary of words and a string made up of those words (no spaces), 
return the original sentence in a list. If there is more than one possible reconstruction, 
return any of them. If there is no possible reconstruction, then return null.

For example, given the set of words 'quick', 'brown', 'the', 'fox', and the string "thequickbrownfox", 
you should return ['the', 'quick', 'brown', 'fox'].

Given the set of words 'bed', 'bath', 'bedbath', 'and', 'beyond', and the string "bedbathandbeyond", 
return either ['bed', 'bath', 'and', 'beyond] or ['bedbath', 'and', 'beyond'].

This will take O(N*S) Time and O(N) Space Complexity. Where N = s.length(), S= largest string length from dictionary

Example 
input
2
4
quick
brown
the
fox
thequickbrownfox1
5
bed
bath
bedbath
and
beyond
bedbathandbeyond

output
null
bed bath and beyond 

*/
//You can get my code in IDE https://ide.geeksforgeeks.org/7tnbcoZEri
#include <bits/stdc++.h>
using namespace std;
/*//Brute force solution but it will not pass all test case it will show Time Limit Exceed
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        if(s.size() == 0) 
            return true;
        unordered_map<string, bool>mp;
        for(string a : wordDict)
            mp[a] = true;
        if(compare_char(s,mp))
            return true;
        return false;
    }
private:
    bool compare_char(string s, unordered_map<string, bool>mp){
        int sz = s.size();
        if(sz == 0)
            return true;
        for(int i = 1; i <= sz; i++)
        {
            if(mp.find(s.substr(0,i)) != mp.end() && compare_char(s.substr(i, sz-i), mp))
                return true;
        }
        return false;
    }
};*/

//DP solution O(n*s) n= string length and s = largest string length from dict
class Solution {
public:
    void wordBreak(string s, vector<string>& wordDict) {
        /*if(s.size() == 0) 
            return true;*/
        unordered_map<string, bool>mp;
        int maxlen = 0;
        for(string a : wordDict)
        {
            mp[a] = true;
            maxlen = max(maxlen, (int)a.length());
        }
        vector<string> res;
        res = compare_char(s, mp, maxlen);
        if(res.size() > 0)
	        for(string str : res)
	        	cout<<str<<' ';
        else
        	cout<<"null";
        cout<<endl;
    }

private:
    vector<string> compare_char(string s, unordered_map<string, bool>mp, int maxlen){
        int sz = s.size();
        vector<string>res;
        if(sz == 0)
            return res;
 
        bool word[sz+1] = {false};//DP table to store result of subproblem
        word[0] = true; // first char true
        for(int i = 1; i <= sz; i++)
        {
            for(int j = i-1; j >= 0 && i - j <= maxlen; j--)
            {
                if(word[j])
                {
                    string str = s.substr(j, i-j);//Upto i
                    if(mp.find(str) != mp.end())
                    {    
                        word[i] = true; //upto i true;
                        res.push_back(str);
                        break; //next i
                    }
                    
                }
            }
        }
        if(word[sz])
        	return res;
        else {//if string not possible
            res.clear();
            return res;
        }
    }
};
/*
private: //This solution is also correct you can uncomment and check but comment the above code
    vector<string> compare_char(string s, unordered_map<string, bool>mp){
        int sz = s.size();
        vector<string>res;
        if(sz == 0)
            return res;
        bool word[sz+1] = {false};//DP table to store result of subproblem
        
        for(int i = 1; i <= sz; i++)
        {
            if(word[i] == false && mp.find(s.substr(0,i)) != mp.end())//if word[i] = false
            {
                string str = s.substr(0,i);
                res.push_back(str);
                word[i] = true;
            }
               
            if(word[i] == true)
            {
                if(i == sz)
                    return res;
                for(int j = i+1; j <= sz; j++) // check for the suffix
                {
                    string str = s.substr(i, j-i);
                    if(word[j] == false && mp.find(str) != mp.end())   
                    {
                        word[j] = true;
                        res.push_back(str);
                    }
                    
                    if(j == sz && word[j] == true)
                        return res;
                }
            }
        }
        vector<string>tmp;
        return tmp;
    }
};
*/
int main()
{
	int t;
	cin>>t;//test case
	while(t--){
		int n,i;
		cin>>n;
		vector<string> dict;
		string s;
		for(i = 0; i < n; i++)
		{
			cin>>s;
			dict.push_back(s);
		}
		cin>>s;
		Solution s1;
		s1.wordBreak(s,dict);
	}
	return 0;
}