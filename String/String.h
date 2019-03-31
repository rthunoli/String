#pragma once
#include<iostream>
using namespace std;

class String
{
private:
	char *str_ptr;
	char *tmp;
	int str_size;

public:
	friend ostream & operator<<(ostream &, String &);
	friend istream & operator>>(istream &, String &);
	char *String::operator+(char *);
	char *String::operator+(String &);
	char *String::operator=(char *);
	char *String::operator=(String &);

	int size();
	int length();
	char *toupper();
	char *tolower();

	String();
	String(char *ptr);
	String(String &s);

	~String();
};

