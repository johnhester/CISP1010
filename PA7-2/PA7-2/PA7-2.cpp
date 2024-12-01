/*
John Hester
CISP 1010 - W02
Programming Assignment 7-2
12/1/2024
Description: Read ins 25 int values from PA7.txt & use binary search to find value provided by user. Provide found or not found response.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;
//function declarations
int getInput();
void output(int);
void bubbleSort(int[], int);
void swap(int&, int&);
int binarySearch(int[], int, int);

int main()
{
    ifstream inputFile;
    string fileName = "PA7.txt";
    inputFile.open(fileName);

    if (inputFile)
    {
        //input file is 25 long     
        // variable declarations 
        const int SIZE = 25;
        int nums[SIZE];
        int item, userInput, position, index = 0;
        //read in input from file
        while (inputFile.good())
        {
            inputFile >> nums[index];
            index++;
        }
        //get input from user;
        userInput = getInput();
        //must sort array before implementing binary search 
        bubbleSort(nums, SIZE);
        //use binary search to locate user value in array
        position = binarySearch(nums, SIZE, userInput);
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
    cout << "\nPlease enter an integer: ";
    //check for integer input
    while (!(cin >> searchVal))
    {
        //clear input buffer
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInvalid. Please enter an integer: ";
    }

    return searchVal;
}

//print output
void output(int position)
{
    if (position == -1)
        cout << "\n\nNum not found.\n";
    else
        cout << "\n\nNum found.\n";
}

//sort array, default is ascending order
void bubbleSort(int nums[], int size)
{
    int maxElement;
    int index;

    for (maxElement = size - 1; maxElement > 0; maxElement--)
    {
        //inner loop
        for (index = 0; index < maxElement; index++)
        {
            if (nums[index] > nums[index + 1])
            {
                swap(nums[index], nums[index + 1]);
            }
        }
    }
}

//swap array values
void swap(int &num1, int &num2)
{
    int temp = num2;
    num2 = num1;
    num1 = temp;
}

//binary search algorithm
int binarySearch(int nums[], int size, int userInput)
{
    //declare variables
    // first array element
    // last array element -1 for zero index
    // middle element (binary search divides array)
    // position (if found), returns -1 if not found
    // bool flag for found to abort search
    int first = 0,
        last = size - 1,
        middle,
        position = -1;
    bool found = false;

    while(!found && first <= last)
    {
        middle = (first + last) / 2; //find current midpoint
        //did we find it?
        if (nums[middle] == userInput)
        {
            //we found it!
            found = true;
            position = middle;
        }
        else if (nums[middle] > userInput) // if userInput is less than middle value it must be in lower half
            last = middle - 1;
        else
            first = middle + 1; // value must be in upper half

    }

    return position;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

