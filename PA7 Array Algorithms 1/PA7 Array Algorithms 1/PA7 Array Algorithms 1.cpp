/*
John Hester
CISP 1010 - W02
Programming Assignment 7-1
12/1/2024
Description: Read ins 25 int values from PA7.txt & use linear search array to find value provided by user. Provide found or not found response.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

int getInput();
int linearSearch(int[], int, int);
void output(int);

int main()
{
    ifstream inputFile;
    string fileName = "PA7.txt";
    inputFile.open(fileName);

    if (inputFile)
    {   
        //input file is 25 long; global     
        const int SIZE = 25;
        int nums[SIZE];
        // variable declarations  
        //vector<int> nums;
        int item, userInput, position, index = 0;
        //read in input from file
        while (inputFile.good())
        {
            inputFile >> nums[index];
            index++;
        }
        
        //get input from user;
        userInput = getInput();
        
        //search nums vector for value
        position = linearSearch(nums, userInput, SIZE);

        //output to user
        output(position);
    }
    else
    {
        cout << "\nFile error. Check input file location.\n";
    }

    inputFile.close();
}

//grab and validate input
int getInput()
{
    int searchVal = -1;
    cout << "\nPlease enter an integer to search for: ";
    //check for integer input
    while (!(cin >> searchVal))
    {
        //clear input buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInvalid. Please enter an integer to search for: ";
    }

    return searchVal;
}

//implement linear search
int linearSearch(int nums[], int userInput, int size)
{
    //set up variables
    bool found = false;
    int position = -1;
    int index = 0;
    //iterate till we either find it or reach the end
    while (index < size && !found)
    {
        //did we find it?
        if (nums[index] == userInput)
        {
            //we found it!
            found = true;
            position = index;
        }
        //iterate index
        index++;
    }

    return position;
}

void output(int position)
{
    if (position == -1)
        cout << "\n\nNum not found.\n";
    else
        cout << "\n\nNum found.\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

