/*
John Hester
CISP 1010-W02
Programming Assignment 5
11/04/2024
Description: The program takes in as many prices as the user wants to enter, validates input, and when they are done it prints the
total # of items, the purchas total, and the average cost per item.
*/

#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

void printMenu();
int menuValid();
double getPrice();
bool priceInvalid(double);
double priceTypeValid();
void printInfo(double, double);

int main()
{
    int menuChoice;
    double price, totalItemCount = 0, totalAmount = 0, averageAmount, taxRate, costAfterTaxes;
    bool keepGoing = true;
    do
    {
        printMenu();
        menuChoice = menuValid();
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
    
    //printes the final lines
    printInfo(totalAmount, totalItemCount);
}

void printMenu()
{
    //tracks first run for alternate message
    static bool firstRun = true;
    int selection;
    cout << "\n------------------------------------------------------------------" << endl;
    cout << "Make a selection: " << endl;
    if (firstRun)
    {
        cout << "1. Enter an item." << endl;
        firstRun = false;
    }
    else
        cout << "1. Enter another item." << endl;
    cout << "2. Quit." << endl;
    cout << "------------------------------------------------------------------" << endl;

}

double getPrice()
{
    double price;
    bool priceBad = true;
    cout << "\nEnter the amount for the item: ";

    //typechecker (did they enter a number?)
    price = priceTypeValid();

    //amount check
    while (priceBad)
    {
        //was the first price good?
        priceBad = priceInvalid(price);
        //if not, try again
        if (priceBad)
        {
            //let them know
            cout << "\nInvalid amount. Must be greater than 0: ";
            //re-obtain price
            price = priceTypeValid();

        }
    }

    return price;
}

//checks if the received price is greater than zero
bool priceInvalid(double price)
{
    if (price > 0)
        return false;
    else
        return true;
}

//type checker for price
double priceTypeValid()
{
    double price;
    while (!(cin >> price))
    {
        //clears cin error flag if needed so that cin can resume operating 
        cin.clear();
        //ignores buffer up to size limit or until \n is reached
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInvalid entry. Please enter a number: ";
    }
    return price;
}

//menu validator
int menuValid()
{
    int selection;
    //if cin fails in the while condition it will throw an error and flag as false, by inverting that with ! we can cause bad input to trigger the validation + use logic for other options
    while (!(cin >> selection) || selection != 1 && selection != 2)
    {
        //clears cin error flag if needed so that cin can resume operating 
        cin.clear();
        //ignores buffer up to size limit or until \n is reached
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInvalid choice. Please select a menu option." << endl;

    }

    return selection;
}

//calculates info and prints final lines
void printInfo(double totalAmount, double totalItemCount)
{
    //variables
    double averageAmount, taxRate, costAfterTaxes;

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


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

