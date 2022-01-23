#include <iostream>

void showMenu()
{
	std::cout << "********** MENU **********" << std::endl;

	std::cout << "1. Check balance" << std::endl;
	std::cout << "2. Deposit" << std::endl;
	std::cout << "3. Withdraw" << std::endl;
	std::cout << "4. Exit" << std::endl;

	std::cout << "********** END MENU **********" << std::endl;

}

int main()
{
	// Check balance, deposit, withdraw, show menu
	int option;

	double balance = 500;

	do {
		showMenu();
		std::cout << "Option: ";
		std::cin >> option;

		// A command to clear the console
		system("cls");

		switch (option) {

		case 1:
			std::cout << "Balance: " << balance << std::endl;
			break;
		case 2:
			std::cout << "Deposit: ";
			double deposit;
			std::cin >> deposit;
			balance += deposit;
			break;
		case 3:
			std::cout << "Withdraw: ";
			double withdraw;
			std::cin >> withdraw;

			if (withdraw <= balance)
				balance -= withdraw;
			else
				std::cout << "You try to withdraw more than you should!" << std::endl;

			break;

		}
	} while (option != 4);
	system("pause>0");
}