/*
John Hester
CISP 1010-W02
Module 6 In-Class Activiy 
11/2/2024
*/

#include <iostream>
#include <limits>

using namespace std;
//prototypes
int menu();
void printStars(int = 30);
double validateDouble();
double add(double, double);
double subtract(double, double);

int main()
{
    //declar vars
    double num1, num2, result;
    int choice = 0;

    //get input
    cout << "\n\nWelcome! Please enter first number: ";
    num1 = validateDouble();
    cout << endl << "Enter your second number: ";
    num2 = validateDouble();
    cout << endl;

    choice = menu();
    switch (choice)
    {
    case 1:
        cout << endl << num1 << " + " << num2 << " = " << add(num1, num2) << endl;
        break;
    case 2:
        cout << endl << num1 << " - " << num2 << " = " << subtract(num1, num2) << endl;
        break;
    case 3:
        cout << "\nQuitting now...\n";
        break;
    default:
        cout << "\nSomething is broken..." << endl;
    }
}

//program menu
int menu()
{
    int choice;
    printStars(100);
    cout << "Bing bong! What would you like to do with your numbers?\n";
    cout << "\n(1) Add";
    cout << "\n(2) Subtract";
    cout << "\n(3) Quit";
    printStars(100);
    cout << "\nMake your selection: ";
    //input validate
    while (!(cin >> choice) || choice < 1 || choice >3)
    {
        cout << "\nInvalid input. Please make a choice from the menu: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return choice;
}



//prints lil stars
void printStars(int x)
{
    cout << endl;
    for (int i = 0; i < x; i++)
    {
        cout << "*";
    }
    cout << endl;
}
//confirms datatype
double validateDouble()
{
    double input;
    while(!(cin >> input)) 
    {
        cout << "\nDoh! Please enter a number: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return input;
}

//adds nums
double add(double num1, double num2)
{
    return num1 + num2;
}

//subtracts nums
double subtract(double num1, double num2)
{
    return num1 - num2;
}
