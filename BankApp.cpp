#include <iostream>
#include <iomanip>
using namespace std;

//initialize variables for yearly report calculations
double initialDeposit = -1.0;
double monthlyDeposit = -1.0;
double interestRate = -1.0;
int numberOfYears = -1;

//variable to store any input after DataInput()
string key = "";




//this function takes data from user and assigns it to the variables
void DataInput() {

	//take user's input for initialDeposit
	//loop until input is non-negative number
	for (;;) {
		cout << "Initial Investment Amount: $";
		if ((cin >> initialDeposit) && (initialDeposit >= 0)) {
			break;
		}
		else {
			cout << "Please enter a non-negative number." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	//take user's input for monthlyDeposit
	//loop until input is non-negative number
	for (;;) {
		cout << "Monthly Deposit: $";
		if ((cin >> monthlyDeposit) && (monthlyDeposit >= 0)) {
			break;
		}
		else {
			cout << "Please enter a non-negative number." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	//take user's input for interestRate
	//loop until input is non-negative number
	for (;;) {
		cout << "Annual Interest Rate: %";
		if ((cin >> interestRate) && (interestRate >= 0)) {
			break;
		}
		else {
			cout << "Please enter a non-negative number." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	//take user's input for numberOfYears
	//loop until input is positive integer
	for (;;) {
		cout << "Number of Years: ";
		if ((cin >> numberOfYears) && (numberOfYears > 0)) {
			break;
		}
		else {
			cout << "Please enter a positive integer." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}

	//any input to proceed
	cout << "Press any key to continue . . ." << endl;
	cin >> key;
}




//this function takes a double and returns its length
//its used for formatting output in PrintYearlyReport()
int NumLength(double number) {
	int num = (int)(number);
	int digits = 0;
	if (num == 0) {		//in case the double parameter was rounded to 0
		digits = 1;		//because the 0 still prints before the decimals
	}
	while (num != 0) {	//loop counts a digit, removes a digit until num is 0
		digits += 1;
		num /= 10;
	}
	return digits + 4;	//+4 to account for the $/% and the decimal tail
}


//this function calculates and prints the yearly report
void PrintYearlyReport(double initialDep, double monthlyDep, double interestRate, int numYears) {

	//initialize variables that keep track of running calculations as 0
	double monthlyEarnedInterest = 0.0;
	double monthlyBalance = 0.0;
	double yearEndEarnedInterest;
	double compoundingAmt = 0.0;

	//start the compounding amt as the initial deposit
	compoundingAmt = initialDep;

	//output header with 3 columns
	cout << "  Year";
	cout << setfill(' ') << setw(8) << "";
	cout << "Year End Balance";
	cout << setw(6) << "";
	cout << "Year End Earned Interest" << endl;
	cout << setfill('-') << setw(64) << "" << endl;

	//for loop will execute for as many years the user input
	//int y indicates the current year of the compounding process
	for (int y = 1; y <= numYears; ++y) {

		//start the yearEnd interest amount as 0
		yearEndEarnedInterest = 0.0;

		//for loop executes one time for each month in the year
		for (int m = 0; m < 12; ++m) {
			//formula calculates interest earned this month
			monthlyEarnedInterest = (compoundingAmt + monthlyDep) * ((interestRate / 100) / 12);
			//update the compounding amt with the monthly earned interest and the monthly deposit
			compoundingAmt += monthlyDep + monthlyEarnedInterest;
			//update the year end total interest with this month's earned interest
			yearEndEarnedInterest += monthlyEarnedInterest;
		}

		// output this year's numbers on a single formatted line
		cout << fixed << setprecision(2);
		cout << setfill(' ') << setw(6) << right << y;
		cout << setfill(' ') << setw((int)24 - NumLength(compoundingAmt)) << "";
		cout << "$" << compoundingAmt;
		cout << setw((int)30 - NumLength(yearEndEarnedInterest)) << "";
		cout << "$" << yearEndEarnedInterest << endl;
	}

	cout << endl;
}




//main simply implements the two main functions
int main() {

	//Data Input header
	cout << setfill('*') << setw(36) << "" << endl;
	cout << setw(12) << "";
	cout << " Data Input ";
	cout << setw(12) << "" << endl;
	//gather user data
	DataInput();

	//annual report without monthly deposits header
	cout << endl << setfill(' ') << setw(4) << "";
	cout << "Balance and Interest Without Additional Monthly Deposits";
	cout << setw(4) << "" << endl;
	cout << setfill('=') << setw(64) << "" << endl;
	//print annual report without monthly deposits
	PrintYearlyReport(initialDeposit, 0.0, interestRate, numberOfYears);

	//annual report with monthly deposits header
	cout << endl << setfill(' ') << setw(5) << "";
	cout << "Balance and Interest with Additional Monthly Deposits";
	cout << setw(6) << "" << endl;
	cout << setfill('=') << setw(64) << "" << endl;
	//print annual report with monthly deposits
	PrintYearlyReport(initialDeposit, monthlyDeposit, interestRate, numberOfYears);

	return 0;
}