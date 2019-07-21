/*
Daily Coding Problem: Problem #82 [Easy]

Good morning! Here's your coding interview problem for today.

This problem was asked Microsoft.

Using a read7() method that returns 7 characters from a file, implement readN(n) which reads n characters.

For example, given a file with the content “Hello world”, three read7() returns “Hello w”, “orld” and then “”.

Example

Write text to be written on file < 200 char
hello world i'm back to my previous world
No. of times and No. of characters :
3 7
hello w
orld i'm
 back to
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{	char text[200];
	ofstream ofile("file.txt");//creating file
	if(ofile.is_open()){
		cout<<"Write text to be written on file < 200 char"<<endl;
		cin.getline(text, sizeof(text));//input from user
		ofile<<text<<endl;//store in file
		ofile.close();//close file
	}
	int n, m;
	cout<<"No. of times and No. of characters : ";
	cin>>n>>m;
	ifstream ifile("file.txt");//open file for reading
	if(ifile.is_open())
	{
		char c,b;
		for(int i = 0; i < n; i++)
		{
			int cnt = 0;
			if(b)
				cout<<b;
			while (ifile.get(c) && cnt < m)          // loop getting single characters
			{
				cout << c;
				cnt++;
			}
			b = c;
			cout<<endl;
		}
		ifile.close();
	}
	return 0;
} 