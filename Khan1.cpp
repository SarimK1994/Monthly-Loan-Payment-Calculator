/**************************************************************************
*                                                                         *
*     Program Filename:  Khan1.cpp                                        *
*     Author          :  Sarim Khan                                       *
*     Date Written    :  September 15, 2017                               *
*     Purpose         :  Calculate payment plan for loans                 *
*     Input from      :  Keyboard                                         *
*     Output to       :  Screen                                           *
*                                                                         *
**************************************************************************/
#include <iostream>
using namespace std; 
#include <conio.h>
#include <iomanip>

int main()
{
	double amountOwed, addPayment, monthlyInterest, annualInterest, principal, monthlyPayment;
	int page = 1, i; 
	char Continue; 
	
	cout << setprecision(2) << fixed; 

	cout << endl << "Please enter the total amount owed: "; 
	cin >> amountOwed;

	cout << endl << "Please enter the annual interest rate: ";
	cin >> annualInterest; 

	cout << endl << "Please enter the additional monthly payment: "; 
	cin >> addPayment; 

	while (amountOwed > 0)
	{
	
		cout << endl << "Page " << page << ":";
		cout << endl << "=======";

		cout << endl << endl << "Amount Owed: " << amountOwed;
		cout << endl << "Annual Interest Rate: " << annualInterest << "%";
		cout << endl << "Additional Payment Each Month: " << addPayment; 

		cout << endl << endl << "================================================================================";
		cout << endl << endl;

		cout << setw(5) << "MONTH     ";
		cout << setw(5) << "PAYMENT     ";
		cout << setw(5) << "PRINCIPAL     ";
		cout << setw(5) << "INTEREST     ";
		cout << setw(5) << "BALANCE     "; 
		cout << endl << setw(5) << "=====     ";
		cout << setw(5) << "=======     ";
		cout << setw(5) << "=========     ";
		cout << setw(5) << "========     ";
		cout << setw(5) << "=======     ";

		for (i = 1; i < 13; i++)
		{
			monthlyPayment = amountOwed*.02 + addPayment;
			monthlyInterest = ((annualInterest / 12) / 100)*amountOwed;
			principal = monthlyPayment - monthlyInterest;
			amountOwed = amountOwed + monthlyInterest - monthlyPayment; 


			if (monthlyPayment > amountOwed)
			{
				monthlyPayment = amountOwed; 
				cout << endl << i << left << setw(9) << "." << left << setw(12) << monthlyPayment << left << setw(14) << principal << left << setw(13) << monthlyInterest << left << amountOwed;
				cout << endl << "Congratulations! You have paid off your balance." << endl << "Please enter any key to exit: ";
				cin >> Continue; 
				return 0; 
			}
			if (i <= 9)
			{
				cout << endl << i << left << setw(9) << ".";
				cout << left << setw(12) << monthlyPayment;
				cout << left << setw(14) << principal;
				cout << left << setw(13) << monthlyInterest;
				cout << left << amountOwed;
			}
			else
			{
				cout << endl << i << left << setw(8) << ".";
				cout << left << setw(12) << monthlyPayment;
				cout << left << setw(14) << principal;
				cout << left << setw(13) << monthlyInterest;
				cout << left << amountOwed;
			}
		}

		cout << endl << "Please enter 'c' to continue: ";
		cin >> Continue; 
		if (Continue == 'c')
			cout << endl;
		else
			return 0; 

		page++; 
	}

	return 0; 

}