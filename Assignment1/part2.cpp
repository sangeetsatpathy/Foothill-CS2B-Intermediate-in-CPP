/*
 Type your code after each of the commented instructions below (except that the statements
 for instructions 11 and 21 should be written where the instructions indicate).  I have
 written the first statement for you.
*/

#include <iostream>
using namespace std;

void readData(string names[], int scores[], int size);
void sortData(string names[], int scores[], int size);
void displayData(const string names[], const int scores[], int size);

int main() {
	int arrSize;
	cout << "How many scores will you enter?: ";
	cin >> arrSize;

	string* scorerNames = new string[arrSize];
	int* allScores = new int[arrSize];

	readData(scorerNames, allScores, arrSize);
	sortData(scorerNames, allScores, arrSize);
	displayData(scorerNames, allScores, arrSize);

} /* end of function main() */

void readData(string names[], int scores[], int size) {
	for (int i = 1; i <= size; i++) {
		cout << "Enter the name  for score #" << i << ": ";
		cin >> names[i - 1];
		cout << "Enter the score for score #" << i << ": ";
		cin >> scores[i - 1];
	}
	cout << endl;
}

void sortData(string names[], int scores[], int size) {
	for (int i = 0; i < size - 1; i++) {
		int currentMaxVal = scores[i];
		int indexOfCurrentMax = i;
		for (int k = i + 1; k < size; k++) {
			if (scores[k] > currentMaxVal)
			{
				currentMaxVal = scores[k];
				indexOfCurrentMax = k;
			}
		}
		swap(scores[i], scores[indexOfCurrentMax]);
		swap(names[i], names[indexOfCurrentMax]);
	}
}

void displayData(const string names[], const int scores[], int size) {
	cout << "Top Scorers: " << endl;
	for (int i = 0; i < size; i++) {
		cout << names[i] << ": " << scores[i] << endl;
	}
}