// Scratch Code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


//not knowing input validation for the correct input type on the above problem or our other projects/assignments was bothering me
//so I spent way too long on this
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <fstream>

using namespace std;

double getAge();

char getSent();

int main()
{
    double value = 0, temp, average;
    ifstream inputFile;
    inputFile.open("values.txt");
    for (int x = 0; x < 10; x++)
    {
        inputFile >> temp;
        value += temp;
    }
    average = value / 10;
    cout << "The average is " << average;

    inputFile.close();
}


double getAge()
{
    double age;

    cout << "\nEnter their age: ";
    //checks for error caused by incorrect type and flips that to a positive for the condition + checks age
    while (!(cin >> age) || age <= 0)
    {
        cout << "\nInvalid. Input an age greater than 0: ";
        //clears error flags so cin can get back to work
        cin.clear();
        //rather than putting in a number, this clears out the stream to its size limit or until it hits '\n'
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return age;
}

char getSent()
{
    //get rid of any lingering \n
    cin.ignore();
    char ch = cin.get();
    //since cin.get() grabs one char at a time I have to clear the buffer in case of multiple entries
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    while (ch != 'y' && ch != 'n')
    {
        cout << "Invalid. Do you wish to continue? (y/n) ";
        ch = cin.get();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return ch;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

