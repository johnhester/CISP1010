/*
John Hester
CISP 1010-W02
In-Class Activity 7 - Array
11/16/2024
*/

#include <iostream>
#include <fstream>

using namespace std;

void getValues(ifstream &inputFile, int[], int);
int highValue(int[], int);
int lowValue(int[], int);
int sumArray(int[], int);
void progOutput(int, int, int, double);

int main()
{
    // set up array
    const int size = 10;
    int numArr[size];
    //file set up
    ifstream inputFile;
    const string fileName = "Numbers.txt";
    inputFile.open(fileName);
    //other values;
    int highVal, lowVal;
    double avg, total;

    if (inputFile)
    {
        //function for grabbing file data
        getValues(inputFile, numArr, size);
        //find the values
        highVal = highValue(numArr, size);
        lowVal = lowValue(numArr, size);
        total = sumArray(numArr, size);
        avg = total / size;

        //print output
        progOutput(highVal, lowVal, total, avg);
    }
    else
    {
        cout << endl << "File error" << endl;
    }

    inputFile.close();

}

//fstreams have to be passed by reference
void getValues(ifstream &inputFile, int numArr[], int size)
{
    //iterate through file
    for (int i = 0; i < size; i++)
    {
        int tempNum;
        //grab the line and load it into the array
        inputFile >> numArr[i];

    }
}

//get highValue
int highValue(int numArr[], int size)
{
    int highVal = numArr[0];
    for (int i = 1; i < size; i++)
    {
        if (numArr[i] > highVal)
            highVal = numArr[i];
    }

    return highVal;
}

//get low value
int lowValue(int numArr[], int size)
{
    int lowVal = numArr[0];
    for (int i = 1; i < size; i++)
    {
        if (numArr[i] < lowVal)
        {
            lowVal = numArr[i];
        }
    }

    return lowVal;
}
//sum array
int sumArray(int numArr[], int size)
{
    int total = 0;
    for (int i = 0; i < size; i++)
    {
        total += numArr[i];
    }

    return total;
}
//prints output
void progOutput(int highVal, int lowVal, int total, double avg)
{
    cout << endl;
    cout << "The highest value is: " << highVal << endl;
    cout << "The lowest value is: " << lowVal << endl;
    cout << "The total is: " << total << endl;
    cout << "The average is: " << avg << endl;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

