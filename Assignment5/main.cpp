/*
CS2B
Assignment 8P
Sangeet Satpathy

isAPalindrome takes in a string and determines whether the string is a palindrome or not,
ignoring any whitespace and punctuation. It does this recursively.
*/
#include "mystring.h"
#include <iostream>
#include <cstring>
using namespace cs_mystring;

bool isAPalindrome(MyString mystr, int lowerBound, int upperBound);

int main() {
	char readString[120];
	std::cout << "Enter a string: ";
	std::cin.getline(readString, 120);
	while (strcmp(readString, "quit") != 0) {
		if (isAPalindrome(MyString(readString), 0, strlen(readString)-1)) {
			std::cout << readString << " is a palindrome." << std::endl;
		}
		else {
			std::cout << readString << " is not a palindrome." << std::endl;
		}
		std::cout << "Enter a string: ";
		std::cin.getline(readString, 120);;
	}

}


bool isAPalindrome(MyString mystr, int lowerBound, int upperBound) {
	int lb = lowerBound;
	int ub = upperBound;
	while (isspace(mystr[lb]) || ispunct(mystr[lb])) {
		lb++;
	}
	while (isspace(mystr[ub]) || ispunct(mystr[ub])) {
		ub--;
	}

	if (lb >= ub) {
		return true;
	}

	if (toupper(mystr[lb]) != toupper(mystr[ub])) {
		return false;
	}
	return isAPalindrome(mystr, lb + 1, ub - 1);
}