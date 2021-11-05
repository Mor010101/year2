#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
	string upTxt;
	
	cout << "\nPlease Enter the String to Convert into Lowercase  =  ";
	getline(cin, upTxt);
	
	std:: transform(upTxt.begin(), upTxt.end(), upTxt.begin(), ::tolower);
  	
	cout<< "\nThe Given String in Lowercase = " << upTxt;
		
 	return 0;
}