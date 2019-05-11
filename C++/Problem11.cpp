/*
Good morning! Here's your coding interview problem for today.

This problem was asked by Twitter.

Implement an autocomplete system. That is, given a query string s and a set of all possible query strings, return all strings in the set that have s as a prefix.

For example, given the query string de and the set of strings [dog, deer, deal], return [deer, deal].

Example:
input:
2
wo
3
wow Wo woooo
de
8
Dam dump deep deer dear Dea de dee

output:
wow woooo 
deep deer dear de dee 
*/
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	//cout<<"GfG!";
	int t;
	cin>>t; //Test cases
	//getchar();    //if You face probelm in test case then use getchar()
	while(t--)
	{
	    string s,tmp,sub;
	    cin>>s; //Input string
	    //getchar();
	    int q,i,len;
	    cin>>q; // No. of element if set of string 
	    len = s.size();
	    std::vector<string>query;
	    for(i=0;i<q;i++)
	    {
	        cin>>tmp; //set element
	        //getchar();
	        sub = tmp.substr(0,len);
	        if(sub == s) //If they prefix equla then push
	            query.push_back(tmp);
	    }
	    for(i = 0;i < query.size(); i++) //The matched prefix string of the set element
	        cout<<query[i]<<' ';
	    cout<<endl;
	}
	return 0;
}