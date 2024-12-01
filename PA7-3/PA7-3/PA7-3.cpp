/*
John Hester
CISP 1010 - W02
Programming Assignment 7-3
12/1/2024
Description: Read in 25 int values from PA7.txt. Take in value from user. Do nothing with it. Sort array in ascending order with bubble sort. Print array one element at a time.
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
        int item, userInput, index = 0;
        //read in input from file
        while (inputFile.good())
        {
            inputFile >> nums[index];
            index++;
        }
        //get input from user;
        userInput = getInput();
        //bubble sort the array, ascending order
        bubbleSort(nums, SIZE);
        //print array 
        cout << "\nSorted array:\n\n";
        for (int num : nums)
            cout << num << endl;

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

// bubble sort, ascending order
void bubbleSort(int nums[], int size)
{
    int maxElement;
    int index;

    for (maxElement = size - 1; maxElement > 0; maxElement--) // iterate backwards as we sort
    {
        //inner loop
        for (index = 0; index < maxElement; index++) // iterate through the array, shifting larger items through
        {
            if (nums[index] > nums[index + 1]) //if num at index is larger, shift it down the array with swap()
            {
                swap(nums[index], nums[index + 1]);
            }
        }
    }
}

//swap array values
void swap(int& num1, int& num2)
{
    int temp = num2;
    num2 = num1;
    num1 = temp;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

