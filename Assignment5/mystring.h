#pragma once
#include <iostream>
/*
Sangeet Satpathy
CS2B 
MyString.h

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
	class MyString {
	public:
		MyString(const char* input);
		MyString();
		int length() const;
		friend std::ostream& operator<<(std::ostream& out, const MyString& s);
		friend std::istream& operator>>(std::istream& in, MyString& s);
		const char& operator[](int i) const;
		char& operator[](int i);
		friend bool operator<(const MyString& lhs, const MyString& rhs);
		friend bool operator<=(const MyString& lhs, const MyString& rhs);
		friend bool operator>(const MyString& lhs, const MyString& rhs);
		friend bool operator>=(const MyString& lhs, const MyString& rhs);
		friend bool operator==(const MyString& lhs, const MyString& rhs);
		friend bool operator!=(const MyString& lhs, const MyString& rhs);
		friend MyString operator+(const MyString& lhs, const MyString& rhs);

		MyString& operator+=(const MyString& rhs);

		void read(std::istream& in, const char delimitingChar);
		~MyString();
		MyString(const MyString& otherObj);
		MyString& operator=(const MyString& otherStr);
		

		static const int MAX_INPUT_SIZE = 127;
	private:
		char* str;
	};

}