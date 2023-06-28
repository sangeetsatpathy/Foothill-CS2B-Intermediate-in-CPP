#define NDEBUG
#include "mystring.h"
#include <cstring>
#include <cassert>

using namespace std;
/*
Sangeet Satpathy
CS2B
MyString.cpp

MyString is a class that represents a c-string.

int length() ->
	pre: MyString object has been defined.
	post: returns a length, object unchanged
ostream& operator<<(ostream out, const MyString& s) ->
	pre: MyString object and ostream object have defined.
	post: prints out the string
const char& operator[](int i) const ->
	pre: i is within the bounds of the array (0 <= i < arr.length)
	post: allows the caller to access char at any point of the string.
char& operator[](int i)
	pre: i is within bounds of the array (0 <= i < arr.length)
	post: allows the caller to access and MODIFY any index of the string
operator<(const MyString& lhs, const MyString& rhs)
	pre: lhs and rhs are both fully defined.
	post: returns whether lhs is smaller than rhs
operators<=, >, >=, ==, != all follow the same pre and post conditions as operator<, except the post
	returns the boolean value associated with its operator
MyString& operator=(const MyString& otherStr)
	pre: otherStr and current object both are both defined; both have a value for str[] assigned.
	post: frees the memory currently allocated for str[] and redefines str to be the same value as otherStr

~MyString():
	pre: memory for str has been allocated
	post: all memory for str has been freed, object can be successfully deleted

*/


namespace cs_mystring {
	int MyString::length() const {
		return strlen(str);
	}







	MyString::MyString(const char* input) {
		str = new char[strlen(input) + 1];
		strcpy(str, input);
	}







	MyString::MyString() {
		str = new char[1];
		strcpy(str, "");
	}







	std::ostream& operator<<(std::ostream& out, const MyString& s) {
		out << s.str;
		return out;
	}







	const char& MyString::operator[](int i) const {
		assert(i < strlen(i) && i >= 0);
		return str[i];
	}






	char& MyString::operator[](int i) {
		assert(i < strlen(str) && i >= 0);
		return str[i];
	}







	bool operator<(const MyString& lhs, const MyString& rhs) {
		if (strcmp(lhs.str, rhs.str) < 0) {
			return true;
		}
		return false;
	}






	bool operator<=(const MyString& lhs, const MyString& rhs) {
		return !(lhs > rhs);
	}






	bool operator>(const MyString& lhs, const MyString& rhs) {
		return rhs < lhs;
	}







	bool operator>=(const MyString& lhs, const MyString& rhs) {
		return !(lhs < rhs);
	}








	bool operator==(const MyString& lhs, const MyString& rhs) {
		if (lhs >= rhs && lhs <= rhs) {
			return true;
		}
		return false;
	}





	bool operator!=(const MyString& lhs, const MyString& rhs) {
		return !(lhs == rhs);
	}







	MyString::~MyString() {
		delete str;
	}







	MyString::MyString(const MyString& otherObj) {
		str = new char[strlen(otherObj.str) + 1];
		strcpy(str, otherObj.str);
	}






	MyString& MyString::operator=(const MyString& otherStr) {
		if (*this != otherStr) {
			delete[] str;
			str = new char[strlen(otherStr.str) + 1];
			strcpy(str, otherStr.str);
		}
		return *this;
	}






	std::istream& operator>>(std::istream& in, MyString& s) {
		char staticArr[MyString::MAX_INPUT_SIZE];
		in >> staticArr;
		delete[] s.str;
		s.str = new char[strlen(staticArr) + 1];
		strcpy(s.str, staticArr);
		return in;
	}






	void MyString::read(std::istream& in, const char delimitingChar) {
		char staticArr[MyString::MAX_INPUT_SIZE];
		in.getline(staticArr, delimitingChar);
		//cout << staticArr << endl; // ADDED --> The firs
		cout << endl;
		delete[] str;
		str = new char[strlen(staticArr) + 1];
		strcpy(str, staticArr);
	}





	MyString operator+(const MyString& lhs, const MyString& rhs) {
		MyString currStr;
		delete currStr.str;
		currStr.str = new char[lhs.length() + rhs.length() + 2];
		strcpy(currStr.str, lhs.str);
		strcat(currStr.str, rhs.str);
		return currStr;
	}






	MyString& MyString::operator+=(const MyString& rhs) {
		*this = *this + rhs;
		return *this;
	}

}