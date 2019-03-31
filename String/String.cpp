#include"String.h"

ostream &operator<<(ostream &os, String &s)
{
	os << s.str_ptr;
	return os;
}

void quit()  // write error message and quit
{
	cerr << "Memory exhausted" << endl;
	exit(1);
}

char *renew(char *ptr, int size)
{
	char *tmp = new(nothrow) char[size];
	if (tmp) {
		strcpy_s(tmp, strlen(ptr) + 1, ptr);
		delete[] ptr;
		ptr = nullptr;

		return tmp;
	}
	else
		return nullptr;
}

istream &operator>>(istream &is, String &s)
{
	int  buffer_size = 20;
	char *tmp = new char[buffer_size];

	int i = 0;
	while (true) {
		char c = getchar();
		if(isspace(c)){
			tmp[i] = 0;
			break;
		}

		tmp[i] = c;
		if (i == buffer_size - 1) {  // buffer full
			buffer_size += buffer_size;
			//tmp = (char*)realloc(tmp, buffer_size); // get a new and larger buffer
			tmp = renew(tmp, buffer_size);
			if (tmp == 0) 
				quit();
		}
		i++;
	}

	s.str_size = strlen(tmp);
	if (s.str_ptr) {
		delete[] s.str_ptr;
		s.str_ptr = nullptr;
	}
	s.str_ptr = new char[s.str_size + 1];
	strcpy_s(s.str_ptr, s.str_size + 1, tmp);
	
	return is;
}

char* String::operator+(char *ptr)
{
	if (tmp) {
		delete[] tmp;
		tmp = nullptr;
	}

	tmp = new char[str_size + strlen(ptr) + 1];
	strcpy_s(tmp, str_size + 1, str_ptr);
	strcat_s(&tmp[strlen(tmp)], strlen(ptr) + 1, ptr);
	return tmp;
}

char* String::operator+(String &s)
{
	if (tmp){
		delete[] tmp;
		tmp = nullptr;
	}

	tmp = new char[str_size + s.str_size + 1];
	strcpy_s(tmp, str_size + 1, str_ptr);
	strcat_s(&tmp[strlen(tmp)], s.str_size + 1, s.str_ptr);
	return tmp;
}

char *String::operator=(char *ptr)
{
	if (str_ptr) {
		delete[] str_ptr;
		str_ptr = nullptr;
	}

	str_size = strlen(ptr);
	str_ptr = new char[str_size + 1];
	strcpy_s(str_ptr, str_size + 1, ptr);

	return str_ptr;
}

char *String::operator=(String &s)
{
	if (str_ptr) {
		delete[] str_ptr;
		str_ptr = nullptr;
	}

	str_size = s.str_size;
	str_ptr = new char[str_size + 1];
	strcpy_s(str_ptr, str_size + 1, s.str_ptr);

	return str_ptr;
}

String::String()
{
	str_ptr = nullptr;
	str_size = 0;
}

String::String(char *ptr)
{
	if (str_ptr) {
		delete[] str_ptr;
		str_ptr = nullptr;
	}

	str_size = strlen(ptr);
	str_ptr = new char[str_size + 1];
	strcpy_s(str_ptr, str_size + 1, ptr);
}

String::String(String &s)
{
	if (str_ptr) {
		delete[] str_ptr;
		str_ptr = nullptr;
	}

	str_size = s.str_size;
	str_ptr = new char[str_size + 1];
	strcpy_s(str_ptr, str_size + 1, s.str_ptr);
}

char *String::toupper()
{
	if (tmp) {
		delete[] tmp;
		tmp = nullptr;
	}

	tmp = new char[str_size + 1];
	strcpy_s(tmp, str_size + 1, str_ptr);
	for (int i = 0; i < str_size; i++)
	{
		if ((int)tmp[i] >= 97 && (int)tmp[i] <= 123)
			tmp[i] = tmp[i] - 32;
	}
	return tmp;
}

char *String::tolower()
{
	if (tmp) {
		delete[] tmp;
		tmp = nullptr;
	}

	tmp = new char[str_size + 1];
	strcpy_s(tmp, str_size + 1, str_ptr);
	for (int i = 0; i < str_size; i++)
	{
		if ((int)tmp[i] >= 65 && (int)tmp[i] <= 91)
			tmp[i] = tmp[i] + 32;
	}
	return tmp;
}

int String::size()
{
	return this->str_size;
}

int String::length()
{
	return this->str_size;
}

String::~String()
{
	if (str_ptr != nullptr)
		delete[] str_ptr;

	if (tmp != nullptr)
		delete[] tmp;

}
