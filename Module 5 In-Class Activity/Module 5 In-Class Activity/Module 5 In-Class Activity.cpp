/*
John Hester
CISP 1010-W02
Module 5 In-Class Activity
10/16/2024
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;


int main()
{
    //stream object
    ifstream inputFile;
    //crack it open
    inputFile.open("Module5InClass.txt");

    double numInput, numSum = 0, totalNums = 0;
    if (inputFile)
    {
        while (inputFile >> numInput)
        {
            cout << numInput << endl;
            numSum += numInput;
            totalNums++;

        }

        cout << "\nThe average of the numbers is " << setprecision(1) << fixed << numSum / totalNums << endl;

        inputFile.close();
    }
    else
    {
        cout << "\nNo file provided.";
    }

}   

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


