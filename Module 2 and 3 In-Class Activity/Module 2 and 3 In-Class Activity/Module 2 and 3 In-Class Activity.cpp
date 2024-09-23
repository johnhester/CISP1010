// Module 2 and 3 In-Class Activity.cpp : This file contains the 'main' function. Program execution begins and ends there.
/* 
John Hester
CISP 1010-W02
Module 2 and 3 In-Class Activity
09/22/2024
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    string name, favFood, favDrink, favAnimal, dreamJob;
    double number;

    cout << "Enter your name: ";
    getline(cin, name);
    cout << "Enter your favorite food: ";
    getline(cin, favFood);
    cout << "Enter your favorite drink: ";
    getline(cin, favDrink);
    cout << "Enter your favorite animal: ";
    getline(cin, favAnimal);
    cout << "Enter your dream job: ";
    getline(cin, dreamJob);
    cout << "Enter a decimal number with at least 3 decimal places: ";
    cin >> number;

    //output
    cout << endl;
    cout << "Hi\n";
    cout << "My name is " << name << endl;
    cout << "My favorite food is " << favFood << endl;
    cout << "My favorite drink is " << favDrink << endl;
    cout << "My favorite animal is " << favAnimal << endl;
    cout << "My dream job is " << dreamJob << endl;
    cout << "Your number rounded to 1 decimal place is " << fixed << setprecision(1) << number;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
