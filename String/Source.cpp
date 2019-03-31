#include<iostream>
#include"String.h"
#include<string>
using namespace std;

int main()
{
	string s="hello";
	cout << s << endl;
	cout << s.size() << endl;
	cout << s.length() << endl;

	String s0;
	cout << s0.size() << endl;

	String s1="abcd";
	cout << s1 << endl;
	cout << s1.size() << endl;
	cout << s1.length() << endl;

	String s2("pqrs");
	cout << s2 << endl;

	s1 = "xyz";
	cout << s1 << endl;

	s1 = s2;
	cout << s1 << endl;

	cout << s1.toupper() << endl;
	cout << s1.tolower() << endl;
	
	cin >> s1;
	cout << s1 << endl;

	system("pause");
	return 0;
}
