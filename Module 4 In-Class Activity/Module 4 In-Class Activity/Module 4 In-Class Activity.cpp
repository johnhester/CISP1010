/*
John Hester
CISP 1010-W02
Module 4 In-Class Activity
9/29/2024
*/

#include <iostream>
using namespace std;
int main()
{
    //declare variables
    int num1, num2, num3, large, middle, small;

    //gather input
    cout << "Enter your first number: ";
    cin >> num1;
    cout << "\nEnter your second number: ";
    cin >> num2;
    cout << "\nEnter your third number: ";
    cin >> num3;
    cout << "\n";

    //duplicate chec
    if (num1 == num2 || num1 == num3 || num2 == num3) 
    {
        cout << "You have entered duplicate numbers. Please restart and try again.\n";

    }
    else 
    {

        //re-order numbers
        //gross without arrays, but it works
        if (num1 > num2 && num1 > num3) { //num1 is big
            large = num1;
            if (num2 > num3) { 
                middle = num2;
                small = num3;
            }
            else {
                middle = num3;
                small = num2;
            }
        }
        else if (num2 > num3) { //num2 is big
            large = num2;
            if (num3 > num1) {
                middle = num3;
                small = num1;
            }
            else {
                middle = num1;
                small = num3;
            }
        }
        else { //num3 is big
            large = num3;
            if (num1 > num2) {
                middle = num1;
                small = num2;
            }
            else {
                middle = num2;
                small = num1;
            }
        }
        //normal output
        cout << endl;
        cout << "The smallest number is " << small << endl;
        cout << "The middle number is " << middle << endl;
        cout << "The largest number is " << large << endl;
    }


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
