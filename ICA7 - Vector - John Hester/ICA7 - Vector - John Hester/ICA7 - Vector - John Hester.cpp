/*
John Hester
CISP 1010-W02
In-Class Activity 7 - Vector
11/16/2024
*/

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void getValues(ifstream&, vector<int>&);
int highValue(vector<int>);
int lowValue(vector<int>);
int sumArray(vector<int>);
void progOutput(int, int, int, double);

int main()
{
    // set up array
    vector<int> nums;
    //file set up
    ifstream inputFile;
    const string fileName = "Numbers.txt";
    inputFile.open(fileName);
    //other values;
    int highVal, lowVal;
    double avg, total;

    if (inputFile)
    {
        //function for grabbing file data
        getValues(inputFile, nums);
        //find the values
        highVal = highValue(nums);
        lowVal = lowValue(nums);
        total = sumArray(nums);
        avg = total / static_cast<double>(nums.size());
        
        ////print output
        progOutput(highVal, lowVal, total, avg);

        
    }
    else
    {
        cout << endl << "File error" << endl;
    }

    inputFile.close();

}

//fstreams have to be passed by reference
void getValues(ifstream& inputFile, vector<int>& nums)
{
    //iterate through file till end
    while (inputFile.good())
    {
        int tempNum;
        inputFile >> tempNum;
        //cout << tempNum << endl;
        nums.push_back(tempNum);
    }
    
}

//get highValue
int highValue(vector<int> nums)
{
    int highVal = nums[0];
    for (int num : nums)
    {
        if (num > highVal)
            highVal = num;
    }

    return highVal;
}

//get low value
int lowValue(vector<int> nums)
{
    int lowVal = nums[0];
    for (int num : nums)
    {
        if (num < lowVal)
            lowVal = num;
    }

    return lowVal;
}
//sum array
int sumArray(vector<int> nums)
{
    int total = 0;
    for (int num : nums)
        total += num;

    return total;
}
//prints output
void progOutput(int highVal, int lowVal, int total, double avg)
{
    cout << endl;
    cout << "The highest value is: " << highVal << endl;
    cout << "The lowest value is: " << lowVal << endl;
    cout << "The total is: " << total << endl;
    cout << "The average is: " << avg << endl;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

