#include <iostream>
#include <cstring>
using namespace std;


/*
Finds the index of the last occurrence of a character in a string.
inString - the cString to be examined
target - the character we are looking for
*/
int lastIndexOf(const char* inString, char target) {
	int i = 0;
	int lastTarget = -1;
	while (inString[i] != '\0') {
		if (inString[i] == target) {
			lastTarget = i;
		}
		i++;
	}

	return lastTarget;
}


/*
Reverses the c-string without creating a new array.
inString: the string to be examined.
*/
void reverse(char* inString) {
	int arrLength = strlen(inString);
	int halfSize = arrLength / 2;
	for (int i = 0; i < halfSize; i++) {
		int temp = inString[i];
		inString[i] = inString[arrLength - i - 1];
		inString[arrLength - i - 1] = temp;
	}
}


/*
Replaces all occurrences of a target character in a c-string with a replacement character.
inString: the string to be examined.
target: the character we are looking for.
replacementChar: the character we are using as the replacement.
*/
int replace(char* inString, char target, char replacementChar) {
	int count = 0;
	int i = 0;
	while (inString[i] != '\0') {
		if (inString[i] == target) {
			inString[i] = replacementChar;
			count++;
		}
		i++;
	}
	return count;
}

/*
Returns whether or not the c-string is a palindrome. This is not case sensitive.
inString - the string to be examined.
*/
bool isPalindrome(const char* inString) {
	int arrLength = strlen(inString);
	int halfSize = arrLength / 2;
	for (int i = 0; i < halfSize; i++) {
		if (tolower(inString[i]) != tolower(inString[arrLength - 1 - i])) {
			return false;
		}
	}
	return true;
}

/*
Converts all alphabetical indeces of the c-string to uppercase.
inString - the string to be examined
*/
void toupper(char* inString) {
	int i = 0;
	while (inString[i] != '\0') {
		inString[i] = toupper(inString[i]);
		i++;
	}
}

/*
Returns the number of alphabetical characters in a c-string.
inString - the string to be examined.
*/
int numLetters(const char* inString) {
	int count = 0;
	int i = 0;
	while (inString[i] != '\0') {
		if (isalpha(inString[i])) {
			count++;
		}
		i++;
	}
	return count;
}

int main() {
	//lastIndexOf testing
	char str1[] = "Hello World";
		char str2[] = "C++ is fun!";
	cout << lastIndexOf(str1, 'l') << endl; // should return 9
	cout << lastIndexOf(str2, 'l') << endl; //should return -1

	//reverse testing
	char str3[] = "Sangeet";
	reverse(str3);
	int i = 0;
	while (str3[i] != '\0') { //should print "teegnaS"
		cout << str3[i];
		i++;
	}
	cout << endl;

	//replace testing
	char str4[] = "Statistics";
	cout << replace(str4, 't', 'n') << endl; // should output 3
	int k = 0;
	while (str4[k] != '\0') {
		cout << str4[k]; // should output modified string, "Snanisnics"
		k++;
	}
	cout << endl;

	char str5[] = "Swimming";
	cout << replace(str5, 't', 'n') << endl; // should output 0

	int j = 0;
	while (str5[j] != '\0') {
		cout << str5[j]; // should output same string, "Swimming"
		j++;
	}
	cout << endl;


	//testing palindrome
	char str6[] = "abc ba";
	cout << isPalindrome(str6) << endl; // should be false (0)

	char str7[] = "aBbA";
	cout << isPalindrome(str7) << endl; // should be true (1)

	char str8[] = "";
	cout << isPalindrome(str8) << endl; // should be true (1)


	//testing toupper
	char str9[] = "cRaTeR laKE";
	toupper(str9);

	int l = 0;
	while (str9[l] != '\0') {
		cout << str9[l]; // should output modified string, "CRATER LAKE"
		l++;
	}
	cout << endl;


	//testing numLetters
	char str10[] = "eWir20132jfE";
	cout << numLetters(str10) << endl; // should output 7

	return 0;
}