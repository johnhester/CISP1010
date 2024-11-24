/*
John Hester
CISP 1010-W02
Programming Assignment 6
11/16/24
We're going to do some stuff with arrays and grades
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

//global vars for array rows and cols
//up to 30 students, 2 columns for name array, 3 columns for grade array
const int ROWS = 30, NAME_COLS = 2, GRADE_COLS =3;

//function prototypes
int loadArrays(ifstream&, string[][NAME_COLS], double[][GRADE_COLS]);
char calcGrade(double[]);
string getName(string[]);
void output(string, char);

int main()
{
    //set up file input
    ifstream inputFile;
    string fileName = "Students.txt";
    inputFile.open(fileName);
    
    if (inputFile)
    {
        //arrays
        string names[ROWS][NAME_COLS];
        double grades[ROWS][GRADE_COLS];
        //additional vars
        int numStudents;
        char letterGrade;
        string fullName;
        //load arrays with values & return student count
        numStudents = loadArrays(inputFile, names, grades);

        
        //iterate
        for (int i = 0; i < numStudents; i++)
        {
            //get full name
            fullName = getName(names[i]);
            //get grad vars
            letterGrade = calcGrade(grades[i]);
            //print output
            output(fullName, letterGrade);
        }
    }
    else
    {
        cout << endl << "File Error" << endl;
    }

    //close your filestream
    inputFile.close();
}

//loads values into arrays, also returns student count
int loadArrays(ifstream& inputFile, string names[][NAME_COLS], double grades[][GRADE_COLS])
{
    /*
    File format:
    First Name
    Last Name
    Homework Average
    Quiz Average
    Exam Average
    */

    //counts number of students & tracks columns
    int student_counter = 0;
    static int col_counter = 0;
    //loop runs till end of file
    while (inputFile.good() && student_counter < ROWS)
    {
        //progress resets every 5 lines
        //0-1, load name col
        //2-4, load grade col
        //iterate to new student
        switch (col_counter)
        {
        case 0:
        case 1:
            inputFile >> names[student_counter][col_counter];
            col_counter++;
            break;
        case 2:
        case 3:
        case 4:
            //col-2 to correctly index array
            inputFile >> grades[student_counter][col_counter-2];
            col_counter++;
            if (col_counter > 4)
            {
            //reset column, iterate to next student
                col_counter = 0;
                student_counter++;
            }
            break;
        default:
            cout << endl << "Something broke" << endl;
        }


    }
    return student_counter;

}

//calculate grades
char calcGrade(double gradeCol[])
{
    double hwAvg, quizAvg, examAvg, average;
    /*
    Structure:
    0 - homework
    1 - quiz
    2 - exam
    */
    hwAvg = gradeCol[0];
    quizAvg = gradeCol[1];
    examAvg = gradeCol[2];

    //formula: average = hw*0.1 + quiz*0.1 + exam*0.8
    average = hwAvg * 0.1 + quizAvg * 0.1 + examAvg * 0.8;

    //return appropriate grade
    if (average >= 90)
        return 'A';
    else if (average >= 80)
        return 'B';
    else if (average >= 70)
        return 'C';
    else if (average >= 60)
        return 'D';
    else
        return 'F';
}

//get full name
string getName(string nameCol[NAME_COLS])
{
    /*
    structure:
    0 - First Name
    1 - Last Name
    */

    string fullName;
    bool firstRun = true;
    for (int i = 0; i < NAME_COLS; i++)
    {
        //check for first run to add space to successive iterations
        if (firstRun)
        {
            fullName += nameCol[i];
            firstRun = false;
        }
        else {
            fullName += " " + nameCol[i];

        }

    }

    return fullName;

}

//prints output
void output(string name, char letterGrade)
{
    cout << endl << name << ": " << letterGrade << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
