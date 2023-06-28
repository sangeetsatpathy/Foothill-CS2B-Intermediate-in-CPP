#include <iostream>
#include <vector>
using namespace std;

const int MAX_NAME_SIZE = 24;

struct Highscore {
    char name[MAX_NAME_SIZE];
    int score;
};

void getVectorSize(int& size);

void readData(vector<Highscore>& scores);

void sortData(vector<Highscore>& scores);


vector<Highscore>::iterator findLocationOfLargest(
    const vector<Highscore>::iterator startingLocation,
    const vector<Highscore>::iterator endingLocation);


void displayData(const vector<Highscore>& scores);


int main()
{

    
    int size;

    getVectorSize(size);

    vector<Highscore> highScores(size);

    readData(highScores);
    sortData(highScores);
    displayData(highScores);

    highScores.clear();
}





void getVectorSize(int& size) {
    cout << "How many scores will you enter?: ";
    cin >> size;
    cin.ignore();
}





void readData(vector<Highscore>& scores)
{
    int scoreNum = 1;
    for (vector<Highscore>::iterator i = scores.begin(); i != scores.end(); i++)
    {
        cout << "Enter the name for score #" << scoreNum << ": ";
        cin.getline((*i).name, MAX_NAME_SIZE, '\n');

        cout << "Enter the score for score #" << scoreNum << ": ";
        cin >> (*i).score;
        cin.ignore();
        scoreNum++;
    }
}





void sortData(vector<Highscore>& scores) {
    for (vector<Highscore>::iterator i = scores.begin(); i != scores.end(); i++) {
        vector<Highscore>::iterator locOfLargest = findLocationOfLargest(i, scores.end());
        swap(locOfLargest->name, i->name);
        swap(locOfLargest->score, i->score);
    }
}





vector<Highscore>::iterator findLocationOfLargest(const vector<Highscore>::iterator startingLocation, const vector<Highscore>::iterator endingLocation) {
    vector<Highscore>::iterator indexOfLargest = startingLocation;
    for (vector<Highscore>::iterator i = startingLocation + 1; i != endingLocation; i++) {
        if ((*i).score > (*indexOfLargest).score) {
            indexOfLargest = i;
        }
    }
    return indexOfLargest;
}










void displayData(const vector<Highscore>& scores)
{
    cout << "Top Scorers: " << endl;
    for (vector<Highscore>::const_iterator i = scores.begin(); i != scores.end(); i++) {
        cout << (*i).name << ": " << (*i).score << endl;
    }
}

