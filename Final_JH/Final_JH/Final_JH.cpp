/*
John Hester
CISP 1010-W02
Final Exam Program
12/11/2024
Description: Gather an array of integers from the provided file and sort in ascending order. 
Generate a menu for the user giving them the option to print, prent only even entries, print the average, or quit. 
Validate the file's existence & user input. 
On exit print sorted array to file .
*/

#include <iostream>
#include <fstream>
#include <string>
#include <limits>


using namespace std;

//function declarations
int loadArray(int[], ifstream&);
void menu();
void selectionSort(int[], int);
void swap(int&, int&);
void print(int[], int, int);
int gatherInput();
void evenNumbers(int[], int, int);
void average(int[], int, int);
void outputToFile(int[], int, int);


int main()
{
    //initialize file stuff
    string fileName = "Values.txt";
    ifstream inputFile;
    inputFile.open(fileName);

    //validates that file actually exists
    if (inputFile)
    {
        // array to store ints from file
        // can hold up to 30 values, but not guaranteed 30 values
        const int SIZE = 30;
        int nums[SIZE];
        int actualSize, choice;

        //gather input until end of file & return number of elements provided
        //get actual number of values
        actualSize = loadArray(nums, inputFile);

        //sort da values
        selectionSort(nums, SIZE);

        //query the user and get input
        menu();
        choice = gatherInput();

        //repeat until 4 is chosen
        while (choice != 4)        {

            //what are we doing
            switch (choice)
            {
                case 1: 
                    print(nums, SIZE, actualSize);
                    break;
                case 2:
                    evenNumbers(nums, SIZE, actualSize);
                    break;
                case 3:
                    average(nums, SIZE, actualSize);
                    break;
                default:
                    cout << "\n\nError. Something got past input validation.\n";
            }
            
            //query the user and get input
            menu();
            choice = gatherInput();
        }
        //we're done, print nums array to file
        outputToFile(nums, SIZE, actualSize);
    }
    else
        cout << "\n\nFile Error\n";

    inputFile.close();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

//fill array & get actual number of values
int loadArray(int nums[], ifstream& inputFile)
{
    //iterate array location
    int counter = 0;
    while (inputFile.good())
    {
        inputFile >> nums[counter];
        counter++;
    }
    //returns actual number of items in array
    return counter;
}

//menu function
void menu()
{
    
    cout << endl;
    cout << "\t1. Print Values\n";
    cout << "\t2. Print Only Even Numbers\n";
    cout << "\t3. Print Average\n";
    cout << "\t4. Quit\n\n";

    cout << "Enter your choice: ";

}

//selection sort, ascending order
//selection sort for efficiency, not that it is needed
void selectionSort(int nums[], int size)
{
    int minIndex, minValue; //store index & lowest val for iteratino

    for (int start = 0; start < (size - 1); start++)
    {
        minIndex = start; //start at beginning
        minValue = nums[start]; // get first value

        for (int index = start + 1; index < size; index++) // start one ahead of the smallest value known 
        {
            //check for small value
            if (nums[index] < minValue)
            {
                minValue = nums[index]; //grab new small value
                minIndex = index; //grab smallest location
            }
        }

        //after cycle, swap min value and value at starting index
        swap(nums[minIndex], nums[start]);

    }

}

//lil function for swapping arr values
void swap(int& num1, int& num2)
{
    int temp = num2;
    num2 = num1;
    num1 = temp;
}


//print array values
void print(int nums[], int size, int actualSize)
{
    cout << endl;
    //array will always be sorted in ascending value for this assignment
    for (int i = size - actualSize; i < size; i++)
        cout << nums[i] << endl;
    cout << endl;
}

//gather input, check for validity
int gatherInput()
{
    int val;
    //makes sure cin is compatible with val's type & that choice is between 1 & 4
    while (!(cin >> val) || (val < 1 || val > 4))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInvalid Menu Choice\n";
        menu();
    }
    return val;
}

//print even numbers
void evenNumbers(int nums[], int size, int actualSize)
{
    cout << endl;
    //print only relevant items;
    for (int i = size - actualSize; i < size; i++)
    {
        //checks if entry is even using modulo
        if (nums[i] % 2 == 0)
            cout << nums[i] << endl;;
    }
}

//calculate average
void average(int nums[], int size, int actualSize)
{
    double sum = 0, average;

    for (int i = size - actualSize; i < size; i++)
    {
        sum += nums[i];
    }

    average = sum / actualSize;

    cout << "\nThe average of the numbers is " << average << endl;
}

//print sorted array to file at end of program
void outputToFile(int nums[], int size, int actualSize)
{
    //prepare ye olde output file
    string fileName = "SortedArray.txt";
    ofstream outputFile;
    outputFile.open(fileName);

    for (int i = size - actualSize; i < size; i++)
        outputFile << nums[i] << endl;

    //close output file
    outputFile.close();

}