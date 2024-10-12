/*
John Hester
CISP 1010-N01
Midterm Program 1
Description: This program will take in hourly pay and hours worked and calculate total pay. If hours worked > 40 pay is 1.5x for hours over 40. 
Program will check for input greater than 0, else it will display an error message and stop.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;

bool inputChecker(double input, string inputType) {
    if (input < 0)
    {
        cout << endl << inputType << " must be greater than 0." << endl;
        return false;
    }
    else
    {
        return true;
    }
}

int main()
{
    long double hours, rate, otHours, otPay, regPay, totalPay;
    bool validHours, validRate;
    //input
    cout << "\nWelcome to pay estimator." << endl;
    cout << "\nPlease enter the number of hours you worked this week: ";
    cin >> hours;
    cout << "\nPlease enter your hourly rate of pay: ";
    cin >> rate;

    //check input
    validHours = inputChecker(hours, "Hours worked");
    validRate = inputChecker(rate, "Hourly pay");
    

    //check if rest of program executes
    if (validHours && validRate)
    {
        //calculate
        if (hours > 40) {
            //get overtime
            otHours = hours - 40;
            otPay = otHours * (1.5 * rate);
            //get regular hours
            regPay = 40 * rate;
            //total
            totalPay = otPay + regPay;
        }
        else {
            totalPay = hours * rate;
        }

        //output
         
        //cout << "\nYou earned $" << setprecision(2) << fixed << showpoint << totalPay << " this week." << endl;
        // 
        //Using setprecision(2), fixed, and showpoint as shown above produced inconsistent rounding output so I used the round function from the math library to do the actual calculation and the others to format output
        double roundedTotalPay = round(totalPay * 100) / 100.0;

        cout << "\nYou earned $" << setprecision(2) << fixed << showpoint << roundedTotalPay << " this week." << endl;

    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu


