/*
Daily Coding Problem: Problem #55 [Easy]

Good morning! Here's your coding interview problem for today.

This problem was asked by Microsoft.

Implement a URL shortener with the following methods:

shorten(url), which shortens the url into a six-character alphanumeric string, such as zLg6wl.
restore(short), which expands the shortened string into the original url. If no such shortened string exists, return null.
Hint: What if we enter the same URL twice?
Example
input
6
0
5151
12345
250
1111
145

output

0
bvf
5151
dnh
12345
ec
250
r5
1111
cv
145

*/
//Problem in GFG https://practice.geeksforgeeks.org/problems/design-a-tiny-url-or-url-shortener/0
//You can get  my code in IDE https://ide.geeksforgeeks.org/6lZUlY8XVV
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class URL{
public:
    string Shorten_Url(long n)//number to url
    {
        string s="";
        int x, rem, base, Case, y;
        while(n)
        {
            rem = n%62;
            n=n/62;
            get_case(rem, &base, &Case);
            y = Case + (rem - base);
            char ch = y;
            s= ch+s;
        }
        return s;
    }
    
    long get_number(string s)//url to number
    {
        int i = s.size() - 1, n, base, Case;
        long res = 0, o_base = 1;
        
        while(i >= 0)
        {
            int x = s[i--];
            get_case_char(x, &base, &Case);
            n = x + base - Case;
            res = n * o_base + res;
            o_base *=62;
            //cout<<s[i+1]<<" "<<x<<" Base : "<<base<<" Case : "<<Case<<" n : "<<n<<" Res : "<<res<<" o_base "<<o_base<<endl;
        }
        return res;
    }
    void get_case_char(int x, int *b, int *c) // char to int
    {
        if(x > 96)
            *b = 0, *c = 97;
        else if(x > 64)
            *b = 26, *c = 65;
        else
            *b = 52, *c = 48;
    }
    
    void get_case(int n, int *b, int *c)//int to char 
    {
        if(n < 26)
            *b = 0, *c = 97;
        else if(n <52)
            *b = 26, *c = 65;
        else
            *b = 52, *c = 48;
    }
};
int main() {
    int t;
    cin>>t;
    while(t--)
    {
        long n;
        cin>>n;
        URL *obj = new URL();//Creating Objects
        string url = obj->Shorten_Url(n);//call for url
        cout<<url<<endl;
        n = obj->get_number(url);//restor the url
        cout<<n<<endl;
    }
    return 0;
}