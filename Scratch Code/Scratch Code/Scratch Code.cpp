// Scratch Code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string name;
    double score;

    cout << "Welcome to the Midterm 1 exam." << endl;
    cout << "What is your name?";

    getline(cin, name);

    cout << "What grade do you hope to receive? ";
    cin >> score;

    if (score >= 90)
    {
        cout << name << ", hope you get your A." << endl;
    }
    else if (score >= 80)
    {
        cout << name << ", hope you get your B." << endl;
    }
    else if(score >= 60)
    {
        cout << name << ", shoot for the A or B." << endl;
    }
    else
    {
        cout << name << ", you can do better!." << endl;
    }

    return 0;
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

