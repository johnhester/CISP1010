// Scratch Code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	const int A_score = 90,
		B_score = 80,
		C_score = 70,
		D_score = 60;

	int testScore;
	//get score
	cout << "Enter you numeric test score and I will\n"
		<< "tell you the letter grade you earned: ";
	cin >> testScore;

	//determine grade
	if (testScore >= A_score)
		cout << "Your grade is A.\n";
	else if (testScore >= B_score)
		cout << "Your grade is B.\n";
	else if (testScore >= C_score)
		cout << "Your grade is C.\n";
	else if (testScore >= D_score)
		cout << "Your grade is D.\n";
	else if (testScore >= 0)
		cout << "Your grade is F.\n";
	else
		cout << "Invalid test score.\n";

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

