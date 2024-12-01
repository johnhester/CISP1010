/*
John Hester
CISP 1010 - W02
Programming Assignment 7-4
12/1/2024
Description: Read in 25 int values from PA7.txt. Take in value from user. Do nothing with it. Use selection sort to sort array in descending order. Print array one element at a time.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;
//function declarations
int getInput();
void selectionSort(int[], int);
void swap(int&, int&);

int main()
{
    ifstream inputFile;
    string fileName = "PA7.txt";
    inputFile.open(fileName);

    if (inputFile)
    {
        //input file is 25 long     
        //variable declarations 
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
        //use selection sort to sort array in descending value 
        selectionSort(nums, SIZE);
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


//selection sort, descending order
void selectionSort(int nums[], int size)
{
    int maxIndex, maxValue; //store index and value of highest value for the iteration
    
    for (int start = 0; start < (size - 1); start++)
    {
        maxIndex = start; //start at the beginning
        maxValue = nums[start]; //get first value 
        for (int index = start + 1; index < size; index++)
        {
            //check for large value
            if (nums[index] > maxValue)
            {
                // if larger than current max value grab value & index
                maxValue = nums[index];
                maxIndex = index;
            }
        }

        //after cycling through, swap max value and value at starting index
        swap(nums[maxIndex], nums[start]);
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

