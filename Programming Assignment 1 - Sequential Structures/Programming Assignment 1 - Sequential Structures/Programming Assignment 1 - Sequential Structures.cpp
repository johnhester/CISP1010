/*
    John Hester
    CISP 1010-W02
    Programming Assignment 1
    Last Date Modified: 09/13/2024
    Program Description: This program prompts the user for information (Name, current date, city & state) and the temp in celsius. It then returns that information formatted 
        with the temp in Celsius, Fahrenheit, and Kelvin
    in Kelvin and Fahrenheit
*/
#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

int main()
{
    string name, month, city, state;
    int day, year;
    float temp_c, temp_f, temp_k;

    // User input section
    cout << "Hello! Welcome to temp converter!\n" << "I am going to ask you for some information.\n";
    cout << "What is your name?\n";
    cin >> name;
    cout << "What month is it?\n";
    cin >> month;
    cout << "What day of the month is it?\n";
    cin >> day;
    cout << "What year is it?\n";
    cin >> year;
    cout << "What city are you from?\n";
    cin >> city;
    cout << "What state is that in?\n";
    cin >> state;
    cout << "What is the current temperature in Celsius?\n";
    cin >> temp_c;
    cout << "\nThank you for your patience. Converting temperatures...\n\n";

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
    cout << "Today's Date is " << month << ", " << day << ", " << year << endl;
    cout << "Current City: " << city << ", " << state << endl;
    cout << "It is currently " << temp_c << " degrees Celsius" << endl;
    cout << "It is currently " << temp_f << " degrees Fahrenheit" << endl;
    cout << "It is currently " << temp_k << " degrees Kelvin" << endl;



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


