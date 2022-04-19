// Micah Pennington
// March 28 2022 ©
// Chapter 11 Program

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct customerAccount {
	string name;
	string streetAddress;
	string cityStateZip;
	string phoneNumber;
	double balance;
	string lastPayment;
};

// Prototypes
customerAccount makeCustomer();
void displayAccounts(customerAccount arr[], int arrSize);
void accountsearch(customerAccount arr[], int arraySize, string searchTerm);

int main() {
	// Create the array to hold the accounts
	const int ACCOUNTS_SIZE = 2;
	customerAccount accounts[ACCOUNTS_SIZE];

	cout << "Please enter the information for " << ACCOUNTS_SIZE <<" customers: \n";

	// Get the starting accounts
	for (int i = 0; i < ACCOUNTS_SIZE; i++) {
		cout << "Account number: " << i + 1 << '\n';
		// Make and assign a customer
		accounts[i] = makeCustomer();
		cout << '\n';
	}

	cout << '\n' << '\n';

	/***** MENU *****/
	char input = ' ';
	do {
		cout<< "Main Menu:\n"
			<< "A) Edit a customer account\n"
			<< "B) View all customer accounts\n"
			<< "C) Search for an account\n"
			<< "D) Exit\n";
		cin.get(input);
		cin.ignore();
		input = toupper(input);

		if (input == 'A') {
			// Get the customer number
			int custNum;
			cout << "Customer number: ";
			cin >> custNum;
			cin.ignore();

			// Make and assign the customer
			accounts[custNum - 1] = makeCustomer();
			continue;
		}
		// Display all accounts
		if (input == 'B') { displayAccounts(accounts, ACCOUNTS_SIZE); continue; }
		if (input == 'C') {
			// Get search
			cout << "Search: ";
			string searchTerm = "";
			getline(cin, searchTerm);

			//Search for account
			accountsearch(accounts, ACCOUNTS_SIZE, searchTerm);
			continue;
		}
		if (input != 'D') cout << "Error: Invalid menu item\nPlease enter valid menu item\n";


	} while (input != 'D');

	return EXIT_SUCCESS;
}

customerAccount makeCustomer() {
	customerAccount account;
	double tempBal = -1;
	string temp = "";

	// Name
	cout << "Name: ";
	getline(cin, temp);
	while (temp == "") {
		cout << "Error: Please enter a name\n"
			<< "Name: ";
		getline(cin, temp);
	}
	account.name = temp;

	// Street Address
	cout << "Street Address: ";
	getline(cin, temp);
	while (temp == "") {
		cout << "Error: Please enter a Street Address\n"
			<< "Street Address: ";
		getline(cin, temp);
	}
	account.streetAddress = temp;

	// City, State, and Zip
	cout << "City, State, and Zip: ";
	getline(cin, temp);
	while (temp == "") {
		cout << "Error: Please enter a City, State, and Zip\n"
			<< "City, State, and Zip: ";
		getline(cin, temp);
	}
	account.cityStateZip = temp;

	// Phone Number
	cout << "Phone Number: ";
	getline(cin, temp);
	while (temp == "") {
		cout << "Error: Please enter a Phone Number\n"
			<< "Phone Number: ";
		getline(cin, temp);
	}
	account.phoneNumber = temp;

	// Balance
	cout << "Balance: ";
	cin >> tempBal;
	cin.ignore();
	while (tempBal < 0) {
		cout<< "Error: Please enter a positive number\n"
			<< "Balance: ";
		cin >> tempBal;
		cin.ignore();
	}
	account.balance = tempBal;

	// Date of Last Payment
	cout << "Date of Last Payment: ";
	getline(cin, temp);
	while (temp == "") {
		cout << "Error: Please enter a Date of Last Payment\n"
			<< "Date of Last Payment: ";
		getline(cin, temp);
	}
	account.lastPayment = temp;

	return account;
}

void displayAccounts(customerAccount arr[], int arrSize) {
	for (int i = 0; i < arrSize; i++) {
		cout << "Account number: " << i + 1 << '\n';
		cout
			<< "Name:                 " << arr[i].name << '\n'
			<< "Street Address:       " << arr[i].streetAddress << '\n'
			<< "City, State, and Zip: " << arr[i].cityStateZip << '\n'
			<< "Phone Number:         " << arr[i].phoneNumber << '\n'
			<< "Balance:              " << fixed << setprecision(2) << arr[i].balance << '\n'
			<< "Date of Last Payment: " << arr[i].lastPayment << '\n' << '\n';
	}
}

void accountsearch(customerAccount arr[], int arraySize, string searchTerm) {
	cout << "Searching for \"" << searchTerm << "\" in the array\n\n";

	bool found = false;
	//Search through array
	for (int i = 0; i < arraySize; i++) {
		// If the search term is found in the name of the account, display it
		if (arr[i].name.find(searchTerm) != string::npos) {
			// If this is the first result, diaplay a message and set found to true
			if (found == false) {
				cout << "Search Results:\n";
				found = true;
			}
			// Display the account information
			cout << "Name:                 " << arr[i].name << '\n'
				<< "Street Address:       " << arr[i].streetAddress << '\n'
				<< "City, State, and Zip: " << arr[i].cityStateZip << '\n'
				<< "Phone Number:         " << arr[i].phoneNumber << '\n'
				<< "Balance:              " << fixed << setprecision(2) <<arr[i].balance << '\n'
				<< "Date of Last Payment: " << arr[i].lastPayment << '\n' << '\n';
		}
	}

	// If no results are found display message
	if (found == false) cout << "No results found :(";
}