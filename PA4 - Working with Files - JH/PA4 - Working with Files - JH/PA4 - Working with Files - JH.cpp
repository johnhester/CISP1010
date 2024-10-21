/*
John Hester
CISP 1010-W02
Programming Assignment 4
Description: Take in values from a provided document + % owed to corporate based on user input and present values related to that store to the user
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

void storeOutput(double profitWeekly, double costWeekly, double amountOwedHQ, double percentageOwed, string storeName, ofstream& outputFile);
void finalOutput(int totalStores, double profitAllStores, double totalPaidCompany, ofstream& outputFile);


int main()
{

    //input file 
    ifstream inputFile;
    inputFile.open("Stores.txt");
    //output file
    ofstream outputFile;
    outputFile.open("Results per Location.txt");

    int totalStores = 0;
    double profitWeekly, revenueWeekly = 0, salariesWeekly = 0, materialsWeekly = 0, costWeekly = 0, amountOwedHQ = 0, profitAllStores = 0, totalPaidCompany = 0, percentageOwed;
    string storeName;
    bool didStoreProfit;


    //get percentage owed to corporate and validate input
    cout << "\nEnter the percentage owed to corporate: ";
    while (!(cin >> percentageOwed) || percentageOwed < 0)
    {
        //validate input, reset & clear out cin
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\nInvalid entry. Enter an amount greater than 0: ";
    }

    //check if inputFile exists
    if (inputFile)
    {
        //read information from input file
        //cout << "\nGathering data from file..." << endl;

        //read data from file till end
        /*
         * iterate through data in file to process
         Data Order: 
         Store name, 
         weekly amount spent on salaries, 
         weekly material cost, 
         weekly revenue

         Find weekly cost (alaries + materials)
         Find weekly profit (revenue - cost)
         
        */

        //was originally checking just inputfile, but it was printing the last line twice
        //apparently it takes one more iteration for the end of file (eof) to flag
        //.good() does a manual check to prevent that last iteration

        bool firstRun = true;

        while (inputFile.good())
        {
            //we know file iterates through an individual store every 4 lines 
            //we can use that to sort the input from the file
            for (int i = 0; i < 4; i++)
            {
                switch (i)
                {
                    case 0: 
                        //need to clear \n after first iteration
                        if (!firstRun) {
                            inputFile.ignore();
                        }
                        getline(inputFile, storeName, '\n');
                        firstRun = false;
                        break;
                    case 1:
                        inputFile >> salariesWeekly;
                        break;
                    case 2:
                        inputFile >> materialsWeekly;
                        break;
                    case 3:
                        inputFile >> revenueWeekly;
                        break;
                    default:
                        cout << "\nError. For loop went too far. Something is broken." << endl;
                }
            }
            //calculate profit & cost
            costWeekly = salariesWeekly + materialsWeekly;
            profitWeekly = revenueWeekly - costWeekly;
            amountOwedHQ = profitWeekly * percentageOwed;

            //update totals for final iteration
            totalStores++;
            profitAllStores += profitWeekly;
            if (profitWeekly > 0)
            {
                totalPaidCompany += amountOwedHQ;
            }

            //print output to command line & file
            storeOutput(profitWeekly, costWeekly, amountOwedHQ, percentageOwed, storeName, outputFile);
            
        } 

        //final output
        finalOutput(totalStores, profitAllStores, totalPaidCompany, outputFile);

    }
    else
    {
        cout << "\nError. Input file has an invalid name or is missing." << endl;
    }


    //cout << "\nEnding Program." << endl;
    inputFile.close();
    outputFile.close();
}

//learned fstreams have to be passed by reference
void storeOutput(double profitWeekly, double costWeekly, double amountOwedHQ, double percentageOwed, string storeName, ofstream& outputFile)
{
    //print name
    cout << "\n\n" << storeName << endl;
    outputFile << "\n\n" << storeName << endl;
    if (profitWeekly > 0)
    {
        //profit description
        cout << "\nTotal Cost for this location is $" << setprecision(2) << fixed << costWeekly << "." << endl;
        outputFile << "\nTotal Cost for this location is $" << setprecision(2) << fixed << costWeekly << "." << endl;
        cout << "\nThe profit for this location is $" << setprecision(2) << fixed << profitWeekly << "." << endl;
        outputFile << "\nThe profit for this location is $" << setprecision(2) << fixed << profitWeekly << "." << endl;
        cout << "\nThe store owes $" << setprecision(2) << fixed << amountOwedHQ << " to corporate." << endl;
        outputFile << "\nThe store owes $" << setprecision(2) << fixed << amountOwedHQ << " to corporate." << endl;
    }
    else
    {
        //didn't make no money
        cout << "\nStore did not make a profit. Location will be reevaluated." << endl;
        outputFile << "\nStore did not make a profit. Location will be reevaluated." << endl;
    }
}

void finalOutput(int totalStores, double profitAllStores, double totalPaidCompany, ofstream& outputFile)
{
    cout << "\n\nThis company currently has " << totalStores << " stores." << endl;
    outputFile << "\n\nThis company currently has " << totalStores << " stores." << endl;
    cout << "\nThe total profit for all stores is $" << setprecision(2) << fixed << profitAllStores << "." << endl;
    outputFile << "\nThe total profit for all stores is $" << setprecision(2) << fixed << profitAllStores << "." << endl;
    cout << "\nThe total amount paid to corporate is $" << setprecision(2) << fixed << totalPaidCompany << "." << endl;
    outputFile << "\nThe total amount paid to corporate is $" << setprecision(2) << fixed << totalPaidCompany << "." << endl;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

