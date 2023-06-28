#include <cstring>
#include <iostream>
using namespace std;

/*
Sangeet Satpathy
CS2B Assignment 8 Part 1

The reverseWithinBounds function takes in an array, a lower bound, and upperbound, and only reverses
the elements within the bounds.

The reverseCString() function takes in a cstring and completely reverses it, utilizing the
reverseWithinBounds() function mentioned above.
*/


void reverseWithinBounds(char arr[], int lowerBound, int upperBound);
void reverseCString(char* cstr);

int main(){
	char myArr[] = {'A', 'B', 'C', 'd', 'g', 'H', 'P'};
	cout << "Original array: " << endl;
	for (int i = 0; i < 7; i++) {
		cout << myArr[i] << " ";
	}
	cout << endl;


	cout << "Testing Reverse within bounds" << endl;
	reverseWithinBounds(myArr, 0, 4);
	for (int i = 0; i < 7; i++) { 
		cout << myArr[i] << " ";
	}
	cout << endl;
	//array should now be g, d, C, B, A, H, P

	cout << "Testing reverseCString() with 'USA': " << endl;
	char string2[4] = "USA";
	reverseCString(string2);
	int i = 0;
	while (string2[i] != '\0') {
		cout << string2[i];
		i++;
	}
	cout << endl;
}







void reverseWithinBounds(char arr[], int lowerBound, int upperBound) {
	if (upperBound <= lowerBound) {
		return;
	}

	swap(arr[lowerBound], arr[upperBound]);
	reverseWithinBounds(arr, lowerBound + 1, upperBound - 1);
}







void reverseCString(char* cstr) {
	reverseWithinBounds(cstr, 0, strlen(cstr) - 1);
}
