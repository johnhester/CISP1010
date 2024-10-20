/* 
John Hester
CISP 1010-W02
Programming Assignment 3
10/20/2024
Description: The program takes in as many prices as the user wants to enter, validates input, and when they are done it prints the 
total # of items, the purchas total, and the average cost per item.
*/

#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

int menu();
double getPrice();

int main()
{
    int menuChoice;
    double price, totalItemCount = 0, totalAmount = 0, averageAmount, taxRate, costAfterTaxes;
    bool keepGoing = true;
    do
    {
        menuChoice = menu();
        switch (menuChoice)
        {
            case 1:
                price = getPrice();
                totalItemCount++;
                totalAmount += price;
                break;
            case 2:
                keepGoing = false;
                break;
            default: 
                cout << "/nSomething broke." << endl;
        }

    } while (keepGoing);
    //get average
    averageAmount = totalAmount / totalItemCount;
    
    //determine tax rate
    if (totalItemCount < 10)
    {
        taxRate = 0.095;
    }
    else
    {
        taxRate = 0.09;
    }
    //total cost including taxes
    costAfterTaxes = totalAmount + (totalAmount * taxRate);


    //exit lines
    cout << "\nYou purchased " << totalItemCount << " items." << endl;
    cout << "\nThe total for this purchase is $" << setprecision(2) << fixed << totalAmount << " before tax." << endl;
    cout << "\nThe average amount per item for this puchase was $" << setprecision(2) << fixed << averageAmount << "." << endl;
    cout << "\nThe tax burden for this purchase is $" << setprecision(2) << fixed << totalAmount * taxRate << "." << endl;
    cout << "\nThe total cost after taxes is $" << setprecision(2) << fixed << costAfterTaxes << "." << endl;
}

int menu()
{
    int selection;
    cout << "\n------------------------------------------------------------------" << endl;
    cout << "Make a selection: " << endl;
    cout << "1. Enter another item." << endl;
    cout << "2. Quit." << endl;
    cout << "------------------------------------------------------------------" << endl;

    //if cin fails in the while condition it will throw an error and flag as false, by inverting that with ! we can cause bad input to trigger the validation + use logic for other options
    while (!(cin >> selection) || selection != 1 && selection !=2)
    {
        //clears cin error flag if needed so that cin can resume operating 
        cin.clear();
        //ignores buffer up to size limit or until \n is reached
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInvalid choice. Please select a menu option." << endl;

    }

    return selection;
}

double getPrice()
{
    double price;
    cout << "\nEnter the amount for the item: ";
    while (!(cin >> price) || price <= 0)
    {
        //clears cin error flag if needed so that cin can resume operating 
        cin.clear();
        //ignores buffer up to size limit or until \n is reached
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInvalid amount. Must be greater than 0. ";
    }

    return price;
}




// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

