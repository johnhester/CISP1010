/*
John Hester
CISP 1010-W02
Programming Assignment 2
Description: This program is going to take in sure info and calculate grades using that info before producing output based on the grades.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double exam1, exam2, exam3, examAvg, homeworkAvg, quizAvg, totalAvg;
    //input
    cout << "Hello!" << endl << endl;
    cout << "Please enter your homework average: ";
    cin >> homeworkAvg;
    cout << "\nPlease enter your quiz average: ";
    cin >> quizAvg;
    cout << "\nEnter your first exam score: ";
    cin >> exam1;
    cout << "\nEnter your second exam score: ";
    cin >> exam2;
    cout << "\nEnter your third exam score: ";
    cin >> exam3;
    cout << "\nThank you\n\n calculating..." << endl;

    //calculate grade
    /*
    Formulas:
    Exam Average = (E1 + E2 + E3)/3
    Total Average = 0.15*Homework Average + 0.15*Quiz Average + 0.70*Exame Average
    */
    examAvg = (exam1 + exam2 + exam3) / 3;
    totalAvg = (0.15*homeworkAvg)+(0.15*quizAvg)+(0.7*examAvg);


    //output
    cout << endl;
    cout << setprecision(2) << fixed << "Your average is a " << totalAvg << endl;
    
    //did they pass?
    if (totalAvg >= 60)
    {
        cout << "You passed the course." << endl;
        //only applies if passing
        if (examAvg < 60)
        {
            cout << "You need to do better on your exams!" << endl;
        }
        if (homeworkAvg < 60)
        {
            cout << "You need to do better on your homework." << endl;
        }
        if (quizAvg < 60)
        {
            cout << "you need to do better on your quizzes" << endl;
        }
        if (totalAvg >= 80)
        {
            cout << "You are doing awesome in this course." << endl;
        }
    }
    else //they're failing, more intense output 
    {
        if (homeworkAvg < 60)
        {
            cout << "You need to do better on your homework!" << endl;
        }
        if (quizAvg < 60)
        {
            cout << "You need to do better on your quizzes!" << endl;
        }
        if (examAvg < 60)
        {
            cout << "You need to do better on your exams!" << endl;
        }
    }

    if (totalAvg >= 90)
    {
        cout << "You have an A" << endl;
    }
    else if (totalAvg >= 80)
    {
        cout << "You have a B" << endl;
    }
    else if (totalAvg >= 70)
    {
        cout << "You have a C" << endl;
    }
    else if (totalAvg >= 60)
    {
        cout << "You have a D" << endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

