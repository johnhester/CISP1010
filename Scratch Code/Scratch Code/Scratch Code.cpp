// Scratch Code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
//#include <limits>

using namespace std;

void main()
{
    double hoursWorked, payPerHour, netPay;

    cout << "\nEnter the number of hours the employee worked this week: ";

    while (!(cin >> hoursWorked) || hoursWorked < 0 || hoursWorked > 40)
    {
        cout << "\nInvalid input. Input a number between 0 and 40: ";
        
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "\nEnter the amount the emopee is paid per hour: ";
    cin >> payPerHour;

    while (payPerHour < 7.25 || payPerHour > 20.00)
    {
        cout << "\nInvalid pay rate. Please input a number between the federal minimum wage and $20.00 per hour: ";
        cin >> payPerHour;
    }

    netPay = hoursWorked * payPerHour;

    cout << "\nThe pay this week is $" << setprecision(2) << fixed << netPay << endl;

}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

