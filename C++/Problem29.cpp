/*
Daily Coding Problem: Problem #29 [Easy]

Good morning! Here's your coding interview problem for today.

This problem was asked by Amazon.

Run-length encoding is a fast and simple method of encoding strings. The basic idea is to represent repeated successive 
characters as a single count and character. For example, the string "AAAABBBCCDAA" would be encoded as "4A3B2C1D2A".

Implement run-length encoding and decoding. You can assume the string to be encoded have no digits and consists solely of 
alphabetic characters. You can assume the string to be decoded is valid.

Example
input
4
AAAABBBCCDAA
abcdefgh
aaaabbbccc
abbbcdddd

output
Input string is : AAAABBBCCDAA
Encoded to : 4A3B2C1D2A
Decoded : AAAABBBCCDAA
Input string is : abcdefgh
Encoded to : 1a1b1c1d1e1f1g1h
Decoded : abcdefgh
Input string is : aaaabbbccc
Encoded to : 4a3b3c
Decoded : aaaabbbccc
Input string is : abbbcdddd
Encoded to : 1a3b1c4d
Decoded : abbbcdddd

*/

// You can get my code in IDE https://ide.geeksforgeeks.org/U4rxCNtxdz
// This code will take O(n) Time and Space complexity
#include <bits/stdc++.h>
using namespace std;
char *encode(char *src);
char *decode(char *src);
 
int main() {
    
    int T;
    cin>>T;
    while(T--)
    {
        char *str1, *str2, str[10000];
        cin>>str;
        str1 = encode(str);
        cout<<"Input string is : "<<str<<endl;
        cout<<"Encoded to : "<<str1<<endl;
        str2 = decode(str1);
        cout<<"Decoded : "<<str2<<endl;
    }
    return 0;
}

/*This is a function problem.You only need to complete the function given below*/
/*You are required to complete this function */

#define M 10
char * decode(char * src){
    int len = strlen(src);
    char *res =(char *)malloc(sizeof(char) * (10000));
    int i,j=0;
    for(i = 0; i < len; i++)
    {
        int rLen = src[i]-'0';
        i++;
        while(i < len && src[i]<='9' && src[i] >= '0')
        {
            rLen= rLen*10 + (src[i]-'0');
            i++;
        }
        for(int k = 0; k < rLen; k++)
        {
            res[j++]=src[i];
        }
    }
    res[j] = '\0';
    return res;
}
char *encode(char *src)
{     
  //Your code here 
   char count[M];// when length > 9
   int len = strlen(src);
   char *res =(char *)malloc(sizeof(char) * (len * 2 + 1));//result when every char occurs once
   int i,j=0, rLen;
   for(i = 0; i < len; i++)
   {
       
       rLen = 1;
       while(i+1 < len && src[i] == src[i+1])
       {
           rLen++; // rlength
           i++;
       }
       
       sprintf(count, "%d", rLen);//store in char 
       
       for(int k = 0; *(count+k); k++,j++)
            res[j] = count[k];//stores the length
        res[j++] = src[i];
   }
   res[j] = '\0';
   return res;
}    

