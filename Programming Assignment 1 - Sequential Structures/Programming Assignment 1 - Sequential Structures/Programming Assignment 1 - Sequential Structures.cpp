/*
    John Hester
    CISP 1010-W02
    Programming Assignment 1
    Last Date Modified: 09/22/2024
    Program Description: This program prompts the user for information (Name, current date, city & state) and the temp in celsius. It then returns that information formatted 
        with the temp in Celsius, Fahrenheit, and Kelvin
    in Kelvin and Fahrenheit
*/
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    string name, month, city, state;
    int day, year;
    float temp_c, temp_f, temp_k;

    // User input section
    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter the month: ";
    getline(cin, month);
    cout << "Enter the day of the month: ";
    cin >> day;
    cout << "Enter the year: ";
    cin >> year;
    cout << "Enter the city: ";
    //gets rid of newline character from cin above 
    cin.ignore(); 
    getline(cin, city);
    cout << "Enter the state: ";
    getline(cin, state);
    cout << "What is the current temperature in Celsius? ";
    cin >> temp_c;

    /*
        Temp Calculations:
        F = 1.8*C + 32 
        K = C + 273.15
     */
    temp_f = (1.8 * temp_c) + 32;
    temp_k = temp_c + 273.15;

    //Formatted output

    cout << endl;
    cout << "Hello, " << name << endl;
    cout << "Today's Date is " << month << " " << day << ", " << year << endl;
    cout << "Current City: " << city << ", " << state << endl;
    cout << "It is currently " << setprecision(1) << fixed << showpoint << temp_c << " degrees Celsius" << endl;
    cout << "It is currently " << setprecision(1) << fixed << showpoint << temp_f << " degrees Fahrenheit" << endl;
    cout << "It is currently " << setprecision(1) << fixed << showpoint << temp_k << " degrees Kelvin" << endl;



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


